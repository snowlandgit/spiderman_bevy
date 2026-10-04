mod air;
mod animation;
mod camera;
mod environment;
mod jump;
mod loading;
mod zip;
use camera::CameraTuning;
use loading::{SceneReady, SceneReadyPlugin};
#[cfg(not(test))]
mod comparison;
mod native_swing;
mod physics;
mod point_zip;
mod presentation;
mod traversal;
mod world;
use bevy::{
    app::AppExit,
    gltf::Gltf,
    input::{
        gamepad::{GamepadAxis, GamepadButton},
        mouse::AccumulatedMouseMotion,
    },
    light::CascadeShadowConfigBuilder,
    prelude::*,
    render::view::screenshot::{Screenshot, save_to_disk},
    window::{CursorGrabMode, CursorOptions, PresentMode},
    world_serialization::WorldInstanceReady,
};
use physics::*;
use std::{collections::HashMap, path::PathBuf, sync::Arc};

const MODEL: &str = "character/spiderman.glb";
#[derive(Component)]
struct FollowCamera;
#[derive(Component, Default)]
struct HeroVisual {
    swing: u32,
}
#[derive(Component)]
struct WebLine(usize);

/// The swing web as the game's rope manager runs it (ArkWeb's port, native.h, from HeroRopeConfig and 41 recorded
/// swings): thrown 0.35 s into the swing, it shoots out at 40 m/s, rising to 100 m/s along pow(u, 1.2) from 0.1 to 0.4 s
/// after the throw. Let go, its end at the hand follows the hand for 0.15 s, then drops at 1.5 m/s, kept at the web's
/// length from the hold, until it is gone 2 s on (the game dissolves it; here it fades).
#[derive(Resource, Default)]
struct Webs {
    /// the live swing web: (hold, the end at the hand, its hand)
    live: Option<(Vec3, Vec3, usize)>,
    gone: Vec<GoneWeb>,
}
struct GoneWeb {
    hold: Vec3,
    end: Vec3,
    length: f32,
    hand: usize,
    age: f32,
}
const WEB_THROW: f32 = 0.35;
/// How far the web is out `t` seconds after the throw
fn web_out(t: f32) -> f32 {
    if t <= 0. {
        0.
    } else if t <= 0.1 {
        40. * t
    } else if t <= 0.4 {
        let u = t - 0.1;
        4. + 40. * u + 60. * 0.3 / 2.2 * (u / 0.3).powf(2.2)
    } else {
        4. + 12. + 60. * 0.3 / 2.2 + 100. * (t - 0.4)
    }
}
#[derive(Component)]
struct StatusText;
#[derive(Component)]
struct HelpText;
#[derive(Component)]
struct TowerMesh;
#[derive(Component)]
struct Animator(animation::Mixer);
#[derive(Resource)]
struct CharacterAsset(Handle<Gltf>);
#[derive(Resource)]
struct Clips {
    graph: Handle<AnimationGraph>,
    nodes: HashMap<String, AnimationNodeIndex>,
}
#[derive(Resource)]
struct CameraRig {
    yaw: f32,
    pitch: f32,
    follow: camera::Follow,
    locked: bool,

    look_age: f32,
    /// horizontal FOV now (degrees)
    fov: f32,
}
impl Default for CameraRig {
    fn default() -> Self {
        Self {
            yaw: 0.,
            pitch: CameraTuning::default().base_pitch_degrees.to_radians(),
            follow: camera::Follow::default(),
            locked: false,

            look_age: 10.,
            fov: CameraTuning::default().horizontal_fov_degrees,
        }
    }
}
impl CameraRig {
    fn forward(&self) -> Vec3 {
        Vec3::new(-self.yaw.sin(), 0., -self.yaw.cos())
    }
}
/// The collision world's build from the imported meshes (once they have loaded)
#[derive(Resource, Default)]
struct WorldBuild {
    frames: u32,
    done: bool,
}
#[derive(Resource, Default)]
struct DisplayState {
    debug: bool,
    help: bool,
}
#[derive(Resource)]
struct Smoke {
    enabled: bool,
    preview: bool,
    zip_test: bool,
    jump_test: bool,
    direction_test: bool,
    high_jump_peak: f32,
    long_jump_distance: f32,
    long_jump_start: Vec3,
    jump_captures: u32,
    perched: bool,
    frame: u32,
    steps: u32,
    complete: bool,
    loaded: bool,
    captures: u32,
    zip_captures: u32,
    swing_to_zips: u32,
    main_capture: bool,
    first_main_swing_age: Option<f32>,
    max_main_seek_rate: f32,
    max_animation_weight_error: f32,
    max_auto_pitch_degrees: f32,
    max_camera_focus_error: f32,
    interpolated_frames: u32,
    max_interpolation_offset: f32,
    last_drawn_swing: u32,
    new_web_shots: u32,
    behind_web_shots: u32,
    behind_body_shots: u32,
    min_web_shot_lead: Option<f32>,
}

#[cfg(target_arch = "wasm32")]
fn asset_root() -> PathBuf {
    // in the browser the assets are fetched over HTTP, relative to the page
    PathBuf::from("assets")
}
#[cfg(not(target_arch = "wasm32"))]
fn asset_root() -> PathBuf {
    let executable = std::env::current_exe().unwrap();
    let installed = executable.parent().unwrap().join("assets");
    if installed.is_dir() {
        installed
    } else {
        PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("assets")
    }
}
fn main() -> AppExit {
    #[cfg(not(test))]
    if std::env::args().any(|arg| arg == "--physics-report") {
        comparison::write_report();
        return AppExit::Success;
    }
    let _ = std::fs::create_dir_all("screenshots");
    let preview = std::env::args().any(|arg| arg == "--model-preview");
    let zip_test = std::env::args().any(|arg| arg == "--zip-smoke-test");
    let jump_test = std::env::args().any(|arg| arg == "--jump-smoke-test");
    let direction_test = std::env::args().any(|arg| arg == "--direction-smoke-test");
    let smoke = direction_test
        || jump_test
        || zip_test
        || preview
        || std::env::args().any(|arg| arg == "--smoke-test");
    App::new()
        .add_plugins(
            DefaultPlugins
                .set(AssetPlugin {
                    file_path: asset_root().to_string_lossy().into_owned(),
                    // the web server has no .meta files; don't request them
                    meta_check: bevy::asset::AssetMetaCheck::Never,
                    ..default()
                })
                .set(WindowPlugin {
                    primary_window: Some(Window {
                        title: "Spider-Man | Bevy Swing Sandbox".into(),
                        resolution: (1440, 900).into(),
                        present_mode: PresentMode::AutoVsync,
                        #[cfg(target_arch = "wasm32")]
                        canvas: Some("#bevy".into()),
                        #[cfg(target_arch = "wasm32")]
                        fit_canvas_to_parent: true,
                        #[cfg(target_arch = "wasm32")]
                        prevent_default_event_handling: true,
                        visible: !std::env::args().any(|arg| arg == "--headless"),
                        ..default()
                    }),
                    ..default()
                }),
        )
        .add_plugins(SceneReadyPlugin)
        .insert_resource(ClearColor(Color::srgb(0.48, 0.59, 0.69)))
        .insert_resource(GlobalAmbientLight {
            color: Color::srgb(0.8, 0.86, 1.),
            brightness: 450.,
            ..default()
        })
        .insert_resource(Time::<Fixed>::from_hz(60.))
        .init_resource::<Arena>()
        .init_resource::<WorldBuild>()
        .init_resource::<Tuning>()
        .init_resource::<Hero>()
        .init_resource::<presentation::Snapshots>()
        .init_resource::<Webs>()
        .init_resource::<presentation::RenderedHero>()
        .init_resource::<Intent>()
        .init_resource::<CameraRig>()
        .init_resource::<CameraTuning>()
        .init_resource::<animation::ClipTiming>()
        .insert_resource(DisplayState {
            debug: false,
            help: true,
        })
        .insert_resource(Smoke {
            enabled: smoke,
            preview,
            zip_test,
            jump_test,
            direction_test,
            high_jump_peak: 0.,
            long_jump_distance: 0.,
            long_jump_start: Vec3::ZERO,
            jump_captures: 0,
            perched: false,
            frame: 0,
            steps: 0,
            complete: false,
            loaded: false,
            captures: 0,
            zip_captures: 0,
            swing_to_zips: 0,
            main_capture: false,
            first_main_swing_age: None,
            max_main_seek_rate: 0.,
            max_animation_weight_error: 0.,
            max_auto_pitch_degrees: 0.,
            max_camera_focus_error: 0.,
            interpolated_frames: 0,
            max_interpolation_offset: 0.,
            last_drawn_swing: 0,
            new_web_shots: 0,
            behind_web_shots: 0,
            behind_body_shots: 0,
            min_web_shot_lead: None,
        })
        .add_systems(Startup, setup)
        .add_systems(PreUpdate, read_input.after(bevy::input::InputSystems))
        .add_systems(FixedUpdate, simulate)
        .add_systems(
            Update,
            (
                build_world,
                load_character,
                presentation::update_render,
                animate,
                update_visual,
                update_camera,
                update_hud,
                smoke_test,
            )
                .chain(),
        )
        .add_systems(
            PostUpdate,
            draw_web
                .after(bevy::transform::TransformSystems::Propagate)
                .before(bevy::camera::visibility::VisibilitySystems::VisibilityPropagate),
        )
        .run()
}

fn setup(
    mut commands: Commands,
    asset_server: Res<AssetServer>,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
) {
    let model = if std::env::args().any(|a| a == "--rest-pose") {
        "character/spiderman_rest.glb"
    } else {
        MODEL
    };
    commands.insert_resource(CharacterAsset(asset_server.load(model)));
    commands.spawn((
        Name::new("Floor"),
        Mesh3d(meshes.add(Plane3d::default().mesh().size(1800., 1800.))),
        MeshMaterial3d(materials.add(StandardMaterial {
            base_color: Color::srgb(0.32, 0.34, 0.36),
            perceptual_roughness: 0.95,
            ..default()
        })),
        Transform::default(),
    ));
    environment::spawn(&mut commands, &asset_server);
    // Four-meter lane dashes give ground-level motion a consistent scale reference.
    let paint = materials.add(StandardMaterial {
        base_color: Color::srgb(0.85, 0.82, 0.63),
        perceptual_roughness: 0.95,
        ..default()
    });
    let dash = meshes.add(Cuboid::new(0.12, 0.015, 4.));
    for z in (-300..40).step_by(8) {
        commands.spawn((
            Name::new("Street center line"),
            Mesh3d(dash.clone()),
            MeshMaterial3d(paint.clone()),
            Transform::from_xyz(0., 0.012, z as f32),
        ));
    }
    commands.spawn((
        DirectionalLight {
            illuminance: 18000.,
            shadow_maps_enabled: true,
            ..default()
        },
        Transform::from_rotation(Quat::from_euler(EulerRot::XYZ, -0.85, -0.55, 0.)),
        CascadeShadowConfigBuilder {
            first_cascade_far_bound: 20.,
            maximum_distance: 240.,
            ..default()
        }
        .build(),
    ));
    commands.spawn((
        Camera3d::default(),
        FollowCamera,
        Transform::from_xyz(0., 21., 16.).looking_at(Vec3::new(0., 19., 8.), Vec3::Y),
        Projection::Perspective(PerspectiveProjection {
            fov: 56f32.to_radians(),
            far: 2000.,
            ..default()
        }),
        DistanceFog {
            color: Color::srgb(0.48, 0.59, 0.69),
            falloff: FogFalloff::Linear {
                start: 140.,
                end: 600.,
            },
            ..default()
        },
    ));
    let webmat = materials.add(StandardMaterial {
        base_color: Color::srgb(0.91, 0.95, 1.),
        unlit: true,
        ..default()
    });
    let webmesh = meshes.add(Cylinder::new(0.014, 1.));
    for hand in 0..2 {
        commands.spawn((
            WebLine(hand),
            Mesh3d(webmesh.clone()),
            MeshMaterial3d(webmat.clone()),
            Visibility::Hidden,
            Transform::default(),
        ));
    }
    commands.spawn((
        Text::new("SPIDER-MAN  /  SWING SANDBOX"),
        TextFont {
            font_size: FontSize::Px(22.),
            ..default()
        },
        TextColor(Color::WHITE),
        Node {
            position_type: PositionType::Absolute,
            left: px(26),
            top: px(22),
            ..default()
        },
    ));
    commands.spawn((
        StatusText,
        Text::new("LOADING ORIGINAL SUIT..."),
        TextFont {
            font_size: FontSize::Px(17.),
            ..default()
        },
        TextColor(Color::srgb(0.78, 0.89, 1.)),
        Node {
            position_type: PositionType::Absolute,
            left: px(26),
            top: px(55),
            ..default()
        },
    ));
    commands.spawn((HelpText,Text::new("WASD  Move / steer     SHIFT or LMB  Hold to swing     SPACE  Tap jump / hold then release high or long jump\nCTRL  Dive     E/X  Air zip     Q  Zip to the marked point (SPACE as you arrive: point launch)     C  Drop off a perch     R  Reset\nRMB  Look     ESC  Free cursor     F1  Hide controls     F3  Debug     F12  Screenshot\nController: RT swing / A jump / X zip / LT+RT zip to point, A as you arrive to launch / B drop"),
        TextFont {font_size:FontSize::Px(16.),..default()},TextColor(Color::srgb(0.91,0.93,0.95)),
        Node {position_type:PositionType::Absolute,left:px(26),bottom:px(24),..default()}));
    commands.spawn((
        Text::new("+"),
        TextFont {
            font_size: FontSize::Px(22.),
            ..default()
        },
        TextColor(Color::srgba(1., 1., 1., 0.7)),
        Node {
            position_type: PositionType::Absolute,
            left: percent(50),
            top: percent(47),
            ..default()
        },
    ));
}

/// Builds the collision world once the environment has loaded: the authored boxes, then every [`MeshCollider`]
/// scene's meshes where they stand (one model per mesh, shared by all its placements)
///
/// [`MeshCollider`]: environment::MeshCollider
fn build_world(
    mut arena: ResMut<Arena>,
    mut build: ResMut<WorldBuild>,
    environment: Res<environment::EnvironmentAssets>,
    server: Res<AssetServer>,
    roots: Query<Entity, With<environment::MeshCollider>>,
    children: Query<&Children>,
    parts: Query<(&Mesh3d, &GlobalTransform)>,
    meshes: Res<Assets<Mesh>>,
) {
    if build.done || !environment.ready(&server) {
        return;
    }
    // a couple of frames after the scenes are in, their transforms have propagated
    build.frames += 1;
    if build.frames < 3 {
        return;
    }
    let mut models: HashMap<AssetId<Mesh>, Arc<world::Model>> = HashMap::new();
    let mut objects = Vec::new();
    for root in &roots {
        for e in children.iter_descendants(root) {
            let Ok((mesh3d, global)) = parts.get(e) else {
                continue;
            };
            let Some(mesh) = meshes.get(&mesh3d.0) else {
                continue;
            };
            let model = models
                .entry(mesh3d.0.id())
                .or_insert_with(|| {
                    let mut tris = Vec::new();
                    world::mesh_triangles(mesh, &GlobalTransform::IDENTITY, &mut tris);
                    Arc::new(world::Model::new(&tris))
                })
                .clone();
            if model.triangle_count() > 0 {
                objects.push(world::Object { model, transform: global.compute_transform() });
            }
        }
    }
    let towers = arena.0.towers.clone();
    arena.0 = world::World::new(towers, &objects);
    build.done = true;
    info!(
        "collision world: {} boxes, {} placed meshes ({} distinct), {} triangles, {} perch ledges",
        arena.0.towers.len(),
        arena.0.object_count(),
        models.len(),
        arena.0.triangle_count(),
        arena.0.ledges.len()
    );
}

fn read_input(
    keys: Res<ButtonInput<KeyCode>>,
    time: Res<Time>,
    mouse: Res<ButtonInput<MouseButton>>,
    motion: Res<AccumulatedMouseMotion>,
    pads: Query<&Gamepad>,
    window: Single<&Window>,
    mut cursor: Single<&mut CursorOptions>,
    camera: Single<&Transform, With<FollowCamera>>,
    mut rig: ResMut<CameraRig>,
    mut intent: ResMut<Intent>,
    mut display: ResMut<DisplayState>,
    smoke: Res<Smoke>,
    mut commands: Commands,
    mut aiming: Local<bool>,
    camera_tuning: Res<CameraTuning>,
) {
    let look_up = camera_tuning.look_up_max_degrees.to_radians();
    if smoke.enabled {
        return;
    }
    if !window.focused {
        intent.cancel_jump_charge = true;
        intent.jump_held = false;
        intent.jump = false;
        intent.swing = false;
        intent.movement = Vec2::ZERO;
        intent.dive = false;
        intent.zip = false;
        intent.point_zip = false;
        intent.drop = false;
        rig.locked = false;
        cursor.grab_mode = CursorGrabMode::None;
        cursor.visible = true;
        return;
    }
    if mouse.just_pressed(MouseButton::Right) {
        rig.locked = true;
        cursor.grab_mode = CursorGrabMode::Locked;
        cursor.visible = false;
    }
    if keys.just_pressed(KeyCode::Escape) {
        rig.locked = false;
        cursor.grab_mode = CursorGrabMode::None;
        cursor.visible = true;
    }
    if rig.locked {
        if motion.delta.length_squared() > 0. {
            rig.look_age = 0.;
        }
        rig.yaw -= motion.delta.x * 0.0025;
        rig.pitch = (rig.pitch + motion.delta.y * 0.002).clamp(-look_up, 1.1);
    }
    let mut movement = Vec2::new(
        (keys.pressed(KeyCode::KeyD) as u8 as f32) - (keys.pressed(KeyCode::KeyA) as u8 as f32),
        (keys.pressed(KeyCode::KeyW) as u8 as f32) - (keys.pressed(KeyCode::KeyS) as u8 as f32),
    );
    let mut swing = keys.pressed(KeyCode::ShiftLeft)
        || keys.pressed(KeyCode::ShiftRight)
        || mouse.pressed(MouseButton::Left);
    let mut dive = keys.pressed(KeyCode::ControlLeft) || keys.pressed(KeyCode::ControlRight);
    let mut jump = keys.just_pressed(KeyCode::Space);
    let mut jump_held = keys.pressed(KeyCode::Space);
    let mut zip = keys.just_pressed(KeyCode::KeyE) || keys.just_pressed(KeyCode::KeyX);
    let mut point_zip = keys.just_pressed(KeyCode::KeyQ);
    let mut drop = keys.just_pressed(KeyCode::KeyC);
    for pad in &pads {
        let stick = Vec2::new(
            pad.get(GamepadAxis::LeftStickX).unwrap_or(0.),
            pad.get(GamepadAxis::LeftStickY).unwrap_or(0.),
        );
        if stick.length() > 0.13 {
            movement = stick;
        }
        let lt = pad.pressed(GamepadButton::LeftTrigger2);
        let rt = pad.pressed(GamepadButton::RightTrigger2);
        swing |= rt;
        // LT held on from the zip-to-point chord is aiming at the next point, not the dive
        if lt && rt {
            *aiming = true;
        } else if !lt {
            *aiming = false;
        }
        dive |= lt && !*aiming;
        if lt && rt {
            dive = false;
            swing = false;
        }
        drop |= pad.just_pressed(GamepadButton::East);
        jump |= pad.just_pressed(GamepadButton::South);
        jump_held |= pad.pressed(GamepadButton::South);
        zip |= pad.just_pressed(GamepadButton::West);
        point_zip |= pad.pressed(GamepadButton::LeftTrigger2)
            && pad.just_pressed(GamepadButton::RightTrigger2);
        if pad.get(GamepadAxis::RightStickX).unwrap_or(0.).abs() > 0.13
            || pad.get(GamepadAxis::RightStickY).unwrap_or(0.).abs() > 0.13
        {
            rig.look_age = 0.;
        }
        rig.yaw -= pad.get(GamepadAxis::RightStickX).unwrap_or(0.) * 2.1 * time.delta_secs();
        rig.pitch = (rig.pitch
            - pad.get(GamepadAxis::RightStickY).unwrap_or(0.) * 1.5 * time.delta_secs())
        .clamp(-look_up, 1.1);
    }
    let forward = rig.forward();
    intent.movement = movement.clamp_length_max(1.);
    intent.forward = forward;
    intent.right = forward.cross(Vec3::Y);
    intent.swing = swing;
    intent.dive = dive;
    intent.cancel_jump_charge = false;
    intent.jump_held = jump_held;
    intent.jump |= jump;
    intent.zip |= zip;
    intent.point_zip |= point_zip;
    intent.drop |= drop;
    intent.aim = *camera.forward();
    intent.aim_origin = camera.translation;
    intent.reset |= keys.just_pressed(KeyCode::KeyR);
    if keys.just_pressed(KeyCode::F1) {
        display.help = !display.help;
    }
    if keys.just_pressed(KeyCode::F3) {
        display.debug = !display.debug;
    }
    if keys.just_pressed(KeyCode::F12) {
        commands
            .spawn(Screenshot::primary_window())
            .observe(save_to_disk("screenshots/swing.png"));
    }
}

fn simulate(
    mut hero: ResMut<Hero>,
    mut input: ResMut<Intent>,
    arena: Res<Arena>,
    tuning: Res<Tuning>,
    mut smoke: ResMut<Smoke>,
    time: Res<Time<Fixed>>,
    mut snapshots: ResMut<presentation::Snapshots>,
    real_time: Res<Time<Real>>,
    ready: Res<SceneReady>,
    environment: Res<environment::EnvironmentAssets>,
    server: Res<AssetServer>,
    world_build: Res<WorldBuild>,
) {
    if !world_build.done
        || !environment.ready(&server)
        || !smoke.loaded
        || ready.stable_frames < 30
        || real_time.elapsed_secs() < 2.
    {
        return;
    }
    if smoke.enabled {
        let step = smoke.steps;
        let cycle = step % 340;
        *input = Intent {
            movement: Vec2::Y,
            forward: Vec3::NEG_Z,
            right: Vec3::X,
            swing: cycle < 280,
            jump: cycle == 279,
            dive: cycle > 315,
            reset: step == 1900,
            ..default()
        };
        if smoke.direction_test {
            let cycle = step % 350;
            if cycle == 0 {
                let count = hero.swing_count;
                let (position, velocity) = match step / 350 {
                    0 => (Vec3::new(0., 18., -40.), Vec3::Z * 24.),
                    1 => (Vec3::new(0., 18., -80.), Vec3::X * 24.),
                    _ => (Vec3::new(0., 18., -160.), Vec3::NEG_Z * 24.),
                };
                *hero = Hero::default();
                hero.swing_count = count;
                hero.pos = position;
                hero.previous = position;
                hero.velocity = velocity;
                hero.heading = -velocity.normalize();
            }
            *input = Intent {
                swing: cycle < 260,
                ..default()
            };
        }
        if smoke.zip_test {
            *input = Intent {
                forward: Vec3::NEG_Z,
                movement: if step < 100 { Vec2::Y } else { Vec2::ZERO },
                swing: step < 100,
                zip: matches!(step, 100 | 270 | 440),
                ..default()
            };
            if step == 550 {
                hero.pos = Vec3::new(6., 70., -43.);
                hero.previous = hero.pos;
                hero.velocity = Vec3::ZERO;
                hero.mode = Mode::Air;
                hero.mode_age = 0.;
                hero.rope = None;
                hero.zip_motion = None;
                hero.point_zip = None;
                hero.perch = None;
                hero.native.stop(time.delta_secs());
                hero.zip_cooldown = 0.;
                input.point_zip = true;
                input.aim = (Vec3::new(16.7, 72.95, -31.7) - hero.pos).normalize();
            }
            if step > 600 && hero.mode == Mode::Perch && hero.pos.y > 60. {
                smoke.perched = true;
            }
        }
        if smoke.jump_test {
            if matches!(step, 0 | 450) {
                *hero = Hero::default();
                hero.pos = Vec3::new(0., FOOT, 8.);
                hero.previous = hero.pos;
                hero.velocity = Vec3::ZERO;
                hero.mode = Mode::Ground;
                if step == 450 {
                    hero.ground_jump_count = 1;
                }
            }
            *input = Intent {
                forward: Vec3::NEG_Z,
                movement: if step >= 450 { Vec2::Y } else { Vec2::ZERO },
                jump: matches!(step, 1 | 451),
                jump_held: (1..140).contains(&step) || (451..590).contains(&step),
                ..default()
            };
            if step < 450 {
                smoke.high_jump_peak = smoke.high_jump_peak.max(hero.pos.y - FOOT);
            } else {
                if step == 590 {
                    smoke.long_jump_start = hero.pos;
                }
                if step > 590 && hero.mode == Mode::Air {
                    smoke.long_jump_distance = smoke
                        .long_jump_distance
                        .max((hero.pos - smoke.long_jump_start).with_y(0.).length());
                }
            }
        }
        if smoke.preview {
            *hero = Hero::default();
            hero.pos = Vec3::new(0., FOOT, 8.);
            hero.previous = hero.pos;
            hero.velocity = Vec3::ZERO;
            hero.heading = Vec3::Z;
            hero.mode = Mode::Ground;
            *input = Intent::default();
        }
        smoke.steps += 1;
    }
    let before = hero.clone();
    hero.step(*input, &arena.0, &tuning, time.delta_secs());
    if smoke.zip_test && before.rope.is_some() && hero.zip_count > before.zip_count {
        smoke.swing_to_zips += 1;
    }
    snapshots.capture(&before, &hero, time.elapsed_secs_f64(), input.reset);
    input.cancel_jump_charge = false;
    input.jump = false;
    input.zip = false;
    input.point_zip = false;
    input.drop = false;
    input.reset = false;
}

fn load_character(
    mut commands: Commands,
    asset: Res<CharacterAsset>,
    gltfs: Res<Assets<Gltf>>,
    server: Res<AssetServer>,
    mut graphs: ResMut<Assets<AnimationGraph>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
    existing: Option<Res<Clips>>,
) {
    if existing.is_some() || !server.is_loaded_with_dependencies(&asset.0) {
        return;
    }
    let Some(gltf) = gltfs.get(&asset.0) else {
        return;
    };
    if std::env::args().any(|a| a == "--flat-normals") {
        for (_, m) in materials.iter_mut() {
            m.normal_map_texture = None;
        }
    }
    if std::env::args().any(|a| a == "--two-sided") {
        for (_, m) in materials.iter_mut() {
            m.cull_mode = None;
        }
    }
    let mut names: Vec<String> = gltf
        .named_animations
        .keys()
        .map(|n| n.to_string())
        .collect();
    names.sort();
    let handles = names
        .iter()
        .map(|name| gltf.named_animations[name.as_str()].clone())
        .collect::<Vec<_>>();
    let (graph, nodes) = AnimationGraph::from_clips(handles);
    let graph = graphs.add(graph);
    let mapping = names.into_iter().zip(nodes).collect();
    commands.insert_resource(Clips {
        graph,
        nodes: mapping,
    });
    let scene = gltf
        .default_scene
        .clone()
        .unwrap_or_else(|| gltf.scenes[0].clone());
    commands
        .spawn((
            Name::new("Original Advanced Suit"),
            HeroVisual::default(),
            Transform::default(),
            WorldAssetRoot(scene),
        ))
        .observe(bind_animation);
}
fn bind_animation(
    ready: On<WorldInstanceReady>,
    mut commands: Commands,
    children: Query<&Children>,
    mut players: Query<&mut AnimationPlayer>,
    clips: Res<Clips>,
    mut smoke: ResMut<Smoke>,
) {
    smoke.loaded = true;
    for entity in children.iter_descendants(ready.entity) {
        if let Ok(mut player) = players.get_mut(entity) {
            let Some(index) = clips.nodes.get("fall_cycle_spiderman").copied() else {
                continue;
            };
            player.start(index).repeat().set_speed(0.);
            commands.entity(entity).insert((
                AnimationGraphHandle(clips.graph.clone()),
                Animator(animation::Mixer::new("fall_cycle_spiderman")),
            ));
            smoke.loaded = true;
        }
    }
}
fn animate(
    rendered: Res<presentation::RenderedHero>,
    clips: Option<Res<Clips>>,
    timing: Res<animation::ClipTiming>,
    time: Res<Time>,
    mut players: Query<(&mut AnimationPlayer, &mut Animator)>,
    mut smoke: ResMut<Smoke>,
) {
    let hero = &rendered.hero;
    let Some(clips) = clips else { return };
    if smoke.enabled && smoke.steps > 0 && rendered.interpolated {
        smoke.interpolated_frames += 1;
        smoke.max_interpolation_offset = smoke.max_interpolation_offset.max(rendered.offset);
    }
    let pose = animation::pose(hero, &timing);
    let dt = time.delta_secs();
    for (mut player, mut animator) in &mut players {
        let previous = animator.0.current.clone();
        let previous_seek = animator.0.current_seek();
        animator.0.update(&pose, hero.mode, &timing, dt);
        let weight_error = (animator.0.layers.iter().map(|l| l.weight).sum::<f32>() - 1.).abs();
        smoke.max_animation_weight_error = smoke.max_animation_weight_error.max(weight_error);
        if smoke.enabled && smoke.steps > 0 && pose.clip.starts_with("web_swing_fwd_rh_spiderman") {
            smoke.first_main_swing_age = Some(
                smoke
                    .first_main_swing_age
                    .unwrap_or(f32::INFINITY)
                    .min(hero.mode_age),
            );
            if previous == animator.0.current && dt > 0. {
                smoke.max_main_seek_rate = smoke
                    .max_main_seek_rate
                    .max((animator.0.current_seek() - previous_seek).abs() / dt.min(0.1));
            }
        }
        let stale = player
            .playing_animations()
            .filter_map(|(index, _)| {
                (!animator
                    .0
                    .layers
                    .iter()
                    .any(|l| clips.nodes.get(&l.clip) == Some(index)))
                .then_some(*index)
            })
            .collect::<Vec<_>>();
        for index in stale {
            player.stop(index);
        }
        for layer in &animator.0.layers {
            if let Some(index) = clips.nodes.get(&layer.clip) {
                player
                    .play(*index)
                    .repeat()
                    .set_speed(0.)
                    .set_weight(layer.weight)
                    .set_seek_time(layer.seek);
            }
        }
    }
}
fn update_visual(
    rendered: Res<presentation::RenderedHero>,
    time: Res<Time>,
    mut visual: Query<(&mut Transform, &mut HeroVisual)>,
) {
    let hero = &rendered.hero;
    for (mut transform, mut visual) in &mut visual {
        transform.translation = hero.pos - Vec3::Y * FOOT;
        // The source suit's face points toward +Z in glTF.
        // In the game's swing, swing jump and fall his mover turns him (its turn spring): the heading is that facing.
        let native = hero.native.active();
        let facing = if native {
            hero.heading
        } else if matches!(hero.mode, Mode::Air | Mode::Dive | Mode::Swing) {
            swing_direction(hero, hero.heading)
        } else {
            hero.heading
        };
        let yaw = facing.x.atan2(facing.z);
        let target = if hero.mode == Mode::Wall {
            // Wall-run clips already contain the vertical body pose in their reference wall space.
            let facing = -hero.wall_normal;
            transform.translation = hero.pos - Vec3::Y * FOOT;
            Quat::from_rotation_y(facing.x.atan2(facing.z))
        } else {
            Quat::from_rotation_y(yaw)
        };
        // A new shot and the visible body must share their forward frame immediately.
        if native && hero.mode != Mode::Wall {
            transform.rotation = target;
        } else if hero.rope.is_some() && visual.swing != hero.swing_count {
            transform.rotation = target;
        } else {
            transform.rotation = transform
                .rotation
                .slerp(target, 1. - (-14. * time.delta_secs()).exp());
        }
        visual.swing = hero.swing_count;
    }
}
fn draw_web(
    rendered: Res<presentation::RenderedHero>,
    time: Res<Time>,
    mut webs: ResMut<Webs>,
    mut web: Query<(
        &WebLine,
        &mut Transform,
        &mut GlobalTransform,
        &mut Visibility,
    )>,
    names: Query<(&Name, &GlobalTransform), Without<WebLine>>,
    display: Res<DisplayState>,
    arena: Res<Arena>,
    input: Res<Intent>,
    mut gizmos: Gizmos,
    mut smoke: ResMut<Smoke>,
    visuals: Query<&GlobalTransform, (With<HeroVisual>, Without<WebLine>)>,
) {
    let hero = &rendered.hero;
    let hand_at = |index: usize| {
        let joint = if index == 0 { "LF_wrist" } else { "RT_wrist" };
        names
            .iter()
            .find(|(name, _)| name.as_str() == joint)
            .map(|(_, t)| t.translation())
            .filter(|p| p.distance(hero.pos) < 4.)
            .unwrap_or(hero.pos + Vec3::Y * 0.7)
    };
    let mut anchors = [None, None];
    // how far each web is out (the swing's shoots out; zips' are out at once)
    let mut out = [f32::INFINITY; 2];
    let swing_hand = if hero.swing_left { 0 } else { 1 };
    if let Some(rope) = hero.rope {
        let thrown = hero.mode_age - WEB_THROW;
        if thrown > 0. {
            anchors[swing_hand] = Some(rope.anchor);
            out[swing_hand] = web_out(thrown);
        }
    } else if let Some(zip) = hero.zip_motion {
        if hero.mode_age >= 0.12 && hero.mode_age <= 0.48 {
            anchors = zip.anchors;
        }
    } else if let Some(z) = hero.point_zip {
        if hero.mode_age >= 0.12 {
            anchors = [Some(z.perch.hold), Some(z.perch.hold)];
        }
    }
    // a swing web let go: it hangs from its hold and drops away
    let dt = time.delta_secs().clamp(0., 0.1);
    if let (Some((hold, end, hand)), false) =
        (webs.live, hero.rope.is_some() && anchors[swing_hand].is_some())
    {
        webs.gone.push(GoneWeb { hold, end, length: hold.distance(end), hand, age: 0. });
        webs.live = None;
    }
    for g in &mut webs.gone {
        g.age += dt;
        if g.age < 0.15 {
            g.end = hand_at(g.hand);
        } else {
            g.end.y -= 1.5 * dt;
            g.end = g.hold + (g.end - g.hold).normalize_or_zero() * g.length;
        }
    }
    webs.gone.retain(|g| g.age < 2.15);
    if webs.gone.len() > 3 {
        let extra = webs.gone.len() - 3;
        webs.gone.drain(..extra);
    }
    for g in &webs.gone {
        let fade = (1. - (g.age - 0.15).max(0.) / 2.).clamp(0., 1.);
        gizmos.line(g.hold, g.end, Color::srgba(0.95, 0.97, 1., 0.85 * fade));
    }
    for (line, mut transform, mut global, mut visibility) in &mut web {
        if let Some(anchor) = anchors[line.0] {
            let hand = hand_at(line.0);
            let full = anchor - hand;
            let shown = full.length().min(out[line.0]);
            if line.0 == swing_hand && hero.rope.is_some() {
                webs.live = Some((anchor, hand, line.0));
            }
            let delta = full.normalize_or_zero() * shown;
            let anchor = hand + delta;
            if smoke.enabled && hero.rope.is_some() && smoke.last_drawn_swing != hero.swing_count {
                let lead = delta.dot(swing_direction(hero, hero.heading));
                smoke.last_drawn_swing = hero.swing_count;
                smoke.new_web_shots += 1;
                smoke.behind_web_shots += u32::from(lead <= 0.);
                if let Some(body) = visuals.iter().next() {
                    let visible_forward =
                        (body.rotation() * Vec3::Z).with_y(0.).normalize_or_zero();
                    smoke.behind_body_shots += u32::from(delta.dot(visible_forward) <= 0.);
                }
                smoke.min_web_shot_lead =
                    Some(smoke.min_web_shot_lead.map_or(lead, |old| old.min(lead)));
            }
            transform.translation = (anchor + hand) * 0.5;
            transform.rotation = Quat::from_rotation_arc(Vec3::Y, delta.normalize_or_zero());
            transform.scale = Vec3::new(1., delta.length(), 1.);
            *global = GlobalTransform::from(*transform);
            *visibility = Visibility::Visible;
            if display.debug {
                gizmos.sphere(
                    Isometry3d::from_translation(anchor),
                    0.35,
                    Color::srgb(0.3, 0.8, 1.),
                );
            }
        } else {
            *visibility = Visibility::Hidden;
        }
    }
    // the point a zip would go to: a light diamond facing the camera round it, 2 % of its distance across (ArkWeb's)
    let eye = if input.aim_origin == Vec3::ZERO { hero.pos + Vec3::Y * 0.6 } else { input.aim_origin };
    if hero.point_zip.is_none() {
        if let Some(p) = point_zip::find(&arena.0, hero.pos, eye, input.aim) {
            let to_eye = (eye - p.hold).normalize_or(Vec3::Z);
            let right = Vec3::Y.cross(to_eye).normalize_or(Vec3::X);
            let up = to_eye.cross(right);
            let r = (eye.distance(p.hold) * 0.02).max(0.12);
            let corners = [p.hold + up * r, p.hold + right * r, p.hold - up * r, p.hold - right * r];
            for k in 0..4 {
                gizmos.line(corners[k], corners[(k + 1) % 4], Color::srgb(0.55, 0.85, 1.));
            }
        }
    }
    if display.debug {
        // the perch ledges nearby (on buildings and imported objects alike)
        arena.0.ledges_near(hero.pos, 25., |l| {
            if l.a.distance(hero.pos) < 25. {
                gizmos.line(l.a, l.b, Color::srgba(1., 0.8, 0.2, 0.6));
            }
        });
    }
    if display.debug {
        let wish = input.forward * input.movement.y + input.right * input.movement.x;
        if let Some(point) =
            traversal::find_swing_point(hero.pos, hero.velocity, wish, input.forward, &arena.0)
        {
            gizmos.sphere(
                Isometry3d::from_translation(point.attach),
                0.6,
                Color::srgb(0.2, 1., 0.5),
            );
            gizmos.sphere(
                Isometry3d::from_translation(point.anchor),
                0.3,
                Color::srgb(0.2, 0.6, 1.),
            );
        }
        gizmos.line(
            hero.pos,
            hero.pos + hero.velocity * 0.25,
            Color::srgb(1., 0.6, 0.2),
        );
    }
}
fn update_camera(
    rendered: Res<presentation::RenderedHero>,
    arena: Res<Arena>,
    time: Res<Time>,
    mut rig: ResMut<CameraRig>,
    mut smoke: ResMut<Smoke>,
    config: Res<CameraTuning>,
    mut camera: Single<(&mut Transform, &mut Projection), With<FollowCamera>>,
) {
    let hero = &rendered.hero;
    if smoke.preview {
        let angle = if smoke.steps < 180 {
            0.35f32
        } else if smoke.steps < 600 {
            3.3
        } else {
            1.5
        };
        camera.0.translation = hero.pos + Vec3::new(angle.sin() * 3., 0.6, angle.cos() * 3.);
        camera.0.look_at(hero.pos + Vec3::Y * 0.05, Vec3::Y);
        if let Projection::Perspective(p) = &mut *camera.1 {
            p.fov = 45f32.to_radians();
        }
        return;
    }
    let dt = time.delta_secs().clamp(0., 0.1);
    rig.look_age += dt;
    if !rig.locked && rig.look_age > config.auto_yaw_delay && hero.velocity.with_y(0.).length() > 5.
    {
        rig.yaw = camera::follow_yaw(rig.yaw, hero.heading, dt, &config);
    }
    rig.follow.update(&hero, dt, &config);
    smoke.max_auto_pitch_degrees = smoke
        .max_auto_pitch_degrees
        .max(rig.follow.auto_pitch.to_degrees().abs());
    smoke.max_camera_focus_error = smoke
        .max_camera_focus_error
        .max(rig.follow.focus.distance(hero.pos));
    let forward = rig.forward();
    let target = rig.follow.focus + Vec3::Y * config.pivot_height;
    let look = (rig.pitch + rig.follow.auto_pitch).clamp(-config.look_up_max_degrees.to_radians(), 1.2);
    // the floor under the camera (the street, or a roof he stands on); then the boom as far as nothing is in its way
    let at = camera.0.translation;
    let floor = arena.0.ground_below(Vec3::new(at.x, target.y + 0.5, at.z));
    let (reach, _) = camera::pose(target, forward, look, config.follow_distance, floor, &config);
    let boom = reach - target;
    let mut allowed = config.follow_distance;
    if let Some(hit) = arena.0.raycast(target, boom.normalize_or(Vec3::Y), boom.length()) {
        allowed = allowed.min((hit.t - 0.35).max(0.7));
    }
    rig.follow.constrain_distance(allowed, dt, &config);
    let (eye, view) = camera::pose(target, forward, look, rig.follow.distance, floor, &config);
    camera.0.translation = eye;
    camera.0.look_to(view, Vec3::Y);
    rig.fov = camera::speed_fov(rig.fov, hero.velocity.length(), dt, &config);
    if let Projection::Perspective(projection) = &mut *camera.1 {
        projection.fov =
            2. * ((rig.fov.to_radians() * 0.5).tan() / projection.aspect_ratio).atan();
    }
}

fn update_hud(
    hero: Res<Hero>,
    tuning: Res<Tuning>,
    display: Res<DisplayState>,
    clips: Option<Res<Clips>>,
    ready: Res<SceneReady>,
    environment: Res<environment::EnvironmentAssets>,
    server: Res<AssetServer>,
    mut status: Single<&mut Text, With<StatusText>>,
    mut help: Single<&mut Visibility, With<HelpText>>,
) {
    **status = Text::new(
        if clips.is_none() || !environment.ready(&server) || ready.stable_frames < 30 {
            "LOADING SUIT AND CITY ASSETS...".into()
        } else if display.debug {
            format!(
                "{}  |  {:0.0} km/h  |  {:0.1} m  |  {} swings\nvelocity  {:0.1} / {:0.1} / {:0.1}  |  rope {:0.1} m  |  error {:0.4} m",
                hero.mode.label(),
                hero.velocity.length() * 3.6,
                hero.pos.y - FOOT,
                hero.swing_count,
                hero.velocity.x,
                hero.velocity.y,
                hero.velocity.z,
                hero.rope.map(|r| r.length).unwrap_or(0.),
                hero.max_rope_error
            )
        } else {
            format!(
                "{}    {:0.0} km/h    {:0.0} m",
                if let Some(charge) = hero.jump_charge {
                    format!(
                        "JUMP CHARGE {:0.0}%",
                        charge / tuning.jump.full_charge_seconds * 100.
                    )
                } else if hero.since_launch < 1.2 {
                    match hero.launch_fx {
                        2 => "POINT LAUNCH  BOOST".into(),
                        1 => "POINT LAUNCH  (EARLY)".into(),
                        _ => "POINT LAUNCH".into(),
                    }
                } else {
                    hero.mode.label().into()
                },
                hero.velocity.length() * 3.6,
                hero.pos.y - FOOT
            )
        },
    );
    **help = if display.help {
        Visibility::Visible
    } else {
        Visibility::Hidden
    };
}
fn smoke_test(
    mut commands: Commands,
    mut smoke: ResMut<Smoke>,
    hero: Res<Hero>,
    towers: Query<Entity, With<TowerMesh>>,
    cars: Query<Entity, With<environment::ParkedCar>>,
    environment: Res<environment::EnvironmentAssets>,
    server: Res<AssetServer>,
    players: Query<&AnimationPlayer>,
    animators: Query<&Animator>,
    mut exit: MessageWriter<AppExit>,
) {
    if !smoke.enabled || smoke.complete {
        return;
    }
    smoke.frame += 1;
    if smoke.frame % 300 == 0 && smoke.steps == 0 {
        eprintln!(
            "SCENE_LOADING character={} {}",
            smoke.loaded,
            environment.diagnostics(&server)
        );
    }
    if smoke.frame == 120 && smoke.steps == 0 {
        commands
            .spawn(Screenshot::primary_window())
            .observe(save_to_disk("screenshots/world_loading.png"));
    }
    for (step, label) in [(90, "swing"), (300, "release"), (750, "traversal")] {
        if !smoke.zip_test
            && !smoke.jump_test
            && smoke.loaded
            && smoke.steps >= step
            && smoke.captures
                < (if step == 90 {
                    1
                } else if step == 300 {
                    2
                } else {
                    3
                })
        {
            commands
                .spawn(Screenshot::primary_window())
                .observe(save_to_disk(format!(
                    "screenshots/{}{label}.png",
                    if smoke.direction_test {
                        "direction_"
                    } else {
                        ""
                    }
                )));
            smoke.captures += 1;
        }
    }
    if !smoke.zip_test
        && !smoke.jump_test
        && !smoke.main_capture
        && smoke.steps > 0
        && animators.iter().any(|a| {
            a.0.current.starts_with("web_swing_fwd_rh_spiderman")
                && a.0
                    .layers
                    .iter()
                    .any(|l| l.clip == a.0.current && l.weight > 0.3)
        })
    {
        commands
            .spawn(Screenshot::primary_window())
            .observe(save_to_disk(if smoke.direction_test {
                "screenshots/direction_swing_main.png"
            } else {
                "screenshots/swing_main.png"
            }));
        smoke.main_capture = true;
    }
    if smoke.zip_test {
        for (number, step, label) in [
            (1, 127, "zip_fire"),
            (2, 184, "zip_flight"),
            (3, 645, "roof_zip"),
        ] {
            if smoke.loaded && smoke.steps >= step && smoke.zip_captures < number {
                commands
                    .spawn(Screenshot::primary_window())
                    .observe(save_to_disk(format!("screenshots/{label}.png")));
                smoke.zip_captures += 1;
            }
        }
    }
    if smoke.jump_test {
        for (number, step, label) in [
            (1, 80, "jump_charge"),
            (2, 200, "high_jump"),
            (3, 660, "long_jump"),
        ] {
            if smoke.loaded && smoke.steps >= step && smoke.jump_captures < number {
                commands
                    .spawn(Screenshot::primary_window())
                    .observe(save_to_disk(format!("screenshots/{label}.png")));
                smoke.jump_captures += 1;
            }
        }
    }
    if smoke.steps > 1000 || smoke.frame > 3600 {
        let loaded =
            smoke.loaded && environment.ready(&server) && (!players.is_empty() || smoke.preview);
        let passed = loaded
            && towers.iter().count() == 7
            && cars.iter().count() == environment::layout().cars.len()
            && hero.pos.is_finite()
            && smoke.max_animation_weight_error < 0.0001
            && smoke.max_auto_pitch_degrees <= 8.001
            && smoke.max_camera_focus_error <= 1.251
            && smoke.behind_web_shots == 0
            && smoke.behind_body_shots == 0
            && (smoke.preview
                || if smoke.jump_test {
                    hero.ground_jump_count >= 2
                        && smoke.high_jump_peak > 24.
                        && smoke.long_jump_distance > 45.
                } else if smoke.zip_test {
                    hero.zip_count >= 4 && smoke.swing_to_zips > 0 && smoke.perched
                } else if smoke.direction_test {
                    smoke.new_web_shots >= 3
                } else {
                    hero.swing_count > 0 && smoke.new_web_shots > 0
                });
        let report = serde_json::json!({"passed":passed,"loaded":loaded,"towers":towers.iter().count(),"cars":cars.iter().count(),"environment_loaded":environment.ready(&server),"environment_diagnostics":environment.diagnostics(&server),"character_loaded":smoke.loaded,"steps":smoke.steps,"swings":hero.swing_count,"zips":hero.zip_count,"swing_to_zips":smoke.swing_to_zips,"perched":smoke.perched,"ground_jumps":hero.ground_jump_count,"high_jump_peak":smoke.high_jump_peak,"long_jump_distance":smoke.long_jump_distance,"peak_speed":hero.peak_speed,"max_rope_error":hero.max_rope_error,"position":[hero.pos.x,hero.pos.y,hero.pos.z],"web_selection":{"new_shots":smoke.new_web_shots,"behind_shots":smoke.behind_web_shots,"behind_body_shots":smoke.behind_body_shots,"minimum_rendered_shot_lead":smoke.min_web_shot_lead},"presentation":{"first_main_swing_age":smoke.first_main_swing_age,"main_swing_captured":smoke.main_capture,"max_main_seek_rate":smoke.max_main_seek_rate,"max_blend_weight_error":smoke.max_animation_weight_error,"max_auto_pitch_degrees":smoke.max_auto_pitch_degrees,"max_camera_focus_error":smoke.max_camera_focus_error,"horizontal_fov_degrees":[CameraTuning::default().horizontal_fov_degrees,CameraTuning::default().fast_fov_degrees],"interpolated_frames":smoke.interpolated_frames,"max_interpolation_offset":smoke.max_interpolation_offset}});
        let saved = match std::fs::write(
            if smoke.direction_test {
                "direction_smoke_report.json"
            } else if smoke.jump_test {
                "jump_smoke_report.json"
            } else if smoke.zip_test {
                "zip_smoke_report.json"
            } else {
                "smoke_report.json"
            },
            serde_json::to_string_pretty(&report).unwrap(),
        ) {
            Ok(()) => true,
            Err(error) => {
                eprintln!("Could not save rendered verification report: {error}");
                false
            }
        };
        smoke.complete = true;
        exit.write(if passed && saved {
            AppExit::Success
        } else {
            AppExit::error()
        });
    }
}
