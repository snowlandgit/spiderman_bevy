# Spider-Man Bevy swing sandbox

## For agents: build it, then get the user playing

This repository is complete. The models, animations and configs are already in `assets/`, so building and playing
need neither the original game nor any extraction step. Windows 10/11 x64 is the tested platform.

### 1. Prerequisites

- **Rust through rustup** (https://rustup.rs). `rust-toolchain.toml` pins Rust 1.99.0; rustup installs it on first use.
- **Visual Studio Build Tools** with the *Desktop development with C++* workload (the MSVC linker and Windows SDK).
  Without it the build fails at linking (`link.exe` not found).
- A GPU and driver with DirectX 12 (`Play.bat` selects it).
- Internet access for the first build (cargo downloads the crates) and several GB free for `target/` (about 10 GB with
  the tests).

### 2. Build

From the repository root, in PowerShell:

```powershell
./Build.ps1
```

It runs `cargo build --locked` and copies `target/debug/spiderman_bevy.exe` to the root, next to `assets/`. The first
build compiles Bevy and takes a long time and a lot of CPU and memory. On a machine that struggles under load, build at
below-normal priority with two jobs instead, then copy the executable yourself:

```powershell
./tools/native_oracle/cargo_low.ps1 build --locked
Copy-Item target/debug/spiderman_bevy.exe spiderman_bevy.exe -Force
```

### 3. Check

- `cargo test --workspace` runs 55 tests with no window or GPU. Six of them run the swing, swing jump and fall and
  compare his path with the original game's own runs of the same inputs.
- `./Verify.ps1 -Rebuild` also runs the rendered smoke tests (hidden windows, using the GPU) and the asset checks (they
  need Python with Pillow). Ask the user before running it on a machine that is sensitive to GPU load. Always pass
  `-Rebuild`: the bundled test executable it otherwise uses is not in the repository.
- After changing anything under `crates/sm_traversal`, `cargo test -p sm_traversal` must still pass: it is the check
  against the original game.
- Don't run the other tools in `tools/native_oracle`. They need the original Spider-Man.exe and ArkWeb's research
  harness, which only exist on the author's machine.

### 4. Get the user playing

Tell the user to:

1. Double-click **Play.bat**, or run `spiderman_bevy.exe`. It has to stay next to the `assets` folder.
2. Wait a few seconds until "LOADING SUIT AND CITY ASSETS..." disappears.
3. Hold **W** and **Shift** (or the left mouse button; RT on a controller) to swing down the street, and steer with
   **A** and **D**.
4. Press **Space** (A) during a swing to let go with a jump, or release Shift to let go without one. A fresh press of
   Shift in the air catches the next web at once; holding it catches one as he starts to fall.
5. Click the **right mouse button** to look around with the mouse (**Esc** frees the cursor). **R** resets, **F1**
   shows the controls, **F3** shows diagnostics, **F12** saves a screenshot.

The full controls are in the table under [Play](#play).

### Troubleshooting

- **`link.exe` not found:** install the C++ build tools (above), then build again.
- **Git reports "dubious ownership"** (common on Steam or external drives):
  `git config --global --add safe.directory "<path to the clone>"`.
- **The window stays black or closes at once:** update the GPU driver; the game needs DirectX 12.
- **"LOADING..." never goes away:** the executable can't find `assets/`. It looks next to itself, so keep
  `spiderman_bevy.exe` in the repository root.

A playable Rust / Bevy 0.19.1 recreation in a world containing a floor, seven towers assembled from the game’s original Midtown glass and stone facade kits, and 56 original parked cars at meter scale. It uses the Advanced Suit mesh and animation clips extracted from this local installation of Marvel's Spider-Man Remastered.

**The swing, the swing jump and the fall are the game's own code.** They are ported to Rust in `crates/sm_traversal` from the installed Spider-Man.exe and checked against the executable running offline: the port stays within a few centimetres of the game's path, with every state change on the same frame (see [research/NATIVE_TRAVERSAL.md](research/NATIVE_TRAVERSAL.md)). The swing points, ground movement, wall runs, zips, charged jumps, the dive, collisions, animation blending and materials remain this sandbox's; the game's swing hint volumes, camera code, animation graph, IK and material systems have not been ported. The collapsed-limb conversion bug has been fixed and all clips rebuilt.

## Play

Double-click **Play.bat**, or run `spiderman_bevy.exe` from this folder. The executable has been built for this Windows installation. Assets are found next to the executable, so the runnable folder is independent of the parent game archives.

Swing points come from a fan of rays over the towers ahead of his travel (turned toward the stick). They are scored by where the game's own anchors sat in recorded swinging, best about 18 m up and 32 m away. The pivot is pushed out from the wall as the game's swing point hunter hands it over. A fresh press swings as soon as a point is in reach; holding the button swings again once he is falling.

The swing itself is the game's, with no authored floors or targets. The slow and standard swing setups blend by speed and momentum, momentum builds through swings and falls, and the swing lets go by itself near the top. Releasing the button lets go after the game's two-frame countdown; Space releases with the jump. The swing jump and the fall that follow carry the game's gravity (26 m/s², growing to 30 while falling), its drag and its air steering, which turns him toward the stick without lift. His body turns with the game's own turn spring. The web is thrown 0.35 s into the swing and shoots out; let go, it hangs and drops away. The camera follows his travel 5.5 m back, widening its view from 93 to 111 degrees with speed. `spiderman_bevy_previous.exe` is the build from before this change, kept for comparison.

Forward zips retain momentum and use actual surfaces ahead of the character. Gravity remains active during the shot, kick and follow-through; a zip uses existing upward velocity toward its lift instead of stacking another launch onto an upswing. See [research/ZIP_GRAVITY_REVISION.md](research/ZIP_GRAVITY_REVISION.md). Aim near a reachable roof corner until the white target appears, then press Q to zip onto it.

Wait for the scene to load. Hold **W + Shift** to swing down the street. Release Shift to let go; press Space during a swing to launch upward. Holding swing advances to successive tower anchors. The attachment transitions into the main swing after 0.45 seconds (0.55 from a dive), with an earlier forward leg kick and eased animation blends. Character, animation, webs and camera share interpolated physics snapshots to keep movement smooth between fixed updates. Turn the camera to travel back through the towers, or press R to reset. Hold Space for one second on the ground and release for a high jump, or move while releasing for a long jump.

| Input | Action |
|---|---|
| WASD | Move / steer on the ground, in a swing, or in free fall relative to camera |
| Shift or left mouse | Hold to swing; wall-run on contact |
| Space | Tap for normal jump; hold then release for high jump standing, long jump moving; swing release / wall jump |
| Ctrl | Release the web and dive |
| E or X | Forward web zip using visible tower attachments |
| Q | Zip to the white rooftop target in the camera direction |
| Right mouse | Capture mouse for camera look |
| Esc | Release mouse cursor |
| R | Reset position and momentum |
| F1 | Show / hide controls |
| F3 | Show physics and anchor diagnostics |
| F12 | Save a screenshot in `screenshots/` |
| Controller | Left stick: move, right stick: look, RT: swing, A: jump, LT: dive, X: forward zip, LT + RT: rooftop zip |

## Build and checks

```powershell
./Build.ps1
./Verify.ps1 -Rebuild
```

`Build.ps1` rebuilds and copies the executable next to `assets/`. It detects the project-local Rustup toolchain in `tools/rustup` when present. Rust 1.99.0 is pinned in `rust-toolchain.toml`; rebuilding requires Rustup and the Windows C++ build tools. `Verify.ps1` runs the bundled physics-test executable, compares trajectories with the earlier controller, runs swing, direction reversal, web-zip and charged-jump scenarios with their windows hidden, checks the resulting captures, compares exported animation poses with decoded source samples, and validates the GLB, exported rest transforms against native inverse-bind matrices, and source manifest. After changing Rust source, use `Verify.ps1 -Rebuild` to rebuild and run the current source tests. Playing and the default checks do not require a Rust toolchain; asset validation uses Python (and Pillow for image checks). `--model-preview` captures front, back, and side views for inspecting the converted character.

The simulation steps at 60 Hz, the frame the game's code runs at, and rendering interpolates between steps. `cargo test --workspace` runs 55 tests. Six run the game's swing, swing jump and fall closed loop on the oracle's scenarios and compare his path with the game's own run of them. The rest cover the hookup: swing points ahead of travel in every direction and from the camera when slow, no webs to buildings behind, a held swing letting go by itself and swinging on, the fall's steering without lift, falling from rest, staying out of the towers down the street, the dive, wall contact and jumping, zips (including from a swing, and the game's fall after one), charged jumps, collisions at high speed and a long traversal. Presentation tests cover normalized interrupted animation blends, bounded sampling, camera tracking, and uniform rendered travel at 60, 75, 144 and 240 FPS. The rendered checks load the skeleton and animations, traverse the seven-building scene, check that all 56 car instances load, and save attachment, main-swing, release, direction reversal, zip, rooftop and charged-jump images. Exported poses are independently compared with 212 decoded original bone transforms in thirteen traversal clips. `tools/native_oracle` holds the tools that check the port against the game itself (they need the installed game and ArkWeb's research harness).

## What was recovered

- Original Advanced Suit: 91,378 source vertices, 133,464 triangles, 18 mesh sections and 212 original bones, converted to `assets/character/spiderman.glb`.
- 49 original animation clips plus 19 rest-frame-correct mirrored variants: idle, jogging, sprinting, falling, diving, swing attachment, swing, swing release, swing jumps, wall running, and web zipping. The complete list and durations are in `assets/character/conversion.json`.
- Original swing motion, release, anchor-search and camera configurations, decoded into `assets/tuning/`. The Rust controller reads movement values from the standard swing setup and outdoor/ground web-zip setups.
- Native pseudocode around the swing state, release/jump state and rope manager in `research/swing_decompiled.c`; another 189 selected entries in the nearby swing-code region in `research/swing_core_decompiled.c`. Some are compiler fragments or exception handlers. RTTI gives class names; function labels, most types, and many callees remain unresolved.
- Extracted source files and SHA-256 records in `assets/source/` and `assets/source_manifest.json`. The game executable fingerprint is in `research/swing_vtables.json`.

## Differences from the requested 1:1 result

- The swing, swing jump, fall, traversal tracker and the mover's turn are the game's code (above). Swing points come from a ray fan instead of the game's swing hint volumes. Collisions are the sandbox's: a swing that touches a wall doesn't feed the swing's obstacle probes. The game's dive, its landing and its other jumps are not ported; the sandbox's own remain. See [research/NATIVE_TRAVERSAL.md](research/NATIVE_TRAVERSAL.md); the authored controller it replaced is described in [research/CONTROLLER_REVISION.md](research/CONTROLLER_REVISION.md).
- Charged jumps use original standing up/forward charge-jump clips and the running high-jump clip. Hold Space (controller A) for one second while grounded, then release: standing jumps reach about 25 m, moving jumps cover about 45-65 m depending on forward air input. Descending jumps now use the heavier free-fall gravity. Motion values are independently authored in `assets/tuning/sandbox_jump.json`; native charge-jump runtime parity is not verified.

- Original clip data was converted through a compatibility adaptation of Luna Engine IO Tools. The complete native animation graph, additive-pose evaluation, IK and corrective deformation have not been recreated. The collapsed-limb conversion error was traced to creating zero-length Blender bones and fixed. Every exported rest transform is now verified against the native inverse-bind matrices. The controller uses the forward swing clip named in the native traversal lookup, wrist-attached webs, retimed full-clip intros, full-duration releases and original two-handed zip variants. See [research/WEB_ZIP_ANIMATIONS.md](research/WEB_ZIP_ANIMATIONS.md) for source-pose checks and remaining runtime gaps. Details and pose captures are in `research/RIG_DEFORMATION.md`.
- Skinning exports the strongest four weights per vertex for Bevy. The original rig and mesh sections are retained, but this is not a bit-exact rendering pipeline.
- PBR materials approximate the game's layered shaders. The textures currently use the resident resolution, usually 512 pixels, rather than reconstructed high-resolution streaming textures.
- The camera matches measurements of the real game: 5.5 m back and about 2.2 m up, 93 to 111 degrees of horizontal view with speed, and a yaw that closes in on his travel a second after you last looked around. It is not the game's swing camera code, whose configuration remains available as research (`assets/tuning/hero_swingcameraconfig.json`). See [research/PRESENTATION_REVISION.md](research/PRESENTATION_REVISION.md).

`Rust_Rewrite` was ignored. The parent game's installed files were read for extraction and analysis and were not modified.

## Extraction and research tools

The project retains the extraction and conversion scripts in `tools/`, the intermediate Blender file, and the portable tools used for the conversion. These are not needed to play the executable. Main stages are `extract_assets.py`, `decode_configs.py`, `prepare_model.py`, `convert_textures.py`, and `convert_character.py`. `locate_swing.py` and `DecompileSwing.java` perform the native-code research.

Mesh decoding uses [ALERT](https://github.com/Tkachov/ALERT), archive/config schemas were checked against [Overstrike](https://github.com/Tkachov/Overstrike), and animation decoding uses [Luna Engine IO Tools](https://github.com/Pcniado/luna_engine_io_tools). Their source and license files are retained in the downloaded tool directories. Game assets remain original game content. See `THIRD_PARTY.md` for tool attribution.


## World scale references

The seven towers use the original Midtown glass and stone facade meshes, UVs,
material textures, entrance modules, roof caps and rooftop air-conditioning
models. Tower arrangements are custom assemblies for this sandbox, rather than
copies of particular placed buildings in Manhattan. Heights range from 56 to
92 meters with native 4-meter facade floors. Collision and web-anchor envelopes
are generated from their visible facade bounds.

There are 56 parked original game vehicles: sedans in three paint colors,
yellow hybrid taxis and SUVs. Their original geometry is kept at scale 1:
sedans are 5.17 m long, taxis 4.77 m and SUVs 5.39 m. Car origins are translated
to center the body and place the tires on the floor. Parking positions use a
fixed random seed; cars remain visual props. Four-meter lane dashes provide an
additional motion reference. This scene revision does not retune swing physics.

The native layered vehicle paint and interior window shaders are approximated
using Bevy standard PBR materials. Geometry and textures come from the locally
installed game; roof closure surfaces and lane markings are authored here.

Reproduce world extraction/conversion with `tools/prepare_world.py` followed by
`tools/convert_world.py`. Asset provenance, bounds and checksums are in
`research/world_assets.json`; `tools/validate_world.py` checks units, geometry,
texture dependencies, facade collision bounds and parked-car clearances.
