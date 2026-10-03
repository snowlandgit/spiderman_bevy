"""Original game props (tools/prepare_props.py) as static glTF, and where the sandbox places them.

Each prop becomes assets/world/prop_<name>.glb, its origin at the middle of its footprint and its base (as
convert_world.py does for the cars). They enter the world only through assets/world/layout.json's `objects` list, the
way any imported glTF does: none has an authored collision box. They collide by their own meshes and their ledges are
zip-to-point targets (src/world.rs).

The two air conditioners on each tower's roof are part of the tower models, as visuals. The same unit is placed over
each one as a hidden object (`"hidden": true`), so they collide and can be perched on too without drawing twice.
"""
import json
import math
import numpy as np
from convert_world import read_mesh, Glb, transformed, out, LAYOUT
from extract_assets import ROOT

props = json.loads((ROOT / 'tools/world/props.json').read_text())
AC_SOURCE = 'environment/props/manmade/global/pp_skyscraper_ac_unit/pp_skyscraper_ac_unit.model'
USE = ['water_tank', 'rooftop_access', 'lamp_post', 'newsstand', 'scaffold_tower', 'hvac_industrial', 'helipad',
       'perch_antenna', 'intel_tower', 'billboard_stand', 'pp_skyscraper_ac_unit']

report = {}
for name in USE:
    parts = read_mesh(name)
    v = np.concatenate([p[1] for p in parts])
    origin = np.array([(v[:, 0].min() + v[:, 0].max()) / 2, v[:, 1].min(), (v[:, 2].min() + v[:, 2].max()) / 2])
    alias = 'prop_' + ('ac_unit' if name == 'pp_skyscraper_ac_unit' else name)
    r = Glb().write(alias, transformed(parts, translation=-origin))
    r['source'] = AC_SOURCE if name == 'pp_skyscraper_ac_unit' else props[name]
    report[alias] = r

objects = []


def place(prop, x, y, z, yaw=0., name=None, hidden=False):
    o = {'asset': f'world/prop_{prop}.glb', 'name': name or prop.replace('_', ' '), 'position': [round(x, 3), round(y, 3), round(z, 3)],
         'yaw': round(yaw, 4), 'scale': 1}
    if hidden:
        o['hidden'] = True
    objects.append(o)


# the street: lamp posts down both sidewalks, a newsstand and a billboard stand
for side in (-1, 1):
    for z in range(20, -280, -30):
        place('lamp_post', side * 11.5, 0, z)
place('newsstand', 12.8, 0, -2, -math.pi / 2)
place('billboard_stand', -12.6, 0, 12, math.pi / 2)

# the open space right of the start: a helipad, a stepped scaffold tower with an antenna on top, an HVAC plant
place('helipad', 32, 0, -4)
storey = report['prop_scaffold_tower']['size'][1]
for level in range(4):
    place('scaffold_tower', 22, level * storey, -17, name=f'scaffold tower, level {level + 1}')
for level in range(2):
    place('scaffold_tower', 22, level * storey, -12.9, name=f'scaffold step, level {level + 1}')
place('intel_tower', 22, 4 * storey, -17)
place('hvac_industrial', 40, 0, -20)

# the open space left of the start: a rooftop shed, a water tank and the perch antenna on the ground
place('rooftop_access', -22, 0, 2)
place('water_tank', -30, 0, 10)
place('perch_antenna', -36, 0, -2)

# the towers' roofs: props in the two quarters the air conditioners leave free, and the air conditioners themselves
rooftop = [
    ('water_tank', 'rooftop_access'),
    ('hvac_industrial', 'water_tank'),
    ('intel_tower', 'perch_antenna'),
    ('rooftop_access', 'water_tank'),
    ('hvac_industrial', 'perch_antenna'),
    ('water_tank', 'intel_tower'),
    ('rooftop_access', 'water_tank'),
]
for i, ((x, z, width, depth, height, style), (first, second)) in enumerate(zip(LAYOUT, rooftop)):
    place(first, x - width / 4, height, z + depth / 4, math.pi / 2 if first == 'hvac_industrial' else 0., name=f'tower {i + 1} roof {first.replace("_", " ")}')
    place(second, x + width / 4, height, z - depth / 4, name=f'tower {i + 1} roof {second.replace("_", " ")}')
    for ax, az in [(-width / 4, -depth / 4), (width / 4, depth / 4)]:
        place('ac_unit', x + ax, height, z + az, name=f'tower {i + 1} roof air conditioner (the model\'s own)', hidden=True)

layout_path = out / 'layout.json'
layout = json.loads(layout_path.read_text())
layout['objects'] = objects
layout_path.write_text(json.dumps(layout, indent=2))
(ROOT / 'research/world_props.json').write_text(json.dumps({'units': 'meters', 'props': report, 'objects': len(objects)}, indent=2))
print('PROPS', len(report), 'models', len(objects), 'placed', flush=True)
