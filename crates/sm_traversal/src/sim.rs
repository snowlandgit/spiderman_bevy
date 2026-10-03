//! One hero's traversal, frame by frame, the way the game runs it: the tracker's update, then the active state's
//! transition check, then its update, then the mover's move and turn. The host supplies the input, the camera and
//! the swings to start (the swing point search is its own), moves the body with the displacement (its collisions),
//! and reports where he ended up. tools/native_oracle's loop is the same; `oracle_replay` runs its scenarios
//! through this and compares the paths.
use crate::air::{AirEntry, AirInput, AirLocal, AirShared};
use crate::config::Configs;
use crate::math::{Rows, V3};
use crate::swing::{Env, FrameInput, SwingEntry, SwingLocal, SwingProcessor, SwingRelease};
use crate::tracker::{MoverView, Tracker};
use crate::turn;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Mode {
    Swing,
    /// the jump state: HeroStateSwingJump after a swing, HeroStateJump for the launches (the same class)
    SwingJump,
    Fall,
    /// none of these (on the ground, or the host's own air movement)
    Off,
}

/// What the host gives a frame
#[derive(Clone, Copy, Debug, Default)]
pub struct StepInput {
    pub input: FrameInput,
    /// the camera's rows (side points left)
    pub cam: Rows,
    /// a swing to start this frame (the host's swing point search)
    pub swing: Option<SwingEntry>,
    /// the jump state (or the fall, `.1`) to enter this frame with this data, ending the state he is in: the launches
    /// (the point launch, the jump off a perch), a fall entered directly
    pub air: Option<(AirEntry, bool)>,
    /// the swing processor's pivot drift (exe+ab8410), on in the game
    pub drift: bool,
    /// the mover's height above the ground (the tracker's ground release parameters below 8 m; a dive needs 16 m)
    pub height: f32,
    /// the animation's state for the swing jump's hand-over to the fall (None: while rising)
    pub anim_playing: Option<bool>,
    /// the dive button's event and the dive input (0..1, the fall processor's +0x394)
    pub dive_button: bool,
    pub dive_input: f32,
}

/// What a frame hands the host
#[derive(Clone, Copy, Debug, Default)]
pub struct StepOutput {
    /// this frame's move (zero when off)
    pub displacement: V3,
    /// the facing the state asks for, if it asked
    pub facing: Option<V3>,
    pub snap: bool,
    /// the swing let go this frame
    pub released: Option<SwingRelease>,
    /// the swing jump handed over to the fall this frame
    pub fell: bool,
}

#[derive(Clone, Debug)]
pub struct Traversal {
    pub cfg: std::sync::Arc<Configs>,
    pub tracker: Tracker,
    pub swing: SwingLocal,
    pub processor: SwingProcessor,
    pub jump: AirLocal,
    pub fall: AirLocal,
    pub shared: AirShared,
    pub mode: Mode,
    /// the game clock and this traversal's frame count
    pub time: f64,
    pub frame: u64,
    entered_at: u64,
    /// his position, forward (flat) and the mover's velocity (its last move over the frame's time)
    pub pos: V3,
    pub fwd: V3,
    pub mover_vel: V3,
    /// the turn's angular velocity (rad/s)
    pub turn_v: f32,
    /// seconds in the air (negative), the mover's +0x6b4
    pub air_time: f32,
    /// the facing asked for this frame, kept for `moved`
    pending: Option<(V3, bool)>,
}

impl Traversal {
    pub fn new(cfg: std::sync::Arc<Configs>, pos: V3, vel: V3, fwd: V3) -> Self {
        // the game's tracker has run before anything reads it: its fall gravity and terminal velocity are set
        let mut tracker = Tracker::default();
        tracker.update(&cfg, MoverView { velocity: vel, airborne: true, height_above_ground: 50. }, 0.);
        Self {
            cfg,
            tracker,
            swing: SwingLocal::default(),
            processor: SwingProcessor::default(),
            jump: AirLocal::new(false),
            fall: AirLocal::new(true),
            shared: AirShared::default(),
            mode: Mode::Off,
            time: 100.,
            frame: 0,
            entered_at: 0,
            pos,
            fwd: fwd.flat_norm(),
            mover_vel: vel,
            turn_v: 0.,
            air_time: 0.,
            pending: None,
        }
    }

    pub fn hero_rows(&self) -> Rows {
        Rows::facing(self.fwd, self.pos)
    }

    /// The turn constants of the active state (set on its entry, exe+1fc3540; the jump's by its kind, exe+a7d260)
    pub fn turn_constants(&self) -> turn::TurnConstants {
        match self.mode {
            Mode::Swing => turn::SWING,
            Mode::SwingJump if self.jump.kind == crate::air::KIND_SWING_JUMP => turn::SWING_JUMP,
            _ => turn::FALL,
        }
    }

    fn env(&self, si: &StepInput, dt: f32) -> Env {
        Env { time: self.time, dt, hero: self.hero_rows(), cam: si.cam, mover_vel: self.mover_vel, input: si.input }
    }

    /// Leave the traversal states (he landed, or the host takes over)
    pub fn stop(&mut self) {
        match self.mode {
            Mode::Fall => self.fall.exit(&mut self.tracker),
            Mode::SwingJump => self.jump.exit(&mut self.tracker),
            _ => {}
        }
        self.mode = Mode::Off;
    }

    /// Let go of the swing without the release's jump (the host's own move takes over, e.g. a dive): the swing's exit
    /// as a plain release
    pub fn cancel_swing(&mut self, dt: f32) {
        if self.mode == Mode::Swing {
            let env = Env { time: self.time, dt, hero: self.hero_rows(), mover_vel: self.mover_vel, ..Default::default() };
            self.swing.exit(&self.cfg, &mut self.tracker, &env, false);
        }
        self.mode = Mode::Off;
    }

    /// The fall without a swing before it (walking off a ledge): the fall's kind with no second kind
    pub fn start_fall(&mut self, dt: f32) {
        let v = self.mover_vel;
        let e = AirEntry {
            dir: v.flat_norm(),
            vy: v.y,
            h_speed: v.flat_len(),
            gravity: self.tracker.fall_gravity,
            gravity_after: self.tracker.fall_gravity,
            max_height: self.pos.y,
            kind: crate::air::KIND_FALL,
            ..Default::default()
        };
        let env = Env { time: self.time, dt, hero: self.hero_rows(), mover_vel: self.mover_vel, ..Default::default() };
        self.fall = AirLocal::new(true);
        self.fall.enter(&e, &self.tracker, &env, &mut self.shared);
        self.mode = Mode::Fall;
        self.entered_at = self.frame;
    }


    /// A frame: the tracker, the transitions, the update. Move the body by the displacement, then call `moved`.
    pub fn step(&mut self, si: &StepInput, dt: f32) -> StepOutput {
        self.time += dt as f64;
        let mut out = StepOutput::default();
        let airborne = self.air_time < 0.;
        self.tracker.update(&self.cfg, MoverView { velocity: self.mover_vel, airborne, height_above_ground: si.height }, dt);
        let env = self.env(si, dt);
        let air_in = AirInput {
            anim_playing: si.anim_playing,
            anim_phase: 0.,
            dive_input: si.dive_input,
            dive_button: si.dive_button,
            height: si.height,
            air_time: self.air_time,
        };
        // transitions
        if let Some((e, fall)) = si.air {
            match self.mode {
                Mode::Swing => self.swing.exit(&self.cfg, &mut self.tracker, &env, false),
                Mode::SwingJump => self.jump.exit(&mut self.tracker),
                Mode::Fall => self.fall.exit(&mut self.tracker),
                Mode::Off => {}
            }
            // a requested state starts from its driver's init (exe+a85f70), as on a new activation
            if fall {
                self.fall = AirLocal::new(true);
                self.fall.enter(&e, &self.tracker, &env, &mut self.shared);
                self.mode = Mode::Fall;
            } else {
                self.jump = AirLocal::new(false);
                self.jump.enter(&e, &self.tracker, &env, &mut self.shared);
                self.mode = Mode::SwingJump;
            }
            self.entered_at = self.frame;
        } else if let (Some(e), true) = (si.swing, self.mode != Mode::Swing) {
            match self.mode {
                Mode::SwingJump => self.jump.exit(&mut self.tracker),
                Mode::Fall => self.fall.exit(&mut self.tracker),
                _ => {}
            }
            let mut e = e;
            if self.tracker.forward_action_time < self.cfg.swing.transition_data.forward_action_lookback_time {
                e.flags |= 0x100;
            }
            self.swing.enter(&self.cfg, &mut self.tracker, &mut self.processor, &e, &env);
            self.mode = Mode::Swing;
            self.entered_at = self.frame;
        } else if self.mode == Mode::Swing && self.frame > self.entered_at {
            if let Some(r) = self.swing.check(&self.cfg, &self.tracker, &env) {
                self.swing.exit(&self.cfg, &mut self.tracker, &env, r.jumped);
                let e = AirEntry::swing_jump(&r, &self.tracker);
                self.jump.enter(&e, &self.tracker, &env, &mut self.shared);
                self.mode = Mode::SwingJump;
                self.entered_at = self.frame;
                out.released = Some(r);
            }
        } else if self.mode == Mode::SwingJump && self.frame > self.entered_at {
            if let Some(e) = self.jump.check(&self.cfg, &env, &air_in) {
                self.jump.exit(&mut self.tracker);
                self.fall.enter(&e, &self.tracker, &env, &mut self.shared);
                self.mode = Mode::Fall;
                self.entered_at = self.frame;
                out.fell = true;
            }
        }
        // the update
        match self.mode {
            Mode::Swing => {
                if si.drift {
                    self.processor.drift(self.pos, self.swing.age(&env));
                }
                let o = self.swing.update(&self.cfg, &mut self.tracker, &self.processor, &env);
                self.swing.read_release_event(&env);
                out.displacement = o.displacement;
                out.facing = Some(o.facing);
                out.snap = o.snap;
            }
            Mode::SwingJump | Mode::Fall => {
                let st = if self.mode == Mode::SwingJump { &mut self.jump } else { &mut self.fall };
                let o = st.update(&self.cfg, &mut self.tracker, &env, &air_in, &mut self.shared);
                out.displacement = o.displacement;
                out.facing = Some(o.facing);
                out.snap = o.snap;
            }
            Mode::Off => {}
        }
        self.pending = out.facing.map(|f| (f, out.snap));
        out
    }

    /// Where the body ended up after the host moved it (`airborne`: not standing on anything): the mover's velocity,
    /// its air time, and the turn toward the facing the state asked for
    pub fn moved(&mut self, new_pos: V3, airborne: bool, dt: f32) {
        if dt > 0. {
            self.mover_vel = (new_pos - self.pos) * (1. / dt);
        }
        self.pos = new_pos;
        self.air_time = if airborne { self.air_time.min(0.) - dt } else { self.air_time.max(0.) + dt };
        if let Some((f, snap)) = self.pending.take() {
            if let Some(want) = turn::want_facing(f) {
                let k = self.turn_constants();
                self.fwd = turn::step(self.fwd, V3::UP, want, &mut self.turn_v, k, snap, dt);
            }
        }
        self.frame += 1;
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::air::{AirEntry, KIND_PERCH_JUMP, KIND_POINT_LAUNCH};

    fn jump_from_rest(e: AirEntry, held: bool) -> (Traversal, f32) {
        let cfg = std::sync::Arc::new(Configs::embedded());
        let mut t = Traversal::new(cfg, V3::new(0., 30., 0.), V3::ZERO, V3::new(0., 0., 1.));
        let dt = 1. / 60.;
        let mut top = 30f32;
        for f in 0..90 {
            let si = StepInput {
                input: FrameInput { jump_held: held, ..Default::default() },
                cam: Rows::facing(V3::new(0., 0., 1.), t.pos),
                air: (f == 0).then_some((e, false)),
                height: 30.,
                ..Default::default()
            };
            let o = t.step(&si, dt);
            let p = t.pos + o.displacement;
            t.moved(p, true, dt);
            top = top.max(t.pos.y);
        }
        (t, top)
    }

    #[test]
    fn the_perch_jump_reads_its_own_config_and_thrusts_while_held() {
        let cfg = Configs::embedded();
        let e = AirEntry::ground_jump(&cfg, KIND_PERCH_JUMP, V3::new(0., 0., 1.), 0., 0., 26.);
        // PerchJumpConfig: 2 m up in 0.35 s, 0.3 s to fall
        assert!((e.vy - 4. / 0.35).abs() < 1e-4 && (e.gravity - 4. / 0.35 / 0.35).abs() < 1e-3);
        assert!((e.gravity_after - 4. / 0.09).abs() < 1e-3 && e.h_speed == 0.);
        let (_, plain) = jump_from_rest(e, false);
        let (_, held) = jump_from_rest(e, true);
        assert!((plain - 32.).abs() < 0.05, "a 2 m jump: top {plain}");
        assert!(held > plain + 1., "the held button's thrust: {held} vs {plain}");
        let with_stick = AirEntry::ground_jump(&cfg, KIND_PERCH_JUMP, V3::new(0., 0., 1.), 0., 0.8, 26.);
        assert!((with_stick.h_speed - (0.8 * 0.8 + 0.2) * 7.).abs() < 1e-4);
    }

    #[test]
    fn the_point_launch_has_no_thrust_and_falls_at_gravity_fall() {
        let l = crate::point_launch::launch(
            &Configs::embedded().traversal.point_launch_config,
            crate::point_launch::Exit::Point,
            V3::new(0., 0., 1.),
            0.,
            None,
            &crate::point_launch::Probes::CLEAR,
        );
        let e = l.entry();
        assert_eq!(e.kind, KIND_POINT_LAUNCH);
        let (a, top_a) = jump_from_rest(e, false);
        let (_, top_b) = jump_from_rest(e, true);
        assert_eq!(top_a, top_b);
        assert!((top_a - 36.).abs() < 0.1, "6 m up: {top_a}");
        assert_eq!(a.mode, Mode::Fall);
    }
}
