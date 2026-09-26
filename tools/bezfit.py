#!/usr/bin/env python3
u"""Fit the control points GDI gives an Arc.

    tmp/gdiarc.exe < tmp/cps.txt > tmp/cps.out
    python tools/bezfit.py

GDI turns an Arc into cubic Beziers -- BeginPath / Arc / EndPath / GetPath
hands back PT_MOVETO followed by PT_BEZIERTO, and flattening that path and
stroking it paints exactly what Arc paints.  So the port can draw an arc the
way GDI does, once it can work out the same control points.

Two rules are settled (docs/notes-pixels.md):

  * the cuts are at the quarter turns, with a degenerate Bezier where the
    sweep does not reach one
  * the radius is **rp + 0.5**, not rp -- read straight off GDI's own
    quadrant control points, where the tangent step is k*(rp+0.5) rounded

What is fitted here is the rest: where the ends sit, and hence where the
degenerate piece falls.  `lead` tries the reading that a piece is emitted
for the stretch behind a start that sits on a quarter turn, which is what
would put a degenerate one at the front rather than the back.
"""
import io
import math
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


def rounder(how):
    if how == "round":
        return lambda t: int(math.floor(t + 0.5))
    if how == "floor":
        return lambda t: int(math.floor(t))
    if how == "ceil":
        return lambda t: int(math.ceil(t))
    return lambda t: int(t)


def build(rp, a0, sweep, acen, pcen, prad, how, lead, krad):
    f = rounder(how)
    R = rp + prad
    gx, gy = ray(rp, a0)
    a = math.atan2(-(gy - acen), gx - acen)
    d = 1.0 if sweep >= 0 else -1.0
    left = abs(sweep)
    pts = [(f(pcen + R * math.cos(a)), f(pcen - R * math.sin(a)))]
    guard = 0
    if lead:
        q = a / HALF
        if abs(q - round(q)) < 1e-9:
            x0 = pcen + R * math.cos(a)
            y0 = pcen - R * math.sin(a)
            pts.append((f(x0), f(y0)))
            pts.append((f(x0), f(y0)))
            pts.append((f(x0), f(y0)))
    while left > 1e-12 and guard < 64:
        guard += 1
        q = a / HALF
        if d > 0:
            nxt = (math.floor(q) + 1.0) * HALF
        else:
            nxt = (math.ceil(q) - 1.0) * HALF
        step = (nxt - a) if d > 0 else (a - nxt)
        if step < 1e-9:
            step = HALF
        if step > left:
            step = left
        b1 = a + d * step
        k = 4.0 / 3.0 * math.tan(step / 4.0) * d
        KR = (rp + krad) * k
        x0, y0 = pcen + R * math.cos(a), pcen - R * math.sin(a)
        x3, y3 = pcen + R * math.cos(b1), pcen - R * math.sin(b1)
        c1 = (x0 - KR * math.sin(a), y0 - KR * math.cos(a))
        c2 = (x3 + KR * math.sin(b1), y3 + KR * math.cos(b1))
        pts.append((f(c1[0]), f(c1[1])))
        pts.append((f(c2[0]), f(c2[1])))
        pts.append((f(x3), f(y3)))
        a = b1
        left -= step
    return pts


def main():
    got = read_points("tmp/cps.out")
    cs = cases()
    best = []
    for acen in (0.0, 0.5):
        for pcen in (0.0, 0.5):
            for prad in (0.0, 0.5):
                for how in ("round", "floor", "trunc", "ceil"):
                    for krad in (0.0, 0.5, 1.0):
                     for lead in (0, 1):
                      ok = n = same = 0
                      for tag, rp, a0, sw in cs:
                        g = got.get(tag)
                        if not g:
                            continue
                        n += 1
                        m = build(rp, a0, sw, acen, pcen, prad, how, lead,
                                  krad)
                        if len(m) == len(g):
                            same += 1
                        if m == g:
                            ok += 1
                      best.append((ok, same, acen, pcen, prad, how, lead,
                                   krad, n))
    best.sort(reverse=True)
    print("%6s %8s  %-6s %-6s %-8s %-7s %-5s %-6s"
          % ("exact", "same n", "angle", "point", "radius", "round", "lead",
             "k rad"))
    for ok, same, ac, pc, pr, how, lead, krad, n in best[:12]:
        print("%6d %8d  %-6.1f %-6.1f %-8s %-7s %-5d rp+%.1f   (of %d)"
              % (ok, same, ac, pc, "rp+%.1f" % pr, how, lead, krad, n))


if __name__ == "__main__":
    main()
