//! Records written by tools/native_oracle (the game's own swing, swing jump and fall code run on scripted scenarios):
//! per frame the inputs and the state objects' memory before the transitions ("pre"), before the update ("mid") and
//! after it ("post"). Loaders map the game's offsets onto the port's fields, so a frame can be run from the game's
//! state and compared field by field.
use crate::math::{Rows, V3};
use crate::air::{AirEntry, AirLocal};
use crate::swing::{Env, FrameInput, Probes, SwingLocal, SwingProcessor};
use crate::tracker::Tracker;

#[derive(Clone)]
pub struct Snapshot {
    pub blobs: Vec<Vec<u8>>,
}

#[derive(Clone)]
pub struct Frame {
    pub index: i32,
    pub pre: Snapshot,
    pub mode: i32,
    pub flags: u32,
    pub request: u64,
    pub request_data: Vec<u8>,
    pub mid: Snapshot,
    pub displacement: V3,
    pub facing: V3,
    pub snap: i32,
    pub post: Snapshot,
    pub hero_after: [f32; 16],
    pub turn_v: f32,
    pub cam: [f32; 16],
    pub hero_before: [f32; 16],
    pub vel_before: V3,
    pub stick: [f32; 2],
    pub swing_button: f32,
    pub t: f32,
}

pub struct Record {
    pub names: Vec<String>,
    pub sizes: Vec<usize>,
    pub frames: Vec<Frame>,
}

pub const SWING: usize = 0;
pub const SWING_PROC: usize = 1;
pub const TRACKER: usize = 2;
pub const JUMP: usize = 3;
pub const FALL: usize = 4;
pub const JUMP_PROC: usize = 5;
pub const FALL_PROC: usize = 6;
pub const MOVER: usize = 7;
pub const ANIM: usize = 8;

struct Reader<'a> {
    b: &'a [u8],
    at: usize,
}
impl Reader<'_> {
    fn take(&mut self, n: usize) -> &[u8] {
        let s = &self.b[self.at..self.at + n];
        self.at += n;
        s
    }
    fn u32(&mut self) -> u32 {
        u32::from_le_bytes(self.take(4).try_into().unwrap())
    }
    fn i32(&mut self) -> i32 {
        i32::from_le_bytes(self.take(4).try_into().unwrap())
    }
    fn u64(&mut self) -> u64 {
        u64::from_le_bytes(self.take(8).try_into().unwrap())
    }
    fn f32(&mut self) -> f32 {
        f32::from_le_bytes(self.take(4).try_into().unwrap())
    }
    fn f32s<const N: usize>(&mut self) -> [f32; N] {
        std::array::from_fn(|_| self.f32())
    }
}

impl Record {
    pub fn load(path: &std::path::Path) -> std::io::Result<Self> {
        let b = std::fs::read(path)?;
        let mut r = Reader { b: &b, at: 0 };
        assert_eq!(r.take(8), b"SMORACLE", "not an oracle record");
        let _version = r.u32();
        let count = r.u32() as usize;
        let nb = r.u32() as usize;
        let mut names = vec![];
        let mut sizes = vec![];
        for _ in 0..nb {
            let n = r.take(16).to_vec();
            names.push(String::from_utf8_lossy(&n).trim_end_matches('\0').to_string());
            sizes.push(r.u32() as usize);
        }
        let snap = |r: &mut Reader| Snapshot { blobs: sizes.iter().map(|&s| r.take(s).to_vec()).collect() };
        let mut frames = Vec::with_capacity(count);
        for _ in 0..count {
            let index = r.i32();
            let pre = snap(&mut r);
            let mode = r.i32();
            let flags = r.u32();
            let request = r.u64();
            let request_data = r.take(0x100).to_vec();
            let mid = snap(&mut r);
            let d: [f32; 3] = r.f32s();
            let f: [f32; 3] = r.f32s();
            let snap_flag = r.i32();
            let post = snap(&mut r);
            let hero_after = r.f32s();
            let turn_v = r.f32();
            let cam = r.f32s();
            let hero_before = r.f32s();
            let vb: [f32; 3] = r.f32s();
            let inp: [f32; 4] = r.f32s();
            frames.push(Frame {
                index,
                pre,
                mode,
                flags,
                request,
                request_data,
                mid,
                displacement: V3::from_slice(&d),
                facing: V3::from_slice(&f),
                snap: snap_flag,
                post,
                hero_after,
                turn_v,
                cam,
                hero_before,
                vel_before: V3::from_slice(&vb),
                stick: [inp[0], inp[1]],
                swing_button: inp[2],
                t: inp[3],
            });
        }
        Ok(Record { names, sizes, frames })
    }
}

pub fn f(b: &[u8], off: usize) -> f32 {
    f32::from_le_bytes(b[off..off + 4].try_into().unwrap())
}
pub fn v3(b: &[u8], off: usize) -> V3 {
    V3::new(f(b, off), f(b, off + 4), f(b, off + 8))
}
pub fn i32_at(b: &[u8], off: usize) -> i32 {
    i32::from_le_bytes(b[off..off + 4].try_into().unwrap())
}
pub fn f64_at(b: &[u8], off: usize) -> f64 {
    f64::from_le_bytes(b[off..off + 8].try_into().unwrap())
}
fn floats<T: Copy>(b: &[u8], off: usize, n: usize) -> T {
    assert_eq!(std::mem::size_of::<T>(), n * 4);
    let v: Vec<f32> = (0..n).map(|i| f(b, off + i * 4)).collect();
    // SAFETY: T is a struct of `n` f32 fields only (repr(C))
    unsafe { std::ptr::read_unaligned(v.as_ptr() as *const T) }
}

/// The frame's environment as the oracle gave it to the states (the game clock runs 100 s + dt per frame)
pub fn env_of(fr: &Frame, dt: f32) -> Env {
    let mut hero = Rows::from_matrix(&fr.hero_before);
    hero.pos = V3::from_slice(&fr.hero_before[12..15]);
    Env {
        time: 100.0 + (fr.index as f64 + 1.0) * dt as f64,
        dt,
        hero,
        cam: Rows::from_matrix(&fr.cam),
        mover_vel: fr.vel_before,
        input: FrameInput { stick: fr.stick, swing_button: fr.swing_button, jump_pressed: fr.flags & 1 != 0, jump_held: false, look: 0. },
    }
}

/// The tracker's fields the states read
pub fn tracker_of(b: &[u8]) -> Tracker {
    use crate::config::*;
    let mut t = Tracker::default();
    t.momentum = f(b, 0x1e8);
    for i in 0..32 {
        t.ring_time[i] = f(b, 0x1ec + i * 4);
        t.ring_value[i] = f(b, 0x26c + i * 4);
    }
    t.ring_next = i32_at(b, 0x30c) as usize;
    t.momentum_frac = f(b, 0x310);
    t.stage_momentum = f(b, 0x320);
    t.terminal_floor = f(b, 0x324);
    t.gravity_scale = f(b, 0x334);
    t.line_length_tweak = f(b, 0x338);
    t.line_angle_tweak = f(b, 0x33c);
    t.pivot_factor = [f(b, 0x340), f(b, 0x344), f(b, 0x348)];
    t.turn_speed_scale = f(b, 0x34c);
    t.speed_blend = f(b, 0x5e8);
    t.terminal = f(b, 0x174);
    t.fall_gravity = f(b, 0x178);
    t.state = i32_at(b, 0x150);
    t.fall_gravity_override = b[0x17d] != 0;
    for i in 0..8 {
        t.cooldowns[i] = f(b, 0x2ec + i * 4);
    }
    t.params.search = floats::<SearchParams>(b, 0x3a8 + 8, 21);
    t.params.motion.speed_params = floats::<SpeedParams>(b, 0x410 + 8, 23);
    t.params.motion.turn_params = floats::<TurnParams>(b, 0x478 + 8, 14);
    t.params.motion.gravity_params = floats::<GravityParams>(b, 0x4b8 + 8, 26);
    let set = |o: usize| ReleaseParamSet { jump_boost: f(b, o + 8), vert_floor_base: f(b, o + 0xc), vert_floor_jump: f(b, o + 0x10) };
    t.params.release = ReleaseParams {
        params_fall: set(0x528 + 8),
        params_low: set(0x528 + 0x20),
        params_middle: set(0x528 + 0x38),
        params_high: set(0x528 + 0x50),
        release_gravity_data: floats::<ReleaseGravityData>(b, 0x528 + 0x68 + 8, 9),
    };
    t
}

pub fn processor_of(b: &[u8]) -> SwingProcessor {
    SwingProcessor { anchor: v3(b, 0x150), pivot: v3(b, 0x15c), hold: v3(b, 0x168), drift: f(b, 0x174) }
}

/// The swing state from its memory
pub fn swing_of(b: &[u8]) -> SwingLocal {
    let rows = |o: usize| Rows { side: v3(b, o), up: v3(b, o + 0x10), fwd: v3(b, o + 0x20), pos: v3(b, o + 0x30) };
    let mut probes = Probes::default();
    for i in 0..7 {
        probes.center[i] = f(b, 0x120 + 0x9c + i * 4);
    }
    for i in 0..8 {
        probes.side[i] = f(b, 0x120 + 0x160 + i * 4);
    }
    probes.stuck = f(b, 0x120 + 0x24c);
    probes.blocked = f(b, 0x120 + 0x98);
    SwingLocal {
        entry_time: f64_at(b, 0xd8),
        probes,
        hero: rows(0x398),
        cam: rows(0x3d8),
        input_dir: v3(b, 0x418),
        input_mag: f(b, 0x424),
        input_angle: f(b, 0x428),
        speed_input_smooth: f(b, 0x42c),
        speed_input: f(b, 0x430),
        speed_input_hold: f(b, 0x434),
        anchor: v3(b, 0x438),
        attach: v3(b, 0x444),
        min_time: f(b, 0x450),
        boost_target: f(b, 0x454),
        boost_accel_base: f(b, 0x458),
        boost_accel: f(b, 0x45c),
        boost_accel_accel: f(b, 0x460),
        boost_on: b[0x464] != 0,
        gravity_scale: f(b, 0x468),
        speed_change: f(b, 0x46c),
        push: v3(b, 0x470),
        probe_turn_scale: f(b, 0x47c),
        low_point: v3(b, 0x480),
        has_low_point: b[0x48c] != 0,
        init_pull: f(b, 0x490),
        floor_y: f(b, 0x494),
        floor_rate: f(b, 0x498),
        floor_vel: f(b, 0x49c),
        floor_acc: f(b, 0x4a0),
        rope_len0: f(b, 0x4a4),
        sink: f(b, 0x4a8),
        grav_fall_initial: f(b, 0x4ac),
        grav_fall_final: f(b, 0x4b0),
        grav_fall_hold: f(b, 0x4b4),
        vel: v3(b, 0x4b8),
        prev_vel: v3(b, 0x4c4),
        dir: v3(b, 0x4d0),
        along: v3(b, 0x4dc),
        prev_dir: v3(b, 0x4e8),
        dir_spring_v: f(b, 0x4f4),
        dir_time: f(b, 0x4f8),
        turn_v: f(b, 0x4fc),
        turn_ramp: f(b, 0x500),
        twist_v: f(b, 0x504),
        twist: f(b, 0x508),
        blend_in: f(b, 0x50c),
        gravity_blend: f(b, 0x510),
        gravity_blend_delay: f(b, 0x514),
        pivot_factor: f(b, 0x518),
        terminal: f(b, 0x51c),
        terminal_min: f(b, 0x520),
        terminal_max: f(b, 0x524),
        release_anim_rate: f(b, 0x528),
        release_anim_blend: f(b, 0x52c),
        last_dt: f(b, 0x530),
        release_pitch: f(b, 0x534),
        yaw_rate: f(b, 0x54c),
        look: f(b, 0x550),
        look_input: 0.,
        entry_input_dir: v3(b, 0x554),
        input_angle2: f(b, 0x560),
        entry_input_angle: f(b, 0x564),
        input_agree: f(b, 0x568),
        agree_peak: f(b, 0x56c),
        agree_timer: f(b, 0x570),
        phase: i32_at(b, 0x574),
        phase_time: f(b, 0x578),
        reverse: f(b, 0x57c),
        sub_state: b[0x580],
        b5f0: b[0x5f0] != 0,
        release_event: b[0x5f1] != 0,
        first: b[0x5f3] != 0,
        back_swing: b[0x5f7] != 0,
        b5f8: b[0x5f8] != 0,
        b5f9: b[0x5f9] != 0,
        forward_action: b[0x5fa] != 0,
        release_countdown: b[0x5fb] as i8,
    }
}

/// Named fields of the swing state to compare (name, game offset, port value)
pub fn swing_fields(s: &SwingLocal) -> Vec<(&'static str, usize, Vec<f32>)> {
    let v = |x: V3| vec![x.x, x.y, x.z];
    vec![
        ("vel", 0x4b8, v(s.vel)),
        ("dir", 0x4d0, v(s.dir)),
        ("along", 0x4dc, v(s.along)),
        ("prev_dir", 0x4e8, v(s.prev_dir)),
        ("input_dir", 0x418, v(s.input_dir)),
        ("input_mag", 0x424, vec![s.input_mag]),
        ("speed_input", 0x430, vec![s.speed_input]),
        ("boost_accel", 0x45c, vec![s.boost_accel]),
        ("speed_change", 0x46c, vec![s.speed_change]),
        ("push", 0x470, v(s.push)),
        ("probe_turn_scale", 0x47c, vec![s.probe_turn_scale]),
        ("init_pull", 0x490, vec![s.init_pull]),
        ("floor_y", 0x494, vec![s.floor_y]),
        ("floor_vel", 0x49c, vec![s.floor_vel]),
        ("floor_acc", 0x4a0, vec![s.floor_acc]),
        ("sink", 0x4a8, vec![s.sink]),
        ("dir_spring_v", 0x4f4, vec![s.dir_spring_v]),
        ("dir_time", 0x4f8, vec![s.dir_time]),
        ("turn_v", 0x4fc, vec![s.turn_v]),
        ("turn_ramp", 0x500, vec![s.turn_ramp]),
        ("twist_v", 0x504, vec![s.twist_v]),
        ("twist", 0x508, vec![s.twist]),
        ("blend_in", 0x50c, vec![s.blend_in]),
        ("gravity_blend", 0x510, vec![s.gravity_blend]),
        ("gravity_blend_delay", 0x514, vec![s.gravity_blend_delay]),
        ("pivot_factor", 0x518, vec![s.pivot_factor]),
        ("terminal", 0x51c, vec![s.terminal]),
        ("terminal_min", 0x520, vec![s.terminal_min]),
        ("terminal_max", 0x524, vec![s.terminal_max]),
        ("yaw_rate", 0x54c, vec![s.yaw_rate]),
        ("input_agree", 0x568, vec![s.input_agree]),
        ("reverse", 0x57c, vec![s.reverse]),
        ("phase", 0x574, vec![s.phase as f32]),
        ("grav_fall_initial", 0x4ac, vec![s.grav_fall_initial]),
        ("grav_fall_final", 0x4b0, vec![s.grav_fall_final]),
        ("rope_len0", 0x4a4, vec![s.rope_len0]),
        ("entry_input_angle", 0x564, vec![s.entry_input_angle]),
        ("input_angle2", 0x560, vec![s.input_angle2]),
    ]
}

/// The game's values of the same fields
pub fn native_fields(b: &[u8], names: &[(&'static str, usize, Vec<f32>)]) -> Vec<Vec<f32>> {
    names
        .iter()
        .map(|(n, off, port)| {
            if *n == "phase" {
                vec![i32_at(b, *off) as f32]
            } else {
                (0..port.len()).map(|i| f(b, off + i * 4)).collect()
            }
        })
        .collect()
}

/// The swing jump's or the fall's state from its memory
pub fn air_of(b: &[u8], fall: bool) -> AirLocal {
    let bit = |o: usize| b[o] != 0;
    let mut a = AirLocal::new(fall);
    a.entry_time = f64_at(b, 0xd8);
    a.dir = v3(b, 0x124);
    a.facing = v3(b, 0x130);
    a.carry = v3(b, 0x13c);
    a.vel = v3(b, 0x154);
    a.prev_vel = v3(b, 0x160);
    a.hold_facing = v3(b, 0x16c);
    a.last_vel = v3(b, 0x184);
    a.saved = v3(b, 0x1d0);
    a.entry_input = f(b, 0x1dc);
    a.gravity = f(b, 0x1e0);
    a.gravity_after = f(b, 0x1e4);
    a.fall_time = f(b, 0x1e8);
    a.vy_prev = f(b, 0x1ec);
    a.vy = f(b, 0x1f0);
    a.terminal = f(b, 0x1f4);
    a.anim_end = f(b, 0x1f8);
    a.gravity_switch_time = f(b, 0x1fc);
    a.anim_duration = f(b, 0x204);
    a.anim_fall_a = f(b, 0x208);
    a.anim_dive = f(b, 0x20c);
    a.anim_dive_ok = f(b, 0x210);
    a.anim_fall_b = f(b, 0x214);
    a.anim_land = f(b, 0x21c);
    a.vel_decay = f(b, 0x224);
    a.tracker_gravity = bit(0x228);
    a.thrust_accel = f(b, 0x250);
    a.thrust_gravity = f(b, 0x254);
    a.thrust_time = f(b, 0x258);
    a.speed = f(b, 0x25c);
    a.run_speed = f(b, 0x264);
    a.run_accel = f(b, 0x268);
    a.max_height = f(b, 0x26c);
    a.h_speed = f(b, 0x274);
    a.kind = i32_at(b, 0x2c0) as u8;
    a.kind2 = i32_at(b, 0x2c4) as u8;
    a.early = bit(0x2c8);
    a.no_early = bit(0x2c9);
    a.started = bit(0x2ca);
    a.b2cb = bit(0x2cb);
    a.b2cc = bit(0x2cc);
    a.thrust_done = bit(0x2d0);
    a.b2d1 = bit(0x2d1);
    a.anim_read = bit(0x2d2);
    a.fall_anim_done = bit(0x2d3);
    a.b2d4 = bit(0x2d4);
    a.b2d5 = bit(0x2d5);
    a.b2d6 = bit(0x2d6);
    a.b2d7 = bit(0x2d7);
    a.b2d8 = bit(0x2d8);
    a.dive = bit(0x2da);
    a.b2db = bit(0x2db);
    a.b2dc = bit(0x2dc);
    a.thrust_clock = f(b, 0x2e0);
    a.boost_speed = f(b, 0x2e4);
    a.boost_time = f(b, 0x2e8);
    a.boost_rate = f(b, 0x2ec);
    a.input_time = f(b, 0x2f0);
    a.input_out = f(b, 0x2f4);
    a.thrust_held = bit(0x2f8);
    a.turn_side = bit(0x2f9);
    a.facing_blend = f(b, 0x2fc);
    if fall {
        a.dive_input = f(b, 0x300);
        a.dive_time = f(b, 0x304);
        a.fall_clock = f(b, 0x308);
        a.diving = bit(0x30c);
        a.dive_drag = bit(0x30d);
        a.b30e = bit(0x30e);
        a.b310 = bit(0x310);
        a.b311 = bit(0x311);
    }
    a
}

/// A transition's jump data (the request the state machine got)
pub fn air_entry_of(b: &[u8]) -> AirEntry {
    AirEntry {
        dir: v3(b, 0x34),
        vel: v3(b, 0x40),
        facing: v3(b, 0x4c),
        vy: f(b, 0x58),
        h_speed: f(b, 0x5c),
        gravity: f(b, 0x60),
        gravity_after: f(b, 0x64),
        fall_time: f(b, 0x6c),
        max_height: f(b, 0x70),
        input: f(b, 0x74),
        boost_time: f(b, 0x78),
        gravity_switch_time: f(b, 0x7c),
        kind: b[0x81],
        kind2: b[0x82],
        flags: b[0x83],
    }
}

/// Compared values: (name, port, game)
pub type Fields = Vec<(&'static str, Vec<f32>, Vec<f32>)>;

/// The entry fields to compare
pub fn air_entry_fields(p: &AirEntry, g: &AirEntry) -> Fields {
    let v = |x: V3| vec![x.x, x.y, x.z];
    vec![
        ("dir", v(p.dir), v(g.dir)),
        ("vel", v(p.vel), v(g.vel)),
        ("facing", v(p.facing), v(g.facing)),
        ("vy", vec![p.vy], vec![g.vy]),
        ("h_speed", vec![p.h_speed], vec![g.h_speed]),
        ("gravity", vec![p.gravity], vec![g.gravity]),
        ("gravity_after", vec![p.gravity_after], vec![g.gravity_after]),
        ("fall_time", vec![p.fall_time], vec![g.fall_time]),
        ("max_height", vec![p.max_height], vec![g.max_height]),
        ("input", vec![p.input], vec![g.input]),
        ("boost_time", vec![p.boost_time], vec![g.boost_time]),
        ("gravity_switch_time", vec![p.gravity_switch_time], vec![g.gravity_switch_time]),
        ("kind", vec![p.kind as f32], vec![g.kind as f32]),
        ("kind2", vec![p.kind2 as f32], vec![g.kind2 as f32]),
        ("flags", vec![p.flags as f32], vec![g.flags as f32]),
    ]
}

/// Named fields of an air state to compare
pub fn air_fields(p: &AirLocal, g: &AirLocal) -> Fields {
    let v = |x: V3| vec![x.x, x.y, x.z];
    let bl = |x: bool| vec![x as u8 as f32];
    let mut out = vec![
        ("dir", v(p.dir), v(g.dir)),
        ("facing", v(p.facing), v(g.facing)),
        ("carry", v(p.carry), v(g.carry)),
        ("vel", v(p.vel), v(g.vel)),
        ("hold_facing", v(p.hold_facing), v(g.hold_facing)),
        ("last_vel", v(p.last_vel), v(g.last_vel)),
        ("entry_input", vec![p.entry_input], vec![g.entry_input]),
        ("gravity", vec![p.gravity], vec![g.gravity]),
        ("gravity_after", vec![p.gravity_after], vec![g.gravity_after]),
        ("fall_time", vec![p.fall_time], vec![g.fall_time]),
        ("vy_prev", vec![p.vy_prev], vec![g.vy_prev]),
        ("vy", vec![p.vy], vec![g.vy]),
        ("terminal", vec![p.terminal], vec![g.terminal]),
        ("gravity_switch_time", vec![p.gravity_switch_time], vec![g.gravity_switch_time]),
        ("speed", vec![p.speed], vec![g.speed]),
        ("run_speed", vec![p.run_speed], vec![g.run_speed]),
        ("run_accel", vec![p.run_accel], vec![g.run_accel]),
        ("max_height", vec![p.max_height], vec![g.max_height]),
        ("h_speed", vec![p.h_speed], vec![g.h_speed]),
        ("kind", vec![p.kind as f32], vec![g.kind as f32]),
        ("kind2", vec![p.kind2 as f32], vec![g.kind2 as f32]),
        ("early", bl(p.early), bl(g.early)),
        ("started", bl(p.started), bl(g.started)),
        ("thrust_done", bl(p.thrust_done), bl(g.thrust_done)),
        ("thrust_clock", vec![p.thrust_clock], vec![g.thrust_clock]),
        ("thrust_time", vec![p.thrust_time], vec![g.thrust_time]),
        ("dive", bl(p.dive), bl(g.dive)),
        ("boost_speed", vec![p.boost_speed], vec![g.boost_speed]),
        ("boost_time", vec![p.boost_time], vec![g.boost_time]),
        ("input_time", vec![p.input_time], vec![g.input_time]),
        ("input_out", vec![p.input_out], vec![g.input_out]),
        ("turn_side", bl(p.turn_side), bl(g.turn_side)),
        ("facing_blend", vec![p.facing_blend], vec![g.facing_blend]),
        ("tracker_gravity", bl(p.tracker_gravity), bl(g.tracker_gravity)),
    ];
    if p.fall {
        out.extend([
            ("dive_input", vec![p.dive_input], vec![g.dive_input]),
            ("dive_time", vec![p.dive_time], vec![g.dive_time]),
            ("fall_clock", vec![p.fall_clock], vec![g.fall_clock]),
            ("diving", bl(p.diving), bl(g.diving)),
            ("dive_drag", bl(p.dive_drag), bl(g.dive_drag)),
            ("b30e", bl(p.b30e), bl(g.b30e)),
        ]);
    }
    out
}

/// The pairs that differ by more than `tol` (NaN matches NaN, infinities themselves)
pub fn differing(fields: &Fields, tol: f32) -> Vec<String> {
    let mut out = vec![];
    for (name, p, g) in fields {
        let bad = p.iter().zip(g.iter()).any(|(a, b)| {
            if a.is_finite() && b.is_finite() {
                (a - b).abs() > tol
            } else {
                !(a.is_nan() && b.is_nan()) && a != b
            }
        });
        if bad {
            out.push(format!("{name} port {p:?} game {g:?}"));
        }
    }
    out
}
