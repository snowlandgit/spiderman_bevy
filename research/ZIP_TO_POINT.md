# Zip to a point and the point launch

Aim at a ledge, a roof's rim, the top of a post or a car's roof until a light-blue diamond marks it. Then press
**Q** (**LT + RT** on a controller) to zip there. Press **Space** (**A**) as he arrives for a point launch. Without
the press he perches on the point: **Space** jumps off, **C** (**B**) steps off the edge, the stick stands him up.
The same chord zips on to the next point.

The launch is Spider-Man.exe 4.0630's own code, ported to Rust in `crates/sm_traversal` and checked against the game.
The zip follows the game's own zip animation. The points come from the world's geometry, so any imported object
offers them.

## The launch: the game's

`Hero::HeroStateZipToPointLaunchLocal` (vtable exe+38d5dd0) ends a zip to a point. The parts that decide the launch were
decompiled and ported in `crates/sm_traversal/src/point_launch.rs`.

| What | Game code (RVA) | Port |
|---|---|---|
| The press: the jump button (buffered 0.1 s) starts a clock (+0x250) that runs until the launch | exe+b1d640 | `PointZip::press`, `PRESS_BUFFER` |
| The direction | exe+b1d640 | `exit_direction` |
| The launch | exe+b19fb0 | `launch` |
| The checks ahead of the point | exe+b1d250, exe+b1be00 | `Probes`, `clear_ahead` |
| Into HeroStateJump, kind 0x2a | exe+b19fb0, exe+a86490 | `AirEntry::point_launch`, `sim::StepInput::air` |
| The jump state reads its motion and speed data by kind | exe+a87910, exe+a879d0 | `air::motion_data`, `air::speed_data` |
| The jump off a perch: kind 0x1d through the transition manager's ground jump | exe+974c90, exe+868850 | `AirEntry::ground_jump` |
| The button thrust while the jump is held | exe+a87b90 | `AirLocal::motion_frame` |

**The direction.** At the end of the zip the stick's direction is used when it is within MaxExitAngle (35 degrees) of
the zip's. From there up to 120 degrees off, the zip's direction is turned 35 degrees toward the stick. Pulled back
further, the zip's direction is kept and the stick's amount goes negative: the "back" exit.

**The launch.**
- Speed, height and time to the top are lerped by the stick's amount. Toward ExitDataFull (zero stick reads
  ExitDataZero), or toward ExitDataBack when the amount is negative.
- Each gets its bonus scaled by the boost: 1 − remap(clock, 0.2, 0.5), at least BoostMinApply (0). The Point Launch
  Boost skill is taken as owned.
  - A press 0.2 s or less before the launch gives the full boost.
  - A press 0.5 s or more before gives none.
  - At 0.75 or more the game plays the full boost effect. The HUD shows "POINT LAUNCH  BOOST" for it, and "(EARLY)"
    for a smaller one.
- The vertical speed is 2h/t and the gravity to the top 2h/t². After the top the gravity is GravityFall, 30 m/s².
- From PointLaunchConfig, with the stick at zero, full and back:
  - Zero: 24 m/s on, 6 m up in 0.65 s.
  - Full: 26 m/s on, 6 m up in 0.6 s.
  - Back: 12 m/s on, 10 m up in 0.6 s.
  - The full boost adds 3, 6 and 2 m/s and 6, 3 and 16 m of height. So a perfectly timed launch with the stick pulled
    back goes 26 m up.

**Clearing what's ahead.**
- Eight 0.25 m spheres are cast 16 m along the launch, from 2 to 9 m above the point, under the ceiling a 0.3 m
  sphere finds going up to 21 m.
- **A wall with a top in reach:** the launch slows until its rise clears that top by 1.25 m, rising faster if it has
  to.
- **A wall with no top:** the launch is lowered and slowed so he reaches it no sooner than 0.9 of the way to his top.
- The game's flag for this (exe+5d9fef5) is set in the executable's data.

**The jump state.** The launch is HeroStateJump, the swing jump's class. Kind 0x2a reads ZipPointLaunchJumpConfig
(drag profile ZipJumpDrag) and SwingJumpSpeed, and it turns with the default turn constants (exe+a7d260). The jump off
a perch is kind 0x1d and reads PerchJumpConfig and PerchJumpSpeed:
- 2 m up in 0.35 s, falling at 2h/TimeToFall².
- On at (0.8 × stick + 0.2) × 7 m/s with the stick past 0.04.
- Holding the button adds the thrust: 14 m/s² for up to 0.38 s.

A fall with no jump before it (walking off a ledge) is kind 0x0b with no second kind. It reads SingleJumpConfig and
GroundJumpSpeed, which the port did not do before.

### How it is checked

`tools/native_oracle/oracle.exe` has a new scenario key, `enter t jump|fall kind kind2 dx dz hspeed vy gravity
gravity_after input`. It enters HeroStateJumpLocal (vtable exe+38c1628) or the fall with data built by the game's own
helpers (exe+a7d820, exe+a7d8c0, exe+a7dc50), then runs the game's frames. Five scenarios:

| Scenario | What it covers | Air frames | Differ | Closed loop |
|---|---|---|---|---|
| `launch_zero` | ExitDataZero, into the fall | 150 | 0 | 0.0000 m |
| `launch_steer` | ExitDataFull with its bonuses, then steered right, back and let go | 180 | 0 | 0.0000 m |
| `launch_back` | ExitDataBack with its bonuses | 240 | 0 | 0.0000 m |
| `perch_jump` | the jump off a perch with the stick at 0.8 | 90 | 0 | 0.0000 m |
| `ledge_fall` | the fall from a ledge, steered | 120 | 0 | 0.0000 m |

- In every scenario the entries are identical and the hand-over to the fall is on the same frame.
- The six earlier scenarios are unchanged.
- `cargo test -p sm_traversal` replays all eleven against the paths kept in `tests/fixtures`
  (`tools/native_oracle/make_fixture.py` writes them).
- The launch's own arithmetic (exit data, boost, direction, clearing) is unit-tested against values worked out by hand
  from the decompiled code.
- Not checked against the game:
  - the button thrust while held (the harness has no jump action, so only its "not held" branch runs);
  - the launch values from b19fb0 themselves (the state's processor and animation can't run offline). The oracle is
    given them.

## The zip: the game's animation

- The game moves him by the root motion of its zip clip, warped onto the target by his mover. The mover's warp isn't
  ported.
- The clip's way to the target is in its `sync` joint, joint 7 in ArkWeb's notes. `tools/extract_zip_way.py` reads it
  from the character file into `assets/tuning/web_zip_attach_way.json`: 30 m in 1.33 s at an even 22.5 m/s, rising
  3 m on the way.
- `src/point_zip.rs` plays it as ArkWeb does:
  - the clip starts where its remaining way equals his distance, so a zip keeps the clip's speed;
  - a zip longer than 30 m starts at the clip's start and is scaled;
  - the offset is turned and scaled onto his in the forward-up plane, so he arrives coming down onto the point;
  - the body plays `web_zip_attach_fwd_spiderman` at the same time.
- A 0.25 m sphere is swept along the path. If something is in the way short of the point, the zip ends there: a launch
  if A was pressed, else a fall.

**Not decoded:** PointLaunchConfig's Yank values (zip speeds by range) aren't read by any function decompiled here.

**Arrival.**
- With A pressed during the zip, he launches on arrival.
- A press within 0.2 s after arriving still launches (the game's check buffers that press for 0.2 s, exe+98f870). How
  long the game's arrival animation keeps that window open isn't known.
- Otherwise he perches, 0.35 m in from the edge.

## The points: from the geometry

The game's perch points are authored on New York's buildings and picked by its HeroPerchTargeting component, which isn't
ported. Here they come from what collides, so any object works (`src/world.rs`).

**What collides.**
- A building with an authored box in `assets/world/layout.json` collides as that box.
- Everything else collides as its own meshes: a building without one, the parked cars, and any glTF in the layout's
  `objects` list (`{"asset": "world/x.glb", "position": [x, y, z], "yaw": 0, "scale": 1}`, and `"hidden": true` for
  one that should collide without being drawn).
- Any scene spawned with the `environment::MeshCollider` component on its root also collides by its meshes.
- Once the meshes have loaded, each distinct mesh becomes one model: a triangle BVH and its ledges. Every placement
  shares it. The 56 parked cars are 5 models and 1.1 million triangles, built in about 0.1 s.

**What is a ledge.**
- An edge of a surface he can stand on (up to 45 degrees of slope) where every face across the edge falls away below
  it, or where there is none.
- Vertices are welded to 1 cm. Faces count by their upper side, so meshes wound either way work.
- A wall rising from a roof isn't a ledge, but the top of that wall is.
- **Tips** of thin things (a lamp post, an antenna, a water tank's cap) are points too, though there is nothing to stand
  on. In a 0.2 m grid of the model's highest surface, a tip is a cell at least 1 m up that is the highest within 0.6 m
  and stands clear (0.1 m) over everything 0.4 to 1 m round it. He perches on the tip itself.
- When a model is built, each ledge is checked against the model itself (somewhere along it: a surface to stand on just
  in from the edge, headroom, a drop past it; a tip: headroom) and the ones he could never stand at are dropped. A
  lattice tower otherwise leaves thousands of tiny ledges along the aim that all fail.

**Picking one (ArkWeb's rule for its points).**
- On each ledge, the place nearest the camera's aim line.
- Within 4 to 67.5 m of him and 25 degrees of the aim. The game's RangeBreak, which ArkWeb used, is 45 m; the reach
  is half again that, as the user asked.
- The nearest to the aim comes first. Up to 24 are checked.

**Accepting it.**
- Room to stand 0.35 m in from the edge (less on a narrow top), with a surface he can stand on there.
- Headroom.
- A drop of 1 m or more past the edge, so it isn't a step: measured 0.6 m out, past a car's shoulder under its roof,
  or 0.15 m out from a narrow top (under 0.7 m deep: a cap with arms or a lattice just below it).
- In sight from him to just off the edge and over it.

**The world's queries.**
- The same world answers the swing point fan, the forward zip's anchors, the camera's collision, the floor under him,
  and his collisions with imported objects.
- Those collisions are:
  - a swept sphere so fast moves don't pass through thin objects;
  - the floor from a step up;
  - level push-outs from walls;
  - a wall run with the swing button held, as on the buildings.

## The map's objects

The game's own props, placed only through the layout's `objects` list (62 placements of 11 models), so they reach the
game the generic way:

- **The street:** lamp posts down both sidewalks every 30 m, a newsstand, a billboard stand.
- **The open space right of the start:** a helipad, a stepped scaffold tower (four sections, and two beside them) with
  an antenna tower on top (23 m), an industrial HVAC plant.
- **The open space left of the start:** a rooftop shed, a water tank, the Oscorp perch antenna.
- **Every tower's roof:** two of the water tank, the shed, the HVAC plant, the antenna tower and the perch antenna, in
  the quarters the air conditioners leave free.
- **The towers' air conditioners:** they are part of the tower models, as visuals only. The same unit is placed over
  each as a hidden object, so they collide and can be perched on.

How they were made:
- `tools/prepare_props.py` extracts the props from the installed game's archives (environment props only), through
  ALERT, with their textures.
- `tools/convert_props.py` writes `assets/world/prop_*.glb` (centred on their footprint, standing at 0) and the
  `objects` list. `tools/convert_world.py` now keeps that list when it rewrites the layout.
- Left out:
  - a double street light (its export is the lamp head without a pole);
  - a flag pole (its flag hangs level from the top, so the top is no perch);
  - the Brooklyn building groups already in `tools/world` (they decode at the wrong scale).

**Tests.** `src/world.rs` reads the repository's own glTF files directly and builds the map as the app does (towers,
cars and every object), then checks:
- every car's roof is hit by a ray, and 55 of 56 offer a roof point from the street;
- every placed object, hidden or not, has ledges on it;
- points are found from the street or the air on a lamp post's tip, the helipad, the scaffold's step, the antenna on the
  scaffold, the newsstand, a tower roof's water tank and a hidden air conditioner;
- the antenna on the scaffold is found from 60 m, beyond the old 45 m;
- the hero zips onto a parked car's roof, perches and point-launches off it, and zips to the scaffold's antenna from
  60 m down the street and launches off it with the full boost.

The other tests in `src/point_zip.rs` and `src/world.rs` use boxes and box-shaped meshes:
- a thin post's tip, and no tip on a roof;
- perching on a car-like mesh;
- the full, early and late presses;
- the jump off, the drop and standing up;
- the launch over a wall ahead;
- landing on and running into meshes;
- no tunnelling through a thin plate;
- swing points on meshes.

## Not modelled

- The game's targeting scores (ZipToPerchSetup's aim data, HeroZipToPerchConfig's priorities): ArkWeb's simpler rule is
  used.
- The mover's warp.
- The game's other zip clips by distance (only `web_zip_attach_fwd` is in the character file).
- The Yank speeds.
- The perch's own animations (LedgePerch_Idle and the arrivals aren't in the character file, so landing and standing
  clips stand in).
- Point launches between perches (PerchToPerchPointLaunch) and over low obstacles (AutoVault).
- Custom launch data on authored points.
- The launch's camera shake.
- Does a requested state start from a fresh driver? The game's state machine may run each state's init (exe+a85f70) on
  every activation. The oracle and ArkWeb run it once. Here the launches and the falls the sandbox asks for get a fresh
  driver, which is what the oracle checked. The swing's own hand-overs keep the oracle's convention.
