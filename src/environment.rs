//! Original game vehicles and facade kits, assembled in a simple street sandbox.
use bevy::{gltf::Gltf, prelude::*, world_serialization::WorldInstanceReady};
use serde::Deserialize;
use std::collections::{HashMap, HashSet};

#[derive(Deserialize)]
pub struct Building {
    pub asset: String,
    pub name: String,
    pub position: [f32; 3],
    pub center: [f32; 3],
    pub half: [f32; 3],
}
#[derive(Deserialize)]
pub struct Car {
    pub asset: String,
    pub position: [f32; 3],
    pub yaw: f32,
    pub scale: f32,
}
#[derive(Deserialize)]
pub struct Layout {
    pub buildings: Vec<Building>,
    pub cars: Vec<Car>,
}
pub fn layout() -> Layout {
    serde_json::from_str(include_str!("../assets/world/layout.json")).unwrap()
}
#[derive(Component)]
pub struct ParkedCar;
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
        expected: layout.buildings.len() + layout.cars.len(),
        ..default()
    };
    let mut models = HashMap::new();
    for asset in layout
        .buildings
        .iter()
        .map(|b| &b.asset)
        .chain(layout.cars.iter().map(|c| &c.asset))
    {
        if !models.contains_key(asset) {
            let handle: Handle<Gltf> = server.load(asset.clone());
            assets.handles.push(handle.clone());
            models.insert(asset.clone(), handle);
        }
    }
    for (index, b) in layout.buildings.into_iter().enumerate() {
        commands
            .spawn((
                super::TowerMesh,
                Name::new(format!("{} tower {}", b.name, index + 1)),
                Transform::from_translation(Vec3::from_array(b.position)),
                WorldAssetRoot(server.load(format!("{}#Scene0", b.asset))),
            ))
            .observe(instance_ready);
    }
    for (index, car) in layout.cars.into_iter().enumerate() {
        commands
            .spawn((
                ParkedCar,
                Name::new(format!("Original game parked car {}", index + 1)),
                Transform::from_translation(Vec3::from_array(car.position))
                    .with_rotation(Quat::from_rotation_y(car.yaw))
                    .with_scale(Vec3::splat(car.scale)),
                WorldAssetRoot(server.load(format!("{}#Scene0", car.asset))),
            ))
            .observe(instance_ready);
    }
    commands.insert_resource(assets);
}
