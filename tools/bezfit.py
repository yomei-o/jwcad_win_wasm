#!/usr/bin/env python3
u"""Fit the control points GDI gives an Arc.

    tmp/gdiarc.exe < tmp/cps.txt > tmp/cps.out 2> tmp/cps.types
    python tools/bezfit.py

GDI turns an Arc into cubic Beziers -- BeginPath / Arc / EndPath / GetPath
hands back PT_MOVETO followed by PT_BEZIERTO, and flattening that path and
stroking it paints exactly what Arc paints.  So the port can draw an arc the
way GDI does, if it can work out the same control points.

This holds a candidate rule up against GDI's own answer, arc by arc, and
says where it parts company.  The rule under test:

  * the middle is (cx, cy) and the radius rp exactly -- Arc's rect is
    exclusive on the right and bottom, so (cx-rp, cy-rp, cx+rp+1, cy+rp+1)
    covers cx-rp .. cx+rp
  * the sweep is cut at the quarter turns
  * each piece is the textbook arc Bezier, k = 4/3 tan(step/4)
  * every point is rounded to whole device units

The run prints how many arcs match outright and, for the rest, the first
point that differs -- which says which of those four is wrong.
"""
import io
import math
import os
import sys

TWO = 2.0 * math.pi
HALF = math.pi / 2.0


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


def cases():
    out = []
    for rp in (7, 14, 19, 24, 40, 61):
        for k in range(16):
            a0 = TWO * k / 16.0
            for sw in (math.pi / 2, math.pi / 4, 1.0, 2.6):
                out.append(("%d_%d_%d" % (rp, k, int(sw * 1000)), rp, a0, sw))
    return out


def read_points(path):
    got = {}
    lines = io.open(path, encoding="ascii", errors="replace").read().split("\n")
    k = 0
    while k < len(lines):
        head = lines[k].split()
        k += 1
        if len(head) != 2:
            continue
        tag, n = head[0], int(head[1])
        pts = []
        for _ in range(n):
            if k >= len(lines):
                break
            p = lines[k].split()
            k += 1
            if len(p) == 2:
                pts.append((int(p[0]), int(p[1])))
        got[tag] = pts
    return got


def rnd(v):
    return int(math.floor(v + 0.5))


def mine(rp, a0, sweep):
    """The candidate: quarter-turn cuts, textbook Bezier, rounded."""
    pts = []
    a = a0
    left = abs(sweep)
    d = 1.0 if sweep >= 0 else -1.0
    x, y = rp * math.cos(a), -rp * math.sin(a)
    pts.append((rnd(x), rnd(y)))
    guard = 0
    while left > 1e-12 and guard < 64:
        guard += 1
        q = a / HALF
        nxt = (math.floor(q) + 1.0) * HALF if d > 0 else (math.ceil(q) - 1.0) * HALF
        step = (nxt - a) if d > 0 else (a - nxt)
        if step < 1e-9 or step > left:
            step = left
        b0, b1 = a, a + d * step
        k = 4.0 / 3.0 * math.tan(step / 4.0) * d
        x0, y0 = rp * math.cos(b0), -rp * math.sin(b0)
        x3, y3 = rp * math.cos(b1), -rp * math.sin(b1)
        c1x, c1y = x0 - k * rp * math.sin(b0), y0 - k * rp * math.cos(b0)
        c2x, c2y = x3 + k * rp * math.sin(b1), y3 + k * rp * math.cos(b1)
        pts.append((rnd(c1x), rnd(c1y)))
        pts.append((rnd(c2x), rnd(c2y)))
        pts.append((rnd(x3), rnd(y3)))
        a = b1
        left -= step
    return pts


VARIANTS = []
for acen in (0.0, 0.5):
    for pcen, prad in ((0.0, 0.0), (0.5, 0.5)):
        for how in ("round", "floor", "trunc", "ceil"):
            VARIANTS.append((acen, pcen, prad, how))


def place(v, rp, gx, gy):
    """Where a candidate rule puts the arc's end, given the point asked for."""
    acen, pcen, prad, how = v
    vx, vy = gx - acen, gy - acen
    a = math.atan2(-vy, vx)
    R = rp + prad
    x = pcen + R * math.cos(a)
    y = pcen - R * math.sin(a)
    if how == "round":
        f = lambda t: int(math.floor(t + 0.5))
    elif how == "floor":
        f = lambda t: int(math.floor(t))
    elif how == "ceil":
        f = lambda t: int(math.ceil(t))
    else:
        f = lambda t: int(t)
    return f(x), f(y)


def mine(rp, a0, sweep):
    """The candidate control points: quarter-turn cuts, textbook Bezier."""
    pts = []
    a = a0
    left = abs(sweep)
    d = 1.0 if sweep >= 0 else -1.0
    HALFT = math.pi / 2.0
    x, y = rp * math.cos(a), -rp * math.sin(a)
    pts.append((rnd(x), rnd(y)))
    guard = 0
    while left > 1e-12 and guard < 64:
        guard += 1
        q = a / HALFT
        nxt = (math.floor(q) + 1.0) * HALFT if d > 0 else (math.ceil(q) - 1.0) * HALFT
        step = (nxt - a) if d > 0 else (a - nxt)
        if step < 1e-9 or step > left:
            step = left
        b0, b1 = a, a + d * step
        k = 4.0 / 3.0 * math.tan(step / 4.0) * d
        x0, y0 = rp * math.cos(b0), -rp * math.sin(b0)
        x3, y3 = rp * math.cos(b1), -rp * math.sin(b1)
        c1 = (x0 - k * rp * math.sin(b0), y0 - k * rp * math.cos(b0))
        c2 = (x3 + k * rp * math.sin(b1), y3 + k * rp * math.cos(b1))
        pts.append((rnd(c1[0]), rnd(c1[1])))
        pts.append((rnd(c2[0]), rnd(c2[1])))
        pts.append((rnd(x3), rnd(y3)))
        a = b1
        left -= step
    return pts


def rnd(v):
    return int(math.floor(v + 0.5))


def build(rp, a0, sweep, acen, pcen, prad, how):
    """A candidate: cut at the quarter turns with ceil, textbook Bezier."""
    if how == "round":
        f = lambda t: int(math.floor(t + 0.5))
    elif how == "floor":
        f = lambda t: int(math.floor(t))
    elif how == "ceil":
        f = lambda t: int(math.ceil(t))
    else:
        f = lambda t: int(t)
    R = rp + prad
    HALFT = math.pi / 2.0
    gx, gy = ray(rp, a0)
    ex, ey = ray(rp, a0 + sweep)
    a = math.atan2(-(gy - acen), gx - acen)
    b = math.atan2(-(ey - acen), ex - acen)
    d = 1.0 if sweep >= 0 else -1.0
    left = abs(sweep)
    pts = []
    pts.append((f(pcen + R * math.cos(a)), f(pcen - R * math.sin(a))))
    guard = 0
    while left > -1e-12 and guard < 64:
        guard += 1
        q = a / HALFT
        nxt = math.ceil(q) * HALFT if d > 0 else math.floor(q) * HALFT
        step = (nxt - a) if d > 0 else (a - nxt)
        if step > left:
            step = left
        b1 = a + d * step
        k = 4.0 / 3.0 * math.tan(step / 4.0) * d
        x0, y0 = pcen + R * math.cos(a), pcen - R * math.sin(a)
        x3, y3 = pcen + R * math.cos(b1), pcen - R * math.sin(b1)
        c1 = (x0 - k * R * math.sin(a), y0 - k * R * math.cos(a))
        c2 = (x3 + k * R * math.sin(b1), y3 + k * R * math.cos(b1))
        pts.append((f(c1[0]), f(c1[1])))
        pts.append((f(c2[0]), f(c2[1])))
        pts.append((f(x3), f(y3)))
        left -= step
        a = b1
        if left <= 1e-12:
            break
        if step <= 1e-12:
            a = a + d * 1e-9
    return pts


def main():
    got = read_points("tmp/cps.out")
    cs = cases()
    best = []
    for acen in (0.0, 0.5):
        for pcen in (0.0, 0.5):
            for prad in (0.0, 0.5):
                for how in ("round", "floor", "trunc", "ceil"):
                    ok = n = same_len = 0
                    for tag, rp, a0, sw in cs:
                        g = got.get(tag)
                        if not g:
                            continue
                        n += 1
                        m = build(rp, a0, sw, acen, pcen, prad, how)
                        if len(m) == len(g):
                            same_len += 1
                        if m == g:
                            ok += 1
                    best.append((ok, same_len, acen, pcen, prad, how, n))
    best.sort(reverse=True)
    print("%6s %8s  %-6s %-6s %-8s %-7s" % ("exact", "same n", "angle",
                                            "point", "radius", "round"))
    for ok, sl, ac, pc, pr, how, n in best[:10]:
        print("%6d %8d  %-6.1f %-6.1f %-8s %-7s   (of %d)"
              % (ok, sl, ac, pc, "rp+%.1f" % pr, how, n))


if __name__ == "__main__":
    main()
