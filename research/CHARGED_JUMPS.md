# Charged high and long jumps

Hold Space or controller A while grounded, then release. A short tap performs
an ordinary jump. A full charge takes one second. Standing launches upward;
moving launches forward. Charge strength scales continuously above the tap
threshold. The HUD displays charge percentage. Existing swing releases and
wall jumps still respond to the initial press. Holding jump during an airborne
jump does not trigger another launch on landing. Losing focus, resetting,
zipping or leaving the ground cancels a pending ground charge. Holding swing
through a charged jump leaves the ascent intact, and can attach on descent.

Original files extracted for this revision:
- characters/hero/hero_spiderman/animations/stand_chargejump_up_spiderman.animclip
- characters/hero/hero_spiderman/animations/stand_chargejump_fwd_spiderman.animclip
- characters/hero/hero_spiderman/animations/stand_sprint_high_jump_fwd_spiderman.animclip
- configs/equipment/skill_charge_jump.config (only identifies the ChargeJump skill)

The charge pose holds the crouched first sample of the original jump clip,
blended from the prior grounded pose. Releasing plays the original full clip.
The long jump uses the forward charge-jump clip; an ordinary running jump uses
the original sprint high-jump clip. Source poses for all three are included in
independent pre-export/GLB bone-transform comparisons.

The native jump motion settings have not been recovered. Values in
assets/tuning/sandbox_jump.json are authored: normal upward speed 21 m/s,
fully charged standing upward speed 34 m/s, fully charged moving upward speed
24 m/s and forward speed 26 m/s, gravity 23 m/s^2. On a flat surface with no
steering or web attachment these yield approximately 25 m height for a standing
charge and 54 m airborne distance for a moving charge. Partial charge scales
between normal and charged velocities. Motion preserves existing fast forward
travel. These numbers are not claimed to match original runtime tuning.

Tests cover tap/full charge, launch direction, height/distance, held-button
landing behavior, held-swing ascent, charge cancellation and original clip
selection. --jump-smoke-test renders both moves with its window hidden and
records peak standing height and airborne forward distance. The verified
full-charge scenario reached 24.99 m upward and covered 58.66 m while holding
forward movement in the air. Verify.ps1 also
runs the existing swing and zip scenarios, checks all captures and verifies
the extracted source files and exported animated skeleton.
