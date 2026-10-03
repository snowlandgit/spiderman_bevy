import bpy,numpy as np
from pathlib import Path
root=Path(__file__).resolve().parents[1]
bpy.ops.wm.open_mainfile(filepath=str(root/'tools/character.blend'));a=bpy.data.objects['SpiderMan'];a.animation_data.action=bpy.data.actions['stand_idle_spiderman']
for t in a.animation_data.nla_tracks:t.mute=True
bpy.context.scene.frame_set(35)
obj=bpy.data.objects['SuitPart_00'];groupnames={vg.index:vg.name for vg in obj.vertex_groups};matrices={pb.name:np.array(pb.matrix@pb.bone.matrix_local.inverted()) for pb in a.pose.bones};ranking=[]
for v in obj.data.vertices:
 if v.co.x<.35:continue
 gs=[(groupnames[x.group],x.weight) for x in v.groups];mat=sum(matrices[n]*w for n,w in gs);sing=np.linalg.svd(mat[:3,:3],compute_uv=False);ranking.append((float(sing[-1]),v.index,gs))
for x in sorted(ranking)[:6]:
 print(x)
 for n,w in x[2]:print(n,'pose head',tuple(round(f,3) for f in a.pose.bones[n].matrix.translation),'delta quaternion',tuple(round(f,3) for f in (a.pose.bones[n].matrix@a.pose.bones[n].bone.matrix_local.inverted()).to_quaternion()))
