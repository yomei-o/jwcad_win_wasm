#!/usr/bin/env python3
u"""Guess the control points GDI makes for an arc, and check by flattening.

    python tools/arcbez2.py

The flattener is exact now (`tools/hfd.py`), so a guess at the control
points can be checked end to end: flatten it and hold the polyline against
the one GDI produced for the same arc (`tools/gdiarc.c`, odd 9).  Solving
for the control points directly does not work -- the flattening is rounded
to whole POINTs, so many sixteenths give the same answer -- but a *rule*
either reproduces every arc or it does not.

The rule under test, in POINTFIX (sixteenths of a pixel):

  * Arc's rect is exclusive on the right and bottom, so
    (cx-rp, cy-rp, cx+rp+1, cy+rp+1) puts the middle at (cx+0.5, cy+0.5)
    and the radius at rp+0.5
  * an end's angle is the ray from that middle through the point Jw_cad
    hands GDI
  * the piece is cut at the quarter turns, and each is the textbook arc
    Bezier with k = 4/3 tan(step/4)
"""
import math
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import hfd

HALFPI = math.pi / 2.0


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


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


def fx(v, how):
    """A device value to POINTFIX."""
    if how == "round":
        return int(math.floor(v * 16.0 + 0.5))
    if how == "floor":
        return int(math.floor(v * 16.0))
    if how == "trunc":
        return int(v * 16.0)
    return int(math.ceil(v * 16.0))


def pieces(rp, a0, sweep, mid, rad, how):
    """The Bezier pieces, as POINTFIX control points."""
    gx, gy = ray(rp, a0)
    ex, ey = ray(rp, a0 + sweep)
    a = math.atan2(-(gy - mid), gx - mid)
    b = math.atan2(-(ey - mid), ex - mid)
    d = 1.0 if sweep >= 0 else -1.0
    left = (b - a) * d
    while left <= 0:
        left += 2 * math.pi
    R = rp + rad
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
        k = 4.0 / 3.0 * math.tan(step / 4.0) * d
        x0, y0 = mid + R * math.cos(a), mid - R * math.sin(a)
        x3, y3 = mid + R * math.cos(b1), mid - R * math.sin(b1)
        c1 = (x0 - k * R * math.sin(a), y0 - k * R * math.cos(a))
        c2 = (x3 + k * R * math.sin(b1), y3 + k * R * math.cos(b1))
        out.append([(fx(x0, how), fx(y0, how)), (fx(c1[0], how), fx(c1[1], how)),
                    (fx(c2[0], how), fx(c2[1], how)), (fx(x3, how), fx(y3, how))])
        a = b1
        left -= step
    return out


def mine(rp, a0, sweep, mid, rad, how):
    segs = pieces(rp, a0, sweep, mid, rad, how)
    if not segs:
        return []
    out = [((segs[0][0][0] + 8) >> 4, (segs[0][0][1] + 8) >> 4)]
    for seg in segs:
        for p in hfd.flatten(seg):
            out.append(((p[0] + 8) >> 4, (p[1] + 8) >> 4))
    return out


def cases():
    out = []
    for rp in (14, 19, 24, 40, 61):
        for k in range(8):
            out.append((rp, 0.06 + k * 0.4, 0.9))
            out.append((rp, 0.06 + k * 0.4, math.pi / 2))
    return out


def main():
    cs = cases()
    ask = []
    for i, (rp, a0, sw) in enumerate(cs):
        x1, y1 = ray(rp, a0)
        x2, y2 = ray(rp, a0 + sw)
        ask.append("F%d %d 9 %d %d %d %d" % (i, rp, x1, y1, x2, y2))
    got = gdi(ask)
    print("%-6s %-6s %-7s  %s" % ("middle", "radius", "to fix", "matches"))
    for mid in (0.0, 0.5):
        for rad in (0.0, 0.5):
            for how in ("round", "floor", "trunc", "ceil"):
                same = n = 0
                for i, (rp, a0, sw) in enumerate(cs):
                    g = got.get("F%d" % i)
                    if not g:
                        continue
                    n += 1
                    if mine(rp, a0, sw, mid, rad, how) == g:
                        same += 1
                print("%-6.1f %-6.1f %-7s  %3d / %d" % (mid, rad, how, same, n))


if __name__ == "__main__":
    main()
