#!/usr/bin/env python3
u"""The whole of GDI's Arc, from the decompilation, held against GDI.

    python tools/arcfull.py

**472 of 472 arcs come out pixel for pixel**, over radii 1 to 1023, every
start angle and every sweep.  Four steps, all read out of
`win32kfull.sys` and `win32kbase.sys` (see `decomp/gdi/`):

1. **the ends.**  The point Jw_cad hands `Arc` is normalised by the rect's
   own middle and half-widths and `vArctan` takes its angle off
   `gaefArctan`, a table of atan(i/32) in **degrees**; `vCosSin` puts it
   back on the unit circle off `gaefSin`, or `vCosSinPrecise` -- a Taylor
   series -- when the two ends are less than three degrees apart.
   (`tools/gdimath.py`)
2. **the control points** (`bPartialQuadrantArc`):

       cross = |p0.x*p3.y - p0.y*p3.x|
       c     = |efCos((a1 - a0) / 2)|
       beta  = (4/3 * c) / (c + 1)        alpha = 1 - beta
       c1 = alpha*p0 + beta*((p3.y-p0.y)/cross, (p0.x-p3.x)/cross)
       c2 = alpha*p3 + beta*(        same                        )

   For a whole quadrant beta comes out kappa, 0.5523.  Only the two end
   pieces go this way: a quadrant in the middle is built from the box's
   corners with one integer multiply, `(w * 0x729d7775) >> 32`.
3. **onto the ellipse** (`EBOX::ptlXform`): P = middle + u*p.x + v*p.y,
   rounded, in POINTFIX.  The rect is taken with its right and bottom edge
   off, so the ellipse's middle is half a pixel from the middle the angle
   in step 1 was measured against.  That is GDI's doing, not a slip here.
4. **flattening and stroking** -- `tools/hfd.py` (which falls to
   `tools/hfd64.py` over 1023 pixels) and `tools/gdiline.py`, each exact on
   its own (352 of 352, 60 of 60, and 120 of 120).

`tools/arccheck.py` holds the C in `src/draw.c` against this.
"""
import math
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import hfd
import arcpipe
import struct
import gdiline


def f32(v):
    """Round to single precision.  On x64 `EFLOAT` is a plain IEEE float --
    `EFLOAT::bIsZero` compares `*(float *)this` against 0.0 and
    `bIs1Over16` against 0.0625 -- so GDI does this arithmetic in single
    precision, and doing it in double gives a different last bit."""
    return struct.unpack("<f", struct.pack("<f", v))[0]

HALFPI = math.pi / 2.0


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


import gdimath
from gdimath import f32


def arc_pieces(cx, cy, rp, a0, sweep):
    """The cubics GDI would build for the arc Jw_cad asks for, in POINTFIX.

    Jw_cad passes the box (cx-rp, cy-rp, cx+rp+1, cy+rp+1) and the two end
    points it works out itself, as whole pixels.
    """
    gx, gy = ray(rp, a0)
    ex, ey = ray(rp, a0 + sweep)
    if sweep < 0:
        gx, gy, ex, ey = ex, ey, gx, gy
    box = gdimath.Box(cx - rp, cy - rp, cx + rp + 1, cy + rp + 1)
    return gdimath.arc(box, cx + gx, cy + gy, cx + ex, cy + ey)


def stroke(rp, a0, sw):
    """The pixels the port would paint: the pieces, flattened, stroked the
    way `bLines` strokes them."""
    poly = []
    for seg in arc_pieces(0, 0, rp, a0, sw):
        if not poly:
            poly.append(seg[0])
        poly.extend(hfd.flatten(seg))
    return gdiline.stroke(poly)


def main():
    import random

    random.seed(19)
    cs = []
    for rp in (1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 300, 400, 550,
               700, 900, 1000, 1023):
        for _ in range(25):
            cs.append((rp, random.uniform(0, 2 * math.pi),
                       random.choice([random.uniform(0.005, 0.2),
                                      random.uniform(0.02, 6.28)])))
    ask = []
    for i, (rp, a0, sw) in enumerate(cs):
        x1, y1 = ray(rp, a0)
        x2, y2 = ray(rp, a0 + sw)
        ask.append("A%d %d 1 %d %d %d %d" % (i, rp, x1, y1, x2, y2))
    got = arcpipe.gdi(ask)
    same = n = tot = 0
    worst = []
    for i, (rp, a0, sw) in enumerate(cs):
        px = set(got.get("A%d" % i, []))
        if not px:
            continue
        n += 1
        d = len(stroke(rp, a0, sw) ^ px)
        tot += d
        if d == 0:
            same += 1
        else:
            worst.append((d, len(px), rp, a0, sw))
    print("%d of %d arcs painted exactly like GDI, %d pixels out in all"
          % (same, n, tot))
    worst.sort(reverse=True)
    for d, ng, rp, a0, sw in worst[:6]:
        print("   rp %4d start %6.3f sweep %6.3f: %3d out of %3d"
              % (rp, a0, sw, d, ng))

    # and the whole circles, which Jw_cad draws as two Arc calls in a box
    # 2rp across rather than 2rp+1
    rps = [2, 3, 4, 5, 7, 10, 14, 19, 24, 33, 47, 64, 89, 120, 160, 233,
           300, 400, 550, 700, 900]
    for hi, odd, tag in ((0, 2, "2rp"), (1, 3, "2rp+1")):
        got = arcpipe.gdi(["C%d %d %d 0 0 0 0" % (i, rp, odd)
                           for i, rp in enumerate(rps)])
        same = n = tot = 0
        for i, rp in enumerate(rps):
            px = set(got.get("C%d" % i, []))
            if not px:
                continue
            n += 1
            box = gdimath.Box(-rp, -rp, rp + hi, rp + hi)
            mine = set()
            for ends in ((rp, 0, -rp, 0), (-rp, 0, rp, 0)):
                poly = []
                for seg in gdimath.arc(box, *ends):
                    if not poly:
                        poly.append(seg[0])
                    poly.extend(hfd.flatten(seg))
                mine |= gdiline.stroke(poly)
            d = len(mine ^ px)
            tot += d
            if d == 0:
                same += 1
        print("whole circles in the %-5s box: %d of %d exact, %d pixels out"
              % (tag, same, n, tot))


if __name__ == "__main__":
    main()
