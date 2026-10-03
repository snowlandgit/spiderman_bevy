# Gravity through swing-to-zip transitions

The previous forward zip derived gravity only from configured outgoing height
and time to peak. This could replace the 44 m/s² release gravity with roughly
11-25 m/s² for the entire one-second zip animation. It also added its lift to
all carried upward velocity. Coming out of a rising swing could therefore
produce a second long, shallow ascent before normal falling returned.

Forward zip now enforces the same 44 m/s² rising-gravity floor as swing
release and the same 52 m/s² falling floor as airborne traversal. Gravity
applies during the airborne shot delay, kick and follow-through, then carries
into normal air motion without a weaker-gravity window. A grounded shot still
keeps the feet on the ground until its launch; point zips still approach and
stop at their selected roof target.

The recovered 3-5 m outdoor height and ground height targets determine lift
speed with the stronger gravity. Existing upward speed counts toward that
lift: the zip raises insufficient ascent to the target, retains faster ascent,
and preserves the configured fraction of downward speed on repeated zips.
It does not add a second vertical launch to an already fast upstroke. Forward
boost, carried lateral momentum, visible anchors, cooldowns and clips retain
their existing calculations. These are independent sandbox corrections;
native zip runtime parity has not been established.

## Checks

Two new regressions bring the suite to 66 tests. The swing fixture starts at
100 m with 18 m/s upward and 24 m/s forward velocity. Each non-kick step loses
at least 44 m/s² of vertical speed, including before launch and throughout
follow-through. Its peak is approximately 105.74 m; at 1.1 seconds vertical
speed is approximately -27.53 m/s. A second fixture starts with 30 m/s upward
velocity and verifies that the kick preserves ascent under gravity while
adding forward speed, without canceling or stacking vertical momentum.

The hidden zip scenario now swings for 100 physics ticks before the first
forward zip. Its report records swing_to_zips, and verification requires at
least one successful swing interruption, four zips and rooftop arrival.
Zip-fire and follow-through captures are taken after the transition. The full
Verify.ps1 -Rebuild run also checks ordinary swings, shot direction, charged
jumps, source animation poses, world assets and the installed build hash.