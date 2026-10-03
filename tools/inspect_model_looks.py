import struct,json
from extract_assets import ROOT,sections
p=ROOT/'assets/source/characters/hero/hero_spiderman/hero_spiderman_body.model';raw=p.read_bytes();d=raw[raw.find(b'1TAD'):];s=sections(d)
for tag in [0x811902d7,0x06eb7efc,0xdcA379a2]:
 v=s[tag];print(hex(tag),'bytes',len(v))
 if tag==0x811902d7:
  for i in range(len(s[0x06eb7efc])//32):
   off=i*80;rec=struct.unpack_from('<16I4I',v,off);name=d[rec[-1]:d.index(b'\0',rec[-1])].decode();ptr=struct.unpack_from('<Q',v,off)[0];count=struct.unpack_from('<H',v,off+56)[0];ids=struct.unpack_from('<'+'H'*count,v,ptr);print(i,name,rec,'ids',ids)
 if tag==0x06eb7efc:print(list(struct.iter_unpack('<16H',v)))
 if tag==0xdca379a2: print('Skin data, not dumped')
