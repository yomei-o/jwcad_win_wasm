#!/bin/sh
# The last split: take GDI's **own** flattened polyline and stroke it with
# the port's line drawing.  If that matches GDI's pixels, the whole problem
# is making the polyline; if it does not, GDI strokes with more than the
# whole numbers GetPath hands back.
cd "$(dirname "$0")/.."
PATH="$PATH:/c/prog/tools/w64devkit/bin"
mkdir -p tmp
gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32 || exit 1
printf 'P 61 1 61 0 -52 -31\n' > tmp/p.txt
printf 'F 61 9 61 0 -52 -31\n' > tmp/f.txt
tmp/gdiarc.exe < tmp/p.txt > tmp/p.out
tmp/gdiarc.exe < tmp/f.txt > tmp/f.out
python - <<'PY'
import io, sys
sys.path.insert(0, 'tools')
import bezpix
g = bezpix.read_sets('tmp/p.out')['P']
pl = []
L = io.open('tmp/f.out', encoding='ascii', errors='replace').read().split('\n')
k = 0
while k < len(L):
    h = L[k].split(); k += 1
    if len(h) != 2:
        continue
    n = int(h[1])
    for _ in range(n):
        if k >= len(L):
            break
        q = L[k].split(); k += 1
        if len(q) == 2:
            pl.append((int(q[0]), int(q[1])))
print("GDI's polyline has %d points, its arc %d pixels" % (len(pl), len(g)))
out = set()
for i in range(len(pl) - 1):
    bezpix.bres(pl[i][0], pl[i][1], pl[i+1][0], pl[i+1][1], out, 0)
print("stroking it gives %d pixels, differ %d" % (len(out), len(g ^ out)))
out2 = set(pl)
print("just the points themselves: %d pixels, differ %d"
      % (len(out2), len(g ^ out2)))
PY
