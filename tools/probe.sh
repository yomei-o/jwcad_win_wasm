#!/bin/sh
# GetPath's polyline is about a point a pixel but only half its points are
# arc pixels -- GDI keeps the curve in fixed point and GetPath rounds it.
# The curve itself is something the port can compute, so try the plainest
# thing: sample the Beziers finely and take the pixel each sample falls in.
cd "$(dirname "$0")/.."
PATH="$PATH:/c/prog/tools/w64devkit/bin"
mkdir -p tmp
gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32 || exit 1
printf 'P 61 1 61 0 -52 -31\n' > tmp/p.txt
tmp/gdiarc.exe < tmp/p.txt > tmp/p.out
python - <<'PY'
import sys
sys.path.insert(0, 'tools')
import bezpix
g = bezpix.read_sets('tmp/p.out')['P']
segs = [((61, 0), (61, -34), (34, -61), (0, -61)),
        ((0, -61), (-21, -61), (-41, -50), (-52, -31))]
def at(seg, t):
    (x0, y0), (x1, y1), (x2, y2), (x3, y3) = seg
    u = 1.0 - t
    x = u*u*u*x0 + 3*u*u*t*x1 + 3*u*t*t*x2 + t*t*t*x3
    y = u*u*u*y0 + 3*u*u*t*y1 + 3*u*t*t*y2 + t*t*t*y3
    return x, y
for n in (200, 500, 2000):
    out = set()
    for seg in segs:
        for i in range(n + 1):
            x, y = at(seg, float(i) / n)
            out.add((bezpix.rnd(x), bezpix.rnd(y)))
    print("%5d samples a piece: %4d pixels (GDI %d), differ %3d"
          % (n, len(out), len(g), len(g ^ out)))
# and the same with the pixel taken by flooring rather than rounding
for n in (500,):
    import math
    for how, f in (("floor", math.floor), ("round", lambda v: math.floor(v + 0.5))):
        out = set()
        for seg in segs:
            for i in range(n + 1):
                x, y = at(seg, float(i) / n)
                out.add((int(f(x)), int(f(y))))
        print("%-6s: %4d pixels, differ %3d" % (how, len(out), len(g ^ out)))
PY
