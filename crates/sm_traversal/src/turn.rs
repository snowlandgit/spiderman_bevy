//! How Spider-Man's mover turns him toward the facing his state asks for (MoverStandard, exe+1fc0800 -> exe+1c46d50 ->
//! exe+1c46be0). The constants are set by each state on entry (exe+1fc3540). Ported from ArkWeb's turn.h, which
//! predicts the recorded turns to 0.03 degrees a frame.
use crate::math::{acos, rotate, spring, wrap_pi, V3};

/// (gain, damping, maximum rate in rad/s)
pub type TurnConstants = [f32; 3];
/// the swing (its processor, exe+ab2af0): 240 degrees per second at most
pub const SWING: TurnConstants = [-1.42, -44.0, 4.18879];
/// the swing jump (exe+a7d260, jump type 0x11)
pub const SWING_JUMP: TurnConstants = [-1.2, -33.0, 7.85398];
/// other jumps and the fall's default (exe+a6f930)
pub const FALL: TurnConstants = [-1.18, -18.0, 10.472];

/// exe+1fc34b0: the facing a state asks for, if usable
pub fn want_facing(f: V3) -> Option<V3> {
    if !f.is_finite() || !(f.x.abs() > 0.001 || f.y.abs() > 0.001 || f.z.abs() > 0.001) {
        return None;
    }
    let n = f.norm();
    (n.max_abs() > 0.).then_some(n)
}

/// One frame of the turn: `fwd` turned about `up` toward `want` (both taken flat), `v` the angular velocity carried
/// between frames. Returns the new forward.
pub fn step(fwd: V3, up: V3, want: V3, v: &mut f32, k: TurnConstants, snap: bool, dt: f32) -> V3 {
    let flat = |a: V3| a - up * a.dot(up);
    let mut w = flat(want);
    if w == V3::ZERO {
        w.y = 1.;
    }
    let w = w.norm();
    let f = flat(fwd).norm();
    let angle = acos(f.dot(w).clamp(-1., 1.));
    if snap || angle <= 0.005 {
        *v = 0.;
        return w;
    }
    let axis = f.cross(w).norm();
    let sign = if axis.dot(up) >= 0. { 1. } else { -1. };
    let target = (sign * angle).min(3.11018);
    let d = wrap_pi(target);
    let s = wrap_pi(spring(0., d, v, k[0], k[1], k[2], dt));
    rotate(fwd, up.norm(), s)
}
