import bpy,math,json
from pathlib import Path
from mathutils import Matrix,Quaternion
root=Path(__file__).resolve().parents[1];bpy.ops.wm.open_mainfile(filepath=str(root/'tools/character.blend'));arm=bpy.data.objects['SpiderMan'];it=iter((root/'tools/character.ascii').read_text().splitlines());n=int(next(it));swz=Matrix.Rotation(math.pi/2,4,'X');errors=[]
for i in range(n):
 name=next(it);next(it);x,y,z,qx,qy,qz,qw=map(float,next(it).split());source=swz@(Matrix.Translation((x,y,z))@Quaternion((qw,qx,qy,qz)).to_matrix().to_4x4());actual=arm.data.bones[name].matrix_local
 error=max(abs(actual[r][c]-source[r][c]) for r in range(4) for c in range(4));errors.append((error,name))
for e in sorted(errors,reverse=True)[:20]:print(e)
