//! Hero::HeroStateSwingLocal (Spider-Man.exe 4.0630, vtable exe+38ce990): the swing's motion. Entry exe+ab97e0, per frame
//! exe+ac30e0 (input exe+abcf40, integration exe+abdb30, facing exe+abd820, momentum exe+ac36f0), transition check
//! exe+aba1f0 with the release velocity of exe+ac1680 and the automatic release of exe+ac2200. Field comments give the
//! state's offsets. Ported from Ghidra's decompilation, with argument order and constants taken from the disassembly;
//! tools/native_oracle runs the game's own code on the same inputs to compare.
use crate::config::Configs;
use crate::math::*;
use crate::tracker::Tracker;

/// What the states read each frame
#[derive(Clone, Copy, Debug, Default)]
pub struct FrameInput {
    /// left stick, x right, y forward (-1..1)
    pub stick: [f32; 2],
    /// the swing button (R2), 0..1
    pub swing_button: f32,
    /// the jump button pressed within the buffer window (0.05 s): the swing's release event
    pub jump_pressed: bool,
    /// |right stick x| (the camera's look input)
    pub look: f32,
}

#[derive(Clone, Copy, Debug, Default)]
pub struct Env {
    /// the game clock (seconds)
    pub time: f64,
    pub dt: f32,
    /// the hero's rows as the state reads them (the mover's turn of the previous frame) and his position now
    pub hero: Rows,
    pub cam: Rows,
    /// the mover's velocity (its last move)
    pub mover_vel: V3,
    pub input: FrameInput,
}

impl Env {
    /// exe+b7e920 as ArkWeb's research harness stands in for it: the stick as a flat world direction seen from the
    /// camera (the camera's side row points left), its magnitude with a radial dead zone 0.01..0.99, and its angle
    pub fn stick_world(&self) -> (V3, f32, f32) {
        let [x, y] = self.input.stick;
        let m = (x * x + y * y).sqrt();
        let mag = ((m - 0.01) / (0.99 - 0.01)).clamp(0., 1.);
        let angle = atan2(x, y);
        if mag <= 0.0001 {
            return (V3::ZERO, mag, angle);
        }
        let f = self.cam.fwd;
        let s = self.cam.side;
        let fl = (f.x * f.x + f.z * f.z).sqrt();
        let sl = (s.x * s.x + s.z * s.z).sqrt();
        let (fx, fz, sx, sz) = (f.x / fl, f.z / fl, s.x / sl, s.z / sl);
        let (dx, dz) = (-sx * x + fx * y, -sz * x + fz * y);
        let dl = (dx * dx + dz * dz).sqrt();
        (V3::new(dx / dl, 0., dz / dl), mag, angle)
    }
    /// exe+1f2d8f0: the stick's magnitude and angle, no dead zone
    pub fn stick_raw(&self) -> (f32, f32) {
        let [x, y] = self.input.stick;
        ((x * x + y * y).sqrt().min(1.), atan2(x, y))
    }
}

/// The swing's entry data (built by the transition manager's slot 81, exe+97c470: constructor exe+ab3820, points exe+ab5da0)
#[derive(Clone, Copy, Debug)]
pub struct SwingEntry {
    /// +0x24: the pivot (the hunter's anchor, pushed out from the wall)
    pub anchor: V3,
    /// +0x30: the web's point on the surface
    pub attach: V3,
    /// +0x54
    pub min_time: f32,
    /// +0x6c flags: 1 input angle given (+0x58), 2 velocity given (+0x5c), 4 blend given (+0x68), 8 rising starts in the
    /// second phase, 0x40, 0x100 (a forward action just before)
    pub flags: u16,
    pub input_angle: f32,
    pub velocity: V3,
    pub blend: f32,
}
impl SwingEntry {
    pub fn new(anchor: V3, attach: V3) -> Self {
        Self { anchor, attach, min_time: 0.2, flags: 0, input_angle: 0., velocity: V3::ZERO, blend: 0. }
    }
}

/// The swing's processor (Hero::HeroStateSwing, the animation side) as far as the motion reads it: the anchor it slides
/// (exe+ab8410, ArkWeb's PivotDrift port)
#[derive(Clone, Copy, Debug, Default)]
pub struct SwingProcessor {
    /// +0x150: the anchor the swing reads each frame
    pub anchor: V3,
    /// +0x15c: the pivot as the hunter placed it
    pub pivot: V3,
    /// +0x168: the hold (the web's surface point)
    pub hold: V3,
    /// +0x174: how far the anchor has slid (never back)
    pub drift: f32,
}
impl SwingProcessor {
    pub fn start(&mut self, e: &SwingEntry) {
        self.anchor = e.anchor;
        self.pivot = e.anchor;
        self.hold = e.attach;
        self.drift = 0.;
    }
    /// exe+ab8410's first part: the anchor slides along a level segment at the hold's height, from the pivot toward a
    /// point 1 m off the hold, by the larger of where he projects on it, (time - 2 s) * 2/3, and what it already slid
    pub fn drift(&mut self, pos: V3, swing_time: f32) {
        let (pv, ho) = (self.pivot, self.hold);
        let (mut dx, mut dz) = (pv.x - ho.x, pv.z - ho.z);
        let m = dx.abs().max(dz.abs());
        if m > 0. {
            dx /= m;
            dz /= m;
            let l = 1. / (dx * dx + dz * dz).sqrt();
            dx *= l;
            dz *= l;
        }
        let a = V3::new(pv.x, ho.y, pv.z);
        let b = V3::new(ho.x + dx, ho.y, ho.z + dz);
        let ab = b - a;
        let l = ab.dot(ab);
        let u = if l >= 1e-8 { ((pos - a).dot(ab) / l).clamp(0., 1.) } else { 0. };
        let f = ((swing_time - 2.) * 0.6666667).clamp(0., 1.).max(u).max(self.drift);
        self.drift = f;
        self.anchor = V3::new(a.x + ab.x * f, pv.y, a.z + ab.z * f);
    }
}

/// The swing's obstacle probes (+0x120, exe+b919c0 / b90af0 / b90780): horizontal distances to what rays found, 40 m
/// when nothing. Filled by the host's ray casts; clear (all 40) by default, as in the research harness.
#[derive(Clone, Copy, Debug)]
pub struct Probes {
    /// +0x9c: the fan ahead, read as c(i), i = -3..3
    pub center: [f32; 7],
    /// +0x160: the two side fans, s(i, side)
    pub side: [f32; 8],
    /// +0x24c: time stuck against something; +0x98: time the velocity sweep was blocked
    pub stuck: f32,
    pub blocked: f32,
}
impl Default for Probes {
    fn default() -> Self {
        Self { center: [40.; 7], side: [40.; 8], stuck: 0., blocked: 0. }
    }
}
impl Probes {
    /// exe+b8fda0
    pub fn c(&self, i: i32) -> f32 {
        self.center[(i + 3) as usize]
    }
    /// exe+b8fdb0
    pub fn count(&self) -> i32 {
        let mut i = 0;
        loop {
            let n = i + 1;
            if self.center[3] < (n as f32) + (n as f32) {
                break;
            }
            i = n;
            if n >= 4 {
                break;
            }
        }
        i.min(3)
    }
    /// exe+b8fdf0
    pub fn s(&self, i: i32, flag: bool) -> f32 {
        self.side[(i + if flag { 0 } else { 4 }) as usize]
    }
    /// exe+b91970: release because he is stuck
    pub fn blocked(&self) -> bool {
        self.stuck > 0.05 || self.blocked > 0.1
    }
}

/// What a frame of the swing hands the mover
#[derive(Clone, Copy, Debug, Default)]
pub struct SwingOutput {
    pub displacement: V3,
    pub facing: V3,
    pub snap: bool,
}

/// The release (exe+ac1680) handed to the transition manager's slot 82 (exe+97c9d0), which builds the swing jump
#[derive(Clone, Copy, Debug, Default)]
pub struct SwingRelease {
    /// +0x540
    pub velocity: V3,
    /// +0x53c: the swing jump's rising gravity
    pub gravity: f32,
    /// +0x538: released with the jump button (or the fast automatic release)
    pub jumped: bool,
    /// the swing direction's pitch above level at release (+0x534, degrees)
    pub pitch: f32,
    /// +0x528, +0x52c: the release animation's rate and blend
    pub anim_rate: f32,
    pub anim_blend: f32,
    /// +0x539: released high (above ReleaseAngleHighStart)
    pub high: bool,
    /// the low or early release path (gravity 24)
    pub early: bool,
}

#[derive(Clone, Debug)]
pub struct SwingLocal {
    /// +0xd8
    pub entry_time: f64,
    pub probes: Probes,
    /// +0x398.. the rows the state copied this frame
    pub hero: Rows,
    pub cam: Rows,
    /// +0x418 the stick's world direction, +0x424 its magnitude, +0x428 its angle
    pub input_dir: V3,
    pub input_mag: f32,
    pub input_angle: f32,
    /// +0x42c, +0x430 (the throttle: forward stick along travel, negative pulling back), +0x434
    pub speed_input_smooth: f32,
    pub speed_input: f32,
    pub speed_input_hold: f32,
    /// +0x438 the anchor (the processor's, each frame), +0x444 the web's surface point
    pub anchor: V3,
    pub attach: V3,
    /// +0x450
    pub min_time: f32,
    /// +0x454.. the entry speed boost: target, base acceleration, acceleration, its growth, on
    pub boost_target: f32,
    pub boost_accel_base: f32,
    pub boost_accel: f32,
    pub boost_accel_accel: f32,
    pub boost_on: bool,
    /// +0x468 (the momentum stage's gravity scale at entry)
    pub gravity_scale: f32,
    /// +0x46c
    pub speed_change: f32,
    /// +0x470 push off obstacles (abb030), +0x47c the probes' turn scale
    pub push: V3,
    pub probe_turn_scale: f32,
    /// +0x480, +0x48c the low point under a swing floor volume
    pub low_point: V3,
    pub has_low_point: bool,
    /// +0x490
    pub init_pull: f32,
    /// +0x494.. the floor guard (abf850)
    pub floor_y: f32,
    pub floor_rate: f32,
    pub floor_vel: f32,
    pub floor_acc: f32,
    /// +0x4a4 the distance to the anchor at entry, +0x4a8 the sink speed
    pub rope_len0: f32,
    pub sink: f32,
    /// +0x4ac, +0x4b0, +0x4b4 descending gravity: initial, final, and in the third phase
    pub grav_fall_initial: f32,
    pub grav_fall_final: f32,
    pub grav_fall_hold: f32,
    /// +0x4b8 velocity, +0x4c4 its previous value
    pub vel: V3,
    pub prev_vel: V3,
    /// +0x4d0 the swing direction, +0x4dc the velocity along it, +0x4e8 last frame's direction
    pub dir: V3,
    pub along: V3,
    pub prev_dir: V3,
    /// +0x4f4, +0x4f8 (abc8c0)
    pub dir_spring_v: f32,
    pub dir_time: f32,
    /// +0x4fc, +0x500 (abb8e0)
    pub turn_v: f32,
    pub turn_ramp: f32,
    /// +0x504, +0x508 the facing twist spring
    pub twist_v: f32,
    pub twist: f32,
    /// +0x50c the entry blend toward the mover's velocity
    pub blend_in: f32,
    /// +0x510, +0x514 the gravity blend and its delay
    pub gravity_blend: f32,
    pub gravity_blend_delay: f32,
    /// +0x518 the pivot factor (only decreases)
    pub pivot_factor: f32,
    /// +0x51c terminal speed, +0x520 its minimum, +0x524 its maximum
    pub terminal: f32,
    pub terminal_min: f32,
    pub terminal_max: f32,
    /// +0x528, +0x52c
    pub release_anim_rate: f32,
    pub release_anim_blend: f32,
    /// +0x530 the last frame's step
    pub last_dt: f32,
    /// +0x534 the release pitch
    pub release_pitch: f32,
    /// +0x54c his yaw rate (degrees per second)
    pub yaw_rate: f32,
    /// +0x550 look input (eased), and the camera's look input this frame (camera vtable +0xa0)
    pub look: f32,
    pub look_input: f32,
    /// +0x554 the stick's direction at entry, +0x560 its angle
    pub entry_input_dir: V3,
    pub input_angle2: f32,
    /// +0x564, +0x568, +0x56c, +0x570
    pub entry_input_angle: f32,
    pub input_agree: f32,
    pub agree_peak: f32,
    pub agree_timer: f32,
    /// +0x574 0 falling into it, 1 past the bottom, 2 swinging back; +0x578 time in phase 2; +0x57c pulling back
    pub phase: i32,
    pub phase_time: f32,
    pub reverse: f32,
    /// +0x580 the animation sub-state (stays 0 without the animation system, as in the research harness)
    pub sub_state: u8,
    /// +0x5f0, +0x5f1 the release event, +0x5f3 first substep, +0x5f7 back swing, +0x5f8, +0x5f9, +0x5fa, +0x5fb
    pub b5f0: bool,
    pub release_event: bool,
    pub first: bool,
    pub back_swing: bool,
    pub b5f8: bool,
    pub b5f9: bool,
    pub forward_action: bool,
    pub release_countdown: i8,
}

impl Default for SwingLocal {
    fn default() -> Self {
        Self {
            entry_time: 0.,
            probes: Probes::default(),
            hero: Rows::default(),
            cam: Rows::default(),
            input_dir: V3::ZERO,
            input_mag: 0.,
            input_angle: 0.,
            speed_input_smooth: -1.,
            speed_input: -1.,
            speed_input_hold: 0.,
            anchor: V3::ZERO,
            attach: V3::ZERO,
            min_time: 0.2,
            boost_target: 0.,
            boost_accel_base: 0.,
            boost_accel: 0.,
            boost_accel_accel: 0.,
            boost_on: false,
            gravity_scale: 1.,
            speed_change: 1.,
            push: V3::ZERO,
            probe_turn_scale: 1.,
            low_point: V3::ZERO,
            has_low_point: false,
            init_pull: -1.,
            floor_y: -1e30,
            floor_rate: 0.,
            floor_vel: 0.,
            floor_acc: 0.,
            rope_len0: 0.,
            sink: 0.,
            grav_fall_initial: 0.,
            grav_fall_final: 0.,
            grav_fall_hold: 0.,
            vel: V3::ZERO,
            prev_vel: V3::ZERO,
            dir: V3::ZERO,
            along: V3::ZERO,
            prev_dir: V3::ZERO,
            dir_spring_v: 0.,
            dir_time: 0.,
            turn_v: 0.,
            turn_ramp: 0.,
            twist_v: 0.,
            twist: 0.,
            blend_in: 0.,
            gravity_blend: 1.,
            gravity_blend_delay: 0.,
            pivot_factor: 1.,
            terminal: 0.,
            terminal_min: 0.,
            terminal_max: 0.,
            release_anim_rate: 1.,
            release_anim_blend: 0.35,
            last_dt: 0.,
            release_pitch: 0.,
            yaw_rate: 0.,
            look: 0.,
            look_input: 0.,
            entry_input_dir: V3::ZERO,
            input_angle2: 0.,
            entry_input_angle: 0.,
            input_agree: 0.,
            agree_peak: 0.,
            agree_timer: 0.3,
            phase: 0,
            phase_time: 0.,
            reverse: 0.,
            sub_state: 0,
            b5f0: false,
            release_event: false,
            first: true,
            back_swing: false,
            b5f8: false,
            b5f9: false,
            forward_action: false,
            release_countdown: 2,
        }
    }
}

/// exe+ab4450: the swing plane through the web point, his position and a direction. Returns its normal, the normal's
/// tilt (degrees, unsigned) and his angle round the swing (degrees; about 180 entering above, 90 under the point,
/// toward 0 up the far side)
pub fn rope_geometry(attach: V3, pos: V3, v: V3) -> (V3, f32, f32) {
    let d = (attach - pos).norm();
    let k = v.x * d.x + v.y * d.y + v.z * d.z;
    let p = V3::new(v.x - d.x * k, v.y - d.y * k, v.z - d.z * k);
    let n = V3::new(p.y * d.z - p.z * d.y, p.z * d.x - p.x * d.z, p.x * d.y - p.y * d.x).norm();
    let tilt = (pitch_of(n) * RAD).abs();
    // a level direction (b, 0, a) across the normal
    let (mut a, mut b) = (-n.x, n.z);
    let m = a.abs().max(0.).max(b.abs());
    if m > 0. {
        a *= 1. / m;
        b *= 1. / m;
        let l = 1. / (a * a + b * b).sqrt();
        a *= l;
        b *= l;
    }
    let w = V3::new(a * n.y, b * n.z - a * n.x, -(b * n.y)).norm();
    let (s, u, f) = basis(V3::new(b, 0., a), w);
    let mut q = -d;
    q = q - s * s.dot(q);
    let q = q.norm();
    let (qu, qf) = (u.dot(q), f.dot(q));
    let mut angle = angle_between(V3::new(s.dot(q), qu, qf), V3::new(0., 0., 1.)) * RAD;
    if qu > 0. {
        angle = if qf <= 0. { 360. - angle } else { -angle };
    }
    (n, tilt, angle)
}

/// exe+1c5a450: a vector of length `len` at heading `yaw` (atan2(x, z)) and elevation `pitch`
fn from_angles(yaw: f32, pitch: f32, len: f32) -> V3 {
    let cp = cos(pitch);
    V3::new(sin(yaw) * len * cp, sin(pitch) * len, cos(yaw) * len * cp)
}

/// exe+1c5b5d0: from a toward b by t, direction by angle and length by lerp
fn slerp_scaled(a: V3, b: V3, t: f32) -> V3 {
    let la = a.len();
    let lb = b.len();
    let an = if la >= 0.0001 { a * (1. / la) } else { a };
    let bn = if lb >= 0.0001 { b * (1. / lb) } else { b };
    let d = an.dot(bn).clamp(-1., 1.);
    let perp = (bn - an * d).norm();
    let th = acos(d) * t;
    let (sn, cs) = (sin(th), cos(th));
    let l = (lb - la) * t + la;
    V3::new((an.x * cs + sn * perp.x) * l, (an.y * cs + perp.y * sn) * l, (an.z * cs + perp.z * sn) * l)
}

/// exe+1c46f80: unit `from` turned toward unit `to` by one damped-spring step of the angle between them
fn vector_spring(from: V3, to: V3, v: &mut f32, a: f32, b: f32, c: f32, dt: f32) -> V3 {
    let ang = angle_between(from, to);
    let mut out = to;
    if ang > 0.0001 {
        let axis = from.cross(to).norm();
        let step = spring(0., ang, v, a, b, c, dt);
        out = rotate(from, axis, step);
        // past the target: snap to it
        if out.cross(to).dot(axis) < 0. {
            *v = ang / dt;
            out = to;
        }
    }
    out.norm()
}

/// exe+2e7060: a 3x3 inverse (rows)
fn inverse3(m: &[f32; 9]) -> [f32; 9] {
    let (a, b, c, d, e, f, g, h, i) = (m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8]);
    let det = e * a * i + f * b * g + d * c * h - f * a * h - d * b * i - e * c * g;
    if det == 0. {
        return [0.; 9];
    }
    let r = 1. / det;
    [
        (i * e - h * f) * r,
        (h * c - i * b) * r,
        (f * b - e * c) * r,
        (g * f - i * d) * r,
        (i * a - g * c) * r,
        (d * c - f * a) * r,
        (h * d - g * e) * r,
        (g * b - h * a) * r,
        (e * a - d * b) * r,
    ]
}

/// exe+86c2a0: the hunter's heading for a new swing from the camera, his travel and the stick; true for a back swing
pub fn swing_heading(cam_flat: V3, travel: V3, input: V3) -> (V3, bool) {
    let t = (angle_between(cam_flat, travel) * 1.909859 - 1.).clamp(0., 1.);
    let mid = slerp(cam_flat, travel, t);
    let a = angle_between(input, mid) * RAD;
    if a > 90. {
        if a < 135. {
            let d = input.dot(mid);
            return ((input - mid * d).norm(), false);
        }
        let t2 = ((a - 135.) * 0.02857143).clamp(0., 1.) * 0.65 + 0.35;
        return (slerp(input, -mid, t2), true);
    }
    (input, false)
}

impl SwingLocal {
    /// exe+20dc660: time in the state
    pub fn age(&self, env: &Env) -> f32 {
        (env.time - self.entry_time) as f32
    }

    /// exe+abcf40: the frame's input, rows and throttle
    fn read_input(&mut self, cfg: &Configs, env: &Env, dt: f32) {
        self.cam = env.cam;
        self.hero = env.hero;
        self.look_input = env.input.look;
        self.input_mag = 0.;
        let (dir, mag, angle) = env.stick_world();
        self.input_dir = dir;
        self.input_mag = mag;
        self.input_angle = angle;
        if self.forward_action {
            let cf = self.cam.fwd.flat_norm();
            if self.input_mag < 0.05 || cf.dot(self.input_dir) > 0.5 {
                self.forward_action = false;
            } else {
                // exe+b85760: the stick turned toward the camera's forward, at most 45 degrees off it
                let (side, _, _) = basis(cf, V3::UP);
                let mut a = angle_between(cf, self.input_dir);
                if a > 1.570796 {
                    a = 3.141593 - a;
                }
                let mut w = (a * 0.6366197).clamp(0., 1.) * 0.7853982;
                if side.dot(self.input_dir) <= 0. {
                    w = -w;
                }
                self.input_dir = rotate(cf, V3::UP, w);
                // its angle in the camera's frame
                let (cs, cu, cfw) = (self.cam.side, self.cam.up, self.cam.fwd);
                let inv = inverse3(&[cs.x, cs.y, cs.z, cu.x, cu.y, cu.z, cfw.x, cfw.y, cfw.z]);
                let d = self.input_dir;
                let lx = inv[0] * d.x + inv[3] * d.y + inv[6] * d.z;
                let lz = inv[2] * d.x + inv[5] * d.y + inv[8] * d.z;
                self.input_angle = atan2(lx, lz);
                self.input_angle2 = self.input_angle;
            }
        }
        if self.input_mag < 0.05 {
            self.input_dir = self.cam.fwd.flat_norm();
        }
        let vf = self.vel.flat_norm();
        let d = vf.z * self.input_dir.z + vf.x * self.input_dir.x;
        let mag = self.input_mag;
        if d >= -0.707 {
            let s = &cfg.swing;
            let x = if mag <= s.speed_input_mid {
                remap(mag, s.speed_input_min, s.speed_input_mid) * s.speed_input_mid_value
            } else {
                let r = s.speed_input_max - s.speed_input_mid;
                let t = if r.abs() > 0.0001 { ((mag - s.speed_input_mid) / r).clamp(0., 1.) } else { 1. };
                (1. - s.speed_input_mid_value) * t + s.speed_input_mid_value
            };
            let mut smooth = self.speed_input_smooth;
            if x < smooth {
                self.speed_input_hold = (self.speed_input_hold - dt).max(0.);
                if self.speed_input_hold < 0.0001 {
                    smooth = approach(smooth, x, 2., dt);
                    self.speed_input_smooth = smooth;
                }
            } else {
                self.speed_input_smooth = x;
                self.speed_input_hold = 0.2;
                smooth = x;
            }
            self.speed_input = (d.max(0.) * 0.25 + 0.75) * smooth;
        } else {
            self.speed_input = -mag;
            self.speed_input_smooth = -mag;
        }
    }

    /// exe+ac04f0: the velocity turned into the swing round the anchor: its heading kept, its pitch from the part
    /// across the rope and the speed kept
    fn swing_dir(&self, vel: V3, pos: V3, first_phase: bool, prev: Option<V3>) -> V3 {
        let raw = self.anchor - pos;
        let d = raw.norm();
        let vn = vel.norm();
        let (mut hz, mut hx) = (-d.x, d.z);
        let m = hz.abs().max(0.).max(hx.abs());
        if m > 0. {
            hz *= 1. / m;
            hx *= 1. / m;
            let l = 1. / (hz * hz + hx * hx).sqrt();
            hz *= l;
            hx *= l;
        }
        let speed = vel.len();
        let small = vel.x * vel.x + vel.z * vel.z < 0.001;
        let k = vel.x * d.x + vel.y * d.y + vel.z * d.z;
        let p = V3::new(vel.x - k * d.x, vel.y - k * d.y, vel.z - k * d.z);
        let q = p.x * hx + p.z * hz;
        let (ax, az) = (hx * q, hz * q);
        let (p2x, p2z) = (p.x - ax, p.z - az);
        let al = V3::new(ax, 0., az).flat_len();
        let u = (speed * speed - al * al).max(0.).sqrt();
        let len2 = p2x * p2x + p.y * p.y + p2z * p2z;
        let (wx, wy, wz) = if len2 >= 1e-15 {
            let f = u / len2.sqrt();
            (ax + p2x * f, f * p.y, az + p2z * f)
        } else {
            (ax + u, 0., az)
        };
        let yaw = if small { atan2(self.input_dir.x, self.input_dir.z) } else { atan2(vel.x, vel.z) };
        let pitch = atan2(wy, V3::new(wx, 0., wz).flat_len());
        let mut out = from_angles(yaw, pitch, vel.len());
        let dd = vn.x * d.x + vn.y * d.y + vn.z * d.z;
        if dd < -0.1 {
            let a = dd.abs();
            let t = if a < 0.3 {
                1. - ((a - 0.1) * 4.9999995).clamp(0., 1.) * 0.39999998
            } else {
                ((a - 0.3) * 1.6666667).clamp(0., 1.) * 0.39999998 + 0.6
            };
            out = slerp_scaled(p, out, t);
        }
        if first_phase {
            if raw.y < 0. {
                out = V3::new(0., -vel.y.abs(), 0.);
            } else if out.y > 0. {
                if 0. >= vel.y {
                    let neg = -out;
                    if prev.map_or(true, |v| neg.dot(v) > 0.) {
                        out = neg;
                    }
                } else {
                    out = self.swing_dir(V3::new(vel.x, -vel.y, vel.z), pos, false, None);
                }
            }
        }
        out
    }

    /// exe+ab97e0: the swing begins. `hero_pos` is where the entity is now (exe+1676930).
    pub fn enter(&mut self, cfg: &Configs, tr: &mut Tracker, proc_: &mut SwingProcessor, e: &SwingEntry, env: &Env) {
        // the state object persists between swings: only its velocity survives the entry's resets
        let vel = self.vel;
        *self = SwingLocal::default();
        self.vel = vel;
        self.entry_time = env.time;
        proc_.start(e);
        self.attach = e.attach;
        self.anchor = e.anchor;
        self.min_time = e.min_time;
        self.b5f9 = e.flags & 0x40 != 0;
        self.forward_action = e.flags & 0x100 != 0;
        self.rope_len0 = dist(self.anchor, env.hero.pos);
        self.last_dt = env.dt;
        self.read_input(cfg, env, 0.);
        self.entry_velocity(env);
        if e.flags & 2 != 0 {
            self.vel = e.velocity;
        }
        if e.flags & 4 != 0 {
            self.blend_in = e.blend;
        }
        self.prev_vel = self.vel;
        if self.vel.y > 0. && e.flags & 8 != 0 {
            self.phase = 1;
        }
        let d = self.swing_dir(self.vel, self.hero.pos, true, None);
        self.dir = d.norm();
        let dd = self.dir.dot(self.dir);
        let k = if dd.abs() <= 1e-15 { 0. } else { self.dir.dot(self.vel) / dd };
        let mut p = self.dir * k;
        if p.dot(self.dir) < 0. {
            p = -p;
        }
        self.prev_dir = self.dir;
        self.along = p;
        self.initial_gravity_blend();
        if self.back_swing {
            tr.hold_momentum(cfg, 0.5);
        }
        let (_, tilt, _) = rope_geometry(self.attach, self.hero.pos, self.dir);
        let g = &tr.params.motion.gravity_params;
        let t = remap(tilt, g.init_tilt_angle_min, g.init_tilt_angle_max);
        self.grav_fall_final = lerp(g.gravity_fall_init, g.gravity_fall_turn, t);
        self.grav_fall_initial = (self.grav_fall_final * 0.33).min(-12.);
        self.grav_fall_hold = g.gravity_fall_hold;
        let sp = &tr.params.motion.speed_params;
        let mut terminal = terminal_target(sp, self.attach, self.hero.pos, self.vel);
        if self.back_swing {
            terminal *= 0.85;
        }
        self.terminal = terminal.max(tr.terminal_floor);
        self.gravity_scale = tr.gravity_scale;
        self.terminal_max = self.terminal * 3.;
        self.terminal_min = (self.terminal * sp.terminal_velocity_min_percent).max(sp.terminal_velocity_min_floor);
        self.boost_target = sp.speed_boost_target;
        self.boost_accel_base = sp.speed_boost_accel;
        self.boost_accel = (sp.speed_boost_accel * 0.15).max(8.);
        self.boost_accel_accel = sp.speed_boost_accel_accel;
        self.boost_on = true;
        self.entry_input_dir = self.input_dir;
        self.input_agree = 0.;
        let (mag, ang) = env.stick_raw();
        self.input_angle2 = if mag >= 0.1 { ang } else { 0. };
        if e.flags & 1 != 0 {
            self.input_angle2 = e.input_angle;
        }
        if e.flags & 0x100 != 0 {
            self.input_angle2 = self.input_angle;
        }
        let vf = self.vel.flat_norm();
        self.entry_input_angle = angle_between(self.input_dir, vf) * RAD;
        self.agree_timer = 0.3;
        self.agree_peak = 0.;
        self.speed_change = 1.;
    }

    /// exe+ac00e0: his velocity on entry, turned toward the hunter's heading when slow and steering away
    fn entry_velocity(&mut self, env: &Env) {
        let mv = env.mover_vel;
        let hs = mv.flat_len();
        let cam_flat = self.cam.fwd.flat_norm();
        let dir0 = if hs >= 0.001 { V3::new(mv.x, 0., mv.z).norm() } else { cam_flat };
        let (heading, back) = swing_heading(cam_flat, dir0, self.input_dir);
        self.back_swing = back;
        let a = (angle_between(dir0, heading) * 1.909859 - 0.6666667).clamp(0., 1.);
        let sp = ((hs - 10.) * 0.04).clamp(0., 1.);
        let inp = ((self.input_mag - 0.1) * 3.333333).clamp(0., 1.);
        let (w, hs) = if !self.back_swing {
            // the hunter's own blend (+0xe97c) is 0 here
            (a * (1. - sp) * inp, hs)
        } else {
            (1., hs.min(6.))
        };
        let d = slerp(dir0, heading, w);
        self.vel = V3::new(d.x * hs, d.y * hs + mv.y, d.z * hs);
        self.blend_in = if w >= 0.0001 { 0. } else { 1. };
    }

    /// exe+abd610
    fn initial_gravity_blend(&mut self) {
        let dist = (self.anchor - self.hero.pos).flat_len();
        let vf = self.vel.flat_norm();
        let a = (angle_between(self.input_dir, vf) * 2.291831 - 1.2).clamp(0., 1.);
        let d = 1. - ((dist - 8.) * 0.125).clamp(0., 1.);
        let p = (-pitch_of(self.dir) * 5.729578 + 2.).clamp(0., 1.);
        self.gravity_blend_delay = 0.2;
        self.gravity_blend = 1. - p * a * (d * 0.65 + 0.35);
    }

    /// exe+ac30e0: one frame. Returns the displacement and the facing for the mover.
    pub fn update(&mut self, cfg: &Configs, tr: &mut Tracker, proc_: &SwingProcessor, env: &Env) -> SwingOutput {
        let dt = env.dt;
        self.anchor = proc_.anchor;
        self.read_input(cfg, env, dt);
        let mut disp = self.integrate(cfg, tr, env, dt);
        let facing = self.facing(disp, dt);
        if self.blend_in < 1. {
            let mv = env.mover_vel;
            let old = self.blend_in;
            self.blend_in = approach(old, 1., 2., dt);
            let w = ((self.blend_in - old) / (1. - old)).clamp(0., 1.);
            disp.x = (disp.x - mv.x * dt) * w + mv.x * dt;
            disp.z = (disp.z - mv.z * dt) * w + mv.z * dt;
        }
        self.update_yaw_rate();
        if self.init_pull < 0. {
            self.init_pull = ((self.vel.y + 5.) * 0.1111111).clamp(0., 1.);
        }
        self.gain_momentum(cfg, tr, env, dt);
        self.last_dt = dt;
        SwingOutput { displacement: disp, facing, snap: false }
    }

    /// exe+abd820: the facing he asks for: his flat motion turned by a twist that springs toward 0.15 x his yaw rate
    fn facing(&mut self, disp: V3, dt: f32) -> V3 {
        let mut out = V3::new(disp.x, 0., disp.z).norm();
        if self.sub_state == 3 {
            return self.hero.fwd;
        }
        if V3::new(disp.x, 0., disp.z).flat_len() < dt {
            out = V3::new(self.hero.fwd.x, 0., self.hero.fwd.z).norm();
        }
        self.twist = spring(self.twist, self.yaw_rate * 0.15, &mut self.twist_v, -1., -16., 12., dt);
        rotate(out, V3::UP, self.twist * DEG)
    }

    /// exe+ac2dd0: his yaw rate (degrees per second)
    fn update_yaw_rate(&mut self) {
        let a = atan2(self.prev_vel.x, self.prev_vel.z);
        let b = atan2(self.vel.x, self.vel.z);
        self.yaw_rate = wrap_pi(b - a) * RAD / self.last_dt;
        if self.prev_vel.flat_len() < 0.01 {
            self.yaw_rate = 0.;
        }
    }

    /// exe+ac36f0: momentum while he swings with the stick forward
    fn gain_momentum(&mut self, cfg: &Configs, tr: &mut Tracker, env: &Env, dt: f32) {
        if self.back_swing || self.phase == 2 || self.speed_input < 0.6 {
            return;
        }
        let (_, _, angle) = rope_geometry(self.attach, self.hero.pos, self.dir);
        let a = 180. - angle.clamp(0., 180.);
        let sd = &cfg.swing.momentum_config.swing_data;
        if sd.rate_list.is_empty() {
            return;
        }
        let list = &sd.rate_list;
        let (mut lo, mut hi, mut t) = (&list[0], &list[0], 1.);
        for k in 1..list.len() {
            hi = &list[k];
            if a < list[k].angle {
                lo = &list[k - 1];
                t = unlerp(a, list[k - 1].angle, list[k].angle);
                break;
            }
            lo = &list[k];
        }
        let rate = (hi.rate - lo.rate) * t + lo.rate;
        let tt = remap(self.age(env), sd.min_time, sd.max_time);
        let s = ((self.speed_input - 0.6) * 2.5).clamp(0., 1.);
        let amount = s * ((1. - sd.start_scale) * tt + sd.start_scale) * rate * dt;
        tr.add_momentum(cfg, amount, sd.boost_cap, false);
        self.terminal = self.terminal.max(tr.terminal_floor);
    }

    /// exe+abdb30: four substeps round the (virtual) pivot. Returns the frame's displacement.
    fn integrate(&mut self, cfg: &Configs, tr: &mut Tracker, env: &Env, dt: f32) -> V3 {
        self.prev_vel = self.vel;
        // exe+abb420: sliding along a surface he touches (none here)
        self.vel = self.phase_update(self.vel, self.prev_dir, dt);
        self.prev_dir = self.dir;
        let d0 = self.swing_dir(self.vel, self.hero.pos, self.phase == 0, Some(self.prev_dir));
        self.dir = d0.norm();
        let dd = self.dir.dot(self.dir);
        let k = if dd.abs() <= 1e-15 { 0. } else { self.dir.dot(self.vel) / dd };
        let p_raw = self.dir * k;
        let mut p = p_raw;
        if p.dot(self.dir) < 0. {
            p = -p;
        }
        self.along = p;
        // swing floor volumes (exe+8478f0, exe+b8a4f0): none here
        let mut pos = self.hero.pos;
        let mut v = self.vel;
        let mut dirv = self.along;
        let ds = dt * 0.25;
        let age = self.age(env);
        let mut last_dirv = dirv;
        for i in 0..4 {
            // the web stretches: 72 % of the way out is allowed until 0.33 s, nothing by 1.0 s
            let t = age + i as f32 * ds;
            let elastic = 0.72 - ((t - 0.33) * 1.4925373).clamp(0., 1.) * 0.72;
            let (_, tilt, angle) = rope_geometry(self.attach, pos, dirv);
            // the entry boost
            if self.boost_on {
                if self.phase == 0 {
                    let mut speed = v.len();
                    if v.y > 0. {
                        speed = v.flat_len();
                    }
                    if (speed > self.boost_target && v.y < 0.) || !(0.2 >= self.reverse) {
                        self.boost_on = false;
                    } else {
                        self.boost_accel = approach(self.boost_accel, self.boost_accel_base, self.boost_accel_accel, ds);
                        let add = (self.boost_target - speed).max(0.).min(self.boost_accel * ds);
                        let l2 = dirv.dot(dirv);
                        if l2 >= 1e-15 {
                            v += dirv * (add / l2.sqrt());
                        }
                    }
                } else {
                    self.boost_on = false;
                }
            }
            let v0 = v;
            v = self.steer_toward_swing(v, dirv, ds);
            let v1 = v;
            v = self.steer(cfg, tr, v, ds);
            if std::env::var_os("SMT_DEBUG").is_some() {
                eprintln!("  sub {i}: v in {v0:?} toward-swing {v1:?} steer {v:?} dirv {dirv:?}");
            }
            let d2 = self.swing_dir(v, pos, self.phase == 0, Some(dirv));
            let d2n = d2.norm();
            let base = if d2n.dot(p_raw) >= 0. { p_raw } else { -p_raw };
            let delta = v - base;
            // the level direction across his motion, for the pivot
            let vn = v.norm();
            let side = V3::new(vn.z, 0., -vn.x).flat_norm();
            let pivot = self.pivot(cfg, tr, self.anchor, pos, base, side, ds, age);
            let r = pivot - pos;
            let rlen = r.len();
            let rn = r.norm();
            let g = self.gravity(tr, base, angle, tilt, rlen, age);
            let bl = base.len();
            let c = bl * bl / rlen;
            self.gravity_blend_delay -= ds;
            if self.gravity_blend_delay <= 0. {
                self.gravity_blend = (ds * 1.25 + self.gravity_blend).min(1.);
            }
            let b = self.gravity_blend;
            let gy = rn.y * g;
            let nvx = -(gy * rn.x * b) * ds + c * rn.x * ds + base.x;
            let nvz = -(gy * rn.z * b) * ds + c * rn.z * ds + base.z;
            let cy = c * rn.y;
            let nvy = (((g - gy * rn.y) - g) * b + g) * ds + (cy * b).min(cy) * ds + base.y;
            let nv = V3::new(nvx, nvy, nvz);
            self.speed_change = nv.len() - bl;
            // the base motion on the circle round the pivot
            let p1 = pos + nv * ds;
            let to = pivot - p1;
            let (p1c, rcon) = if to.y >= 0. {
                let l2 = to.dot(to);
                let f = rlen / l2.sqrt();
                let o = if l2 >= 1e-15 { to * f } else { V3::new(rlen, 0., 0.) };
                (pivot - o, rlen)
            } else {
                (p1, to.len())
            };
            // the rest of his motion may stretch the web (elastic), never pushes it
            let p3 = p1c + delta * ds;
            let to3 = pivot - p3;
            let r3 = to3.len();
            let rope = ((r3 - rcon) * elastic + rcon).min(r3);
            let l2 = to3.dot(to3);
            let o = if l2 >= 1e-15 { to3 * (rope / l2.sqrt()) } else { V3::new(rope, 0., 0.) };
            let mut fin = pivot - o;
            if to3.y > 0. {
                if self.phase != 2 {
                    // sinking when the web is shorter than it began, past 85 degrees
                    let c1 = (cos(angle * DEG) + 1.).clamp(0., 1.);
                    let c2 = ((angle - 85.) * 0.2).clamp(0., 1.);
                    let tt = ((age - 0.1) * 2.5).clamp(0., 1.);
                    let dd = (fin - self.anchor).len();
                    let len0 = self.rope_len0.min(20.);
                    let s1 = ((len0 - dd - 1.) * 0.1428571).clamp(0., 1.);
                    self.sink = approach(self.sink, s1 * c1 * tt * 4. * c2, 12., ds);
                }
                fin.y -= ds * self.sink;
            }
            fin = self.push_off(fin, ds, age);
            v = nv + delta;
            let v_before_cap = v;
            v = self.cap_speed(tr, v, dirv, rope, ds);
            let v_capped = v;
            let pos_before = pos;
            pos = self.floor_guard(&mut v, pos, fin, pivot, tilt, ds);
            if std::env::var_os("SMT_DEBUG").is_some() {
                eprintln!(
                    "  sub {i}: elastic {elastic:.3} tilt {tilt:.2} angle {angle:.2} base {base:?} delta {delta:?} pivot {pivot:?} rlen {rlen:.3} g {g:.3} c {c:.3} b {b:.3} nv {nv:?} v {v_before_cap:?} capped {v_capped:?} guarded {v:?} pos {pos_before:?} -> {fin:?} -> {pos:?}"
                );
            }
            let d3 = self.swing_dir(v, pos, self.phase == 0, Some(dirv)).norm();
            dirv = if d3.dot(p_raw) >= 0. { p_raw } else { -p_raw };
            last_dirv = dirv;
            self.first = false;
        }
        self.vel = v;
        self.along = last_dirv;
        self.dir = last_dirv.norm();
        pos - self.hero.pos
    }

    /// exe+abc5d0: the phases and the drag of the third
    fn phase_update(&mut self, vel: V3, prev_dir: V3, dt: f32) -> V3 {
        let (_, _, angle) = rope_geometry(self.attach, self.hero.pos, prev_dir);
        if self.phase == 0 {
            if angle < 90. {
                self.phase = 1;
            }
        } else if self.phase == 1 && vel.y < 0. && angle > 70. {
            self.phase = 2;
        }
        let mut r = 0.;
        if self.input_mag > 0.01 && self.input_agree > 0.99 {
            let vf = V3::new(vel.x, 0., vel.z).norm();
            if vf.dot(self.input_dir) < -0.707 {
                r = (1. - ((angle - 90.) * 0.02222222).clamp(0., 1.)) * self.input_mag;
            }
        }
        self.reverse = approach(self.reverse, r, 2., dt);
        if self.phase == 2 {
            self.phase_time += dt;
            let f = (self.phase_time * 0.1).clamp(0., 1.);
            let mut s = vel.len();
            s -= (f.sqrt() * f * 0.14 + 0.01) * s * dt;
            return vel.with_len(s.max(0.));
        }
        vel
    }

    /// exe+abc8c0: the velocity eased toward the swing direction
    fn steer_toward_swing(&mut self, vel: V3, dirv: V3, dt: f32) -> V3 {
        let s1 = ((vel.len() - 4.) * 0.25).clamp(0., 1.);
        if s1 < 0.0001 {
            self.dir_time = 0.;
            return vel;
        }
        let hs = vel.flat_len();
        let fv = ((hs - 25.) * 0.06666667).clamp(0., 1.);
        self.dir_time += (fv + 1.) * dt;
        let fd = ((dist(self.anchor, self.hero.pos) - 24.) * 0.08333334).clamp(0., 1.);
        let fd2 = (1. - fv) * fd;
        let mut m = 1. - fd2 * 0.7;
        let nd = dirv.norm();
        let speed = vel.len();
        let p = ((atan2(nd.y, nd.flat_len()) * -RAD).abs() - 35.) * 0.04;
        let p = p.clamp(0., 1.);
        let fy = ((vel.y + 10.) * 0.06666667).clamp(0., 1.);
        m -= (1. - p) * 0.2 - fd2 * (1. - p) * 0.14;
        let toward = (self.anchor - self.hero.pos).dot(vel);
        let fy1 = 1. - fy;
        let hi = -4. - (fy1 + fy1);
        let lo = if toward <= 0. { -1.5 } else { (-1.75 - fy1 * 0.5) * m };
        let t = ((self.dir_time - 0.3) * 3.333333).clamp(0., 1.);
        let a = ((hi - lo) * t + lo) * s1;
        let c = ((1. - m) * t + m) * 6.981317;
        let out = vector_spring(vel.norm(), nd, &mut self.dir_spring_v, a, -15., c, dt);
        let k = ((angle_between(nd, vel.norm()) * 1.432394) - 0.125).clamp(0., 1.);
        let sp = ((out.dot(vel)) - speed) * k + speed;
        let mut r = out.with_len(sp);
        if self.phase == 0 && r.y > 0. && toward > 0. {
            let f = V3::new(r.x, 0., r.z);
            let l = f.len().min(hs);
            let fl2 = r.z * r.z + r.x * r.x;
            if fl2 >= 1e-15 {
                let s = l / fl2.sqrt();
                r = V3::new(r.x * s, r.y, r.z * s);
            } else {
                r = V3::new(0., r.y, 0.);
            }
        }
        r
    }

    /// exe+abb8e0: the stick steers the swing: his velocity turned about the vertical by a damped spring
    fn steer(&mut self, _cfg: &Configs, tr: &Tracker, mut vel: V3, dt: f32) -> V3 {
        let tp = tr.params.motion.turn_params;
        let d_deg = wrap_pi(self.input_angle - self.input_angle2) * RAD;
        let t;
        if d_deg > 70. || self.entry_input_angle < 30. {
            self.agree_timer = 0.;
            self.input_agree = 1.;
            t = 1.;
        } else if self.input_agree >= 1. {
            t = self.input_agree;
        } else {
            let a = ((d_deg - 5.) * 0.04).clamp(0., 1.);
            let e = ((self.entry_input_angle - 30.) * 0.03333334).clamp(0., 1.);
            let peak = self.agree_peak.max(a);
            self.agree_peak = peak;
            let e1 = 1. - e;
            let pe = peak * e1;
            let mut ramp = true;
            if peak < 0.05 {
                self.agree_timer -= ((peak + e1) * 4. + pe * 16. + 1.) * dt;
                if self.agree_timer >= 0.0001 {
                    ramp = false;
                }
            } else {
                self.agree_timer = 0.;
            }
            if ramp {
                self.input_agree = (self.input_agree + (peak * 8.5 + pe * 34. + e1 * 6. + 1.5) * dt).min(1.);
            }
            t = self.input_agree;
        }
        let tgt = slerp(self.entry_input_dir, self.input_dir, t);
        let vf = vel.flat_norm();
        let left = tgt.x * vf.z - tgt.z * vf.x > 0.;
        if self.input_agree > 0.99 && vf.x * self.input_dir.x + vf.z * self.input_dir.z < -0.707 {
            return vel;
        }
        if self.phase == 2 && self.input_mag < 0.02 {
            return vel;
        }
        let mut ang = angle_between(vf, tgt);
        if ang < 0.0005 {
            return vel;
        }
        let a1 = (ang * 0.9549296).clamp(0., 1.);
        let a2 = ((a1 - 0.33) * 1.754386).clamp(0., 1.);
        let ramp0 = if self.first { a2 * a1 * 0.4 } else { self.turn_ramp };
        self.turn_ramp = ramp0;
        let ramp = (a1 * dt * tp.turn_ramp_speed + ramp0).min(a1);
        self.turn_ramp = ramp;
        let mut gain = lerp(tp.turn_gain_min, tp.turn_gain_max, ramp);
        let mut s_min = lerp(tp.turn_speed_min_min, tp.turn_speed_min_max, ramp);
        let mut s_max = lerp(tp.turn_speed_max_min, tp.turn_speed_max_max, ramp);
        let damp = lerp(tp.turn_damp_min, tp.turn_damp_max, ramp);
        // the camera's look input
        let l = ((self.look_input - 0.1) * 1.666667).clamp(0., 1.);
        self.look = if l > self.look { l } else { approach(self.look, l, 2., dt) };
        let lk = l * 0.25 + 1.;
        let ag = (self.input_agree * 1.515152).clamp(0., 1.);
        let f = (1. - ag) * 0.22 + 1.;
        gain = gain * (l + 1.) * f;
        let mut damp = damp * (1. - l * 0.5) / f;
        s_min = s_min * lk * f;
        s_max = s_max * lk * f;
        let ts = tr.turn_speed_scale;
        gain += (gain * ts - gain) * 0.33;
        s_min *= ts;
        s_max *= ts;
        damp += (damp / ts - damp) * 0.33;
        let (_, tilt, angle) = rope_geometry(self.attach, self.hero.pos, self.dir);
        let a90 = (90. - angle).max(0.);
        let t1 = remap(tilt, tp.turn_speed_tilt_angle_min, tp.turn_speed_tilt_angle_max);
        let tsf = (1. - tp.turn_speed_tilt_scale) * (1. - t1) + tp.turn_speed_tilt_scale;
        let p1 = remap(a90, tp.turn_speed_pitch_min, tp.turn_speed_pitch_max);
        let mut speed = ((s_max - s_min) * (1. - p1) + s_min) * tsf;
        // the probes: slower turning toward what is close
        let pr = &self.probes;
        let mut maxc = 0f32;
        for i in -2..=2 {
            maxc = pr.c(i).max(maxc);
        }
        let (mut lsum, mut rsum) = (0., 0.);
        for k in 1..=3 {
            lsum += (maxc - pr.c(-k)).max(0.);
            rsum += (maxc - pr.c(k)).max(0.);
        }
        let weights = [3., 1., 0.5, 0.25];
        let n = pr.count();
        let (mut sw, mut ws) = (0., 0.);
        for k in 0..n.max(0) {
            let w = weights[k as usize];
            sw += w;
            ws += w * ((pr.s(k, left) - 4.) * 0.125).clamp(0., 1.);
        }
        let avg = if n > 0 && sw >= 0.0001 { ws / sw } else { 0. };
        let near = ((maxc - 6.) * 0.1).clamp(0., 1.);
        let sidesum = if left { lsum } else { rsum };
        let blk = (sidesum * 0.03333334 - 0.6).clamp(0., 1.) * near * 0.8;
        let target_scale = (1. - blk) + blk * avg;
        let rate = if target_scale > self.probe_turn_scale { 8. } else { 9. };
        self.probe_turn_scale = approach(self.probe_turn_scale, target_scale, rate, dt);
        speed *= self.probe_turn_scale;
        let mag = self.input_mag;
        if mag > 0.01 {
            let m = if mag < 0.7 {
                ((mag * 1.428571).clamp(0., 1.) + 1.) * 0.33
            } else {
                ((mag - 0.7) * 4.545454).clamp(0., 1.) * 0.34 + 0.66
            };
            let ia = (((self.input_angle * RAD).abs() - 25.) * 0.04).clamp(0., 1.);
            speed *= (m - 1.) * ia + 1.;
        }
        if !left {
            ang = -ang;
        }
        let maxstep = speed * DEG;
        if self.first {
            let r = ang / dt * RAD;
            let lo = speed * 0.5;
            let range = speed * 1.25 - lo;
            let f = if range.abs() > 0.0001 {
                ((r.abs() - lo) / range).clamp(0., 1.)
            } else if r.abs() < lo {
                0.
            } else if r.abs() > lo {
                1.
            } else {
                0.5
            };
            let v0 = ((1. - a2) * (1. - f) * r * DEG).abs().min(maxstep);
            self.turn_v = if ang < 0. { -v0 } else { v0 };
        }
        let x = spring(ang, 0., &mut self.turn_v, gain, damp, maxstep, dt);
        let step = ang - x;
        vel = rotate(vel, V3::UP, step);
        vel
    }

    /// exe+abf160: the virtual pivot: the anchor moved toward his plane of travel by the pivot factor
    #[allow(clippy::too_many_arguments)]
    fn pivot(&mut self, cfg: &Configs, tr: &Tracker, anchor: V3, pos: V3, base: V3, side: V3, ds: f32, age: f32) -> V3 {
        let si = self.speed_input.max(0.);
        let s = &cfg.swing;
        let f0 = { let x = lerp(tr.pivot_factor[0], 1., s.zero_input_pivot_scale_start); (tr.pivot_factor[0] - x) * si + x };
        let f1 = { let x = lerp(tr.pivot_factor[1], 1., s.zero_input_pivot_scale_trough); (tr.pivot_factor[1] - x) * si + x };
        let f2 = { let x = lerp(tr.pivot_factor[2], 1., s.zero_input_pivot_scale_final); (tr.pivot_factor[2] - x) * si + x };
        let p = pitch_of(base) * RAD;
        let mut f = if p <= 0. {
            let a = ((p.abs() - 20.) * 0.025).clamp(0., 1.);
            (f2 - f1) * a + f1
        } else {
            let a = ((p.abs() - 5.) * 0.02222222).clamp(0., 1.);
            (1. - a) * (f1 - f0) + f0
        };
        if self.phase == 2 {
            f = 0.;
        }
        self.pivot_factor = self.pivot_factor.min(f);
        let tw = (self.turn_v * RAD).abs();
        let at = ((age - 0.4) * 2.222222).clamp(0., 1.);
        let tt = ((tw - 45.) * 0.02222222).clamp(0., 1.);
        self.pivot_factor = (self.pivot_factor - at * ds * tt * 0.6).max(0.);
        let k = self.pivot_factor;
        let ap = anchor - pos;
        let d = ap.dot(side);
        V3::new(
            ((ap.x - side.x * d) + pos.x - anchor.x) * k + anchor.x,
            ((ap.y - side.y * d) + pos.y - anchor.y) * k + anchor.y,
            ((ap.z - side.z * d) + pos.z - anchor.z) * k + anchor.z,
        )
    }

    /// exe+ac0b60: the swing's gravity (negative) from the motion along the swing direction (`base`)
    fn gravity(&self, tr: &Tracker, base: V3, angle: f32, tilt: f32, rlen: f32, age: f32) -> f32 {
        let g = &tr.params.motion.gravity_params;
        let speed = base.len();
        let up = pitch_of(base) * -RAD;
        let t_pitch = remap(up, g.rise_pitch_angle_min, g.rise_pitch_angle_max);
        let t_tilt = remap(tilt, g.rise_tilt_angle_min, g.rise_tilt_angle_max);
        let tl = remap(speed, g.rise_low_speed_min, g.rise_low_speed_max);
        let th = remap(speed, g.rise_high_speed_min, g.rise_high_speed_max);
        let si = self.speed_input.max(0.);
        let low0 = (g.rise_gravity_low_max_zero - g.rise_gravity_low_min_zero) * tl + g.rise_gravity_low_min_zero;
        let mut low = (((g.rise_gravity_low_max - g.rise_gravity_low_min) * tl + g.rise_gravity_low_min) - low0) * si + low0;
        let high0 = (g.rise_gravity_high_max_zero - g.rise_gravity_high_min_zero) * th + g.rise_gravity_high_min_zero;
        low += (g.rise_gravity_low_tilt - low) * t_tilt;
        let high = (((g.rise_gravity_high_max - g.rise_gravity_high_min) * th + g.rise_gravity_high_min) - high0) * si + high0;
        let mut val = (((g.rise_gravity_high_tilt - high) * t_tilt + high) - low) * t_pitch + low;
        if base.y >= 0. {
            if rlen >= 16. {
                let t = remap(rlen, g.rise_line_length_min, g.rise_line_length_max);
                val *= (g.rise_line_length_scale - 1.) * t + 1.;
            } else {
                let t = ((rlen - 8.) * 0.125).clamp(0., 1.);
                val -= (val + 35.) * t;
            }
        } else if self.phase == 2 {
            val = self.grav_fall_hold;
        } else {
            let a = ((angle - 145.) * 0.02857143).clamp(0., 1.);
            let t = ((age - 0.25) * 4.).clamp(0., 1.);
            val = (self.grav_fall_final - self.grav_fall_initial) * t + self.grav_fall_initial;
            val -= (val + 50.) * a;
        }
        let floor = val.min(-10.);
        let mut out = (val - floor) * self.gravity_blend + floor;
        if self.phase != 0 {
            if base.y > 0. && self.speed_input < 0. {
                let a = self.speed_input.abs();
                let b = -25. - a * 15.;
                let tgt = ((-35. - a * 15.) - b) * t_pitch + b;
                let cand = (tgt - out) * a + out;
                if cand < out {
                    out = cand;
                }
            }
            if self.phase == 1 {
                out *= self.gravity_scale * if self.b5f9 { 0.5 } else { 1. };
            } else if self.phase == 2 {
                out = if base.y <= 0. { -14. } else { -22. };
            }
        }
        out
    }

    /// exe+abb030: pushed sideways off what the probes find ahead (nothing when they are clear)
    fn push_off(&mut self, mut pos: V3, ds: f32, age: f32) -> V3 {
        let pr = self.probes;
        let c0 = pr.c(0);
        let cl = pr.c(-1).max(pr.c(-2));
        let cr = pr.c(1).max(pr.c(2));
        let f = ((age - 0.25) * 2.439024).clamp(0., 1.);
        let sp = ((self.vel.len() - 4.) * 0.25).clamp(0., 1.);
        let w = (sp - 1.) * f + 1.;
        let mut target = V3::ZERO;
        if c0 <= 20. {
            let th = c0 + 12.;
            let mut push = true;
            let mut left = th < cl;
            if left {
                if th < cr {
                    let a = V3::new(self.attach.x - pos.x, 0., self.attach.z - pos.z).norm();
                    let b = V3::new(self.vel.x, 0., self.vel.z).norm();
                    left = a.x * b.z - b.x * a.z > 0.;
                }
            } else if cr <= th {
                push = false;
            }
            if push {
                let spd = self.vel.len();
                let side = V3::new(self.vel.z, 0., -self.vel.x).flat_norm();
                let a = ((c0 - 8.) * 0.08333334).clamp(0., 1.);
                let b = ((spd - 20.) * 0.1).clamp(0., 1.);
                let m = b * 0.3 + 0.6;
                let mut mag = (1. - a) * ((b * 0.75 + 1.) - m) + m;
                if !left {
                    mag = -mag;
                }
                target = V3::new(side.x * mag, 0., side.z * mag);
            }
        }
        self.push = approach_v(self.push, target, 16., ds);
        pos.y += self.push.y * ds * w;
        pos.z += self.push.z * ds * w;
        pos.x += ds * self.push.x * w;
        pos
    }

    /// exe+abf580: speed limits: the terminal speed (eased by the throttle) and the line's total
    fn cap_speed(&mut self, tr: &Tracker, v: V3, dirv: V3, rope: f32, ds: f32) -> V3 {
        let sp = &tr.params.motion.speed_params;
        let speed = v.len();
        let hs = v.flat_len();
        let si = self.speed_input;
        let mut term = self.terminal;
        let cap;
        if si < 0. {
            term -= si.abs() * sp.input_decel_back * ds;
            term = term.max(sp.terminal_velocity_max_floor);
            self.terminal = term;
            cap = (term * sp.terminal_velocity_min_percent).max(sp.terminal_velocity_min_floor);
            self.terminal_max = term;
            self.terminal_min = cap;
        } else {
            let x = (term - self.terminal_min) * si + self.terminal_min;
            let mut c = x;
            if x <= hs {
                c = term;
                if hs < term {
                    c = (hs - ds * sp.input_decel_zero).max(x);
                }
            }
            cap = c;
        }
        let p = pitch_of(dirv);
        let tmax = (self.terminal_max - self.terminal) * si.max(0.) + self.terminal;
        let total = match self.phase {
            0 => {
                if p <= 1.492257 {
                    (cap / cos(p).max(0.001)).min(tmax)
                } else {
                    tmax
                }
            }
            1 => tmax,
            _ => cap,
        };
        let lim = ((rope * 0.07142857).clamp(0., 1.) * total).min(sp.terminal_velocity_pure_max);
        let mut out = v;
        if lim < speed {
            out = out * (lim / speed);
        }
        let hs2 = out.flat_len();
        if cap < hs2 {
            out = out * (cap / hs2);
        }
        out
    }

    /// exe+abf850: keeps him above a floor (the lowest point of the web's first length, 2 m lower, or a swing floor
    /// volume's low point), and gives a step it shortened 70 % of the lost length back horizontally
    fn floor_guard(&mut self, v: &mut V3, old: V3, new: V3, pivot: V3, tilt: f32, ds: f32) -> V3 {
        let d_piv = dist(new, pivot);
        let mut floor = (self.anchor.y - self.rope_len0) - 2.;
        let mut cur = if self.floor_y == -1e30 { floor } else { self.floor_y };
        self.floor_y = cur;
        let mut rate_div = 0.5f32;
        if self.has_low_point {
            let d3 = dist(self.low_point, pivot);
            let lim = (d3 - 1.5).min(d_piv);
            if lim < d_piv - 0.001 && self.low_point.y < self.attach.y - 4. {
                floor = self.low_point.y + 2.;
                let a = v.flat_len();
                rate_div = flat_dist(self.low_point, old) / ((self.terminal - a) * 0.75 + a);
            }
        }
        if floor <= cur {
            if floor < cur - 2. {
                let t = ((cur - floor - 4.) * 0.08333334).clamp(0., 1.);
                self.floor_rate = approach(self.floor_rate, t * 8. + 2., t * 30. + 10., ds);
                self.floor_y = approach(self.floor_y, floor, self.floor_rate, ds);
                cur = self.floor_y;
            }
        } else {
            self.floor_y = floor;
            self.floor_rate = 0.;
            cur = floor;
        }
        let mut out = new;
        if old.y.max(new.y) < cur {
            let fr = ((rate_div - 0.2) * 5.).clamp(0., 1.);
            let need = if rate_div <= 0.01 { 0. } else { ((cur - new.y) / rate_div).max(0.) };
            let a = ((((cur - new.y) - 1.) * 0.8).clamp(0., 1.) * (1. - fr) * 4. + 1.).max(need).min(5.);
            self.floor_acc = approach(self.floor_acc, a, 32., ds);
            let gap = self.floor_y - new.y;
            let mut y = self.floor_acc * ds + new.y;
            let up = y - out.y;
            if up < gap && ds * v.y < 0. {
                y += (gap - up).min((ds * v.y).abs());
            }
            let mut fv = (y - new.y) / ds;
            if fv <= self.floor_vel {
                fv = approach(self.floor_vel, fv, 30., ds);
            }
            self.floor_vel = fv;
            out.y += fv * ds;
        } else {
            let dy = new.y - old.y;
            let mut decay = true;
            if dy < 0. {
                let c = cos(tilt * DEG);
                let fall = dy.abs();
                let fy = self.floor_y;
                let f10 = 1. - (((fy - new.y) / v.y - 0.1) * 2.5).clamp(0., 1.);
                if !(fy <= self.attach.y - c * d_piv) {
                    let e1 = exp((f10 * 3. - 8.) * ds);
                    let k = ((1. - e1) * (old.y - fy)).min(exp((-25. - f10 * 35.) * ds) * fall);
                    let fv = (fall - k) / ds;
                    out.y += fall - k;
                    self.floor_vel = fv;
                    if v.y < 0. {
                        v.y += (v.y.abs() * 0.33).min(fv * 0.66 * ds);
                    }
                    decay = false;
                }
            }
            if decay && self.floor_vel.abs() > 0.0001 {
                let t = ((self.floor_vel - 5.) * 0.1).clamp(0., 1.);
                let p = (pitch_of(*v) * -2.291831 - 0.8).clamp(0., 1.);
                let r = t * 23. + 7.;
                self.floor_vel = approach(self.floor_vel, 0., (30. - r) * p + r, ds);
                out.y += self.floor_vel.abs() * ds;
            }
            self.floor_acc = approach(self.floor_acc, 0., 32., ds);
        }
        let full = (new - old).len();
        let got = (out - old).len();
        if got < full - 0.0001 {
            let add = (full - got) * 0.7;
            let (hx, hz) = (out.x - old.x, out.z - old.z);
            let l = V3::new(hx, 0., hz).flat_len() + add;
            let l2 = hz * hz + hx * hx;
            let (nx, nz) = if l2 >= 1e-15 { let f = l / l2.sqrt(); (hx * f, hz * f) } else { (l, 0.) };
            out = V3::new(nx + old.x, out.y, nz + old.z);
            let hs = v.flat_len();
            if hs >= 0.001 {
                let extra = (self.terminal - hs).max(0.).min(add);
                let k = (extra + hs) / hs;
                v.x *= k;
                v.z *= k;
            }
        }
        out
    }

    /// exe+ac2200: the automatic release: 0 none, 1 a jump (fast), 2 a plain release (slow)
    pub fn auto_release(&self) -> u8 {
        let (_, tilt, angle) = rope_geometry(self.attach, self.hero.pos, self.dir);
        let d = (self.hero.pos - self.attach).norm();
        let elev = atan2(d.y, d.flat_len()) * -RAD;
        let dd = dist(self.hero.pos, self.attach);
        let lim = 50. - ((dd - 12.) * 0.125).clamp(0., 1.) * 45.;
        let speed = self.vel.len();
        if std::env::var_os("SMT_DEBUG").is_some() {
            eprintln!("  auto: elev {elev:.2} lim {lim:.2} angle {angle:.2} tilt {tilt:.2} vy {:.2} phase {} speed {speed:.2}", self.vel.y, self.phase);
        }
        if (elev < lim && self.vel.y > 0. && self.phase != 0) || (tilt <= 60. && angle <= lim) {
            if speed <= 20. { 2 } else { 1 }
        } else {
            0
        }
    }

    /// exe+aba8a0, the swing's exit, as far as the tracker goes: a release above -10 degrees after half a second of
    /// swinging raises the speed blend by 0.35 (exe+861290); the release adds momentum by his angle round the swing
    /// (exe+ac1430 on SwingReleaseData) unless that boost's cooldown runs (exe+861de0). The camera and animation hints
    /// it leaves on the tracker (+0x360..+0x380) aren't modelled.
    pub fn exit(&self, cfg: &Configs, tr: &mut Tracker, env: &Env, jumped: bool) {
        if self.release_pitch > -10. && self.age(env) > 0.5 && tr.speed_blend < 1. {
            tr.speed_blend = (tr.speed_blend + 0.35).min(1.);
        }
        // exe+85e310
        tr.ring_next = (tr.ring_next + 1) % 32;
        if self.phase == 2 || self.back_swing {
            return;
        }
        let rd = &cfg.swing.momentum_config.swing_release_data;
        let list = &rd.rate_scale_list;
        if list.is_empty() {
            return;
        }
        let (_, _, angle) = rope_geometry(self.attach, self.hero.pos, self.dir);
        let a = 180. - angle.clamp(0., 180.);
        let (mut prev, mut cur, mut t) = (&list[0], &list[0], 0.);
        for e in list.iter().skip(1) {
            cur = e;
            if a < e.angle {
                t = remap(a, prev.angle, e.angle);
                break;
            }
            prev = e;
            t = 1.;
        }
        let scale = (cur.scale - prev.scale) * t + prev.scale;
        let b = if jumped { &rd.jump_data } else { &rd.release_data };
        if tr.cooldowns[2] < 0.0001 {
            tr.add_momentum(cfg, scale * b.boost, b.boost_cap, true);
            tr.cooldowns[2] = b.retrigger_delay;
        }
    }

    /// exe+aba1f0: lets go when the button is up (after a two-frame countdown), on the jump button, when stuck or by
    /// itself near the top. Returns the release.
    pub fn check(&mut self, cfg: &Configs, tr: &Tracker, env: &Env) -> Option<SwingRelease> {
        let up = !(env.input.swing_button >= 0.09) && !self.b5f0;
        let age = self.age(env);
        let ev = age > 0.25 && self.release_event;
        let auto = self.auto_release();
        let blocked = self.probes.blocked() && !ev;
        let jumped = if ev { true } else { auto == 1 };
        let button = up || auto == 2;
        let high = auto == 2;
        let mut allowed = true;
        if auto == 0 && button && !jumped && !blocked {
            let c = self.release_countdown;
            self.release_countdown = c - 1;
            if c > 0 {
                allowed = false;
            }
        }
        if age > self.min_time && (button || jumped || blocked) && allowed {
            return Some(self.release(cfg, tr, env, jumped, blocked, high));
        }
        None
    }

    /// The release event: the jump button (buffered 0.05 s), read each frame by the swing's second callback (exe+ac3c80)
    pub fn read_release_event(&mut self, env: &Env) {
        if env.input.jump_pressed {
            self.release_event = true;
        }
    }

    /// exe+ac1680: the release velocity, its rising gravity and the release animation's pace
    fn release(&mut self, cfg: &Configs, tr: &Tracker, env: &Env, jumped: bool, blocked: bool, high: bool) -> SwingRelease {
        let mv = env.mover_vel;
        let mut pitch = pitch_of(self.dir) * -RAD;
        let mut out = mv;
        self.release_pitch = pitch;
        let s = &cfg.swing;
        if jumped {
            for z in &s.jump_redirect_zones {
                let a = pitch + 90.;
                if z.line_angle_start <= a && a <= z.line_angle_end {
                    let t = unlerp(a, z.line_angle_start, z.line_angle_end).powf(z.exit_bias);
                    let exit = (z.exit_angle_end - z.exit_angle_start) * t + z.exit_angle_start;
                    let l = mv.max_abs();
                    let (mut ax, mut az) = (mv.x, mv.z);
                    if l > 0. {
                        let k = 1. / l;
                        let n = 1. / ((mv.y * k).powi(2) + (mv.x * k).powi(2) + (mv.z * k).powi(2)).sqrt();
                        ax = n * mv.x * k;
                        az = n * mv.z * k;
                    }
                    let axis = V3::new(az, 0., -ax);
                    out = rotate(out, axis, (exit - a) * -DEG);
                    pitch = exit - 90.;
                    self.release_pitch = pitch;
                }
            }
        }
        let eq = pitch == s.release_angle_high_start;
        let lt = pitch < s.release_angle_high_start;
        let low_final = pitch < s.release_angle_low_final;
        let ge_low = s.release_angle_low_start <= pitch;
        let age = self.age(env);
        let early = if 0.5 <= age { !ge_low && !jumped } else { !ge_low };
        if early || blocked {
            if self.vel.y < out.y {
                out.y = (self.vel.y - out.y) * 0.25 + out.y;
            }
            self.release_anim_rate = 0.5;
            self.release_anim_blend = 0.33;
            return SwingRelease { velocity: out, gravity: 24., jumped, pitch, anim_rate: 0.5, anim_blend: 0.33, high: false, early: true };
        }
        let rp = &tr.params.release;
        let mut set = rp.params_middle;
        let mut band_high = false;
        if ge_low {
            if low_final {
                set = rp.params_low;
            } else if !(lt || eq) {
                band_high = true;
                set = rp.params_high;
            }
        } else {
            set = rp.params_fall;
            let hs = out.flat_len();
            if s.jump_from_fall_horz_min < hs {
                let m = (hs * s.jump_from_fall_horz_damp).max(s.jump_from_fall_horz_min);
                let f = ((pitch.abs() - 20.) * 0.02857143).clamp(0., 1.);
                let k = (m / hs - 1.) * f + 1.;
                out.z *= k;
                out.x *= k;
            }
        }
        let mut y = out.y;
        if jumped {
            y = set.jump_boost + out.y;
            y += if lt || eq || !self.b5f9 { 0. } else { 6. };
            out.y = y;
        }
        let sp = &tr.params.motion.speed_params;
        let floor;
        if y <= 0. || high {
            floor = if jumped { set.vert_floor_jump } else { set.vert_floor_base };
        } else {
            let hs = out.flat_len();
            let ft = unlerp(hs, (sp.terminal_velocity_horz_max - sp.terminal_velocity_horz_min) * 0.33 + sp.terminal_velocity_horz_min, sp.terminal_velocity_horz_max);
            let f19 = 1. - ft * 0.5;
            let n = out.norm();
            let mut add = n.y * sp.release_boost_xz * f19;
            add = add.min((self.terminal + 1. - hs).max(0.));
            add = add.max(sp.release_boost_alt_min - hs);
            let fl = V3::new(out.x, 0., out.z).norm();
            out = V3::new(add * fl.x + out.x, fl.y * add + out.y, fl.z * add + out.z);
            if jumped {
                let jb = if pitch < sp.jump_boost_pitch_low_max {
                    unlerp(pitch, sp.jump_boost_pitch_low_min, sp.jump_boost_pitch_low_max)
                } else if sp.jump_boost_pitch_high_min < pitch {
                    1. - unlerp(pitch, sp.jump_boost_pitch_high_min, sp.jump_boost_pitch_high_max)
                } else {
                    1.
                };
                let add2 = jb * sp.jump_boost_xz * f19;
                let fl = V3::new(out.x, 0., out.z).norm();
                out = V3::new(add2 * fl.x + out.x, fl.y * add2 + out.y, fl.z * add2 + out.z);
                floor = set.vert_floor_jump;
            } else {
                floor = set.vert_floor_base;
            }
        }
        out.y = out.y.max(floor);
        let gd = &rp.release_gravity_data;
        let (t, lo, hi) = if gd.gravity_angle_mid <= pitch {
            let t = remap(pitch, gd.gravity_angle_mid, gd.gravity_angle_high);
            if jumped { (t, gd.gravity_jump_mid, gd.gravity_jump_high) } else { (t, gd.gravity_release_mid, gd.gravity_release_high) }
        } else {
            let t = remap(pitch, gd.gravity_angle_low, gd.gravity_angle_mid);
            if jumped { (t, gd.gravity_jump_low, gd.gravity_jump_mid) } else { (t, gd.gravity_release_low, gd.gravity_release_mid) }
        };
        let gravity = (hi - lo) * t + lo;
        let r = (out.y / gravity).max(0.1);
        let rate = (r * 1.25).max(0.1).min(2.);
        self.release_anim_rate = rate;
        self.release_anim_blend = if low_final || !jumped { 0.35 } else { rate.min(1.) };
        SwingRelease {
            velocity: out,
            gravity,
            jumped,
            pitch,
            anim_rate: self.release_anim_rate,
            anim_blend: self.release_anim_blend,
            high: band_high,
            early: false,
        }
    }
}

/// exe+ab38e0: the swing's terminal speed from how far and high the web is and how fast he falls into it
pub fn terminal_target(sp: &crate::config::SpeedParams, attach: V3, pos: V3, vel: V3) -> f32 {
    let d = attach - pos;
    let dist = d.len();
    let flat = d.flat_len();
    let elev = atan2(d.y, flat);
    let a = (elev * 2.291831 - 0.4).clamp(0., 1.);
    let fall = vel.y.min(0.).abs();
    let lt = ((dist - 22.) * 0.04545455).clamp(0., 1.);
    let w = ((1. - a) + lt) * 0.75;
    let mid = sp.fall_speed_threshold_mid;
    let x = if mid <= fall {
        if w < 1. {
            fall
        } else {
            ((((sp.fall_speed_threshold_max - mid) * 0.5 + mid) - mid) * (w - 1.) + mid).max(fall)
        }
    } else if w < 1. {
        fall + (mid - fall) * w
    } else {
        ((((sp.fall_speed_threshold_max - mid) * 0.5 + mid) - mid) * (w - 1.) + mid).max(fall)
    };
    let t = if mid <= x {
        let r = sp.fall_speed_threshold_max - mid;
        let t = if r.abs() <= 0.0001 { if x <= mid { 0.5 } else { 1. } } else { ((x - mid) / r).clamp(0., 1.) };
        (sp.terminal_velocity_horz_max - sp.terminal_velocity_horz_mid) * t + sp.terminal_velocity_horz_mid
    } else {
        let t = remap(x, sp.fall_speed_threshold_min, mid);
        (sp.terminal_velocity_horz_mid - sp.terminal_velocity_horz_min) * t + sp.terminal_velocity_horz_min
    };
    t.max(vel.flat_len())
}
