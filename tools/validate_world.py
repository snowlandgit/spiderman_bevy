"""Validate original world geometry, units, shared textures and scene placement."""
import json,hashlib,struct,math
from pathlib import Path
import numpy as np
root=Path(__file__).resolve().parents[1]
report=json.loads((root/'research/world_assets.json').read_text());layout=json.loads((root/'assets/world/layout.json').read_text())
assert report['car_scale']==1 and len(layout['buildings'])==7 and len(layout['cars'])==56
textures=set()
for name,asset in report['assets'].items():
    path=root/'assets'/asset['asset'];blob=path.read_bytes();magic,version,length=struct.unpack_from('<III',blob)
    assert magic==0x46546c67 and version==2 and length==len(blob)
    assert hashlib.sha256(blob).hexdigest()==asset['sha256']
    size=struct.unpack_from('<I',blob,12)[0];g=json.loads(blob[20:20+size]);binary=blob[28+size:]
    def array(index):
        a=g['accessors'][index];v=g['bufferViews'][a['bufferView']];dtype={5126:'<f4',5125:'<u4'}[a['componentType']];width={'VEC3':3,'VEC2':2,'SCALAR':1}[a['type']]
        offset=v.get('byteOffset',0)+a.get('byteOffset',0);count=a['count']*width
        assert offset+count*np.dtype(dtype).itemsize<=len(binary)
        return np.frombuffer(binary,dtype=dtype,count=count,offset=offset).reshape(-1,width)
    vertices=[];triangles=0
    for mesh in g['meshes']:
        for primitive in mesh['primitives']:
            v=array(primitive['attributes']['POSITION']);n=array(primitive['attributes']['NORMAL']);uv=array(primitive['attributes']['TEXCOORD_0']);indices=array(primitive['indices']).ravel().reshape(-1,3)
            assert np.isfinite(v).all() and np.isfinite(n).all() and np.isfinite(uv).all()
            assert indices.max()<len(v) and len(v)==len(n)==len(uv)
            assert np.allclose(np.linalg.norm(n,axis=1),1,atol=.002)
            cross=np.cross(v[indices[:,1]]-v[indices[:,0]],v[indices[:,2]]-v[indices[:,0]])
            dots=(cross*n[indices].mean(1)).sum(1)
            assert np.count_nonzero(dots>0)>=np.count_nonzero(dots<0),'Inverted mesh '+name
            vertices.append(v);triangles+=len(indices)
    vertices=np.concatenate(vertices)
    assert np.allclose(vertices.min(0),asset['min'],atol=.0001) and np.allclose(vertices.max(0),asset['max'],atol=.0001)
    assert len(vertices)==asset['vertices'] and triangles==asset['triangles']
    for im in g.get('images',[]):
        p=(path.parent/im['uri']).resolve();assert p.is_relative_to((root/'assets/world').resolve()) and p.is_file();textures.add(p)
for building in layout['buildings']:
    height=building['height'];assert height%4==0 and 50<=height<=100
    asset=next(a for a in report['assets'].values() if a['asset']==building['asset'])
    assert np.allclose(building['center'],[building['position'][0],height/2,building['position'][2]])
    assert abs(building['half'][0]-max(abs(asset['min'][0]),abs(asset['max'][0])))<.001
    assert abs(building['half'][2]-max(abs(asset['min'][2]),abs(asset['max'][2])))<.001
for car in layout['cars']:
    assert car['scale']==1 and car['position'][1]==.015
    a=next(a for a in report['assets'].values() if a['asset']==car['asset'])
    assert 4<a['size'][2]<6 and 1.5<a['size'][0]<3 and abs(a['min'][1])<.0001
    p=np.array(car['position']);c=abs(math.cos(car['yaw']));s=abs(math.sin(car['yaw']));car_half=np.array([(c*a['size'][0]+s*a['size'][2])/2,(s*a['size'][0]+c*a['size'][2])/2])
    for b in layout['buildings']:
        center=np.array(b['center']);h=np.array(b['half']);separation=np.abs(p[[0,2]]-center[[0,2]])-h[[0,2]]-car_half
        assert (separation>0).any(),'Car intersects building'
for i,c in enumerate(layout['cars']):
    for d in layout['cars'][i+1:]:assert np.linalg.norm(np.array(c['position'])-np.array(d['position']))>6,'Overlapping parked cars'
result={'passed':True,'buildings':len(layout['buildings']),'cars':len(layout['cars']),'car_scale':1,'units':'meters','assets_checked':len(report['assets']),'referenced_textures_checked':len(textures),'facade_floor_height':4,'building_layout_from_original_game':False}
(root/'research/world_validation.json').write_text(json.dumps(result,indent=2));print(json.dumps(result,indent=2))
