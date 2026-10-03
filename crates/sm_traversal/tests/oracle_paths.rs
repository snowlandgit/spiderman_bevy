//! The port against the game's own code. tools/native_oracle ran each scenario through Spider-Man.exe's swing, swing
//! jump and fall (tests/fixtures keeps his path from those runs); here the port runs the same scenario closed loop from
//! its starting conditions alone and must stay with the game: within a few centimetres, every state change on the
//! same frame, the same facing.
use sm_traversal::config::Configs;
use sm_traversal::math::{angle_between, V3};
use sm_traversal::replay::{run, Scenario};
use std::sync::Arc;

fn check(scenario: &str, fixture: &str, tolerance: f32) {
    let sc = Scenario::parse(scenario);
    let game: serde_json::Value = serde_json::from_str(fixture).unwrap();
    let modes = game["mode"].as_array().unwrap();
    let pos = game["pos"].as_array().unwrap();
    let fwd = game["fwd"].as_array().unwrap();
    let path = run(&sc, Arc::new(Configs::embedded()));
    assert_eq!(path.len(), modes.len());
    let f = |v: &serde_json::Value, i: usize| v[i].as_f64().unwrap() as f32;
    for (k, p) in path.iter().enumerate() {
        let g = V3::new(f(&pos[k], 0), f(&pos[k], 1), f(&pos[k], 2));
        let e = (p.pos - g).len();
        assert!(e < tolerance, "frame {k}: {e:.4} m from the game (port {:?}, game {:?})", p.pos, g);
        assert_eq!(p.mode as i64, modes[k].as_i64().unwrap(), "frame {k}: in a different state");
        let gf = V3::new(f(&fwd[k], 0), 0., f(&fwd[k], 1)).norm();
        let df = angle_between(p.fwd.norm(), gf).to_degrees();
        assert!(df < 0.5, "frame {k}: facing {df:.3} degrees off");
    }
}

macro_rules! scenario {
    ($name:ident, $tol:expr) => {
        #[test]
        fn $name() {
            check(
                include_str!(concat!("../../../tools/native_oracle/scenarios/", stringify!($name), ".txt")),
                include_str!(concat!("fixtures/", stringify!($name), ".json")),
                $tol,
            );
        }
    };
}

// a jump release, the swing jump, the fall
scenario!(basic_jump, 0.02);
// steering left through the swing and the air
scenario!(turn_left, 0.02);
// the swing button let go past the bottom: a plain release
scenario!(r2_release, 0.05);
// held to the top: the swing lets go by itself
scenario!(hold_auto, 0.03);
// steering in the air: across, back against the travel, partly, none
scenario!(air_steer, 0.02);
// a second swing from the fall, a second release
scenario!(chain, 0.03);
