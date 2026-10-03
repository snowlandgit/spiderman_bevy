# Swing timing, transitions and calmer camera

The original phase-only sampling could jump immediately into a substantially
later body pose. The first timing revision overcorrected this: its 1.067-second
attachment and main clip starting at zero held the starting pose too long.
Normal attachment now plays the complete source intro over 0.45 seconds,
or 0.55 seconds when entering from a dive. The main clip starts at source time
0.6 seconds and advances at 2.4 source seconds per second, bounded by physical
arc progress. At 0.85 seconds into a normal swing its target is about 1.56 source
seconds, bringing the knees forward; around 1.15 seconds its target reaches the
forward foot kick. Sampling is filtered and rate-limited to 3 source seconds/s.
These are sandbox presentation values, not recovered native animation timing.

Physics still runs at 120 Hz. Previously the rendered character used the newest
fixed position directly while the camera ran on the variable render clock,
producing uneven relative motion when render and physics updates did not line
up. Each physics tick now captures its before/after state; each render frame
interpolates position, velocity, heading, swing phase and continuous animation
timers using the fixed-clock remainder. Character, animation, wrist webs and
camera consume the same interpolated state, with at most one fixed tick of
presentation latency (8.33 ms). Resets and teleports snap immediately; a skipped
simulation tick does not reuse stale snapshots. Simulation and input still use
the authoritative physics state.

The previous animation transition used a short linear fade while manually
sampled outgoing clips were left at speed zero. The new mixer evaluates a
smoothstep fade with normalized weights, snapshots current blend weights when
interrupted, and continues outgoing clocks using their last playback rates.
Ground, swing, release, fall and zip transitions have separate blend durations.
Terminal non-looping poses stop just short of the exact end time, avoiding a
Bevy loop wrap when clips are sampled manually. The original exported joint
curves and mirrored variants have not been changed for this revision.

Camera presentation changes:

| Behavior | Previous sandbox | Current sandbox |
|---|---|---|
| Automatic pitch | Up to 40 degrees; dive target 45 | Up to 5 degrees; dive target 8; maximum change 8 degrees/s |
| Horizontal FOV | Speed and state dependent, including up to 40 degrees boost and 15 degrees extra in dive | Fixed 80 degrees |
| Follow distance | 2.75 m plus up to 1.4 m speed offset | Fixed 6 m, except obstacle avoidance |
| Swing camera bob | Phase-dependent vertical offsets | Shared stable focus for position and aim |
| Automatic turning | Fast exponential following of velocity | Slower heading following, limited to 30 degrees/s |

The focus predicts translation and smoothly corrects its tracking error, capped
at 1.25 m. Both camera position and look direction use this same focus. Obstacle
avoidance retracts immediately to prevent clipping and restores distance at a
limited rate. Manual mouse look remains responsive. Controller right-stick
look now scales with frame time rather than incrementing per rendered frame.

All settings are in assets/tuning/sandbox_presentation.json and are embedded
at build time. Change them and rebuild to apply further adjustments. The
original recovered camera config remains intact as a research reference.

Tests verify earlier forward-leg progression, bounded clip seeking, interrupted blend
continuity, normalized weights and moving outgoing clips. Camera tests cover
rapid ascent/descent, steady-speed focus tracking, teleport recovery, turning
limits and obstacle-distance recovery. Hidden rendered swing, zip and charged
jump runs record observed camera and blending bounds in their presentation
report fields. A separate swing_main.png capture checks the actual blended
main-swing pose. Interpolation tests check uniform travel at 60, 75, 144 and
240 FPS, reset/teleport handling and release timer continuity. Verify.ps1 runs
all 55 tests, these rendered scenarios, source
pose validation and asset checks, then records executable/source hashes.

This improves the sandbox presentation; it does not reconstruct the complete
native animation graph or hand IK. The separate physics feel revision is documented in
SWING_WEIGHT_REVISION.md; jump tuning is unchanged.
