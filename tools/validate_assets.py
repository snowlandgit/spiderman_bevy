"""Validate converted assets and rendered captures; does not certify game fidelity."""
from pathlib import Path
import json, struct, hashlib, math
ROOT=Path(__file__).resolve().parents[1]

def check(condition,message):
    if not condition: raise RuntimeError(message)

blob=(ROOT/'assets/character/spiderman.glb').read_bytes()
magic,version,length=struct.unpack_from('<III',blob)
check(magic==0x46546c67 and version==2 and length==len(blob),'Invalid GLB header')
json_size,json_type=struct.unpack_from('<II',blob,12)
check(json_type==0x4e4f534a,'Missing GLB JSON chunk')
gltf=json.loads(blob[20:20+json_size]); binary=blob[28+json_size:]
widths={'SCALAR':1,'VEC2':2,'VEC3':3,'VEC4':4,'MAT4':16}
formats={5126:'f',5125:'I',5123:'H',5121:'B'}
def rows(index):
    a=gltf['accessors'][index];v=gltf['bufferViews'][a['bufferView']]
    width=widths[a['type']];fmt='<'+formats[a['componentType']]*width
    size=struct.calcsize(fmt);offset=v.get('byteOffset',0)+a.get('byteOffset',0)
    step=v.get('byteStride',size)
    check(offset+(a['count']-1)*step+size<=len(binary),'Accessor outside binary buffer')
    return [struct.unpack_from(fmt,binary,offset+i*step) for i in range(a['count'])]

check(len(gltf['meshes'])==18,'Expected all original 18 suit mesh sections')
check(len(gltf['skins'])==1 and len(gltf['skins'][0]['joints'])==212,'Expected original 212-bone skin')
conversion=json.loads((ROOT/'assets/character/conversion.json').read_text())
check(len(gltf['animations'])==len(conversion['clips']),'Animation count differs from conversion metadata')
check({a['name'] for a in gltf['animations']}=={c['name'] for c in conversion['clips']},'Animation names differ from conversion metadata')
# Check the exported hierarchy against the game's inverse-bind matrices.
# A self-consistent GLB can still contain wrong rest rotations, so checking only
# its own inverse-bind matrices would miss the zero-length EditBone regression.
def mul(a,b):
    return [[sum(a[r][k]*b[k][c] for k in range(4)) for c in range(4)] for r in range(4)]

def node_matrix(node):
    if 'matrix' in node:
        values=node['matrix']; return [[values[c*4+r] for c in range(4)] for r in range(4)]
    x,y,z,w=node.get('rotation',[0,0,0,1]); scale=node.get('scale',[1,1,1])
    matrix=[[1-2*(y*y+z*z),2*(x*y-z*w),2*(x*z+y*w),0],
            [2*(x*y+z*w),1-2*(x*x+z*z),2*(y*z-x*w),0],
            [2*(x*z-y*w),2*(y*z+x*w),1-2*(x*x+y*y),0],[0,0,0,1]]
    for r in range(3):
        for c in range(3): matrix[r][c]*=scale[c]
        matrix[r][3]=node.get('translation',[0,0,0])[r]
    return matrix
parents={c:i for i,n in enumerate(gltf['nodes']) for c in n.get('children',[])}
world={}
def world_matrix(index):
    if index not in world:
        local=node_matrix(gltf['nodes'][index])
        world[index]=mul(world_matrix(parents[index]),local) if index in parents else local
    return world[index]
source=(ROOT/'assets/source/characters/hero/hero_spiderman/hero_spiderman_body.model').read_bytes()
source=source[source.find(b'1TAD'):]
sections={tag:source[offset:offset+size] for tag,offset,size in
          (struct.unpack_from('<III',source,16+i*12) for i in range(struct.unpack_from('<H',source,12)[0]))}
source_joints=list(struct.iter_unpack('<hHHHII',sections[0x15df9d3b]))
native_bind={}
for i,record in enumerate(source_joints):
    offset=record[5]; name=source[offset:source.index(b'\0',offset)].decode()
    values=struct.unpack_from('<16f',sections[0xdcc88a19],len(source_joints)*48+i*64)
    native_bind[name]=[[values[c*4+r] for c in range(4)] for r in range(4)]
rest_errors=[]
for index in gltf['skins'][0]['joints']:
    name=gltf['nodes'][index]['name']
    check(name in native_bind,'Unknown exported skin joint '+name)
    identity=mul(world_matrix(index),native_bind[name])
    rest_errors.append(max(abs(identity[r][c]-(1 if r==c else 0)) for r in range(4) for c in range(4)))
check(max(rest_errors)<.0001,'Exported bones do not match native bind transforms: '+str(max(rest_errors)))
for mesh in gltf['meshes']:
    for p in mesh['primitives']:
        vertices=rows(p['attributes']['POSITION'])
        check(all(all(math.isfinite(n) for n in row) for row in vertices),'Nonfinite mesh position')
        check(all(all(j<212 for j in row) for row in rows(p['attributes']['JOINTS_0'])),'Skin joint outside palette')
        weights=rows(p['attributes']['WEIGHTS_0'])
        check(all(abs(sum(row)-1)<0.0001 and min(row)>=0 for row in weights),'Invalid normalized skin weight')
for animation in gltf['animations']:
    for sampler in animation['samplers']:
        times=[r[0] for r in rows(sampler['input'])]
        check(all(math.isfinite(t) for t in times),'Nonfinite animation time')
        check(all(a<b for a,b in zip(times,times[1:])),'Animation keys out of order')
        check(all(all(math.isfinite(x) for x in r) for r in rows(sampler['output'])),'Nonfinite animation value')

manifest=json.loads((ROOT/'assets/source_manifest.json').read_text(encoding='utf-8-sig'))
records={r['path']:r for r in manifest}
for name,record in records.items():
    source=(ROOT/'assets/source'/name).read_bytes()
    check(len(source)==record['bytes'],'Source size mismatch: '+name)
    check(hashlib.sha256(source).hexdigest()==record['sha256'],'Source checksum mismatch: '+name)

captures={}
try:
    from PIL import Image
    for name in ['swing','swing_main','release','traversal','zip_fire','zip_flight','roof_zip','jump_charge','high_jump','long_jump']:
        path=ROOT/'screenshots'/f'{name}.png'
        im=Image.open(path).convert('RGB');colors=im.crop((100,100,im.width-100,im.height-100)).getcolors(im.width*im.height)
        unique=len(colors) if colors else im.width*im.height
        check(unique>1000,'Capture has no rendered 3D scene: '+name)
        captures[name]={'resolution':list(im.size),'unique_scene_colors':unique}
except ImportError:
    captures={'status':'Pillow unavailable; image verification skipped'}

report={'asset_validation_passed':True,'meshes':len(gltf['meshes']),'joints':212,'animations':len(gltf['animations']),'native_bind_max_identity_error':max(rest_errors),'source_files_checked':len(records),'captures':captures,'one_to_one_fidelity_verified':False,'known_gap':'Native traversal, animation blending, IK and layered materials are not fully ported.'}
(ROOT/'validation_report.json').write_text(json.dumps(report,indent=2))
print(json.dumps(report,indent=2))
