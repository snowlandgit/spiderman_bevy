//! The hero's traversal tracker (Hero::HeroTraversalTracker), as far as the swing, swing jump and fall read it:
//! momentum (exe+8630f0), the blend of the swing setups by speed and momentum (exe+864660), and fall gravity and terminal
//! velocity (exe+85f580). Offsets are the tracker's.
use crate::config::{Configs, DecayData, MomentumStage, ReleaseParams, SearchParams, SwingSetup};
use crate::math::{approach, lerp, remap, V3};

#[derive(Clone, Copy, Debug, Default)]
pub struct Blended {
    /// +0x3a8
    pub search: SearchParams,
    /// +0x408: speed +0x410, turn +0x478, gravity +0x4b8
    pub motion: crate::config::MotionParams,
    /// +0x528
    pub release: ReleaseParams,
}

#[derive(Clone, Debug)]
pub struct Tracker {
    /// +0x1e8
    pub momentum: f32,
    /// +0x1ec / +0x26c: recent momentum gains (time left, value); +0x30c the next slot
    pub ring_time: [f32; 32],
    pub ring_value: [f32; 32],
    pub ring_next: usize,
    /// +0x314: no decay
    pub hold: bool,
    /// +0x310: momentum / max, eased
    pub momentum_frac: f32,
    /// +0x320.. the momentum stage now
    pub stage_momentum: f32,
    pub terminal_floor: f32,
    pub gravity_scale: f32,
    pub line_length_tweak: f32,
    pub line_angle_tweak: f32,
    pub pivot_factor: [f32; 3],
    pub turn_speed_scale: f32,
    /// +0x5e8: speed blend (kept while airborne)
    pub speed_blend: f32,
    pub params: Blended,
    /// +0x178 fall gravity, +0x174 terminal velocity (both positive), +0x170 its rate
    pub fall_gravity: f32,
    pub terminal: f32,
    /// +0x364: time since a forward action (stays 0 here, as in the research harness)
    pub forward_action_time: f32,
    /// the swing skill level (exe+cc0b20; 3 = all upgrades)
    pub skill_level: i32,
    /// +0x150: the traversal state (2: the fall keeps its own clock)
    pub state: i32,
    /// +0x17d: a mission's fall gravity is in force (the air states then take +0x178 at the apex)
    pub fall_gravity_override: bool,
    /// +0x2ec..+0x308: cooldowns the tracker's own update counts down (exe+862d10); +0x2f4 the swing release's
    /// momentum boost, +0x2f8 exe+861cd0's
    pub cooldowns: [f32; 8],
}

impl Default for Tracker {
    fn default() -> Self {
        Self {
            momentum: 0.,
            ring_time: [0.; 32],
            ring_value: [0.; 32],
            ring_next: 0,
            hold: false,
            momentum_frac: 0.,
            stage_momentum: 0.,
            terminal_floor: 0.,
            gravity_scale: 1.,
            line_length_tweak: 0.,
            line_angle_tweak: 0.,
            pivot_factor: [1.; 3],
            turn_speed_scale: 1.,
            speed_blend: 0.,
            params: Blended::default(),
            fall_gravity: 0.,
            terminal: 0.,
            forward_action_time: 0.,
            skill_level: 3,
            state: 0,
            fall_gravity_override: false,
            cooldowns: [0.; 8],
        }
    }
}

/// What the tracker reads off the mover each frame
#[derive(Clone, Copy, Debug, Default)]
pub struct MoverView {
    pub velocity: V3,
    pub airborne: bool,
    /// +0x430: height above the ground (> 8: no ground release params)
    pub height_above_ground: f32,
}

fn decay_at(list: &[DecayData], momentum: f32, field: impl Fn(&DecayData) -> f32) -> f32 {
    // exe+85f810 / the loop in exe+8630f0: the first entry above `momentum` and the one before it
    if list.is_empty() {
        return 1.;
    }
    let mut prev = &list[0];
    for e in list.iter().skip(1) {
        if momentum < e.momentum_value {
            let t = remap(momentum, prev.momentum_value, e.momentum_value);
            return lerp(field(prev), field(e), t);
        }
        prev = e;
    }
    field(prev)
}

/// exe+85ed20, 85e5e0, 85e330, 85ef50 and the inline turn block: every float field from a to b by t
fn lerp_setup(a: &SwingSetup, b: &SwingSetup, t: f32) -> Blended {
    let f = |x: f32, y: f32| lerp(x, y, t);
    let sa = &a.search_params;
    let sb = &b.search_params;
    let search = SearchParams {
        broad_search_radius: f(sa.broad_search_radius, sb.broad_search_radius),
        narrow_search_radius: f(sa.narrow_search_radius, sb.narrow_search_radius),
        ideal_line_length_forward: f(sa.ideal_line_length_forward, sb.ideal_line_length_forward),
        ideal_line_length_turn: f(sa.ideal_line_length_turn, sb.ideal_line_length_turn),
        ideal_angle_forward: f(sa.ideal_angle_forward, sb.ideal_angle_forward),
        ideal_angle_turn: f(sa.ideal_angle_turn, sb.ideal_angle_turn),
        ideal_angle_turn_speed_min: f(sa.ideal_angle_turn_speed_min, sb.ideal_angle_turn_speed_min),
        ideal_angle_turn_speed_max: f(sa.ideal_angle_turn_speed_max, sb.ideal_angle_turn_speed_max),
        ideal_angle_fall: f(sa.ideal_angle_fall, sb.ideal_angle_fall),
        ideal_angle_fall_speed_min: f(sa.ideal_angle_fall_speed_min, sb.ideal_angle_fall_speed_min),
        ideal_angle_fall_speed_max: f(sa.ideal_angle_fall_speed_max, sb.ideal_angle_fall_speed_max),
        ideal_angle_dive: f(sa.ideal_angle_dive, sb.ideal_angle_dive),
        ideal_angle_dive_speed_min: f(sa.ideal_angle_dive_speed_min, sb.ideal_angle_dive_speed_min),
        ideal_angle_dive_speed_max: f(sa.ideal_angle_dive_speed_max, sb.ideal_angle_dive_speed_max),
        near_ground_distance_min: f(sa.near_ground_distance_min, sb.near_ground_distance_min),
        near_ground_distance_max: f(sa.near_ground_distance_max, sb.near_ground_distance_max),
        near_ground_angle: f(sa.near_ground_angle, sb.near_ground_angle),
        line_length_fall_tweak: f(sa.line_length_fall_tweak, sb.line_length_fall_tweak),
        line_length_dive_tweak: f(sa.line_length_dive_tweak, sb.line_length_dive_tweak),
        line_length_tweak_speed_min: f(sa.line_length_tweak_speed_min, sb.line_length_tweak_speed_min),
        line_length_tweak_speed_max: f(sa.line_length_tweak_speed_max, sb.line_length_tweak_speed_max),
    };
    let (pa, pb) = (&a.motion_params.speed_params, &b.motion_params.speed_params);
    let speed = crate::config::SpeedParams {
        fall_speed_threshold_min: f(pa.fall_speed_threshold_min, pb.fall_speed_threshold_min),
        fall_speed_threshold_mid: f(pa.fall_speed_threshold_mid, pb.fall_speed_threshold_mid),
        fall_speed_threshold_max: f(pa.fall_speed_threshold_max, pb.fall_speed_threshold_max),
        terminal_velocity_horz_min: f(pa.terminal_velocity_horz_min, pb.terminal_velocity_horz_min),
        terminal_velocity_horz_mid: f(pa.terminal_velocity_horz_mid, pb.terminal_velocity_horz_mid),
        terminal_velocity_horz_max: f(pa.terminal_velocity_horz_max, pb.terminal_velocity_horz_max),
        terminal_velocity_pure_max: f(pa.terminal_velocity_pure_max, pb.terminal_velocity_pure_max),
        terminal_velocity_min_percent: f(pa.terminal_velocity_min_percent, pb.terminal_velocity_min_percent),
        terminal_velocity_min_floor: f(pa.terminal_velocity_min_floor, pb.terminal_velocity_min_floor),
        terminal_velocity_max_floor: f(pa.terminal_velocity_max_floor, pb.terminal_velocity_max_floor),
        input_decel_zero: f(pa.input_decel_zero, pb.input_decel_zero),
        input_decel_back: f(pa.input_decel_back, pb.input_decel_back),
        in_speed_carryover: f(pa.in_speed_carryover, pb.in_speed_carryover),
        speed_boost_target: f(pa.speed_boost_target, pb.speed_boost_target),
        speed_boost_accel: f(pa.speed_boost_accel, pb.speed_boost_accel),
        speed_boost_accel_accel: f(pa.speed_boost_accel_accel, pb.speed_boost_accel_accel),
        release_boost_xz: f(pa.release_boost_xz, pb.release_boost_xz),
        release_boost_alt_min: f(pa.release_boost_alt_min, pb.release_boost_alt_min),
        jump_boost_xz: f(pa.jump_boost_xz, pb.jump_boost_xz),
        jump_boost_pitch_low_min: f(pa.jump_boost_pitch_low_min, pb.jump_boost_pitch_low_min),
        jump_boost_pitch_low_max: f(pa.jump_boost_pitch_low_max, pb.jump_boost_pitch_low_max),
        jump_boost_pitch_high_min: f(pa.jump_boost_pitch_high_min, pb.jump_boost_pitch_high_min),
        jump_boost_pitch_high_max: f(pa.jump_boost_pitch_high_max, pb.jump_boost_pitch_high_max),
    };
    let (ta, tb) = (&a.motion_params.turn_params, &b.motion_params.turn_params);
    let turn = crate::config::TurnParams {
        turn_speed_min_min: f(ta.turn_speed_min_min, tb.turn_speed_min_min),
        turn_speed_min_max: f(ta.turn_speed_min_max, tb.turn_speed_min_max),
        turn_speed_max_min: f(ta.turn_speed_max_min, tb.turn_speed_max_min),
        turn_speed_max_max: f(ta.turn_speed_max_max, tb.turn_speed_max_max),
        turn_gain_min: f(ta.turn_gain_min, tb.turn_gain_min),
        turn_gain_max: f(ta.turn_gain_max, tb.turn_gain_max),
        turn_damp_min: f(ta.turn_damp_min, tb.turn_damp_min),
        turn_damp_max: f(ta.turn_damp_max, tb.turn_damp_max),
        turn_ramp_speed: f(ta.turn_ramp_speed, tb.turn_ramp_speed),
        turn_speed_tilt_angle_min: f(ta.turn_speed_tilt_angle_min, tb.turn_speed_tilt_angle_min),
        turn_speed_tilt_angle_max: f(ta.turn_speed_tilt_angle_max, tb.turn_speed_tilt_angle_max),
        turn_speed_tilt_scale: f(ta.turn_speed_tilt_scale, tb.turn_speed_tilt_scale),
        turn_speed_pitch_min: f(ta.turn_speed_pitch_min, tb.turn_speed_pitch_min),
        turn_speed_pitch_max: f(ta.turn_speed_pitch_max, tb.turn_speed_pitch_max),
    };
    let (ga, gb) = (&a.motion_params.gravity_params, &b.motion_params.gravity_params);
    let gravity = crate::config::GravityParams {
        gravity_fall_init: f(ga.gravity_fall_init, gb.gravity_fall_init),
        gravity_fall_turn: f(ga.gravity_fall_turn, gb.gravity_fall_turn),
        gravity_fall_hold: f(ga.gravity_fall_hold, gb.gravity_fall_hold),
        init_tilt_angle_min: f(ga.init_tilt_angle_min, gb.init_tilt_angle_min),
        init_tilt_angle_max: f(ga.init_tilt_angle_max, gb.init_tilt_angle_max),
        rise_pitch_angle_min: f(ga.rise_pitch_angle_min, gb.rise_pitch_angle_min),
        rise_pitch_angle_max: f(ga.rise_pitch_angle_max, gb.rise_pitch_angle_max),
        rise_tilt_angle_min: f(ga.rise_tilt_angle_min, gb.rise_tilt_angle_min),
        rise_tilt_angle_max: f(ga.rise_tilt_angle_max, gb.rise_tilt_angle_max),
        rise_low_speed_min: f(ga.rise_low_speed_min, gb.rise_low_speed_min),
        rise_low_speed_max: f(ga.rise_low_speed_max, gb.rise_low_speed_max),
        rise_high_speed_min: f(ga.rise_high_speed_min, gb.rise_high_speed_min),
        rise_high_speed_max: f(ga.rise_high_speed_max, gb.rise_high_speed_max),
        rise_gravity_low_min: f(ga.rise_gravity_low_min, gb.rise_gravity_low_min),
        rise_gravity_low_max: f(ga.rise_gravity_low_max, gb.rise_gravity_low_max),
        rise_gravity_high_min: f(ga.rise_gravity_high_min, gb.rise_gravity_high_min),
        rise_gravity_high_max: f(ga.rise_gravity_high_max, gb.rise_gravity_high_max),
        rise_gravity_low_min_zero: f(ga.rise_gravity_low_min_zero, gb.rise_gravity_low_min_zero),
        rise_gravity_low_max_zero: f(ga.rise_gravity_low_max_zero, gb.rise_gravity_low_max_zero),
        rise_gravity_high_min_zero: f(ga.rise_gravity_high_min_zero, gb.rise_gravity_high_min_zero),
        rise_gravity_high_max_zero: f(ga.rise_gravity_high_max_zero, gb.rise_gravity_high_max_zero),
        rise_gravity_low_tilt: f(ga.rise_gravity_low_tilt, gb.rise_gravity_low_tilt),
        rise_gravity_high_tilt: f(ga.rise_gravity_high_tilt, gb.rise_gravity_high_tilt),
        rise_line_length_scale: f(ga.rise_line_length_scale, gb.rise_line_length_scale),
        rise_line_length_min: f(ga.rise_line_length_min, gb.rise_line_length_min),
        rise_line_length_max: f(ga.rise_line_length_max, gb.rise_line_length_max),
    };
    let set = |x: &crate::config::ReleaseParamSet, y: &crate::config::ReleaseParamSet| crate::config::ReleaseParamSet {
        jump_boost: f(x.jump_boost, y.jump_boost),
        vert_floor_base: f(x.vert_floor_base, y.vert_floor_base),
        vert_floor_jump: f(x.vert_floor_jump, y.vert_floor_jump),
    };
    let (ra, rb) = (&a.release_params, &b.release_params);
    let (da, db) = (&ra.release_gravity_data, &rb.release_gravity_data);
    let release = ReleaseParams {
        params_fall: set(&ra.params_fall, &rb.params_fall),
        params_low: set(&ra.params_low, &rb.params_low),
        params_middle: set(&ra.params_middle, &rb.params_middle),
        params_high: set(&ra.params_high, &rb.params_high),
        release_gravity_data: crate::config::ReleaseGravityData {
            gravity_release_low: f(da.gravity_release_low, db.gravity_release_low),
            gravity_release_mid: f(da.gravity_release_mid, db.gravity_release_mid),
            gravity_release_high: f(da.gravity_release_high, db.gravity_release_high),
            gravity_jump_low: f(da.gravity_jump_low, db.gravity_jump_low),
            gravity_jump_mid: f(da.gravity_jump_mid, db.gravity_jump_mid),
            gravity_jump_high: f(da.gravity_jump_high, db.gravity_jump_high),
            gravity_angle_low: f(da.gravity_angle_low, db.gravity_angle_low),
            gravity_angle_mid: f(da.gravity_angle_mid, db.gravity_angle_mid),
            gravity_angle_high: f(da.gravity_angle_high, db.gravity_angle_high),
        },
    };
    Blended { search, motion: crate::config::MotionParams { speed_params: speed, turn_params: turn, gravity_params: gravity }, release }
}

impl Tracker {
    /// exe+85f580, once a frame before the states run
    pub fn update(&mut self, cfg: &Configs, mover: MoverView, dt: f32) {
        // exe+862d10 (the component's update, which tools/native_oracle doesn't run): the cooldowns
        for c in self.cooldowns.iter_mut() {
            *c = (*c - dt).max(0.);
        }
        self.update_momentum(cfg, dt);
        self.blend_setups(cfg, mover);
        // fall gravity and terminal velocity (no mission overrides)
        let t = &cfg.traversal;
        self.fall_gravity = t.standard_fall_gravity;
        let mut target = t.standard_fall_terminal_velocity;
        let max = t.standard_fall_terminal_velocity_max;
        let vy = mover.velocity.y;
        if max > 0. && vy < -1. {
            target = self.terminal.max(target).min(max);
            if vy < 0.01 - self.terminal {
                target = approach(self.terminal, max, t.standard_fall_term_vel_accel, dt);
            }
        }
        if vy <= -target {
            self.terminal = self.terminal.min(vy.abs());
            self.terminal = approach(self.terminal, target, 30., dt);
        } else {
            self.terminal = target;
        }
    }

    /// exe+8630f0
    fn update_momentum(&mut self, cfg: &Configs, dt: f32) {
        let mc = &cfg.swing.momentum_config;
        let mut held = 0f32;
        for i in 0..32 {
            let t = (self.ring_time[i] - dt).max(0.);
            self.ring_time[i] = t;
            if t > 0.0001 && self.ring_value[i] > held {
                held = self.ring_value[i];
            }
        }
        let max = mc.max_momentum.max(0.);
        self.momentum = self.momentum.min(max);
        let rate = decay_at(&mc.decay_data_air, self.momentum, |d| d.decay_rate);
        if held < self.momentum && !self.hold {
            self.momentum = (self.momentum - rate * dt).max(0.);
        }
        let frac = if max > 0. { (self.momentum / max).clamp(0., 1.) } else { 0. };
        self.momentum_frac = approach(self.momentum_frac, frac, 3., dt);
        // the momentum stage
        let stages = &mc.momentum_stages;
        let default = MomentumStage {
            gravity_scale: 1.,
            true_pivot_factor_start: 1.,
            true_pivot_factor_trough: 1.,
            true_pivot_factor_final: 1.,
            turn_speed_scale: 1.,
            skill_offset_for_horz_floor: vec![0.; 3],
            ..Default::default()
        };
        let mut prev = &default;
        let mut next = &default;
        let mut t = 0.;
        for s in stages.iter() {
            next = s;
            if self.momentum < s.momentum_value {
                t = remap(self.momentum, prev.momentum_value, s.momentum_value);
                break;
            }
            prev = s;
            t = 1.;
        }
        let skill = |s: &MomentumStage| {
            if self.skill_level > 0 {
                let i = (self.skill_level.min(3) - 1) as usize;
                s.skill_offset_for_horz_floor.get(i).copied().unwrap_or(0.)
            } else {
                0.
            }
        };
        self.stage_momentum = self.momentum;
        self.terminal_floor = lerp(prev.terminal_velocity_horz_floor + skill(prev), next.terminal_velocity_horz_floor + skill(next), t);
        self.gravity_scale = lerp(prev.gravity_scale, next.gravity_scale, t);
        self.line_length_tweak = lerp(prev.line_length_tweak, next.line_length_tweak, t);
        self.line_angle_tweak = lerp(prev.line_angle_tweak, next.line_angle_tweak, t);
        self.pivot_factor = [
            lerp(prev.true_pivot_factor_start, next.true_pivot_factor_start, t),
            lerp(prev.true_pivot_factor_trough, next.true_pivot_factor_trough, t),
            lerp(prev.true_pivot_factor_final, next.true_pivot_factor_final, t),
        ];
        self.turn_speed_scale = lerp(prev.turn_speed_scale, next.turn_speed_scale, t);
    }

    /// exe+864660: the slow setup at no speed or momentum, the standard one from 30 m/s or momentum 1; releases near the
    /// ground (under 8 m) use the ground setup's release parameters
    fn blend_setups(&mut self, cfg: &Configs, mover: MoverView) {
        self.speed_blend = if mover.airborne { self.speed_blend } else { 0. };
        let speed = mover.velocity.flat_len();
        self.speed_blend = self.speed_blend.max(remap(speed, 8., 30.));
        self.momentum = self.momentum.max(self.speed_blend);
        let f = self.momentum.min(1.);
        self.params = lerp_setup(&cfg.setup_slow, &cfg.setup_standard, f);
        if mover.height_above_ground < 8. {
            self.params.release = cfg.setup_ground.release_params;
        }
    }

    /// exe+85f220: momentum gained (while swinging), up to `cap`; recorded in the ring for its hold time
    pub fn add_momentum(&mut self, cfg: &Configs, amount: f32, cap: f32, advance: bool) {
        if amount < 0.0001 {
            return;
        }
        if self.momentum < cap {
            self.momentum = (self.momentum + amount).min(cap).min(cfg.swing.momentum_config.max_momentum);
        }
        self.ring_value[self.ring_next] = cap;
        self.ring_time[self.ring_next] = decay_at(&cfg.swing.momentum_config.decay_data_air, self.momentum, |d| d.decay_delay);
        if advance {
            self.ring_next = (self.ring_next + 1) % 32;
        }
    }

    /// exe+85f2e0: momentum capped at `value` and held for its delay
    pub fn hold_momentum(&mut self, cfg: &Configs, value: f32) {
        self.momentum = self.momentum.min(value);
        let delay = decay_at(&cfg.swing.momentum_config.decay_data_air, self.momentum, |d| d.decay_delay);
        self.ring_time[self.ring_next] = delay;
        self.ring_value[self.ring_next] = value;
        self.ring_next = (self.ring_next + 1) % 32;
    }
}
