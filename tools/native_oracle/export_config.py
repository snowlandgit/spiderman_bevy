"""export_config.py: the traversal configs the Rust port (crates/sm_traversal) reads, as named JSON.

Sources (all from this user's own game, gathered by ArkWeb's research tools):
  - ArkWeb/logs/swingcfg/*.bin: config objects dumped from the running game's memory (their in-memory values include
    the defaults the asset files leave out). Header: u64 address, u32 size, then the object.
  - H:/arkre/harness/arrays.bin: HeroSwingConfig's dynamic arrays (momentum stages, decay data, rate curves, jump zones),
    rebuilt from the decoded asset with the exe's field defaults (ArkWeb make_arrays.py).
  - H:/arkre/harness/traversal.bin: HeroTraversalConfig with its arrays resolved (ArkWeb cfgfix.py).
  - ArkWeb/recon/sm_reflection.json: field names, offsets and types from the exe's reflection tables.

Writes assets/tuning/native/<name>.json: struct fields by name (floats, bools, ints), nested structs as objects, arrays
as lists. Strings, asset references and object ids are left out.
"""
import json
import os
import struct
import sys

ARKWEB = r"H:\SteamLibrary\steamapps\common\Saints Row the Third\ArkWeb"
REFL = json.load(open(os.path.join(ARKWEB, "recon", "sm_reflection.json")))
OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "assets", "tuning", "native")

SCALARS = {
	0x08: ("<f", 4, float),
	0x0F: ("<B", 1, bool),
	0x02: ("<I", 4, int),
	0x06: ("<i", 4, int),
	0x00: ("<B", 1, int),
	0x04: ("<B", 1, int),
	0x11: ("<I", 4, int),  # enum
}


def size_of(f):
	if f["type"] in SCALARS:
		return SCALARS[f["type"]][1]
	if f["type"] == 0x0D:
		return REFL[f["type_name"]]["size"]
	return None


def read_struct(name, blob, base, arrays, path="", strings=None):
	"""strings: {absolute offset: text} for this blob's string fields"""
	out = {}
	strings = strings or {}
	for f in REFL[name]["fields"]:
		off = base + f["offset"]
		key = f["name"]
		if f["type"] == 0x0A and f["container"] == 0:
			if off in strings:
				out[key] = strings[off]
			continue
		if f["container"] == 2:  # dynamic array {ptr, count}
			arr = arrays.get(path + key)
			if arr is None:
				continue
			esize, items = arr[0], arr[1]
			item_strings = arr[2] if len(arr) > 2 else [{} for _ in items]
			if f["type"] == 0x0D:
				out[key] = [read_struct(f["type_name"], it, 0, {}, "", st) for it, st in zip(items, item_strings)]
			elif f["type"] in SCALARS:
				fmt = SCALARS[f["type"]][0]
				out[key] = [SCALARS[f["type"]][2](struct.unpack_from(fmt, it, 0)[0]) for it in items]
			continue
		n = f["count"] if f["container"] == 1 else 1
		if f["type"] == 0x0D:
			if f["container"] not in (0, 1):
				continue
			sub = [read_struct(f["type_name"], blob, off + k * REFL[f["type_name"]]["size"], arrays, path + key + ".", strings) for k in range(n)]
			out[key] = sub[0] if f["container"] == 0 else sub
		elif f["type"] in SCALARS and f["container"] in (0, 1):
			fmt, sz, conv = SCALARS[f["type"]]
			vals = [conv(struct.unpack_from(fmt, blob, off + k * sz)[0]) for k in range(n)]
			out[key] = vals[0] if f["container"] == 0 else vals
	return out


def load_dump(name):
	b = open(os.path.join(ARKWEB, "logs", "swingcfg", name), "rb").read()
	_, size = struct.unpack_from("<QI", b, 0)
	return b[12:12 + size]


def swing_arrays():
	"""arrays.bin -> {path: (element size, [element bytes])} keyed by HeroSwingConfig field path"""
	b = open(r"H:\arkre\harness\arrays.bin", "rb").read()
	(count,) = struct.unpack_from("<I", b, 0)
	at = 4
	by_off = {}
	for _ in range(count):
		off, size, n = struct.unpack_from("<III", b, at)
		at += 12
		by_off[off] = (size, [b[at + k * size:at + (k + 1) * size] for k in range(n)])
		at += size * n
	mc = 0xae8
	return {
		"MomentumConfig.DecayDataAir": by_off[mc + 0x10],
		"MomentumConfig.DecayDataGround": by_off[mc + 0x20],
		"MomentumConfig.DecayDataSprint": by_off[mc + 0x30],
		"MomentumConfig.DecayDataStop": by_off[mc + 0x40],
		"MomentumConfig.MomentumStages": by_off[mc + 0x50],
		"MomentumConfig.SwingData.RateList": by_off[mc + 0xd8 + 0x08],
		"MomentumConfig.SwingReleaseData.RateScaleList": by_off[mc + 0x100 + 0x08],
		"JumpBankZones": by_off[0x1d8],
		"JumpRedirectZones": by_off[0x1e8],
	}


def cstr(raw):
	end = raw.find(bytes([0]))
	return (raw if end < 0 else raw[:end]).decode("ascii", "replace")


def traversal_fixed():
	"""traversal.bin (cfgfix.py): the root object and its arrays by offset"""
	b = open(r"H:\arkre\harness\traversal.bin", "rb").read()
	at = 4 + 8
	(size,) = struct.unpack_from("<I", b, at)
	at += 4
	root = b[at:at + size]
	at += size
	(nfix,) = struct.unpack_from("<I", b, at)
	at += 4
	arrays, strings = {}, {}
	for _ in range(nfix):
		off, kind = struct.unpack_from("<II", b, at)
		at += 8
		if kind == 1:
			(n,) = struct.unpack_from("<I", b, at)
			strings[off] = cstr(b[at + 4:at + 4 + n])
			at += 4 + n
			continue
		esize, count = struct.unpack_from("<II", b, at)
		at += 8
		elems = [b[at + k * esize:at + (k + 1) * esize] for k in range(count)]
		at += esize * count
		(nsub,) = struct.unpack_from("<I", b, at)
		at += 4
		# element string fields (cfgfix.py: offset into the elements, kind, then the text)
		subs = []
		for _ in range(nsub):
			so, sk, n = struct.unpack_from("<III", b, at)
			subs.append((so, cstr(b[at + 12:at + 12 + n])))
			at += 12 + n
		# element strings: offsets are into the concatenated elements
		per = [{} for _ in elems]
		for so, text in subs:
			if esize and so // esize < len(per):
				per[so // esize][so % esize] = text
		arrays[off] = (esize, elems, per)
	return root, arrays, strings


def array_paths(name, base, by_off, path="", out=None):
	"""maps absolute offsets of dynamic arrays to field paths"""
	out = {} if out is None else out
	for f in REFL[name]["fields"]:
		off = base + f["offset"]
		if f["container"] == 2 and off in by_off:
			out[path + f["name"]] = by_off[off]
		elif f["type"] == 0x0D and f["container"] == 0:
			array_paths(f["type_name"], off, by_off, path + f["name"] + ".", out)
	return out


def write(name, data):
	os.makedirs(OUT, exist_ok=True)
	p = os.path.join(OUT, name + ".json")
	json.dump(data, open(p, "w"), indent=1)
	print("wrote", os.path.normpath(p))


def main():
	write("hero_swing_config", read_struct("HeroSwingConfig", load_dump("HeroSwingConfig_1.bin"), 0, swing_arrays()))
	for idx, name in ((1, "swing_setup_standard"), (3, "swing_setup_ground"), (4, "swing_setup_open")):
		write(name, read_struct("SwingSetupConfig", load_dump("SwingSetupConfig_%d.bin" % idx), 0, {}))
	root, arrays, strings = traversal_fixed()
	write("hero_traversal_config", read_struct("HeroTraversalConfig", root, 0, array_paths("HeroTraversalConfig", 0, arrays), "", strings))
	write("hero_rope_config_swing", read_struct("HeroRopeConfig", load_dump("HeroRopeConfig_7.bin"), 0, {}))


if __name__ == "__main__":
	sys.exit(main())
