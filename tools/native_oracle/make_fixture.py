"""make_fixture.py <oracle out.json> <scenario name> <fixture.json>: the game's path from an oracle run (its JSON
output), as crates/sm_traversal/tests/fixtures keeps it: per frame after the move and turn, the state, his position
(4 decimals) and his flat forward (x, z; 5 decimals)."""
import json
import sys

run = json.load(open(sys.argv[1]))
name = sys.argv[2]
out = {
    "source": "tools/native_oracle: Spider-Man.exe 4.0630's own traversal states on scenarios/%s.txt; per frame after the move and turn" % name,
    "dt": round(run["dt"], 7),
    "mode": [f["mode"] for f in run["frames"]],
    "pos": [[round(c, 4) for c in f["pos"]] for f in run["frames"]],
    "fwd": [[round(f["fwd"][0], 5), round(f["fwd"][2], 5)] for f in run["frames"]],
}
open(sys.argv[3], "w").write(json.dumps(out, separators=(",", ":")))
