# World scale revision

The scene now contains seven high-rises assembled from the installed game's
Midtown glass/stone architecture kits and 56 original sedans, hybrid taxis and
SUVs. All vehicle geometry keeps its native scale; only the pivot is moved to
the body center at tire contact height. Original 4 m facade units are repeated
without resizing. Tower floor heights are 56–92 m; collision/anchor bounds
follow the visible facade envelopes. Roof AC units retain native dimensions.

The seven building assemblies and parking positions are custom to this
sandbox. These are original game mesh assets, not copies of particular
Manhattan building instances or their layered material renderer. Original
color/normal textures are decoded into PNG and shared among instances; native
vehicle paint and window interiors use approximate standard PBR materials.
Roof closure planes and 4 m lane paint marks are authored in this project.

No swing speed, acceleration, attachment, release, or camera tuning was changed
in this revision. Arena geometry changes to fit the newly visible buildings.
The previously reported attachment-direction issue remains separate work.

World meshes are merged per material at conversion, while repeated vehicle
instances share mesh handles. Scene startup waits for all 63 world roots and
their dependencies; a set tracks unique ready entities so repeated readiness
events cannot lock movement. Smoke checks include these loaded roots and the
expected seven tower/56 car counts. Verification also checks finite vertices,
normal lengths, index bounds, outward winding, source checksums, texture files,
meter dimensions, parked-car clearances and facade collider envelopes.

Provenance and mesh bounds: `world_assets.json`.
Scene checks: `world_validation.json`.
Final executable/source/asset hashes and runtime results: `revision_validation.json`.
