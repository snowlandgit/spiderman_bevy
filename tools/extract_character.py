import json,re
from extract_assets import Archives,ROOT
archives=Archives()
traversal='characters/hero/hero_spiderman/animations/traversal/'
names=['web_swing_2rh_000_twist_0_spiderman','web_swing_2rh_045_twist_0_spiderman','web_swing_2rh_000_bend_l_spiderman','web_swing_2rh_000_bend_r_spiderman','web_swing_rh_a_spiderman','web_swing_intro_fromairaggro_fwd_rh_spiderman','web_swing_intro_fromairaggro_fwd_spiderman','web_swing_jump_high_spiderman','web_swing_jump_mid_spiderman','web_swing_jump_mid2_spiderman','web_swing_jump_mid3_spiderman','web_swing_release_low_spiderman','web_swing_release_mid_spiderman','web_swing_release_high_spiderman','fall_cycle_spiderman','fastfall_spiderman','skydive_spiderman','fall_toland_spiderman']
selection=[traversal+n+'.animclip' for n in names]
locomotion=archives.available(r'^characters/hero/hero_spiderman/animations/.*(idle|sprint|jog|wallrun|jump).*animclip$')
(ROOT/'tools/locomotion_names.txt').write_text('\n'.join(locomotion))
manifest=json.loads((ROOT/'assets/source_manifest.json').read_text())
for name in selection:
    if name in archives.by_name and archives.by_name[name] in archives.indices:
        record=archives.extract(name); manifest.append(record); print(record['bytes'],name,flush=True)
model=(ROOT/'assets/source/characters/hero/hero_spiderman/hero_spiderman_body.model').read_bytes()
materials=sorted(set(x.decode().replace('\\','/').lower() for x in re.findall(rb'[\x20-\x7e]+\.material',model)))
for name in materials:
    if name in archives.by_name and archives.by_name[name] in archives.indices:
        record=archives.extract(name); manifest.append(record); print(record['bytes'],name,flush=True)
(ROOT/'assets/source_manifest.json').write_text(json.dumps(manifest,indent=2))
