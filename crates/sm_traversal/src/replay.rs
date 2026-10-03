//! tools/native_oracle's scenarios run through the port, closed loop (sim::Traversal from the starting conditions
//! alone), the way the oracle runs them through the game's code: the same inputs, the same stand-in camera and the
//! same scripted swings. `oracle_replay` compares a run with the game's record; the crate's tests compare it with the
//! game's paths kept in tests/fixtures.
use crate::config::Configs;
use crate::math::{atan2, cos, sin, wrap_pi, Rows, V3};
use crate::sim::{Mode, StepInput, Traversal};
use crate::swing::{FrameInput, SwingEntry};
use std::sync::Arc;

pub struct Key {
    pub t: f32,
    pub x: f32,
    pub y: f32,
}

/// A scenario file (the oracle's format: see tools/native_oracle/oracle.cpp)
pub struct Scenario {
    pub dt: f32,
    pub frames: usize,
    pub momentum: f32,
    pub pos: V3,
    pub vel: V3,
    pub yaw: f32,
    /// (time, anchor, attach)
    pub swings: Vec<(f32, V3, V3)>,
    pub sticks: Vec<Key>,
    pub r2: Vec<Key>,
    pub jumps: Vec<f32>,
    pub cam_follow: bool,
    pub cam_yaw: f32,
    pub cam_pitch: f32,
    pub cam_rate: f32,
    pub drift: bool,
}

impl Scenario {
    pub fn parse(text: &str) -> Self {
        let mut s = Scenario {
            dt: 1. / 60.,
            frames: 300,
            momentum: 0.,
            pos: V3::new(0., 40., 0.),
            vel: V3::new(0., 0., 20.),
            yaw: 0.,
            swings: vec![],
            sticks: vec![],
            r2: vec![],
            jumps: vec![],
            cam_follow: true,
            cam_yaw: 0.,
            cam_pitch: -12.,
            cam_rate: 3.,
            drift: true,
        };
        for line in text.lines() {
            let line = line.split('#').next().unwrap();
            let w: Vec<&str> = line.split_whitespace().collect();
            if w.is_empty() {
                continue;
            }
            let n = |i: usize| -> f32 { w[i].parse().unwrap() };
            match w[0] {
                "dt" => s.dt = n(1),
                "frames" => s.frames = n(1) as usize,
                "momentum" => s.momentum = n(1),
                "pos" => s.pos = V3::new(n(1), n(2), n(3)),
                "vel" => s.vel = V3::new(n(1), n(2), n(3)),
                "yaw" => s.yaw = n(1),
                "swing" => s.swings.push((n(1), V3::new(n(2), n(3), n(4)), V3::new(n(5), n(6), n(7)))),
                "stick" => s.sticks.push(Key { t: n(1), x: n(2), y: n(3) }),
                "r2" => s.r2.push(Key { t: n(1), x: n(2), y: 0. }),
                "jump" => s.jumps.push(n(1)),
                "cam" => {
                    s.cam_follow = w[1] != "fixed";
                    if s.cam_follow {
                        s.cam_rate = n(2);
                    } else {
                        s.cam_yaw = n(2);
                    }
                    s.cam_pitch = n(3);
                }
                "drift" => s.drift = n(1) != 0.,
                k => panic!("unknown scenario key {k}"),
            }
        }
        s
    }
}

fn at(keys: &[Key], t: f32) -> Option<&Key> {
    keys.iter().filter(|k| k.t <= t + 1e-6).last()
}

/// The oracle's camera: 5.5 m behind him and 1 m up, at a fixed pitch
fn camera(yaw: f32, pitch_deg: f32, pos: V3) -> Rows {
    let p = pitch_deg * 0.01745329;
    let f = V3::new(sin(yaw) * cos(p), sin(p), cos(yaw) * cos(p));
    let up = V3::new(-sin(yaw) * sin(p), cos(p), -cos(yaw) * sin(p));
    Rows { side: up.cross(f), up, fwd: f, pos: pos - f * 5.5 + V3::new(0., 1., 0.) }
}

/// A frame after the move and the turn: where he is, his forward and the state (0 swing, 1 swing jump, 2 fall, 3 none)
#[derive(Clone, Copy, Debug)]
pub struct Sample {
    pub pos: V3,
    pub fwd: V3,
    pub mode: i32,
}

pub fn run(sc: &Scenario, cfg: Arc<Configs>) -> Vec<Sample> {
    let dt = sc.dt;
    let yaw = sc.yaw * 0.01745329;
    let mut tr = Traversal::new(cfg.clone(), sc.pos, sc.vel, V3::new(sin(yaw), 0., cos(yaw)));
    tr.air_time = -dt;
    tr.tracker.momentum = sc.momentum;
    tr.tracker.update(&cfg, crate::tracker::MoverView { velocity: sc.vel, airborne: true, height_above_ground: 50. }, dt);
    let mut cam_yaw = if sc.cam_follow { atan2(sc.vel.x, sc.vel.z) } else { sc.cam_yaw * 0.01745329 };
    let mut next_swing = 0;
    let mut out = Vec::with_capacity(sc.frames);
    for f in 0..sc.frames {
        let t = f as f32 * dt;
        let stick = at(&sc.sticks, t).map(|k| [k.x, k.y]).unwrap_or([0., 0.]);
        let r2 = at(&sc.r2, t).map(|k| k.x).unwrap_or(1.);
        let jump = sc.jumps.iter().any(|&j| t >= j - 1e-6 && t < j + 0.05);
        if sc.cam_follow {
            let v = tr.mover_vel;
            if v.x * v.x + v.z * v.z > 1. {
                let d = wrap_pi(atan2(v.x, v.z) - cam_yaw);
                cam_yaw = wrap_pi(cam_yaw + d * (1. - (-sc.cam_rate * dt).exp()));
            }
        }
        let mut si = StepInput {
            input: FrameInput { stick, swing_button: r2, jump_pressed: jump, look: 0. },
            cam: camera(cam_yaw, sc.cam_pitch, tr.pos),
            drift: sc.drift,
            height: 50.,
            ..Default::default()
        };
        if next_swing < sc.swings.len() && t >= sc.swings[next_swing].0 - 1e-6 && tr.mode != Mode::Swing {
            let (_, anchor, attach) = sc.swings[next_swing];
            si.swing = Some(SwingEntry::new(anchor, attach));
            next_swing += 1;
        }
        let o = tr.step(&si, dt);
        // before the first swing the oracle moves him by plain gravity
        let disp = if tr.mode == Mode::Off { V3::new(tr.mover_vel.x * dt, tr.mover_vel.y * dt - 13. * dt * dt, tr.mover_vel.z * dt) } else { o.displacement };
        tr.moved(tr.pos + disp, true, dt);
        let mode = match tr.mode {
            Mode::Swing => 0,
            Mode::SwingJump => 1,
            Mode::Fall => 2,
            Mode::Off => 3,
        };
        out.push(Sample { pos: tr.pos, fwd: tr.fwd, mode });
    }
    out
}
