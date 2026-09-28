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

HALFPI = math.pi / 2.0


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


ARCTAN_SIZE = 64


def varctan(x, y):
    """GDI's own arctan: fold into the first eighth, look the ratio up in a
    table and interpolate, and come back in **degrees**.

    (`vArctan` in decomp/gdi/arc_x64.c.  The table is `gaefArctan`; here it
    is synthesised, since what matters is its size and the interpolation.)
    """
    oct_ = 2 if x >= 0 else 3
    ax = x if x >= 0 else -x
    o = 0 if x >= 0 else 1
    ay = y
    if y < 0:
        o = oct_
        ay = -y
    hi, lo = ax, ay
    if ax < ay:
        o |= 4
        hi, lo = ay, ax
    if hi == 0.0:
        return 0.0
    t = (lo * ARCTAN_SIZE) / hi
    i = int(t)
    f = t - i
    import math as m
    a0 = m.degrees(m.atan(float(i) / ARCTAN_SIZE))
    a1 = m.degrees(m.atan(float(i + 1) / ARCTAN_SIZE))
    ang = a0 + (a1 - a0) * f
    if o == 1:
        return 180.0 - ang
    if o == 2:
        return 360.0 - ang
    if o == 3:
        return ang + 180.0
    if o == 4:
        return 90.0 - ang
    if o == 5:
        return ang + 90.0
    if o == 6:
        return ang + 270.0
    if o == 7:
        return 270.0 - ang
    return ang


def quad_bezier(p0, p3, a0, a1):
    """bPartialQuadrantArc, on the unit circle."""
    cross = p0[0] * p3[1] - p0[1] * p3[0]
    if abs(cross) < 1e-12:
        return [p0, p0, p3, p3]
    c = abs(math.cos((a1 - a0) * 0.5))
    beta = (4.0 / 3.0 * c) / (c + 1.0)
    alpha = 1.0 - beta
    tx = beta * ((p3[1] - p0[1]) / cross)
    ty = beta * ((p0[0] - p3[0]) / cross)
    c1 = (alpha * p0[0] + tx, alpha * p0[1] + ty)
    c2 = (alpha * p3[0] + tx, alpha * p3[1] + ty)
    return [p0, c1, c2, p3]


def xform(cx, cy, rp, p):
    """EBOX::ptlXform: onto the ellipse, in POINTFIX, rounded.

    The rect Arc is given runs (cx-rp, cy-rp) to (cx+rp+1, cy+rp+1), and
    GDI takes it with **both edges in**: the ellipse spans cx-rp to cx+rp,
    so its middle is cx exactly and its radius rp exactly.  Asked for
    p = (1, 0) at radius 24 GDI's control point is 24, not 25."""
    ux = rp * 16                   # the half-axis across, in sixteenths
    vy = -rp * 16                  # and up; device y grows downward
    mx = cx * 16
    my = cy * 16
    return (int(math.floor(mx + ux * p[0] + 0.5)),
            int(math.floor(my + vy * p[1] + 0.5)))


def arc_pieces(cx, cy, rp, a0, sweep):
    """The Beziers GDI would build, in POINTFIX."""
    gx, gy = ray(rp, a0)
    ex, ey = ray(rp, a0 + sweep)
    # where the ends sit on the unit circle: the ray from the middle,
    # measured in the box's own units, made a unit long
    def unit(px, py):
        # The angle is measured from the rect's **true** middle -- the rect
        # runs (cx-rp, cy-rp) to (cx+rp+1, cy+rp+1), so that is
        # (cx+.5, cy+.5) -- while the ellipse the point lands on is the one
        # EBOX builds, middle cx and radius rp.  The two are not the same
        # place, which is what made this look arbitrary from outside.
        dx = (px - 0.5) / (rp + 0.5)
        dy = -(py - 0.5) / (rp + 0.5)
        n = math.hypot(dx, dy)
        return (dx / n, dy / n)

    # vArctan is handed the point in **device** terms -- y downward -- and
    # answers in degrees the same way round, so the maths angle is its
    # negative.
    a = -math.radians(varctan((gx - 0.5) / (rp + 0.5),
                              (gy - 0.5) / (rp + 0.5)))
    b = -math.radians(varctan((ex - 0.5) / (rp + 0.5),
                              (ey - 0.5) / (rp + 0.5)))
    d = 1.0 if sweep >= 0 else -1.0
    left = (b - a) * d
    while left <= 0:
        left += 2 * math.pi
    out = []
    guard = 0
    while left > 1e-12 and guard < 16:
        guard += 1
        q = a / HALFPI
        nxt = (math.floor(q) + 1.0) * HALFPI if d > 0 else (math.ceil(q) - 1.0) * HALFPI
        step = (nxt - a) if d > 0 else (a - nxt)
        if step < 1e-9:
            step = HALFPI
        if step > left:
            step = left
        b1 = a + d * step
        q0 = (math.cos(a), math.sin(a))
        q1 = (math.cos(b1), math.sin(b1))
        cp = quad_bezier(q0, q1, a, b1)
        out.append([xform(cx, cy, rp, q) for q in cp])
        a = b1
        left -= step
    return out


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
