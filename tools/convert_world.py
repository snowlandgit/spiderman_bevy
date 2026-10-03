"""Original meter-scale game meshes to static glTF, with sandbox building assemblies.
Facade modules retain native geometry, UVs and 4 m floor spacing. The layout and
roof closure slabs are authored here; this is not an extracted Manhattan block.
"""
import json,struct,math,collections,hashlib
from pathlib import Path
import numpy as np
from extract_assets import ROOT
work=ROOT/'tools/world';out=ROOT/'assets/world';out.mkdir(exist_ok=True)
models=json.loads((work/'models.json').read_text());maps=json.loads((work/'materials.json').read_text());textures=json.loads((work/'textures.json').read_text())

def read_mesh(alias):
    lines=iter((work/(alias+'.ascii')).read_text().splitlines());bones=int(next(lines))
    for _ in range(bones):next(lines);next(lines);next(lines)
    parts=[]
    for _ in range(int(next(lines))):
        name=next(lines);uvs=int(next(lines));texs=int(next(lines))
        for _ in range(texs):next(lines);next(lines)
        verts=[];normals=[];uv=[]
        for _ in range(int(next(lines))):
            verts.append(list(map(float,next(lines).split())));normals.append(list(map(float,next(lines).split())));next(lines)
            tex=[list(map(float,next(lines).split())) for _ in range(uvs)];uv.append(tex[0] if tex else [0,0])
            if bones:next(lines);next(lines)
        faces=np.array([list(map(int,next(lines).split())) for _ in range(int(next(lines)))],dtype=np.int32)
        valid=(faces.min(1)>=0)&(faces.max(1)<len(verts))&(faces[:,0]!=faces[:,1])&(faces[:,1]!=faces[:,2])&(faces[:,0]!=faces[:,2]);faces=faces[valid][:,[0,2,1]]
        v=np.array(verts,dtype=np.float32);n=np.array(normals,dtype=np.float32);n/=np.maximum(np.linalg.norm(n,axis=1,keepdims=True),1e-8)
        # ALERT's flipped index stream is restored to the source's normal-facing winding.
        cross=np.cross(v[faces[:,1]]-v[faces[:,0]],v[faces[:,2]]-v[faces[:,0]])
        dots=(cross*n[faces].mean(1)).sum(1)
        if np.count_nonzero(dots<0)>np.count_nonzero(dots>0):faces=faces[:,[0,2,1]]
        parts.append((name[5:].replace('\\','/').lower(),v,n,np.array(uv,dtype=np.float32),faces))
    return parts
source={alias:read_mesh(alias) for alias in models}

class Glb:
    def __init__(self,paint=None):
        self.data=bytearray();self.g={'asset':{'version':'2.0','generator':'MSMR static asset converter'},'scene':0,'scenes':[{'nodes':[0]}],'nodes':[{'name':'Original game asset','mesh':0}],'meshes':[],'materials':[],'textures':[],'images':[],'samplers':[{'magFilter':9729,'minFilter':9987,'wrapS':10497,'wrapT':10497}],'accessors':[],'bufferViews':[]};self.mat={};self.tex={};self.paint=paint
    def array(self,a,typ,component,target=None):
        while len(self.data)%4:self.data.append(0)
        off=len(self.data);self.data.extend(a.tobytes());view={'buffer':0,'byteOffset':off,'byteLength':a.nbytes}
        if target:view['target']=target
        vi=len(self.g['bufferViews']);self.g['bufferViews'].append(view)
        ac={'bufferView':vi,'componentType':component,'count':len(a),'type':typ}
        if typ=='VEC3':ac.update(min=a.min(0).tolist(),max=a.max(0).tolist())
        index=len(self.g['accessors']);self.g['accessors'].append(ac);return index
    def texture(self,path):
        if path not in self.tex:
            ti=len(self.g['textures']);self.tex[path]=ti
            self.g['images'].append({'uri':'textures/'+textures[path]});self.g['textures'].append({'source':len(self.g['images'])-1,'sampler':0})
        return self.tex[path]
    def material(self,path):
        if path in self.mat:return self.mat[path]
        name=Path(path).stem;refs=[p for p in maps.get(path,[]) if p in textures]
        glass='glass' in name or 'window_mtg' in name or 'window_mts' in name
        metal=any(s in name for s in ['metal','brass','trim','ext','exterior'])
        color=[.64,.65,.66,1] if path=='sandbox_roof' else [1,1,1,1]
        if glass:color=[.065,.105,.14,1]
        if 'window_mts' in name:color=[.12,.16,.18,1]
        if 'window_mtg_v4_4x4_02' in name:color=[.08,.17,.20,1]
        if 'red' in name:color=[.22,.025,.022,1]
        if 'black' in name:color=[.045,.05,.052,1]
        if self.paint and any(s in name for s in ['sedan_01_ext_','suv_cine_ext','hybridtaxi_ext']):color=list(self.paint)+[1]
        pbr={'baseColorFactor':color,'metallicFactor':.52 if metal or glass else 0,'roughnessFactor':.19 if glass else (.3 if metal else .8)}
        candidates=[p for p in refs if p.endswith('_c.texture') and not any(s in p for s in ['blend_rust','dirt','detail'])]
        if candidates and not glass:pbr['baseColorTexture']={'index':self.texture(candidates[-1])}
        normal=[p for p in refs if p.endswith('_n.texture') and not any(s in p for s in ['detail','pink','distortion','rust'])]
        mat={'name':name,'pbrMetallicRoughness':pbr}
        if normal:mat['normalTexture']={'index':self.texture(normal[0]),'scale':.65}
        # Native decal and interior shader layers are approximated by standard PBR.
        if 'decal' in name:mat['alphaMode']='MASK';mat['alphaCutoff']=.5
        mi=len(self.g['materials']);self.mat[path]=mi;self.g['materials'].append(mat);return mi
    def write(self,alias,parts):
        groups=collections.defaultdict(list)
        for part in parts:groups[part[0]].append(part)
        primitives=[];allv=[];tris=0
        for path,entries in groups.items():
            vertices=[];normals=[];uvs=[];faces=[];offset=0
            for _,v,n,u,f in entries:
                vertices.append(v);normals.append(n);uvs.append(u);faces.append(f+offset);offset+=len(v)
            v=np.concatenate(vertices).astype('<f4');n=np.concatenate(normals).astype('<f4');u=np.concatenate(uvs).astype('<f4');f=np.concatenate(faces).astype('<u4').ravel()
            allv.append(v);tris+=len(f)//3
            attributes={'POSITION':self.array(v,'VEC3',5126,34962),'NORMAL':self.array(n,'VEC3',5126,34962),'TEXCOORD_0':self.array(u,'VEC2',5126,34962)}
            primitives.append({'attributes':attributes,'indices':self.array(f,'SCALAR',5125,34963),'material':self.material(path)})
        self.g['meshes']=[{'name':alias,'primitives':primitives}];self.g['buffers']=[{'byteLength':len(self.data)}]
        j=json.dumps(self.g,separators=(',',':')).encode();j+=b' '*((-len(j))%4);b=bytes(self.data)+b'\0'*((-len(self.data))%4)
        glb=struct.pack('<III',0x46546c67,2,12+8+len(j)+8+len(b))+struct.pack('<II',len(j),0x4e4f534a)+j+struct.pack('<II',len(b),0x004e4942)+b
        (out/(alias+'.glb')).write_bytes(glb);v=np.concatenate(allv)
        report={'asset':'world/'+alias+'.glb','min':v.min(0).tolist(),'max':v.max(0).tolist(),'size':np.ptp(v,axis=0).tolist(),'vertices':len(v),'triangles':tris,'sha256':hashlib.sha256(glb).hexdigest()}
        print(alias,report['vertices'],report['triangles'],[round(x,3) for x in report['size']],flush=True);return report

def transformed(parts,angle=0,translation=(0,0,0)):
    c=math.cos(angle);s=math.sin(angle);r=np.array([[c,0,s],[0,1,0],[-s,0,c]],dtype=np.float32);t=np.array(translation,dtype=np.float32)
    return [(p,v@r.T+t,n@r.T,u,f) for p,v,n,u,f in parts]

def slab(width,depth,height):
    # Roof closure only; all visible tower facades come from original kit geometry.
    v=np.array([[-width/2,height,-depth/2],[-width/2,height,depth/2],[width/2,height,depth/2],[width/2,height,-depth/2]],dtype=np.float32)
    return [('sandbox_roof',v,np.tile([0,1,0],(4,1)).astype(np.float32),np.array([[0,0],[0,depth],[width,depth],[width,0]],dtype=np.float32),np.array([[0,1,2],[0,2,3]],dtype=np.int32))]
report={'units':'meters','car_scale':1,'building_assembly':'Original Midtown kit meshes in a custom sandbox arrangement','assets':{},'buildings':[],'cars':[]}
for alias,paint in [('sedan_blue',(.11,.24,.42)),('sedan_red',(.38,.045,.025)),('sedan_silver',(.6,.62,.64)),('taxi',(.95,.68,.045)),('suv',(.14,.16,.19))]:
    mesh=source['sedan' if alias.startswith('sedan_') else alias];v=np.concatenate([p[1] for p in mesh]);origin=[(v[:,0].min()+v[:,0].max())/2,v[:,1].min(),(v[:,2].min()+v[:,2].max())/2]
    mesh=transformed(mesh,translation=-np.array(origin));r=Glb(paint).write(alias,mesh);report['assets'][alias]=r
    assert 4<r['size'][2]<6 and 1.5<r['size'][0]<3 and 1.2<r['size'][1]<2.5
layout=[(-27,-20,20,24,56,2),(26,-43,20,24,72,1),(-26,-82,24,24,88,0),(28,-122,24,24,64,2),(-26,-163,24,24,76,1),(28,-198,24,24,92,0),(-23,-235,24,24,64,2)]
styles=['sza_mtg_window_v1_4x4','sza_mtg_window_v4_4x4','sza_mts_window_v1_4x4']
for i,(x,z,width,depth,height,style) in enumerate(layout):
    parts=[];kit=styles[style];cap='sza_mts_window_cap_v1_4x4' if style==2 else 'sza_mtg_window_cap_v1_4x4';door='sza_mts_door_1stfl_8x8' if style==2 else 'sza_mtg_door_v1_1stfl_8x8'
    for face in range(4):
        angle=face*math.pi/2;face_width=width if face%2==0 else depth;distance=depth/2 if face%2==0 else width/2
        for y in range(0,height,4):
            for column in range(int(face_width)//4):
                along=-face_width/2+2+column*4;chosen=cap if y==height-4 else (door if y==0 and column==int(face_width)//8 else kit)
                pos=(along, y, distance-.2)
                c=math.cos(angle);s=math.sin(angle);translation=(c*pos[0]+s*pos[2],y,-s*pos[0]+c*pos[2])
                parts.extend(transformed(source[chosen],angle,translation))
    parts.extend(slab(width-.4,depth-.4,height))
    for ax,az in [(-width/4,-depth/4),(width/4,depth/4)]:
        ac=source['pp_skyscraper_ac_unit'];v=np.concatenate([p[1] for p in ac]);offset=np.array([ax-(v[:,0].max()+v[:,0].min())/2,height-v[:,1].min(),az-(v[:,2].max()+v[:,2].min())/2]);parts.extend(transformed(ac,translation=offset))
    alias=f'tower_{i+1}';r=Glb().write(alias,parts);report['assets'][alias]=r
    # Match the collision envelope to visible facades; rooftop props are visual only.
    half=[max(abs(r['min'][0]),abs(r['max'][0])),height/2,max(abs(r['min'][2]),abs(r['max'][2]))]
    report['buildings'].append({'asset':r['asset'],'name':['Midtown glass','Midtown bronze glass','Midtown stone'][style],'position':[x,0,z],'center':[x,height/2,z],'half':half,'height':height,'facade_source':models[kit]})
rng=np.random.default_rng(1701);choices=['sedan_blue','sedan_red','sedan_silver','taxi','suv']
for side in [-1,1]:
    for k,z in enumerate(np.arange(24,-280,-10)):
        if rng.random()<.14:continue
        alias=choices[int(rng.integers(0,len(choices)))];x=side*(8.0+float(rng.uniform(-.25,.25)));z=float(z+rng.uniform(-1,1))
        yaw=(0 if side<0 else math.pi)+float(rng.uniform(-.035,.035))
        report['cars'].append({'asset':report['assets'][alias]['asset'],'position':[x,.015,z],'yaw':yaw,'scale':1})
(out/'layout.json').write_text(json.dumps({'buildings':report['buildings'],'cars':report['cars']},indent=2));(ROOT/'research/world_assets.json').write_text(json.dumps(report,indent=2))
print('SCENE',len(report['buildings']),'buildings',len(report['cars']),'cars',flush=True)
