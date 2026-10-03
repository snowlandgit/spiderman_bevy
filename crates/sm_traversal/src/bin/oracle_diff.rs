//! oracle_diff <record.bin> [frame...]: runs each swing frame of an oracle record through the port from the game's own
//! state, and prints where the port's result differs from the game's.
use sm_traversal::config::Configs;
use sm_traversal::oracle::*;

fn main() {
    let args: Vec<String> = std::env::args().collect();
    let rec = Record::load(std::path::Path::new(&args[1])).expect("record");
    let only: Vec<i32> = args[2..].iter().filter_map(|a| a.parse().ok()).collect();
    let cfg = Configs::embedded();
    let dt = if rec.frames.len() > 1 { rec.frames[1].t - rec.frames[0].t } else { 1. / 60. };
    let mut worst: Vec<(f32, String)> = vec![];
    let mut swing_frames = 0;
    for fr in &rec.frames {
        if fr.mode != 0 || fr.flags & 2 != 0 || (!only.is_empty() && !only.contains(&fr.index)) {
            continue;
        }
        swing_frames += 1;
        let mid = &fr.mid.blobs;
        let post = &fr.post.blobs;
        let mut s = swing_of(&mid[SWING]);
        let mut tr = tracker_of(&mid[TRACKER]);
        let proc_ = processor_of(&post[SWING_PROC]);
        let env = env_of(fr, dt);
        let out = s.update(&cfg, &mut tr, &proc_, &env);
        let dd = (out.displacement - fr.displacement).len();
        let df = (out.facing - fr.facing).len();
        let fields = swing_fields(&s);
        let native = native_fields(&post[SWING], &fields);
        let mut diffs = vec![];
        for ((name, _, port), nat) in fields.iter().zip(native.iter()) {
            let e: f32 = port.iter().zip(nat.iter()).map(|(a, b)| (a - b).abs()).fold(0., f32::max);
            if e > 1e-3 {
                diffs.push(format!("{name} port {port:?} game {nat:?}"));
            }
        }
        if dd > 1e-4 || df > 1e-3 || !diffs.is_empty() || !only.is_empty() {
            println!("frame {} t {:.3}: disp err {:.5} (port {:?} game {:?}) facing err {:.4}", fr.index, fr.t, dd, out.displacement, fr.displacement, df);
            for d in &diffs {
                println!("    {d}");
            }
        }
        worst.push((dd, format!("frame {}", fr.index)));
    }
    worst.sort_by(|a, b| b.0.total_cmp(&a.0));
    println!("{} swing frames; worst displacement errors: {:?}", swing_frames, &worst[..worst.len().min(5)]);

    // entries: the port's entry from the state before it, against the game's state after it
    for (k, fr) in rec.frames.iter().enumerate() {
        if fr.flags & 2 == 0 {
            continue;
        }
        let pre = &fr.pre.blobs;
        let mid = &fr.mid.blobs;
        let mut s = swing_of(&pre[SWING]);
        let mut tr = tracker_of(&mid[TRACKER]);
        let mut proc_ = sm_traversal::swing::SwingProcessor::default();
        let env = env_of(fr, dt);
        let game = swing_of(&mid[SWING]);
        let mut e = sm_traversal::swing::SwingEntry::new(game.anchor, game.attach);
        if tr.forward_action_time < 0.25 {
            e.flags |= 0x100;
        }
        s.enter(&cfg, &mut tr, &mut proc_, &e, &env);
        let fields = swing_fields(&s);
        let native = native_fields(&mid[SWING], &fields);
        println!("entry at frame {} (record {k}):", fr.index);
        for ((name, _, port), nat) in fields.iter().zip(native.iter()) {
            let e: f32 = port.iter().zip(nat.iter()).map(|(a, b)| (a - b).abs()).fold(0., f32::max);
            if e > 1e-3 {
                println!("    {name} port {port:?} game {nat:?}");
            }
        }
    }

    // transition checks: from the state before the check
    let mut prev_mode = 3;
    let mut checks = 0;
    for fr in &rec.frames {
        let was = prev_mode;
        prev_mode = fr.mode;
        if was != 0 || fr.flags & 2 != 0 {
            continue;
        }
        let pre = &fr.pre.blobs;
        let mid = &fr.mid.blobs;
        let mut s = swing_of(&pre[SWING]);
        let tr = tracker_of(&mid[TRACKER]);
        let env = env_of(fr, dt);
        let r = s.check(&cfg, &tr, &env);
        let game_released = fr.flags & 4 != 0 && fr.request == 0x6dfa880;
        checks += 1;
        if r.is_some() != game_released {
            println!("check frame {}: port {} game {}", fr.index, r.is_some(), game_released);
        }
        if let (Some(r), true) = (r, game_released) {
            let g = &mid[SWING];
            println!(
                "release at frame {}: vel port {:?} game {:?} | gravity port {} game {} | pitch port {} game {} | jumped port {} game {} | anim {} {} game {} {}",
                fr.index, r.velocity, v3(g, 0x540), r.gravity, f(g, 0x53c), r.pitch, f(g, 0x534), r.jumped, g[0x538],
                r.anim_rate, r.anim_blend, f(g, 0x528), f(g, 0x52c)
            );
        }
    }
    println!("{checks} checks compared");

    // the tracker's own update
    let mut tracker_bad = 0;
    let mut last_mode = 3;
    for fr in &rec.frames {
        let was = last_mode;
        last_mode = fr.mode;
        let mut t = tracker_of(&fr.pre.blobs[TRACKER]);
        let mover = sm_traversal::tracker::MoverView { velocity: fr.vel_before, airborne: true, height_above_ground: 50. };
        t.update(&cfg, mover, dt);
        // the game's countdown (exe+862d10) isn't run by the oracle
        t.cooldowns = tracker_of(&fr.pre.blobs[TRACKER]).cooldowns;
        // a new swing from the fall: the fall's exit
        if fr.flags & 2 != 0 && was == 2 {
            sm_traversal::air::AirLocal::new(true).exit(&mut t);
        }
        // a release: the swing's exit (exe+aba8a0) leaves momentum and the speed blend on the tracker
        if fr.flags & 4 != 0 && fr.request == 0x6dfa880 {
            let sw = &fr.mid.blobs[SWING];
            swing_of(sw).exit(&cfg, &mut t, &env_of(fr, dt), sw[0x538] != 0);
        }
        let g = tracker_of(&fr.mid.blobs[TRACKER]);
        let pairs = [
            ("ring_next", t.ring_next as f32, g.ring_next as f32),
            ("release_cooldown", t.cooldowns[2], g.cooldowns[2]),
            ("momentum", t.momentum, g.momentum),
            ("momentum_frac", t.momentum_frac, g.momentum_frac),
            ("terminal_floor", t.terminal_floor, g.terminal_floor),
            ("gravity_scale", t.gravity_scale, g.gravity_scale),
            ("pivot0", t.pivot_factor[0], g.pivot_factor[0]),
            ("pivot1", t.pivot_factor[1], g.pivot_factor[1]),
            ("turn_scale", t.turn_speed_scale, g.turn_speed_scale),
            ("speed_blend", t.speed_blend, g.speed_blend),
            ("terminal", t.terminal, g.terminal),
            ("fall_gravity", t.fall_gravity, g.fall_gravity),
            ("boost_target", t.params.motion.speed_params.speed_boost_target, g.params.motion.speed_params.speed_boost_target),
            ("ideal_angle", t.params.search.ideal_angle_forward, g.params.search.ideal_angle_forward),
            ("rise_low_max", t.params.motion.gravity_params.rise_gravity_low_max, g.params.motion.gravity_params.rise_gravity_low_max),
            ("jump_boost_mid", t.params.release.params_middle.jump_boost, g.params.release.params_middle.jump_boost),
            ("grav_jump_mid", t.params.release.release_gravity_data.gravity_jump_mid, g.params.release.release_gravity_data.gravity_jump_mid),
        ];
        let bad: Vec<_> = pairs.iter().filter(|(_, a, b)| (a - b).abs() > 1e-4).collect();
        if !bad.is_empty() {
            tracker_bad += 1;
            if tracker_bad <= 5 {
                println!("tracker frame {}: {:?}", fr.index, bad);
            }
        }
    }
    println!("tracker: {tracker_bad} of {} frames differ", rec.frames.len());

    air(&rec, &cfg, dt, &only);
}

/// The swing jump and the fall: entries, the jump's hand-over to the fall, every frame's update
fn air(rec: &Record, cfg: &Configs, dt: f32, only: &[i32]) {
    use sm_traversal::air::{AirEntry, AirInput, AirShared};
    use sm_traversal::swing::SwingRelease;
    const JUMP_REQ: u64 = 0x6dfa880;
    const FALL_REQ: u64 = 0x6ded020;
    let mut clock = 0f32;
    let mut prev_mode = 3;
    let (mut frames, mut bad, mut worst) = (0, 0, (0f32, 0));
    let mut checks = 0;
    for fr in &rec.frames {
        let was = prev_mode;
        prev_mode = fr.mode;
        let env = env_of(fr, dt);
        let pre = &fr.pre.blobs;
        let mid = &fr.mid.blobs;
        let post = &fr.post.blobs;
        // the swing jump's entry
        if fr.flags & 4 != 0 && fr.request == JUMP_REQ {
            let sw = &mid[SWING];
            let r = SwingRelease { velocity: v3(sw, 0x540), gravity: f(sw, 0x53c), jumped: sw[0x538] != 0, ..Default::default() };
            let tr = tracker_of(&mid[TRACKER]);
            let e = AirEntry::swing_jump(&r, &tr);
            let game = air_entry_of(&fr.request_data);
            for d in differing(&air_entry_fields(&e, &game), 1e-4) {
                println!("swing jump data at frame {}: {d}", fr.index);
            }
            let mut a = air_of(&pre[JUMP], false);
            let mut sh = AirShared { clock, ..Default::default() };
            a.enter(&game, &tr, &env, &mut sh);
            clock = sh.clock;
            let diffs = differing(&air_fields(&a, &air_of(&mid[JUMP], false)), 1e-4);
            println!("swing jump entry at frame {}: {} fields differ", fr.index, diffs.len());
            for d in diffs {
                println!("    {d}");
            }
        }
        // a launch, or a fall, entered directly (the scenario's `enter`): the state from the game's own data
        if fr.flags & 8 != 0 {
            let fall = fr.mode == 2;
            let blob = if fall { FALL } else { JUMP };
            let game = air_entry_of(&fr.request_data);
            let mut a = air_of(&pre[blob], fall);
            let tr = tracker_of(&mid[TRACKER]);
            let mut sh = AirShared { clock, ..Default::default() };
            a.enter(&game, &tr, &env, &mut sh);
            clock = sh.clock;
            let diffs = differing(&air_fields(&a, &air_of(&mid[blob], fall)), 1e-4);
            println!("{} entry (kind {:#x}) at frame {}: {} fields differ", if fall { "fall" } else { "jump" }, game.kind, fr.index, diffs.len());
            for d in diffs {
                println!("    {d}");
            }
        }
        // the swing jump's check, and the fall's entry
        if was == 1 && fr.mode != 0 {
            let a = air_of(&pre[JUMP], false);
            let mover = &pre[MOVER];
            let inp = AirInput { air_time: f(mover, 0x6b4), height: f(mover, 0x6b8), ..Default::default() };
            let r = a.check(cfg, &env, &inp);
            let game = fr.flags & 4 != 0 && fr.request == FALL_REQ;
            checks += 1;
            if r.is_some() != game {
                println!("jump check frame {}: port {} game {}", fr.index, r.is_some(), game);
            }
            if let (Some(e), true) = (r, game) {
                let g = air_entry_of(&fr.request_data);
                for d in differing(&air_entry_fields(&e, &g), 1e-4) {
                    println!("fall data at frame {}: {d}", fr.index);
                }
                let mut fa = air_of(&pre[FALL], true);
                let tr = tracker_of(&mid[TRACKER]);
                let mut sh = AirShared { clock, facing_blend: f(&pre[JUMP], 0x2fc), ..Default::default() };
                fa.enter(&g, &tr, &env, &mut sh);
                let diffs = differing(&air_fields(&fa, &air_of(&mid[FALL], true)), 1e-4);
                println!("fall entry at frame {}: {} fields differ", fr.index, diffs.len());
                for d in diffs {
                    println!("    {d}");
                }
            }
        }
        if fr.mode != 1 && fr.mode != 2 {
            continue;
        }
        // the frame's update, from the game's state
        let (blob, fall) = if fr.mode == 1 { (JUMP, false) } else { (FALL, true) };
        let mut a = air_of(&mid[blob], fall);
        let mut tr = tracker_of(&mid[TRACKER]);
        let mut sh = AirShared { clock, facing_blend: f(&mid[JUMP], 0x2fc), ..Default::default() };
        let inp = AirInput { air_time: f(&mid[MOVER], 0x6b4), height: f(&mid[MOVER], 0x6b8), ..Default::default() };
        let out = a.update(cfg, &mut tr, &env, &inp, &mut sh);
        clock = sh.clock;
        if !only.is_empty() && !only.contains(&fr.index) {
            continue;
        }
        frames += 1;
        let dd = (out.displacement - fr.displacement).len();
        let df = (out.facing - fr.facing).len();
        let mut diffs = differing(&air_fields(&a, &air_of(&post[blob], fall)), 1e-3);
        let gt = tracker_of(&post[TRACKER]);
        if (tr.momentum - gt.momentum).abs() > 1e-4 {
            diffs.push(format!("tracker momentum port {} game {}", tr.momentum, gt.momentum));
        }
        if dd > worst.0 {
            worst = (dd, fr.index);
        }
        if dd > 1e-4 || df > 1e-3 || !diffs.is_empty() || !only.is_empty() {
            bad += 1;
            if bad <= 12 || !only.is_empty() {
                println!(
                    "air frame {} (mode {}) t {:.3}: disp err {:.5} (port {:?} game {:?}) facing err {:.4} (port {:?} game {:?})",
                    fr.index, fr.mode, fr.t, dd, out.displacement, fr.displacement, df, out.facing, fr.facing
                );
                for d in &diffs {
                    println!("    {d}");
                }
            }
        }
    }
    println!("{frames} air frames, {bad} differ; worst displacement error {:.6} at frame {}; {checks} jump checks", worst.0, worst.1);
}
