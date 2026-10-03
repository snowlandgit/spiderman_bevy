import re,struct,json
from pathlib import Path
from extract_assets import ROOT,sections

def crc(text):
    value=0xedb88320
    for b in text.encode():
        value^=b
        for _ in range(8): value=(value>>1)^ (0xedb88320 if value&1 else 0)
    return value
b=(ROOT/'assets/source/characters/hero/hero_spiderman/hero_spiderman_body.model').read_bytes(); d=b[b.find(b'1TAD'):]; s=sections(d)
exe=(ROOT.parent/'Spider-Man.exe').read_bytes()
strings=[x.decode(errors='replace') for x in re.findall(rb'[\x20-\x7e]{5,}',exe)]
model_names={crc(n):n for n in strings if n.startswith('Model ')}
for key,value in s.items(): print(hex(key),model_names.get(key,'?'),len(value),value[:64].hex())
(ROOT/'tools/executable_strings.txt').write_text('\n'.join(n for n in strings if re.search('swing|Swing|HeroJump|HeroAir|HeroRope',n)))
(ROOT/'tools/model_sections.json').write_text(json.dumps({hex(k):{'name':model_names.get(k),'size':len(v)} for k,v in s.items()},indent=2))
