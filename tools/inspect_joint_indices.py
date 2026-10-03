from pathlib import Path
import sys,struct,json
root=Path(__file__).resolve().parents[1];sys.path.insert(0,str(root/'tools'))
from extract_assets import sections
p=root/'assets/source/characters/hero/hero_spiderman/hero_spiderman_body.model';b=p.read_bytes();s=sections(b[b.find(b'1TAD'):]);j=s[0x15df9d3b]
records=list(struct.iter_unpack('<hHHHII',j))
for i,r in enumerate(records):
 if i<35 or 92<=i<144:print(i,r)
print('all-index-is-slot',all(r[1]==i for i,r in enumerate(records)))
print('bind-indices',struct.unpack('<'+'H'*(len(s[0xB7380E8C])//2),s[0xB7380E8C]))
