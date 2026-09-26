#!/bin/sh
# Does GDI subdivide in whole numbers?  Its flattened points are not the
# curve's own B(k/8) -- at radius 61 the first is (60,-13) where the maths
# gives (59.773,-12.383).  Halving with the midpoints rounded at every
# level would drift exactly like that.
cd "$(dirname "$0")/.."
PATH="$PATH:/c/prog/tools/w64devkit/bin"
mkdir -p tmp
gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32 || exit 1
printf 'C 61 7 61 0 -52 -31\nF 61 9 61 0 -52 -31\n' > tmp/cut.txt
tmp/gdiarc.exe < tmp/cut.txt > tmp/cut.out 2>/dev/null
python - <<'PY'
import io, math, sys
sys.path.insert(0, 'tools')
import bezcut
got = bezcut.read('tmp/cut.out')
cps, fl = got['C'], got['F']
segs = []
for i in range(1, len(cps) - 2, 3):
    segs.append((cps[i-1], cps[i], cps[i+1], cps[i+2]))

def far(p):
    (x0, y0), (x1, y1), (x2, y2), (x3, y3) = p
    ax, ay = x3 - x0, y3 - y0
    n = math.hypot(ax, ay)
    if n < 1e-12:
        return max(math.hypot(x1-x0, y1-y0), math.hypot(x2-x0, y2-y0))
    d1 = abs(ax * (y0 - y1) - ay * (x0 - x1)) / n
    d2 = abs(ax * (y0 - y2) - ay * (x0 - x2)) / n
    return max(d1, d2)

def half(v, how):
    return how(v / 2.0)

def flat_int(p, out, tol, how, depth=0):
    if depth < 20 and far(p) > tol:
        (x0, y0), (x1, y1), (x2, y2), (x3, y3) = p
        ax, ay = half(x0 + x1, how), half(y0 + y1, how)
        bx, by = half(x1 + x2, how), half(y1 + y2, how)
        cx, cy = half(x2 + x3, how), half(y2 + y3, how)
        dx, dy = half(ax + bx, how), half(ay + by, how)
        ex, ey = half(bx + cx, how), half(by + cy, how)
        mx, my = half(dx + ex, how), half(dy + ey, how)
        flat_int(((x0, y0), (ax, ay), (dx, dy), (mx, my)), out, tol, how,
                 depth + 1)
        flat_int(((mx, my), (ex, ey), (cx, cy), (x3, y3)), out, tol, how,
                 depth + 1)
        return
    out.append((p[3][0], p[3][1]))

import math as m
for name, how in (("floor", m.floor), ("round", lambda v: m.floor(v + 0.5)),
                  ("trunc", lambda v: float(int(v))), ("ceil", m.ceil)):
    for tol in (0.70, 1.0):
        pts = []
        for seg in segs:
            if not pts:
                pts.append((float(seg[0][0]), float(seg[0][1])))
            flat_int(tuple((float(q[0]), float(q[1])) for q in seg), pts,
                     tol, how)
        same = sum(1 for i in range(min(len(pts), len(fl)))
                   if (int(pts[i][0]), int(pts[i][1])) == fl[i])
        print("%-6s tol %.2f: %2d points (GDI %d), %2d match in place"
              % (name, tol, len(pts), len(fl), same))
        if name == "floor" and tol == 0.70:
            print("      ", [(int(a), int(b)) for a, b in pts])
PY
