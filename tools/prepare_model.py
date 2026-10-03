import sys,re,json,struct
from pathlib import Path
from extract_assets import ROOT,Archives,sections
sys.path.insert(0,str(ROOT/'tools/ALERT-main'))
import model_to_ascii
model_to_ascii.main(['convert',str(ROOT/'assets/source/characters/hero/hero_spiderman/hero_spiderman_body.model'),str(ROOT/'tools/character.ascii'),str(ROOT/'tools/character_materials.txt')])
a=Archives(); manifest=json.loads((ROOT/'assets/source_manifest.json').read_text())
textures=set()
for p in (ROOT/'assets/source').rglob('*.material'):
    for x in re.findall(rb'[\x20-\x7e]+\.texture',p.read_bytes()):
        textures.add(x.decode().replace('\\','/').lower())
for name in sorted(textures):
    if name in a.by_name and a.by_name[name] in a.indices:
        r=a.extract(name); manifest.append(r); print(r['bytes'],name,flush=True)
extra=['characters/hero/hero_spiderman/animations/stand_idle_spiderman.animclip','characters/hero/hero_spiderman/animations/sprint_fwd_spiderman.animclip']
for name in extra:
    if name in a.by_name and a.by_name[name] in a.indices:
        r=a.extract(name); manifest.append(r); print(r['bytes'],name,flush=True)
(ROOT/'assets/source_manifest.json').write_text(json.dumps(manifest,indent=2))
for path in (ROOT/'assets/source').rglob('*.animclip'):
    b=path.read_bytes(); d=b[b.find(b'1TAD'):]; s=sections(d)
    print('ANIM',path.stem,[(hex(k),len(v)) for k,v in s.items()])
    break
