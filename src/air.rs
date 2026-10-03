//! Authored airborne steering: rotate carried momentum without changing vertical speed.
use crate::native_swing::{mix, remap};
use bevy::prelude::*;
use serde::Deserialize;

#[derive(Clone, Deserialize)]
pub struct AirTuning {
    pub fall_gravity: f32,
    pub dive_gravity: f32,
    pub turn_rate_slow: f32,
    pub turn_rate_fast: f32,
    pub turn_speed_slow: f32,
    pub turn_speed_fast: f32,
    pub acceleration: f32,
    pub speed_target: f32,
}
impl Default for AirTuning {
    fn default() -> Self {
        serde_json::from_str(include_str!("../assets/tuning/sandbox_air.json")).unwrap()
    }
}
impl AirTuning {
    pub fn steer(&self, velocity: Vec3, wish: Vec3, amount: f32, dt: f32) -> Vec3 {
        let desired = wish.with_y(0.).normalize_or_zero();
        let amount = amount.clamp(0., 1.);
        if desired.length_squared() < 0.1 || amount <= 0. {
            return velocity;
        }
        let horizontal = velocity.with_y(0.);
        let speed = horizontal.length();
        let direction = if speed > 0.01 {
            let yaw = horizontal.x.atan2(horizontal.z);
            let target = desired.x.atan2(desired.z);
            let difference = (target - yaw + std::f32::consts::PI)
                .rem_euclid(std::f32::consts::TAU)
                - std::f32::consts::PI;
            let rate = mix(
                self.turn_rate_slow,
                self.turn_rate_fast,
                remap(speed, self.turn_speed_slow, self.turn_speed_fast),
            );
            let limit = rate.to_radians() * amount * dt;
            let yaw = yaw + difference.clamp(-limit, limit);
            Vec3::new(yaw.sin(), 0., yaw.cos())
        } else {
            desired
        };
        // Acceleration fills low speed; steering remains effective above the target.
        let gain = (self.speed_target - speed)
            .max(0.)
            .min(self.acceleration * amount * dt);
        direction * (speed + gain) + Vec3::Y * velocity.y
    }
}
