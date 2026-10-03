import bpy,json
from pathlib import Path
root=Path(__file__).resolve().parents[1]
bpy.ops.wm.open_mainfile(filepath=str(root/'tools/character.blend'));arm=bpy.data.objects['SpiderMan'];arm.animation_data.action=bpy.data.actions['stand_idle_spiderman']
for tr in arm.animation_data.nla_tracks:tr.mute=True
bpy.context.scene.frame_set(35)
for pb in arm.pose.bones:
 s=pb.matrix.to_scale()
 if max(abs(x-1) for x in s)>.01:print('SCALE',pb.name,tuple(s),tuple(pb.scale))
print('armworld',arm.matrix_world)
