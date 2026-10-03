# Movement-based anchor search and recovery

Search uses actual horizontal velocity at speeds of at least 1.5 m/s. At lower
horizontal speed it falls back to movement input, then heading. Vertical speed
alone does not override the fallback. Search, new swing-plane initialization
and the candidate debug marker use the same direction. Existing swing steering
remains rate-limited.

The first direction revision introduced two regressions. Its 69.5-degree cone
could reject clearly visible side walls near the end of a facade. Its limited
candidate set could also reject an entire face when a preferred high attachment
lay beyond the 62 m search radius, despite reachable lower surface points.
Fresh swing presses during release lockout could expire as pressed input before
lockout cleared, preventing an attachment until descent.

The search now samples all four vertical faces at the nearest coordinate,
several projected travel distances and five evenly spaced coordinates. Each
point is evaluated at three heights: the preferred trough-clearance height,
the recovered ideal rise and the highest reachable height. Heights are bounded
by both the visible tower and remaining search radius. The minimum permitted
rise is 0.5 m; short reachable lines are allowed down to 2 m. Occlusion rejection
and the real-surface requirement remain in use.

New attachments must be at least 1.25 m ahead in the horizontal travel plane.
There is no narrow angular cutoff for side facades. Ranking strongly prefers
alignment and enough lead for the shot: 0.35 seconds of horizontal travel plus
1.25 m, with an 8 m minimum preference. A close side point remains available
when no further reachable forward point exists. The prior drop budget remains
a scoring preference. These are sandbox rules, not measured native search.

A fresh swing request is buffered for 0.4 seconds while the button remains held.
This permits retries during a 0.15-second release lockout or a brief absence
of valid targets. Release or dive cancels the request; attachment consumes it.
Continuing to hold swing without a fresh request preserves the existing
successive-line timing and charged-jump ascent behavior.

Tests cover camera/steering opposed to momentum, cardinal travel and fallbacks,
behind-only buildings, visible side-facade ends, low and near-roof entries,
release-lockout retries and preference for useful shot lead. An additional
288-entry grid across the actual city checks the attachment's direction after
the complete physics step. Previous height-loss, arc, animation and camera tests
remain active, for 55 total tests.

Hidden render verification measures the actual vector from the animated wrist
to the selected anchor on the first rendered frame of each new swing. Its
web_selection report records shot count, backward-shot count and minimum
rendered lead. A nonzero backward count fails verification. A held web naturally
passes behind the character after crossing its anchor during the existing arc;
the direction check applies to newly rendered shots. Web-zip aiming retains its
existing input semantics.
