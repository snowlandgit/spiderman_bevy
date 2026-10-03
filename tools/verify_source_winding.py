import numpy as np
from pathlib import Path
root=Path(__file__).resolve().parents[1];it=iter((root/'tools/character.ascii').read_text().splitlines());n=int(next(it))
for _ in range(n):next(it);next(it);next(it)
for mi in range(int(next(it))):
 name=next(it);uv=int(next(it));tc=int(next(it))
 for _ in range(tc):next(it);next(it)
 vc=int(next(it));verts=[];norms=[]
 for _ in range(vc):
  verts.append(list(map(float,next(it).split())));norms.append(list(map(float,next(it).split())));next(it)
  for _ in range(uv):next(it)
  next(it);next(it)
 faces=[list(map(int,next(it).split())) for _ in range(int(next(it)))];faces=[f for f in faces if len(set(f))==3]
 v=np.array(verts);n=np.array(norms);f=np.array(faces);cross=np.cross(v[f[:,1]]-v[f[:,0]],v[f[:,2]]-v[f[:,0]]);dots=np.sum(cross*np.mean(n[f],axis=1),axis=1);mask=np.linalg.norm(cross,axis=1)>1e-10
 print(mi,'source winding agrees with normals',np.mean(dots[mask]>0),'of',len(dots),name)
