# Web zips and original animation poses

E / X performs a forward two-handed web zip. Q performs a rooftop point zip
when a reachable white target is visible in the camera direction. Controller
X performs a forward zip; LT + RT performs a rooftop zip. Forward zips may
interrupt swinging, have repeat lockouts, preserve existing fast momentum,
and use distinct grounded, airborne and dive entry behavior. Web endpoints
are visible, unobstructed original building surfaces. Rooftop zips stop at a
roof corner rather than launching past it.

The forward zip controller reads the recovered outdoor and ground zip setup
JSON files in assets/tuning. These supply boost limits, outgoing speed floors,
height and time-to-peak values, successive-zip caps and cooldowns. Motion is
independently integrated; the original native zip implementation has not been
ported in full. Point-zip approach and braking are authored for this sandbox.

The character library now contains 49 original clips and 19 mirrored variants.
The forward swing uses web_swing_fwd_rh_spiderman, referenced by the original
spiderman_traversal.animset lookup, rather than the older generic swing clip.
Intros, releases, jump releases, dive entries and wall-run entries use their
source clip durations. Falling at the jump apex no longer truncates a release
clip. Forward zip chooses the original normal, fast-fall or high-release
2-handed animation. Source wrist transforms supply the rendered web origins.
The extra procedural body tilt has been removed from swinging.

Mirroring accounts for the original skeleton's asymmetric bind axes: joint
world-space deformation is reflected across model X and mapped onto the
opposite bone's original bind frame before rebuilding local curves. Merely
swapping local rotations would twist the clavicles. See mirror_validation.json
for per-clip reconstruction errors.

Animation export validation compares 212 global joint transforms with samples
from the decoded original Blender actions, before GLB export. Thirteen representative
clips cover forward swing, swing entry, three zip entries, short point-zip
attachment, standing jump, charged up/forward jumps, running high jump, release, high jump release and wall-run entry. See
animation_pose_validation.json for measured maximum errors. This verifies source
clip pose preservation; it does not verify the original engine's runtime graph.

Remaining differences include the complete native animation graph, blend
parameters, additive evaluation, hand IK, corrective deformation, native root
motion coordination and traversal transitions. The mirrored variants are
reconstructed from original right-handed actions. The current sandbox mixer eases transitions, advances outgoing clips and delays
main-swing entry; see PRESENTATION_REVISION.md. Blend windows and mapping
between physical swing arc and clip time remain sandbox implementations.
Identical animation playback in all gameplay states is not established.

Verify.ps1 runs the movement/animation tests, hidden rendered swing and zip
scenarios, asset/bind checks, original pose comparisons and world validation.
Reports and executable/source hashes are recorded in revision_validation.json.
