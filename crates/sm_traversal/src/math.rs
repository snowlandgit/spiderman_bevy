//! Vector and scalar helpers as Spider-Man.exe 4.0630 computes them (RVAs in the comments). Vectors are normalized the
//! way the game does: scaled by their largest component first, then by their length; a zero vector stays as it is.
use std::ops::{Add, AddAssign, Mul, Neg, Sub, SubAssign};

#[derive(Clone, Copy, Debug, Default, PartialEq)]
pub struct V3 {
    pub x: f32,
    pub y: f32,
    pub z: f32,
}

impl V3 {
    pub const ZERO: V3 = V3::new(0., 0., 0.);
    pub const UP: V3 = V3::new(0., 1., 0.);
    pub const fn new(x: f32, y: f32, z: f32) -> Self {
        Self { x, y, z }
    }
    pub fn from_slice(a: &[f32]) -> Self {
        Self::new(a[0], a[1], a[2])
    }
    pub fn to_array(self) -> [f32; 3] {
        [self.x, self.y, self.z]
    }
    pub fn dot(self, o: V3) -> f32 {
        self.x * o.x + self.y * o.y + self.z * o.z
    }
    pub fn cross(self, o: V3) -> V3 {
        V3::new(
            self.y * o.z - self.z * o.y,
            self.z * o.x - self.x * o.z,
            self.x * o.y - self.y * o.x,
        )
    }
    pub fn max_abs(self) -> f32 {
        self.z.abs().max(self.y.abs()).max(self.x.abs())
    }
    /// exe+2c2450
    pub fn len(self) -> f32 {
        let m = self.max_abs();
        if !(m > 0.) {
            return 0.;
        }
        let s = 1. / m;
        let (a, b, c) = (self.x * s, self.y * s, self.z * s);
        (b * b + a * a + c * c).sqrt() * m
    }
    /// exe+2d0740: unchanged when zero
    pub fn norm(self) -> V3 {
        let m = self.max_abs();
        if !(m > 0.) {
            return self;
        }
        let s = 1. / m;
        let v = V3::new(self.x * s, self.y * s, self.z * s);
        let l = 1. / (v.y * v.y + v.x * v.x + v.z * v.z).sqrt();
        V3::new(v.x * l, v.y * l, v.z * l)
    }
    /// The x/z part (y = 0)
    pub fn flat(self) -> V3 {
        V3::new(self.x, 0., self.z)
    }
    /// exe+3e3f30
    pub fn flat_len(self) -> f32 {
        let m = self.x.abs().max(self.z.abs());
        if !(m > 0.) {
            return 0.;
        }
        let (a, c) = (self.x * (1. / m), self.z * (1. / m));
        (c * c + a * a).sqrt() * m
    }
    /// The x/z direction, normalized as the game does it inline (zero stays zero)
    pub fn flat_norm(self) -> V3 {
        let (mut x, mut z) = (self.x, self.z);
        let m = z.abs().max(0.).max(x.abs());
        if m > 0. {
            z *= 1. / m;
            x *= 1. / m;
            let l = 1. / (z * z + x * x).sqrt();
            z *= l;
            x *= l;
        }
        V3::new(x, 0., z)
    }
    /// v scaled to length `l` along its direction, zero when it has none (the "/ sqrt(len^2) if >= 1e-15" pattern)
    pub fn with_len(self, l: f32) -> V3 {
        let d = self.dot(self);
        if d >= 1e-15 {
            self * (l / d.sqrt())
        } else {
            V3::ZERO
        }
    }
    pub fn is_finite(self) -> bool {
        self.x.is_finite() && self.y.is_finite() && self.z.is_finite()
    }
}
impl Add for V3 {
    type Output = V3;
    fn add(self, o: V3) -> V3 {
        V3::new(self.x + o.x, self.y + o.y, self.z + o.z)
    }
}
impl Sub for V3 {
    type Output = V3;
    fn sub(self, o: V3) -> V3 {
        V3::new(self.x - o.x, self.y - o.y, self.z - o.z)
    }
}
impl Mul<f32> for V3 {
    type Output = V3;
    fn mul(self, s: f32) -> V3 {
        V3::new(self.x * s, self.y * s, self.z * s)
    }
}
impl Neg for V3 {
    type Output = V3;
    fn neg(self) -> V3 {
        V3::new(-self.x, -self.y, -self.z)
    }
}
impl AddAssign for V3 {
    fn add_assign(&mut self, o: V3) {
        *self = *self + o;
    }
}
impl SubAssign for V3 {
    fn sub_assign(&mut self, o: V3) {
        *self = *self - o;
    }
}

/// A transform's rows as the game keeps them: side (= up x forward; for a camera it points left), up, forward, position
#[derive(Clone, Copy, Debug, Default, PartialEq)]
pub struct Rows {
    pub side: V3,
    pub up: V3,
    pub fwd: V3,
    pub pos: V3,
}
impl Rows {
    /// Upright, facing `fwd` (flattened)
    pub fn facing(fwd: V3, pos: V3) -> Self {
        let f = fwd.flat_norm();
        Rows { side: V3::UP.cross(f), up: V3::UP, fwd: f, pos }
    }
    pub fn from_matrix(m: &[f32]) -> Self {
        Rows {
            side: V3::from_slice(&m[0..3]),
            up: V3::from_slice(&m[4..7]),
            fwd: V3::from_slice(&m[8..11]),
            pos: V3::from_slice(&m[12..15]),
        }
    }
}

pub const RAD: f32 = 57.29578;
pub const DEG: f32 = 0.01745329;

/// exe+1c58560: atan2(y, x)
pub fn atan2(y: f32, x: f32) -> f32 {
    (y as f64).atan2(x as f64) as f32
}
/// exe+876340: minus the angle of v above the horizontal (radians; negative going up)
pub fn pitch_of(v: V3) -> f32 {
    -atan2(v.y, v.flat_len())
}
/// exe+1c59090: the angle between two unit vectors
pub fn angle_between(a: V3, b: V3) -> f32 {
    (a.dot(b).clamp(-1., 1.) as f64).acos() as f32
}
/// exe+1c58210
pub fn acos(x: f32) -> f32 {
    (x.clamp(-1., 1.) as f64).acos() as f32
}
/// exe+1c58730 / exe+366a0e0
pub fn cos(x: f32) -> f32 {
    (x as f64).cos() as f32
}
/// exe+1c58e50
pub fn sin(x: f32) -> f32 {
    (x as f64).sin() as f32
}
/// exe+3667c70
pub fn exp(x: f32) -> f32 {
    x.exp()
}
/// exe+1c477e0: x moved toward the target by at most rate * dt
pub fn approach(cur: f32, target: f32, rate: f32, dt: f32) -> f32 {
    let step = rate * dt;
    let d = target - cur;
    if d >= 0. {
        cur + d.min(step)
    } else {
        cur - (-d).min(step)
    }
}
/// exe+1c47af0: a point moved toward the target by at most rate * dt
pub fn approach_v(cur: V3, target: V3, rate: f32, dt: f32) -> V3 {
    let d = target - cur;
    let l = d.len();
    let f = if l > 0. { (rate * dt).min(l) / l } else { 0. };
    cur + d * f
}
/// clamp((x - a) / (b - a)); for a degenerate range: 0 below, 1 above, 0.5 on it (the game's inline remap)
pub fn remap(x: f32, a: f32, b: f32) -> f32 {
    let r = b - a;
    if r.abs() <= 0.0001 {
        if a <= x {
            if x <= a { 0.5 } else { 1. }
        } else {
            0.
        }
    } else {
        ((x - a) / r).clamp(0., 1.)
    }
}
/// exe+41c590: clamp((x - a) / (b - a)) (same degenerate rule)
pub fn unlerp(x: f32, a: f32, b: f32) -> f32 {
    remap(x, a, b)
}
pub fn lerp(a: f32, b: f32, t: f32) -> f32 {
    (b - a) * t + a
}
pub fn clamp01(x: f32) -> f32 {
    x.max(0.).min(1.)
}

/// exe+1c46be0: one step of x toward a target. `v` (per second) carries over; a and b are (negative) rates, c caps the
/// speed (none when <= 0); the step never passes the target. (ArkWeb turn.h, validated against recordings.)
pub fn spring(x: f32, target: f32, v: &mut f32, a: f32, b: f32, c: f32, dt: f32) -> f32 {
    if !(dt > 0.) || (x == target && *v == 0.) {
        return x;
    }
    let d = target - x;
    let e = ((b as f64) * 0.033333333333333333).exp().powf(dt as f64);
    let mut s = (((1.0 - e) * (*v as f64)) as f32 + *v) * 0.5 * dt;
    s += (1. - (a * dt).exp()) * d;
    let lim = if c > 0. { c * dt } else { 1e30 };
    let step = s.max(-lim).min(lim);
    let ad = d.abs();
    let step = step.max(-ad).min(ad);
    *v = step / dt;
    x + step
}
/// The nearest whole turn, as exe+1c46d50 rounds
pub fn wrap_pi(a: f32) -> f32 {
    const TWO_PI: f32 = 6.28318548;
    let t = a * 0.159154937 + 0.5;
    if !(t.abs() < 2147483520.) {
        return a;
    }
    let mut f = (t as i32) as f32;
    if f != t && t < 0. {
        f -= 1.;
    }
    a - f * TWO_PI
}

/// exe+1c54e30 + exe+1c5b320: v turned about `axis` by `angle` (radians)
pub fn rotate(v: V3, axis: V3, angle: f32) -> V3 {
    let l = axis.len();
    if !(l > 0.) {
        return v;
    }
    let u = axis * (1. / l);
    let (s, c) = (sin(angle * 0.5), cos(angle * 0.5));
    let q = u * s;
    // v' = v + 2w(q x v) + 2 q x (q x v)
    let t = q.cross(v) * 2.;
    v + t * c + q.cross(t)
}
/// exe+1c5b3e0: from unit a toward unit b by t of the angle between them
pub fn slerp(a: V3, b: V3, t: f32) -> V3 {
    let d = b.dot(a).clamp(-1., 1.);
    let perp = (b - a * d).norm();
    let th = acos(d) * t;
    let (s, c) = (sin(th), cos(th));
    V3::new(c * a.x + perp.x * s, perp.y * s + c * a.y, c * a.z + perp.z * s)
}
/// exe+1c511e0 (the usual case): rows side = up x f, up' = f x side, forward = f
pub fn basis(f: V3, up: V3) -> (V3, V3, V3) {
    let s = up.cross(f).norm();
    (s, f.cross(s), f)
}

/// exe+311350
pub fn dist(a: V3, b: V3) -> f32 {
    (a - b).len()
}
/// exe+4c4e20
pub fn flat_dist(a: V3, b: V3) -> f32 {
    (a - b).flat_len()
}
