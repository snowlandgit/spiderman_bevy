import sys,json
from pathlib import Path
from extract_assets import ROOT,Archives
a=Archives(); manifest=json.loads((ROOT/'assets/source_manifest.json').read_text())
for rel in ['stand_jog_fwd_spiderman','stand_sprint_fwd_spiderman','stand_jump_fwd_spiderman']:
    name='characters/hero/hero_spiderman/animations/'+rel+'.animclip'
    if name in a.by_name and a.by_name[name] in a.indices:
        record=a.extract(name); manifest.append(record); print(name,flush=True)
for name in a.available(r'^characters/hero/hero_spiderman/animations/traversal/wallrun.*animclip$')[:5]: print('WALL',name)
(ROOT/'assets/source_manifest.json').write_text(json.dumps(manifest,indent=2))
