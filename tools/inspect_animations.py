import struct,json
from pathlib import Path
from extract_assets import ROOT,sections
for stem in ['stand_idle_spiderman','web_swing_rh_a_spiderman','web_swing_2rh_000_twist_0_spiderman']:
    path=next((ROOT/'assets/source').rglob(stem+'.animclip')); b=path.read_bytes(); d=b[b.find(b'1TAD'):]; s=sections(d)
    cb=struct.unpack_from('<IIIffBBBBIIHHIIHHHHHHHHHHfIIII12s',s[0x9DF23F77])
    print(stem, 'header', list(enumerate(cb)), 'sections',[(hex(k),len(v)) for k,v in s.items()])
