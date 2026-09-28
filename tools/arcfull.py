#!/usr/bin/env python3
u"""The whole of GDI's Arc, from the decompilation, held against GDI.

    python tools/arcfull.py

Four steps, all read out of `win32kfull.sys` and `win32kbase.sys`:

1. **the ends**, as points on the unit circle
2. **the control points** (`bPartialQuadrantArc`):

       cross = p0.x*p3.y - p0.y*p3.x
       c     = |cos((a1 - a0) / 2)|
       beta  = (4/3 * c) / (c + 1)        alpha = 1 - beta
       c1 = (alpha*p0.x + beta*(p3.y-p0.y)/cross,
             alpha*p0.y + beta*(p0.x-p3.x)/cross)
       c2 = (alpha*p3.x + beta*(p3.y-p0.y)/cross,
             alpha*p3.y + beta*(p0.x-p3.x)/cross)

   For a quadrant (p0=(1,0), p3=(0,1)) beta comes out 0.5523 -- kappa --
   and the control points are the textbook ones.

3. **the box** (`EBOX::ptlXform`): the unit circle is carried onto the
   ellipse by `P = middle + u*p.x + v*p.y`, rounded, where u and v are the
   half-axes.  The constructor builds them as u = (A-B)/2, v = (B-C)/2 and
   middle = C + u + v from the rect's four corners in POINTFIX, which for
   Arc's rect (cx-rp, cy-rp, cx+rp+1, cy+rp+1) gives middle (cx+.5, cy+.5)
   and radius rp+.5.

4. **flattening and stroking** -- `tools/hfd.py` and `tools/fixline.py`,
   already exact on their own (352 of 352, and 10 of 10).

What is *not* read out is how GDI turns a given end point into its place on
the unit circle: that goes through `vArctan`, which walks a table.  Here it
is taken as the plain normalised direction, which is what it should come to
-- and this run says whether it does.
"""
import math
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import hfd
import arcpipe
import struct


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


def main():
    cs = []
    for rp in (14, 19, 24, 40, 61):
        for k in range(8):
            cs.append((rp, 0.06 + k * 0.4, HALFPI))
            cs.append((rp, 0.06 + k * 0.4, 0.9))
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
        mine = arcpipe.pixels(arc_pieces(0, 0, rp, a0, sw))
        d = len(mine ^ px)
        tot += d
        if d == 0:
            same += 1
        else:
            worst.append((d, len(px), rp, a0, sw))
    print("%d of %d arcs painted exactly like GDI, %d pixels out in all"
          % (same, n, tot))
    worst.sort(reverse=True)
    for d, ng, rp, a0, sw in worst[:6]:
        print("   rp %3d start %6.3f sweep %5.3f: %3d out of %3d"
              % (rp, a0, sw, d, ng))


if __name__ == "__main__":
    main()
