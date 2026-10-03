//! Small scalar helpers shared by the sandbox's own movement. The game's swing, swing jump and fall live in
//! crates/sm_traversal (a full port checked against the executable); the partial equations that used to be here were
//! superseded by it.
use bevy::prelude::*;

/// clamp((x - min) / (max - min)), with the game's rule for an empty range: 0 below, 1 above, 0.5 on it
pub fn remap(x: f32, min: f32, max: f32) -> f32 {
    if (max - min).abs() < 1e-4 {
        return if x < min {
            0.
        } else if x > min {
            1.
        } else {
            0.5
        };
    }
    ((x - min) / (max - min)).clamp(0., 1.)
}
pub fn mix(a: f32, b: f32, x: f32) -> f32 {
    a + (b - a) * x
}
/// Degrees above the horizontal
pub fn pitch(velocity: Vec3) -> f32 {
    velocity.y.atan2(velocity.with_y(0.).length()).to_degrees()
}
