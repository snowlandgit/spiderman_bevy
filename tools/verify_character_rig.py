"""Compare actual Blender bind matrices and render original animated suit poses."""
import bpy, math, json
from pathlib import Path
from mathutils import Matrix, Quaternion, Vector
root = Path(__file__).resolve().parents[1]
bpy.ops.wm.open_mainfile(filepath=str(root/'tools/character.blend'))
arm = bpy.data.objects['SpiderMan']
lines = iter((root/'tools/character.ascii').read_text().splitlines())
count = int(next(lines)); swizzle = Matrix.Rotation(math.pi/2, 4, 'X')
errors = []
for _ in range(count):
    name = next(lines); next(lines)
    x,y,z,qx,qy,qz,qw = map(float, next(lines).split())
    source = swizzle @ (Matrix.Translation((x,y,z)) @ Quaternion((qw,qx,qy,qz)).to_matrix().to_4x4())
    actual = arm.data.bones[name].matrix_local
    errors.append(max(abs(actual[r][c]-source[r][c]) for r in range(4) for c in range(4)))
assert max(errors) < .00005, max(errors)
for track in arm.animation_data.nla_tracks: track.mute = True
# Neutral lighting reveals geometry without normal-map or material distractions.
mat = bpy.data.materials.new('RigVerificationGray'); mat.diffuse_color = (.55,.55,.55,1)
for obj in bpy.context.scene.objects:
    if obj.type == 'MESH':
        obj.data.materials.clear(); obj.data.materials.append(mat)
bpy.ops.object.camera_add(location=(.6,-3.4,1.25)); camera = bpy.context.active_object
camera.rotation_euler = (Vector((0,0,1))-camera.location).to_track_quat('-Z','Y').to_euler()
bpy.context.scene.camera = camera
bpy.ops.object.light_add(type='AREA', location=(-1,-3,4)); light = bpy.context.active_object
light.data.energy = 550; light.data.size = 3
light.rotation_euler = (Vector((0,0,1))-light.location).to_track_quat('-Z','Y').to_euler()
scene = bpy.context.scene; scene.render.engine = 'CYCLES'; scene.cycles.samples = 12
scene.world.color = (.2,.2,.2)
scene.render.resolution_x = 600; scene.render.resolution_y = 750; scene.render.resolution_percentage = 100
poses = [('stand_idle_spiderman',35,'idle'),('web_swing_rh_a_spiderman',150,'swing'),('web_swing_jump_high_spiderman',45,'release')]
report = {'blender_bind_max_matrix_error':max(errors), 'verified_bones':count, 'poses':[]}
for clip,frame,label in poses:
    arm.animation_data.action = bpy.data.actions[clip]
    scene.frame_set(frame)
    depsgraph = bpy.context.evaluated_depsgraph_get()
    corners = [obj.matrix_world @ Vector(corner)
               for source in scene.objects if source.type == 'MESH'
               for obj in [source.evaluated_get(depsgraph)] for corner in obj.bound_box]
    low = Vector(tuple(min(v[d] for v in corners) for d in range(3)))
    high = Vector(tuple(max(v[d] for v in corners) for d in range(3)))
    center = (low+high)*.5
    camera.location = center+Vector((.6,-3.4,.25)).normalized()*max(high-low)*2.0
    camera.rotation_euler = (center-camera.location).to_track_quat('-Z','Y').to_euler()
    path = root/'research'/f'rig_fixed_{label}.png'
    scene.render.filepath = str(path); bpy.ops.render.render(write_still=True)
    report['poses'].append({'clip':clip,'frame':frame,'image':path.name})
(root/'research/rig_validation.json').write_text(json.dumps(report,indent=2))
print('RIG_VALIDATION',report,flush=True)

