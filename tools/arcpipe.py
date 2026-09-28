#!/usr/bin/env python3
u"""The whole chain from control points to pixels, held against GDI.

    python tools/arcpipe.py

Three of the four steps are settled and exact:

    flatten   tools/hfd.py      352 of 352 arc-shaped curves
    stroke    tools/fixline.py  10 of 10
    to POINT  round, not truncate

so anything still wrong is in the fourth -- the control points GDI makes
for an arc.  This runs the three that work end to end, taking the control
points from whatever `cp` is given, and says how far the pixels are from
GDI's.  Feed it a rule for the control points and it grades the rule.
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


def walk(x0, y0, x1, y1, out):
    """One piece of the polyline, the way GDI strokes it: the longer axis a
    whole pixel at a time from the rounded start, the other axis off the
    line through the unrounded ends, and the far end left out."""
    ax0, ay0 = (x0 + 8) >> 4, (y0 + 8) >> 4
    ax1, ay1 = (x1 + 8) >> 4, (y1 + 8) >> 4
    dxp, dyp = ax1 - ax0, ay1 - ay0
    if dxp == 0 and dyp == 0:
        out.add((ax0, ay0))
        return
    if abs(dxp) >= abs(dyp):
        n = abs(dxp)
        sx = 1 if dxp > 0 else -1
        m = (y1 - y0) / float(x1 - x0) if x1 != x0 else 0.0
        for i in range(n):
            px = ax0 + sx * i
            out.add((px, int(math.floor((y0 + (px * 16 - x0) * m) / 16.0
                                        + 0.5))))
    else:
        n = abs(dyp)
        sy = 1 if dyp > 0 else -1
        m = (x1 - x0) / float(y1 - y0) if y1 != y0 else 0.0
        for i in range(n):
            py = ay0 + sy * i
            out.add((int(math.floor((x0 + (py * 16 - y0) * m) / 16.0 + 0.5)),
                     py))


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
