"""Compare exported animated joint matrices with pre-export native clip samples."""
import json,struct
from pathlib import Path
import numpy as np
root=Path(__file__).resolve().parents[1];b=(root/'assets/character/spiderman.glb').read_bytes();size=struct.unpack_from('<I',b,12)[0];g=json.loads(b[20:20+size]);binary=b[28+size:];nodes=g['nodes'];count=len(nodes);parents={c:i for i,n in enumerate(nodes) for c in n.get('children',[])};names={n.get('name'):i for i,n in enumerate(nodes)};order=[]
def visit(i):
    if i in order:return
    if i in parents:visit(parents[i])
    order.append(i)
for i in range(count):visit(i)
def rows(index):
    a=g['accessors'][index];v=g['bufferViews'][a['bufferView']];w={'SCALAR':1,'VEC3':3,'VEC4':4}[a['type']];off=v.get('byteOffset',0)+a.get('byteOffset',0)
    return np.ndarray((a['count'],w),dtype='<f4',buffer=binary,offset=off,strides=(v.get('byteStride',w*4),4)).copy()
def matrix(t,q,s):
    q=q/np.linalg.norm(q);x,y,z,w=q
    m=np.array([[1-2*(y*y+z*z),2*(x*y-z*w),2*(x*z+y*w),t[0]],[2*(x*y+z*w),1-2*(x*x+z*z),2*(y*z-x*w),t[1]],[2*(x*z-y*w),2*(y*z+x*w),1-2*(x*x+y*y),t[2]],[0,0,0,1]],dtype=np.float64);m[:3,:3]*=s;return m
rest=[np.array(n['matrix']).reshape(4,4).T if 'matrix' in n else matrix(n.get('translation',[0,0,0]),np.array(n.get('rotation',[0,0,0,1])),n.get('scale',[1,1,1])) for n in nodes]
animations={a['name']:a for a in g['animations']}
def evaluate(name,time):
    channels={};a=animations[name]
    for c in a['channels']:
        s=a['samplers'][c['sampler']];t=rows(s['input']).ravel();v=rows(s['output']);i=int(np.clip(np.searchsorted(t,time,side='right')-1,0,len(t)-1));j=min(i+1,len(t)-1);f=0 if i==j or s.get('interpolation')=='STEP' else np.clip((time-t[i])/(t[j]-t[i]),0,1)
        x=v[i].astype(np.float64);y=v[j].astype(np.float64)
        if c['target']['path']=='rotation':
            dot=np.dot(x,y)
            if dot<0:y=-y;dot=-dot
            angle=np.arccos(np.clip(dot,0,1))
            value=x*(1-f)+y*f if angle<1e-5 else (x*np.sin((1-f)*angle)+y*np.sin(f*angle))/np.sin(angle)
            value/=np.linalg.norm(value)
        else:value=x*(1-f)+y*f
        channels.setdefault(c['target']['node'],{})[c['target']['path']]=value
    world=[]
    for _ in nodes:world.append(None)
    for i in order:
        n=nodes[i];values=channels.get(i)
        local=rest[i] if values is None else matrix(values.get('translation',n.get('translation',[0,0,0])),values.get('rotation',np.array(n.get('rotation',[0,0,0,1]))),values.get('scale',n.get('scale',[1,1,1])))
        world[i]=world[parents[i]]@local if i in parents else local
    return world
reference=json.loads((root/'research/native_pose_samples.json').read_text());results=[]
for clip in reference['clips']:
    maximum=0.;position_error=0.
    for frame in clip['frames']:
        world=evaluate(clip['name'],frame['time']);expected=np.array(frame['matrices'])
        actual=np.array([world[names[name]] for name in reference['bones']]);maximum=max(maximum,float(np.abs(actual-expected).max()));position_error=max(position_error,float(np.linalg.norm(actual[:,:3,3]-expected[:,:3,3],axis=1).max()))
    print('POSE_MATCH',clip['name'],maximum,position_error,flush=True)
    assert maximum<.001 and position_error<.001,(clip['name'],maximum,position_error)
    results.append({'clip':clip['name'],'frames':len(clip['frames']),'max_matrix_error':maximum,'max_joint_position_error_m':position_error})
conversion=json.loads((root/'assets/character/conversion.json').read_text());mirrors=json.loads((root/'research/mirror_validation.json').read_text());assert mirrors['passed']
result={'passed':True,'joint_count':len(reference['bones']),'original_clips':sum('mirrored_from' not in c for c in conversion['clips']),'mirrored_clips':len(mirrors['clips']),'sampled_original_clips':results,'native_graph_runtime_parity_verified':False}
(root/'research/animation_pose_validation.json').write_text(json.dumps(result,indent=2));print('ANIMATION_POSES_VERIFIED')
