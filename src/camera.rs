//! Stable orbit camera: shared aim/position focus, bounded pitch, speed FOV; it looks up past him from the ground.
use crate::physics::{Hero, Mode};
use bevy::prelude::*;
use serde::Deserialize;
#[derive(Resource, Clone, Deserialize)]
pub struct CameraTuning {
    pub follow_distance: f32,
    pub pivot_height: f32,
    pub base_pitch_degrees: f32,
    pub auto_pitch_max_degrees: f32,
    pub dive_pitch_degrees: f32,
    pub pitch_response: f32,
    pub pitch_rate_degrees: f32,
    pub yaw_response: f32,
    pub yaw_rate_degrees: f32,
    pub auto_yaw_delay: f32,
    pub focus_response: f32,
    pub max_focus_error: f32,
    /// horizontal FOV slow, and at speed (between fov_speed_min and fov_speed_max), changing at fov_rate_degrees/s
    pub horizontal_fov_degrees: f32,
    pub fast_fov_degrees: f32,
    pub fov_speed_min: f32,
    pub fov_speed_max: f32,
    pub fov_rate_degrees: f32,
    pub distance_restore_rate: f32,
    /// how far up the view can tilt; the boom's length it comes in to when looking up; its clearance over the floor
    pub look_up_max_degrees: f32,
    pub look_up_distance: f32,
    pub ground_clearance: f32,
}
impl Default for CameraTuning {
    fn default() -> Self {
        let v: serde_json::Value =
            serde_json::from_str(include_str!("../assets/tuning/sandbox_presentation.json"))
                .unwrap();
        serde_json::from_value(v["camera"].clone()).unwrap()
    }
}
#[derive(Default)]
pub struct Follow {
    pub focus: Vec3,
    pub auto_pitch: f32,
    pub distance: f32,
    initialized: bool,
}
impl Follow {
    pub fn update(&mut self, hero: &Hero, dt: f32, tuning: &CameraTuning) {
        let dt = dt.clamp(0., 0.1);
        if !self.initialized || self.focus.distance(hero.pos) > 12. {
            self.focus = hero.pos;
            self.initialized = true;
            self.distance = tuning.follow_distance;
        } else {
            // Predict translation so steady travel does not create a trailing camera that
            // points sharply at the current hero position. Both eye and aim use this focus.
            self.focus += hero.velocity * dt;
            self.focus = self
                .focus
                .lerp(hero.pos, 1. - (-tuning.focus_response * dt).exp());
            self.focus =
                hero.pos + (self.focus - hero.pos).clamp_length_max(tuning.max_focus_error);
        }
        let target = if hero.mode == Mode::Dive {
            tuning.dive_pitch_degrees.to_radians()
        } else {
            (-crate::native_swing::pitch(hero.velocity) * 0.12)
                .clamp(
                    -tuning.auto_pitch_max_degrees,
                    tuning.auto_pitch_max_degrees,
                )
                .to_radians()
        };
        let step = (target - self.auto_pitch) * (1. - (-tuning.pitch_response * dt).exp());
        self.auto_pitch += (step).clamp(
            -tuning.pitch_rate_degrees.to_radians() * dt,
            tuning.pitch_rate_degrees.to_radians() * dt,
        );
    }
    pub fn constrain_distance(&mut self, allowed: f32, dt: f32, tuning: &CameraTuning) {
        let allowed = allowed.min(tuning.follow_distance).max(0.7);
        if allowed < self.distance {
            self.distance = allowed;
        } else {
            self.distance = (self.distance + tuning.distance_restore_rate * dt).min(allowed);
        }
    }
}
/// The camera's place and view round `target` (just over his head) along `forward` (level). `look`: the pitch the
/// player asked for (radians; positive from above, negative looking up), `distance`: the boom as collisions allow it,
/// `floor`: the height of what is under the camera. Looking up, the boom swings down under him and comes in toward
/// look_up_distance, but never lower than ground_clearance over the floor; once it is down there the view alone tilts
/// on up, so standing on the street he can still look up at the rooftops. Elsewhere it is the plain orbit, looking at
/// the target.
pub fn pose(target: Vec3, forward: Vec3, look: f32, distance: f32, floor: f32, tuning: &CameraTuning) -> (Vec3, Vec3) {
    let min_y = floor + tuning.ground_clearance;
    let lowest = |d: f32| ((min_y - target.y) / d.max(0.01)).clamp(-1., 1.).asin();
    let full = lowest(distance);
    let mut d = distance;
    if look < full {
        let k = ((full - look) / (full + tuning.look_up_max_degrees.to_radians())).clamp(0., 1.);
        d = distance + (tuning.look_up_distance.min(distance) - distance) * k;
    }
    let orbit = look.max(lowest(d));
    let mut eye = target + (-forward * orbit.cos() + Vec3::Y * orbit.sin()) * d;
    eye.y = eye.y.max(min_y);
    (eye, forward * look.cos() - Vec3::Y * look.sin())
}

/// The horizontal FOV for his speed, approached at the configured rate
pub fn speed_fov(current: f32, speed: f32, dt: f32, tuning: &CameraTuning) -> f32 {
    let t = crate::native_swing::remap(speed, tuning.fov_speed_min, tuning.fov_speed_max);
    let target = tuning.horizontal_fov_degrees + (tuning.fast_fov_degrees - tuning.horizontal_fov_degrees) * t;
    let step = tuning.fov_rate_degrees * dt.clamp(0., 0.1);
    current + (target - current).clamp(-step, step)
}
pub fn follow_yaw(yaw: f32, heading: Vec3, dt: f32, tuning: &CameraTuning) -> f32 {
    let target = (-heading.x).atan2(-heading.z);
    let diff = (target - yaw + std::f32::consts::PI).rem_euclid(std::f32::consts::TAU)
        - std::f32::consts::PI;
    let limit = tuning.yaw_rate_degrees.to_radians() * dt;
    yaw + (diff * (1. - (-tuning.yaw_response * dt).exp())).clamp(-limit, limit)
}
#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn rising_and_falling_do_not_whip_camera_pitch() {
        let t = CameraTuning::default();
        let mut follow = Follow::default();
        let mut h = Hero::default();
        let dt = 1. / 120.;
        for vertical in [40., -40., 40., -40.] {
            h.velocity = Vec3::new(0., vertical, -25.);
            for _ in 0..120 {
                let old = follow.auto_pitch;
                follow.update(&h, dt, &t);
                assert!(follow.auto_pitch.abs() <= t.auto_pitch_max_degrees.to_radians() + 1e-6);
                assert!(
                    (follow.auto_pitch - old).abs()
                        <= t.pitch_rate_degrees.to_radians() * dt + 1e-6
                );
            }
        }
    }
    #[test]
    fn constant_speed_has_no_focus_lag_and_teleport_recovers() {
        let t = CameraTuning::default();
        let mut follow = Follow::default();
        let mut h = Hero::default();
        let dt = 1. / 60.;
        follow.update(&h, dt, &t);
        h.velocity = Vec3::new(0., 20., -40.);
        for _ in 0..120 {
            h.pos += h.velocity * dt;
            follow.update(&h, dt, &t);
            assert!(follow.focus.distance(h.pos) < 0.001);
        }
        h.pos = Vec3::new(80., 2., 30.);
        follow.update(&h, dt, &t);
        assert!(follow.focus.distance(h.pos) < 0.001);
    }
    #[test]
    fn looking_up_from_the_ground_tilts_the_view_without_going_under_it() {
        let t = CameraTuning::default();
        let target = Vec3::new(0., 1.3, 0.);
        let mut last_d = f32::INFINITY;
        for look_degrees in [0f32, -10., -20., -40., -60., -72.] {
            let look = look_degrees.to_radians();
            let (eye, view) = pose(target, Vec3::NEG_Z, look, 5.5, 0., &t);
            assert!(eye.y >= t.ground_clearance - 1e-4, "{look_degrees}: under the street at {eye:?}");
            // the view is the asked pitch: up to 72 degrees above the horizon
            assert!((view.y - (-look).sin()).abs() < 1e-5 && (view.length() - 1.).abs() < 1e-5);
            let d = eye.distance(target);
            assert!(d <= last_d + 1e-4 && d >= t.look_up_distance - 1e-3, "{look_degrees}: {d}");
            assert!(eye.z > 0., "behind him");
            last_d = d;
        }
    }
    #[test]
    fn in_the_air_the_camera_orbits_and_looks_at_him() {
        let t = CameraTuning::default();
        let target = Vec3::new(0., 50., 0.);
        for look_degrees in [30f32, 0., -40., -72.] {
            let look = look_degrees.to_radians();
            let (eye, view) = pose(target, Vec3::NEG_Z, look, 5.5, 0., &t);
            assert!((eye.distance(target) - 5.5).abs() < 1e-4);
            assert!(((target - eye).normalize() - view).length() < 1e-4, "{look_degrees}");
        }
    }
    #[test]
    fn automatic_turning_and_collision_recovery_are_rate_limited() {
        let t = CameraTuning::default();
        let dt = 1. / 60.;
        let yaw = follow_yaw(0., Vec3::X, dt, &t);
        assert!(yaw.abs() <= t.yaw_rate_degrees.to_radians() * dt + 1e-6);
        let mut follow = Follow {
            distance: 6.,
            ..default()
        };
        follow.constrain_distance(1., dt, &t);
        assert_eq!(follow.distance, 1.);
        follow.constrain_distance(6., dt, &t);
        assert!(follow.distance <= 1. + t.distance_restore_rate * dt + 1e-6);
    }
}
