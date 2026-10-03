//! Interpolate fixed simulation snapshots on the render clock.
use crate::physics::Hero;
use bevy::prelude::*;
#[derive(Resource)]
pub struct Snapshots {
    previous: Hero,
    current: Hero,
    elapsed: f64,
    valid: bool,
}
impl Default for Snapshots {
    fn default() -> Self {
        Self {
            previous: Hero::default(),
            current: Hero::default(),
            elapsed: 0.,
            valid: false,
        }
    }
}
impl Snapshots {
    pub fn capture(&mut self, before: &Hero, after: &Hero, elapsed: f64, reset: bool) {
        let teleported = reset
            || before.pos.distance(after.pos) > 8.
            || (self.valid && before.pos.distance(self.current.pos) > 8.);
        self.previous = if teleported {
            after.clone()
        } else {
            before.clone()
        };
        self.current = after.clone();
        self.elapsed = elapsed;
        self.valid = true;
    }
    pub fn sample(&self, alpha: f32, elapsed: f64) -> Option<Hero> {
        // A skipped simulation tick must not replay an old segment while loading/paused.
        if !self.valid || (elapsed - self.elapsed).abs() > 0.000001 {
            return None;
        }
        let alpha = alpha.clamp(0., 1.);
        let mut hero = self.current.clone();
        hero.pos = self.previous.pos.lerp(self.current.pos, alpha);
        hero.velocity = self.previous.velocity.lerp(self.current.velocity, alpha);
        let heading = self
            .previous
            .heading
            .lerp(self.current.heading, alpha)
            .normalize_or_zero();
        if heading.length_squared() > 0.1 {
            hero.heading = heading;
        }
        let timer = |old: f32, new: f32| {
            if new >= old {
                old + (new - old) * alpha
            } else {
                new
            }
        };
        if self.previous.mode == self.current.mode {
            hero.mode_age = timer(self.previous.mode_age, self.current.mode_age);
        }
        hero.last_swing = timer(self.previous.last_swing, self.current.last_swing);
        hero.last_ground_jump = timer(
            self.previous.last_ground_jump,
            self.current.last_ground_jump,
        );
        if self.previous.swing_count == self.current.swing_count {
            hero.swing_phase = self.previous.swing_phase
                + (self.current.swing_phase - self.previous.swing_phase) * alpha;
        }
        Some(hero)
    }
}
#[derive(Resource)]
pub struct RenderedHero {
    pub hero: Hero,
    pub interpolated: bool,
    pub offset: f32,
}
impl Default for RenderedHero {
    fn default() -> Self {
        Self {
            hero: Hero::default(),
            interpolated: false,
            offset: 0.,
        }
    }
}
pub fn update_render(
    hero: Res<Hero>,
    snapshots: Res<Snapshots>,
    fixed: Res<Time<Fixed>>,
    mut rendered: ResMut<RenderedHero>,
) {
    let sample = snapshots.sample(fixed.overstep_fraction(), fixed.elapsed_secs_f64());
    rendered.interpolated = sample.is_some();
    rendered.hero = sample.unwrap_or_else(|| hero.clone());
    rendered.offset = rendered.hero.pos.distance(hero.pos);
}
#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn constant_travel_is_uniform_across_mismatched_render_and_physics_rates() {
        let physics_dt = 1. / 120.;
        let velocity = Vec3::new(12., 5., -40.);
        for fps in [60., 75., 144., 240.] {
            let mut hero = Hero::default();
            hero.pos = Vec3::ZERO;
            hero.velocity = velocity;
            let mut snapshots = Snapshots::default();
            let mut physics_time = 0.;
            let mut previous: Option<Vec3> = None;
            for frame in 1..=240 {
                let render_time = frame as f64 / fps;
                while physics_time + physics_dt <= render_time + 1e-10 {
                    let before = hero.clone();
                    hero.pos += velocity * physics_dt as f32;
                    physics_time += physics_dt;
                    snapshots.capture(&before, &hero, physics_time, false);
                }
                let alpha = ((render_time - physics_time) / physics_dt) as f32;
                if let Some(sample) = snapshots.sample(alpha, physics_time) {
                    if let Some(last) = previous {
                        let measured = (sample.pos - last) * fps as f32;
                        assert!(
                            measured.distance(velocity) < 0.004,
                            "fps={fps} measured={measured:?}"
                        );
                    }
                    previous = Some(sample.pos);
                }
            }
        }
    }
    #[test]
    fn resets_and_paused_ticks_do_not_show_old_motion() {
        let mut before = Hero::default();
        let mut after = before.clone();
        let mut s = Snapshots::default();
        after.pos += Vec3::NEG_Z;
        s.capture(&before, &after, 1., false);
        assert!(s.sample(0.5, 1. + 1. / 120.).is_none());
        before = after;
        after = Hero::default();
        s.capture(&before, &after, 2., true);
        assert!(s.sample(0.1, 2.).unwrap().pos.distance(after.pos) < 0.001);
        before = after.clone();
        before.pos += Vec3::Y * 50.;
        after = before.clone();
        after.pos += Vec3::NEG_Z;
        s.capture(&before, &after, 3., false);
        assert!(s.sample(0.1, 3.).unwrap().pos.distance(after.pos) < 0.001);
    }
    #[test]
    fn release_timers_reset_immediately_and_then_advance_smoothly() {
        let before = Hero::default();
        let mut after = before.clone();
        after.last_swing = 0.;
        let mut s = Snapshots::default();
        s.capture(&before, &after, 1., false);
        assert_eq!(s.sample(0.2, 1.).unwrap().last_swing, 0.);
        let before = after.clone();
        after.last_swing = 1. / 120.;
        s.capture(&before, &after, 2., false);
        assert!((s.sample(0.5, 2.).unwrap().last_swing - 1. / 240.).abs() < 0.00001);
    }
}
