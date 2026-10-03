# Consecutive swing height and longer arcs

Historical revision note: measurements below describe the longer-line and height-carry revision. Current gravity, air steering and regression results are documented in [AIR_CONTROL_REVISION.md](AIR_CONTROL_REVISION.md).

The previous revision applied a 0.83 terminal-speed carryover cap without
forward input and released ordinary long lines at 60 degrees from horizontal.
That discarded carried momentum and cut the upward arc before it could climb.

Each rope now records its entry height, speed and horizontal speed. Its speed
cap preserves carried horizontal momentum and speed earned by falling into
the trough. Forward assistance aims for 28 m/s on a taut descending line;
it does not add power to the rising arc. Ascending and descending gravity floors
remain 32 m/s², as does ordinary-release gravity. Charged jumps and zip motion
use their existing independent settings.

The surface search prefers a 42 m projected swing radius and uses 0.9 seconds
of movement lookahead, retaining the 4 m entry-drop penalty, real visible
surface requirement and 62 m search radius. Shorter ropes remain possible
where roofs or sparse buildings limit available attachment height or distance.

Automatic release retains the web through the upper arc. After the trough,
it waits until entry height is recovered and horizontal speed approaches
12 m/s; reversal and stalled upward motion still allow a new swing. The final
angle safeguard is 5 degrees, rather than the old early 60-degree gate.
Moving beyond the anchor does not itself sever the web. Releasing the swing
button detaches immediately and preserves momentum; the swing-jump remains
an explicit boosted release.

## Regression measurements

The forward-input fixture starts at 18 m and 16 m/s. Four ordinary automatic
releases occur at approximately 23.54, 29.85, 33.27 and 38.56 m. Their entry
heights are 18.00, 24.77, 30.94 and 34.22 m, respectively. The first release
retains approximately 11.90 m/s forward and 9.01 m/s upward velocity.

Consecutive-swing cases also start at 40 m / 28 m/s and omit forward input.
Every tested automatic release recovers its own entry height within 0.5 m,
and stays above the starting altitude. The low-speed unsteered case checks
two consecutive lines; its lateral route then leaves the seven-building
coverage. The other cases complete four lines. These results concern available
attachments in the sandbox, not indefinite flight without buildings.

The long-facade fixture selects a 42.84 m projected radius. Entry drops at
16, 24 and 32 m/s remain below 4 m. Separate 34 and 50 m/s arc fixtures keep
the same anchor into the rising arc past the old cutoff, then verify manual
release preserves horizontal velocity. The upstroke energy regression still
rejects powered climbing, and ordinary release falls promptly.

Verify.ps1 -Rebuild builds and installs the executable, runs all 60 tests,
performs four hidden rendered scenarios, validates source animation poses and
world assets, and records the current source, tuning and executable hashes.
These are independently authored sandbox corrections. They do not establish
original-game trajectory or runtime parity.