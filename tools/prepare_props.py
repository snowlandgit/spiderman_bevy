"""Extract original game props for the sandbox's generic objects, without modifying archives.

The props are placed in the world only through assets/world/layout.json's `objects` list: they collide by their own
meshes and their ledges are zip-to-point targets (src/world.rs), the way any imported glTF would. This writes each prop
as tools/world/<alias>.ascii (with _materials.txt, look 0, LOD 0) through ALERT, decodes its textures into
assets/world/textures as prepare_world.py does, merges its materials and textures into tools/world/materials.json and
textures.json, and lists the props in tools/world/props.json. tools/convert_props.py turns them into glTF.
"""
import sys, re, json, io, struct, hashlib
import numpy as np
from PIL import Image
from extract_assets import ROOT, Archives, sections

sys.path.insert(0, str(ROOT / 'tools/ALERT-main'))
import model_to_ascii, dat1lib

PROPS = {
    'water_tank': 'environment/global/prop/gbl_prop_water_tank_plant_01/ch_gbl_prop_water_tank_plant_01.model',
    'rooftop_access': 'environment/global/prop/gbl_prop_rooftop_access_01/gm_gbl_prop_rooftop_access_01.model',
    'lamp_post': 'environment/global/ambient/gbl_amb_lamp_post_central_park_01/cg_gbl_amb_lamp_post_central_park_01.model',
    'newsstand': 'environment/master_kits/np_newsstand/np_newsstand/np_newsstand.model',
    'scaffold_tower': 'environment/master_kits/construction_tower/rv_construction_tower_scaffold_4x4x4/rv_construction_tower_scaffold_4x4x4.model',
    'hvac_industrial': 'environment/outsourcing/dhruva/manmade/os_hvackit/os_hvackit_industrial_01/os_hvackit_industrial_01.model',
    'helipad': 'environment/outsourcing/dhruva/manmade/os_hvackit/os_helipad_platform/os_helipad_platform.model',
    'perch_antenna': 'environment/building_kits/oscorp_building/rv_oscorp_building_roof_perch_antenna_01/rv_oscorp_building_roof_perch_antenna_01.model',
    'intel_tower': 'environment/global/prop/gbl_prop_intel_tower_large_01/gm_gbl_prop_intel_tower_large_01.model',
    'billboard_stand': 'environment/master_kits/jp_billboards/jp_billboardstand_2sides_4m/jp_billboardstand_2sides_4m.model',
}
if len(sys.argv) > 1:
    PROPS = {k: v for k, v in PROPS.items() if k in sys.argv[1:]}

out = ROOT / 'tools/world'
a = Archives()
manifest = {r['path']: r for r in json.loads((ROOT / 'assets/source_manifest.json').read_text())}


def extract(path):
    if path not in a.by_name or a.by_name[path] not in a.indices:
        return None
    manifest[path] = a.extract(path)
    return ROOT / 'assets/source' / path


def texture_png(path, p):
    """A .texture as an RGBA image (the decoding prepare_world.py uses), or None"""
    b = p.read_bytes()
    off = b.find(b'1TAD')
    if off < 0:
        return None
    d = b[off:]
    size = struct.unpack_from('<I', d, 8)[0]
    h = sections(d).get(0x4EDE3593)
    if h is None:
        return None
    sd_len, hd_len, hd_w, hd_h, w, height = struct.unpack_from('<IIHHHH', h)
    fmt = struct.unpack_from('<H', h, 20)[0]
    mips = h[30]
    dds_fmt = {72: 71, 75: 74, 78: 77, 91: 87, 93: 88, 99: 98}.get(fmt, fmt)
    header = b'DDS ' + struct.pack('<7I', 124, 0x000a1007, height, w, w * 4, 0, mips) + bytes(44)
    header += struct.pack('<II4sIIIII', 32, 4, b'DX10', 0, 0, 0, 0, 0) + struct.pack('<5I', 0x401008, 0, 0, 0, 0) + struct.pack('<5I', dds_fmt, 3, 0, 1, 0)
    if fmt in (34, 35, 16, 61):
        channels = 1 if fmt == 61 else 2
        dtype = {34: '<f2', 35: '<u2', 16: '<f4', 61: 'u1'}[fmt]
        raw = np.frombuffer(d[size:size + w * height * channels * np.dtype(dtype).itemsize], dtype=dtype).reshape(height, w, channels).astype(np.float32)
        if fmt == 35:
            raw /= 65535
        if fmt == 61:
            raw /= 255
        pixels = np.zeros((height, w, 4), dtype=np.uint8)
        pixels[:, :, :channels] = np.rint(np.clip(raw, 0, 1) * 255).astype(np.uint8)
        pixels[:, :, 3] = 255
        if channels == 1:
            pixels[:, :, 1:3] = pixels[:, :, :1]
        im = Image.fromarray(pixels)
    else:
        im = Image.open(io.BytesIO(header + d[size:])).convert('RGBA')
    if p.stem.lower().endswith('_n'):
        pixels = np.array(im)
        x = pixels[:, :, 0].astype(np.float32) / 127.5 - 1
        y = pixels[:, :, 1].astype(np.float32) / 127.5 - 1
        pixels[:, :, 1] = 255 - pixels[:, :, 1]
        pixels[:, :, 2] = np.rint((np.sqrt(np.maximum(0, 1 - x * x - y * y)) + 1) * 127.5).astype(np.uint8)
        pixels[:, :, 3] = 255
        im = Image.fromarray(pixels)
    return im


props_file = out / 'props.json'
props = json.loads(props_file.read_text()) if props_file.exists() else {}
materials = set()
for alias, path in PROPS.items():
    model_path = extract(path)
    if model_path is None:
        print('MISSING', alias, path, flush=True)
        continue
    try:
        with model_path.open('rb') as f:
            model = dat1lib.read(f)
        with (out / (alias + '.ascii')).open('w') as f:
            model_to_ascii.AsciiWriter().write_model(f, model, [0], 0, materials_txt=str(out / (alias + '_materials.txt')))
    except Exception as e:
        print('MODEL_ERROR', alias, repr(e), flush=True)
        continue
    props[alias] = path
    for line in (out / (alias + '_materials.txt')).read_text().splitlines():
        if '\t' in line and '.material' in line:
            materials.add(line.split('\t', 1)[1].replace('\\', '/').lower())
maps = json.loads((out / 'materials.json').read_text())
textures = json.loads((out / 'textures.json').read_text())
texture_dir = ROOT / 'assets/world/textures'
for path in sorted(materials):
    if path in maps:
        continue
    p = extract(path)
    refs = [] if p is None else [x.decode().replace('\\', '/').lower() for x in re.findall(rb'[\x20-\x7e]+\.texture', p.read_bytes())]
    maps[path] = refs
    for tpath in refs:
        if tpath in textures:
            continue
        tp = extract(tpath)
        if tp is None:
            continue
        try:
            im = texture_png(tpath, tp)
        except Exception as e:
            print('TEXTURE_ERROR', tpath, repr(e), flush=True)
            continue
        if im is None:
            continue
        filename = hashlib.sha256(tpath.encode()).hexdigest()[:12] + '_' + tp.stem + '.png'
        im.save(texture_dir / filename)
        textures[tpath] = filename
(out / 'materials.json').write_text(json.dumps(maps, indent=2))
(out / 'textures.json').write_text(json.dumps(textures, indent=2))
props_file.write_text(json.dumps(props, indent=2))
(ROOT / 'assets/source_manifest.json').write_text(json.dumps(list(manifest.values()), indent=2))
print('PROPS', len(props), 'props', len(materials), 'materials', flush=True)
