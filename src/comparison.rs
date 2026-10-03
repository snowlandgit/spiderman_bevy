//! Windowless comparison against the controller delivered before the feel revision.
#[allow(dead_code)]
#[path = "../research/previous_physics.rs"]
mod previous;
use crate::physics;
use bevy::prelude::*;
use serde_json::{Value, json};
const DT: f32 = 1. / 120.;
fn intent(frame: u32, scenario: &str) -> physics::Intent {
    physics::Intent {
        swing: scenario == "held" || scenario == "dive_entry" || frame < 120,
        jump: scenario == "jump_release" && frame == 120,
        movement: Vec2::Y,
        forward: Vec3::NEG_Z,
        right: Vec3::X,
        ..default()
    }
}
fn current(scenario: &str) -> Value {
    let a = physics::Arena::default();
    let t = physics::Tuning::default();
    let mut h = physics::Hero::default();
    if scenario == "dive_entry" {
        h.pos.y = 45.;
        h.velocity = Vec3::new(0., -42., -20.);
    }
    let mut trace = Vec::new();
    let mut max_y = h.pos.y;
    let mut max_x = 0f32;
    let mut peak_h = 0f32;
    let mut release = Value::Null;
    let mut first_velocity = Vec3::ZERO;
    let mut first_arc_minimum = h.pos.y;
    let mut first_trough_time = None;
    for frame in 0..1600 {
        let before = h.velocity;
        h.step(intent(frame, scenario), &a.0, &t, DT);
        if frame == 0 {
            first_velocity = h.velocity;
        }
        if h.swing_count == 1 && h.rope.is_some() {
            first_arc_minimum = first_arc_minimum.min(h.pos.y);
            if h.rope.is_some_and(|r| r.crossed_trough) && first_trough_time.is_none() {
                first_trough_time = Some((frame + 1) as f32 * DT);
            }
        }
        max_y = max_y.max(h.pos.y);
        max_x = max_x.max(h.pos.x.abs());
        peak_h = peak_h.max(h.velocity.with_y(0.).length());
        if frame == 120 && matches!(scenario, "normal_release" | "jump_release") {
            release = json!({"before":before.to_array(),"after":h.velocity.to_array(),"delta_speed":h.velocity.length()-before.length(),"pitch":h.release_angle,"gravity":h.release_gravity});
        }
        if frame % 12 == 0 {
            trace.push(json!({"time":frame as f32*DT,"position":h.pos.to_array(),"velocity":h.velocity.to_array(),"mode":h.mode.label(),"phase":h.swing_phase,"momentum":h.momentum,"pivot":h.rope.map(|r|r.pivot.to_array()),"anchor":h.rope.map(|r|r.anchor.to_array())}));
        }
    }
    json!({"swings":h.swing_count,"position":h.pos.to_array(),"peak_speed":h.peak_speed,"peak_horizontal":peak_h,"max_height":max_y,"max_lateral":max_x,"release":release,"max_rope_error":h.max_rope_error,"entry_metrics":{"first_tick_velocity":first_velocity.to_array(),"first_arc_minimum_height":first_arc_minimum,"first_trough_time":first_trough_time},"trace":trace})
}
fn before(scenario: &str) -> Value {
    let a = previous::Arena::default();
    let t = previous::Tuning::default();
    let mut h = previous::Hero::default();
    if scenario == "dive_entry" {
        h.pos.y = 45.;
        h.velocity = Vec3::new(0., -42., -20.);
    }
    let mut trace = Vec::new();
    let mut max_y = h.pos.y;
    let mut max_x = 0f32;
    let mut peak_h = 0f32;
    let mut release = Value::Null;
    for frame in 0..1600 {
        let i = intent(frame, scenario);
        let before = h.velocity;
        h.step(
            previous::Intent {
                swing: i.swing,
                jump: i.jump,
                movement: i.movement,
                forward: i.forward,
                right: i.right,
                ..default()
            },
            &a.0,
            &t,
            DT,
        );
        max_y = max_y.max(h.pos.y);
        max_x = max_x.max(h.pos.x.abs());
        peak_h = peak_h.max(h.velocity.with_y(0.).length());
        if frame == 120 && matches!(scenario, "normal_release" | "jump_release") {
            release = json!({"before":before.to_array(),"after":h.velocity.to_array(),"delta_speed":h.velocity.length()-before.length()});
        }
        if frame % 12 == 0 {
            trace.push(json!({"time":frame as f32*DT,"position":h.pos.to_array(),"velocity":h.velocity.to_array(),"mode":h.mode.label()}));
        }
    }
    json!({"swings":h.swing_count,"position":h.pos.to_array(),"peak_speed":h.peak_speed,"peak_horizontal":peak_h,"max_height":max_y,"max_lateral":max_x,"release":release,"trace":trace})
}
pub fn write_report() {
    let mut scenarios = serde_json::Map::new();
    for name in ["held", "normal_release", "jump_release", "dive_entry"] {
        let old = before(name);
        let revised = current(name);
        println!(
            "{name}: swings {} -> {}, lateral {:.2} -> {:.2} m, peak speed {:.2} -> {:.2} m/s",
            old["swings"],
            revised["swings"],
            old["max_lateral"].as_f64().unwrap(),
            revised["max_lateral"].as_f64().unwrap(),
            old["peak_speed"].as_f64().unwrap(),
            revised["peak_speed"].as_f64().unwrap()
        );
        scenarios.insert(name.into(), json!({"previous":old,"revised":revised}));
    }
    let report = json!({"dt":DT,"steps":1600,"original_game_trajectory_measured":false,"scenarios":scenarios});
    let output = std::path::Path::new("research");
    std::fs::create_dir_all(&output).unwrap();
    if let Err(error) = std::fs::write(
        output.join("controller_comparison.json"),
        serde_json::to_string_pretty(&report).unwrap(),
    ) {
        eprintln!("Could not save comparison report: {error}");
        std::process::exit(1);
    }
}
