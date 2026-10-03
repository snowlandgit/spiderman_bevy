//! Traversal clip selection using original clip durations and mirrored skin poses.
use crate::physics::{Hero, Mode};
use bevy::prelude::*;
use serde::Deserialize;
use std::collections::HashMap;
#[derive(Deserialize)]
struct Clip {
    name: String,
    duration: f32,
}
#[derive(Resource)]
pub struct ClipTiming {
    durations: HashMap<String, f32>,
    jump: crate::jump::JumpTuning,
    presentation: AnimationTuning,
}
impl Default for ClipTiming {
    fn default() -> Self {
        #[derive(Deserialize)]
        struct Report {
            clips: Vec<Clip>,
        }
        let data: Report =
            serde_json::from_str(include_str!("../assets/character/conversion.json")).unwrap();
        Self {
            durations: data
                .clips
                .into_iter()
                .map(|c| (c.name, c.duration))
                .collect(),
            jump: crate::jump::JumpTuning::default(),
            presentation: AnimationTuning::default(),
        }
    }
}
impl ClipTiming {
    pub fn duration(&self, name: &str) -> f32 {
        *self
            .durations
            .get(name)
            .unwrap_or_else(|| panic!("Missing original animation {name}"))
    }
    pub fn has(&self, name: &str) -> bool {
        self.durations.contains_key(name)
    }
}
pub struct Pose {
    pub clip: String,
    pub seek: Option<f32>,
    pub looping: bool,
    pub speed: f32,
    pub activation: u32,
}
fn ground_jump_clip(hero: &Hero) -> &'static str {
    match hero.ground_jump_kind {
        crate::jump::JumpKind::High => "stand_chargejump_up_spiderman",
        crate::jump::JumpKind::Long => "stand_chargejump_fwd_spiderman",
        crate::jump::JumpKind::Normal if hero.velocity.with_y(0.).length() > 7. => {
            "stand_sprint_high_jump_fwd_spiderman"
        }
        _ => "stand_jump_spiderman",
    }
}
pub fn pose(hero: &Hero, timing: &ClipTiming) -> Pose {
    let speed = hero.velocity.with_y(0.).length();
    let mut seek = None;
    let mut looping = false;
    let mut playback = 1.;
    let name: String = match hero.mode {
        Mode::Swing => {
            let intro = if hero.swing_from_dive {
                "web_swing_intro_fromfastfall_fwd_rh_spiderman"
            } else {
                "web_swing_intro_fromairaggro_fwd_rh_spiderman"
            };
            let intro_time = if hero.swing_from_dive {
                timing.presentation.swing_dive_intro_seconds
            } else {
                timing.presentation.swing_intro_seconds
            };
            if hero.mode_age < intro_time {
                seek = Some(hero.mode_age * timing.duration(intro) / intro_time);
                intro.into()
            } else {
                let clip = "web_swing_fwd_rh_spiderman";
                // Never jump ahead to a later body pose when the attachment completes.
                let elapsed = timing.presentation.swing_main_start_seconds
                    + (hero.mode_age - intro_time) * timing.presentation.swing_playback_rate;
                seek = Some(
                    elapsed.min(
                        (hero.swing_phase * timing.duration(clip))
                            .max(timing.presentation.swing_main_start_seconds),
                    ),
                );
                clip.into()
            }
        }
        Mode::Zip => {
            if let Some(zip) = hero.zip_motion {
                let clip = if zip.from_dive {
                    "web_zip_fwd_fastfall_2h_spiderman"
                } else if zip.from_high_release {
                    "web_zip_fwd_jumpreleasehigh_2h_spiderman"
                } else if zip.from_ground {
                    "web_zip_fwd_2hand_spiderman"
                } else {
                    "web_zip_fwd_2hand_spiderman"
                };
                seek = Some(hero.mode_age);
                clip.into()
            } else {
                let intro = "web_zip_attach_short_fwd_spiderman";
                if hero.mode_age < timing.duration(intro) {
                    seek = Some(hero.mode_age);
                    intro.into()
                } else {
                    seek = Some(
                        (hero.mode_age - timing.duration(intro))
                            .min(timing.duration("web_zip_fwd_2hand_spiderman")),
                    );
                    "web_zip_fwd_2hand_spiderman".into()
                }
            }
        }
        Mode::Air => {
            let release = if hero.boosted_release {
                if hero.release_angle >= 45. {
                    match hero.release_variant % 3 {
                        0 => "web_swing_jump_high_spiderman".into(),
                        1 => "web_swing_jump_high1_spiderman".into(),
                        _ => "web_swing_jump_high2_spiderman".into(),
                    }
                } else {
                    match hero.release_variant % 5 {
                        0 => "web_swing_jump_mid_spiderman".into(),
                        i => format!("web_swing_jump_mid{}_spiderman", i + 1),
                    }
                }
            } else if hero.release_angle >= 45. {
                "web_swing_release_high_spiderman".into()
            } else if hero.release_angle < 7. {
                "web_swing_release_low_spiderman".into()
            } else {
                format!(
                    "web_swing_release_mid{}_spiderman",
                    hero.release_variant % 5 + 1
                )
            };
            if hero.last_swing < timing.duration(&release) {
                seek = Some(hero.last_swing);
                release
            } else if hero.last_ground_jump
                < timing.duration(ground_jump_clip(hero))
                    - if hero.ground_jump_kind == crate::jump::JumpKind::Normal {
                        0.
                    } else {
                        timing.jump.charge_pose_seconds
                    }
            {
                let offset = if hero.ground_jump_kind == crate::jump::JumpKind::Normal {
                    0.
                } else {
                    timing.jump.charge_pose_seconds
                };
                seek = Some(hero.last_ground_jump + offset);
                ground_jump_clip(hero).into()
            } else {
                looping = true;
                "fall_cycle_spiderman".into()
            }
        }
        Mode::Dive => {
            let intro = "air_tofastfall_spiderman";
            if hero.mode_age < timing.duration(intro) {
                seek = Some(hero.mode_age);
                intro.into()
            } else {
                looping = true;
                "fastfall_spiderman".into()
            }
        }
        Mode::Wall => {
            let intro = "wall_run_up_intro_spiderman";
            if hero.mode_age < timing.duration(intro) {
                seek = Some(hero.mode_age);
                intro.into()
            } else {
                looping = true;
                "wall_run_up_spiderman".into()
            }
        }
        Mode::Ground => {
            let landing = "fall_toland_spiderman";
            if let Some(charge) = hero.jump_charge {
                let tuning = &timing.jump;
                seek = Some(charge.min(tuning.charge_pose_seconds));
                if speed > tuning.moving_threshold {
                    "stand_chargejump_fwd_spiderman".into()
                } else {
                    "stand_chargejump_up_spiderman".into()
                }
            } else if hero.mode_age < timing.duration(landing) && hero.airborne_before_landing > 0.3
            {
                seek = Some(hero.mode_age);
                landing.into()
            } else {
                looping = true;
                if speed > 7. {
                    playback = (speed / 10.5).clamp(0.7, 1.5);
                    "stand_sprint_fwd_spiderman".into()
                } else if speed > 0.8 {
                    playback = (speed / 5.).clamp(0.7, 1.5);
                    "stand_jog_fwd_spiderman".into()
                } else {
                    "stand_idle_spiderman".into()
                }
            }
        }
    };
    let mirrored = format!("{name}_mirrored");
    let clip =
        if hero.swing_left && matches!(hero.mode, Mode::Swing | Mode::Air) && timing.has(&mirrored)
        {
            mirrored
        } else {
            name
        };
    Pose {
        clip,
        seek,
        looping,
        speed: playback,
        activation: hero
            .swing_count
            .wrapping_mul(31)
            .wrapping_add(hero.zip_count)
            .wrapping_add(hero.ground_jump_count.wrapping_mul(173)),
    }
}
#[derive(Clone, Deserialize)]
struct AnimationTuning {
    swing_intro_seconds: f32,
    swing_dive_intro_seconds: f32,
    swing_main_start_seconds: f32,
    swing_playback_rate: f32,
    seek_response: f32,
    max_seek_rate: f32,
    swing_blend_seconds: f32,
    release_blend_seconds: f32,
    fall_blend_seconds: f32,
    zip_blend_seconds: f32,
    ground_blend_seconds: f32,
}
impl Default for AnimationTuning {
    fn default() -> Self {
        let v: serde_json::Value =
            serde_json::from_str(include_str!("../assets/tuning/sandbox_presentation.json"))
                .unwrap();
        serde_json::from_value(v["animation"].clone()).unwrap()
    }
}
pub struct Layer {
    pub clip: String,
    pub seek: f32,
    pub weight: f32,
    rate: f32,
    start_weight: f32,
    looping: bool,
}
pub struct Mixer {
    pub current: String,
    pub layers: Vec<Layer>,
    mode: Mode,
    activation: u32,
    blend_age: f32,
    blend_duration: f32,
}
fn smoothstep(x: f32) -> f32 {
    let x = x.clamp(0., 1.);
    x * x * (3. - 2. * x)
}
impl Mixer {
    pub fn new(clip: &str) -> Self {
        Self {
            current: clip.into(),
            layers: vec![Layer {
                clip: clip.into(),
                seek: 0.,
                weight: 1.,
                rate: 1.,
                start_weight: 1.,
                looping: true,
            }],
            mode: Mode::Air,
            activation: 0,
            blend_age: 1.,
            blend_duration: 0.,
        }
    }
    pub fn update(&mut self, pose: &Pose, mode: Mode, timing: &ClipTiming, dt: f32) {
        let dt = dt.clamp(0., 0.1);
        let tuning = &timing.presentation;
        let changed =
            self.current != pose.clip || self.mode != mode || self.activation != pose.activation;
        if changed {
            for layer in &mut self.layers {
                layer.start_weight = layer.weight;
            }
            if !self.layers.iter().any(|layer| layer.clip == pose.clip) {
                self.layers.push(Layer {
                    clip: pose.clip.clone(),
                    seek: pose.seek.unwrap_or(0.),
                    weight: 0.,
                    start_weight: 0.,
                    rate: pose.speed,
                    looping: pose.looping,
                });
            }
            self.blend_duration = match mode {
                Mode::Swing | Mode::Dive | Mode::Wall => tuning.swing_blend_seconds,
                Mode::Zip => tuning.zip_blend_seconds,
                Mode::Ground => tuning.ground_blend_seconds,
                Mode::Air if pose.clip.starts_with("fall_") => tuning.fall_blend_seconds,
                Mode::Air => tuning.release_blend_seconds,
            };
            self.blend_age = 0.;
            self.current = pose.clip.clone();
            self.mode = mode;
            self.activation = pose.activation;
        }
        self.blend_age += dt;
        let blend = if self.blend_duration > 0. {
            smoothstep(self.blend_age / self.blend_duration)
        } else {
            1.
        };
        for layer in &mut self.layers {
            let incoming = layer.clip == self.current;
            let duration = timing.duration(&layer.clip);
            if incoming {
                layer.looping = pose.looping;
                if let Some(target) = pose.seek {
                    let old = layer.seek;
                    let step = (target - old) * (1. - (-tuning.seek_response * dt).exp());
                    layer.seek += step.clamp(-tuning.max_seek_rate * dt, tuning.max_seek_rate * dt);
                    if dt > 0. {
                        layer.rate = (layer.seek - old) / dt;
                    }
                } else {
                    layer.rate = pose.speed;
                    layer.seek += layer.rate * dt;
                }
            } else {
                layer.seek += layer.rate * dt;
            }
            layer.seek = if layer.looping {
                layer.seek.rem_euclid(duration)
            } else {
                layer.seek.clamp(0., (duration - 0.0001).max(0.))
            };
            let target = if incoming { 1. } else { 0. };
            layer.weight = layer.start_weight + (target - layer.start_weight) * blend;
        }
        if blend >= 1. {
            self.layers.retain(|layer| layer.clip == self.current);
        }
    }
    pub fn current_seek(&self) -> f32 {
        self.layers
            .iter()
            .find(|layer| layer.clip == self.current)
            .map(|layer| layer.seek)
            .unwrap_or(0.)
    }
}
#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn main_swing_brings_legs_forward_without_skipping_to_an_advanced_pose() {
        let timing = ClipTiming::default();
        let mut hero = Hero::default();
        hero.mode = Mode::Swing;
        hero.mode_age = 0.3;
        hero.swing_phase = 0.6;
        assert!(pose(&hero, &timing).clip.contains("intro"));
        hero.mode_age = 0.46;
        let entry = pose(&hero, &timing);
        assert_eq!(entry.clip, "web_swing_fwd_rh_spiderman");
        assert!(entry.seek.unwrap() < 0.7);
        hero.mode_age = 0.85;
        let moving = pose(&hero, &timing);
        assert!(moving.seek.unwrap() > 1.5 && moving.seek.unwrap() < 1.7);
        // The old full-arc seek would already be at 2.84 seconds here.
    }
    #[test]
    fn blend_interruption_preserves_weights_and_outgoing_motion() {
        let timing = ClipTiming::default();
        let mut mixer = Mixer::new("fall_cycle_spiderman");
        let mut hero = Hero::default();
        hero.mode = Mode::Swing;
        hero.mode_age = 0.2;
        for _ in 0..12 {
            mixer.update(&pose(&hero, &timing), hero.mode, &timing, 1. / 60.);
            hero.mode_age += 1. / 60.;
        }
        let outgoing = mixer
            .layers
            .iter()
            .find(|l| l.clip.contains("intro"))
            .unwrap()
            .seek;
        hero.mode = Mode::Air;
        hero.last_swing = 0.;
        let old_weights = mixer
            .layers
            .iter()
            .map(|l| (l.clip.clone(), l.weight))
            .collect::<Vec<_>>();
        mixer.update(&pose(&hero, &timing), hero.mode, &timing, 0.0001);
        for (clip, old) in old_weights {
            assert!(
                (mixer.layers.iter().find(|l| l.clip == clip).unwrap().weight - old).abs() < 0.001
            );
        }
        assert!(
            mixer
                .layers
                .iter()
                .find(|l| l.clip.contains("intro"))
                .unwrap()
                .seek
                > outgoing
        );
        for _ in 0..90 {
            mixer.update(&pose(&hero, &timing), hero.mode, &timing, 1. / 60.);
            hero.last_swing += 1. / 60.;
            assert!((mixer.layers.iter().map(|l| l.weight).sum::<f32>() - 1.).abs() < 1e-5);
            assert!(mixer.layers.iter().all(|l| (0.0..=1.0).contains(&l.weight)));
        }
    }
    #[test]
    fn main_clip_sampling_stays_bounded_when_arc_phase_changes_abruptly() {
        let timing = ClipTiming::default();
        let mut mixer = Mixer::new("web_swing_fwd_rh_spiderman");
        let mut hero = Hero::default();
        hero.mode = Mode::Swing;
        hero.mode_age = 2.;
        for phase in [0.01, 0.98, 0.02, 0.99] {
            hero.swing_phase = phase;
            let before = mixer.current_seek();
            mixer.update(&pose(&hero, &timing), hero.mode, &timing, 1. / 60.);
            assert!(
                (mixer.current_seek() - before).abs()
                    <= timing.presentation.max_seek_rate / 60. + 0.00001
            );
        }
    }
    #[test]
    fn charged_ground_and_air_poses_use_original_directional_clips() {
        let timing = ClipTiming::default();
        let mut hero = Hero::default();
        hero.mode = Mode::Ground;
        hero.jump_charge = Some(1.);
        hero.velocity = Vec3::ZERO;
        let charge = pose(&hero, &timing);
        assert_eq!(charge.clip, "stand_chargejump_up_spiderman");
        assert_eq!(charge.seek, Some(timing.jump.charge_pose_seconds));
        hero.mode = Mode::Air;
        hero.jump_charge = None;
        hero.last_ground_jump = 0.4;
        hero.ground_jump_kind = crate::jump::JumpKind::Long;
        let launch = pose(&hero, &timing);
        assert_eq!(launch.clip, "stand_chargejump_fwd_spiderman");
        assert!((launch.seek.unwrap() - (0.4 + timing.jump.charge_pose_seconds)).abs() < 0.001);
        assert!(!launch.looping);
    }
    #[test]
    fn release_clip_finishes_after_the_physics_apex() {
        let timing = ClipTiming::default();
        let mut hero = Hero::default();
        hero.boosted_release = true;
        hero.last_swing = 1.7;
        hero.release_angle = 50.;
        hero.velocity.y = -6.;
        let pose = pose(&hero, &timing);
        assert!(pose.clip.starts_with("web_swing_jump_high"));
        assert_eq!(pose.seek, Some(1.7));
        assert!(!pose.looping);
    }
    #[test]
    fn swing_uses_the_native_traversal_clip_and_matching_hand() {
        let timing = ClipTiming::default();
        let mut hero = Hero::default();
        hero.mode = Mode::Swing;
        hero.mode_age = 1.4;
        hero.swing_phase = 0.6;
        hero.swing_left = true;
        let pose = pose(&hero, &timing);
        assert_eq!(pose.clip, "web_swing_fwd_rh_spiderman_mirrored");
        let expected = timing.presentation.swing_main_start_seconds
            + (1.4 - timing.presentation.swing_intro_seconds)
                * timing.presentation.swing_playback_rate;
        assert!(
            (pose.seek.unwrap()
                - expected.min(0.6 * timing.duration("web_swing_fwd_rh_spiderman")))
            .abs()
                < 1e-5
        );
    }
    #[test]
    fn intros_are_not_looped_or_cut_at_the_old_short_gate() {
        let timing = ClipTiming::default();
        let mut hero = Hero::default();
        hero.mode = Mode::Wall;
        hero.mode_age = 0.6;
        let pose = pose(&hero, &timing);
        assert_eq!(pose.clip, "wall_run_up_intro_spiderman");
        assert!(!pose.looping);
        assert_eq!(pose.seek, Some(0.6));
    }
}
