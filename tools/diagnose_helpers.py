import bpy,re
from pathlib import Path
from mathutils import Vector,Matrix
root=Path(__file__).resolve().parents[1]
bpy.ops.wm.open_mainfile(filepath=str(root/'tools/character.blend'));arm=bpy.data.objects['SpiderMan']
arm.animation_data.action=bpy.data.actions['stand_idle_spiderman']
for tr in arm.animation_data.nla_tracks:tr.mute=True
bpy.context.scene.frame_set(35)
original={p.name:p.matrix.copy() for p in arm.pose.bones}
rest={b.name:b.matrix_local.copy() for b in arm.data.bones}
arm.animation_data.action=None
ends={'uparm':'loarm','loarm':'wrist','upleg':'loleg','loleg':'foot'}
for pb in arm.pose.bones:
 match=re.fullmatch(r'(LF|RT)_(uparm|loarm|upleg|loleg)_bind_([1-5])',pb.name)
 if not match:continue
 side,section,idx=match.groups();an=f'{side}_{section}';bn=f'{side}_{ends[section]}'
 ra=rest[an];rb=rest[bn];rh=rest[pb.name];pa=original[an];pp=original[bn]
 axis=rb.translation-ra.translation
 t=max(0,min(1,(rh.translation-ra.translation).dot(axis)/axis.length_squared))
 qa=(pa@ra.inverted()).to_quaternion();qb=(pp@rb.inverted()).to_quaternion()
 delta=qa.slerp(qb,t).to_matrix().to_4x4()
 posed=delta@rh;posed.translation=pa.translation.lerp(pp.translation,t)
 pb.matrix=posed
 bpy.context.view_layer.update()
# Helpers inherit the corrected deformation of their nearest control joint.
for pb in arm.pose.bones:
 if not any(k in pb.name.lower() for k in ('helper','buttock','upknee')):continue
 parent=pb.parent
 if not parent:continue
 pb.matrix=parent.matrix@rest[parent.name].inverted()@rest[pb.name]
 bpy.context.view_layer.update()
for o in bpy.context.scene.objects:
 if o.type=='MESH':
  for mod in o.modifiers:
   if mod.type=='ARMATURE':mod.use_deform_preserve_volume=True
bpy.ops.object.camera_add(location=(.6,-3.4,1.25));camera=bpy.context.active_object
camera.rotation_euler=(Vector((0,0,1))-camera.location).to_track_quat('-Z','Y').to_euler();bpy.context.scene.camera=camera
bpy.ops.object.light_add(type='AREA',location=(-1,-3,4));light=bpy.context.active_object;light.data.energy=550;light.data.size=3
light.rotation_euler=(Vector((0,0,1))-light.location).to_track_quat('-Z','Y').to_euler()
scene=bpy.context.scene;scene.render.engine='CYCLES';scene.cycles.samples=12;scene.world.color=(.2,.2,.2);scene.render.resolution_x=600;scene.render.resolution_y=750;scene.render.resolution_percentage=100
scene.render.filepath=str(root/'tools/rig_corrected.png');bpy.ops.render.render(write_still=True)

