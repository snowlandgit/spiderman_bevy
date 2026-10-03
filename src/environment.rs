//! Original game vehicles and facade kits, assembled in a simple street sandbox, and any other glTF the layout places.
//!
//! What collides: a building with an authored box (`center`, `half`) collides as that box; anything else the layout
//! places (a building without one, the cars, the `objects`) collides as its own meshes, and the ledges on them are
//! perch points (crate::world). Any glTF scene spawned with a [`MeshCollider`] on its root joins the same way.
use crate::physics::Tower;
use bevy::{gltf::Gltf, prelude::*, world_serialization::WorldInstanceReady};
use serde::Deserialize;
use std::collections::{HashMap, HashSet};

#[derive(Deserialize)]
pub struct Building {
    pub asset: String,
    pub name: String,
    pub position: [f32; 3],
    /// the authored collision box (without one, the building's meshes collide)
    pub center: Option<[f32; 3]>,
    pub half: Option<[f32; 3]>,
}
#[derive(Deserialize)]
pub struct Car {
    pub asset: String,
    pub position: [f32; 3],
    pub yaw: f32,
    pub scale: f32,
}
/// Any glTF placed in the world (its meshes collide, its ledges are perch points)
#[derive(Deserialize)]
pub struct Object {
    pub asset: String,
    #[serde(default)]
    pub name: String,
    pub position: [f32; 3],
    #[serde(default)]
    pub yaw: f32,
    #[serde(default = "one")]
    pub scale: f32,
    /// collides (and offers its ledges) without being drawn: for what another model already shows
    #[serde(default)]
    pub hidden: bool,
}
fn one() -> f32 {
    1.
}
#[derive(Deserialize)]
pub struct Layout {
    pub buildings: Vec<Building>,
    pub cars: Vec<Car>,
    #[serde(default)]
    pub objects: Vec<Object>,
}
pub fn layout() -> Layout {
    serde_json::from_str(include_str!("../assets/world/layout.json")).unwrap()
}
/// The authored boxes of the layout's buildings
pub fn layout_towers() -> Vec<Tower> {
    layout()
        .buildings
        .into_iter()
        .filter_map(|b| {
            Some(Tower {
                center: Vec3::from_array(b.center?),
                half: Vec3::from_array(b.half?),
            })
        })
        .collect()
}
#[derive(Component)]
pub struct ParkedCar;
/// A scene whose meshes collide (and offer perch points): put it on any glTF scene's root
#[derive(Component)]
pub struct MeshCollider;
#[derive(Resource, Default)]
pub struct EnvironmentAssets {
    handles: Vec<Handle<Gltf>>,
    expected: usize,
    spawned: HashSet<Entity>,
}
impl EnvironmentAssets {
    pub fn diagnostics(&self, server: &AssetServer) -> serde_json::Value {
        serde_json::json!({"spawned":self.spawned.len(),"expected":self.expected,
            "models":self.handles.iter().map(|h| serde_json::json!({
                "path":server.get_path(h.id()).map(|p|p.to_string()),
                "state":format!("{:?}",server.get_load_states(h.id()))
            })).collect::<Vec<_>>()})
    }
    pub fn ready(&self, server: &AssetServer) -> bool {
        self.spawned.len() == self.expected
            && self
                .handles
                .iter()
                .all(|handle| server.is_loaded_with_dependencies(handle))
    }
}
fn instance_ready(event: On<WorldInstanceReady>, mut assets: ResMut<EnvironmentAssets>) {
    assets.spawned.insert(event.entity);
}
pub fn spawn(commands: &mut Commands, server: &AssetServer) {
    let layout = layout();
    let mut assets = EnvironmentAssets {
        expected: layout.buildings.len() + layout.cars.len() + layout.objects.len(),
        ..default()
    };
    let mut models = HashMap::new();
    for asset in layout
        .buildings
        .iter()
        .map(|b| &b.asset)
        .chain(layout.cars.iter().map(|c| &c.asset))
        .chain(layout.objects.iter().map(|o| &o.asset))
    {
        if !models.contains_key(asset) {
            let handle: Handle<Gltf> = server.load(asset.clone());
            assets.handles.push(handle.clone());
            models.insert(asset.clone(), handle);
        }
    }
    for (index, b) in layout.buildings.into_iter().enumerate() {
        let mut e = commands.spawn((
            super::TowerMesh,
            Name::new(format!("{} tower {}", b.name, index + 1)),
            Transform::from_translation(Vec3::from_array(b.position)),
            WorldAssetRoot(server.load(format!("{}#Scene0", b.asset))),
        ));
        if b.center.is_none() || b.half.is_none() {
            e.insert(MeshCollider);
        }
        e.observe(instance_ready);
    }
    for (index, car) in layout.cars.into_iter().enumerate() {
        commands
            .spawn((
                ParkedCar,
                MeshCollider,
                Name::new(format!("Original game parked car {}", index + 1)),
                Transform::from_translation(Vec3::from_array(car.position))
                    .with_rotation(Quat::from_rotation_y(car.yaw))
                    .with_scale(Vec3::splat(car.scale)),
                WorldAssetRoot(server.load(format!("{}#Scene0", car.asset))),
            ))
            .observe(instance_ready);
    }
    for (index, o) in layout.objects.into_iter().enumerate() {
        commands
            .spawn((
                MeshCollider,
                Name::new(if o.name.is_empty() { format!("Object {}", index + 1) } else { o.name }),
                Transform::from_translation(Vec3::from_array(o.position))
                    .with_rotation(Quat::from_rotation_y(o.yaw))
                    .with_scale(Vec3::splat(o.scale)),
                if o.hidden { Visibility::Hidden } else { Visibility::Inherited },
                WorldAssetRoot(server.load(format!("{}#Scene0", o.asset))),
            ))
            .observe(instance_ready);
    }
    commands.insert_resource(assets);
}
