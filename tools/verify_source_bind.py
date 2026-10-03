import numpy as np,struct
from pathlib import Path
from extract_assets import sections
root=Path(__file__).resolve().parents[1];b=(root/'assets/source/characters/hero/hero_spiderman/hero_spiderman_body.model').read_bytes();d=sections(b[b.find(b'1TAD'):])[0xDCC88A19]
it=iter((root/'tools/character.ascii').read_text().splitlines());n=int(next(it));rows=[]
for i in range(n):
 name=next(it);parent=int(next(it));v=list(map(float,next(it).split()));x,y,z=v[:3];qx,qy,qz,qw=v[3:];q=np.array(v[3:]);q/=np.linalg.norm(q);qx,qy,qz,qw=q
 m=np.eye(4);m[:3,:3]=[[1-2*(qy*qy+qz*qz),2*(qx*qy-qz*qw),2*(qx*qz+qy*qw)],[2*(qx*qy+qz*qw),1-2*(qx*qx+qz*qz),2*(qy*qz-qx*qw)],[2*(qx*qz-qy*qw),2*(qy*qz+qx*qw),1-2*(qx*qx+qy*qy)]];m[:3,3]=[x,y,z]
 raw=np.array(struct.unpack_from('<16f',d,n*48+i*64)).reshape(4,4).T
 error=np.max(np.abs(raw@m-np.eye(4)));rows.append((error,name,np.linalg.det(raw[:3,:3]),v[:3],raw[:3,3]))
print('Worst')
for row in sorted(rows,reverse=True)[:15]:print(row)
