# Native traversal: the game's swing, swing jump, fall and point launch

The sandbox's swing, its release, the time in the air after it and the point launch are now Spider-Man.exe 4.0630's own
code, ported to Rust in `crates/sm_traversal` and checked against the executable running offline. (The zip to a point
and the point launch: [ZIP_TO_POINT.md](ZIP_TO_POINT.md).) This replaces the authored controller in
CONTROLLER_REVISION.md, SWING_WEIGHT_REVISION.md, HEIGHT_CARRY_REVISION.md and AIR_CONTROL_REVISION.md. That controller
used gravity floors of 44/52/64 m/s², a 4 m entry-drop cap, a 28 m/s driven speed target, a horizontal cap and its own
release rules. Those documents describe what was replaced.

## What runs

| Part | Game code (RVA) | Port |
|---|---|---|
| Traversal tracker: momentum, the blend of the slow and standard swing setups by speed and momentum, fall gravity and terminal velocity | 85f580, 8630f0, 864660 | `tracker.rs` |
| Swing entry, its frame (4-substep integrator round the virtual pivot, steering, caps, floor guard, facing), release check (button, jump event, automatic release) and release velocity/gravity | ab97e0, ac30e0, abdb30, aba1f0, ac2200, ac1680 | `swing.rs` |
| The swing's exit on the tracker: speed blend, release momentum (SwingReleaseData) | aba8a0, ac1430, 861de0, 861290 | `SwingLocal::exit` |
| The swing jump and the fall: entry, speeds (SwingJumpSpeed), target speed, drag (TraversalJumpDrag), steering, vertical with the apex gravity switch, facing toward the input over FacingToInputTime, the fall's gravity growth (+3 m/s per second up to 30), its momentum from falling fast (FallData) | a86490, a70080, a8d5b0, a88ec0, a87a70, a8b140, a8b1d0, a8b520, a8c7f0, a8c3c0, a8beb0, a706a0, a71a40 | `air.rs` |
| The swing jump's hand-over to the fall (TryFall) | a87f10, a885c0, 96e580 | `AirLocal::check` |
| The jump state's motion and speed data by kind (the swing jump, the point launch 0x2a, the jump off a perch 0x1d, a fall with no jump before it) | a87910, a879d0 | `air::motion_data`, `air::speed_data` |
| The point launch: its direction, the press's boost, the exit data, the checks ahead | b1d640, b19fb0, b1d250, b1be00 | `point_launch.rs` |
| The jump off a perch (the ground jump's numbers), the button thrust | 974c90, 868850, a87b90 | `AirEntry::ground_jump`, `AirLocal` |
| The mover's turn toward the facing a state asks for (per-state springs) | 1fc0800 → 1c46be0 | `turn.rs` (ArkWeb turn.h) |
| The frame: tracker, transition, update, move, turn | (the state machine) | `sim.rs` |

The configs the port reads are the user's own game's, in `assets/tuning/native/`. They were exported from config objects
in memory, defaults included, by `tools/native_oracle/export_config.py`.

## How it is checked

`tools/native_oracle/oracle.exe` maps the installed Spider-Man.exe without starting it. It patches engine services with
stand-ins (ArkWeb's research harness) and runs the game's own swing, swing jump and fall on scripted scenarios
(`tools/native_oracle/scenarios/*.txt`), recording every frame's state objects.

- `oracle_diff <record>`: every frame of the port is run from the game's own state and compared field by field. Over
  six scenarios (jump release, steering through the swing, plain release, automatic release at the top, steering in the
  air, a second swing from the fall):
  - air frames: 1,174, every one identical (displacement error 0);
  - swing frames: displacement within 0.06 mm;
  - entries, releases, the jump-to-fall hand-over and the tracker: identical on every frame.
- `oracle_replay <scenario> <record>`: the port runs closed loop from the scenario's starting conditions alone. Its path
  stays within 0.8 to 3.2 cm of the game's over 4 to 7 seconds, every state change happens on the same frame, and the
  facing is within 0.1 degree.
- Five more scenarios enter the jump state or the fall directly (the scenario key `enter`): the point launch three ways,
  the jump off a perch, the fall from a ledge. Each of their 780 air frames is identical, and closed loop the port
  follows the game's path exactly (see [ZIP_TO_POINT.md](ZIP_TO_POINT.md)).
- `cargo test -p sm_traversal` runs the same closed-loop comparison against the game's paths kept in
  `crates/sm_traversal/tests/fixtures` (all eleven scenarios), so the check runs without the game.

The tools need the installed game and ArkWeb's harness (H:\arkre). The records are kept out of the project.

## What the sandbox supplies

`src/traversal.rs` stands in for the game's world:

- **The swing point.** The game's hunter scores swing hint volumes placed over New York's buildings, and the sandbox has
  none. Points come from ArkWeb's fan instead, cast against the world (`src/world.rs`: the buildings' boxes and any
  imported object's meshes): 7 × 7 rays, 22 to 70 degrees up and up to 50 to either side of his
  heading (his travel, else the camera, turned toward the stick), 70 m long. They are scored by where the game's own
  anchors sat in recorded swinging: best 18 m up and 32 m away, straight ahead. Points under 8 m up, nearer than 12 m or
  more than 80 degrees off are refused. The pivot is pushed out from a wall along its normal by 0.75 × the horizontal
  distance, kept between 1 and 6 m, as the hunter hands it over.
- **Inputs.** The stick, the swing button and the jump button's release event (buffered 0.05 s, as the game's input
  buffer does). The release countdown, the 0.2 s minimum swing and the automatic release are the game's.
- **When a swing starts.** A fresh press swings when a point is in reach; a held button swings again once he is falling.
  The game's own transition-manager probe for this is not decoded.
- **Collisions and landings** are the sandbox's. A landing or a wall ends the native states. Touching something during
  a swing does not reach the swing's obstacle probes; they read clear, as in the research harness.
- **The step** is 60 Hz, the frame the game's code and the recordings run at. Rendering interpolates between steps.

## Presentation

- **Facing.** His body faces the way the game's mover turned him (its turn spring), with no extra smoothing.
- **Web.** The web follows the game's rope manager as ArkWeb ported it:
  - it is thrown 0.35 s into the swing;
  - it shoots out at 40 m/s, rising to 100 m/s along pow(u, 1.2) from 0.1 to 0.4 s after the throw;
  - let go, its end follows the hand for 0.15 s, then drops at 1.5 m/s on the web's length and fades over 2 s.

  The waving strand is not reproduced.
- **Camera.** Measured from recordings of the real game:
  - 5.5 m behind him and about 2.2 m above;
  - horizontal FOV from 93 degrees slow to 111 degrees at speed, between HeroSwingCameraConfig's FOV boost speeds (10
    and 33 m/s) at 13 degrees per second;
  - the yaw closes in on his heading a second after the last look input.

  The game's swing camera code is not ported.
- **Animation.** The sandbox's clips are driven by the native values: the swing phase is the game's angle round the
  swing, and the release pose comes from the release's pitch and whether it was a jump.

## Not modelled

- Platforms.
- Wall contact during the air states.
- Animation-driven jumps.
- Spline and focus targets.
- The game's dive. Ctrl / LT keeps the sandbox's dive, which leaves the native states.
- The game's ground jumps and landings (the jump off a perch is the one ground jump ported).
- The camera and animation hints the swing's exit leaves on the tracker.
- Ground decay of momentum: the tracker always uses the air list, as tools/native_oracle runs it.
