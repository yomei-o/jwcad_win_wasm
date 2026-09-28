#!/usr/bin/env python3
u"""The whole chain from control points to pixels, held against GDI.

    python tools/arcpipe.py

**Its `walk` is superseded**: `tools/gdiline.py` has GDI's own `bLines`,
which is exact where this one's rule of thumb is not.  What is still used
from here is `gdi()`, the pipe to `tools/gdiarc.exe`, and `pixels()` as a
record of how far a good guess got (52 of 80 arcs, against 80 of 80 with
`bLines`).

    flatten   tools/hfd.py      352 of 352 arc-shaped curves
    stroke    tools/gdiline.py  120 of 120
    to POINT  round, not truncate
"""
import math
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import hfd


def gdi(lines):
    out = subprocess.run([os.path.join("tmp", "gdiarc.exe")],
                         input="\n".join(lines) + "\n",
                         capture_output=True, text=True).stdout
    got, k = {}, 0
    rows = out.split("\n")
    while k < len(rows):
        h = rows[k].split()
        k += 1
        if len(h) != 2:
            continue
        tag, n = h[0], int(h[1])
        pts = []
        for _ in range(n):
            if k >= len(rows):
                break
            p = rows[k].split()
            k += 1
            if len(p) == 2:
                pts.append((int(p[0]), int(p[1])))
        got[tag] = pts
    return got


def rnd_away(v):
    """Half away from zero -- which is what GDI's line does: on the segment
    from (4.5, -18.4375) the sample at x = 4 lands on y = -18.5 exactly, and
    GDI paints -19."""
    return int(math.floor(v + 0.5)) if v >= 0 else -int(math.floor(-v + 0.5))


def walk(x0, y0, x1, y1, out):
    """One piece of the polyline, the way GDI strokes it.

    The samples sit on whole values of the longer axis, starting at the
    first one **in the direction of travel** -- from 4.5 going down that is
    4, from -10.9375 going up it is -10 -- and running to the far end,
    which is left out the way LineTo leaves its last point out.  The other
    axis comes off the line through the unrounded ends.
    """
    fx0, fy0 = x0 / 16.0, y0 / 16.0
    fx1, fy1 = x1 / 16.0, y1 / 16.0
    dx, dy = fx1 - fx0, fy1 - fy0
    if abs(dx) >= abs(dy):
        if dx == 0:
            out.add((rnd_away(fx0), rnd_away(fy0)))
            return
        m = dy / dx
        if dx > 0:
            a = int(math.ceil(fx0))
            while a < fx1:
                out.add((a, rnd_away(fy0 + (a - fx0) * m)))
                a += 1
        else:
            a = int(math.floor(fx0))
            while a > fx1:
                out.add((a, rnd_away(fy0 + (a - fx0) * m)))
                a -= 1
    else:
        m = dx / dy
        if dy > 0:
            a = int(math.ceil(fy0))
            while a < fy1:
                out.add((rnd_away(fx0 + (a - fy0) * m), a))
                a += 1
        else:
            a = int(math.floor(fy0))
            while a > fy1:
                out.add((rnd_away(fx0 + (a - fy0) * m), a))
                a -= 1


def pixels(segs):
    """segs: a list of four-POINTFIX-point Beziers, end to end."""
    poly = []
    for seg in segs:
        if not poly:
            poly.append(seg[0])
        poly.extend(hfd.flatten(seg))
    out = set()
    for i in range(len(poly) - 1):
        walk(poly[i][0], poly[i][1], poly[i + 1][0], poly[i + 1][1], out)
    return out


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


def main():
    """A sanity run: feed it the control points GDI itself reports (whole
    numbers, so their fractions are lost) and see how much of the gap that
    alone accounts for."""
    cs = []
    for rp in (14, 19, 24, 40, 61):
        for k in range(8):
            cs.append((rp, 0.06 + k * 0.4, math.pi / 2))
    ask = []
    for i, (rp, a0, sw) in enumerate(cs):
        x1, y1 = ray(rp, a0)
        x2, y2 = ray(rp, a0 + sw)
        ask.append("P%d %d 7 %d %d %d %d" % (i, rp, x1, y1, x2, y2))
        ask.append("A%d %d 1 %d %d %d %d" % (i, rp, x1, y1, x2, y2))
    got = gdi(ask)
    same = n = tot = 0
    for i, (rp, a0, sw) in enumerate(cs):
        cp = got.get("P%d" % i)
        px = set(got.get("A%d" % i, []))
        if not cp or not px or (len(cp) - 1) % 3:
            continue
        n += 1
        segs = []
        for j in range(1, len(cp) - 2, 3):
            segs.append([(p[0] * 16, p[1] * 16)
                         for p in (cp[j - 1], cp[j], cp[j + 1], cp[j + 2])])
        mine = pixels(segs)
        d = len(mine ^ px)
        tot += d
        if d == 0:
            same += 1
    print("GDI が見せる整数の制御点から通すと: %d / %d が画素まで一致、"
          "外れは合計 %d 画素" % (same, n, tot))
    print("（制御点の小数部が落ちているぶんだけ外れます。"
          "ここが最後の一段です）")


if __name__ == "__main__":
    main()
