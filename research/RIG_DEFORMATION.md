# Character deformation fix

The collapsed limbs were caused by the Blender conversion, and have been fixed. This does not establish complete 1:1 animation or rendering parity.

## Root cause

`convert_character.py` originally assigned the native matrix to a newly created, zero-length `EditBone`, then set its length. Blender could not retain the intended bone orientation through that sequence. The resulting rest matrices had component errors as large as 2.0. Animation import then calculated channels against those incorrect rest matrices, so playback destroyed the limbs.

The earlier `verify_source_bind.py` check compared the ASCII skeleton with the game's inverse-bind matrices. That check passed because the ASCII data was correct. It did not check the actual Blender bones and therefore did not catch the conversion error. Earlier speculation about missing native corrective evaluation did not isolate the cause.

The converter now sets a nonzero length before assigning each bone matrix and verifies every actual Blender rest transform before importing animation. All 26 original clips were rebuilt; no helper-channel muting, weight remapping, dual-quaternion substitution or speculative pose correction is used.

## Verification

- Maximum Blender rest-matrix component error against the decoded source: approximately 0.0000204.
- The GLB validator now reconstructs the exported joint hierarchy and multiplies each joint's world rest matrix by the corresponding inverse-bind matrix from the original model. Maximum identity residual: approximately 0.0000371 across all 212 joints. This checks an independent native reference, rather than the GLB against its own matrices.
- Original idle, swing and boosted-release clips were rendered in Blender. Images and actual bind-error result are recorded in `rig_validation.json` and `rig_fixed_idle.png`, `rig_fixed_swing.png`, `rig_fixed_release.png`.
- Bevy's hidden rendered traversal check loads the repaired GLB and saves swing, release and traversal captures. All 16 controller tests pass.
- All 18 original suit mesh sections are retained. Excluding the white gauntlet/leg/shoe sections was tested and produced gaps in close-up poses, so that experiment was reverted. Material-path names alone do not establish that a section is alternate clothing.

## Remaining differences

The complete native animation graph, additive-pose evaluation, IK and corrective systems remain unported. Material shaders and resident texture resolution remain approximations. The controller combines recovered calculations with independent integration and transitions. None of these checks measures complete original-game fidelity.

## Earlier diagnostic experiments

The diagnostic render scripts and old broken captures are retained as investigation history. They compare helper-channel muting, helper-weight remapping, translation-channel muting, volume-preserving skinning and interpolated helper transforms. These experiments were not applied to the delivered GLB. The old `tools/rig_idle_gray.png` shows the failure before the conversion fix.
