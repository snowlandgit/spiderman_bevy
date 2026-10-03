# Air direction control and heavier traversal

Air steering previously added up to 7 m/s² along input, scaled by
1 - horizontal_speed / 40. At 40 m/s or above there was no control, and
sideways input at lower speeds mainly added a small drift to existing momentum.

WASD and the left stick now turn existing horizontal velocity toward the
camera-relative input direction. Turning is bounded to 90-110 degrees per
second depending on speed, and scales with stick magnitude. It remains
available above the 40 m/s acceleration target. Low-speed input accelerates
at up to 18 m/s²; no-input horizontal momentum coasts. Steering does not alter
vertical speed, and a reversal follows an arc rather than flipping instantly.
The global 80 m/s total-speed cap and collisions still apply.

Swing ascent and descent now use 44 m/s² gravity floors instead of 32.
Ordinary and boosted swing releases have at least 44 m/s² rising gravity;
free descent has at least 52 m/s², and dive gravity is 64 m/s² instead of 42.
Charged ground-jump ascent retains its authored gravity and launch heights,
then uses the heavier fall. Zip motion uses its recovered setup with the current gravity floors; see [ZIP_GRAVITY_REVISION.md](ZIP_GRAVITY_REVISION.md) for the subsequent transition correction.

The longer-web search, momentum carry, unilateral rope, upper-arc attachment,
smooth animation sampling and calm camera remain in place. Air control uses
assets/tuning/sandbox_air.json; swing corrections use sandbox_swing.json.
These are authored sandbox values and independent integration, rather than
verified original-game runtime equations.

## Validation

Four new physics regressions bring the suite to 64 tests. Sideways input turns
falling momentum at 16, 40 and 55 m/s by more than 40 degrees within 0.5 seconds,
without changing vertical motion relative to a no-input fall. Opposite input
turns through a continuous arc and faces the reverse direction within two
seconds. A stationary fall develops more than 8 m/s sideways speed in half
a second, while descending at more than 25 m/s.

An ordinary release with 16 m/s upward speed reaches its apex in less than
0.4 seconds and drops more than 3.5 m below that apex by 0.75 seconds. Without
input, its 24 m/s horizontal momentum is preserved. The swing ascent fixture
has approximately -6 m/s vertical speed after 0.5 seconds, compared with
approximately zero before this revision and +14.23 with the native curves
alone in this independent controller.

Consecutive forward swings from 18 m / 16 m/s release at approximately
21.45, 24.86, 28.24 and 32.01 m. Forward cases starting at 40 m complete four
lines, and unsteered cases at 18 and 40 m complete two lines before lateral
paths can leave coverage or meet a wall. Only automatic airborne releases
are counted; wall contact is a separate transition. Each tested automatic
release recovers its own entry height within 0.5 m.

Existing tests retain long reachable lines, upper-arc attachment, release
momentum, charged jumps, zip behavior, animation transitions and camera
limits. Verify.ps1 -Rebuild also runs the four hidden rendered scenarios,
asset and original pose checks, and records the installed executable and
source/tuning hashes in revision_validation.json.