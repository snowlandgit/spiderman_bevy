# Swing controller revision

The current entry-height, unilateral-web and gravity corrections are documented
in [SWING_WEIGHT_REVISION.md](SWING_WEIGHT_REVISION.md). The recovery and
comparison notes below describe the earlier controller revision.

The first playable controller did not reproduce the original game's swing feel. This revision replaces several arbitrary behaviors with equations recovered from the locally installed executable. It remains a partial port: the complete native traversal and animation evaluation have not been reconstructed.

## Evidence and implementation

`src/native_swing.rs` implements the recovered scalar/vector calculations. `src/physics.rs` supplies the independent Bevy state machine, surface search, integration and collisions.

| Native entry | Recovered behavior | Implementation scope |
|---|---|---|
| `0x140abf160` | Building anchor projected into the plane of travel; pitch-dependent pivot factor; factor only decreases during a line | Projection and factor curves, with interpolated config momentum stages. Turning-specific factor reduction and the native controller's implicit input-offset defaults remain incomplete. |
| `0x140ab38e0` | Entry terminal target from line length, elevation and incoming fall speed; retain higher incoming horizontal speed | Scalar calculation ported. No fixed 14 m/s attachment impulse. |
| `0x140ac0b60` | Ascending gravity interpolates by pitch, speed, plane tilt, input and radius; descending gravity ramps from its initial value | Standard-mode calculation ported. The outer momentum-stage gravity multiplier and stage acquisition are independently integrated. Native special traversal modes are incomplete. |
| `0x140abd610` | Initial gravity blend depends on entry alignment, pitch and horizontal line distance; delay of 0.2 seconds | Initial blend calculation ported; recovered substep loop ramps the blend at 1.25 per second after the delay. |
| `0x140abf580` | Velocity caps scale the whole vector and preserve pitch | Uniform caps and radius-scaled total cap implemented. Native terminal-target damping/braking details remain incomplete. |
| `0x140ac1680` | Jump release adds the selected vertical boost before enforcing a minimum; low/mid/high gravity interpolation | Additive boosts and angle-based selection implemented. Complete jump redirection, contextual bonuses, jump banking and release animation selection are incomplete. Gravity-angle endpoint defaults are inferred as 0 and 90 degrees. |
| `0x140ac2200` | Release eligibility depends on angle and radius, with a low-speed branch | Radius/angle gate implemented with an independent turnaround fallback. Its planar angle approximation is not a complete port of the native oriented frame or contextual transition logic. |

The standard swing integrator's recovered loop runs four substeps. The Bevy controller now does the same within each 120 Hz physics step. It conserves speed while redirecting entry motion into the arc, removes the previous continuous forward thrust and timed 3.2-second cutoff, and waits for descending motion before automatically selecting a successive line. Turning changes horizontal velocity direction while preserving its magnitude; the full native damped steering controller is not ported.

The displayed web connects to the real tower surface. The physics constraint uses the projected pivot. Surface ranking follows decoded ideal angle/length settings and rejects occluded anchors; its floor-clearance adjustment is independent logic.

## Field interpretation

`tools/map_native_layout.py` resolves config property CRCs against the original PE's reflection tables. The gravity property hash array starts at file offset `0x3ac93a0`; float members begin after an eight-byte header. This resolved a potentially misleading low/high speed ordering in the decompiled code:

| Runtime offset | Field |
|---|---|
| `+0x1c` / `+0x20` | RisePitchAngleMin / Max |
| `+0x24` / `+0x28` | RiseTiltAngleMin / Max |
| `+0x2c` / `+0x30` | RiseLowSpeedMin / Max |
| `+0x34` / `+0x38` | RiseHighSpeedMin / Max |
| `+0x3c` / `+0x40` | RiseGravityLowMin / Max |
| `+0x44` / `+0x48` | RiseGravityHighMin / Max |
| `+0x4c` / `+0x50` | RiseGravityLowMinZero / MaxZero |
| `+0x54` / `+0x58` | RiseGravityHighMinZero / MaxZero |
| `+0x5c` / `+0x60` | RiseGravityLowTilt / HighTilt |
| `+0x64` | RiseLineLengthScale |
| `+0x68` / `+0x6c` | RiseLineLengthMin / Max |

Disassembly confirms `0x1402c2450` returns full three-dimensional vector length. `0x140876340` returns negated `atan2(y, length(xz))`. Annotated selected pseudocode and the PE float constants are retained alongside the earlier decompilation.

## Animation and camera

Swing animation seek time follows progress along the arc instead of time spent in the swing state. Release animation variants use release pitch. This is independent phase mapping, not recovery of the native animation graph. The collapsed-limb conversion error has since been fixed by correcting Blender bone creation and rebuilding all clips; see `RIG_DEFORMATION.md` for the native bind checks and pose captures.

The camera uses the decoded follow distance, pivot height, pitch limits/biases, swing height offsets, distance bonus and FOV speed curves. Its filtering and automatic heading follow remain independent. Conversion from the original FOV values to Bevy's vertical projection assumes those source values describe horizontal FOV; this convention has not been verified against the native renderer.

## Validation

Sixteen tests cover recovered gravity/pivot/terminal reference cases, initial gravity blend, entry speed conservation, additive release boosts, arc continuity, forward travel without attachment churn, 60/120 Hz consistency, collision, wall contact, dive release and long-running numerical stability.

`spiderman_bevy.exe --physics-report` compares identical inputs against `research/previous_physics.rs` and saves positions/velocities at 10 Hz in `research/controller_comparison.json`. It does not contain measured trajectories from the original game and does not certify fidelity. `Verify.ps1` additionally runs a hidden render check, validates all 26 converted clips and checks the original source manifest.

## Comparison measurements

These measurements use the same scripted inputs for 13.33 seconds and compare against the previous prototype. They are not comparisons with a measured run of the original game.

| Scenario | Lateral excursion before / after (m) | Peak speed before / after (m/s) |
|---|---|---|
| dive_entry | 17.60 / 6.74 | 57.08 / 51.81 |
| held | 19.31 / 3.05 | 56.69 / 34.33 |
| jump_release | 17.62 / 0.03 | 50.29 / 35.49 |
| normal_release | 10.89 / 0.03 | 44.24 / 30.64 |
