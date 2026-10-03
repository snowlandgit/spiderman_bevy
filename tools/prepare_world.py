"""Extract original vehicles and Midtown building kit assets without modifying archives."""
import sys,re,json,io,struct,hashlib
import numpy as np
from PIL import Image
from extract_assets import ROOT,Archives,sections
sys.path.insert(0,str(ROOT/'tools/ALERT-main'))
import model_to_ascii,dat1lib
out=ROOT/'tools/world';out.mkdir(exist_ok=True)
models=json.loads((out/'models.json').read_text())
models={k:v for k,v in models.items() if not k.startswith('group')}
a=Archives();manifest={r['path']:r for r in json.loads((ROOT/'assets/source_manifest.json').read_text())}
def extract(path):
    if path not in a.by_name or a.by_name[path] not in a.indices:return None
    manifest[path]=a.extract(path);return ROOT/'assets/source'/path
materials=set()
for alias,path in models.items():
    model_path=extract(path)
    with model_path.open('rb') as f:model=dat1lib.read(f)
    with (out/(alias+'.ascii')).open('w') as f:model_to_ascii.AsciiWriter().write_model(f,model,[0],0,materials_txt=str(out/(alias+'_materials.txt')))
    for line in (out/(alias+'_materials.txt')).read_text().splitlines():
        if '\t' in line and '.material' in line:materials.add(line.split('\t',1)[1].replace('\\','/').lower())
texture_paths=set();maps={}
for path in sorted(materials):
    p=extract(path)
    refs=[] if p is None else [x.decode().replace('\\','/').lower() for x in re.findall(rb'[\x20-\x7e]+\.texture',p.read_bytes())]
    maps[path]=refs;texture_paths.update(refs)
texture_dir=ROOT/'assets/world/textures';texture_dir.mkdir(parents=True,exist_ok=True)
textures={}
for path in sorted(texture_paths):
    p=extract(path)
    if p is None:continue
    b=p.read_bytes();off=b.find(b'1TAD')
    if off<0:continue
    d=b[off:];size=struct.unpack_from('<I',d,8)[0];h=sections(d).get(0x4EDE3593)
    if h is None:continue
    sd_len,hd_len,hd_w,hd_h,w,height=struct.unpack_from('<IIHHHH',h);fmt=struct.unpack_from('<H',h,20)[0];mips=h[30]
    dds_fmt={72:71,75:74,78:77,91:87,93:88,99:98}.get(fmt,fmt)
    header=b'DDS '+struct.pack('<7I',124,0x000a1007,height,w,w*4,0,mips)+bytes(44)
    header+=struct.pack('<II4sIIIII',32,4,b'DX10',0,0,0,0,0)+struct.pack('<5I',0x401008,0,0,0,0)+struct.pack('<5I',dds_fmt,3,0,1,0)
    try:
        if fmt in (34,35,16,61):
            channels=1 if fmt==61 else 2
            dtype={34:'<f2',35:'<u2',16:'<f4',61:'u1'}[fmt]
            raw=np.frombuffer(d[size:size+w*height*channels*np.dtype(dtype).itemsize],dtype=dtype).reshape(height,w,channels).astype(np.float32)
            if fmt==35:raw/=65535
            if fmt==61:raw/=255
            pixels=np.zeros((height,w,4),dtype=np.uint8);pixels[:,:,:channels]=np.rint(np.clip(raw,0,1)*255).astype(np.uint8);pixels[:,:,3]=255
            if channels==1:pixels[:,:,1:3]=pixels[:,:,:1]
            im=Image.fromarray(pixels)
        else:im=Image.open(io.BytesIO(header+d[size:])).convert('RGBA')
        if p.stem.lower().endswith('_n'):
            pixels=np.array(im);x=pixels[:,:,0].astype(np.float32)/127.5-1;y=pixels[:,:,1].astype(np.float32)/127.5-1
            pixels[:,:,1]=255-pixels[:,:,1];pixels[:,:,2]=np.rint((np.sqrt(np.maximum(0,1-x*x-y*y))+1)*127.5).astype(np.uint8);pixels[:,:,3]=255;im=Image.fromarray(pixels)
        filename=hashlib.sha256(path.encode()).hexdigest()[:12]+'_'+p.stem+'.png';im.save(texture_dir/filename);textures[path]=filename
    except Exception as e:print('TEXTURE_ERROR',path,repr(e),flush=True)
(out/'materials.json').write_text(json.dumps(maps,indent=2));(out/'textures.json').write_text(json.dumps(textures,indent=2))
(out/'models.json').write_text(json.dumps(models,indent=2));(ROOT/'assets/source_manifest.json').write_text(json.dumps(list(manifest.values()),indent=2))
print('WORLD_SOURCE',len(models),'models',len(materials),'materials',len(textures),'textures',flush=True)
