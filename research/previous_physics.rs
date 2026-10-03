//! Traversal simulation. Values are read from the installed game's decoded configs.
//! The integration, collisions and state transitions are an independent Rust implementation.
use bevy::prelude::*;
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
#[derive(Resource)]
pub struct Arena(pub Vec<Tower>);
impl Default for Arena {
    fn default() -> Self {
        // Seven gray cuboids, placed to make a continuous loop of swingable streets.
        Self(vec![
            Tower {
                center: Vec3::new(-27., 28., -20.),
                half: Vec3::new(10., 28., 11.),
            },
            Tower {
                center: Vec3::new(26., 35., -43.),
                half: Vec3::new(10., 35., 12.),
            },
            Tower {
                center: Vec3::new(-26., 43., -82.),
                half: Vec3::new(11., 43., 11.),
            },
            Tower {
                center: Vec3::new(28., 32., -122.),
                half: Vec3::new(11., 32., 12.),
            },
            Tower {
                center: Vec3::new(-26., 38., -163.),
                half: Vec3::new(12., 38., 11.),
            },
            Tower {
                center: Vec3::new(28., 46., -198.),
                half: Vec3::new(12., 46., 12.),
            },
            Tower {
                center: Vec3::new(-23., 31., -235.),
                half: Vec3::new(12., 31., 12.),
            },
        ])
    }
}

#[derive(Resource, Clone)]
pub struct Tuning {
    pub gravity_down: f32,
    pub gravity_up: f32,
    pub gravity_hold: f32,
    pub max_speed: f32,
    pub pure_max: f32,
    pub acceleration: f32,
    pub search_radius: f32,
    pub ideal_length: f32,
    pub min_length: f32,
    pub max_length: f32,
    pub release_low: f32,
    pub release_mid: f32,
    pub release_high: f32,
    pub jump_low: f32,
    pub jump_mid: f32,
    pub jump_high: f32,
    pub jump_gravity_low: f32,
    pub jump_gravity_mid: f32,
    pub jump_gravity_high: f32,
}
impl Default for Tuning {
    fn default() -> Self {
        let v: Value = serde_json::from_str(include_str!(
            "../assets/tuning/hero_swingsetup_standard.json"
        ))
        .unwrap();
        let value = |path: &str| v.pointer(path).and_then(Value::as_f64).unwrap() as f32;
        Self {
            gravity_down: value("/MotionParams/GravityParams/GravityFallInit"),
            gravity_up: value("/MotionParams/GravityParams/RiseGravityHighMax"),
            gravity_hold: value("/MotionParams/GravityParams/GravityFallHold"),
            max_speed: value("/MotionParams/SpeedParams/TerminalVelocityHorzMax"),
            pure_max: value("/MotionParams/SpeedParams/TerminalVelocityPureMax"),
            acceleration: value("/MotionParams/SpeedParams/SpeedBoostAccel"),
            search_radius: value("/SearchParams/BroadSearchRadius"),
            ideal_length: value("/SearchParams/IdealLineLengthForward"),
            min_length: value("/MotionParams/GravityParams/RiseLineLengthMin"),
            max_length: value("/MotionParams/GravityParams/RiseLineLengthMax"),
            release_low: value("/ReleaseParams/ReleaseGravityData/GravityReleaseLow"),
            release_mid: value("/ReleaseParams/ReleaseGravityData/GravityReleaseMid"),
            release_high: value("/ReleaseParams/ReleaseGravityData/GravityReleaseHigh"),
            jump_low: value("/ReleaseParams/ParamsLow/VertFloorJump"),
            jump_mid: value("/ReleaseParams/ParamsMiddle/VertFloorJump"),
            jump_high: value("/ReleaseParams/ParamsHigh/VertFloorJump"),
            jump_gravity_low: value("/ReleaseParams/ReleaseGravityData/GravityJumpLow"),
            jump_gravity_mid: value("/ReleaseParams/ReleaseGravityData/GravityJumpMid"),
            jump_gravity_high: value("/ReleaseParams/ReleaseGravityData/GravityJumpHigh"),
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
        }
    }
}
#[derive(Clone, Copy, Debug)]
pub struct Rope {
    pub anchor: Vec3,
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
    pub zip_target: Option<Vec3>,
    pub release_variant: usize,
    pub boosted_release: bool,
    pub peak_speed: f32,
    pub max_rope_error: f32,
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
            release_gravity: 23.,
            swing_count: 0,
            last_swing: 999.,
            jump_buffer: 0.,
            coyote: 0.,
            cooldown: 0.,
            zip_target: None,
            release_variant: 0,
            boosted_release: false,
            peak_speed: 0.,
            max_rope_error: 0.,
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
    pub dive: bool,
    pub zip: bool,
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

pub fn anchor_for(hero: &Hero, forward: Vec3, towers: &[Tower], tuning: &Tuning) -> Option<Vec3> {
    let direction = forward.with_y(0.).normalize_or_zero();
    let mut result = None;
    let mut best = f32::NEG_INFINITY;
    for tower in towers {
        let min = tower.min();
        let max = tower.max();
        // Candidate points are on the tower surface. Their elevation follows the hero.
        let height = (hero.pos.y + 24.).clamp(9., max.y - 0.5);
        for dx in [-1., 0., 1.] {
            for dz in [-1., 0., 1.] {
                if dx == 0. && dz == 0. {
                    continue;
                }
                let p = Vec3::new(
                    (hero.pos.x + direction.x * 20.).clamp(min.x + 0.3, max.x - 0.3),
                    height,
                    (hero.pos.z + direction.z * 22.).clamp(min.z + 0.3, max.z - 0.3),
                );
                let p = Vec3::new(
                    if dx < 0. {
                        min.x
                    } else if dx > 0. {
                        max.x
                    } else {
                        p.x
                    },
                    height,
                    if dz < 0. {
                        min.z
                    } else if dz > 0. {
                        max.z
                    } else {
                        p.z
                    },
                );
                let delta = p - hero.pos;
                let length = delta.length();
                if length > tuning.search_radius || length < 9. || delta.y < 6. {
                    continue;
                }
                let alignment = delta.with_y(0.).normalize_or_zero().dot(direction);
                if alignment < -0.30 {
                    continue;
                }
                // Reject a candidate obscured by the same tower or another tower.
                if towers
                    .iter()
                    .any(|t| ray_box(hero.pos, delta / length, *t, length - 0.15).is_some())
                {
                    continue;
                }
                let score =
                    alignment * 22. - (length - tuning.ideal_length).abs() * 0.28 + delta.y * 0.08;
                if score > best {
                    best = score;
                    result = Some(p);
                }
            }
        }
    }
    result
}

impl Hero {
    fn set_mode(&mut self, mode: Mode) {
        if self.mode != mode {
            self.mode = mode;
            self.mode_age = 0.;
        }
    }
    fn release(&mut self, boosted: bool, tuning: &Tuning) {
        if self.rope.take().is_none() {
            return;
        }
        self.release_variant = (self.swing_count as usize) % 3;
        let rise = self.velocity.y;
        self.release_gravity = if rise > 10. {
            tuning.release_high
        } else if rise < -8. {
            tuning.release_low
        } else {
            tuning.release_mid
        };
        self.boosted_release = boosted;
        if boosted {
            self.release_gravity = if rise > 10. {
                tuning.jump_gravity_high
            } else if rise < -8. {
                tuning.jump_gravity_low
            } else {
                tuning.jump_gravity_mid
            };
            let floor = if rise > 10. {
                tuning.jump_high
            } else if rise < -8. {
                tuning.jump_low
            } else {
                tuning.jump_mid
            };
            self.velocity.y = self.velocity.y.max(floor);
            self.velocity += self.heading * 1.5;
        }
        self.set_mode(Mode::Air);
        self.cooldown = 0.2;
        self.last_swing = 0.;
    }
    pub fn step(&mut self, input: Intent, towers: &[Tower], tuning: &Tuning, dt: f32) {
        if input.reset {
            *self = Self::default();
            return;
        }
        self.previous = self.pos;
        self.mode_age += dt;
        self.last_swing += dt;
        self.cooldown = (self.cooldown - dt).max(0.);
        self.coyote = (self.coyote - dt).max(0.);
        if input.jump {
            self.jump_buffer = 0.14;
        } else {
            self.jump_buffer = (self.jump_buffer - dt).max(0.);
        }
        let wish = (input.forward * input.movement.y + input.right * input.movement.x)
            .with_y(0.)
            .normalize_or_zero();
        if wish.length_squared() > 0.1 {
            self.heading = self
                .heading
                .lerp(wish, 1. - (-8. * dt).exp())
                .normalize_or_zero();
        }
        if self.heading.length_squared() < 0.1 {
            self.heading = Vec3::NEG_Z;
        }
        if self.rope.is_some() && (!input.swing || self.jump_buffer > 0. || input.dive) {
            self.release(self.jump_buffer > 0., tuning);
            self.jump_buffer = 0.;
        }
        // Holding swing advances to a new line after the rising part of the arc.
        if let Some(rope) = self.rope {
            let passed = (self.pos - rope.anchor).with_y(0.).dot(self.heading);
            if rope.age > 0.65 && ((passed > 5. && self.velocity.y > 1.) || rope.age > 3.2) {
                self.release(false, tuning);
            }
        }
        if self.mode == Mode::Wall && self.jump_buffer > 0. {
            self.velocity = self.wall_normal * 12. + self.heading * 9. + Vec3::Y * 20.;
            self.set_mode(Mode::Air);
            self.jump_buffer = 0.;
            self.cooldown = 0.3;
        } else if self.mode == Mode::Ground && self.jump_buffer > 0. {
            self.velocity.y = 21.;
            self.set_mode(Mode::Air);
            self.jump_buffer = 0.;
            self.coyote = 0.;
        }
        if input.swing
            && !input.dive
            && self.rope.is_none()
            && self.mode != Mode::Wall
            && self.cooldown <= 0.
        {
            let forward = if wish.length_squared() > 0.1 {
                wish
            } else {
                self.heading
            };
            if let Some(anchor) = anchor_for(self, forward, towers, tuning) {
                let length = anchor.distance(self.pos).max(tuning.min_length * 0.6);
                self.swing_count += 1;
                self.rope = Some(Rope {
                    anchor,
                    length,
                    age: 0.,
                });
                self.set_mode(Mode::Swing);
                self.zip_target = None;
                if self.pos.y < 4. {
                    self.velocity.y = self.velocity.y.max(16.);
                }
                let speed = self.velocity.with_y(0.).length();
                if speed < 14. {
                    self.velocity += forward * (14. - speed);
                }
            }
        }
        if input.zip && self.rope.is_none() {
            if let Some(anchor) = anchor_for(self, self.heading, towers, tuning) {
                self.zip_target = Some(anchor);
                self.set_mode(Mode::Zip);
            }
        }
        if self.zip_target.is_some() && self.mode == Mode::Zip {
            let target = self.zip_target.unwrap();
            let delta = target - self.pos;
            if delta.length() < 3. || self.mode_age > 1.4 {
                self.zip_target = None;
                self.velocity = self.heading * 23. + Vec3::Y * 12.;
                self.set_mode(Mode::Air);
            } else {
                self.velocity = self
                    .velocity
                    .lerp(delta.normalize() * 42., 1. - (-12. * dt).exp());
            }
        } else if let Some(mut rope) = self.rope {
            rope.age += dt;
            let radial = (self.pos - rope.anchor).normalize_or_zero();
            let gravity = if self.velocity.y > 0. {
                tuning.gravity_up
            } else if rope.age > 2. {
                tuning.gravity_hold
            } else {
                tuning.gravity_down
            };
            let direction = if wish.length_squared() > 0.1 {
                wish
            } else {
                self.heading
            };
            let tangent = (direction - radial * direction.dot(radial)).normalize_or_zero();
            let speed = self.velocity.with_y(0.).length();
            let assist = (1. - speed / tuning.max_speed).clamp(0., 1.) * tuning.acceleration;
            self.velocity += (Vec3::Y * gravity + tangent * assist + wish * 10.) * dt;
            // Raise a very low arc before impact, with an elevated real anchor.
            let clearance = self.pos.y - FOOT;
            if clearance < 4. && self.velocity.y < 0. {
                self.velocity.y += (4. - clearance) * 19. * dt;
                rope.length = (rope.length - 10. * dt).max(rope.anchor.y - 4.);
            }
            if input.dive {
                rope.length = (rope.length + 8. * dt).min(tuning.max_length);
            }
            self.rope = Some(rope);
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
                -42.
            } else {
                -self.release_gravity
            };
            self.velocity += (Vec3::Y * gravity + wish * 7.) * dt;
            if input.dive {
                self.velocity += self.heading * 6. * dt;
            }
            self.velocity *= 1. - 0.015 * dt;
        }
        let horizontal = self.velocity.with_y(0.);
        let hspeed = horizontal.length();
        if hspeed > tuning.max_speed {
            self.velocity -= horizontal * (1. - tuning.max_speed / hspeed);
        }
        self.velocity = self.velocity.clamp_length_max(tuning.pure_max);
        let next = self.pos + self.velocity * dt;
        self.pos = next;
        if let Some(rope) = self.rope {
            let delta = self.pos - rope.anchor;
            let length = delta.length();
            if length > rope.length {
                let radial = delta / length;
                self.pos = rope.anchor + radial * rope.length;
                let outward = self.velocity.dot(radial);
                if outward > 0. {
                    self.velocity -= radial * outward;
                }
            }
            self.max_rope_error = self
                .max_rope_error
                .max((self.pos.distance(rope.anchor) - rope.length).max(0.));
        }
        self.collide(towers, input, dt);
        if self.mode != Mode::Ground {
            self.airborne += dt;
        } else {
            self.airborne = 0.;
        }
        self.peak_speed = self.peak_speed.max(self.velocity.length());
        if !self.pos.is_finite() || self.pos.y < -20. || self.pos.length() > 2000. {
            *self = Self::default();
        }
    }
    fn collide(&mut self, towers: &[Tower], input: Intent, dt: f32) {
        let mut floor = FOOT;
        self.wall_normal = Vec3::ZERO;
        for tower in towers {
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
        if self.pos.y <= floor && self.velocity.y <= 0. {
            self.pos.y = floor;
            self.velocity.y = 0.;
            self.rope = None;
            self.zip_target = None;
            self.set_mode(Mode::Ground);
            self.coyote = 0.12;
        } else if self.mode == Mode::Ground {
            self.set_mode(Mode::Air);
        }
        if self.mode == Mode::Wall && self.wall_normal == Vec3::ZERO {
            self.velocity.y -= 24. * dt;
            self.set_mode(Mode::Air);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn arena_has_seven_towers_and_surface_anchors() {
        let arena = Arena::default();
        assert_eq!(arena.0.len(), 7);
        let h = Hero::default();
        let t = Tuning::default();
        let a = anchor_for(&h, Vec3::NEG_Z, &arena.0, &t).expect("initial swing target");
        assert!(arena.0.iter().any(|b| b.contains(a, 0.001)));
        assert!(a.y > h.pos.y && a.distance(h.pos) <= t.search_radius);
    }
    #[test]
    fn rope_constraint_holds_and_release_preserves_momentum() {
        let t = Tuning::default();
        let mut h = Hero::default();
        let a = Vec3::new(0., 50., -12.);
        h.rope = Some(Rope {
            anchor: a,
            length: a.distance(h.pos),
            age: 0.,
        });
        h.mode = Mode::Swing;
        let i = Intent {
            swing: true,
            forward: Vec3::NEG_Z,
            ..default()
        };
        for _ in 0..100 {
            h.step(i, &[], &t, DT);
            assert!(h.pos.distance(a) <= h.rope.unwrap().length + 0.002);
            assert!(h.pos.is_finite());
        }
        let before = h.velocity;
        h.step(
            Intent {
                swing: false,
                ..default()
            },
            &[],
            &t,
            DT,
        );
        assert!(h.rope.is_none());
        assert!((h.velocity - before).length() < 1.);
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
            assert!(arena.0.iter().all(|b| !b.contains(h.pos, -0.005)));
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
}
