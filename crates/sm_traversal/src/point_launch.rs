//! Hero::HeroStateZipToPointLaunchLocal (Spider-Man.exe 4.0630, vtable exe+38d5dd0): how a zip to a point ends in a
//! point launch. The state's frame (exe+b1d640), its transition check (exe+b19fb0) and the checks ahead of the launch
//! (exe+b1d250, exe+b1be00):
//!   - the press: the jump button (buffered 0.1 s, exe+909320) starts a clock (+0x250) that runs until the launch;
//!   - the direction (at the zip's end): the stick's way when within MaxExitAngle (35 degrees) of the zip's; the zip's
//!     turned MaxExitAngle toward the stick up to 120 degrees off; pulled back further, the zip's, with the stick's
//!     amount negative (the "back" exit);
//!   - the launch: speed, height and time to the top from PointLaunchConfig's exit data (zero, toward full by the
//!     stick's amount, or toward back), plus their bonuses scaled by the boost: 1 - remap(clock, BoostWindowMin,
//!     BoostWindowMax), at least BoostMinApply (the Point Launch Boost skill: assumed owned). The vertical speed and
//!     the gravity reach that height in that time; GravityFall after the top. Into HeroStateJump, kind 0x2a.
//!   - clearing what is ahead: casts from the point along the launch at 2 to 9 m up, under the ceiling, find a wall in
//!     the way; the launch then rises enough to clear its top by 1.25 m (slower if need be), or, with no top in reach,
//!     goes lower and slower so it doesn't hit it.
//!
//! The zip itself (its animation's root motion warped onto the point by the mover) and the perch are the host's.
use crate::air::AirEntry;
use crate::config::{PointLaunchConfig, PointLaunchExitData};
use crate::math::*;

/// The jump press the state reads is buffered this long (exe+909320's window in exe+b1d640)
pub const PRESS_BUFFER: f32 = 0.1;

/// Which exit data a launch reads (exe+b19fb0)
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Exit {
    /// zero, toward full or back by the stick
    Point,
    /// +0x1df: a launch from one perch to the next
    PerchToPerch,
    /// +0x26d: over a low obstacle (no boost, no clearing)
    AutoVault,
}

/// exe+b1d640 at the end of the zip: the launch's direction (+0x1fc) and the stick's signed amount (+0x208).
/// `zip`: the zip's flat direction (+0x1f0); `prev`: the direction kept from the frame before (the zip's, on the first);
/// `stick`: the stick's flat direction in the world and its amount (exe+b7e920).
pub fn exit_direction(cfg: &PointLaunchConfig, zip: V3, prev: V3, stick: V3, amount: f32) -> (V3, f32) {
    if amount <= 0.05 {
        return (prev, amount);
    }
    // the angle from the zip's way to the stick's, about up (positive: to his left)
    let (side, _, fwd) = basis(zip, V3::UP);
    let a = atan2(side.dot(stick), fwd.dot(stick)) * RAD;
    if a.abs() < cfg.max_exit_angle {
        (stick, amount)
    } else if a.abs() < 120. {
        let s = if a < 0. { -DEG } else { DEG };
        (rotate(zip, V3::UP, cfg.max_exit_angle * s), amount)
    } else {
        (prev, -amount)
    }
}

/// exe+b19fb0: the boost for a press `clock` seconds before the launch
pub fn boost(cfg: &PointLaunchConfig, clock: f32) -> f32 {
    (1. - unlerp(clock, cfg.boost_window_min, cfg.boost_window_max)).max(cfg.boost_min_apply)
}

/// What exe+b1d250's casts found ahead of the point. They start from the point at 2 to 9 m up and go 16 m along the
/// launch's direction (0.25 m spheres), below the ceiling a cast straight up finds (0.3 m sphere, to 21 m).
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct Probes {
    /// +0x164..: the flat distance to what blocks each height in turn from 2 m up (1e30 past the last)
    pub blocked: [f32; 8],
    /// +0x184: the nearest of them
    pub nearest: f32,
    /// +0x188: 1e30 when nothing blocks at 2 m; 0 when every height under the ceiling is blocked; else the first clear
    /// height above the blocked ones
    pub clear: f32,
}

impl Probes {
    pub const CLEAR: Probes = Probes { blocked: [1e30; 8], nearest: 1e30, clear: 1e30 };

    /// Heights of the casts above the point
    pub fn height(k: usize) -> f32 {
        2. + k as f32
    }

    /// exe+b1d250's reading: `ceiling`, the height above the point of what the cast up hit; `hit(k)`, the flat
    /// distance from the point to what the cast at `height(k)` hit
    pub fn read(ceiling: Option<f32>, mut hit: impl FnMut(usize) -> Option<f32>) -> Probes {
        let mut p = Probes::CLEAR;
        let ceiling = ceiling.unwrap_or(1e30);
        for k in 0..8 {
            if Self::height(k) > ceiling {
                break;
            }
            match hit(k) {
                None => {
                    if p.clear == 0. {
                        p.clear = Self::height(k);
                    }
                    break;
                }
                Some(d) => {
                    p.blocked[k] = d;
                    p.nearest = p.nearest.min(d);
                    p.clear = 0.;
                }
            }
        }
        p
    }
}

/// A launch: what HeroStateJump is asked for
#[derive(Clone, Copy, Debug)]
pub struct Launch {
    /// the launch velocity (the horizontal part, and the vertical speed)
    pub velocity: V3,
    /// gravity until the top, and after it (GravityFall)
    pub gravity: f32,
    pub gravity_fall: f32,
    /// the boost (0 without a timed press)
    pub boost: f32,
    /// +0x264: 2 when the boost reached BoostMaxFXPerc (the full effect), 1 with a press, 0 without
    pub fx: u32,
    /// the launch had to go lower (its animation switches from 0xd1f08899 to 0xf5f636ff)
    pub lowered: bool,
}

impl Launch {
    pub fn entry(&self) -> AirEntry {
        AirEntry::point_launch(self.velocity, self.gravity, self.gravity_fall)
    }
}

/// exe+b19fb0: the launch in direction `dir` (flat) with the stick's signed `amount`, `press` the clock since the jump
/// press (None: launched without one), `probes` what is ahead of the point
pub fn launch(cfg: &PointLaunchConfig, exit: Exit, dir: V3, amount: f32, press: Option<f32>, probes: &Probes) -> Launch {
    let (a, b, f): (&PointLaunchExitData, &PointLaunchExitData, f32) = match exit {
        Exit::PerchToPerch => (&cfg.perch_to_perch_point_launch, &cfg.perch_to_perch_point_launch, amount),
        Exit::AutoVault => (&cfg.auto_vault, &cfg.auto_vault, amount),
        Exit::Point if amount < 0. => (&cfg.exit_data_zero, &cfg.exit_data_back, amount.abs()),
        Exit::Point => (&cfg.exit_data_zero, &cfg.exit_data_full, amount),
    };
    let l = |x: f32, y: f32| (y - x) * f + x;
    let mut speed = l(a.launch_speed, b.launch_speed);
    let mut height = l(a.jump_height, b.jump_height);
    let mut time = l(a.time_to_peak, b.time_to_peak);
    let (mut bst, mut fx) = (0., 0);
    if let (Some(clock), false) = (press, exit == Exit::AutoVault) {
        bst = boost(cfg, clock);
        speed += l(a.launch_speed_bonus, b.launch_speed_bonus) * bst;
        time += l(a.time_to_peak_bonus, b.time_to_peak_bonus) * bst;
        fx = if cfg.boost_max_fx_perc <= bst { 2 } else { 1 };
        height += l(a.jump_height_bonus, b.jump_height_bonus) * bst;
    }
    let vy = (height + height) * (1. / time);
    let mut gravity = (1. / time) * vy;
    let mut v = scaled(dir, speed);
    v.y = vy;
    let mut lowered = false;
    if exit != Exit::AutoVault {
        clear_ahead(probes, &mut v, &mut gravity, &mut lowered);
    }
    Launch { velocity: v, gravity, gravity_fall: cfg.gravity_fall, boost: bst, fx, lowered }
}

/// exe+b1be00: the launch against what is ahead (the launch's gravity changes only when it has to go lower)
fn clear_ahead(p: &Probes, v: &mut V3, g: &mut f32, lowered: &mut bool) {
    if p.clear == 0. {
        // a wall with no top in reach: arrive at it no sooner than 0.9 of the way to the top, lower if it is near
        let vy = v.y;
        let mut t = vy / *g;
        let reach = p.nearest / v.flat_len();
        if reach < t * 0.6 && !*lowered {
            let h = (vy * t - t * t * *g * 0.5) * 0.925;
            t *= 0.85;
            *lowered = true;
            let vy = (h + h) * (1. / t);
            v.y = vy;
            *g = (1. / t) * vy;
        }
        let s = ((1.111111 / t) * reach).min(1.);
        v.z *= s;
        v.x *= s;
        return;
    }
    // a wall with a top: rise to clear it by 1.25 m, slower if it is close
    for &d in p.blocked.iter() {
        if d == 1e30 {
            return;
        }
        let vy = v.y;
        let peak = vy / *g;
        let speed = v.flat_len();
        let half = *g * 0.5;
        let need = p.clear + 1.25;
        let t = d / speed;
        if need - 0.1 < vy * t - t * half * t || peak < t {
            return;
        }
        let k = (t / peak).clamp(0., 1.);
        let k = (k * 1.515152).clamp(0., 1.);
        let speed = speed * (k * 0.97 + 0.03);
        let t = d / speed;
        let vy = ((t * half * t + need) / t).max(vy).min(50.);
        let h = V3::new(v.x, 0., v.z).norm();
        *v = V3::new(h.x * speed, vy, h.z * speed);
        if pitch_of(*v) * -RAD > 55. {
            *lowered = true;
        }
    }
}

/// exe+a2f110: v at length `l` (along x when v is zero)
fn scaled(v: V3, l: f32) -> V3 {
    let d = v.dot(v);
    if d >= 1e-15 {
        v * (l / d.sqrt())
    } else {
        V3::new(l, 0., 0.)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::config::Configs;

    fn cfg() -> PointLaunchConfig {
        Configs::embedded().traversal.point_launch_config
    }

    #[test]
    fn the_config_is_the_games() {
        let c = cfg();
        assert_eq!((c.max_exit_angle, c.gravity_fall), (35., 30.));
        assert_eq!((c.boost_window_min, c.boost_window_max, c.boost_min_apply, c.boost_max_fx_perc), (0.2, 0.5, 0., 0.75));
        assert_eq!((c.exit_data_back.launch_speed, c.perch_to_perch_point_launch.jump_height_bonus), (12., 2.));
    }

    #[test]
    fn plain_launch_is_the_zero_exit() {
        let c = cfg();
        let l = launch(&c, Exit::Point, V3::new(0., 0., 1.), 0., None, &Probes::CLEAR);
        // ExitDataZero: 24 m/s on, 6 m up in 0.65 s
        assert!((l.velocity.z - 24.).abs() < 1e-4 && l.velocity.x.abs() < 1e-6);
        assert!((l.velocity.y - 12. / 0.65).abs() < 1e-3);
        assert!((l.gravity - 12. / 0.65 / 0.65).abs() < 1e-2);
        let peak = l.velocity.y * l.velocity.y / (2. * l.gravity);
        assert!((peak - 6.).abs() < 1e-3);
        assert_eq!((l.fx, l.gravity_fall), (0, 30.));
    }

    #[test]
    fn a_late_press_boosts_fully_and_an_early_one_not_at_all() {
        let c = cfg();
        assert_eq!(boost(&c, 0.1), 1.);
        assert_eq!(boost(&c, 0.6), 0.);
        assert!((boost(&c, 0.35) - 0.5).abs() < 1e-5);
        let full = launch(&c, Exit::Point, V3::new(0., 0., 1.), 1., Some(0.05), &Probes::CLEAR);
        // ExitDataFull plus its bonuses: 32 m/s, 9 m in 0.7 s
        assert!((full.velocity.z - 32.).abs() < 1e-4);
        assert!((full.velocity.y - 18. / 0.7).abs() < 1e-3);
        assert_eq!(full.fx, 2);
        let early = launch(&c, Exit::Point, V3::new(0., 0., 1.), 1., Some(0.45), &Probes::CLEAR);
        assert_eq!(early.fx, 1);
        assert!(early.velocity.z < full.velocity.z && early.velocity.z > 26.);
    }

    #[test]
    fn pulling_back_launches_high() {
        let c = cfg();
        let (dir, amount) = exit_direction(&c, V3::new(0., 0., 1.), V3::new(0., 0., 1.), V3::new(0., 0., -1.), 1.);
        assert_eq!((dir, amount), (V3::new(0., 0., 1.), -1.));
        let l = launch(&c, Exit::Point, dir, amount, Some(0.), &Probes::CLEAR);
        // ExitDataBack plus its bonuses: 14 m/s on, 26 m up in 0.9 s
        assert!((l.velocity.z - 14.).abs() < 1e-4);
        assert!((l.velocity.y * l.velocity.y / (2. * l.gravity) - 26.).abs() < 1e-2);
    }

    #[test]
    fn the_stick_turns_the_launch_by_at_most_the_exit_angle() {
        let c = cfg();
        let zip = V3::new(0., 0., 1.);
        let s = V3::new(sin(20. * DEG), 0., cos(20. * DEG));
        assert_eq!(exit_direction(&c, zip, zip, s, 1.).0, s);
        // 90 degrees to his left (+x, the game's side row): turned 35 degrees that way
        let (d, a) = exit_direction(&c, zip, zip, V3::new(1., 0., 0.), 0.8);
        assert!((angle_between(d, zip) * RAD - 35.).abs() < 1e-3 && d.x > 0. && a == 0.8);
        let (d, _) = exit_direction(&c, zip, zip, V3::new(-1., 0., 0.), 0.8);
        assert!(d.x < 0.);
        // no stick: the kept direction
        assert_eq!(exit_direction(&c, zip, s, V3::ZERO, 0.).0, s);
    }

    #[test]
    fn a_wall_ahead_with_a_top_is_cleared() {
        let c = cfg();
        // a wall 6 m ahead, blocking 2 to 5 m up: clear at 6 m
        let p = Probes::read(None, |k| if Probes::height(k) < 6. { Some(6.) } else { None });
        assert_eq!((p.clear, p.nearest), (6., 6.));
        let l = launch(&c, Exit::Point, V3::new(0., 0., 1.), 0., None, &p);
        let (vy, g, s) = (l.velocity.y, l.gravity, l.velocity.flat_len());
        let t = 6. / s;
        assert!(vy * t - 0.5 * g * t * t >= 6. + 1.25 - 0.1 - 1e-3, "over the wall's top");
        assert!(s < 24.);
    }

    #[test]
    fn a_wall_ahead_with_no_top_slows_the_launch() {
        let c = cfg();
        let p = Probes::read(Some(30.), |_| Some(4.));
        assert_eq!(p.clear, 0.);
        let l = launch(&c, Exit::Point, V3::new(0., 0., 1.), 0., None, &p);
        assert!(l.lowered);
        let t = l.velocity.y / l.gravity;
        // he reaches the wall no sooner than 0.9 of the way to the top
        assert!(4. / l.velocity.flat_len() >= 0.9 * t - 1e-4);
        // the cast under a low ceiling isn't read
        let low = Probes::read(Some(2.5), |_| Some(4.));
        assert_eq!(low.blocked[1], 1e30);
    }
}
