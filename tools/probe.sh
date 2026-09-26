#!/bin/sh
# Is the port's way -- cut a stretch out of the whole circle's ring -- right
# when the arc's ends sit on quarter turns?  One axis-aligned quarter came
# out a clean subset.  Ask it of every radius and every quadrant, and of the
# eighth-turn ends for contrast.
cd "$(dirname "$0")/.."
PATH="$PATH:/c/prog/tools/w64devkit/bin"
mkdir -p tmp
gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32 || exit 1
python - <<'PY'
import io, math
with io.open('tmp/q.txt', 'w', encoding='ascii') as f:
    for rp in (7, 14, 19, 24, 40, 61):
        f.write("W%d %d 3 0 0 0 0\n" % (rp, rp))
        for k in range(8):
            a = math.pi / 4 * k
            b = a + math.pi / 2
            x1, y1 = int(rp * math.cos(a)), -int(rp * math.sin(a))
            x2, y2 = int(rp * math.cos(b)), -int(rp * math.sin(b))
            f.write("A%d_%d %d 1 %d %d %d %d\n" % (rp, k, rp, x1, y1, x2, y2))
PY
tmp/gdiarc.exe < tmp/q.txt > tmp/q.out 2>/dev/null
python - <<'PY'
import sys
sys.path.insert(0, 'tools')
import bezcut
got = bezcut.read('tmp/q.out')
print("%5s  %-26s %s" % ("rp", "ends on a quarter turn", "on an eighth"))
for rp in (7, 14, 19, 24, 40, 61):
    w = set(got["W%d" % rp])
    quarter, eighth = [], []
    for k in range(8):
        a = set(got.get("A%d_%d" % (rp, k), []))
        out = len(a - w)
        (quarter if k % 2 == 0 else eighth).append("%d/%d" % (out, len(a)))
    print("%5d  %-26s %s" % (rp, " ".join(quarter), " ".join(eighth)))
print("")
print("each cell is 'pixels the whole ring does not have' / 'pixels in the arc'")
PY
