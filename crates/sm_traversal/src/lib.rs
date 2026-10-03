//! A port of Marvel's Spider-Man Remastered's swing, swing jump, fall and point launch (Spider-Man.exe 4.0630),
//! independent of any engine. The traversal tracker blends the game's swing setups and keeps momentum; the swing state
//! integrates the swing round its (virtual) pivot; the air states carry the release and the launches. tools/native_oracle
//! runs the game's own code on the same inputs; the tests compare against its records.
pub mod air;
pub mod config;
pub mod math;
pub mod oracle;
pub mod point_launch;
pub mod replay;
pub mod sim;
pub mod swing;
pub mod tracker;
pub mod turn;

pub use config::Configs;
pub use math::{Rows, V3};
