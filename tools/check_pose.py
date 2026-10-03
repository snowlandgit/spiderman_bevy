import bpy
from pathlib import Path
root=Path(__file__).resolve().parents[1]
bpy.ops.wm.open_mainfile(filepath=str(root/'tools/character.blend'))
a=bpy.data.objects['SpiderMan'];a.animation_data.action=bpy.data.actions['stand_idle_spiderman']
for t in a.animation_data.nla_tracks:t.mute=True
bpy.context.scene.frame_set(35)
for name in ['a_body','LF_upleg','LF_loleg','LF_loleg_bind_1','LF_loleg_bind_2','LF_loleg_bind_5','LF_upknee','LF_foot','LF_uparm','LF_uparm_bind_1','LF_uparm_bind_5','LF_loarm','LF_loarm_bind_1','LF_loarm_bind_3','LF_loarm_bind_5','LF_wrist']:
 p=a.pose.bones[name]; mat=p.matrix;local=p.parent.matrix.inverted()@mat if p.parent else mat
 print(name,'xyz',tuple(round(v,3) for v in mat.translation),'x-axis',tuple(round(v,3) for v in mat.col[0][:3]),'localxyz',tuple(round(v,3) for v in local.translation))
