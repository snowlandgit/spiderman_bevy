import struct,json,numpy as np
from extract_assets import ROOT,sections
base=json.loads((ROOT/'research/base_model_skeleton.json').read_text());base={r['name']:r for r in base}
b=(ROOT/'assets/source/characters/hero/hero_spiderman/hero_spiderman_body.model').read_bytes();data=b[b.find(b'1TAD'):];s=sections(data)
for i,r in enumerate(struct.iter_unpack('<hHHHII',s[0x15df9d3b])):
 name=data[r[5]:data.index(b'\0',r[5])].decode();t=struct.unpack_from('<12f',s[0xdcc88a19],48*i)
 if name in base:
  n=base[name]['transform'];d=abs(np.dot(np.array(t[4:8]),np.array(n[4:8])))
  pos=np.linalg.norm(np.array(t[8:11])-np.array(n[8:11]))
  if d<.999 or pos>.01:print(name,'angle',np.degrees(2*np.arccos(min(1,d))),'posdiff',round(pos,3),'bodyq',t[4:8],'baseq',n[4:8])
