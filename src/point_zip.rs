//! Zip to a point, the perch and the point launch.
//!
//! - **The point.** The game picks perch points authored on New York's buildings (its HeroPerchTargeting component).
//!   Here they come from the world's geometry (crate::world): any edge of a surface he can stand on that drops away,
//!   on the buildings' boxes and on any imported object's mesh alike. The target is ArkWeb's rule for its own points
//!   (Arkham's grapple ledges): on each ledge the place nearest the camera's aim line, within 67.5 m of him (the game's
//!   ZipToPerchSetup RangeBreak, 45 m, half again at the user's request) and 25 degrees of the aim, the nearest the aim
//!   first. It must have room to
//!   stand 0.35 m in from the edge (less on a narrow top), a drop of 1 m or more past the edge (not a step) and be in
//!   sight. The tips of thin things (poles, antennas) are points too: he perches on the tip itself.
//! - **The zip.** The game moves him by the root motion of WebZip_Attach, warped onto the target by his mover. That
//!   way is in the clip's sync joint (assets/tuning/web_zip_attach_way.json, from the character file): 30 m in
//!   1.33 s, an even 22.5 m/s, rising 3 m on the way. As ArkWeb plays it, the clip starts where the way left is his
//!   distance (so it keeps its speed; a longer zip starts at the clip's start and is scaled), and its offset is turned
//!   and scaled onto his in the forward-up plane. A sphere swept along it stops the zip at anything in the way.
//! - **The launch.** The game's (sm_traversal::point_launch, checked against Spider-Man.exe): A during the zip, or
//!   right on arrival, launches him into the game's jump state; the press's timing sets the boost; the stick steers
//!   the launch within 35 degrees, or pulled back sends him high. Its checks ahead of the point are cast against the
//!   world here.
//! - **The perch.** Without a launch he perches on the point: A jumps off (the game's jump off a perch), the chord
//!   zips on to the next point, the drop button steps off the edge, the stick stands him up on a top wide enough.
use crate::physics::FOOT;
use crate::world::{Ledge, World};
use bevy::prelude::*;
use serde::Deserialize;
use sm_traversal::point_launch::Probes;
use std::sync::OnceLock;

/// Reach and aim: ArkWeb's 25 degrees; the reach is the game's RangeBreak (45 m) half again, as the user asked
pub const RANGE: f32 = 67.5;
pub const MIN_RANGE: f32 = 4.;
/// cos 25 degrees
pub const AIM_COS: f32 = 0.906;
/// After arriving, a jump press within this still launches (the game's check buffers the press 0.2 s, exe+98f870)
pub const ARRIVAL_WINDOW: f32 = 0.2;
/// The sphere swept along the zip
pub const SWEEP_RADIUS: f32 = 0.25;

/// A point to zip to
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct Perch {
    /// on the edge: where the webs hold
    pub hold: Vec3,
    /// where his feet go
    pub feet: Vec3,
    /// level, out over the drop
    pub out: Vec3,
}

/// The point the camera's aim picks (`from`: his middle, `eye`: the camera, `aim`: its forward)
pub fn find(world: &World, from: Vec3, eye: Vec3, aim: Vec3) -> Option<Perch> {
    let aim = aim.normalize_or_zero();
    if aim == Vec3::ZERO {
        return None;
    }
    let mut cands: Vec<(f32, Vec3, Ledge)> = Vec::new();
    world.ledges_near(from, RANGE, |l| {
        let p = l.nearest_to_line(eye, aim);
        let dist = p.distance(from);
        if !(MIN_RANGE..=RANGE).contains(&dist) {
            return;
        }
        let v = p - eye;
        let vl = v.length();
        if vl < 1e-3 {
            return;
        }
        let c = v.dot(aim) / vl;
        if c >= AIM_COS {
            cands.push((1. - c + dist * 0.0005, p, *l));
        }
    });
    cands.sort_by(|a, b| a.0.total_cmp(&b.0));
    // (detailed meshes put many small ledges near the aim that fail their checks)
    cands.iter().take(24).find_map(|&(_, p, l)| check(world, from, p, &l))
}

/// Can he perch at `p` on ledge `l`, and see it from `from`?
fn check(world: &World, from: Vec3, p: Vec3, l: &Ledge) -> Option<Perch> {
    if l.tip {
        // the top of something thin: he perches on the point itself, with nothing over it, in sight
        if world.sphere_cast(p + Vec3::Y * 0.3, Vec3::Y, 0.25, 1.5).is_some() {
            return None;
        }
        let to = p + Vec3::Y * 0.5;
        let d = to - from;
        let len = d.length();
        if len < 1e-3 || world.raycast(from, d / len, len).is_some() {
            return None;
        }
        return Some(Perch { hold: p, feet: p, out: (from - p).with_y(0.).normalize_or(Vec3::X) });
    }
    // room to stand on the top, a little in from the edge (less on a narrow top)
    let spot = p - l.out * crate::world::inset(l);
    let floor = world.floor_below(spot + Vec3::Y * 0.6, 1.2)?;
    if (floor.point.y - p.y).abs() > 0.3 {
        return None;
    }
    let feet = floor.point;
    if world.sphere_cast(feet + Vec3::Y * 0.3, Vec3::Y, 0.25, 1.5).is_some() {
        return None;
    }
    // a drop past the edge, not a step
    if world.floor_below(p + l.out * crate::world::drop_offset(l) + Vec3::Y * 0.05, 1.).is_some() {
        return None;
    }
    // in sight: from his middle to just off the edge and over it
    let to = p + l.out * 0.6 + Vec3::Y * 0.5;
    let d = to - from;
    let len = d.length();
    if len < 1e-3 || world.raycast(from, d / len, len).is_some() {
        return None;
    }
    Some(Perch { hold: p, feet, out: l.out })
}

#[derive(Deserialize)]
struct WayFile {
    times: Vec<f32>,
    way: Vec<[f32; 3]>,
}

/// The zip's way to its target over the clip (the sync joint: x left, y up, z forward)
struct Way {
    times: Vec<f32>,
    way: Vec<Vec3>,
}

fn way() -> &'static Way {
    static WAY: OnceLock<Way> = OnceLock::new();
    WAY.get_or_init(|| {
        let f: WayFile = serde_json::from_str(include_str!("../assets/tuning/web_zip_attach_way.json")).unwrap();
        Way { times: f.times, way: f.way.into_iter().map(Vec3::from_array).collect() }
    })
}

impl Way {
    fn duration(&self) -> f32 {
        *self.times.last().unwrap()
    }
    /// At `n` of the clip (0..1)
    fn at(&self, n: f32) -> Vec3 {
        let t = n.clamp(0., 1.) * self.duration();
        let k = self.times.partition_point(|&x| x <= t).clamp(1, self.times.len() - 1);
        let (t0, t1) = (self.times[k - 1], self.times[k]);
        let u = if t1 > t0 { ((t - t0) / (t1 - t0)).clamp(0., 1.) } else { 0. };
        self.way[k - 1].lerp(self.way[k], u)
    }
}

/// The clip's length
#[cfg(test)]
pub fn clip_duration() -> f32 {
    way().duration()
}

/// A zip to a point under way
#[derive(Clone, Copy, Debug)]
pub struct PointZip {
    pub perch: Perch,
    /// his middle on arrival
    pub target: Vec3,
    /// the zip's frame (level)
    pub fwd: Vec3,
    left: Vec3,
    /// where in the clip it started (0..1) and how long it has run
    t0: f32,
    pub elapsed: f32,
    /// the clip's way onto his: a scale and a turn (cos, sin) in the forward-up plane
    warp: (f32, f32, f32),
    /// the jump press's clock (exe+b1d640's +0x250): from the press to the launch
    pub press: Option<f32>,
    /// the launch's direction and the stick's signed amount, as the end of the zip leaves them (+0x1fc, +0x208)
    pub launch_dir: Vec3,
    pub amount: f32,
}

impl PointZip {
    /// From his middle `from` to `perch` (None when it is too near to zip)
    pub fn start(from: Vec3, perch: Perch) -> Option<Self> {
        let target = perch.feet + Vec3::Y * FOOT;
        let d = target - from;
        let flat = d.with_y(0.).length();
        let dist = d.length();
        if flat < 0.5 || dist < 3. {
            return None;
        }
        let fwd = d.with_y(0.) / flat;
        let left = Vec3::new(fwd.z, 0., -fwd.x);
        let w = way();
        // the clip's start: where its way left is his distance
        let mut t0 = 0.;
        let l0 = w.at(0.).length();
        if l0 > dist {
            let (mut pn, mut pl) = (0., l0);
            for k in 1..=40 {
                let n = k as f32 / 40. * 0.95;
                let l = w.at(n).length();
                if l <= dist {
                    t0 = pn + (n - pn) * ((pl - dist) / (pl - l).max(1e-4));
                    break;
                }
                (pn, pl) = (n, l);
            }
        }
        // the warp: the clip's offset there, turned and scaled onto his
        let j = w.at(t0);
        let (cz, cy) = (j.z, j.y);
        let cl = (cz * cz + cy * cy).sqrt();
        let ol = (flat * flat + d.y * d.y).sqrt();
        let th = d.y.atan2(flat) - cy.atan2(cz);
        let s = if cl > 1e-3 { ol / cl } else { 1. };
        Some(Self {
            perch,
            target,
            fwd,
            left,
            t0,
            elapsed: 0.,
            warp: (s, th.cos(), th.sin()),
            press: None,
            launch_dir: fwd,
            amount: 0.,
        })
    }

    /// How far through the clip (0..1)
    pub fn norm(&self) -> f32 {
        (self.t0 + self.elapsed / way().duration()).min(1.)
    }
    /// The clip's time (for the animation)
    pub fn clip_time(&self) -> f32 {
        self.norm() * way().duration()
    }
    /// Seconds left
    pub fn remaining(&self) -> f32 {
        (1. - self.norm()) * way().duration()
    }
    /// Where his middle is now
    pub fn position(&self) -> Vec3 {
        let j = way().at(self.norm());
        let (s, c, sn) = self.warp;
        let f = (j.z * c - j.y * sn) * s;
        let u = (j.z * sn + j.y * c) * s;
        self.target - (self.fwd * f + self.left * (j.x * s) + Vec3::Y * u)
    }
    pub fn arrived(&self) -> bool {
        self.norm() >= 0.999
    }
}

/// Perched on a point after a zip to it
#[derive(Clone, Copy, Debug)]
pub struct Perched {
    /// the zip that brought him (its point, its direction, the launch it leaves)
    pub zip: PointZip,
    /// seconds since he arrived
    pub age: f32,
}

/// exe+b1d250's casts from the point where his feet are along the launch direction `dir`: up for the ceiling (a 0.3 m
/// sphere from 1 m to 21 m up), and out 16 m at 2 to 9 m up (0.25 m spheres)
pub fn probes(world: &World, feet: Vec3, dir: Vec3) -> Probes {
    let dir = dir.with_y(0.).normalize_or_zero();
    if dir == Vec3::ZERO {
        return Probes::CLEAR;
    }
    let ceiling = world.sphere_cast(feet + Vec3::Y, Vec3::Y, 0.3, 20.).map(|h| h.point.y - feet.y);
    Probes::read(ceiling, |k| {
        let o = feet + Vec3::Y * Probes::height(k);
        world.sphere_cast(o, dir, 0.25, 16.).map(|h| (h.point - feet).with_y(0.).length())
    })
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::physics::Tower;
    use crate::world::tests::box_mesh;

    #[test]
    fn the_way_is_the_clips() {
        let w = way();
        assert!((w.duration() - 1.3333).abs() < 1e-3);
        assert!((w.at(0.).z - 30.).abs() < 1e-3 && w.at(1.).length() < 1e-3);
        // it rises 3 m on the way (the target 3 m below him half way)
        assert!((w.at(0.5).y + 2.95).abs() < 0.1, "{:?}", w.at(0.5));
    }

    #[test]
    fn a_zip_keeps_the_clips_speed_and_lands_on_the_point() {
        let perch = Perch { hold: Vec3::new(0., 10., -20.35), feet: Vec3::new(0., 10., -20.), out: Vec3::Z };
        let from = Vec3::new(0., 8., 0.);
        let mut z = PointZip::start(from, perch).unwrap();
        assert!((z.position() - from).length() < 1e-3, "starts where he is");
        let dt = 1. / 60.;
        let mut prev = z.position();
        let mut top = 0f32;
        let mut speeds = vec![];
        while !z.arrived() {
            z.elapsed += dt;
            let p = z.position();
            speeds.push((p - prev).length() / dt);
            top = top.max(p.y);
            prev = p;
        }
        assert!((prev - z.target).length() < 1e-3);
        // 20 m at about 22.5 m/s
        let mean = speeds.iter().sum::<f32>() / speeds.len() as f32;
        assert!((mean - 22.6).abs() < 1.5, "{mean}");
        // the clip's way comes down onto the point from above it
        assert!(top > z.target.y + 0.3, "the arc rises above the point: {top}");
        // a long zip is scaled: 45 m in the clip's whole length
        let far = Perch { feet: Vec3::new(0., 30., -42.), hold: Vec3::new(0., 30., -42.35), out: Vec3::Z };
        let z = PointZip::start(Vec3::new(0., 15., 0.), far).unwrap();
        assert!((z.remaining() - clip_duration()).abs() < 1e-3);
    }

    #[test]
    fn points_are_found_on_imported_objects_like_on_boxes() {
        // a statue-like block (a mesh) and a building (a box), each 12 m tall
        let mesh = World::with_triangles(vec![], &box_mesh(Vec3::new(0., 6., -20.), Vec3::new(3., 6., 3.)));
        let boxes = World::boxes(&[Tower { center: Vec3::new(0., 6., -20.), half: Vec3::new(3., 6., 3.) }]);
        let eye = Vec3::new(0., 3., 6.);
        let from = Vec3::new(0., 1., 0.);
        for w in [&mesh, &boxes] {
            let aim = (Vec3::new(0.5, 12., -17.) - eye).normalize();
            let p = find(w, from, eye, aim).expect("the near rim");
            assert!((p.hold.y - 12.).abs() < 1e-3 && (p.hold.z + 17.).abs() < 1e-3, "{p:?}");
            assert!((p.feet - Vec3::new(p.hold.x, 12., -17.35)).length() < 1e-3, "{p:?}");
            assert_eq!(p.out, Vec3::Z);
            // looking away: nothing
            assert!(find(w, from, eye, Vec3::Z).is_none());
        }
    }

    #[test]
    fn a_point_out_of_sight_or_without_room_is_refused() {
        let mut tris = box_mesh(Vec3::new(0., 6., -20.), Vec3::new(3., 6., 3.));
        // a wall in front of it
        tris.extend(box_mesh(Vec3::new(0., 8., -10.), Vec3::new(6., 8., 0.5)));
        let w = World::with_triangles(vec![], &tris);
        let eye = Vec3::new(0., 3., 6.);
        let aim = (Vec3::new(0.5, 12., -17.) - eye).normalize();
        // (the wall's own top, in sight, may be taken instead)
        let p = find(&w, Vec3::new(0., 1., 0.), eye, aim);
        assert!(p.is_none_or(|p| p.hold.z > -11.), "{p:?}");
        // a low ceiling over the top
        let mut tris = box_mesh(Vec3::new(0., 6., -20.), Vec3::new(3., 6., 3.));
        tris.extend(box_mesh(Vec3::new(0., 13.2, -20.), Vec3::new(3., 0.2, 3.)));
        let w = World::with_triangles(vec![], &tris);
        let p = find(&w, Vec3::new(0., 1., 0.), eye, aim);
        assert!(p.is_none_or(|p| p.hold.y > 13.), "{p:?}");
    }

    #[test]
    fn the_launch_probes_see_a_wall_ahead() {
        let w = World::boxes(&[Tower { center: Vec3::new(0., 3., -6.), half: Vec3::new(5., 3., 0.5) }]);
        let p = probes(&w, Vec3::ZERO, Vec3::NEG_Z);
        // the cast at the wall's top height grazes it (0.25 m sphere): clear from 7 m
        assert_eq!(p.clear, 7.);
        assert!((p.nearest - 5.5).abs() < 1e-3, "{p:?}");
        assert_eq!(probes(&World::default(), Vec3::ZERO, Vec3::NEG_Z), Probes::CLEAR);
    }

    // ---- the hero: zips, perches and launches against imported objects and buildings --------------------------------
    use crate::physics::{DT, FOOT, Hero, Intent, Mode, Tuning};

    /// A car-like object (a body and a cabin on it) as an imported mesh
    fn car_world() -> World {
        let mut tris = box_mesh(Vec3::new(0., 0.7, -12.), Vec3::new(1., 0.7, 2.3));
        tris.extend(box_mesh(Vec3::new(0., 1.7, -12.2), Vec3::new(0.8, 0.3, 1.2)));
        World::with_triangles(vec![], &tris)
    }
    /// A 10 m block, as a box or as an imported mesh, its near rim 16 m in front of him
    fn block(mesh: bool, extra: &[Tower]) -> World {
        let (c, h) = (Vec3::new(0., 5., -20.), Vec3::new(4., 5., 4.));
        if mesh {
            World::with_triangles(extra.to_vec(), &box_mesh(c, h))
        } else {
            let mut t = vec![Tower { center: c, half: h }];
            t.extend_from_slice(extra);
            World::new(t, &[])
        }
    }
    fn standing(at: Vec3) -> Hero {
        let mut h = Hero::default();
        h.pos = at;
        h.previous = at;
        h.velocity = Vec3::ZERO;
        h.mode = Mode::Ground;
        h
    }
    fn walk() -> Intent {
        Intent { forward: Vec3::NEG_Z, right: Vec3::X, ..default() }
    }
    /// Zips to the point the camera (behind him) aims at `at`, pressing jump `press_before` s before the zip ends
    fn zip_to(h: &mut Hero, w: &World, at: Vec3, press_before: Option<f32>) {
        let t = Tuning::default();
        let eye = h.pos + Vec3::new(0., 1.5, 4.);
        let start = Intent { point_zip: true, aim: (at - eye).normalize(), aim_origin: eye, ..walk() };
        h.step(start, w, &t, DT);
        assert_eq!(h.mode, Mode::Zip, "the zip started");
        let mut pressed = false;
        for _ in 0..600 {
            let mut i = walk();
            if let (Some(b), Some(z), false) = (press_before, h.point_zip, pressed) {
                if z.remaining() <= b {
                    i.jump = true;
                    pressed = true;
                }
            }
            h.step(i, w, &t, DT);
            if h.point_zip.is_none() {
                return;
            }
        }
        panic!("the zip never ended");
    }

    #[test]
    fn he_perches_on_an_imported_cars_roof() {
        let w = car_world();
        let mut h = standing(Vec3::new(7., FOOT, -12.));
        zip_to(&mut h, &w, Vec3::new(0.8, 2., -12.4), None);
        assert_eq!(h.mode, Mode::Perch);
        let feet = h.pos - Vec3::Y * FOOT;
        assert!((feet.y - 2.).abs() < 1e-3 && feet.x.abs() < 0.8, "on the cabin roof: {feet:?}");
        // he stays there
        for _ in 0..120 {
            h.step(walk(), &w, &Tuning::default(), DT);
        }
        assert_eq!(h.mode, Mode::Perch);
        assert!((h.pos - feet - Vec3::Y * FOOT).length() < 1e-4);
    }

    #[test]
    fn a_press_just_before_arriving_launches_with_the_full_boost() {
        for mesh in [false, true] {
            let w = block(mesh, &[]);
            let mut h = standing(Vec3::new(0., FOOT, 0.));
            zip_to(&mut h, &w, Vec3::new(0.5, 10., -16.), Some(0.1));
            assert_eq!((h.launches, h.launch_fx, h.mode), (1, 2, Mode::Air));
            assert!(h.native.active());
            // ExitDataZero with its bonuses: 27 m/s on, 12 m up in 0.8 s
            let v = h.velocity;
            assert!(v.with_y(0.).length() > 25. && v.z < -25., "{v:?}");
            assert!(v.y > 27. && v.y < 30.5, "{v:?}");
            let mut top = h.pos.y;
            for _ in 0..240 {
                h.step(walk(), &w, &Tuning::default(), DT);
                top = top.max(h.pos.y);
            }
            assert!((top - (10. + FOOT + 12.)).abs() < 0.5, "12 m over the point: {top}");
        }
    }

    #[test]
    fn an_early_press_launches_without_the_boost() {
        let w = block(false, &[]);
        let mut h = standing(Vec3::new(0., FOOT, 10.));
        zip_to(&mut h, &w, Vec3::new(0.5, 10., -16.), Some(0.6));
        assert_eq!((h.launches, h.launch_fx), (1, 1));
        // ExitDataZero alone: 24 m/s on, 6 m up in 0.65 s
        let v = h.velocity;
        assert!((v.with_y(0.).length() - 24.).abs() < 1., "{v:?}");
        assert!(v.y > 16. && v.y < 19., "{v:?}");
    }

    #[test]
    fn a_press_right_after_arriving_still_launches() {
        let w = block(true, &[]);
        let mut h = standing(Vec3::new(0., FOOT, 0.));
        zip_to(&mut h, &w, Vec3::new(0.5, 10., -16.), None);
        assert_eq!(h.mode, Mode::Perch);
        h.step(walk(), &w, &Tuning::default(), DT);
        h.step(Intent { jump: true, ..walk() }, &w, &Tuning::default(), DT);
        assert_eq!((h.launches, h.launch_fx, h.mode), (1, 2, Mode::Air));
    }

    #[test]
    fn perched_he_jumps_off_drops_or_stands_up() {
        let t = Tuning::default();
        for mesh in [false, true] {
            let w = block(mesh, &[]);
            let perched = || {
                let mut h = standing(Vec3::new(0., FOOT, 0.));
                zip_to(&mut h, &w, Vec3::new(0.5, 10., -16.), None);
                for _ in 0..60 {
                    h.step(walk(), &w, &t, DT);
                }
                assert_eq!(h.mode, Mode::Perch);
                h
            };
            // A: the game's jump off a perch, 2 m up
            let mut h = perched();
            let y0 = h.pos.y;
            h.step(Intent { jump: true, ..walk() }, &w, &t, DT);
            assert_eq!((h.mode, h.launches), (Mode::Air, 0));
            let mut top = h.pos.y;
            for _ in 0..60 {
                h.step(walk(), &w, &t, DT);
                top = top.max(h.pos.y);
            }
            assert!((top - y0 - 2.).abs() < 0.3, "a 2 m jump: {}", top - y0);
            // the drop: off the edge and down
            let mut h = perched();
            h.step(Intent { drop: true, ..walk() }, &w, &t, DT);
            for _ in 0..120 {
                h.step(walk(), &w, &t, DT);
            }
            assert!(h.pos.y < 8. && h.pos.z > -16., "{:?}", h.pos);
            // the stick: he stands up and walks on the top
            let mut h = perched();
            for _ in 0..60 {
                h.step(Intent { movement: Vec2::Y, ..walk() }, &w, &t, DT);
            }
            assert_eq!(h.mode, Mode::Ground);
            assert!((h.pos.y - (10. + FOOT)).abs() < 0.01 && h.pos.z < -17., "on the top: {:?}", h.pos);
        }
    }

    #[test]
    fn the_launch_rises_over_a_wall_ahead() {
        // a taller block beyond the first, along the launch
        let wall = Tower { center: Vec3::new(0., 9., -27.), half: Vec3::new(6., 9., 0.5) };
        let launch = |extra: &[Tower]| {
            let w = block(true, extra);
            let mut h = standing(Vec3::new(0., FOOT, 0.));
            zip_to(&mut h, &w, Vec3::new(0.5, 10., -16.), Some(0.1));
            assert_eq!(h.launches, 1);
            let v = h.velocity;
            for _ in 0..180 {
                h.step(walk(), &w, &Tuning::default(), DT);
            }
            (v, h.pos)
        };
        let (open, _) = launch(&[]);
        let (walled, past) = launch(&[wall]);
        assert!(past.z < -28., "over the wall: {past:?}");
        // (exe+b1be00: slower, so the rise reaches the top in time; here no faster up than it was)
        assert!(walled.with_y(0.).length() < open.with_y(0.).length() - 3. && walled.y >= open.y - 0.01, "{open:?} {walled:?}");
    }

    #[test]
    fn he_lands_on_imported_objects_and_is_kept_out_of_them() {
        let t = Tuning::default();
        let w = World::with_triangles(vec![], &box_mesh(Vec3::new(0., 1., -6.), Vec3::new(1., 1., 1.)));
        // falling onto its top
        let mut h = Hero::default();
        h.pos = Vec3::new(0., 6., -6.);
        h.previous = h.pos;
        h.velocity = Vec3::ZERO;
        for _ in 0..240 {
            h.step(walk(), &w, &t, DT);
        }
        assert_eq!(h.mode, Mode::Ground);
        assert!((h.pos.y - (2. + FOOT)).abs() < 0.01, "{:?}", h.pos);
        // running into its side
        let mut h = standing(Vec3::new(0., FOOT, 0.));
        for _ in 0..240 {
            h.step(Intent { movement: Vec2::Y, ..walk() }, &w, &t, DT);
            assert!(h.pos.z > -5. + crate::physics::RADIUS - 0.05, "inside it: {:?}", h.pos);
        }
        // falling fast onto a thin plate
        let w = World::with_triangles(vec![], &box_mesh(Vec3::new(0., 10., 0.), Vec3::new(3., 0.05, 3.)));
        let mut h = Hero::default();
        h.pos = Vec3::new(0., 40., 0.);
        h.previous = h.pos;
        h.velocity = Vec3::new(0., -60., 0.);
        for _ in 0..240 {
            h.step(walk(), &w, &t, DT);
        }
        assert!((h.pos.y - (10.05 + FOOT)).abs() < 0.01, "through the plate: {:?}", h.pos);
    }

    #[test]
    fn swing_points_are_found_on_imported_objects() {
        let mut tris = vec![];
        for d in [Vec3::NEG_Z, Vec3::Z, Vec3::X, Vec3::NEG_X] {
            tris.extend(box_mesh(d * 24. + Vec3::Y * 45., Vec3::new(4., 45., 4.)));
        }
        let w = World::with_triangles(vec![], &tris);
        let pos = Vec3::new(0., 18., 0.);
        let p = crate::traversal::find_swing_point(pos, Vec3::NEG_Z * 24., Vec3::ZERO, Vec3::NEG_Z, &w).expect("a point");
        assert!((p.attach.z + 20.).abs() < 1e-3 && p.attach.y > pos.y + 8., "{p:?}");
        assert!(p.anchor.z > p.attach.z, "the pivot off the wall, toward him: {p:?}");
    }
}
