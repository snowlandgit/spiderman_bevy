//! On-screen touch controls for the browser build.
//!
//! Left side of the screen: a floating joystick (touch anywhere there, it appears under the thumb).
//! Right side: action buttons, and any drag that does not start on a button turns the camera.
//! Buttons are hit-tested by hand against every finger, so several can be held at once
//! (Bevy's own UI `Interaction` only follows one finger).
use bevy::input::touch::Touches;
use bevy::prelude::*;

/// Joystick throw, in percent of the window height
const STICK_RADIUS_VH: f32 = 15.;
/// Touches that start left of this fraction of the width (and not on a button) are the joystick
const STICK_ZONE: f32 = 0.42;

#[derive(Clone, Copy, PartialEq)]
pub enum Kind {
    Swing,
    Jump,
    Dive,
    Zip,
    PointZip,
    Drop,
    Reset,
}

struct Spec {
    kind: Kind,
    /// distance of the button's right / bottom edge from the window's, and its diameter, all in percent of the window height
    right: f32,
    bottom: f32,
    size: f32,
    label: &'static str,
}
impl Spec {
    fn centre(&self, win: Vec2) -> Vec2 {
        let u = win.y / 100.;
        Vec2::new(
            win.x - (self.right + self.size / 2.) * u,
            win.y - (self.bottom + self.size / 2.) * u,
        )
    }
    fn hit(&self, p: Vec2, win: Vec2) -> bool {
        p.distance(self.centre(win)) <= self.size / 2. * (win.y / 100.) * 1.2
    }
}
const BUTTONS: [Spec; 7] = [
    Spec { kind: Kind::Swing, right: 4., bottom: 6., size: 26., label: "SWING" },
    Spec { kind: Kind::Jump, right: 32., bottom: 4., size: 20., label: "JUMP" },
    Spec { kind: Kind::Zip, right: 6., bottom: 36., size: 17., label: "ZIP" },
    Spec { kind: Kind::Dive, right: 26., bottom: 28., size: 17., label: "DIVE" },
    Spec { kind: Kind::PointZip, right: 3., bottom: 58., size: 15., label: "POINT\nZIP" },
    Spec { kind: Kind::Drop, right: 57., bottom: 4., size: 14., label: "DROP" },
    Spec { kind: Kind::Reset, right: 2., bottom: 88., size: 10., label: "R" },
];

/// What the fingers are doing this frame; `read_input` merges it with the keyboard and gamepad
#[derive(Resource, Default)]
pub struct TouchState {
    /// a finger has touched the screen at least once
    pub seen: bool,
    pub movement: Vec2,
    /// camera drag this frame, in logical pixels
    pub look: Vec2,
    pub swing: bool,
    pub dive: bool,
    pub jump: bool,
    pub jump_held: bool,
    pub zip: bool,
    pub point_zip: bool,
    pub drop: bool,
    pub reset: bool,
    /// buttons currently held (for the highlight)
    held: Vec<Kind>,
    /// joystick: (where the thumb landed, where it is now)
    stick: Option<(Vec2, Vec2)>,
}

pub struct TouchPlugin;
impl Plugin for TouchPlugin {
    fn build(&self, app: &mut App) {
        app.init_resource::<TouchState>()
            .add_systems(Startup, spawn_ui)
            .add_systems(Update, update_ui);
    }
}

pub fn read_touch(touches: Res<Touches>, window: Single<&Window>, mut state: ResMut<TouchState>) {
    let win = Vec2::new(window.width(), window.height());
    let radius = STICK_RADIUS_VH * win.y / 100.;
    let mut next = TouchState {
        seen: state.seen,
        ..default()
    };
    for touch in touches.iter() {
        next.seen = true;
        let start = touch.start_position();
        if let Some(spec) = BUTTONS.iter().find(|s| s.hit(start, win)) {
            let fresh = touches.just_pressed(touch.id());
            next.held.push(spec.kind);
            match spec.kind {
                Kind::Swing => next.swing = true,
                Kind::Dive => next.dive = true,
                Kind::Jump => {
                    next.jump_held = true;
                    next.jump |= fresh;
                }
                Kind::Zip => next.zip |= fresh,
                Kind::PointZip => next.point_zip |= fresh,
                Kind::Drop => next.drop |= fresh,
                Kind::Reset => next.reset |= fresh,
            }
        } else if start.x < win.x * STICK_ZONE {
            if next.stick.is_none() {
                let d = touch.position() - start;
                let v = Vec2::new(d.x, -d.y) / radius;
                next.movement = if v.length() < 0.12 { Vec2::ZERO } else { v.clamp_length_max(1.) };
                next.stick = Some((start, start + d.clamp_length_max(radius)));
            }
        } else {
            next.look += touch.delta();
        }
    }
    *state = next;
}

#[derive(Component)]
struct TouchButton(Kind);
#[derive(Component)]
struct StickBase;
#[derive(Component)]
struct StickKnob;

const IDLE: Color = Color::srgba(1., 1., 1., 0.16);
const HELD: Color = Color::srgba(1., 1., 1., 0.45);

fn spawn_ui(mut commands: Commands) {
    for s in &BUTTONS {
        commands
            .spawn((
                TouchButton(s.kind),
                Node {
                    position_type: PositionType::Absolute,
                    right: vh(s.right),
                    bottom: vh(s.bottom),
                    width: vh(s.size),
                    height: vh(s.size),
                    justify_content: JustifyContent::Center,
                    align_items: AlignItems::Center,
                    ..default()
                },
                BackgroundColor(IDLE),
                Visibility::Hidden,
            ))
            .with_children(|p| {
                p.spawn((
                    Text::new(s.label),
                    TextFont {
                        font_size: FontSize::Px(12.),
                        ..default()
                    },
                    TextColor(Color::srgba(1., 1., 1., 0.9)),
                ));
            });
    }
    for (is_base, alpha) in [(true, 0.12), (false, 0.4)] {
        let node = Node {
            position_type: PositionType::Absolute,
            ..default()
        };
        let colour = BackgroundColor(Color::srgba(1., 1., 1., alpha));
        if is_base {
            commands.spawn((StickBase, node, colour, Visibility::Hidden));
        } else {
            commands.spawn((StickKnob, node, colour, Visibility::Hidden));
        }
    }
}

fn update_ui(
    state: Res<TouchState>,
    mut buttons: Query<(&TouchButton, &mut BackgroundColor, &mut Visibility)>,
    mut base: Query<
        (&mut Node, &mut Visibility),
        (With<StickBase>, Without<StickKnob>, Without<TouchButton>),
    >,
    mut knob: Query<
        (&mut Node, &mut Visibility),
        (With<StickKnob>, Without<StickBase>, Without<TouchButton>),
    >,
    window: Single<&Window>,
) {
    // always shown in the browser, only after the first touch elsewhere
    let show = cfg!(target_arch = "wasm32") || state.seen;
    for (button, mut colour, mut visibility) in &mut buttons {
        *visibility = if show { Visibility::Visible } else { Visibility::Hidden };
        colour.0 = if state.held.contains(&button.0) { HELD } else { IDLE };
    }
    let radius = STICK_RADIUS_VH * window.height() / 100.;
    if let Ok((mut node, mut visibility)) = base.single_mut() {
        match state.stick {
            Some((start, _)) => {
                node.left = px(start.x - radius);
                node.top = px(start.y - radius);
                node.width = px(radius * 2.);
                node.height = px(radius * 2.);
                *visibility = Visibility::Visible;
            }
            None => *visibility = Visibility::Hidden,
        }
    }
    if let Ok((mut node, mut visibility)) = knob.single_mut() {
        match state.stick {
            Some((_, now)) => {
                let k = radius * 0.5;
                node.left = px(now.x - k);
                node.top = px(now.y - k);
                node.width = px(k * 2.);
                node.height = px(k * 2.);
                *visibility = Visibility::Visible;
            }
            None => *visibility = Visibility::Hidden,
        }
    }
}
