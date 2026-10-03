import io,struct,json,math
from pathlib import Path
from PIL import Image
import numpy as np
from extract_assets import ROOT,sections
out=ROOT/'assets/character/textures'; out.mkdir(parents=True,exist_ok=True)
report=[]
for p in (ROOT/'assets/source').rglob('*.texture'):
    b=p.read_bytes(); off=b.find(b'1TAD')
    if off<0: continue
    d=b[off:]; size=struct.unpack_from('<I',d,8)[0]; s=sections(d); h=s.get(0x4EDE3593)
    if h is None: continue
    sd_len,hd_len,hd_w,hd_h,w,height=struct.unpack_from('<IIHHHH',h)
    fmt=struct.unpack_from('<H',h,20)[0]; mips=h[30]
    if not w or not height: continue
    header=b'DDS '+struct.pack('<7I',124,0x000a1007,height,w,w*4,0,mips)+bytes(44)
    header+=struct.pack('<II4sIIIII',32,4,b'DX10',0,0,0,0,0)
    header+=struct.pack('<5I',0x401008,0,0,0,0)+struct.pack('<5I',fmt,3,0,1,0)
    try:
        im=Image.open(io.BytesIO(header+d[size:])).convert('RGBA')
        if p.stem.lower().endswith('_n'):
            # Insomniac stores tangent-space X/Y; reconstruct the omitted positive Z.
            pixels=np.array(im)
            x=pixels[:,:,0].astype(np.float32)/127.5-1
            y=pixels[:,:,1].astype(np.float32)/127.5-1
            z=np.sqrt(np.maximum(0,1-x*x-y*y))
            pixels[:,:,1]=255-pixels[:,:,1] # DirectX -> glTF/OpenGL tangent convention.
            pixels[:,:,2]=np.rint((z+1)*127.5).astype(np.uint8)
            pixels[:,:,3]=255
            im=Image.fromarray(pixels)
        im.save(out/(p.stem+'.png'))
        report.append({'name':p.stem,'width':w,'height':height,'format':fmt})
    except Exception as e: print('TEXTURE_ERROR',p.stem,fmt,str(e),flush=True)
(ROOT/'tools/texture_report.json').write_text(json.dumps(report,indent=2))
print('Converted',len(report),'textures')
show=['hero_spiderman_body_modcolor_c','hero_spiderman_head_c','hero_spiderman_glove_modcolor_c','reviewasset_spiderman_leg_modcolor_c','hero_spiderman_body_c']
canvas=Image.new('RGB',(256*len(show),256),'#444444')
for i,name in enumerate(show):
    p=out/(name+'.png')
    if p.exists(): canvas.paste(Image.open(p).convert('RGB').resize((256,256)),(256*i,0))
canvas.save(ROOT/'tools/textures_preview.png')
