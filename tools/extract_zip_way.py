"""extract_zip_way.py: the zip's way to its target from the character's web_zip_attach_fwd_spiderman clip.

The game keeps the way a zip still has to go in the "sync" joint (joint 7, at the top of the skeleton; ArkWeb
recon/NATIVE.md): model space, x left, y up, z forward, shrinking to nothing on arrival. Its mover warps that way onto
the real target. This reads the joint's translation keys from assets/character/spiderman.glb (the sandbox's own
character file, already converted) and writes assets/tuning/web_zip_attach_way.json for src/point_zip.rs.
"""
import json
import os
import struct

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
GLB = os.path.join(ROOT, "assets", "character", "spiderman.glb")
OUT = os.path.join(ROOT, "assets", "tuning", "web_zip_attach_way.json")
CLIP = "web_zip_attach_fwd_spiderman"

data = open(GLB, "rb").read()
json_len = struct.unpack_from("<I", data, 12)[0]
gltf = json.loads(data[20:20 + json_len])
bin_at = 20 + json_len + 8


def accessor(i):
    a = gltf["accessors"][i]
    view = gltf["bufferViews"][a["bufferView"]]
    at = bin_at + view.get("byteOffset", 0) + a.get("byteOffset", 0)
    n = {"SCALAR": 1, "VEC3": 3, "VEC4": 4}[a["type"]]
    return [list(struct.unpack_from("<%df" % n, data, at + k * 4 * n)) for k in range(a["count"])]


anim = next(a for a in gltf["animations"] if a["name"] == CLIP)
for ch in anim["channels"]:
    node = gltf["nodes"][ch["target"]["node"]]
    if node.get("name") == "sync" and ch["target"]["path"] == "translation":
        sampler = anim["samplers"][ch["sampler"]]
        times = [t[0] for t in accessor(sampler["input"])]
        way = accessor(sampler["output"])
        break
else:
    raise SystemExit("no sync translation in " + CLIP)

out = {
    "source": "assets/character/spiderman.glb, %s: the sync joint's translation (the way left to the zip's target; x left, y up, z forward, m)" % CLIP,
    "clip": CLIP,
    "times": [round(t, 6) for t in times],
    "way": [[round(c, 5) for c in v] for v in way],
}
open(OUT, "w").write(json.dumps(out, indent=1))
print("%d keys over %.4f s -> %s" % (len(times), times[-1], OUT))
