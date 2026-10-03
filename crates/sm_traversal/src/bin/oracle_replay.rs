//! oracle_replay <scenario.txt> <record.bin>: runs a tools/native_oracle scenario through the port from its starting
//! conditions alone (sm_traversal::replay, closed loop) and compares his path with the game's run of it.
use sm_traversal::config::Configs;
use sm_traversal::math::{angle_between, V3};
use sm_traversal::oracle::Record;
use sm_traversal::replay::{run, Scenario};

fn main() {
    let args: Vec<String> = std::env::args().collect();
    let sc = Scenario::parse(&std::fs::read_to_string(&args[1]).expect("scenario"));
    let rec = Record::load(std::path::Path::new(&args[2])).expect("record");
    let path = run(&sc, std::sync::Arc::new(Configs::embedded()));
    let (mut worst, mut worst_at) = (0f32, 0);
    let mut mode_mismatch = 0;
    for (f, (p, g)) in path.iter().zip(rec.frames.iter()).enumerate() {
        let gp = V3::from_slice(&g.hero_after[12..15]);
        let gf = V3::from_slice(&g.hero_after[8..11]);
        let e = (p.pos - gp).len();
        if p.mode != g.mode {
            mode_mismatch += 1;
        }
        if e > worst {
            worst = e;
            worst_at = f;
        }
        if f % 30 == 0 || p.mode != g.mode {
            println!(
                "frame {f:3} t {:.2} mode {}/{} pos err {e:.4} m (port {:.2?} game {:.2?}) facing err {:.2} deg",
                f as f32 * sc.dt,
                p.mode,
                g.mode,
                p.pos.to_array(),
                gp.to_array(),
                angle_between(p.fwd.norm(), gf.norm()) * 57.29578
            );
        }
    }
    println!("worst position error {worst:.4} m at frame {worst_at}; {mode_mismatch} frames in a different state");
}
