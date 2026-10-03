"""Inspect native rig assets without modifying the installed game archives."""
import json
from pathlib import Path
from extract_assets import Archives, ROOT, sections
from decode_configs import decode_file
names = [
    'actors/hrm_bdy_firsthero/hero_spiderman.actor',
    'characters/hero/hma_master/spiderman_base.animset',
    'characters/hero/hma_master/spiderman_traversal.animset',
]
archives = Archives()
manifest_path = ROOT / 'assets/source_manifest.json'
records = {r['path']: r for r in json.loads(manifest_path.read_text())}
for name in names:
    records[name] = archives.extract(name)
    raw = (ROOT / 'assets/source' / name).read_bytes()
    data = raw[raw.find(b'1TAD'):]
    print(name, [(hex(k), len(v)) for k, v in sections(data).items()])
    try:
        result = decode_file(ROOT / 'assets/source' / name)
        target = ROOT / 'research' / (Path(name).stem + '_' + Path(name).suffix[1:] + '.json')
        target.write_text(json.dumps(result, indent=2))
        print('Decoded', target.name)
    except (KeyError, ValueError, AssertionError) as exc:
        print('Config unavailable:', repr(exc))
manifest_path.write_text(json.dumps(list(records.values()), indent=2))
