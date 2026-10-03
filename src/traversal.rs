//! The game's own swing, swing jump and fall driving the sandbox hero. `crates/sm_traversal` ports them from the
//! installed Spider-Man.exe and is checked against the game's code running offline (tools/native_oracle). This module
//! supplies what the game's world would: the swing point (the game's hunter needs New York's swing hint volumes, so
//! points come from a fan of rays over the towers, as ArkWeb finds them, scored by where the game's own anchors sat in
//! recorded swinging), the inputs, and collisions. Ground movement, wall runs, zips, charged jumps and the dive stay
//! the sandbox's.
use crate::physics::{Tower, ray_box};
use bevy::prelude::*;
use sm_traversal::config::Configs;
use sm_traversal::math::{Rows, V3};
use sm_traversal::sim::{self, StepInput, Traversal};
use sm_traversal::swing::{FrameInput, SwingEntry, SwingRelease};
use std::sync::{Arc, OnceLock};

pub fn v3(v: Vec3) -> V3 {
    V3::new(v.x, v.y, v.z)
}
pub fn vec3(v: V3) -> Vec3 {
    Vec3::new(v.x, v.y, v.z)
}

/// The native configs (assets/tuning/native, exported from the user's game), shared
fn configs() -> Arc<Configs> {
    static CFG: OnceLock<Arc<Configs>> = OnceLock::new();
    CFG.get_or_init(|| Arc::new(Configs::embedded())).clone()
}

/// The game's swing point, as ArkWeb hands it to the swing (the hunter's outputs, exe+871fb0)
#[derive(Clone, Copy, Debug)]
pub struct SwingPoint {
    /// the web's point on the surface
    pub attach: Vec3,
    /// the pivot: pushed out from a wall along its horizontal normal by 0.75 of the horizontal distance, 1 to 6 m
    pub anchor: Vec3,
    pub score: f32,
}

/// ArkWeb's score (native.h ScoreAnchor): best 18 m above and 32 m away, straight ahead. Points under 8 m above or
/// nearer than 12 m are refused (steep little pendulums launch him straight up), as are those over 70 m away or
/// more than 80 degrees off his heading.
fn score(attach: Vec3, hero: Vec3, heading: Vec3) -> Option<f32> {
    let d = attach - hero;
    let flat = d.with_y(0.).length();
    if d.y < 8. || flat < 12. || flat > 70. {
        return None;
    }
    let a = (d.with_y(0.).dot(heading) / flat).clamp(-1., 1.).acos().to_degrees();
    if a > 80. {
        return None;
    }
    Some(-((d.y - 18.) / 10.).powi(2) - ((flat - 32.) / 15.).powi(2) - (a / 45.).powi(2))
}

/// The outward normal of the box face `p` lies on
fn face_normal(t: Tower, p: Vec3) -> Vec3 {
    let (lo, hi) = (t.min(), t.max());
    let faces = [
        ((p.x - lo.x).abs(), Vec3::NEG_X),
        ((hi.x - p.x).abs(), Vec3::X),
        ((p.y - lo.y).abs(), Vec3::NEG_Y),
        ((hi.y - p.y).abs(), Vec3::Y),
        ((p.z - lo.z).abs(), Vec3::NEG_Z),
        ((hi.z - p.z).abs(), Vec3::Z),
    ];
    faces.iter().min_by(|a, b| a.0.total_cmp(&b.0)).unwrap().1
}

/// The best swing point in a 7 x 7 fan of rays ahead of his heading (his travel, else the camera, turned toward the
/// stick), 22 to 70 degrees up and 50 to either side, 70 m long (ArkWeb native.h AnchorRay / ScanStep)
pub fn find_swing_point(pos: Vec3, velocity: Vec3, stick: Vec3, camera_forward: Vec3, towers: &[Tower]) -> Option<SwingPoint> {
    const ELEVATION: [f32; 7] = [30., 22., 38., 46., 54., 62., 70.];
    const AZIMUTH: [f32; 7] = [0., -15., 15., -30., 30., -50., 50.];
    let mut heading = velocity.with_y(0.);
    if heading.length() < 3. {
        heading = camera_forward.with_y(0.);
    }
    let mut heading = heading.normalize_or_zero();
    if heading == Vec3::ZERO {
        return None;
    }
    let stick = stick.with_y(0.);
    if stick.length_squared() > 0.25 {
        heading = (heading + stick).normalize_or(heading);
    }
    let start = pos + Vec3::Y * 0.5;
    let mut best: Option<SwingPoint> = None;
    for el in ELEVATION {
        for az in AZIMUTH {
            let h = Quat::from_rotation_y(az.to_radians()) * heading;
            let e = el.to_radians();
            let dir = (h * e.cos() + Vec3::Y * e.sin()).normalize();
            let hit = towers
                .iter()
                .filter_map(|t| ray_box(start, dir, *t, 70.).filter(|d| *d > 0.).map(|d| (d, *t)))
                .min_by(|a, b| a.0.total_cmp(&b.0));
            let Some((d, tower)) = hit else { continue };
            let attach = start + dir * d;
            let Some(s) = score(attach, pos, heading) else { continue };
            if best.is_some_and(|b| b.score >= s) {
                continue;
            }
            let n = face_normal(tower, attach);
            let mut anchor = attach;
            if n.y.abs() <= 0.85 {
                let flat = (attach - pos).with_y(0.).length();
                anchor += n.with_y(0.).normalize() * (0.75 * flat).clamp(1., 6.);
            }
            best = Some(SwingPoint { attach, anchor, score: s });
        }
    }
    best
}

/// The floor under him (a tower top or the street), for the height above ground the states read
pub fn ground_below(pos: Vec3, towers: &[Tower]) -> f32 {
    towers
        .iter()
        .filter(|t| {
            let (lo, hi) = (t.min(), t.max());
            pos.x >= lo.x && pos.x <= hi.x && pos.z >= lo.z && pos.z <= hi.z && hi.y <= pos.y
        })
        .map(|t| t.max().y)
        .fold(0., f32::max)
}

/// The hero's traversal state machine and what the sandbox keeps beside it
#[derive(Clone)]
pub struct Native {
    pub trav: Traversal,
    /// the web's surface point while swinging
    pub attach: Vec3,
    /// a swing to start on the next step
    pending: Option<SwingPoint>,
    /// seconds since the jump button's press (the swing's release event is buffered 0.05 s)
    pub jump_age: f32,
}

impl Default for Native {
    fn default() -> Self {
        Self {
            trav: Traversal::new(configs(), V3::ZERO, V3::ZERO, V3::new(0., 0., -1.)),
            attach: Vec3::ZERO,
            pending: None,
            jump_age: 99.,
        }
    }
}

/// What a native step leaves for the sandbox hero
pub struct NativeFrame {
    pub mode: sim::Mode,
    pub released: Option<SwingRelease>,
}

impl Native {
    pub fn active(&self) -> bool {
        self.trav.mode != sim::Mode::Off || self.pending.is_some()
    }
    pub fn swinging(&self) -> bool {
        self.trav.mode == sim::Mode::Swing || self.pending.is_some()
    }
    pub fn momentum(&self) -> f32 {
        self.trav.tracker.momentum
    }
    /// The swing processor's anchor this frame (the pivot after its drift)
    pub fn pivot(&self) -> Vec3 {
        vec3(self.trav.processor.anchor)
    }
    /// The angle round the swing (degrees: about 180 entering above, 90 under the point, toward 0 up the far side)
    pub fn swing_angle(&self) -> f32 {
        let s = &self.trav.swing;
        sm_traversal::swing::rope_geometry(s.attach, self.trav.pos, s.dir).2
    }
    pub fn swing_age(&self) -> f32 {
        (self.trav.time - self.trav.swing.entry_time) as f32
    }
    /// The swing's direction of travel (flat)
    pub fn swing_forward(&self) -> Vec3 {
        vec3(self.trav.swing.dir.flat_norm())
    }

    /// Hand the sandbox's motion over: his position, velocity and facing as the mover's
    pub fn sync(&mut self, pos: Vec3, velocity: Vec3, heading: Vec3, airborne: bool) {
        let t = &mut self.trav;
        t.pos = v3(pos);
        t.mover_vel = v3(velocity);
        let f = heading.with_y(0.).normalize_or(Vec3::NEG_Z);
        t.fwd = v3(f);
        if airborne {
            t.air_time = t.air_time.min(-0.01);
        } else {
            t.air_time = t.air_time.max(0.);
        }
    }
    pub fn start_swing(&mut self, point: SwingPoint) {
        self.pending = Some(point);
    }
    pub fn start_fall(&mut self, dt: f32) {
        self.pending = None;
        self.trav.start_fall(dt);
    }
    /// Leave the native states (landing, a wall, a zip, the sandbox's dive)
    pub fn stop(&mut self, dt: f32) {
        self.pending = None;
        if self.trav.mode == sim::Mode::Swing {
            self.trav.cancel_swing(dt);
        } else {
            self.trav.stop();
        }
    }
    /// The tracker runs every frame in the game, on the ground too (momentum decays, setups blend)
    pub fn idle(&mut self, velocity: Vec3, airborne: bool, height: f32, dt: f32) {
        let cfg = self.trav.cfg.clone();
        self.trav.time += dt as f64;
        self.trav.tracker.update(&cfg, sm_traversal::tracker::MoverView { velocity: v3(velocity), airborne, height_above_ground: height }, dt);
    }

    /// One frame of the game's states: returns the move to make. Call `moved` with where he ended up.
    #[allow(clippy::too_many_arguments)]
    pub fn step(&mut self, stick: Vec2, swing_held: bool, jump_pressed: bool, cam_forward: Vec3, cam_right: Vec3, height: f32, dt: f32) -> (Vec3, NativeFrame) {
        if jump_pressed {
            self.jump_age = 0.;
        } else {
            self.jump_age += dt;
        }
        // the camera's rows as the game keeps them (side points left)
        let fwd = cam_forward.normalize_or(Vec3::NEG_Z);
        let side = -cam_right.normalize_or(Vec3::X);
        let up = (-side).cross(fwd).normalize_or(Vec3::Y);
        let cam = Rows { side: v3(side), up: v3(up), fwd: v3(fwd), pos: self.trav.pos };
        let mut si = StepInput {
            input: FrameInput { stick: [stick.x, stick.y], swing_button: if swing_held { 1. } else { 0. }, jump_pressed: self.jump_age < 0.05, look: 0. },
            cam,
            drift: true,
            height,
            ..Default::default()
        };
        if let Some(p) = self.pending.take() {
            si.swing = Some(SwingEntry::new(v3(p.anchor), v3(p.attach)));
            self.attach = p.attach;
        }
        let out = self.trav.step(&si, dt);
        (vec3(out.displacement), NativeFrame { mode: self.trav.mode, released: out.released })
    }
    pub fn moved(&mut self, pos: Vec3, airborne: bool, dt: f32) {
        self.trav.moved(v3(pos), airborne, dt);
    }
    pub fn facing(&self) -> Vec3 {
        vec3(self.trav.fwd)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::physics::FOOT;
    #[test]
    fn swing_point_sits_ahead_and_up_with_the_pivot_off_the_wall() {
        // a long facade to his right, along his travel
        let towers = [Tower { center: Vec3::new(14., 45., -40.), half: Vec3::new(4., 45., 40.) }];
        let pos = Vec3::new(0., 30., 0.);
        let p = find_swing_point(pos, Vec3::NEG_Z * 25., Vec3::ZERO, Vec3::NEG_Z, &towers).expect("a point on the facade");
        let d = p.attach - pos;
        assert!(d.y >= 8. && d.with_y(0.).length() >= 12., "{p:?}");
        assert!(d.z < 0., "ahead of travel: {p:?}");
        assert!((p.attach.x - 10.).abs() < 0.01, "on the facing wall: {p:?}");
        let push = p.attach.x - p.anchor.x;
        assert!((1. ..=6.001).contains(&push), "pivot pushed out toward the street: {p:?}");
    }
    #[test]
    fn nothing_behind_or_too_close() {
        let towers = [Tower { center: Vec3::new(0., 45., 30.), half: Vec3::new(10., 45., 4.) }];
        assert!(find_swing_point(Vec3::new(0., 30., 0.), Vec3::NEG_Z * 25., Vec3::ZERO, Vec3::NEG_Z, &towers).is_none());
        let near = [Tower { center: Vec3::new(0., 45., -8.), half: Vec3::new(10., 45., 2.) }];
        assert!(find_swing_point(Vec3::new(0., 30., 0.), Vec3::NEG_Z * 25., Vec3::ZERO, Vec3::NEG_Z, &near).is_none());
    }
    #[test]
    fn a_swing_carries_him_forward_and_releases_into_the_air() {
        let towers = [
            Tower { center: Vec3::new(14., 45., -60.), half: Vec3::new(4., 45., 80.) },
            Tower { center: Vec3::new(-14., 45., -60.), half: Vec3::new(4., 45., 80.) },
        ];
        let mut n = Native::default();
        let dt = 1. / 60.;
        let mut pos = Vec3::new(0., 40., 0.);
        let vel = Vec3::new(0., -10., -25.);
        n.sync(pos, vel, Vec3::NEG_Z, true);
        let p = find_swing_point(pos, vel, Vec3::ZERO, Vec3::NEG_Z, &towers).unwrap();
        n.start_swing(p);
        let mut released = None;
        for f in 0..240 {
            let jump = f == 80;
            let h = pos.y - FOOT - ground_below(pos, &towers);
            let (d, fr) = n.step(Vec2::Y, true, jump, Vec3::NEG_Z, Vec3::X, h, dt);
            pos += d;
            n.moved(pos, true, dt);
            if let Some(r) = fr.released {
                released = Some((f, r));
            }
            assert!(pos.is_finite());
        }
        let (f, r) = released.expect("the jump lets go");
        assert!(f >= 80 && f <= 82, "released on the jump: frame {f}");
        assert!(r.jumped && r.velocity.y > 0.);
        assert!(pos.z < -60., "travelled forward: {pos:?}");
        assert_ne!(n.trav.mode, sim::Mode::Swing);
    }
}
