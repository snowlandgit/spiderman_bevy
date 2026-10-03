import bpy,math
from pathlib import Path
from mathutils import Vector
root=Path(__file__).resolve().parents[1]
bpy.ops.wm.open_mainfile(filepath=str(root/'tools/character.blend'))
arm=bpy.data.objects['SpiderMan'];arm.animation_data.action=bpy.data.actions['web_swing_2rh_000_twist_0_spiderman']
for track in arm.animation_data.nla_tracks:track.mute=True
bpy.context.scene.frame_set(0)
for pb in arm.pose.bones:
    if pb.name in ['LF_elbow','LF_wrist','LF_knee','RT_knee']:print(pb.name,list(pb.matrix.translation))
bpy.ops.object.camera_add(location=(1.2,-3.5,1.6));camera=bpy.context.active_object
camera.rotation_euler=(Vector((0.,0.,1.0))-camera.location).to_track_quat('-Z','Y').to_euler();bpy.context.scene.camera=camera
bpy.ops.object.light_add(type='AREA',location=(2,-3,4));light=bpy.context.active_object;light.data.energy=500;light.data.shape='DISK';light.data.size=4
light.rotation_euler=(Vector((0,0,1))-light.location).to_track_quat('-Z','Y').to_euler()
scene=bpy.context.scene;scene.render.engine='CYCLES';scene.cycles.samples=12;scene.world.color=(0.3,0.3,0.3)
scene.render.resolution_x=720;scene.render.resolution_y=900;scene.render.resolution_percentage=100
scene.render.filepath=str(root/'tools/blender_static.png');bpy.ops.render.render(write_still=True)

