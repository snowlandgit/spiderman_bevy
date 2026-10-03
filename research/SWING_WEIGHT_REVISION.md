# Entry height and swing weight

Historical revision note: the measurements and values below describe the initial entry-height fix. Current gravity, arc release and carry settings are documented in [HEIGHT_CARRY_REVISION.md](HEIGHT_CARRY_REVISION.md).

The previous level-entry fixture starts at 18 m, moving forward at 16 m/s.
Its first fixed tick redirected that velocity into a downward tangent:
vertical speed became -13.56 m/s, and the first trough reached roughly 5.54 m
(a 12.46 m drop). The previous rendered character/camera interpolation was
working; this drop was a traversal problem, rather than presentation judder.
The trace before this revision is retained in pre_height_revision_comparison.json.

A web is now a unilateral constraint. Inward motion creates slack; it is not
immediately projected into a downward tangent. Gravity acts normally while
the web is slack. Once the character reaches the line's length, the constraint
redirects outward motion into the arc, keeping speed rather than injecting
an attachment impulse. Steering changes to the virtual pivot preserve existing
slack. Level entries no longer acquire a large downward velocity on attachment,
and rising entries continue their ascent until the web catches their descent.

Anchor search uses speed-dependent forward reach and raises candidate surface
attachments to limit the projected trough drop to approximately 4 m where the
available buildings permit it. Candidates with larger drops are penalized.
The calculation also retains floor clearance and occlusion rejection. Each
candidate has its own height calculation; a previous shared mutable height
could let one candidate influence the next. Real visible anchors and projected
physics pivots still use the existing independent surface-search implementation.

Ascending swing gravity has an authored downward floor of 22 m/s�. Ordinary
release gravity has a floor of 23 m/s�. These prevent the low-gravity hovering
produced by applying the recovered scalar curves without the complete native
controller. Boosted releases, charged jumps and zips retain their existing
motion settings. Holding forward raises the low-speed swing target to 22 m/s
using continuous bounded acceleration while the line is taut, rather than an
instant speed increase. This keeps the shallower arc from feeling slow.

All corrections are explicit authored values in assets/tuning/sandbox_swing.json,
embedded at compile time. The recovered configs and native reference equations
remain unchanged. This does not establish original-game runtime parity.

Four new regressions check entry height and speed at 16, 24 and 32 m/s,
upward entry and subsequent web capture, stronger ascent resistance against
the native-curve-only sandbox, and ordinary-release apex/fall timing. In the
level-entry cases the measured drops to the first trough are 3.77, 3.24 and
1.65 m; first-tick vertical speed is about -0.12 m/s. The ascent fixture's
vertical speed after 0.5 s is 5.00 m/s, versus 14.23 m/s without the gravity
floor. These are prototype fixtures, not measured original-game trajectories.

Verify.ps1 rebuilds the executable, runs all 55 tests and hidden swing/zip/jump
renders, validates source animation poses and world assets, and records current
source, tuning and executable hashes. Controller comparison reports now also
include first-tick velocity, minimum first-arc height and time to the trough.
The animation timing, interpolation and calmer camera from the presentation
revision remain in use.
