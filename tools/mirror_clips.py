"""Bake left/right counterparts by reflecting native skin deformation in model space.
Asymmetric bind frames are retained. Mirroring local quaternions alone is wrong
for this skeleton, whose left/right clavicle axes differ by 180 degrees.
"""
import json,struct,copy
from pathlib import Path
import numpy as np
root=Path(__file__).resolve().parents[1];path=root/'assets/character/spiderman.glb'
b=path.read_bytes();size=struct.unpack_from('<I',b,12)[0];g=json.loads(b[20:20+size]);binary=bytearray(b[28+size:]);nodes=g['nodes'];count=len(nodes)
parents={c:i for i,n in enumerate(nodes) for c in n.get('children',[])};joint_set=set(g['skins'][0]['joints']);names={n.get('name'):i for i,n in enumerate(nodes)}
widths={'SCALAR':1,'VEC2':2,'VEC3':3,'VEC4':4,'MAT4':16}
def rows(index):
    a=g['accessors'][index];v=g['bufferViews'][a['bufferView']];width=widths[a['type']];dtype={5126:'<f4',5123:'<u2',5125:'<u4'}[a['componentType']];off=v.get('byteOffset',0)+a.get('byteOffset',0)
    return np.ndarray((a['count'],width),dtype=dtype,buffer=binary,offset=off,strides=(v.get('byteStride',width*np.dtype(dtype).itemsize),np.dtype(dtype).itemsize)).copy()
def matrices(t,q,s):
    q=q/np.linalg.norm(q,axis=-1,keepdims=True);x,y,z,w=np.moveaxis(q,-1,0);m=np.zeros(q.shape[:-1]+(4,4),dtype=np.float64)
    m[...,0,0]=1-2*(y*y+z*z);m[...,0,1]=2*(x*y-z*w);m[...,0,2]=2*(x*z+y*w)
    m[...,1,0]=2*(x*y+z*w);m[...,1,1]=1-2*(x*x+z*z);m[...,1,2]=2*(y*z-x*w)
    m[...,2,0]=2*(x*z-y*w);m[...,2,1]=2*(y*z+x*w);m[...,2,2]=1-2*(x*x+y*y)
    m[...,:3,:3]*=s[...,None,:];m[...,:3,3]=t;m[...,3,3]=1;return m
def quat(m):
    result=np.empty((len(m),4));tr=np.trace(m,axis1=1,axis2=2);diag=np.diagonal(m,axis1=1,axis2=2);kind=np.where(tr>0,3,np.argmax(diag,axis=1))
    for k in range(4):
        mask=kind==k;r=m[mask]
        if not len(r):continue
        if k==3:
            s=np.sqrt(1+tr[mask])*2;result[mask]=np.column_stack([(r[:,2,1]-r[:,1,2])/s,(r[:,0,2]-r[:,2,0])/s,(r[:,1,0]-r[:,0,1])/s,.25*s])
        else:
            i,j=(k+1)%3,(k+2)%3;s=np.sqrt(1+r[:,k,k]-r[:,i,i]-r[:,j,j])*2;v=np.empty((len(r),4));v[:,k]=.25*s;v[:,i]=(r[:,k,i]+r[:,i,k])/s;v[:,j]=(r[:,k,j]+r[:,j,k])/s;v[:,3]=(r[:,j,i]-r[:,i,j])/s;result[mask]=v
    result/=np.linalg.norm(result,axis=1,keepdims=True)
    for i in range(1,len(result)):
        if np.dot(result[i-1],result[i])<0:result[i]*=-1
    return result
local=np.array([np.array(n['matrix']).reshape(4,4).T if 'matrix' in n else matrices(np.array(n.get('translation',[0,0,0])),np.array(n.get('rotation',[0,0,0,1])),np.array(n.get('scale',[1,1,1]))) for n in nodes])
order=[]
def visit(i):
    if i in order:return
    if i in parents:visit(parents[i])
    order.append(i)
for i in range(count):visit(i)
rest=np.empty_like(local)
for i in order:rest[i]=rest[parents[i]]@local[i] if i in parents else local[i]
reflection=np.diag([-1.,1.,1.,1.]);swapped={}
for i in joint_set:
    name=nodes[i]['name'];mirror=name.replace('LF_','RT_') if 'LF_' in name else name.replace('RT_','LF_')
    swapped[i]=names.get(mirror,i)
def add_array(array,kind):
    array=np.array(array,dtype='<f4');array=array.reshape(-1,widths[kind])
    while len(binary)%4:binary.append(0)
    off=len(binary);binary.extend(array.tobytes());view=len(g['bufferViews']);g['bufferViews'].append({'buffer':0,'byteOffset':off,'byteLength':array.nbytes});ac=len(g['accessors']);g['accessors'].append({'bufferView':view,'componentType':5126,'count':len(array),'type':kind,'min':array.min(0).tolist(),'max':array.max(0).tolist()});return ac
conversion=json.loads((root/'assets/character/conversion.json').read_text());meta={c['name']:c for c in conversion['clips']};results=[]
selected=['web_swing_fwd_rh_spiderman','web_swing_intro_fromairaggro_fwd_rh_spiderman','web_swing_intro_fromfastfall_fwd_rh_spiderman']
selected += [name for name in meta if name.startswith(('web_swing_release_','web_swing_jump_'))]
for animation in list(g['animations']):
    name=animation['name']
    if name not in selected:continue
    times=np.unique(np.concatenate([rows(s['input']).ravel() for s in animation['samplers']])).astype(np.float64);frames=len(times)
    t=np.array([n.get('translation',[0,0,0]) for n in nodes],dtype=np.float64)[None].repeat(frames,axis=0);q=np.array([n.get('rotation',[0,0,0,1]) for n in nodes],dtype=np.float64)[None].repeat(frames,axis=0);scale=np.array([n.get('scale',[1,1,1]) for n in nodes],dtype=np.float64)[None].repeat(frames,axis=0)
    for channel in animation['channels']:
        sampler=animation['samplers'][channel['sampler']];assert sampler.get('interpolation','LINEAR') in ('LINEAR','STEP');target=channel['target'];index=target['node'];source_times=rows(sampler['input']).ravel();values=rows(sampler['output'])
        if sampler.get('interpolation')=='STEP':
            dest=q if target['path']=='rotation' else (t if target['path']=='translation' else scale)
            indices=np.clip(np.searchsorted(source_times,times,side='right')-1,0,len(source_times)-1);dest[:,index]=values[indices]
        elif target['path']=='rotation':
            # Preserve exported native keys exactly. Missing intermediate keys use SLERP.
            indices=np.searchsorted(source_times,times,side='right')-1;indices=np.clip(indices,0,len(source_times)-1);next_indices=np.minimum(indices+1,len(source_times)-1)
            fraction=np.divide(times-source_times[indices],source_times[next_indices]-source_times[indices],out=np.zeros_like(times),where=source_times[next_indices]!=source_times[indices]);fraction=np.clip(fraction,0,1)
            a=values[indices].astype(np.float64);z=values[next_indices].astype(np.float64);dot=(a*z).sum(1);z[dot<0]*=-1;dot=np.clip(np.abs(dot),0,1);theta=np.arccos(dot);sine=np.sin(theta);wa=np.divide(np.sin((1-fraction)*theta),sine,out=1-fraction,where=sine>1e-6);wz=np.divide(np.sin(fraction*theta),sine,out=fraction.copy(),where=sine>1e-6);q[:,index]=wa[:,None]*a+wz[:,None]*z
        else:
            dest=t if target['path']=='translation' else scale
            dest[:,index]=np.column_stack([np.interp(times,source_times,values[:,c]) for c in range(3)])
    current_local=matrices(t,q,scale);world=np.empty_like(current_local)
    for i in order:world[:,i]=world[:,parents[i]]@current_local[:,i] if i in parents else current_local[:,i]
    mirrored=world.copy()
    for i,j in swapped.items():mirrored[:,i]=reflection@world[:,j]@np.linalg.inv(rest[j])@reflection@rest[i]
    new={'name':name+'_mirrored','channels':[],'samplers':[]};time_accessor=add_array(times,'SCALAR');recomposed=np.empty_like(world);max_error=0.
    for i in order:
        target_local=np.linalg.inv(mirrored[:,parents[i]])@mirrored[:,i] if i in parents else mirrored[:,i]
        if i in joint_set:
            loc=target_local[:,:3,3];sca=np.linalg.norm(target_local[:,:3,:3],axis=1);rot=quat(target_local[:,:3,:3]/sca[:,None,:]);packed=matrices(loc.astype(np.float32),rot.astype(np.float32),sca.astype(np.float32))
            for kind,values,typ in [('translation',loc,'VEC3'),('rotation',rot,'VEC4'),('scale',sca,'VEC3')]:
                si=len(new['samplers']);new['samplers'].append({'input':time_accessor,'output':add_array(values,typ),'interpolation':'LINEAR'});new['channels'].append({'sampler':si,'target':{'node':i,'path':kind}})
        else:packed=current_local[:,i]
        recomposed[:,i]=recomposed[:,parents[i]]@packed if i in parents else packed
        max_error=max(max_error,float(np.abs(recomposed[:,i]-mirrored[:,i]).max()))
    assert max_error<.0005,(name,max_error)
    g['animations'].append(new);m=dict(meta[name]);m.update(name=new['name'],mirrored_from=name);conversion['clips'].append(m);results.append({'source':name,'mirrored':new['name'],'frames':frames,'max_matrix_error':max_error});print('MIRROR',name,frames,max_error,flush=True)
g['buffers'][0]['byteLength']=len(binary);j=json.dumps(g,separators=(',',':')).encode();j+=b' '*((-len(j))%4);binbytes=bytes(binary)+b'\0'*((-len(binary))%4);path.write_bytes(struct.pack('<III',0x46546c67,2,12+8+len(j)+8+len(binbytes))+struct.pack('<II',len(j),0x4e4f534a)+j+struct.pack('<II',len(binbytes),0x004e4942)+binbytes)
(root/'assets/character/conversion.json').write_text(json.dumps(conversion,indent=2));(root/'research/mirror_validation.json').write_text(json.dumps({'passed':True,'method':'Reflect skin deformation in model space, preserve asymmetric bind frames','clips':results},indent=2));print('MIRRORED_CLIPS',len(results),'TOTAL',len(g['animations']))
