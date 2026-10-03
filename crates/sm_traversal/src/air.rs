//! Hero::HeroStateSwingJumpLocal (Spider-Man.exe 4.0630, vtable exe+38d4b58) and Hero::HeroStateFallLocal (vtable
//! exe+38c9220): what follows a swing. Both share the jump state's layout (the fall adds +0x300..). Entry exe+a86490
//! (the fall's exe+a70080 on top of it); per frame exe+a8d5b0 -> exe+a88ec0 with its virtuals (speed data exe+a87a70,
//! target speed exe+a8b140, drag exe+a8b1d0, displacement exe+a8b520 with the steering exe+a8c7f0 and the vertical
//! exe+a8c3c0, facing exe+a8beb0), then the fall's gravity (exe+a706a0) and momentum (exe+a71a40). The swing jump hands
//! over to the fall on exe+a87f10 / exe+a885c0 through the transition manager's TryFall (exe+96e580). Field comments
//! give the state's offsets. Ported from Ghidra's decompilation with argument order and constants taken from the
//! disassembly; tools/native_oracle runs the game's own code on the same inputs to compare.
//!
//! Left out (they need what this port doesn't model): moving platforms, walls and ledges the mover touches, the
//! animation-driven jumps (+0x204 >= 0), spline and focus targets, the button thrust (kinds the swing never hands
//! over) and the speed boost of entries with +0x78 > 0 (the boost itself is kept, it is short).
use crate::config::{Configs, DragProfile, JumpMotionData, JumpSpeedData};
use crate::math::*;
use crate::swing::{Env, SwingRelease};
use crate::tracker::Tracker;

/// Jump kinds (+0x2c0, +0x2c4) on the way from a swing
pub const KIND_FALL: u8 = 0x0b;
pub const KIND_DIVE: u8 = 0x0c;
pub const KIND_SWING_JUMP: u8 = 0x11;
/// the second kind's default: none
pub const KIND_NONE: u8 = 0x35;

/// The jump data a transition hands the state (defaults: exe+a7d820)
#[derive(Clone, Copy, Debug)]
pub struct AirEntry {
    /// +0x34: the horizontal direction
    pub dir: V3,
    /// +0x40: extra velocity on top of the motion (it decays)
    pub vel: V3,
    /// +0x4c: a facing to hold (zero: none)
    pub facing: V3,
    /// +0x58, +0x5c
    pub vy: f32,
    pub h_speed: f32,
    /// +0x60: gravity while rising; +0x64: after the apex (10000 or more: the same)
    pub gravity: f32,
    pub gravity_after: f32,
    /// +0x6c: time spent falling already
    pub fall_time: f32,
    /// +0x70
    pub max_height: f32,
    /// +0x74: the input magnitude to start with
    pub input: f32,
    /// +0x78: a speed boost's duration
    pub boost_time: f32,
    /// +0x7c: the apex gravity switch waits until this much time in the state
    pub gravity_switch_time: f32,
    /// +0x81, +0x82, +0x83
    pub kind: u8,
    pub kind2: u8,
    pub flags: u8,
}

impl Default for AirEntry {
    fn default() -> Self {
        Self {
            dir: V3::ZERO,
            vel: V3::ZERO,
            facing: V3::ZERO,
            vy: 0.,
            h_speed: 0.,
            gravity: 0.,
            gravity_after: 1e30,
            fall_time: 0.,
            max_height: -1e30,
            input: 0.,
            boost_time: 0.,
            gravity_switch_time: -1.,
            kind: 0,
            kind2: KIND_NONE,
            flags: 0,
        }
    }
}

impl AirEntry {
    /// exe+97c9d0 (the transition manager's slot 82): the swing jump from the swing's release. The direction is the
    /// release velocity's, flattened (exe+a7d8c0 takes out the mover's up); the gravity after the apex is the
    /// tracker's fall gravity (exe+ac1680's last output, exe+85fbb0).
    pub fn swing_jump(r: &SwingRelease, tr: &Tracker) -> Self {
        let v = r.velocity;
        let d = v.flat_norm();
        let dir = if d.x.abs() > 0.01 || d.z.abs() > 0.01 { d.norm() } else { d };
        Self {
            dir,
            vy: v.y,
            h_speed: v.flat_len(),
            gravity: r.gravity,
            gravity_after: tr.fall_gravity,
            kind: KIND_SWING_JUMP,
            ..Default::default()
        }
    }
}

/// What the air states read besides the frame's [`Env`]
#[derive(Clone, Copy, Debug, Default)]
pub struct AirInput {
    /// The animation component's "playing" bit (+0x98 bit 0): the swing jump hands over to the fall once its
    /// animation stops. None: while rising (as tools/native_oracle stands in for it).
    pub anim_playing: Option<bool>,
    /// The animation's time (exe+15c09c0), against the state's animation timings (+0x1f8.., -1 without)
    pub anim_phase: f32,
    /// The fall's dive input (its processor's +0x394, 0..1) and the dive button's buffered event (0xce39bb4c)
    pub dive_input: f32,
    pub dive_button: bool,
    /// The mover's height above the ground (+0x6b8); a dive needs 16 m
    pub height: f32,
    /// The mover's time in the air (+0x6b4, negative while airborne)
    pub air_time: f32,
}

/// The globals the air states share (exe+6deecc0..6deecd0): the air clock (+0xc, the time since the swing jump or
/// a fall that didn't follow one began), the facing blend (+0x10) and a vector the fall keeps (+0x0)
#[derive(Clone, Copy, Debug, Default)]
pub struct AirShared {
    pub v: V3,
    pub clock: f32,
    pub facing_blend: f32,
}

/// What a frame of the air states hands the mover
#[derive(Clone, Copy, Debug, Default)]
pub struct AirOutput {
    pub displacement: V3,
    pub facing: V3,
    pub snap: bool,
    /// the input strength the animation reads (blackboard 0x71e819a6)
    pub input: f32,
}

#[derive(Clone, Debug)]
pub struct AirLocal {
    /// the fall's virtuals (exe+38c9220) instead of the swing jump's
    pub fall: bool,
    /// +0xd8
    pub entry_time: f64,
    /// +0x124: the entry direction
    pub dir: V3,
    /// +0x130
    pub facing: V3,
    /// +0x13c: the horizontal velocity the state started from (the steering compares the input with it)
    pub carry: V3,
    /// +0x154: extra velocity (decays at +0x224 per second); +0x160 last frame's
    pub vel: V3,
    pub prev_vel: V3,
    /// +0x16c: a facing to hold
    pub hold_facing: V3,
    /// +0x184: the horizontal velocity moved last frame
    pub last_vel: V3,
    /// +0x1d0: the shared vector, kept by a fall that follows a jump
    pub saved: V3,
    /// +0x1dc: the input magnitude to start with
    pub entry_input: f32,
    /// +0x1e0, +0x1e4: gravity now and after the apex
    pub gravity: f32,
    pub gravity_after: f32,
    /// +0x1e8: time spent falling
    pub fall_time: f32,
    /// +0x1ec, +0x1f0
    pub vy_prev: f32,
    pub vy: f32,
    /// +0x1f4: the tracker's terminal velocity
    pub terminal: f32,
    /// +0x1f8, +0x208, +0x20c, +0x210, +0x214, +0x21c: animation timings (exe+a88b60 reads them off the animation's
    /// metadata; -1 without)
    pub anim_end: f32,
    pub anim_fall_a: f32,
    pub anim_dive: f32,
    pub anim_dive_ok: f32,
    pub anim_fall_b: f32,
    pub anim_land: f32,
    /// +0x1fc
    pub gravity_switch_time: f32,
    /// +0x204: an animation-driven jump when >= 0
    pub anim_duration: f32,
    /// +0x224
    pub vel_decay: f32,
    /// +0x228: on the tracker's fall gravity
    pub tracker_gravity: bool,
    /// +0x250, +0x254, +0x258: the button thrust (acceleration, gravity, this frame's time)
    pub thrust_accel: f32,
    pub thrust_gravity: f32,
    pub thrust_time: f32,
    /// +0x25c: the horizontal speed allowed, lowered by the drag
    pub speed: f32,
    /// +0x264, +0x268: the run speed and its acceleration
    pub run_speed: f32,
    pub run_accel: f32,
    /// +0x26c, +0x274
    pub max_height: f32,
    pub h_speed: f32,
    /// +0x2c0, +0x2c4
    pub kind: u8,
    pub kind2: u8,
    /// +0x2c8: held by the processor (its +0x3bc time) unless +0x2c9
    pub early: bool,
    pub no_early: bool,
    /// +0x2ca: past the first frame
    pub started: bool,
    /// +0x2cb.. entry flags
    pub b2cb: bool,
    pub b2cc: bool,
    pub thrust_done: bool,
    pub b2d1: bool,
    pub anim_read: bool,
    pub fall_anim_done: bool,
    pub b2d4: bool,
    pub b2d5: bool,
    pub b2d6: bool,
    pub b2d7: bool,
    pub b2d8: bool,
    /// +0x2da: diving
    pub dive: bool,
    pub b2db: bool,
    pub b2dc: bool,
    /// +0x2e0
    pub dive_amount: f32,
    /// +0x2e4, +0x2e8, +0x2ec: the entry's speed boost (target speed, time left, rate)
    pub boost_speed: f32,
    pub boost_time: f32,
    pub boost_rate: f32,
    /// +0x2f0: how long the stick has been held (starts at 5 the first time)
    pub input_time: f32,
    /// +0x2f4
    pub input_out: f32,
    /// +0x2f9: the side the facing turns to near 180 degrees
    pub turn_side: bool,
    /// +0x2fc: the facing's blend toward the input
    pub facing_blend: f32,
    /// HeroStateFallLocal +0x300: the dive input; +0x304 time diving, +0x308 time falling; +0x30c diving, +0x30d the
    /// dive drag, +0x30e, +0x310 (no dive button check), +0x311
    pub dive_input: f32,
    pub dive_time: f32,
    pub fall_clock: f32,
    pub diving: bool,
    pub dive_drag: bool,
    pub b30e: bool,
    pub b310: bool,
    pub b311: bool,
}

impl AirLocal {
    /// exe+a85f70 (and the fall's constructor on top)
    pub fn new(fall: bool) -> Self {
        Self {
            fall,
            entry_time: 0.,
            dir: V3::ZERO,
            facing: V3::ZERO,
            carry: V3::ZERO,
            vel: V3::ZERO,
            prev_vel: V3::ZERO,
            hold_facing: V3::ZERO,
            last_vel: V3::ZERO,
            saved: V3::ZERO,
            entry_input: 0.,
            gravity: 0.,
            gravity_after: 0.,
            fall_time: 0.,
            vy_prev: 0.,
            vy: 0.,
            terminal: 0.,
            anim_end: -1.,
            anim_fall_a: -1.,
            anim_dive: -1.,
            anim_dive_ok: -1.,
            anim_fall_b: -1.,
            anim_land: -1.,
            gravity_switch_time: -1.,
            anim_duration: -1.,
            vel_decay: -0.1,
            tracker_gravity: false,
            thrust_accel: 0.,
            thrust_gravity: 0.,
            thrust_time: 0.,
            speed: 0.,
            run_speed: 0.,
            run_accel: 0.,
            max_height: 0.,
            h_speed: 0.,
            kind: 0,
            kind2: KIND_NONE,
            early: false,
            no_early: false,
            started: false,
            b2cb: false,
            b2cc: false,
            thrust_done: false,
            b2d1: false,
            anim_read: false,
            fall_anim_done: false,
            b2d4: false,
            b2d5: false,
            b2d6: false,
            b2d7: false,
            b2d8: false,
            dive: false,
            b2db: false,
            b2dc: true,
            dive_amount: 0.,
            boost_speed: 0.,
            boost_time: 0.,
            boost_rate: 0.,
            input_time: -1.,
            input_out: 0.,
            turn_side: false,
            facing_blend: 0.,
            dive_input: 0.,
            dive_time: 0.,
            fall_clock: 0.,
            diving: false,
            dive_drag: false,
            b30e: false,
            b310: false,
            b311: false,
        }
    }

    /// exe+20dc660: time in the state
    pub fn age(&self, env: &Env) -> f32 {
        (env.time - self.entry_time) as f32
    }

    /// Slot 18 (exe+a87910): the motion data. Every kind the swing hands over reads the swing jump's (a fall reads
    /// its second kind's).
    fn motion<'a>(&self, cfg: &'a Configs) -> &'a JumpMotionData {
        &cfg.traversal.jump_configs.swing_jump_config.standard_data
    }
    /// Slot 19 (exe+a879d0): the speed data, likewise
    fn speed_data<'a>(&self, cfg: &'a Configs) -> &'a JumpSpeedData {
        &cfg.traversal.jump_configs.swing_jump_speed.standard_data
    }
    /// exe+869300: the motion data's drag profile by name
    fn drag_profile<'a>(&self, cfg: &'a Configs) -> &'a DragProfile {
        cfg.drag_profile(&self.motion(cfg).drag_profile_name)
    }
    /// Slot 42 (exe+a8ae50): steering once the motion data's NoInputTime has passed on the air clock
    fn steering(&self, cfg: &Configs, sh: &AirShared) -> bool {
        self.motion(cfg).no_input_time <= sh.clock
    }
    fn fall_from_jump(&self) -> bool {
        (self.kind == KIND_FALL || self.kind == KIND_DIVE) && self.kind2 != KIND_NONE
    }

    /// exe+a86490 (+ exe+a70080 for the fall)
    pub fn enter(&mut self, e: &AirEntry, tr: &Tracker, env: &Env, sh: &mut AirShared) {
        self.entry_time = env.time;
        self.b2cb = (!(e.flags >> 1)) & 1 != 0;
        self.b2d1 = e.flags & 1 != 0;
        self.b2cc = (!(e.flags >> 2)) & 1 != 0;
        self.b2d6 = (e.flags >> 6) & 1 != 0;
        self.b2d7 = e.flags >> 7 != 0;
        self.b2d8 = false;
        self.started = false;
        self.anim_duration = -1.;
        self.vel = e.vel;
        self.prev_vel = e.vel;
        self.max_height = env.hero.pos.y.max(e.max_height);
        let d = e.dir;
        self.dir = if d.x.abs() > 0.0001 || d.y.abs() > 0.0001 || d.z.abs() > 0.0001 { d.norm() } else { env.hero.fwd };
        self.facing = self.dir;
        let f = e.facing;
        if f.x.abs() > 0.0001 || f.y.abs() > 0.0001 || f.z.abs() > 0.0001 {
            self.facing = f;
            self.hold_facing = f;
        }
        self.entry_input = e.input;
        self.kind = e.kind;
        self.kind2 = e.kind2;
        self.h_speed = e.h_speed;
        self.vy = e.vy;
        self.gravity = e.gravity;
        self.gravity_after = if e.gravity_after >= 10000. { e.gravity } else { e.gravity_after };
        self.gravity_switch_time = e.gravity_switch_time;
        self.speed = self.h_speed;
        self.run_speed = self.h_speed;
        self.run_accel = 0.;
        self.b2d4 = false;
        self.b2d5 = (e.flags >> 5) & 1 != 0;
        if (self.kind == KIND_FALL || self.kind == KIND_DIVE || self.kind == 0x34) && self.kind2 != KIND_NONE {
            self.facing_blend = sh.facing_blend;
            self.saved = sh.v;
        } else {
            sh.clock = 0.;
            sh.v = V3::ZERO;
        }
        self.terminal = tr.terminal;
        self.boost_time = e.boost_time;
        self.boost_speed = e.h_speed;
        self.boost_rate = (self.boost_speed - env.mover_vel.flat_len()).max(0.) / self.boost_time;
        if !self.fall {
            return;
        }
        // exe+a70080
        self.diving = false;
        self.dive_drag = false;
        self.b30e = true;
        self.dive_input = 1e30;
        self.dive_time = 0.;
        self.fall_clock = 0.;
        self.b311 = false;
        if self.kind == KIND_DIVE {
            self.dive_drag = true;
            self.diving = true;
            self.b2dc = false;
        }
        self.b310 = false;
        if self.kind2 != KIND_NONE {
            self.started = true;
            self.carry = env.mover_vel;
        }
    }

    /// The state's exit as far as the tracker goes: the fall's (exe+a701a0) moves the momentum ring on (exe+85e310);
    /// the swing jump's (exe+a86270) leaves nothing modelled here
    pub fn exit(&self, tr: &mut Tracker) {
        if self.fall {
            tr.ring_next = (tr.ring_next + 1) % 32;
        }
    }

    /// exe+a8d5b0: one frame. `tr` is the tracker after its own update this frame.
    pub fn update(&mut self, cfg: &Configs, tr: &mut Tracker, env: &Env, inp: &AirInput, sh: &mut AirShared) -> AirOutput {
        let dt = env.dt;
        // the processor's hold (its +0x3bc; none after a swing)
        self.early = !self.no_early && self.age(env) < 0.;
        // slot 36 (exe+a88b60): the animation's timings, once
        if !self.anim_read {
            self.anim_read = true;
        }
        sh.clock += dt;
        let out = self.motion_frame(cfg, tr, env, sh);
        if self.fall {
            self.fall_gravity(tr, env, inp);
            self.fall_momentum(cfg, tr, env);
        } else {
            self.jump_dive(env, inp);
        }
        out
    }

    /// exe+a88ec0
    fn motion_frame(&mut self, cfg: &Configs, tr: &Tracker, env: &Env, sh: &mut AirShared) -> AirOutput {
        let dt = env.dt;
        let hero = env.hero;
        self.max_height = self.max_height.max(hero.pos.y);
        // slot 45 (exe+a8afa0): the mover's velocity; the extra velocity decays and comes off it
        let mut base = env.mover_vel;
        self.prev_vel = self.vel;
        let e = exp(self.vel_decay * dt);
        self.vel = self.vel + (V3::ZERO - self.vel) * (1. - e);
        base -= self.prev_vel;
        // slot 22 (exe+a87b90): the button thrust, for kinds the swing never hands over
        self.thrust_accel = 0.;
        self.thrust_gravity = 0.;
        self.thrust_time = 0.;
        if !self.thrust_done && !self.early && self.vy < -0.0001 {
            self.thrust_done = true;
        }
        self.vy_prev = self.vy;
        // slot 20 (exe+a87a70): the speeds
        let sd = self.speed_data(cfg);
        self.run_speed = self.run_speed.max(sd.run_speed_alt_min);
        if self.run_speed < sd.run_speed_max_min {
            if sh.clock > sd.max_accel_delay {
                if sd.max_accel_speed <= 0. {
                    self.run_speed = sd.run_speed_max_min;
                } else {
                    let mut a = sd.max_accel_speed;
                    if sd.max_accel_accel > 0. {
                        a = (sd.max_accel_accel * dt + self.run_accel).min(sd.max_accel_speed);
                    }
                    self.run_accel = a;
                    self.run_speed = (a * dt + self.run_speed).min(sd.run_speed_max_min);
                }
            }
        } else {
            self.run_speed = self.run_speed.min(sd.run_speed_max_max);
        }
        let run = self.run_speed;
        let walk = run.min(sd.walk_speed_max);
        let low = (walk * 0.25).min(0.25);
        // the input (exe+b7e2e0: the stick's magnitude, no dead zone)
        let mut dir = self.facing;
        let mut mag = self.entry_input;
        let raw = env.stick_raw().0;
        self.input_time = if raw >= 0.01 {
            if self.input_time >= 0. {
                self.input_time + dt
            } else {
                5.
            }
        } else {
            0.
        };
        let steer_kinds = self.started || self.fall_from_jump();
        if self.steering(cfg, sh) && steer_kinds {
            let (d, _, _) = env.stick_world();
            dir = d;
            mag = if d == V3::ZERO { 0. } else { raw };
        }
        let base_speed = base.len();
        if mag < 0.01 {
            dir = if base.flat_len() > 0.01 { V3::new(base.x, 0., base.z).norm() } else { hero.fwd };
        }
        // slot 48 (exe+a8b140): the speed to settle at
        let target = if mag > 0.04 {
            if mag < dt {
                ((mag / dt).max(0.).min(1.)) * (walk - low) + low
            } else {
                let t = if dt < 1. { (mag - dt) / (1. - dt) } else { 1. };
                t.max(0.).min(1.) * (run - walk) + walk
            }
        } else {
            0.
        };
        let speed = self.drag(cfg, dir, mag, target, base, dt, sh);
        let cap = speed.max(run).max(walk);
        let disp = self.displacement(cfg, tr, env, dir, mag, base, speed, cap, sh);
        // slot 54 (exe+a8c350): a held facing keeps the entry direction
        let held = !(self.steering(cfg, sh)
            && self.hold_facing.x.abs() <= 0.0001
            && self.hold_facing.y.abs() <= 0.0001
            && self.hold_facing.z.abs() <= 0.0001);
        let want = if held { self.dir } else { self.facing_toward(cfg, env, dir, mag, disp * (1. / dt), sh) };
        let facing = if want.x * want.x + want.z * want.z <= 0.001 { hero.fwd } else { V3::new(want.x, 0., want.z).norm() };
        // after the apex: the gravity for falling (from the state's +0x1fc on), or the tracker's
        if self.vy < 0. {
            self.fall_time += dt;
            if self.age(env) > self.gravity_switch_time {
                self.gravity = self.gravity_after;
                if tr.fall_gravity_override || self.tracker_gravity {
                    self.gravity_after = tr.fall_gravity;
                    self.gravity = tr.fall_gravity;
                    self.tracker_gravity = true;
                }
            }
        }
        self.input_out = if walk < base_speed { mag } else { raw };
        self.last_vel = V3::new(disp.x / dt, 0., disp.z / dt);
        if self.kind != 0x34 {
            self.started = !self.early;
        }
        AirOutput { displacement: disp, facing, snap: false, input: self.input_out }
    }

    /// Slot 49 (exe+a8b1d0): the speed allowed comes down toward `target` at the drag profile's rate, which is the
    /// forward drag (by speed) with the input along the carried velocity, the turn drag across it, the no-input drag
    /// without input
    #[allow(clippy::too_many_arguments)]
    fn drag(&mut self, cfg: &Configs, dir: V3, mag: f32, target: f32, base: V3, dt: f32, sh: &AirShared) -> f32 {
        if !self.started || self.boost_time > 0.0001 || self.early {
            return self.speed;
        }
        let p = self.drag_profile(cfg);
        let v = base.len();
        let fwd = unlerp(v, p.forward_speed_min, p.forward_speed_max) * (p.forward_drag_max - p.forward_drag_min) + p.forward_drag_min;
        let b = unlerp(sh.clock, p.turn_blend_in_start, p.turn_blend_in_final);
        let mut drag = ((p.no_input_drag - fwd) * b + fwd).max(fwd);
        let turn = ((p.turn_drag - fwd) * b + fwd).max(fwd);
        if mag > 0.05 {
            let d = self.carry.norm().dot(dir).max(0.);
            drag = unlerp(d, 0., p.forward_tolerance) * (fwd - turn) + turn;
        }
        // slot 50: the fall's dive drag
        if self.fall && self.dive_drag {
            drag = 15.;
        }
        self.speed = self.speed.min(v);
        self.speed = approach(self.speed, target, drag, dt).max(target);
        self.speed
    }

    /// Slot 52 (exe+a8b520): this frame's move. The horizontal velocity steers toward the input at `speed`, capped at
    /// `cap`; the extra velocity rides on top; then the vertical.
    #[allow(clippy::too_many_arguments)]
    fn displacement(&mut self, cfg: &Configs, tr: &Tracker, env: &Env, dir: V3, mag: f32, base: V3, speed: f32, cap: f32, sh: &AirShared) -> V3 {
        let dt = env.dt;
        let dd = dir.dot(dir);
        let mut want = if dd >= 1e-15 { dir * (speed / dd.sqrt()) } else { V3::new(speed, 0., 0.) };
        let mut flat = V3::new(base.x, 0., base.z);
        if self.early {
            // held: the motion carries on (the animation's root motion when +0x2d7)
            return V3::new((flat.x + self.vel.x) * dt, self.vel.y * dt, (flat.z + self.vel.z) * dt);
        }
        if !self.started {
            let src = if matches!(self.kind, 6 | 7 | 0xd | 0xe | 0xf) {
                (dir, cap)
            } else if self.hold_facing.x.abs() > 0.0001 || self.hold_facing.y.abs() > 0.0001 || self.hold_facing.z.abs() > 0.0001 {
                (self.hold_facing, self.h_speed)
            } else {
                (self.dir, self.h_speed)
            };
            self.carry = scaled(src.0, src.1);
            want = self.carry;
            if self.boost_time >= 0.0001 {
                let c = self.carry.norm();
                let cc = c.dot(c);
                let along = if cc <= 1e-15 { V3::ZERO } else { c * ((c.z * flat.z + c.x * flat.x) / cc) };
                flat = if c.dot(along) < 0. { V3::ZERO } else { along };
                let rest = (self.boost_speed - flat.flat_len()).max(0.);
                self.boost_rate = rest / self.boost_time;
            } else {
                flat = self.carry;
            }
        }
        if self.steering(cfg, sh) {
            flat = self.steer(cfg, flat, want, dt, mag, cap, sh);
            if self.boost_time > 0.0001 {
                self.boost(&mut flat, dt);
            }
        } else if self.boost_time >= 0.0001 {
            self.boost(&mut flat, dt);
        } else {
            flat = scaled(self.carry, self.carry.len().min(cap));
        }
        let mut out = (flat + self.vel) * dt;
        self.vertical(tr, env, &mut out);
        out
    }

    /// The entry's speed boost (+0x2e4 over +0x2e8 at +0x2ec)
    fn boost(&mut self, flat: &mut V3, dt: f32) {
        let step = self.boost_time.min(dt);
        let rest = (self.boost_speed - flat.len()).max(0.);
        if rest > 0.0001 {
            *flat += scaled(self.carry, (step * self.boost_rate).min(rest));
        }
        self.boost_time -= step;
    }

    /// Slot 57 (exe+a8c7f0): the horizontal velocity moves toward `want` at the motion data's acceleration (higher
    /// later on the air clock, and at once when the input turns back), scaled by the input and how long it has been
    /// held; at most `cap`
    #[allow(clippy::too_many_arguments)]
    fn steer(&self, cfg: &Configs, cur: V3, want: V3, dt: f32, m: f32, cap: f32, sh: &AirShared) -> V3 {
        let mut back = 0.;
        if m > 0.1 && want.len().min(cur.len()) > 0.1 {
            let a = V3::new(cur.x, 0., cur.z).norm();
            let b = V3::new(want.x, 0., want.z).norm();
            if a.dot(b) < -0.5 {
                back = m;
            }
        }
        let md = self.motion(cfg);
        let tb = remap(sh.clock, md.velocity_accel_time_min, md.velocity_accel_time_max);
        let acc = ((1. - tb) * back + tb) * (md.velocity_accel_accel_max - md.velocity_accel_accel_min) + md.velocity_accel_accel_min;
        let held = (self.input_time * 3.030303).max(0.).min(1.).max(0.2);
        let mut f = ((m * 1.3333334).max(0.).min(1.) * 0.75 + 0.25) * held;
        // slot 51: the fall halves it while diving
        if self.fall && self.diving {
            f *= 0.5;
        }
        let r = approach_v(cur, want, f * acc + back, dt);
        let l = r.len().min(cap);
        let rr = r.dot(r);
        if rr >= 1e-15 {
            r * (l / rr.sqrt())
        } else {
            V3::new(0., 0., 0.)
        }
    }

    /// Slot 56 (exe+a8c3c0): gravity (more while diving), the thrust, the terminal velocity; integrated at the
    /// frame's midpoint
    fn vertical(&mut self, tr: &Tracker, env: &Env, out: &mut V3) {
        let dt = env.dt;
        let y = env.hero.pos.y;
        let floor = -1e30f32;
        let g0 = self.gravity;
        let tg = self.thrust_time * self.thrust_gravity;
        let k = (self.thrust_time / dt).max(0.).min(1.);
        let thrust = self.thrust_time * self.thrust_accel;
        let mut g1 = g0 + tg;
        let half = ((1. - k) + 1.) * 0.5;
        if self.dive {
            g1 += dt * 35.;
        }
        self.gravity = g1;
        self.gravity_after += tg;
        let gdt = ((g1 - g0) * half + g0) * dt;
        self.terminal = tr.terminal;
        let min = -self.terminal;
        let vy = (self.vy - gdt + thrust).max(min);
        let mut dy = (self.vy - gdt * 0.5 + half * thrust).max(min) * dt;
        if out.y + y + dy < floor {
            dy = floor - y;
        }
        out.y += dy;
        self.vy = vy;
    }

    /// Slot 53 (exe+a8beb0): the facing. The fall keeps the input's direction (or his own); the swing jump starts on
    /// its travel and turns toward the input over FacingToInputTime on the air clock.
    fn facing_toward(&mut self, cfg: &Configs, env: &Env, dir: V3, mag: f32, vel: V3, sh: &mut AirShared) -> V3 {
        let mf = env.hero.fwd;
        let base = if mag <= 0.01 { mf } else { dir };
        if self.fall_from_jump() {
            return base;
        }
        let md = self.motion(cfg);
        let fb = remap(sh.clock, md.facing_to_input_time_min, md.facing_to_input_time_max);
        let travel = V3::new(vel.x - self.vel.x, 0., vel.z - self.vel.z).norm();
        if mag < 0.01 && vel.flat_len() < 0.25 {
            return mf;
        }
        let out = if fb > 0.9999 {
            base
        } else if fb > 0.0001 {
            let prev = self.facing_blend;
            let frac = ((fb - prev) / (1. - prev)).max(0.).min(1.);
            let mut ay = if base.x * mf.z - mf.x * base.z >= 0. { 1. } else { -1. };
            let mut ang = angle_between(mf, base);
            let left = ay > 0.;
            if self.turn_side && ang >= 2.984513 {
                if self.turn_side != left {
                    ay = -ay;
                    ang = 6.2831855 - ang;
                }
            } else {
                self.turn_side = left;
            }
            rotate(mf, V3::new(0., ay, 0.), ang * frac)
        } else {
            travel
        };
        self.facing_blend = fb;
        sh.facing_blend = fb;
        out
    }

    /// The swing jump's slot 41 (exe+a8adb0): a dive past 0.3 s on the dive button (exe+a71380) when slot 17
    /// (exe+a87850) agrees: high enough and the dive input pushed; diving while still rising adds gravity at once
    fn jump_dive(&mut self, env: &Env, inp: &AirInput) {
        if self.dive || self.age(env) < 0.3 {
            return;
        }
        let t = self.age(env);
        let wants = inp.height >= 16. && self.anim_dive_ok < t && t > 0.3 && inp.dive_input > 0.8;
        if inp.dive_button && wants {
            self.dive = true;
            if self.vy > 0.1 {
                self.gravity += (self.gravity * 1.5).max(30.);
            }
        } else {
            self.dive = false;
        }
    }

    /// The fall's slot 17 (exe+a70480)
    fn fall_wants_dive(&self, env: &Env, inp: &AirInput) -> bool {
        if self.kind2 == KIND_NONE && self.age(env) <= 0.2 {
            return false;
        }
        self.dive_input > 0.75 && !self.diving && inp.height >= 16.
    }

    /// The fall's slot 41 (exe+a706a0): gravity grows by 3 m/s per second up to 30 (5 while diving)
    fn fall_gravity(&mut self, tr: &Tracker, env: &Env, inp: &AirInput) {
        let dt = env.dt;
        self.dive_input = inp.dive_input;
        let check = self.b310 || inp.dive_button;
        let wants = self.fall_wants_dive(env, inp);
        if check && (self.diving || wants) {
            self.b2d4 = true;
            self.dive_drag = true;
            self.kind = KIND_DIVE;
            self.gravity = (dt * 5. + self.gravity).min(30.);
            self.gravity_after = (dt * 5. + self.gravity_after).min(30.);
            return;
        }
        if !tr.fall_gravity_override {
            self.dive_drag = false;
            self.gravity = (dt * 3. + self.gravity).min(30.);
            self.gravity_after = (dt * 3. + self.gravity_after).min(30.);
        }
    }

    /// exe+a71a40: falling fast builds momentum (more, and longer, when diving)
    fn fall_momentum(&mut self, cfg: &Configs, tr: &mut Tracker, env: &Env) {
        let dt = env.dt;
        let fd = &cfg.swing.momentum_config.fall_data;
        if !self.diving {
            self.dive_time = 0.;
            if tr.state != 2 {
                self.fall_clock = 0.;
            } else {
                self.fall_clock += dt;
            }
        } else {
            self.dive_time += dt;
            self.fall_clock += dt;
        }
        let sf = if self.vy <= 0. { remap(self.vy.abs(), fd.fall_speed_min, fd.fall_speed_max) } else { 0. };
        let tf = remap(self.age(env), fd.fall_time_min, fd.fall_time_max).powf(fd.fall_time_bias);
        let mut gain = (lerp(fd.fall_gain_min, fd.fall_gain_max, tf)) * sf;
        let mut cap = lerp(fd.fall_momentum_cap_min, fd.fall_momentum_cap_max, tf);
        if self.diving {
            let df = remap(self.dive_time, fd.dive_time_min, fd.dive_time_max).powf(fd.dive_time_bias);
            gain = lerp(fd.dive_gain_min, fd.dive_gain_max, df).max(gain);
            cap = lerp(fd.dive_momentum_cap_min, fd.dive_momentum_cap_max, df).max(cap);
        }
        tr.add_momentum(cfg, gain * dt, cap, false);
    }

    /// The swing jump's transition check (exe+a86ad0 as far as a swing's jump goes): it hands over to the fall once
    /// its animation has played out (exe+a87f10) while he is in the air. The fall's entry (exe+a885c0 -> exe+96e580)
    /// comes back.
    pub fn check(&self, cfg: &Configs, env: &Env, inp: &AirInput) -> Option<AirEntry> {
        if self.fall || self.kind == KIND_FALL || self.kind == KIND_DIVE || self.age(env) < 0.05 {
            return None;
        }
        let phase = inp.anim_phase;
        let playing = inp.anim_playing.unwrap_or(self.vy > 0.);
        let dive_ready = self.dive && phase >= self.anim_dive;
        if !((self.anim_end <= phase || dive_ready) && inp.air_time < 0.) {
            return None;
        }
        let long = self.anim_fall_b.max(self.anim_fall_a);
        if !((0. <= long && long < phase) || dive_ready || !playing) {
            return None;
        }
        Some(self.fall_entry(cfg, env))
    }

    /// exe+a885c0 -> exe+96e580: the fall from the swing jump. His move's velocity with the state's vertical speed
    /// (no faster than 4 m/s down when diving).
    pub fn fall_entry(&self, cfg: &Configs, env: &Env) -> AirEntry {
        let mut v = env.mover_vel;
        v.y = self.vy;
        if self.dive && -4. <= v.y {
            v.y = -4.;
        }
        let h = V3::new(v.x, 0., v.z);
        let dir = if h.x.abs() > 0.01 || h.z.abs() > 0.01 { h.norm() } else { env.hero.fwd };
        let dir = if dir.x.abs() > 0.01 || dir.y.abs() > 0.01 || dir.z.abs() > 0.01 { V3::new(dir.x, 0., dir.z).norm() } else { dir };
        let h_speed = h.len();
        let kind = if self.dive { KIND_DIVE } else { KIND_FALL };
        let sd = if self.dive {
            &cfg.traversal.jump_configs.dive_jump_speed.standard_data
        } else {
            &cfg.traversal.jump_configs.ground_jump_speed.standard_data
        };
        let input = if sd.run_speed_max_max > 0.001 { (h_speed / sd.run_speed_max_max).min(1.) } else { 1. };
        let g = if self.gravity_after.abs() < 0.0001 { 26. } else { self.gravity_after };
        AirEntry {
            dir,
            vel: self.vel,
            vy: v.y,
            h_speed,
            gravity: g,
            gravity_after: g,
            fall_time: self.fall_time,
            max_height: self.max_height,
            input,
            kind,
            kind2: self.kind,
            ..Default::default()
        }
    }
}

/// exe+a2f110: v at length `l` (along x when v is zero)
fn scaled(v: V3, l: f32) -> V3 {
    let d = v.dot(v);
    if d >= 1e-15 {
        v * (l / d.sqrt())
    } else {
        V3::new(l, 0., 0.)
    }
}
