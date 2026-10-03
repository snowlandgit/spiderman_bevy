//! The world as the simulation sees it: the buildings' authored collision boxes, and the triangles of any imported
//! object (its own meshes, in world space, from whatever glTF the layout places). Rays, sphere casts, the floor under
//! him and the push out of what he overlaps work on both kinds alike. So do the ledges zip-to-point targets come from:
//! found in the geometry itself, they are the edges of surfaces he can stand on where the surface drops away (a roof's
//! rim, a car's roof, the top of a post or a statue), whatever the object.
use crate::physics::{Tower, ray_box};
use bevy::prelude::*;
use std::collections::HashMap;
use std::sync::Arc;

/// Surfaces at most this steep are ones he stands on (cos 45 degrees)
pub const WALKABLE: f32 = 0.7;

#[derive(Clone, Copy, Debug, PartialEq)]
pub struct Hit {
    /// distance along the ray (or the sweep)
    pub t: f32,
    pub point: Vec3,
    /// the surface's normal, facing back along the ray
    pub normal: Vec3,
}

#[derive(Clone, Copy, Debug)]
pub struct Tri {
    pub a: Vec3,
    pub b: Vec3,
    pub c: Vec3,
    pub n: Vec3,
}

impl Tri {
    fn new(a: Vec3, b: Vec3, c: Vec3) -> Option<Self> {
        let n = (b - a).cross(c - a);
        let l = n.length();
        (l > 1e-9 && l.is_finite()).then(|| Self { a, b, c, n: n / l })
    }
    fn min(&self) -> Vec3 {
        self.a.min(self.b).min(self.c)
    }
    fn max(&self) -> Vec3 {
        self.a.max(self.b).max(self.c)
    }

    /// Möller-Trumbore, either side
    fn ray(&self, o: Vec3, d: Vec3, max: f32) -> Option<f32> {
        let e1 = self.b - self.a;
        let e2 = self.c - self.a;
        let p = d.cross(e2);
        let det = e1.dot(p);
        if det.abs() < 1e-12 {
            return None;
        }
        let inv = 1. / det;
        let s = o - self.a;
        let u = s.dot(p) * inv;
        if !(-1e-6..=1. + 1e-6).contains(&u) {
            return None;
        }
        let q = s.cross(e1);
        let v = d.dot(q) * inv;
        if v < -1e-6 || u + v > 1. + 1e-6 {
            return None;
        }
        let t = e2.dot(q) * inv;
        (t >= 0. && t <= max).then_some(t)
    }

    /// The nearest point of the triangle to `p` (Ericson, Real-Time Collision Detection 5.1.5)
    pub fn closest(&self, p: Vec3) -> Vec3 {
        let (a, b, c) = (self.a, self.b, self.c);
        let ab = b - a;
        let ac = c - a;
        let ap = p - a;
        let d1 = ab.dot(ap);
        let d2 = ac.dot(ap);
        if d1 <= 0. && d2 <= 0. {
            return a;
        }
        let bp = p - b;
        let d3 = ab.dot(bp);
        let d4 = ac.dot(bp);
        if d3 >= 0. && d4 <= d3 {
            return b;
        }
        let vc = d1 * d4 - d3 * d2;
        if vc <= 0. && d1 >= 0. && d3 <= 0. {
            return a + ab * (d1 / (d1 - d3));
        }
        let cp = p - c;
        let d5 = ab.dot(cp);
        let d6 = ac.dot(cp);
        if d6 >= 0. && d5 <= d6 {
            return c;
        }
        let vb = d5 * d2 - d1 * d6;
        if vb <= 0. && d2 >= 0. && d6 <= 0. {
            return a + ac * (d2 / (d2 - d6));
        }
        let va = d3 * d6 - d5 * d4;
        if va <= 0. && (d4 - d3) >= 0. && (d5 - d6) >= 0. {
            return b + (c - b) * ((d4 - d3) / ((d4 - d3) + (d5 - d6)));
        }
        let denom = 1. / (va + vb + vc);
        a + ab * (vb * denom) + ac * (vc * denom)
    }

    /// A sphere of radius `r` moving from `o` along unit `d`: where along the way it first touches the triangle
    fn sweep(&self, o: Vec3, d: Vec3, r: f32, max: f32) -> Option<f32> {
        // already touching
        if (self.closest(o) - o).length_squared() < r * r {
            return Some(0.);
        }
        let mut best = f32::INFINITY;
        // the face, offset by r toward the side the sphere comes from
        let s0 = (o - self.a).dot(self.n);
        let dn = d.dot(self.n);
        if dn.abs() > 1e-9 {
            let side = if s0 >= 0. { 1. } else { -1. };
            let t = (side * r - s0) / dn;
            if t >= 0. && t <= max {
                let p = o + d * t - self.n * (side * r);
                if self.contains(p) {
                    best = t;
                }
            }
        }
        if best.is_finite() {
            return Some(best);
        }
        // the edges (cylinders) and the corners (spheres)
        for (p0, p1) in [(self.a, self.b), (self.b, self.c), (self.c, self.a)] {
            if let Some(t) = ray_capsule(o, d, p0, p1, r) {
                if t <= max {
                    best = best.min(t);
                }
            }
        }
        best.is_finite().then_some(best)
    }

    fn contains(&self, p: Vec3) -> bool {
        let c0 = (self.b - self.a).cross(p - self.a).dot(self.n);
        let c1 = (self.c - self.b).cross(p - self.b).dot(self.n);
        let c2 = (self.a - self.c).cross(p - self.c).dot(self.n);
        c0 >= -1e-6 && c1 >= -1e-6 && c2 >= -1e-6
    }
}

/// A ray against the capsule round segment p0..p1 (unit `d`; from outside)
fn ray_capsule(o: Vec3, d: Vec3, p0: Vec3, p1: Vec3, r: f32) -> Option<f32> {
    let mut best: Option<f32> = None;
    let mut take = |t: f32| {
        if t >= 0. && best.is_none_or(|b| t < b) {
            best = Some(t);
        }
    };
    let e = p1 - p0;
    let m = o - p0;
    let ee = e.dot(e);
    let ed = e.dot(d);
    let em = e.dot(m);
    let a = ee - ed * ed;
    if a > 1e-9 {
        let b = ee * m.dot(d) - em * ed;
        let c = ee * (m.dot(m) - r * r) - em * em;
        let disc = b * b - a * c;
        if disc >= 0. {
            let t = (-b - disc.sqrt()) / a;
            let s = em + t * ed;
            if s >= 0. && s <= ee {
                take(t);
            }
        }
    }
    for p in [p0, p1] {
        let m = o - p;
        let b = m.dot(d);
        let c = m.dot(m) - r * r;
        let disc = b * b - c;
        if disc >= 0. {
            take(-b - disc.sqrt());
        }
    }
    best
}

fn ray_aabb(o: Vec3, inv: Vec3, min: Vec3, max: Vec3, tmax: f32) -> bool {
    let t0 = (min - o) * inv;
    let t1 = (max - o) * inv;
    let lo = t0.min(t1).max_element().max(0.);
    let hi = t0.max(t1).min_element().min(tmax);
    lo <= hi
}

#[derive(Clone, Copy, Debug)]
struct Node {
    min: Vec3,
    max: Vec3,
    /// a leaf's first triangle, or an inner node's first child (the second follows it)
    first: u32,
    /// triangles in a leaf, 0 for an inner node
    count: u32,
}

/// The imported objects' triangles in a bounding volume hierarchy
#[derive(Debug, Default)]
pub struct Bvh {
    tris: Vec<Tri>,
    nodes: Vec<Node>,
}

impl Bvh {
    fn build(mut tris: Vec<Tri>) -> Self {
        let mut nodes = Vec::with_capacity(tris.len() * 2 / 3 + 1);
        if !tris.is_empty() {
            nodes.push(Node { min: Vec3::ZERO, max: Vec3::ZERO, first: 0, count: 0 });
            let n = tris.len();
            Self::split(&mut tris, &mut nodes, 0, 0, n);
        }
        Self { tris, nodes }
    }

    fn split(tris: &mut [Tri], nodes: &mut Vec<Node>, at: usize, lo: usize, hi: usize) {
        let (mut min, mut max) = (Vec3::INFINITY, Vec3::NEG_INFINITY);
        let (mut cmin, mut cmax) = (Vec3::INFINITY, Vec3::NEG_INFINITY);
        for t in &tris[lo..hi] {
            min = min.min(t.min());
            max = max.max(t.max());
            let c = (t.a + t.b + t.c) / 3.;
            cmin = cmin.min(c);
            cmax = cmax.max(c);
        }
        nodes[at].min = min;
        nodes[at].max = max;
        let n = hi - lo;
        let extent = cmax - cmin;
        if n <= 4 || extent.max_element() < 1e-6 {
            nodes[at].first = lo as u32;
            nodes[at].count = n as u32;
            return;
        }
        let axis = if extent.x >= extent.y && extent.x >= extent.z {
            0
        } else if extent.y >= extent.z {
            1
        } else {
            2
        };
        let mid = lo + n / 2;
        tris[lo..hi].select_nth_unstable_by(n / 2, |p, q| {
            let cp = p.a[axis] + p.b[axis] + p.c[axis];
            let cq = q.a[axis] + q.b[axis] + q.c[axis];
            cp.total_cmp(&cq)
        });
        let first = nodes.len();
        nodes.push(Node { min: Vec3::ZERO, max: Vec3::ZERO, first: 0, count: 0 });
        nodes.push(Node { min: Vec3::ZERO, max: Vec3::ZERO, first: 0, count: 0 });
        nodes[at].first = first as u32;
        nodes[at].count = 0;
        Self::split(tris, nodes, first, lo, mid);
        Self::split(tris, nodes, first + 1, mid, hi);
    }

    /// Every triangle whose box overlaps [min, max]
    fn each_in(&self, min: Vec3, max: Vec3, mut f: impl FnMut(&Tri)) {
        if self.nodes.is_empty() {
            return;
        }
        let mut stack = vec![0usize];
        while let Some(i) = stack.pop() {
            let n = self.nodes[i];
            if n.min.cmpgt(max).any() || n.max.cmplt(min).any() {
                continue;
            }
            if n.count > 0 {
                for t in &self.tris[n.first as usize..(n.first + n.count) as usize] {
                    if t.min().cmple(max).all() && t.max().cmpge(min).all() {
                        f(t);
                    }
                }
            } else {
                stack.push(n.first as usize);
                stack.push(n.first as usize + 1);
            }
        }
    }

    /// The nearest hit of a ray (unit `d`), or of a sphere of radius `r` swept along it
    fn cast(&self, o: Vec3, d: Vec3, r: f32, max: f32) -> Option<Hit> {
        if self.nodes.is_empty() {
            return None;
        }
        let inv = Vec3::ONE / d;
        let pad = Vec3::splat(r);
        let mut best: Option<(f32, Tri)> = None;
        let mut stack = vec![0usize];
        while let Some(i) = stack.pop() {
            let n = self.nodes[i];
            let limit = best.map_or(max, |b| b.0);
            if !ray_aabb(o, inv, n.min - pad, n.max + pad, limit) {
                continue;
            }
            if n.count > 0 {
                for t in &self.tris[n.first as usize..(n.first + n.count) as usize] {
                    let limit = best.map_or(max, |b| b.0);
                    let hit = if r > 0. { t.sweep(o, d, r, limit) } else { t.ray(o, d, limit) };
                    if let Some(h) = hit {
                        if best.is_none_or(|b| h < b.0) {
                            best = Some((h, *t));
                        }
                    }
                }
            } else {
                stack.push(n.first as usize);
                stack.push(n.first as usize + 1);
            }
        }
        best.map(|(t, tri)| {
            let c = o + d * t;
            let normal = if r > 0. {
                (c - tri.closest(c)).normalize_or(if tri.n.dot(d) > 0. { -tri.n } else { tri.n })
            } else if tri.n.dot(d) > 0. {
                -tri.n
            } else {
                tri.n
            };
            Hit { t, point: if r > 0. { c - normal * r } else { c }, normal }
        })
    }
}

/// Where he can perch: the rim of a surface he stands on, where it drops away, or the tip of something thin
#[derive(Clone, Copy, Debug)]
pub struct Ledge {
    pub a: Vec3,
    pub b: Vec3,
    /// level, away from the top over the drop
    pub out: Vec3,
    /// how far the top reaches in from the edge
    pub depth: f32,
    /// the top of something thin (a pole, an antenna, a finial): a point (`a`), with no surface to stand on
    pub tip: bool,
}

impl Ledge {
    /// The point of the ledge nearest the line through `o` along unit `d`
    pub fn nearest_to_line(&self, o: Vec3, d: Vec3) -> Vec3 {
        let ab = self.b - self.a;
        let ca = self.a - o;
        let abab = ab.dot(ab);
        let abd = ab.dot(d);
        let den = abab - abd * abd;
        let u = if den > 1e-6 { (abd * ca.dot(d) - ca.dot(ab)) / den } else { 0. };
        self.a + ab * u.clamp(0., 1.)
    }
}

/// The ledges of a triangle soup: edges of walkable triangles whose neighbours across the edge (after welding the
/// vertices to 1 cm) are missing or fall away below the surface
fn mesh_ledges(tris: &[Tri]) -> Vec<Ledge> {
    let mut ids: HashMap<[i32; 3], u32> = HashMap::new();
    let mut weld = |p: Vec3| -> u32 {
        let k = [(p.x * 100.).round() as i32, (p.y * 100.).round() as i32, (p.z * 100.).round() as i32];
        let n = ids.len() as u32;
        *ids.entry(k).or_insert(n)
    };
    let idx: Vec<[u32; 3]> = tris.iter().map(|t| [weld(t.a), weld(t.b), weld(t.c)]).collect();
    // edge -> (triangle, opposite corner)
    let mut edges: HashMap<(u32, u32), Vec<(usize, usize)>> = HashMap::new();
    for (i, v) in idx.iter().enumerate() {
        for k in 0..3 {
            let (p, q) = (v[k], v[(k + 1) % 3]);
            if p != q {
                edges.entry((p.min(q), p.max(q))).or_default().push((i, (k + 2) % 3));
            }
        }
    }
    let corner = |t: &Tri, k: usize| [t.a, t.b, t.c][k];
    // surfaces by their up side (imported meshes don't always wind their faces outward)
    let up = |t: &Tri| if t.n.y < 0. { -t.n } else { t.n };
    let mut out = Vec::new();
    for (i, t) in tris.iter().enumerate() {
        let n = up(t);
        if n.y < WALKABLE {
            continue;
        }
        let v = idx[i];
        for k in 0..3 {
            let (p, q) = (v[k], v[(k + 1) % 3]);
            if p == q {
                continue;
            }
            let (a, b) = (corner(t, k), corner(t, (k + 1) % 3));
            let opposite = corner(t, (k + 2) % 3);
            let drop = edges[&(p.min(q), p.max(q))].iter().filter(|(j, _)| *j != i).all(|&(j, o)| {
                let u = &tris[j];
                // a neighbour he could also stand on, or one rising from the edge (a wall's foot): not a rim
                up(u).y < WALKABLE && (corner(u, o) - a).dot(n) < -0.05
            });
            if !drop {
                continue;
            }
            let e = (b - a).with_y(0.);
            if e.length_squared() < 1e-4 {
                continue;
            }
            let mut o = Vec3::new(e.z, 0., -e.x).normalize();
            if o.dot(opposite - a) > 0. {
                o = -o;
            }
            let depth = (opposite - a).dot(-o).max(0.);
            out.push(Ledge { a, b, out: o, depth, tip: false });
        }
    }
    out
}

/// The tips of a triangle soup: the tops of thin things he can perch on though there is nothing to stand on. In a
/// 0.2 m grid of the highest surface (each triangle filled in, its edges sampled), a cell 1 m or more above the model's
/// foot that is the highest within 0.6 m and stands clear (0.1 m) over everything 0.4 to 1 m round it.
fn mesh_tips(tris: &[Tri]) -> Vec<Ledge> {
    const C: f32 = 0.2;
    let cell = |x: f32| (x / C).floor() as i32;
    let mut top: HashMap<(i32, i32), Vec3> = HashMap::new();
    let mut put = |p: Vec3| {
        let k = (cell(p.x), cell(p.z));
        let e = top.entry(k).or_insert(p);
        if p.y > e.y {
            *e = p;
        }
    };
    let mut foot = f32::INFINITY;
    for t in tris {
        foot = foot.min(t.min().y);
        for (p, q) in [(t.a, t.b), (t.b, t.c), (t.c, t.a)] {
            let n = ((q - p).with_y(0.).length() / (C * 0.5)).ceil().max(1.) as usize;
            for k in 0..=n {
                put(p.lerp(q, k as f32 / n as f32));
            }
        }
        // the cells whose middle the triangle covers, at its height there
        if let (true, Some(flat)) = (t.n.y.abs() > 1e-4, Tri::new(t.a.with_y(0.), t.b.with_y(0.), t.c.with_y(0.))) {
            let (lo, hi) = (t.min(), t.max());
            for x in cell(lo.x)..=cell(hi.x) {
                for z in cell(lo.z)..=cell(hi.z) {
                    let m = Vec3::new((x as f32 + 0.5) * C, 0., (z as f32 + 0.5) * C);
                    if flat.contains(m) {
                        put(m.with_y(t.a.y - ((m.x - t.a.x) * t.n.x + (m.z - t.a.z) * t.n.z) / t.n.y));
                    }
                }
            }
        }
    }
    let mut out = Vec::new();
    for (&(x, z), &p) in &top {
        if p.y < foot + 1. {
            continue;
        }
        let mut peak = true;
        'ring: for dx in -5..=5i32 {
            for dz in -5..=5i32 {
                let r2 = dx * dx + dz * dz;
                if r2 == 0 || r2 > 25 {
                    continue;
                }
                let Some(q) = top.get(&(x + dx, z + dz)) else { continue };
                // the highest within 0.6 m (ties: the first), and clear over the ring from 0.4 m out
                if (r2 <= 9 && (q.y > p.y || (q.y == p.y && (dx, dz) < (0, 0)))) || (r2 >= 4 && q.y > p.y - 0.1) {
                    peak = false;
                    break 'ring;
                }
            }
        }
        if peak {
            out.push(Ledge { a: p, b: p, out: Vec3::X, depth: 0., tip: true });
        }
    }
    out
}

/// How far his feet go in from a ledge's edge (where ArkWeb's LedgePerch_Idle stands; less on a narrow top)
pub fn inset(l: &Ledge) -> f32 {
    0.35f32.min(l.depth * 0.5)
}
/// How far past a ledge's edge the drop under it is measured: 0.6 m (past a car's shoulder under its roof's rim, still on
/// the next tread of a stair), 0.15 m from a narrow top (a cap with arms or a lattice under it)
pub fn drop_offset(l: &Ledge) -> f32 {
    if l.depth < 0.7 { 0.15 } else { 0.6 }
}

/// Could he perch on ledge `l` as far as its own model goes: somewhere along it (at a tenth, half and nine tenths) a
/// surface to stand on just in from the edge, headroom over it and a drop of 1 m or more past the edge; at a tip,
/// headroom
fn standable(bvh: &Bvh, l: &Ledge) -> bool {
    let up = Vec3::Y;
    let floor = |p: Vec3, down: f32| bvh.cast(p, Vec3::NEG_Y, 0., down).filter(|h| h.normal.y >= WALKABLE);
    let at = |p: Vec3| -> bool {
        if l.tip {
            return bvh.cast(p + up * 0.3, up, 0.25, 1.5).is_none();
        }
        let Some(f) = floor(p - l.out * inset(l) + up * 0.6, 1.2) else { return false };
        (f.point.y - p.y).abs() <= 0.3
            && bvh.cast(f.point + up * 0.3, up, 0.25, 1.5).is_none()
            && floor(p + l.out * drop_offset(l) + up * 0.05, 1.).is_none()
    };
    [0.1, 0.5, 0.9].iter().any(|&u| at(l.a.lerp(l.b, u)))
}

/// The four rims of a box's top
fn box_ledges(t: &Tower) -> [Ledge; 4] {
    let (lo, hi) = (t.min(), t.max());
    let y = hi.y;
    let c = |x: f32, z: f32| Vec3::new(x, y, z);
    let (w, d) = (hi.x - lo.x, hi.z - lo.z);
    [
        Ledge { a: c(lo.x, lo.z), b: c(hi.x, lo.z), out: Vec3::NEG_Z, depth: d, tip: false },
        Ledge { a: c(hi.x, lo.z), b: c(hi.x, hi.z), out: Vec3::X, depth: w, tip: false },
        Ledge { a: c(hi.x, hi.z), b: c(lo.x, hi.z), out: Vec3::Z, depth: d, tip: false },
        Ledge { a: c(lo.x, hi.z), b: c(lo.x, lo.z), out: Vec3::NEG_X, depth: w, tip: false },
    ]
}

/// The outward normal of the box face `p` lies on
pub fn box_normal(t: &Tower, p: Vec3) -> Vec3 {
    let (lo, hi) = (t.min(), t.max());
    let faces = [
        ((p.x - lo.x).abs(), Vec3::NEG_X),
        ((hi.x - p.x).abs(), Vec3::X),
        ((p.y - lo.y).abs(), Vec3::NEG_Y),
        ((hi.y - p.y).abs(), Vec3::Y),
        ((p.z - lo.z).abs(), Vec3::NEG_Z),
        ((hi.z - p.z).abs(), Vec3::Z),
    ];
    faces.iter().min_by(|a, b| a.0.total_cmp(&b.0)).unwrap().1
}

/// An imported model's collision: its triangles (in its own space) and the ledges found on them. Shared by every
/// placement of the model.
#[derive(Debug, Default)]
pub struct Model {
    bvh: Bvh,
    ledges: Vec<Ledge>,
    min: Vec3,
    max: Vec3,
}

impl Model {
    pub fn new(triangles: &[[Vec3; 3]]) -> Self {
        let tris: Vec<Tri> = triangles.iter().filter_map(|t| Tri::new(t[0], t[1], t[2])).collect();
        let (mut min, mut max) = (Vec3::INFINITY, Vec3::NEG_INFINITY);
        for t in &tris {
            min = min.min(t.min());
            max = max.max(t.max());
        }
        let mut ledges = mesh_ledges(&tris);
        ledges.extend(mesh_tips(&tris));
        let bvh = Bvh::build(tris);
        // only ledges he could stand at by the model itself (what else stands round it is checked when aiming)
        ledges.retain(|l| standable(&bvh, l));
        Self { bvh, ledges, min, max }
    }
    pub fn triangle_count(&self) -> usize {
        self.bvh.tris.len()
    }
}

/// A model placed in the world (rotation, uniform scale, translation)
#[derive(Clone, Debug)]
pub struct Object {
    pub model: Arc<Model>,
    pub transform: Transform,
}

#[derive(Clone, Debug)]
struct Instance {
    model: Arc<Model>,
    to_world: bevy::math::Affine3A,
    to_local: bevy::math::Affine3A,
    /// world length per model length
    scale: f32,
    min: Vec3,
    max: Vec3,
}

impl Instance {
    fn new(o: &Object) -> Self {
        let to_world = o.transform.compute_affine();
        let scale = o.transform.scale.max_element().max(1e-6);
        let (mut min, mut max) = (Vec3::INFINITY, Vec3::NEG_INFINITY);
        let (lo, hi) = (o.model.min, o.model.max);
        for k in 0..8 {
            let c = Vec3::new(
                if k & 1 == 0 { lo.x } else { hi.x },
                if k & 2 == 0 { lo.y } else { hi.y },
                if k & 4 == 0 { lo.z } else { hi.z },
            );
            let w = to_world.transform_point3(c);
            min = min.min(w);
            max = max.max(w);
        }
        Self { model: o.model.clone(), to_world, to_local: to_world.inverse(), scale, min, max }
    }

    fn cast(&self, o: Vec3, d: Vec3, r: f32, max: f32) -> Option<Hit> {
        let lo = self.to_local.transform_point3(o);
        let ld = self.to_local.transform_vector3(d).normalize_or_zero();
        let k = self.scale;
        let h = self.model.bvh.cast(lo, ld, r / k, max / k)?;
        Some(Hit {
            t: h.t * k,
            point: self.to_world.transform_point3(h.point),
            normal: self.to_world.transform_vector3(h.normal).normalize_or_zero(),
        })
    }
}

/// The ledges by where they are (16 m cells, level)
#[derive(Debug, Default)]
struct LedgeGrid {
    cells: HashMap<(i32, i32), Vec<u32>>,
}

const CELL: f32 = 16.;

impl LedgeGrid {
    fn build(ledges: &[Ledge]) -> Self {
        let mut cells: HashMap<(i32, i32), Vec<u32>> = HashMap::new();
        for (i, l) in ledges.iter().enumerate() {
            let (lo, hi) = (l.a.min(l.b), l.a.max(l.b));
            for x in (lo.x / CELL).floor() as i32..=(hi.x / CELL).floor() as i32 {
                for z in (lo.z / CELL).floor() as i32..=(hi.z / CELL).floor() as i32 {
                    cells.entry((x, z)).or_default().push(i as u32);
                }
            }
        }
        Self { cells }
    }
}

/// The world: the authored boxes and the placed models
#[derive(Clone, Default)]
pub struct World {
    /// the authored boxes (the buildings)
    pub towers: Vec<Tower>,
    instances: Arc<Vec<Instance>>,
    /// every perchable edge of both, in world space
    pub ledges: Arc<Vec<Ledge>>,
    grid: Arc<LedgeGrid>,
}

impl World {
    /// Boxes and placed models
    pub fn new(towers: Vec<Tower>, objects: &[Object]) -> Self {
        let instances: Vec<Instance> = objects.iter().map(Instance::new).collect();
        let mut ledges: Vec<Ledge> = towers.iter().flat_map(box_ledges).collect();
        for i in &instances {
            let m = &i.to_world;
            ledges.extend(i.model.ledges.iter().map(|l| Ledge {
                a: m.transform_point3(l.a),
                b: m.transform_point3(l.b),
                out: m.transform_vector3(l.out).with_y(0.).normalize_or(l.out),
                depth: l.depth * i.scale,
                tip: l.tip,
            }));
        }
        let grid = LedgeGrid::build(&ledges);
        Self { towers, instances: Arc::new(instances), ledges: Arc::new(ledges), grid: Arc::new(grid) }
    }
    /// Boxes and triangles in world space (one model where it stands)
    #[cfg(test)]
    pub fn with_triangles(towers: Vec<Tower>, triangles: &[[Vec3; 3]]) -> Self {
        let objects = [Object { model: Arc::new(Model::new(triangles)), transform: Transform::IDENTITY }];
        Self::new(towers, &objects)
    }
    pub fn boxes(towers: &[Tower]) -> Self {
        Self::new(towers.to_vec(), &[])
    }
    pub fn triangle_count(&self) -> usize {
        self.instances.iter().map(|i| i.model.triangle_count()).sum()
    }
    pub fn object_count(&self) -> usize {
        self.instances.len()
    }

    /// The ledges within `range` of `p` (level); a ledge across cells comes more than once
    pub fn ledges_near(&self, p: Vec3, range: f32, mut f: impl FnMut(&Ledge)) {
        let (x0, x1) = (((p.x - range) / CELL).floor() as i32, ((p.x + range) / CELL).floor() as i32);
        let (z0, z1) = (((p.z - range) / CELL).floor() as i32, ((p.z + range) / CELL).floor() as i32);
        for x in x0..=x1 {
            for z in z0..=z1 {
                if let Some(c) = self.grid.cells.get(&(x, z)) {
                    for &i in c {
                        f(&self.ledges[i as usize]);
                    }
                }
            }
        }
    }

    fn cast_objects(&self, o: Vec3, d: Vec3, r: f32, max: f32) -> Option<Hit> {
        let inv = Vec3::ONE / d;
        let pad = Vec3::splat(r);
        let mut best: Option<Hit> = None;
        for i in self.instances.iter() {
            let limit = best.map_or(max, |b| b.t);
            if !ray_aabb(o, inv, i.min - pad, i.max + pad, limit) {
                continue;
            }
            if let Some(h) = i.cast(o, d, r, limit) {
                if best.is_none_or(|b| h.t < b.t) {
                    best = Some(h);
                }
            }
        }
        best
    }

    /// The nearest surface along a ray (unit `d`) within `max`
    pub fn raycast(&self, o: Vec3, d: Vec3, max: f32) -> Option<Hit> {
        let mut best = self.cast_objects(o, d, 0., max);
        for t in &self.towers {
            if let Some(h) = ray_box(o, d, *t, best.map_or(max, |b| b.t)).filter(|h| *h >= 0.) {
                let p = o + d * h;
                best = Some(Hit { t: h, point: p, normal: box_normal(t, p) });
            }
        }
        best
    }

    /// The first surface a sphere of radius `r` touches moving from `o` along unit `d` within `max` (0 when it
    /// starts touching). `point` is where it touches.
    pub fn sphere_cast(&self, o: Vec3, d: Vec3, r: f32, max: f32) -> Option<Hit> {
        let mut best = self.cast_objects(o, d, r, max);
        for t in &self.towers {
            let grown = Tower { center: t.center, half: t.half + Vec3::splat(r) };
            if let Some(h) = ray_box(o, d, grown, best.map_or(max, |b| b.t)).filter(|h| *h >= 0.) {
                let c = o + d * h;
                let n = box_normal(&grown, c);
                best = Some(Hit { t: h, point: c - n * r, normal: n });
            }
        }
        best
    }

    /// The top of what he could stand on under `p`, within `down` (the street, y = 0, counts)
    pub fn floor_below(&self, p: Vec3, down: f32) -> Option<Hit> {
        let hit = self.raycast(p, Vec3::NEG_Y, down).filter(|h| h.normal.y >= WALKABLE);
        let street = (p.y >= 0. && p.y - down <= 0.).then(|| Hit { t: p.y, point: p.with_y(0.), normal: Vec3::Y });
        match (hit, street) {
            (Some(h), Some(s)) => Some(if h.t <= s.t { h } else { s }),
            (h, s) => h.or(s),
        }
    }

    /// The height of the floor under him (a tower's top, an object's surface, or the street)
    pub fn ground_below(&self, pos: Vec3) -> f32 {
        self.floor_below(pos, 1000.).map_or(0., |h| h.point.y)
    }

    /// The placed models' triangles a sphere overlaps: (the nearest point on each, the triangle's normal; world)
    pub fn mesh_contacts(&self, c: Vec3, r: f32, mut f: impl FnMut(Vec3, Vec3)) {
        for i in self.instances.iter() {
            if (c + Vec3::splat(r)).cmplt(i.min).any() || (c - Vec3::splat(r)).cmpgt(i.max).any() {
                continue;
            }
            let lc = i.to_local.transform_point3(c);
            let lr = r / i.scale;
            let pad = Vec3::splat(lr);
            i.model.bvh.each_in(lc - pad, lc + pad, |t| {
                let q = t.closest(lc);
                if (q - lc).length_squared() < lr * lr {
                    f(i.to_world.transform_point3(q), i.to_world.transform_vector3(t.n).normalize_or_zero());
                }
            });
        }
    }
    pub fn has_mesh(&self) -> bool {
        !self.instances.is_empty()
    }
    /// `sphere_cast` against the placed models only (the boxes have their own collision)
    pub fn mesh_cast(&self, o: Vec3, d: Vec3, r: f32, max: f32) -> Option<Hit> {
        self.cast_objects(o, d, r, max)
    }
    /// `floor_below` on the placed models only
    pub fn mesh_floor(&self, p: Vec3, down: f32) -> Option<Hit> {
        self.cast_objects(p, Vec3::NEG_Y, 0., down).filter(|h| h.normal.y >= WALKABLE)
    }
}

/// Every triangle of a mesh, in world space
pub fn mesh_triangles(mesh: &Mesh, transform: &GlobalTransform, out: &mut Vec<[Vec3; 3]>) {
    use bevy::mesh::{Indices, PrimitiveTopology, VertexAttributeValues};
    if mesh.primitive_topology() != PrimitiveTopology::TriangleList {
        return;
    }
    let Ok(VertexAttributeValues::Float32x3(pos)) = mesh.try_attribute(Mesh::ATTRIBUTE_POSITION) else {
        return;
    };
    let m = transform.affine();
    let p: Vec<Vec3> = pos.iter().map(|v| m.transform_point3(Vec3::from_array(*v))).collect();
    let idx: Vec<usize> = match mesh.try_indices() {
        Ok(Indices::U16(i)) => i.iter().map(|&k| k as usize).collect(),
        Ok(Indices::U32(i)) => i.iter().map(|&k| k as usize).collect(),
        _ => (0..p.len()).collect(),
    };
    for t in idx.chunks_exact(3) {
        if t.iter().all(|&k| k < p.len()) {
            out.push([p[t[0]], p[t[1]], p[t[2]]]);
        }
    }
}

#[cfg(test)]
pub mod tests {
    use super::*;
    use crate::physics::FOOT;

    /// A closed box as triangles (a stand-in for an imported object's mesh)
    pub fn box_mesh(center: Vec3, half: Vec3) -> Vec<[Vec3; 3]> {
        let c = |x: f32, y: f32, z: f32| center + half * Vec3::new(x, y, z);
        let quads = [
            [c(-1., 1., -1.), c(-1., 1., 1.), c(1., 1., 1.), c(1., 1., -1.)],
            [c(-1., -1., -1.), c(1., -1., -1.), c(1., -1., 1.), c(-1., -1., 1.)],
            [c(-1., -1., -1.), c(-1., -1., 1.), c(-1., 1., 1.), c(-1., 1., -1.)],
            [c(1., -1., -1.), c(1., 1., -1.), c(1., 1., 1.), c(1., -1., 1.)],
            [c(-1., -1., -1.), c(-1., 1., -1.), c(1., 1., -1.), c(1., -1., -1.)],
            [c(-1., -1., 1.), c(1., -1., 1.), c(1., 1., 1.), c(-1., 1., 1.)],
        ];
        quads.iter().flat_map(|q| [[q[0], q[1], q[2]], [q[0], q[2], q[3]]]).collect()
    }

    #[test]
    fn rays_and_sweeps_hit_meshes_and_boxes_alike() {
        let half = Vec3::new(2., 3., 4.);
        let mesh = World::with_triangles(vec![], &box_mesh(Vec3::new(0., 3., -10.), half));
        let boxes = World::boxes(&[Tower { center: Vec3::new(0., 3., -10.), half }]);
        for w in [&mesh, &boxes] {
            let h = w.raycast(Vec3::new(0., 2., 0.), Vec3::NEG_Z, 50.).unwrap();
            assert!((h.t - 6.).abs() < 1e-4 && h.normal.abs_diff_eq(Vec3::Z, 1e-4), "{h:?}");
            let s = w.sphere_cast(Vec3::new(0., 2., 0.), Vec3::NEG_Z, 0.5, 50.).unwrap();
            assert!((s.t - 5.5).abs() < 1e-3 && s.normal.abs_diff_eq(Vec3::Z, 1e-3), "{s:?}");
            assert!(w.raycast(Vec3::new(5., 2., 0.), Vec3::NEG_Z, 50.).is_none());
            let f = w.floor_below(Vec3::new(1., 9., -10.), 20.).unwrap();
            assert!((f.point.y - 6.).abs() < 1e-4);
        }
        // a sphere sweeping past an edge touches it at its radius
        let s = mesh.sphere_cast(Vec3::new(2.3, 8., -10.), Vec3::NEG_Y, 0.5, 50.).unwrap();
        assert!((s.point - Vec3::new(2., 6., -10.)).length() < 1e-3, "{s:?}");
        assert!(s.t > 1.5 && s.t < 2., "{s:?}");
    }

    #[test]
    fn a_closed_box_mesh_has_its_top_rim_as_ledges() {
        let w = World::with_triangles(vec![], &box_mesh(Vec3::new(0., 3., -10.), Vec3::new(2., 3., 4.)));
        assert_eq!(w.ledges.len(), 4, "{:?}", w.ledges);
        for l in w.ledges.iter() {
            assert!((l.a.y - 6.).abs() < 1e-5 && (l.b.y - 6.).abs() < 1e-5);
            let mid = (l.a + l.b) * 0.5;
            // outward: away from the box's middle
            assert!(l.out.dot(mid - Vec3::new(0., 6., -10.)) > 0.);
            assert!(l.depth > 3.9);
        }
    }

    #[test]
    fn a_thin_posts_top_is_a_tip_and_a_roof_has_none() {
        // a post 0.1 m across and 5 m tall, by a 2 m block
        let mut tris = box_mesh(Vec3::new(0., 2.5, 0.), Vec3::new(0.05, 2.5, 0.05));
        tris.extend(box_mesh(Vec3::new(4., 1., 0.), Vec3::new(1., 1., 1.)));
        let m = Model::new(&tris);
        let tips: Vec<_> = m.ledges.iter().filter(|l| l.tip).collect();
        assert_eq!(tips.len(), 1, "{tips:?}");
        assert!((tips[0].a - Vec3::new(0., 5., 0.)).length() < 0.11, "{tips:?}");
    }

    #[test]
    fn a_wall_rising_from_a_roof_is_no_ledge_but_its_top_is() {
        // a roof with a parapet on it: the roof's edge at the parapet's foot is not a rim
        let mut tris = box_mesh(Vec3::new(0., 5., 0.), Vec3::new(5., 5., 5.));
        tris.extend(box_mesh(Vec3::new(0., 10.5, -4.75), Vec3::new(5., 0.5, 0.25)));
        let w = World::with_triangles(vec![], &tris);
        assert!(w.ledges.iter().any(|l| (l.a.y - 11.).abs() < 1e-4), "the parapet's top");
        assert!(w.ledges.iter().all(|l| l.a.y > 9.99));
    }

    /// A glTF binary's triangles in its own space (each mesh by its node's transform): what the app gets from Bevy's
    /// loader, read directly for the tests
    pub fn glb_triangles(path: &str) -> Vec<[Vec3; 3]> {
        let data = std::fs::read(path).unwrap();
        let json_len = u32::from_le_bytes(data[12..16].try_into().unwrap()) as usize;
        let gltf: serde_json::Value = serde_json::from_slice(&data[20..20 + json_len]).unwrap();
        let bin = 20 + json_len + 8;
        let accessor = |i: usize| -> (usize, usize, u64, usize) {
            let a = &gltf["accessors"][i];
            let v = &gltf["bufferViews"][a["bufferView"].as_u64().unwrap() as usize];
            let at = bin + v["byteOffset"].as_u64().unwrap_or(0) as usize + a["byteOffset"].as_u64().unwrap_or(0) as usize;
            let stride = v["byteStride"].as_u64().unwrap_or(0) as usize;
            (at, a["count"].as_u64().unwrap() as usize, a["componentType"].as_u64().unwrap(), stride)
        };
        let f32_at = |o: usize| f32::from_le_bytes(data[o..o + 4].try_into().unwrap());
        let mut out = Vec::new();
        for node in gltf["nodes"].as_array().unwrap() {
            let Some(mesh) = node["mesh"].as_u64() else { continue };
            let t = |k: &str, n: usize, d: f32| -> Vec<f32> {
                node[k].as_array().map(|a| a.iter().map(|x| x.as_f64().unwrap() as f32).collect()).unwrap_or(vec![d; n])
            };
            let (tr, r, sc) = (t("translation", 3, 0.), t("rotation", 4, 0.), t("scale", 3, 1.));
            let rot = if node["rotation"].is_null() { Quat::IDENTITY } else { Quat::from_xyzw(r[0], r[1], r[2], r[3]) };
            let m = Transform { translation: Vec3::new(tr[0], tr[1], tr[2]), rotation: rot, scale: Vec3::new(sc[0], sc[1], sc[2]) }
                .compute_affine();
            for p in gltf["meshes"][mesh as usize]["primitives"].as_array().unwrap() {
                let (pa, pn, _, ps) = accessor(p["attributes"]["POSITION"].as_u64().unwrap() as usize);
                let ps = if ps == 0 { 12 } else { ps };
                let pos: Vec<Vec3> = (0..pn)
                    .map(|k| m.transform_point3(Vec3::new(f32_at(pa + k * ps), f32_at(pa + k * ps + 4), f32_at(pa + k * ps + 8))))
                    .collect();
                let idx: Vec<usize> = match p["indices"].as_u64() {
                    Some(i) => {
                        let (ia, n, ct, _) = accessor(i as usize);
                        (0..n)
                            .map(|k| match ct {
                                5125 => u32::from_le_bytes(data[ia + k * 4..ia + k * 4 + 4].try_into().unwrap()) as usize,
                                5123 => u16::from_le_bytes(data[ia + k * 2..ia + k * 2 + 2].try_into().unwrap()) as usize,
                                _ => data[ia + k] as usize,
                            })
                            .collect()
                    }
                    None => (0..pn).collect(),
                };
                for c in idx.chunks_exact(3) {
                    out.push([pos[c[0]], pos[c[1]], pos[c[2]]]);
                }
            }
        }
        out
    }

    /// The layout's parked cars, as the app places them: one model per car file, a placement per car
    pub fn parked_cars() -> World {
        let layout = crate::environment::layout();
        let mut models: std::collections::HashMap<String, Arc<Model>> = Default::default();
        let mut objects = Vec::new();
        for car in &layout.cars {
            let model = models
                .entry(car.asset.clone())
                .or_insert_with(|| Arc::new(Model::new(&glb_triangles(&format!("assets/{}", car.asset)))))
                .clone();
            let transform = Transform::from_translation(Vec3::from_array(car.position))
                .with_rotation(Quat::from_rotation_y(car.yaw))
                .with_scale(Vec3::splat(car.scale));
            objects.push(Object { model, transform });
        }
        World::new(crate::environment::layout_towers(), &objects)
    }

    #[test]
    fn the_parked_cars_collide_and_offer_points_to_perch_on() {
        let started = std::time::Instant::now();
        let w = parked_cars();
        let built = started.elapsed();
        let layout = crate::environment::layout();
        assert_eq!(w.object_count(), layout.cars.len());
        println!("{} cars, {} triangles, {} ledges, built in {:?}", w.object_count(), w.triangle_count(), w.ledges.len(), built);
        // each car: a ray down onto it finds its roof, and aiming at its roof from the street finds a point on it
        let mut perchable = 0;
        for car in &layout.cars {
            let c = Vec3::from_array(car.position);
            let roof = w.raycast(c + Vec3::Y * 10., Vec3::NEG_Y, 20.).expect("the car under the ray");
            assert!(roof.point.y > 1.2 && roof.point.y < 2.3, "{car:?}: {roof:?}", car = car.asset);
            // from the street beside it
            let side = if c.x > 0. { Vec3::NEG_X } else { Vec3::X };
            let from = c + side * 7. + Vec3::Y * FOOT;
            let eye = from + Vec3::Y * 1.5 + side * 4.;
            if let Some(p) = crate::point_zip::find(&w, from, eye, (roof.point - eye).normalize()) {
                if p.feet.distance(roof.point) < 2.5 && p.feet.y > 1.2 {
                    perchable += 1;
                    continue;
                }
            }
            println!("no roof point for {} at {c:?}", car.asset);
        }
        assert!(perchable * 10 >= layout.cars.len() * 9, "{perchable} of {} cars", layout.cars.len());
    }

    #[test]
    fn he_zips_onto_a_parked_car_perches_and_point_launches() {
        use crate::physics::{DT, Hero, Intent, Mode, Tuning};
        let w = parked_cars();
        let t = Tuning::default();
        let car = Vec3::from_array(crate::environment::layout().cars[1].position);
        let roof = w.raycast(car + Vec3::Y * 10., Vec3::NEG_Y, 20.).unwrap().point;
        let side = if car.x > 0. { Vec3::NEG_X } else { Vec3::X };
        let mut h = Hero::default();
        h.pos = car + side * 7. + Vec3::Y * FOOT;
        h.previous = h.pos;
        h.velocity = Vec3::ZERO;
        h.mode = Mode::Ground;
        let eye = h.pos + Vec3::Y * 1.5 + side * 4.;
        let walk = Intent { forward: -side, right: (-side).cross(Vec3::Y), aim: (roof - eye).normalize(), aim_origin: eye, ..default() };
        h.step(Intent { point_zip: true, ..walk }, &w, &t, DT);
        assert_eq!(h.mode, Mode::Zip);
        for _ in 0..240 {
            h.step(walk, &w, &t, DT);
        }
        assert_eq!(h.mode, Mode::Perch, "{:?}", h.pos);
        assert!(h.pos.distance(roof) < 2.5 && h.pos.y - FOOT > 1.2, "on its roof: {:?} (roof {roof:?})", h.pos);
        // a zip on from the car to the next point is a launch's chance: here, A on arrival
        let mut h2 = h.clone();
        h2.perch.as_mut().unwrap().age = 0.;
        h2.step(Intent { jump: true, ..walk }, &w, &t, DT);
        assert_eq!((h2.launches, h2.mode), (1, Mode::Air));
        let mut top = h2.pos.y;
        for _ in 0..120 {
            h2.step(walk, &w, &t, DT);
            top = top.max(h2.pos.y);
        }
        assert!(top > h.pos.y + 10., "launched off the car: {top}");
    }

    /// The whole layout as the app builds it: the towers' boxes, the parked cars and every object (hidden ones too)
    pub fn layout_world() -> World {
        let layout = crate::environment::layout();
        let mut models: std::collections::HashMap<String, Arc<Model>> = Default::default();
        let mut objects = Vec::new();
        let mut add = |asset: &str, position: [f32; 3], yaw: f32, scale: f32| {
            let model = models
                .entry(asset.to_string())
                .or_insert_with(|| Arc::new(Model::new(&glb_triangles(&format!("assets/{asset}")))))
                .clone();
            let transform = Transform::from_translation(Vec3::from_array(position))
                .with_rotation(Quat::from_rotation_y(yaw))
                .with_scale(Vec3::splat(scale));
            objects.push(Object { model, transform });
        };
        for c in &layout.cars {
            add(&c.asset, c.position, c.yaw, c.scale);
        }
        for o in &layout.objects {
            add(&o.asset, o.position, o.yaw, o.scale);
        }
        World::new(crate::environment::layout_towers(), &objects)
    }

    #[test]
    fn the_maps_objects_are_points_to_zip_to() {
        let w = layout_world();
        let layout = crate::environment::layout();
        assert!(layout.objects.len() >= 40 && layout.objects.iter().any(|o| o.hidden));
        assert_eq!(w.object_count(), layout.cars.len() + layout.objects.len());
        // every object has ledges on it
        for o in &layout.objects {
            let p = Vec3::from_array(o.position);
            let mut n = 0;
            w.ledges_near(p, 6., |l| n += usize::from(l.a.distance(p) < 8. && l.a.y >= p.y + 0.5));
            assert!(n > 0, "no ledges on {} at {p:?}", o.name);
        }
        // from the street, a camera behind him: (where he stands, what he aims at, the height his feet should get to)
        let cases = [
            ("a lamp post's top", Vec3::new(2., FOOT, -10.), Vec3::new(11.5, 3.7, -10.), 3.7),
            ("the helipad", Vec3::new(16., FOOT, 4.), Vec3::new(30., 3.2, -1.), 3.2),
            ("the scaffold's step", Vec3::new(4., FOOT, -6.), Vec3::new(21., 8., -11.), 8.),
            ("the antenna on the scaffold", Vec3::new(4., FOOT, 4.), Vec3::new(22., 23.2, -17.), 23.2),
            ("the newsstand", Vec3::new(2., FOOT, 6.), Vec3::new(12., 3.35, -1.), 3.35),
            // (from below the roof the roof's own rim is nearer the aim)
            ("tower 1's water tank", Vec3::new(-6., 66., -14.), Vec3::new(-32., 62., -14.), 62.),
            // (from the street side the roof's HVAC plant is nearer the aim)
            ("tower 2's air conditioner (hidden)", Vec3::new(44., 74., -30.), Vec3::new(31., 76.3, -37.), 76.35),
        ];
        for (what, from, at, height) in cases {
            let eye = from + Vec3::Y * 1.5 + (from - at).with_y(0.).normalize() * 4.;
            let p = crate::point_zip::find(&w, from, eye, (at - eye).normalize()).unwrap_or_else(|| panic!("no point on {what}"));
            assert!((p.feet.y - height).abs() < 0.6 && p.feet.with_y(0.).distance(at.with_y(0.)) < 4., "{what}: {p:?}");
        }
        // farther than the game's 45 m: the scaffold's antenna from down the street
        let from = Vec3::new(0., FOOT, 40.);
        let at = Vec3::new(22., 23.2, -17.);
        let eye = from + Vec3::new(0., 1.5, 4.);
        let p = crate::point_zip::find(&w, from, eye, (at - eye).normalize()).expect("a point 60 m away");
        assert!(p.hold.distance(from) > 55. && p.feet.y > 22., "{p:?}");
    }

    #[test]
    fn he_zips_onto_the_scaffold_from_down_the_street_and_launches() {
        use crate::physics::{DT, Hero, Intent, Mode, Tuning};
        let w = layout_world();
        let t = Tuning::default();
        let mut h = Hero::default();
        h.pos = Vec3::new(0., FOOT, 40.);
        h.previous = h.pos;
        h.velocity = Vec3::ZERO;
        h.mode = Mode::Ground;
        let eye = h.pos + Vec3::new(0., 1.5, 4.);
        let at = Vec3::new(22., 23.2, -17.);
        let walk = Intent { forward: Vec3::NEG_Z, right: Vec3::X, aim: (at - eye).normalize(), aim_origin: eye, ..default() };
        h.step(Intent { point_zip: true, ..walk }, &w, &t, DT);
        assert_eq!(h.mode, Mode::Zip);
        let mut pressed = false;
        for _ in 0..600 {
            let mut i = walk;
            if let (Some(z), false) = (h.point_zip, pressed) {
                if z.remaining() < 0.1 {
                    i.jump = true;
                    pressed = true;
                }
            }
            h.step(i, &w, &t, DT);
            if h.point_zip.is_none() {
                break;
            }
        }
        assert_eq!((h.launches, h.launch_fx, h.mode), (1, 2, Mode::Air), "at {:?}", h.pos);
        assert!(h.pos.y - FOOT > 22., "launched from the antenna's top: {:?}", h.pos);
    }

    #[test]
    fn from_the_street_the_camera_looks_up_at_a_roof_to_zip_to() {
        let w = layout_world();
        let t = crate::camera::CameraTuning::default();
        // on the street beside tower 1 (its rim 56 m up), the camera turned to it and tilted up as far as it goes
        let hero = Vec3::new(0., FOOT, -20.);
        let target = hero + Vec3::Y * t.pivot_height;
        let look = -t.look_up_max_degrees.to_radians();
        let (eye, view) = crate::camera::pose(target, Vec3::NEG_X, look, t.follow_distance, 0., &t);
        assert!(eye.y >= t.ground_clearance - 1e-4 && view.y > 0.9, "{eye:?} {view:?}");
        let p = crate::point_zip::find(&w, hero, eye, view).expect("the roof's rim");
        assert!((p.feet.y - 56.).abs() < 0.5 && p.hold.x > -17.5, "{p:?}");
    }
}
