//! The game's traversal configs (exported by tools/native_oracle/export_config.py from the user's own game: the
//! in-memory config objects, which include the defaults the asset files leave out).
use serde::Deserialize;

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
#[repr(C)]
pub struct SearchParams {
    pub broad_search_radius: f32,
    pub narrow_search_radius: f32,
    pub ideal_line_length_forward: f32,
    pub ideal_line_length_turn: f32,
    pub ideal_angle_forward: f32,
    pub ideal_angle_turn: f32,
    pub ideal_angle_turn_speed_min: f32,
    pub ideal_angle_turn_speed_max: f32,
    pub ideal_angle_fall: f32,
    pub ideal_angle_fall_speed_min: f32,
    pub ideal_angle_fall_speed_max: f32,
    pub ideal_angle_dive: f32,
    pub ideal_angle_dive_speed_min: f32,
    pub ideal_angle_dive_speed_max: f32,
    pub near_ground_distance_min: f32,
    pub near_ground_distance_max: f32,
    pub near_ground_angle: f32,
    pub line_length_fall_tweak: f32,
    pub line_length_dive_tweak: f32,
    pub line_length_tweak_speed_min: f32,
    pub line_length_tweak_speed_max: f32,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
#[repr(C)]
pub struct SpeedParams {
    pub fall_speed_threshold_min: f32,
    pub fall_speed_threshold_mid: f32,
    pub fall_speed_threshold_max: f32,
    pub terminal_velocity_horz_min: f32,
    pub terminal_velocity_horz_mid: f32,
    pub terminal_velocity_horz_max: f32,
    pub terminal_velocity_pure_max: f32,
    pub terminal_velocity_min_percent: f32,
    pub terminal_velocity_min_floor: f32,
    pub terminal_velocity_max_floor: f32,
    pub input_decel_zero: f32,
    pub input_decel_back: f32,
    pub in_speed_carryover: f32,
    pub speed_boost_target: f32,
    pub speed_boost_accel: f32,
    pub speed_boost_accel_accel: f32,
    #[serde(rename = "ReleaseBoostXZ")]
    pub release_boost_xz: f32,
    pub release_boost_alt_min: f32,
    #[serde(rename = "JumpBoostXZ")]
    pub jump_boost_xz: f32,
    pub jump_boost_pitch_low_min: f32,
    pub jump_boost_pitch_low_max: f32,
    pub jump_boost_pitch_high_min: f32,
    pub jump_boost_pitch_high_max: f32,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
#[repr(C)]
pub struct TurnParams {
    pub turn_speed_min_min: f32,
    pub turn_speed_min_max: f32,
    pub turn_speed_max_min: f32,
    pub turn_speed_max_max: f32,
    pub turn_gain_min: f32,
    pub turn_gain_max: f32,
    pub turn_damp_min: f32,
    pub turn_damp_max: f32,
    pub turn_ramp_speed: f32,
    pub turn_speed_tilt_angle_min: f32,
    pub turn_speed_tilt_angle_max: f32,
    pub turn_speed_tilt_scale: f32,
    pub turn_speed_pitch_min: f32,
    pub turn_speed_pitch_max: f32,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
#[repr(C)]
pub struct GravityParams {
    pub gravity_fall_init: f32,
    pub gravity_fall_turn: f32,
    pub gravity_fall_hold: f32,
    pub init_tilt_angle_min: f32,
    pub init_tilt_angle_max: f32,
    pub rise_pitch_angle_min: f32,
    pub rise_pitch_angle_max: f32,
    pub rise_tilt_angle_min: f32,
    pub rise_tilt_angle_max: f32,
    pub rise_low_speed_min: f32,
    pub rise_low_speed_max: f32,
    pub rise_high_speed_min: f32,
    pub rise_high_speed_max: f32,
    pub rise_gravity_low_min: f32,
    pub rise_gravity_low_max: f32,
    pub rise_gravity_high_min: f32,
    pub rise_gravity_high_max: f32,
    pub rise_gravity_low_min_zero: f32,
    pub rise_gravity_low_max_zero: f32,
    pub rise_gravity_high_min_zero: f32,
    pub rise_gravity_high_max_zero: f32,
    pub rise_gravity_low_tilt: f32,
    pub rise_gravity_high_tilt: f32,
    pub rise_line_length_scale: f32,
    pub rise_line_length_min: f32,
    pub rise_line_length_max: f32,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct MotionParams {
    pub speed_params: SpeedParams,
    pub turn_params: TurnParams,
    pub gravity_params: GravityParams,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct ReleaseParamSet {
    pub jump_boost: f32,
    pub vert_floor_base: f32,
    pub vert_floor_jump: f32,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
#[repr(C)]
pub struct ReleaseGravityData {
    pub gravity_release_low: f32,
    pub gravity_release_mid: f32,
    pub gravity_release_high: f32,
    pub gravity_jump_low: f32,
    pub gravity_jump_mid: f32,
    pub gravity_jump_high: f32,
    pub gravity_angle_low: f32,
    pub gravity_angle_mid: f32,
    pub gravity_angle_high: f32,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct ReleaseParams {
    pub params_fall: ReleaseParamSet,
    pub params_low: ReleaseParamSet,
    pub params_middle: ReleaseParamSet,
    pub params_high: ReleaseParamSet,
    pub release_gravity_data: ReleaseGravityData,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct SwingSetup {
    pub search_params: SearchParams,
    pub motion_params: MotionParams,
    pub release_params: ReleaseParams,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct InputBoost {
    pub gravity_scale_max: f32,
    pub gravity_factor_speed: f32,
    pub acceleration_time: f32,
    pub active_acceleration: f32,
    pub max_speed_acceleration: f32,
    pub max_speed_accel_min_speed: f32,
    pub max_speed_accel_max_speed: f32,
}

#[derive(Clone, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct MomentumStage {
    pub momentum_value: f32,
    pub terminal_velocity_horz_floor: f32,
    pub skill_offset_for_horz_floor: Vec<f32>,
    pub gravity_scale: f32,
    pub line_length_tweak: f32,
    pub line_angle_tweak: f32,
    pub true_pivot_factor_start: f32,
    pub true_pivot_factor_trough: f32,
    pub true_pivot_factor_final: f32,
    pub turn_speed_scale: f32,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct DecayData {
    pub momentum_value: f32,
    pub decay_rate: f32,
    pub decay_delay: f32,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct BoostData {
    pub boost: f32,
    pub boost_cap: f32,
    pub retrigger_delay: f32,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct AnglePoint {
    pub angle: f32,
    pub rate: f32,
    pub scale: f32,
}

#[derive(Clone, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct SwingMomentumData {
    pub rate_list: Vec<AnglePoint>,
    pub start_scale: f32,
    pub min_time: f32,
    pub max_time: f32,
    pub boost_cap: f32,
}

#[derive(Clone, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct SwingReleaseMomentumData {
    pub rate_scale_list: Vec<AnglePoint>,
    pub release_data: BoostData,
    pub jump_data: BoostData,
}

#[derive(Clone, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct MomentumConfig {
    pub max_momentum: f32,
    pub decay_data_air: Vec<DecayData>,
    pub decay_data_ground: Vec<DecayData>,
    pub momentum_stages: Vec<MomentumStage>,
    pub swing_data: SwingMomentumData,
    pub swing_release_data: SwingReleaseMomentumData,
    pub fall_data: FallMomentumData,
}

/// MomentumConfig.FallData (HeroSwingConfig +0xc58): momentum gained while falling fast (exe+a71a40)
#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct FallMomentumData {
    pub fall_speed_min: f32,
    pub fall_speed_max: f32,
    pub fall_time_min: f32,
    pub fall_time_max: f32,
    pub fall_time_bias: f32,
    pub fall_gain_min: f32,
    pub fall_gain_max: f32,
    pub fall_momentum_cap_min: f32,
    pub fall_momentum_cap_max: f32,
    pub dive_time_min: f32,
    pub dive_time_max: f32,
    pub dive_time_bias: f32,
    pub dive_gain_min: f32,
    pub dive_gain_max: f32,
    pub dive_momentum_cap_min: f32,
    pub dive_momentum_cap_max: f32,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct RedirectZone {
    pub line_angle_start: f32,
    pub line_angle_end: f32,
    pub exit_angle_start: f32,
    pub exit_angle_end: f32,
    pub exit_bias: f32,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct TransitionData {
    pub forward_action_lookback_time: f32,
}

#[derive(Clone, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct HeroSwingConfig {
    pub input_boost: InputBoost,
    pub transition_data: TransitionData,
    pub release_angle_low_start: f32,
    pub release_angle_low_final: f32,
    pub release_angle_high_start: f32,
    pub release_angle_high_final: f32,
    pub jump_from_fall_horz_damp: f32,
    pub jump_from_fall_horz_min: f32,
    pub jump_redirect_zones: Vec<RedirectZone>,
    pub speed_input_min: f32,
    pub speed_input_mid: f32,
    pub speed_input_max: f32,
    pub speed_input_mid_value: f32,
    pub zero_input_pivot_scale_start: f32,
    pub zero_input_pivot_scale_trough: f32,
    pub zero_input_pivot_scale_final: f32,
    pub momentum_config: MomentumConfig,
}

#[derive(Clone, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct JumpMotionData {
    pub jump_height: f32,
    pub time_to_peak: f32,
    pub time_to_fall: f32,
    pub button_thrust_accel: f32,
    pub button_thrust_accel_grav: f32,
    pub button_thrust_time_max: f32,
    pub velocity_accel_accel_min: f32,
    pub velocity_accel_accel_max: f32,
    pub velocity_accel_time_min: f32,
    pub velocity_accel_time_max: f32,
    pub braking_acceleration: f32,
    pub facing_to_input_time_min: f32,
    pub facing_to_input_time_max: f32,
    pub drag_profile_name: String,
    pub no_input_time: f32,
}

#[derive(Clone, Copy, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct JumpSpeedData {
    pub walk_speed_max: f32,
    pub run_speed_max_min: f32,
    pub run_speed_max_max: f32,
    pub walk_run_threshold: f32,
    pub run_speed_alt_min: f32,
    pub max_accel_speed: f32,
    pub max_accel_delay: f32,
    pub max_accel_accel: f32,
    pub min_launch_speed: f32,
    pub max_launch_speed: f32,
}

#[derive(Clone, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct DragProfile {
    pub profile_name: String,
    pub forward_speed_min: f32,
    pub forward_speed_max: f32,
    pub forward_drag_min: f32,
    pub forward_drag_max: f32,
    pub turn_drag: f32,
    pub no_input_drag: f32,
    pub scale_start_time: f32,
    pub scale_max_time: f32,
    pub scale_max_factor: f32,
    pub turn_blend_in_start: f32,
    pub turn_blend_in_final: f32,
    pub forward_tolerance: f32,
}

#[derive(Clone, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct JumpConfig {
    pub standard_data: JumpMotionData,
}
#[derive(Clone, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct JumpSpeed {
    pub standard_data: JumpSpeedData,
}

#[derive(Clone, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct JumpConfigs {
    pub swing_jump_config: JumpConfig,
    pub swing_jump_speed: JumpSpeed,
    pub dive_jump_speed: JumpSpeed,
    pub ground_jump_speed: JumpSpeed,
    pub default_drag_profile: DragProfile,
    pub drag_profile_list: Vec<DragProfile>,
}

#[derive(Clone, Debug, Default, Deserialize)]
#[serde(rename_all = "PascalCase", default)]
pub struct HeroTraversalConfig {
    pub standard_fall_gravity: f32,
    pub standard_fall_terminal_velocity: f32,
    pub standard_fall_terminal_velocity_max: f32,
    pub standard_fall_term_vel_accel: f32,
    pub jump_configs: JumpConfigs,
}

/// The configs one traversal simulation reads
#[derive(Clone, Debug)]
pub struct Configs {
    pub swing: HeroSwingConfig,
    /// SwingSetupConfig the tracker uses at full momentum or speed (exe+923930, holder +0x8c0)
    pub setup_standard: SwingSetup,
    /// ...and with none (exe+923910, holder +0x8e0): the slow start
    pub setup_slow: SwingSetup,
    /// ...near the ground, for releases (exe+923920, holder +0x900)
    pub setup_ground: SwingSetup,
    pub traversal: HeroTraversalConfig,
}

impl Configs {
    pub fn from_json(swing: &str, standard: &str, slow: &str, ground: &str, traversal: &str) -> serde_json::Result<Self> {
        Ok(Self {
            swing: serde_json::from_str(swing)?,
            setup_standard: serde_json::from_str(standard)?,
            setup_slow: serde_json::from_str(slow)?,
            setup_ground: serde_json::from_str(ground)?,
            traversal: serde_json::from_str(traversal)?,
        })
    }
    /// The configs exported into assets/tuning/native (compiled in)
    pub fn embedded() -> Self {
        Self::from_json(
            include_str!("../../../assets/tuning/native/hero_swing_config.json"),
            include_str!("../../../assets/tuning/native/swing_setup_standard.json"),
            include_str!("../../../assets/tuning/native/swing_setup_open.json"),
            include_str!("../../../assets/tuning/native/swing_setup_ground.json"),
            include_str!("../../../assets/tuning/native/hero_traversal_config.json"),
        )
        .expect("assets/tuning/native configs")
    }
    pub fn drag_profile(&self, name: &str) -> &DragProfile {
        self.traversal
            .jump_configs
            .drag_profile_list
            .iter()
            .find(|d| d.profile_name == name)
            .unwrap_or(&self.traversal.jump_configs.default_drag_profile)
    }
}
