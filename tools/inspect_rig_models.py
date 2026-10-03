import struct
from extract_assets import ROOT,sections,Archives
archives=Archives()
for path in (ROOT/'assets/source/characters/hero/hma_master').glob('*.animset'):
 b=path.read_bytes();s=sections(b[b.find(b'1TAD'):]);head=struct.unpack('<4IQ6I',s[0xd614b18b]);print(path.name,head,archives.names.get(head[4]))
p=ROOT/'assets/source/actors/hrm_bdy_firsthero/hero_spiderman.actor';b=p.read_bytes();b=b[b.find(b'1TAD'):];off=struct.unpack('<I',sections(b)[0x32fac8e0])[0];print('actor model',b[off:b.index(b'\0',off)])
