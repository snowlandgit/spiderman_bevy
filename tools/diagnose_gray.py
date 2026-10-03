import bpy
from pathlib import Path
from mathutils import Vector, Matrix
root=Path(__file__).resolve().parents[1]
bpy.ops.wm.open_mainfile(filepath=str(root/'tools/character.blend'))
arm=bpy.data.objects['SpiderMan']
arm.animation_data.action=None
for track in arm.animation_data.nla_tracks:track.mute=True
for pb in arm.pose.bones:pb.matrix_basis=Matrix.Identity(4)
mat=bpy.data.materials.new('Diagnostic');mat.use_nodes=True
p=mat.node_tree.nodes.get('Principled BSDF');p.inputs['Base Color'].default_value=(.65,.65,.65,1);p.inputs['Roughness'].default_value=.8
for o in bpy.context.scene.objects:
 if o.type=='MESH':o.data.materials.clear();o.data.materials.append(mat)
bpy.ops.object.camera_add(location=(.6,-3.4,1.25));camera=bpy.context.active_object
camera.rotation_euler=(Vector((0,0,1))-camera.location).to_track_quat('-Z','Y').to_euler();bpy.context.scene.camera=camera
bpy.ops.object.light_add(type='AREA',location=(-1,-3,4));light=bpy.context.active_object;light.data.energy=550;light.data.size=3
light.rotation_euler=(Vector((0,0,1))-light.location).to_track_quat('-Z','Y').to_euler()
scene=bpy.context.scene;scene.render.engine='CYCLES';scene.cycles.samples=12;scene.world.color=(.2,.2,.2);scene.render.resolution_x=600;scene.render.resolution_y=750;scene.render.resolution_percentage=100
scene.frame_set(0);scene.render.filepath=str(root/'tools/rig_rest_gray.png');bpy.ops.render.render(write_still=True)
arm.animation_data.action=bpy.data.actions['stand_idle_spiderman'];scene.frame_set(35);scene.render.filepath=str(root/'tools/rig_idle_gray.png');bpy.ops.render.render(write_still=True)
