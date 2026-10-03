//! Charged ground jumps. Motion values are authored; poses use original game clips.
use crate::physics::{Hero, Mode};
use bevy::prelude::*;
use serde::Deserialize;
#[derive(Clone, Deserialize)]
pub struct JumpTuning {
    pub full_charge_seconds: f32,
    pub tap_seconds: f32,
    pub gravity: f32,
    pub normal_up_speed: f32,
    pub high_up_speed: f32,
    pub long_up_speed: f32,
    pub long_forward_speed: f32,
    pub moving_threshold: f32,
    pub charge_pose_seconds: f32,
}
impl Default for JumpTuning {
    fn default() -> Self {
        serde_json::from_str(include_str!("../assets/tuning/sandbox_jump.json")).unwrap()
    }
}
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub enum JumpKind {
    #[default]
    Normal,
    High,
    Long,
}
impl Hero {
    pub fn launch_ground_jump(&mut self, held: f32, wish: Vec3, tuning: &JumpTuning) {
        let ratio = ((held - tuning.tap_seconds)
            / (tuning.full_charge_seconds - tuning.tap_seconds))
            .clamp(0., 1.);
        let moving = wish.length_squared() > 0.1
            || self.velocity.with_y(0.).length() > tuning.moving_threshold;
        self.ground_jump_kind = if ratio <= 0. {
            JumpKind::Normal
        } else if moving {
            JumpKind::Long
        } else {
            JumpKind::High
        };
        let upward = if moving {
            tuning.long_up_speed
        } else {
            tuning.high_up_speed
        };
        self.velocity.y = tuning.normal_up_speed + (upward - tuning.normal_up_speed) * ratio;
        if self.ground_jump_kind == JumpKind::Long {
            let forward = if wish.length_squared() > 0.1 {
                wish
            } else {
                self.heading
            };
            let speed = self
                .velocity
                .with_y(0.)
                .length()
                .max(tuning.normal_up_speed * 0.5);
            let target = speed.max(tuning.long_forward_speed);
            self.velocity =
                forward * (speed + (target - speed) * ratio) + Vec3::Y * self.velocity.y;
            self.heading = forward;
        }
        self.release_gravity = tuning.gravity;
        self.last_ground_jump = 0.;
        self.last_swing = 999.;
        self.swing_left = false;
        self.boosted_release = false;
        self.mode = Mode::Air;
        self.mode_age = 0.;
        self.jump_buffer = 0.;
        self.coyote = 0.;
        self.cooldown = 0.15;
        self.jump_charge = None;
        self.ground_jump_count += 1;
    }
}
#[cfg(test)]
mod tests {
    use super::*;
    use crate::physics::{DT, FOOT, Intent, Tuning};
    fn grounded() -> Hero {
        Hero {
            pos: Vec3::new(0., FOOT, 0.),
            previous: Vec3::new(0., FOOT, 0.),
            velocity: Vec3::ZERO,
            mode: Mode::Ground,
            ..Hero::default()
        }
    }
    fn charged(held: f32, movement: Vec2) -> Hero {
        let mut hero = grounded();
        let tuning = Tuning::default();
        for frame in 0..(held / DT).ceil() as usize {
            hero.step(
                Intent {
                    jump: frame == 0,
                    jump_held: true,
                    movement,
                    forward: Vec3::NEG_Z,
                    ..default()
                },
                &[],
                &tuning,
                DT,
            );
            assert_eq!(hero.mode, Mode::Ground);
        }
        hero.step(
            Intent {
                movement,
                forward: Vec3::NEG_Z,
                ..default()
            },
            &[],
            &tuning,
            DT,
        );
        hero
    }
    #[test]
    fn tap_retains_normal_jump_and_full_charge_gains_height() {
        let normal = charged(0.08, Vec2::ZERO);
        let high = charged(1.1, Vec2::ZERO);
        assert_eq!(normal.ground_jump_kind, JumpKind::Normal);
        assert_eq!(high.ground_jump_kind, JumpKind::High);
        assert!(high.velocity.y > normal.velocity.y + 12.);
        assert!(high.velocity.with_y(0.).length() < 0.001);
    }
    #[test]
    fn moving_charge_travels_farther_than_standing_charge() {
        let mut high = charged(1.1, Vec2::ZERO);
        let mut long = charged(1.1, Vec2::Y);
        let tuning = Tuning::default();
        assert_eq!(long.ground_jump_kind, JumpKind::Long);
        assert!(long.velocity.z < -25.);
        let mut high_peak = 0.;
        let mut long_peak = 0.;
        for _ in 0..420 {
            high.step(Intent::default(), &[], &tuning, DT);
            long.step(Intent::default(), &[], &tuning, DT);
            high_peak = high.pos.y.max(high_peak);
            long_peak = long.pos.y.max(long_peak);
        }
        assert!(high_peak > 24. && long_peak < 15.);
        assert!(long.pos.z < -45.);
    }
    #[test]
    fn holding_after_an_air_jump_does_not_auto_charge_on_landing() {
        let mut hero = grounded();
        let tuning = Tuning::default();
        hero.step(
            Intent {
                jump: true,
                ..default()
            },
            &[],
            &tuning,
            DT,
        );
        for _ in 0..400 {
            hero.step(
                Intent {
                    jump_held: true,
                    ..default()
                },
                &[],
                &tuning,
                DT,
            );
        }
        assert_eq!(hero.mode, Mode::Ground);
        assert_eq!(hero.ground_jump_count, 1);
        assert!(hero.jump_charge.is_none());
    }
    #[test]
    fn held_swing_does_not_cancel_a_charged_jump_ascent() {
        let mut hero = charged(1.1, Vec2::ZERO);
        let tuning = Tuning::default();
        let arena = crate::physics::Arena::default();
        hero.swing_held = true;
        for _ in 0..60 {
            hero.step(
                Intent {
                    swing: true,
                    forward: Vec3::NEG_Z,
                    ..default()
                },
                &arena.0,
                &tuning,
                DT,
            );
        }
        assert_eq!(hero.mode, Mode::Air);
        assert!(hero.velocity.y > 0. && hero.rope.is_none());
    }
    #[test]
    fn interrupted_charge_cancels_without_a_launch() {
        let mut hero = grounded();
        let tuning = Tuning::default();
        hero.step(
            Intent {
                jump: true,
                jump_held: true,
                ..default()
            },
            &[],
            &tuning,
            DT,
        );
        hero.step(
            Intent {
                cancel_jump_charge: true,
                ..default()
            },
            &[],
            &tuning,
            DT,
        );
        assert!(hero.jump_charge.is_none());
        assert_eq!(hero.mode, Mode::Ground);
        assert_eq!(hero.ground_jump_count, 0);
    }
}
