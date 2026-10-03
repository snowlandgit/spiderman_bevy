//! Forward web-zip motion and physical web attachment search.
//! Values come from the game's outdoor/ground web-zip setup; integration is independent.
use crate::physics::{FOOT, Hero, Tower, ray_box};
use bevy::prelude::*;
use serde_json::Value;

#[derive(Clone)]
pub struct ZipTuning {
    pub outdoor: Value,
    pub ground: Value,
}
impl Default for ZipTuning {
    fn default() -> Self {
        Self {
            outdoor: serde_json::from_str(include_str!(
                "../assets/tuning/hero_webzipsetup_outdoor.json"
            ))
            .unwrap(),
            ground: serde_json::from_str(include_str!(
                "../assets/tuning/hero_webzipsetup_ground.json"
            ))
            .unwrap(),
        }
    }
}
#[derive(Clone, Copy, Debug)]
pub struct ZipMotion {
    pub direction: Vec3,
    pub anchors: [Option<Vec3>; 2], // Left wrist, right wrist.
    pub launch_speed: f32,
    pub lift_speed: f32,
    pub gravity: f32,
    pub drop_kept: f32,
    pub carry: f32,
    pub lockout: f32,
    pub kicked: bool,
    pub from_ground: bool,
    pub from_dive: bool,
    pub from_high_release: bool,
}
impl ZipTuning {
    pub fn motion(
        &self,
        hero: &Hero,
        forward: Vec3,
        anchors: [Option<Vec3>; 2],
        ground: bool,
        stage: u32,
        gravity_floor: f32,
    ) -> ZipMotion {
        let config = if ground { &self.ground } else { &self.outdoor };
        let val = |key: &str| config.pointer(key).and_then(Value::as_f64).unwrap() as f32;
        let speed = hero.velocity.with_y(0.).length();
        let ratio = (speed / val("/SpeedInMax")).clamp(0., 1.);
        let mut boost = val("/SpeedBoostForwardMax")
            + (val("/SpeedBoostForwardMin") - val("/SpeedBoostForwardMax")) * ratio;
        let mut floor = val("/OutSpeedFloor");
        let mut cap = if ground {
            val("/BoostSpeedCap")
        } else {
            f32::INFINITY
        };
        let mut drop_kept = 0.;
        let mut lockout = val("/ReZipTime");
        if stage > 1 {
            let key = if stage == 2 { "ReZipTwo" } else { "ReZipThree" };
            let v = |name: &str| config[key][name].as_f64().unwrap() as f32;
            boost *= v("BoostScale");
            floor = v("OutSpeedFloor");
            cap = v("BoostCap");
            drop_kept = v("DropSpeedKept");
            lockout = v("ZipLockoutTime");
        }
        // Native boost caps limit newly gained speed, preserving existing fast travel.
        let launch_speed = (speed + boost).max(floor).min(cap.max(speed));
        let height = val("/OutHeightMax") + (val("/OutHeightMin") - val("/OutHeightMax")) * ratio;
        let peak_ratio = ((launch_speed - val("/TTPOutSpeedMin"))
            / (val("/TTPOutSpeedMax") - val("/TTPOutSpeedMin")))
        .clamp(0., 1.);
        let peak =
            val("/TimeToPeakMin") + (val("/TimeToPeakMax") - val("/TimeToPeakMin")) * peak_ratio;
        // Keep the configured height with a shorter, weighted arc instead of low-gravity hang.
        let gravity = (2. * height / (peak * peak)).max(gravity_floor);
        ZipMotion {
            direction: forward,
            anchors,
            launch_speed,
            lift_speed: (2. * gravity * height).sqrt(),
            gravity,
            drop_kept,
            carry: val("/SpeedScaleLimit"),
            lockout,
            kicked: false,
            from_ground: ground,
            from_dive: hero.mode == crate::physics::Mode::Dive,
            from_high_release: hero.boosted_release && hero.last_swing < 1.5,
        }
    }
}
pub fn anchors_for(position: Vec3, forward: Vec3, towers: &[Tower]) -> [Option<Vec3>; 2] {
    let forward = forward.with_y(0.).normalize_or_zero();
    let right = forward.cross(Vec3::Y);
    let mut anchors = [None, None];
    let mut scores = [f32::INFINITY; 2];
    for tower in towers {
        let lo = tower.min();
        let hi = tower.max();
        let desired = position + forward * 20. + Vec3::Y * 7.;
        let p = desired.clamp(
            lo + Vec3::new(0.02, 2., 0.02),
            hi - Vec3::new(0.02, 1., 0.02),
        );
        for (axis, bound) in [(0, lo.x), (0, hi.x), (2, lo.z), (2, hi.z)] {
            let mut anchor = p;
            anchor[axis] = bound;
            let delta = anchor - position;
            let distance = delta.length();
            if !(3.0..55.0).contains(&distance) || delta.dot(forward) < 1. || delta.y < 0. {
                continue;
            }
            let side = if delta.dot(right) < 0. { 0 } else { 1 };
            let direction = delta / distance;
            if towers.iter().any(|b| {
                ray_box(position + direction * 0.1, direction, *b, distance - 0.25).is_some()
            }) {
                continue;
            }
            let score = (delta.dot(forward) - 20.).abs() + distance * 0.2 + (delta.y - 7.).abs();
            if score < scores[side] {
                scores[side] = score;
                anchors[side] = Some(anchor);
            }
        }
    }
    anchors
}
pub fn perch_for(position: Vec3, aim: Vec3, towers: &[Tower]) -> Option<Vec3> {
    let aim = aim.normalize_or_zero();
    let mut best = None;
    let mut score = f32::NEG_INFINITY;
    for tower in towers {
        let lo = tower.min();
        let hi = tower.max();
        for x in [lo.x + 0.65, hi.x - 0.65] {
            for z in [lo.z + 0.65, hi.z - 0.65] {
                let target = Vec3::new(x, hi.y + FOOT, z);
                let delta = target - position;
                let distance = delta.length();
                if !(3.0..50.0).contains(&distance) {
                    continue;
                }
                let direction = delta / distance;
                let alignment = aim.dot(direction);
                if alignment < 45f32.to_radians().cos() {
                    continue;
                }
                // A reachable roof edge must have an unobstructed capsule-center approach.
                if towers.iter().any(|b| {
                    ray_box(position + direction * 0.1, direction, *b, distance - 0.8).is_some()
                }) {
                    continue;
                }
                let rank = alignment * 4. - distance / 100.;
                if rank > score {
                    score = rank;
                    best = Some(target);
                }
            }
        }
    }
    best
}
#[cfg(test)]
mod tests {
    use super::*;
    use crate::physics::{Arena, DT, Intent, Mode, Tuning};
    #[test]
    fn zip_webs_attach_to_visible_tower_faces() {
        let h = Hero::default();
        let a = Arena::default();
        let anchors = anchors_for(h.pos, Vec3::NEG_Z, &a.0);
        assert!(anchors.iter().any(Option::is_some));
        for p in anchors.into_iter().flatten() {
            assert!(a.0.iter().any(|b| b.contains(p, 0.001)));
        }
    }
    #[test]
    fn forward_zip_does_not_steer_into_the_attachment() {
        let mut h = Hero::default();
        let a = Arena::default();
        let t = Tuning::default();
        h.step(
            Intent {
                zip: true,
                forward: Vec3::NEG_Z,
                ..default()
            },
            &a.0,
            &t,
            DT,
        );
        assert_eq!(h.mode, Mode::Zip);
        for _ in 0..110 {
            h.step(Intent::default(), &a.0, &t, DT);
        }
        assert!(h.velocity.z < -20. && h.velocity.x.abs() < 0.001);
        assert!(h.pos.x.abs() < 0.001);
        assert!(h.pos.y > 18. && h.rope.is_none() && h.zip_count == 1);
    }
    #[test]
    fn zip_interrupts_swing_and_respects_repeat_lockout() {
        let mut h = Hero::default();
        let a = Arena::default();
        let t = Tuning::default();
        h.attach_at(Vec3::new(-16.9, 40., -20.), Vec3::X);
        for _ in 0..75 {
            h.step(
                Intent {
                    zip: true,
                    swing: true,
                    forward: Vec3::NEG_Z,
                    ..default()
                },
                &a.0,
                &t,
                DT,
            );
        }
        assert!(h.rope.is_none() && h.zip_count == 1);
    }
    #[test]
    fn native_zip_caps_preserve_existing_fast_momentum() {
        let mut h = Hero::default();
        h.velocity = Vec3::NEG_Z * 45.;
        let t = ZipTuning::default();
        let motion = t.motion(
            &h,
            Vec3::NEG_Z,
            [None, None],
            false,
            3,
            Tuning::default().swing.release_gravity_min,
        );
        assert!(motion.launch_speed >= 45.);
    }
    #[test]
    fn zip_from_dive_can_finish_with_dive_button_held() {
        let mut h = Hero::default();
        h.mode = Mode::Dive;
        h.velocity = Vec3::new(0., -25., -20.);
        let a = Arena::default();
        let t = Tuning::default();
        h.step(
            Intent {
                zip: true,
                dive: true,
                forward: Vec3::NEG_Z,
                ..default()
            },
            &a.0,
            &t,
            DT,
        );
        assert!(h.zip_motion.is_some_and(|zip| zip.from_dive));
        for _ in 0..35 {
            h.step(
                Intent {
                    dive: true,
                    ..default()
                },
                &a.0,
                &t,
                DT,
            );
        }
        assert_eq!(h.mode, Mode::Zip);
        assert!(h.zip_motion.is_some_and(|zip| zip.kicked));
        assert!(h.velocity.z < -20. && h.velocity.y > 0.);
    }
    #[test]
    fn zip_without_surfaces_does_not_create_floating_webs() {
        let mut h = Hero::default();
        let t = Tuning::default();
        h.step(
            Intent {
                zip: true,
                forward: Vec3::NEG_Z,
                ..default()
            },
            &[],
            &t,
            DT,
        );
        assert_eq!(h.zip_count, 0);
        assert_ne!(h.mode, Mode::Zip);
    }
    #[test]
    fn grounded_zip_finishes_the_shot_before_launching() {
        let mut h = Hero::default();
        h.pos = Vec3::new(0., FOOT, 8.);
        h.mode = Mode::Ground;
        h.velocity = Vec3::ZERO;
        let a = Arena::default();
        let t = Tuning::default();
        h.step(
            Intent {
                zip: true,
                forward: Vec3::NEG_Z,
                ..default()
            },
            &a.0,
            &t,
            DT,
        );
        for _ in 0..35 {
            h.step(Intent::default(), &a.0, &t, DT);
        }
        assert!(
            h.zip_motion.is_some()
                && h.pos.y > FOOT + 0.4
                && h.velocity.y > 0.
                && h.velocity.z < -10.
        );
    }
    fn swing_zip_fixture(upward_speed: f32) -> (Hero, Vec<Tower>, Tuning) {
        let t = Tuning::default();
        let towers = [-20., 20.]
            .into_iter()
            .map(|x| Tower {
                center: Vec3::new(x, 100., -40.),
                half: Vec3::new(4., 100., 70.),
            })
            .collect::<Vec<_>>();
        let mut h = Hero::default();
        h.pos = Vec3::new(0., 100., 0.);
        h.velocity = Vec3::new(0., upward_speed, -24.);
        h.attach_at(Vec3::new(-16., 130., -20.), Vec3::X);
        (h, towers, t)
    }
    #[test]
    fn swing_to_zip_keeps_weight_during_shot_kick_and_followthrough() {
        let (mut h, towers, t) = swing_zip_fixture(18.);
        h.step(
            Intent {
                zip: true,
                forward: Vec3::NEG_Z,
                ..default()
            },
            &towers,
            &t,
            DT,
        );
        assert!(h.rope.is_none() && h.mode == Mode::Zip);
        assert!(
            (h.velocity.y - (18. - 44. * DT)).abs() < 0.001,
            "lost gravity at the swing transition"
        );
        let mut kick_observed = false;
        let mut peak = h.pos.y;
        for _ in 1..132 {
            let before = h.velocity.y;
            let before_zip = h.zip_motion;
            let was_native = h.native.active();
            h.step(Intent::default(), &towers, &t, DT);
            let just_kicked = before_zip.is_some_and(|zip| !zip.kicked)
                && h.zip_motion.is_some_and(|zip| zip.kicked);
            if just_kicked {
                let zip = h.zip_motion.unwrap();
                assert!(
                    h.velocity.y <= before.max(zip.lift_speed) - 44. * DT + 0.001,
                    "zip stacked lift onto the swing ascent"
                );
                kick_observed = true;
            } else if before_zip.is_some() && h.zip_motion.is_some() {
                assert!(
                    h.velocity.y <= before - 44. * DT + 0.001,
                    "gravity paused during zip followthrough: {before} -> {}",
                    h.velocity.y
                );
            } else if h.zip_motion.is_none() && before_zip.is_none() && was_native {
                // the game's fall after it (its first frame measures the move's average, half a step of gravity)
                assert!(
                    h.velocity.y <= before - 25. * DT + 0.001,
                    "gravity paused after the zip: {before} -> {}",
                    h.velocity.y
                );
            }
            peak = peak.max(h.pos.y);
        }
        println!("SWING_ZIP peak={peak} final_vy={}", h.velocity.y);
        assert!(kick_observed && h.mode == Mode::Air && h.zip_motion.is_none());
        assert!(
            peak < 107. && h.velocity.y < -25.,
            "zip still hangs in the air"
        );
    }
    #[test]
    fn zip_on_fast_upstroke_preserves_ascent_without_adding_another_lift() {
        let (mut h, towers, t) = swing_zip_fixture(30.);
        h.step(
            Intent {
                zip: true,
                forward: Vec3::NEG_Z,
                ..default()
            },
            &towers,
            &t,
            DT,
        );
        for _ in 0..30 {
            let before = h.velocity;
            h.step(Intent::default(), &towers, &t, DT);
            if h.zip_motion.is_some_and(|zip| zip.kicked) {
                assert!(
                    (h.velocity.y - (before.y - 44. * DT)).abs() < 0.001,
                    "upward momentum was canceled or lift was stacked: {before:?} -> {:?}",
                    h.velocity
                );
                assert!(h.velocity.z < -27. && h.velocity.y > 20.);
                return;
            }
        }
        panic!("zip never kicked from the swing");
    }
    #[test]
    fn point_zip_stops_on_the_selected_roof() {
        let tower = Tower {
            center: Vec3::new(0., 15., -20.),
            half: Vec3::new(8., 15., 8.),
        };
        let t = Tuning::default();
        let mut h = Hero::default();
        h.pos = Vec3::new(0., 28., 0.);
        h.velocity = Vec3::ZERO;
        let aim = Vec3::new(0., 3., -13.).normalize();
        let target = perch_for(h.pos, aim, &[tower]).expect("roof target");
        h.step(
            Intent {
                point_zip: true,
                aim,
                ..default()
            },
            &[tower],
            &t,
            DT,
        );
        for _ in 0..240 {
            h.step(Intent::default(), &[tower], &t, DT);
        }
        assert_eq!(h.mode, Mode::Ground);
        assert!(h.pos.distance(target) < 0.1);
        assert!(h.velocity.length() < 0.01);
    }
}
