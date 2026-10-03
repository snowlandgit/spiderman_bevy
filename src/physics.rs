//! Traversal simulation. The swing, the swing jump, the fall and the point launch are the game's own
//! (crates/sm_traversal, driven through crate::traversal); the zip to a point follows the game's zip animation
//! (crate::point_zip); ground movement, wall runs, the forward web zip, charged jumps, the dive and collisions are this
//! sandbox's. Everything here works against crate::world: the buildings' boxes and any imported object's triangles.
use crate::native_swing::{pitch, remap};
use crate::point_zip::{self, Perched, PointZip};
use crate::traversal::{self, Native, SwingPoint, v3, vec3};
use crate::world::{WALKABLE, World};
use bevy::prelude::*;
use sm_traversal::air::{AirEntry, KIND_PERCH_JUMP};
use sm_traversal::point_launch::{self, Exit, PRESS_BUFFER};
use serde::Deserialize;
use serde_json::Value;

#[cfg(test)]
pub const DT: f32 = 1.0 / 120.0;
pub const RADIUS: f32 = 0.42;
pub const FOOT: f32 = 0.95;

#[derive(Clone, Copy, Debug)]
pub struct Tower {
    pub center: Vec3,
    pub half: Vec3,
}
impl Tower {
    pub fn min(self) -> Vec3 {
        self.center - self.half
    }
    pub fn max(self) -> Vec3 {
        self.center + self.half
    }
    #[cfg(test)]
    pub fn contains(self, p: Vec3, margin: f32) -> bool {
        p.cmpge(self.min() - Vec3::splat(margin)).all()
            && p.cmple(self.max() + Vec3::splat(margin)).all()
    }
}
/// The world the hero moves through. It starts with the buildings' authored boxes; the imported objects' triangles
/// join once their meshes have loaded (main.rs, build_world).
#[derive(Resource)]
pub struct Arena(pub World);
impl Default for Arena {
    fn default() -> Self {
        // Collision and anchor envelopes follow the visible game-kit buildings.
        Self(World::boxes(&crate::environment::layout_towers()))
    }
}

/// The sandbox's own air weight (zips and the charged jumps' ascent); the swing's is the game's.
#[derive(Clone, Deserialize)]
pub struct SwingTuning {
    pub release_gravity_min: f32,
}
impl Default for SwingTuning {
    fn default() -> Self {
        serde_json::from_str(include_str!("../assets/tuning/sandbox_swing.json")).unwrap()
    }
}

#[derive(Resource, Clone)]
pub struct Tuning {
    pub swing: SwingTuning,
    pub air: crate::air::AirTuning,
    pub zip: crate::zip::ZipTuning,
    pub jump: crate::jump::JumpTuning,
    pub pure_max: f32,
}
impl Default for Tuning {
    fn default() -> Self {
        let v: Value = serde_json::from_str(include_str!(
            "../assets/tuning/hero_swingsetup_standard.json"
        ))
        .unwrap();
        let value = |path: &str| v.pointer(path).and_then(Value::as_f64).unwrap() as f32;
        Self {
            swing: SwingTuning::default(),
            air: crate::air::AirTuning::default(),
            zip: crate::zip::ZipTuning::default(),
            jump: crate::jump::JumpTuning::default(),
            pure_max: value("/MotionParams/SpeedParams/TerminalVelocityPureMax"),
        }
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Mode {
    Ground,
    Air,
    Swing,
    Dive,
    Wall,
    Zip,
    /// on a point after a zip to it
    Perch,
}
impl Mode {
    pub fn label(self) -> &'static str {
        match self {
            Self::Ground => "GROUND",
            Self::Air => "AIR",
            Self::Swing => "SWING",
            Self::Dive => "DIVE",
            Self::Wall => "WALL RUN",
            Self::Zip => "WEB ZIP",
            Self::Perch => "PERCH",
        }
    }
}
#[derive(Clone, Copy, Debug)]
pub struct Rope {
    pub anchor: Vec3,
    pub pivot: Vec3,
    pub forward: Vec3,
    pub side: Vec3,
    pub terminal: f32,
    pub crossed_trough: bool,
    pub gravity_blend: f32,
    pub length: f32,
    pub age: f32,
}
#[derive(Resource, Clone)]
pub struct Hero {
    pub pos: Vec3,
    pub previous: Vec3,
    pub velocity: Vec3,
    pub heading: Vec3,
    pub mode: Mode,
    pub mode_age: f32,
    pub rope: Option<Rope>,
    pub wall_normal: Vec3,
    pub airborne: f32,
    pub release_gravity: f32,
    pub swing_count: u32,
    pub last_swing: f32,
    pub jump_buffer: f32,
    pub coyote: f32,
    pub cooldown: f32,
    pub zip_motion: Option<crate::zip::ZipMotion>,
    /// a zip to a point under way, and the perch it ends on
    pub point_zip: Option<PointZip>,
    pub perch: Option<Perched>,
    /// seconds since the jump button's press
    pub jump_age: f32,
    /// point launches so far, and the last one's boost effect (0 none, 1 a press, 2 the full boost)
    pub launches: u32,
    pub launch_fx: u32,
    pub since_launch: f32,
    pub zip_count: u32,
    pub zip_stage: u32,
    pub zip_cooldown: f32,
    pub last_zip: f32,
    pub swing_left: bool,
    pub swing_from_dive: bool,
    pub airborne_before_landing: f32,
    pub last_ground_jump: f32,
    pub jump_charge: Option<f32>,
    pub ground_jump_kind: crate::jump::JumpKind,
    pub ground_jump_count: u32,
    pub release_variant: usize,
    pub boosted_release: bool,
    pub peak_speed: f32,
    pub max_rope_error: f32,
    pub momentum: f32,
    pub swing_phase: f32,
    pub release_angle: f32,
    pub swing_held: bool,
    pub swing_request: f32,
    /// the game's swing, swing jump and fall
    pub native: Native,
}
impl Default for Hero {
    fn default() -> Self {
        let pos = Vec3::new(0., 18., 8.);
        Self {
            pos,
            previous: pos,
            velocity: Vec3::new(0., 0., -16.),
            heading: Vec3::NEG_Z,
            mode: Mode::Air,
            mode_age: 0.,
            rope: None,
            wall_normal: Vec3::ZERO,
            airborne: 0.,
            release_gravity: SwingTuning::default().release_gravity_min,
            swing_count: 0,
            last_swing: 999.,
            jump_buffer: 0.,
            coyote: 0.,
            cooldown: 0.,
            zip_motion: None,
            point_zip: None,
            perch: None,
            jump_age: 99.,
            launches: 0,
            launch_fx: 0,
            since_launch: 999.,
            zip_count: 0,
            zip_stage: 0,
            zip_cooldown: 0.,
            last_zip: 999.,
            swing_left: false,
            swing_from_dive: false,
            airborne_before_landing: 0.,
            last_ground_jump: 999.,
            jump_charge: None,
            ground_jump_kind: crate::jump::JumpKind::Normal,
            ground_jump_count: 0,
            release_variant: 0,
            boosted_release: false,
            peak_speed: 0.,
            max_rope_error: 0.,
            momentum: 0.,
            swing_phase: 0.,
            release_angle: 0.,
            swing_held: false,
            swing_request: 0.,
            native: Native::default(),
        }
    }
}
#[derive(Resource, Default, Clone, Copy)]
pub struct Intent {
    pub movement: Vec2,
    pub forward: Vec3,
    pub right: Vec3,
    pub swing: bool,
    pub jump: bool,
    pub jump_held: bool,
    pub cancel_jump_charge: bool,
    pub dive: bool,
    pub zip: bool,
    pub point_zip: bool,
    /// the camera's forward and position (what the zip to a point aims with)
    pub aim: Vec3,
    pub aim_origin: Vec3,
    /// step off a perch (B / C)
    pub drop: bool,
    pub reset: bool,
}

pub fn ray_box(origin: Vec3, direction: Vec3, tower: Tower, max_dist: f32) -> Option<f32> {
    let lo = tower.min();
    let hi = tower.max();
    let mut near = 0.0f32;
    let mut far = max_dist;
    for axis in 0..3 {
        if direction[axis].abs() < 1e-6 {
            if origin[axis] < lo[axis] || origin[axis] > hi[axis] {
                return None;
            }
        } else {
            let a = (lo[axis] - origin[axis]) / direction[axis];
            let b = (hi[axis] - origin[axis]) / direction[axis];
            near = near.max(a.min(b));
            far = far.min(a.max(b));
            if near > far {
                return None;
            }
        }
    }
    (near <= max_dist && far >= 0.).then_some(near)
}

/// Select in the plane of actual travel; use steering only when horizontal motion is negligible.
pub fn swing_direction(hero: &Hero, fallback: Vec3) -> Vec3 {
    let travel = hero.velocity.with_y(0.);
    if travel.length_squared() >= 2.25 {
        return travel.normalize();
    }
    for direction in [fallback, hero.heading, Vec3::NEG_Z] {
        let horizontal = direction.with_y(0.).normalize_or_zero();
        if horizontal.length_squared() > 0.1 {
            return horizontal;
        }
    }
    unreachable!("default direction is nonzero")
}


impl Hero {
    fn set_mode(&mut self, mode: Mode) {
        if self.mode != mode {
            self.mode = mode;
            self.mode_age = 0.;
        }
    }
    /// A swing of the game's own, from a swing point (the swing starts on the next native step)
    fn native_attach(&mut self, point: SwingPoint) {
        if !self.native.active() {
            self.native.sync(self.pos, self.velocity, self.heading, true);
        }
        self.native.start_swing(point);
        let forward = self.velocity.with_y(0.).normalize_or(self.heading);
        let side = forward.cross(Vec3::Y).normalize_or_zero();
        self.rope = Some(Rope {
            anchor: point.attach,
            pivot: point.anchor,
            forward,
            side,
            terminal: 0.,
            crossed_trough: false,
            gravity_blend: 0.,
            length: point.anchor.distance(self.pos),
            age: 0.,
        });
        self.swing_request = 0.;
        self.swing_from_dive = self.mode == Mode::Dive;
        self.swing_count += 1;
        self.swing_phase = 0.;
        self.set_mode(Mode::Swing);
        self.point_zip = None;
        self.perch = None;
        self.zip_motion = None;
        self.swing_left = (point.attach - self.pos).dot(side) < 0.;
    }
    /// A frame of the game's swing, swing jump or fall: its move, then collisions, then the mover's record of it
    fn native_step(&mut self, input: Intent, world: &World, dt: f32) {
        let height = self.pos.y - FOOT - world.ground_below(self.pos);
        let (displacement, frame) = self.native.step(
            input.movement,
            input.swing,
            input.jump,
            input.jump_held,
            input.forward,
            input.right,
            height,
            dt,
        );
        if let Some(r) = frame.released {
            let v = traversal::vec3(r.velocity);
            self.rope = None;
            self.release_variant = (self.swing_count as usize) % 5;
            self.release_angle = pitch(v);
            self.boosted_release = r.jumped;
            self.release_gravity = r.gravity;
            self.jump_buffer = 0.;
            self.cooldown = 0.2;
            self.last_swing = 0.;
            self.set_mode(Mode::Air);
        }
        self.pos += displacement;
        self.velocity = displacement / dt;
        self.collide(world, input, dt);
        let airborne = self.mode != Mode::Ground;
        self.native.moved(self.pos, airborne, dt);
        self.velocity = (self.pos - self.previous) / dt;
        if matches!(self.mode, Mode::Ground | Mode::Wall) {
            // landed, or caught a wall: the sandbox's own movement from here
            self.native.stop(dt);
            self.rope = None;
            return;
        }
        self.heading = self.native.facing();
        if frame.mode == sm_traversal::sim::Mode::Swing {
            let pivot = self.native.pivot();
            let forward = self.native.swing_forward();
            let angle = self.native.swing_angle();
            let s = &self.native.trav.swing;
            if let Some(rope) = self.rope.as_mut() {
                rope.pivot = pivot;
                rope.forward = forward;
                rope.side = forward.cross(Vec3::Y).normalize_or_zero();
                rope.terminal = s.terminal;
                rope.gravity_blend = s.gravity_blend;
                rope.length = pivot.distance(self.pos);
                rope.age = self.native.swing_age();
                rope.crossed_trough |= angle <= 90.;
            }
            self.swing_phase = ((180. - angle) / 180.).clamp(0., 1.);
        } else if self.mode == Mode::Swing {
            self.set_mode(Mode::Air);
        }
    }
    pub fn step(&mut self, input: Intent, world: &World, tuning: &Tuning, dt: f32) {
        if input.reset {
            *self = Self::default();
            return;
        }
        let pressed_swing = input.swing && !self.swing_held;
        self.swing_held = input.swing;
        self.swing_request = if !input.swing || input.dive {
            0.
        } else if pressed_swing {
            0.4
        } else {
            (self.swing_request - dt).max(0.)
        };
        self.previous = self.pos;
        self.mode_age += dt;
        self.last_swing += dt;
        self.last_zip += dt;
        self.last_ground_jump += dt;
        self.jump_age = if input.jump { 0. } else { self.jump_age + dt };
        self.since_launch += dt;
        self.zip_cooldown = (self.zip_cooldown - dt).max(0.);
        self.cooldown = (self.cooldown - dt).max(0.);
        self.coyote = (self.coyote - dt).max(0.);
        let charging = self.mode == Mode::Ground && (input.jump_held || self.jump_charge.is_some());
        if input.jump && !charging {
            self.jump_buffer = 0.14;
        } else {
            self.jump_buffer = (self.jump_buffer - dt).max(0.);
        }
        let wish = (input.forward * input.movement.y + input.right * input.movement.x)
            .with_y(0.)
            .normalize_or_zero();
        if input.cancel_jump_charge || input.zip || input.point_zip || self.mode != Mode::Ground {
            self.jump_charge = None;
        } else if charging {
            self.jump_buffer = 0.;
            if input.jump && input.jump_held {
                self.jump_charge = Some(0.);
            }
            if let Some(charge) = self.jump_charge {
                if input.jump_held {
                    self.jump_charge = Some((charge + dt).min(tuning.jump.full_charge_seconds));
                } else {
                    self.launch_ground_jump(charge, wish, &tuning.jump);
                }
            }
        }
        let placed = self.point_zip.is_some() || self.perch.is_some();
        if wish.length_squared() > 0.1 && !self.native.active() && !placed {
            self.heading = self
                .heading
                .lerp(wish, 1. - (-8. * dt).exp())
                .normalize_or_zero();
        }
        if self.heading.length_squared() < 0.1 {
            self.heading = Vec3::NEG_Z;
        }
        // The game's swing lets go by itself (crate::traversal); the dive cancels it here.
        if self.native.active() && input.dive {
            self.native.stop(dt);
            self.rope = None;
            self.last_swing = 0.;
            self.set_mode(Mode::Dive);
        }
        if self.mode == Mode::Wall && self.jump_buffer > 0. {
            self.velocity = self.wall_normal * 12. + self.heading * 9. + Vec3::Y * 20.;
            self.set_mode(Mode::Air);
            self.jump_buffer = 0.;
            self.cooldown = 0.3;
        } else if self.mode == Mode::Ground && self.jump_buffer > 0. {
            self.launch_ground_jump(0., wish, &tuning.jump);
        }
        if input.dive && self.zip_motion.is_some_and(|zip| !zip.from_dive) {
            self.zip_motion = None;
            self.set_mode(Mode::Dive);
        }
        // the drop button lets go of a zip to a point (he falls on)
        if input.drop && self.point_zip.is_some() {
            self.point_zip = None;
            self.set_mode(Mode::Air);
        }
        if input.zip && self.zip_cooldown <= 0. && self.mode != Mode::Zip {
            let forward = if input.forward.with_y(0.).length_squared() > 0.1 {
                input.forward.with_y(0.).normalize()
            } else {
                self.heading
            };
            let anchors = crate::zip::anchors_for(self.pos, forward, world);
            if anchors.iter().any(Option::is_some) {
                let ground = self.mode == Mode::Ground;
                let stage = if self.last_zip <= 1.25 {
                    (self.zip_stage + 1).min(3)
                } else {
                    1
                };
                let motion = tuning.zip.motion(
                    self,
                    forward,
                    anchors,
                    ground,
                    stage,
                    tuning.swing.release_gravity_min,
                );
                self.rope = None;
                self.native.stop(dt);
                self.point_zip = None;
                self.perch = None;
                self.zip_motion = Some(motion);
                self.zip_count += 1;
                self.zip_stage = stage;
                self.zip_cooldown = motion.lockout;
                self.cooldown = motion.lockout;
                self.heading = forward;
                self.set_mode(Mode::Zip);
                self.mode_age = 0.;
            }
        }
        // the zip to a point: from the ground, the air, a swing or a perch (on to the next point)
        if input.point_zip && self.zip_cooldown <= 0. && self.point_zip.is_none() {
            let aim = if input.aim.length_squared() > 0.1 { input.aim } else { self.heading };
            let eye = if input.aim_origin == Vec3::ZERO { self.pos + Vec3::Y * 0.6 } else { input.aim_origin };
            let here = self.perch.map(|p| p.zip.perch.feet);
            let zip = point_zip::find(world, self.pos, eye, aim)
                .filter(|p| here.is_none_or(|f| f.distance(p.feet) > 1.5))
                .and_then(|p| PointZip::start(self.pos, p));
            if let Some(z) = zip {
                self.rope = None;
                self.native.stop(dt);
                self.zip_motion = None;
                self.perch = None;
                self.point_zip = Some(z);
                self.heading = z.fwd;
                self.zip_count += 1;
                self.zip_cooldown = 0.25;
                self.set_mode(Mode::Zip);
                self.mode_age = 0.;
            }
        }
        if input.swing
            && !input.dive
            && self.rope.is_none()
            && !self.native.swinging()
            && !matches!(self.mode, Mode::Wall | Mode::Ground | Mode::Zip | Mode::Perch)
            && self.cooldown <= 0.
            && self.pos.y > 3.
            && (self.swing_request > 0.
                || self.velocity.y <= 0.
                || (self.swing_count == 0 && self.last_ground_jump > 3.))
        {
            if let Some(point) =
                traversal::find_swing_point(self.pos, self.velocity, wish, input.forward, world)
            {
                self.native_attach(point);
            }
        }
        // Falling (and not zipping or diving) is the game's fall state.
        if !self.native.active()
            && self.mode == Mode::Air
            && !input.dive
            && self.velocity.y <= 0.
            && self.zip_motion.is_none()
            && self.point_zip.is_none()
            && self.perch.is_none()
        {
            self.native.sync(self.pos, self.velocity, self.heading, true);
            self.native.start_fall(dt);
        }
        // the zip to a point and the perch place him themselves; a launch from either hands him to the game's jump
        if self.point_zip.is_some() {
            self.point_zip_step(input, world, dt);
        } else if self.perch.is_some() {
            self.perch_step(input, world, dt);
        }
        let placed = self.point_zip.is_some() || self.perch.is_some();
        let mut native_moved = false;
        if placed {
        } else if let Some(mut zip) = self.zip_motion {
            if self.mode_age >= 0.18 && !zip.kicked {
                let horizontal = self.velocity.with_y(0.);
                let sideways = horizontal - zip.direction * horizontal.dot(zip.direction);
                self.velocity = zip.direction * zip.launch_speed
                    + sideways * zip.carry
                    + Vec3::Y
                        // Existing ascent counts toward the zip lift; avoid stacking another launch.
                        * (self.velocity.y.max(0.).max(zip.lift_speed)
                            + self.velocity.y.min(0.) * zip.drop_kept);
                zip.kicked = true;
                self.release_gravity = zip.gravity;
            }
            if !zip.kicked && zip.from_ground {
                self.velocity.y = 0.;
            } else {
                // Gravity also applies during the shot and animation followthrough.
                let gravity = if self.velocity.y <= 0. {
                    zip.gravity.max(tuning.air.fall_gravity)
                } else {
                    zip.gravity
                };
                self.velocity.y -= gravity * dt;
            }
            self.zip_motion = Some(zip);
            if self.mode_age >= 1. {
                self.zip_motion = None;
                self.last_zip = 0.;
                self.last_swing = 999.;
                self.boosted_release = false;
                self.set_mode(Mode::Air);
            }
        } else if self.native.active() {
            self.native_step(input, world, dt);
            native_moved = true;
        } else if self.mode == Mode::Ground {
            let target = wish * 10.5;
            self.velocity = self.velocity.lerp(target, 1. - (-14. * dt).exp());
            self.velocity.y = 0.;
        } else if self.mode == Mode::Wall && input.swing {
            let tangent = wish - self.wall_normal * wish.dot(self.wall_normal);
            self.velocity = Vec3::Y * 16. + tangent * 9.;
        } else {
            self.set_mode(if input.dive { Mode::Dive } else { Mode::Air });
            let gravity = if input.dive {
                tuning.air.dive_gravity
            } else if self.velocity.y <= 0. {
                self.release_gravity.max(tuning.air.fall_gravity)
            } else {
                // Preserve the authored charged-jump ascent, then give its fall full weight.
                self.release_gravity
            };
            self.velocity = tuning
                .air
                .steer(self.velocity, wish, input.movement.length(), dt);
            self.velocity.y -= gravity * dt;
            let (decay_delay, decay_rate) = if self.momentum >= 5. {
                (0.5, 1.)
            } else if self.momentum >= 3.5 {
                (0.75, 0.66)
            } else {
                (1., 0.25)
            };
            if self.last_swing > decay_delay {
                self.momentum = (self.momentum - decay_rate * dt).max(0.);
            }
            if input.dive {
                self.momentum = (self.momentum + remap(self.mode_age, 0.5, 2.) * 1.25 * dt).min(5.);
            }
            if input.dive {
                self.velocity += self.heading * 6. * dt;
            }
        }
        if placed {
            // the game's tracker runs every frame (momentum decays, the swing setups blend)
            let height = self.pos.y - FOOT - world.ground_below(self.pos);
            self.native.idle(self.velocity, true, height, dt);
            self.native.sync(self.pos, self.velocity, self.heading, true);
        } else if !native_moved {
            self.velocity = self.velocity.clamp_length_max(tuning.pure_max);
            if self.rope.is_none() {
                self.pos += self.velocity * dt;
            }
            self.collide(world, input, dt);
            // the game's tracker runs every frame (momentum decays, the swing setups blend)
            let airborne = self.mode != Mode::Ground;
            let height = self.pos.y - FOOT - world.ground_below(self.pos);
            self.native.idle(self.velocity, airborne, height, dt);
            self.native.sync(self.pos, self.velocity, self.heading, airborne);
        }
        self.momentum = self.native.momentum();
        if self.mode != Mode::Ground {
            self.airborne += dt;
        } else {
            self.airborne = 0.;
        }
        if !native_moved
            && matches!(self.mode, Mode::Air | Mode::Dive)
            && self.velocity.with_y(0.).length_squared() >= 2.25
        {
            self.heading = self.velocity.with_y(0.).normalize();
        }
        self.peak_speed = self.peak_speed.max(self.velocity.length());
        if !self.pos.is_finite() || self.pos.y < -20. || self.pos.length() > 2000. {
            *self = Self::default();
        }
    }

    /// The stick in the world, level, and how far it is pushed (exe+b7e920 as the launch reads it)
    fn stick_world(input: Intent) -> (Vec3, f32) {
        let amount = input.movement.length().min(1.);
        let dir = (input.forward * input.movement.y + input.right * input.movement.x)
            .with_y(0.)
            .normalize_or_zero();
        (dir, if dir == Vec3::ZERO { 0. } else { amount })
    }

    /// A frame of the zip to a point: along the clip's way, warped onto the point. A jump press starts the launch's
    /// clock; at the end he launches (with a press) or perches.
    fn point_zip_step(&mut self, input: Intent, world: &World, dt: f32) {
        let Some(mut z) = self.point_zip else { return };
        // the press's clock (exe+b1d640): from a press (buffered 0.1 s) until the launch
        z.press = match z.press {
            Some(c) => Some(c + dt),
            None if self.jump_age < PRESS_BUFFER => Some(0.),
            None => None,
        };
        // the end of the zip: the stick sets the launch's way (exe+b1d640)
        if z.remaining() <= point_zip::ARRIVAL_WINDOW {
            let cfgs = traversal::configs();
            let cfg = &cfgs.traversal.point_launch_config;
            let (stick, amount) = Self::stick_world(input);
            let (dir, amount) = point_launch::exit_direction(cfg, v3(z.fwd), v3(z.launch_dir), v3(stick), amount);
            (z.launch_dir, z.amount) = (vec3(dir), amount);
        }
        let before = self.pos;
        z.elapsed += dt;
        let next = z.position();
        let d = next - before;
        let len = d.length();
        // something in the way (short of the point): the zip ends where he is
        let blocked = len > 1e-5
            && next.distance(z.target) > 0.5
            && world
                .sphere_cast(before, d / len, point_zip::SWEEP_RADIUS, len)
                .is_some_and(|h| h.t > 0. || h.normal.dot(d) < 0.);
        if blocked {
            self.point_zip = None;
            if z.press.is_some() {
                self.point_launch(z, input, world);
            } else {
                self.set_mode(Mode::Air);
            }
            return;
        }
        self.pos = next;
        self.velocity = d / dt;
        self.heading = z.fwd;
        if !z.arrived() {
            self.point_zip = Some(z);
            return;
        }
        self.pos = z.target;
        self.point_zip = None;
        self.last_zip = 0.;
        if z.press.is_some() {
            self.point_launch(z, input, world);
        } else {
            self.perch = Some(Perched { zip: z, age: 0. });
            self.velocity = Vec3::ZERO;
            self.set_mode(Mode::Perch);
        }
    }

    /// The point launch (the game's: sm_traversal::point_launch), into the game's jump state on the next native step
    fn point_launch(&mut self, z: PointZip, input: Intent, world: &World) {
        let cfgs = traversal::configs();
        let cfg = &cfgs.traversal.point_launch_config;
        let (stick, amount) = Self::stick_world(input);
        let (dir, amount) = point_launch::exit_direction(cfg, v3(z.fwd), v3(z.launch_dir), v3(stick), amount);
        let probes = point_zip::probes(world, self.pos - Vec3::Y * FOOT, vec3(dir));
        let launch = point_launch::launch(cfg, Exit::Point, dir, amount, z.press, &probes);
        // the launch's move starts here (the zip's last move is done)
        self.previous = self.pos;
        self.native.sync(self.pos, self.velocity, z.fwd, true);
        self.native.launch(launch.entry());
        self.point_zip = None;
        self.perch = None;
        self.rope = None;
        self.launches += 1;
        self.launch_fx = launch.fx;
        self.since_launch = 0.;
        // the release poses carry the launch
        self.last_swing = 0.;
        self.boosted_release = true;
        self.release_angle = pitch(vec3(launch.velocity));
        self.release_variant = (self.zip_count as usize) % 5;
        self.jump_buffer = 0.;
        self.cooldown = 0.2;
        self.set_mode(Mode::Air);
    }

    /// A frame perched: held on the point facing along the zip. A jump press on arrival still launches; after it, A
    /// jumps off (the game's jump off a perch), the drop button steps off the edge, the stick stands him up.
    fn perch_step(&mut self, input: Intent, world: &World, dt: f32) {
        let Some(mut p) = self.perch else { return };
        p.age += dt;
        let z = p.zip;
        self.pos = z.target;
        self.velocity = Vec3::ZERO;
        self.heading = z.fwd;
        if input.jump && p.age <= point_zip::ARRIVAL_WINDOW {
            let mut z = z;
            z.press = Some(0.);
            self.point_launch(z, input, world);
            return;
        }
        if input.jump {
            let (stick, amount) = Self::stick_world(input);
            let dir = if amount > 0.04 { stick } else { z.fwd };
            let cfg = traversal::configs();
            let fall_gravity = self.native.trav.tracker.fall_gravity;
            let e = AirEntry::ground_jump(&cfg, KIND_PERCH_JUMP, v3(dir), 0., amount, fall_gravity);
            self.previous = self.pos;
            self.native.sync(self.pos, Vec3::ZERO, self.heading, true);
            self.native.launch(e);
            self.perch = None;
            self.last_ground_jump = 0.;
            self.ground_jump_kind = crate::jump::JumpKind::Normal;
            self.jump_buffer = 0.;
            self.set_mode(Mode::Air);
            return;
        }
        if input.drop {
            self.pos = z.target + z.perch.out * 0.9;
            self.previous = self.pos;
            self.perch = None;
            self.set_mode(Mode::Air);
            return;
        }
        if input.movement.length() > 0.5 {
            self.perch = None;
            self.set_mode(Mode::Ground);
            return;
        }
        self.perch = Some(p);
    }

    fn collide(&mut self, world: &World, input: Intent, dt: f32) {
        let mut floor = FOOT;
        self.wall_normal = Vec3::ZERO;
        for tower in &world.towers {
            let lo = tower.min();
            let hi = tower.max();
            if self.pos.x >= lo.x - RADIUS
                && self.pos.x <= hi.x + RADIUS
                && self.pos.z >= lo.z - RADIUS
                && self.pos.z <= hi.z + RADIUS
            {
                if self.previous.y - FOOT >= hi.y - 0.1
                    && self.pos.y - FOOT <= hi.y
                    && self.velocity.y <= 0.
                {
                    floor = floor.max(hi.y + FOOT);
                    continue;
                }
            }
            let min = lo - Vec3::new(RADIUS, FOOT, RADIUS);
            let max = hi + Vec3::new(RADIUS, FOOT, RADIUS);
            let contact_margin = if self.mode == Mode::Wall && input.swing {
                0.03
            } else {
                0.
            };
            if self.pos.cmpge(min - Vec3::splat(contact_margin)).all()
                && self.pos.cmple(max + Vec3::splat(contact_margin)).all()
            {
                let distances = [
                    self.pos.x - min.x,
                    max.x - self.pos.x,
                    self.pos.z - min.z,
                    max.z - self.pos.z,
                ];
                let index = (0..4)
                    .min_by(|&a, &b| distances[a].total_cmp(&distances[b]))
                    .unwrap();
                let normal = match index {
                    0 => Vec3::NEG_X,
                    1 => Vec3::X,
                    2 => Vec3::NEG_Z,
                    _ => Vec3::Z,
                };
                self.pos += normal * (distances[index] + 0.005);
                let inward = self.velocity.dot(normal);
                if inward < 0. {
                    self.velocity -= normal * inward;
                }
                if input.swing && self.pos.y > 2. && self.cooldown <= 0. {
                    self.rope = None;
                    self.wall_normal = normal;
                    self.set_mode(Mode::Wall);
                    self.velocity.y = self.velocity.y.max(14.);
                }
            }
        }
        if world.has_mesh() {
            self.collide_mesh(world, input, &mut floor);
        }
        if self.pos.y <= floor && self.velocity.y <= 0. {
            if self.mode != Mode::Ground {
                self.airborne_before_landing = self.airborne;
            }
            self.pos.y = floor;
            self.velocity.y = 0.;
            let charging_zip = self.zip_motion.is_some_and(|z| z.from_ground && !z.kicked);
            if !charging_zip {
                self.rope = None;
                self.zip_motion = None;
                self.set_mode(Mode::Ground);
                self.coyote = 0.12;
                self.momentum = 0.;
            }
        } else if self.mode == Mode::Ground {
            self.set_mode(Mode::Air);
        }
        if self.mode == Mode::Wall && self.wall_normal == Vec3::ZERO {
            self.velocity.y -= 24. * dt;
            self.set_mode(Mode::Air);
        }
    }

    /// Collisions with the imported objects' triangles: what he moved through this step, the floor under him, and the
    /// walls his body overlaps (pushed out level; with the swing button held, a wall run as on the buildings)
    fn collide_mesh(&mut self, world: &World, input: Intent, floor: &mut f32) {
        let d = self.pos - self.previous;
        let len = d.length();
        if len > 0.2 {
            if let Some(h) = world.mesh_cast(self.previous, d / len, 0.3, len).filter(|h| h.t > 0. && h.normal.dot(d) < 0.) {
                self.pos = self.previous + d / len * (h.t - 0.01).max(0.);
                let inward = self.velocity.dot(h.normal);
                if inward < 0. {
                    self.velocity -= h.normal * inward;
                }
            }
        }
        // the floor: what is under his feet, from a step up (0.45 m) above them, and a little below while he walks
        if self.velocity.y <= 0. {
            let top = self.previous.y.max(self.pos.y) - FOOT + 0.45;
            let reach = top - (self.pos.y - FOOT) + if self.mode == Mode::Ground { 0.35 } else { 0.02 };
            if let Some(h) = world.mesh_floor(Vec3::new(self.pos.x, top, self.pos.z), reach) {
                *floor = floor.max(h.point.y + FOOT);
            }
        }
        let margin = if self.mode == Mode::Wall && input.swing { 0.03 } else { 0. };
        let feet = self.pos.y - FOOT;
        for oy in [-0.45f32, 0., 0.45] {
            let c = self.pos + Vec3::Y * oy;
            let mut push = Vec3::ZERO;
            let mut touch = Vec3::ZERO;
            world.mesh_contacts(c, RADIUS + margin, |q, n| {
                // what he stands on is the floor's
                if n.y.abs() >= WALKABLE && q.y <= feet + 0.5 {
                    return;
                }
                let dy = c.y - q.y;
                let h = (c - q).with_y(0.);
                let l = h.length();
                if l < 1e-4 || dy.abs() >= RADIUS + margin {
                    return;
                }
                let dir = h / l;
                touch = dir;
                if dy.abs() < RADIUS {
                    let need = (RADIUS * RADIUS - dy * dy).sqrt() - l;
                    if need > push.length() {
                        push = dir * need;
                    }
                }
            });
            if push != Vec3::ZERO {
                let n = push.normalize();
                self.pos += push + n * 0.005;
                let inward = self.velocity.dot(n);
                if inward < 0. {
                    self.velocity -= n * inward;
                }
                touch = n;
            }
            if touch != Vec3::ZERO && input.swing && self.pos.y > 2. && self.cooldown <= 0. {
                self.rope = None;
                self.wall_normal = touch;
                self.set_mode(Mode::Wall);
                self.velocity.y = self.velocity.y.max(14.);
            }
        }
    }
}

#[cfg(test)]
impl Hero {
    /// A swing from a surface point (outward normal `normal`), handed over as the game's swing point is
    pub fn attach_at(&mut self, attach: Vec3, normal: Vec3) {
        let flat = (attach - self.pos).with_y(0.).length();
        let anchor = attach + normal * (0.75 * flat).clamp(1., 6.);
        self.native_attach(SwingPoint { attach, anchor, score: 0. });
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    fn forward_swing() -> Intent {
        Intent {
            swing: true,
            movement: Vec2::Y,
            forward: Vec3::NEG_Z,
            right: Vec3::X,
            ..default()
        }
    }
    fn direction_fixture() -> World {
        World::boxes(
            &[Vec3::NEG_Z, Vec3::Z, Vec3::X, Vec3::NEG_X]
                .into_iter()
                .map(|direction| Tower {
                    center: direction * 24. + Vec3::Y * 45.,
                    half: Vec3::new(4., 45., 4.),
                })
                .collect::<Vec<_>>(),
        )
    }
    #[test]
    fn moving_attachment_ignores_camera_and_opposite_steering() {
        let t = Tuning::default();
        let towers = direction_fixture();
        let mut h = Hero::default();
        h.pos = Vec3::new(0., 18., 0.);
        h.velocity = Vec3::NEG_Z * 24.;
        h.heading = Vec3::Z;
        h.step(
            Intent {
                swing: true,
                movement: Vec2::Y,
                forward: Vec3::Z,
                ..default()
            },
            &towers,
            &t,
            DT,
        );
        let rope = h.rope.expect("forward travel attachment");
        assert!((rope.anchor - h.previous).dot(Vec3::NEG_Z) > 0.);
        assert!(
            rope.forward.dot(Vec3::NEG_Z) > 0.99,
            "entry pivot must follow momentum"
        );
        assert!(
            h.velocity.z < -23.,
            "opposite steering must not reverse the entry"
        );
    }
    #[test]
    fn press_during_release_cooldown_retries_while_rising() {
        let t = Tuning::default();
        let towers = direction_fixture();
        let mut h = Hero::default();
        h.pos = Vec3::new(0., 18., 0.);
        h.velocity = Vec3::new(0., 8., -24.);
        h.cooldown = 0.15;
        h.swing_count = 1;
        h.last_ground_jump = 0.;
        for _ in 0..12 {
            h.step(forward_swing(), &towers, &t, DT);
        }
        assert!(h.rope.is_none() && h.velocity.y > 0.);
        for _ in 0..10 {
            h.step(forward_swing(), &towers, &t, DT);
            if h.rope.is_some() {
                break;
            }
        }
        assert!(
            h.rope.is_some() && h.velocity.y > 0.,
            "fresh shot lost during lockout"
        );
    }
    #[test]
    fn real_city_new_shots_remain_forward_after_the_entry_step() {
        let t = Tuning::default();
        let a = Arena::default();
        let mut shots = 0;
        for x in [-10., 0., 10.] {
            for z in [-5., -40., -80., -120., -160., -220.] {
                for y in [6., 18., 45., 65.] {
                    for direction in [Vec3::NEG_Z, Vec3::Z, Vec3::X, Vec3::NEG_X] {
                        let mut h = Hero::default();
                        h.pos = Vec3::new(x, y, z);
                        h.velocity = direction * 24.;
                        h.step(
                            Intent {
                                swing: true,
                                movement: Vec2::Y,
                                forward: -direction,
                                ..default()
                            },
                            &a.0,
                            &t,
                            DT,
                        );
                        if let Some(r) = h.rope {
                            shots += 1;
                            let lead = (r.anchor - h.pos).dot(h.velocity.with_y(0.).normalize());
                            assert!(
                                lead > 0.,
                                "backward shot after entry: start={:?}, anchor={:?}, velocity={:?}",
                                h.previous,
                                r.anchor,
                                h.velocity
                            );
                        }
                    }
                }
            }
        }
        assert!(
            shots > 150,
            "unexpectedly poor city attachment coverage: {shots}"
        );
    }
    #[test]
    fn swing_crosses_the_trough_before_automatic_release() {
        let t = Tuning::default();
        let a = Arena::default();
        let mut h = Hero::default();
        let mut crossed = false;
        for _ in 0..280 {
            h.step(
                Intent {
                    swing: true,
                    movement: Vec2::Y,
                    forward: Vec3::NEG_Z,
                    right: Vec3::X,
                    ..default()
                },
                &a.0,
                &t,
                DT,
            );
            if h.swing_phase > 0.65 {
                crossed = true;
            }
            assert!(
                h.swing_count <= 1,
                "must finish the first arc before choosing another line"
            );
            if h.rope.is_none() {
                assert!(crossed, "released before ascending through the arc");
                break;
            }
        }
        assert!(crossed);
    }
    #[test]
    fn arc_is_consistent_at_different_fixed_steps() {
        let t = Tuning::default();
        let a = Arena::default();
        let i = Intent {
            swing: true,
            movement: Vec2::Y,
            forward: Vec3::NEG_Z,
            right: Vec3::X,
            ..default()
        };
        let mut fast = Hero::default();
        let mut slow = fast.clone();
        for _ in 0..240 {
            fast.step(i, &a.0, &t, 1. / 120.);
        }
        for _ in 0..120 {
            slow.step(i, &a.0, &t, 1. / 60.);
        }
        assert!(
            fast.pos.distance(slow.pos) < 0.5,
            "positions {} / {}",
            fast.pos,
            slow.pos
        );
        assert!(fast.velocity.distance(slow.velocity) < 0.5);
    }
    #[test]
    fn high_speed_collisions_do_not_enter_towers() {
        let t = Tuning::default();
        let arena = Arena::default();
        let mut h = Hero::default();
        h.pos = Vec3::new(-27., 22., 1.);
        h.velocity = Vec3::NEG_Z * 80.;
        for _ in 0..90 {
            h.step(Intent::default(), &arena.0, &t, DT);
            assert!(arena.0.towers.iter().all(|b| !b.contains(h.pos, -0.005)));
        }
    }
    #[test]
    fn dive_releases_a_held_line() {
        let t = Tuning::default();
        let a = Arena::default();
        let mut h = Hero::default();
        h.step(
            Intent {
                swing: true,
                forward: Vec3::NEG_Z,
                ..default()
            },
            &a.0,
            &t,
            DT,
        );
        assert!(h.rope.is_some());
        h.step(
            Intent {
                swing: true,
                dive: true,
                ..default()
            },
            &a.0,
            &t,
            DT,
        );
        assert!(h.rope.is_none());
        assert_eq!(h.mode, Mode::Dive);
    }
    #[test]
    fn holding_swing_selects_successive_lines() {
        let t = Tuning::default();
        let a = Arena::default();
        let mut h = Hero::default();
        for _ in 0..1600 {
            h.step(
                Intent {
                    swing: true,
                    movement: Vec2::Y,
                    forward: Vec3::NEG_Z,
                    right: Vec3::X,
                    ..default()
                },
                &a.0,
                &t,
                DT,
            );
        }
        assert!(
            h.swing_count >= 3,
            "held swing should continue down the street: {}",
            h.swing_count
        );
        assert!(h.pos.z < -100., "forward progress: {}", h.pos.z);
    }
    #[test]
    fn wall_run_stays_in_contact_and_wall_jump_detaches() {
        let t = Tuning::default();
        let a = Arena::default();
        let mut h = Hero::default();
        h.pos = Vec3::new(-16.5, 20., -20.);
        h.previous = h.pos;
        h.velocity = Vec3::NEG_X * 12.;
        h.step(
            Intent {
                swing: true,
                ..default()
            },
            &a.0,
            &t,
            DT,
        );
        assert_eq!(h.mode, Mode::Wall);
        for _ in 0..45 {
            h.step(
                Intent {
                    swing: true,
                    ..default()
                },
                &a.0,
                &t,
                DT,
            );
        }
        assert_eq!(h.mode, Mode::Wall);
        assert!(h.pos.y > 24.);
        h.step(
            Intent {
                swing: true,
                jump: true,
                ..default()
            },
            &a.0,
            &t,
            DT,
        );
        assert_eq!(h.mode, Mode::Air);
        assert!(h.velocity.x > 0.);
    }
    #[test]
    fn long_traversal_is_finite_and_contacts_floor() {
        let t = Tuning::default();
        let a = Arena::default();
        let mut h = Hero::default();
        for frame in 0..12000 {
            let i = Intent {
                movement: Vec2::Y,
                forward: Vec3::NEG_Z,
                right: Vec3::X,
                swing: frame % 240 < 190,
                jump: frame % 240 == 189,
                dive: frame % 500 > 460,
                ..default()
            };
            h.step(i, &a.0, &t, DT);
            assert!(h.pos.is_finite());
            assert!(h.velocity.is_finite());
            assert!(h.pos.y >= FOOT - 0.01);
        }
    }
    // The swing, swing jump and fall are the game's (crates/sm_traversal checks them against Spider-Man.exe's code);
    // these check the sandbox's hookup: the swing point, the inputs, collisions and hand-overs.
    #[test]
    fn swing_point_is_ahead_of_travel_in_every_direction() {
        let towers = direction_fixture();
        for direction in [Vec3::NEG_Z, Vec3::Z, Vec3::X, Vec3::NEG_X] {
            let pos = Vec3::new(0., 18., 0.);
            // the camera and the stick point back: the swing still goes where he travels
            let p = traversal::find_swing_point(pos, direction * 24., Vec3::ZERO, -direction, &towers)
                .expect("a surface ahead");
            assert!(
                (p.attach - pos).with_y(0.).normalize().dot(direction) > 0.9,
                "direction={direction:?}, point={p:?}"
            );
            assert!(towers.towers.iter().any(|t| t.contains(p.attach, 0.01)));
            assert!(p.attach.y - pos.y >= 8.);
        }
    }
    #[test]
    fn slow_travel_aims_where_the_camera_looks() {
        let towers = direction_fixture();
        let pos = Vec3::new(0., 18., 0.);
        let p = traversal::find_swing_point(pos, Vec3::new(0.01, -30., 0.01), Vec3::ZERO, Vec3::X, &towers)
            .expect("the camera's way");
        assert!(p.attach.x >= 19.99, "{p:?}");
    }
    #[test]
    fn buildings_behind_travel_get_no_web() {
        let t = Tuning::default();
        let towers = World::boxes(&[Tower {
            center: Vec3::new(-24., 45., 0.),
            half: Vec3::new(4., 45., 4.),
        }]);
        let mut h = Hero::default();
        h.pos = Vec3::new(0., 18., 0.);
        h.velocity = Vec3::X * 24.;
        assert!(traversal::find_swing_point(h.pos, h.velocity, Vec3::ZERO, Vec3::NEG_X, &towers).is_none());
        h.step(
            Intent {
                swing: true,
                movement: Vec2::Y,
                forward: Vec3::NEG_X,
                ..default()
            },
            &towers,
            &t,
            DT,
        );
        assert!(h.rope.is_none());
        assert!(h.velocity.x > 23.);
    }
    #[test]
    fn arena_offers_a_swing_point_from_the_start() {
        let arena = Arena::default();
        assert_eq!(arena.0.towers.len(), 7);
        let h = Hero::default();
        let p = traversal::find_swing_point(h.pos, h.velocity, Vec3::ZERO, Vec3::NEG_Z, &arena.0)
            .expect("initial swing point");
        assert!(arena.0.towers.iter().any(|b| b.contains(p.attach, 0.01)));
        assert!(p.attach.y > h.pos.y + 8.);
    }
    #[test]
    fn held_swing_lets_go_by_itself_and_travels_on() {
        let t = Tuning::default();
        let a = Arena::default();
        let mut h = Hero::default();
        let mut released = false;
        for _ in 0..960 {
            let swinging = h.rope.is_some();
            h.step(forward_swing(), &a.0, &t, DT);
            released |= swinging && h.rope.is_none() && h.mode == Mode::Air;
        }
        assert!(released, "the held swing never let go");
        assert!(h.swing_count >= 2 && h.pos.z < -60., "{} swings, at {:?}", h.swing_count, h.pos);
    }
    #[test]
    fn the_fall_steers_toward_the_stick_without_lift() {
        let t = Tuning::default();
        for speed in [16., 40.] {
            let mut h = Hero::default();
            h.pos = Vec3::new(0., 300., 0.);
            h.velocity = Vec3::new(0., -10., -speed);
            let mut neutral = h.clone();
            let input = Intent {
                movement: Vec2::X,
                forward: Vec3::NEG_Z,
                right: Vec3::X,
                ..default()
            };
            for _ in 0..120 {
                h.step(input, &World::default(), &t, DT);
                neutral.step(Intent::default(), &World::default(), &t, DT);
            }
            assert!(h.native.active() && h.mode == Mode::Air);
            assert!(h.velocity.x > 2., "no steering at {speed} m/s: {:?}", h.velocity);
            assert!(neutral.velocity.x.abs() < 0.01);
            assert!((h.pos.y - neutral.pos.y).abs() < 0.001, "steering changed the fall");
        }
    }
    #[test]
    fn falling_from_rest_builds_movement_toward_the_stick() {
        let t = Tuning::default();
        let mut h = Hero::default();
        h.pos = Vec3::new(0., 200., 0.);
        h.velocity = Vec3::ZERO;
        let input = Intent {
            movement: Vec2::X,
            forward: Vec3::NEG_Z,
            right: Vec3::X,
            ..default()
        };
        for _ in 0..120 {
            h.step(input, &World::default(), &t, DT);
        }
        assert!(h.velocity.x > 1. && h.pos.x > 0.5, "{:?}", h.velocity);
        // the game's fall gravity: 26 m/s^2, growing by 3 m/s per second
        assert!(h.velocity.y < -24. && h.velocity.y > -32., "{:?}", h.velocity);
    }
    #[test]
    fn swinging_down_the_street_stays_out_of_the_towers() {
        let t = Tuning::default();
        let a = Arena::default();
        let mut h = Hero::default();
        for _ in 0..1600 {
            h.step(forward_swing(), &a.0, &t, DT);
            assert!(a.0.towers.iter().all(|b| !b.contains(h.pos, -0.01)), "inside a tower at {:?}", h.pos);
        }
        assert!(h.swing_count >= 3, "{} swings", h.swing_count);
        assert!(h.pos.z < -120., "{:?}", h.pos);
    }
}
