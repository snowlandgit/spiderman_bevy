use bevy::{
    prelude::*,
    render::{ExtractSchedule, MainWorld, RenderApp, render_resource::PipelineCache},
};

#[derive(Resource, Default)]
pub struct SceneReady {
    pub stable_frames: u32,
}
pub struct SceneReadyPlugin;
impl Plugin for SceneReadyPlugin {
    fn build(&self, app: &mut App) {
        app.init_resource::<SceneReady>();
        app.sub_app_mut(RenderApp)
            .add_systems(ExtractSchedule, update_ready);
    }
}
fn update_ready(mut main_world: ResMut<MainWorld>, pipelines: Res<PipelineCache>) {
    if let Some(mut ready) = main_world.get_resource_mut::<SceneReady>() {
        ready.stable_frames = if pipelines.waiting_pipelines().count() == 0 {
            ready.stable_frames.saturating_add(1)
        } else {
            0
        };
    }
}
