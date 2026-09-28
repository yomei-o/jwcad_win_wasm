#!/usr/bin/env python3
u"""How does GDI turn a POINTFIX polyline into pixels?

    python tools/fixline.py

The flattener hands the stroker points in sixteenths -- (59.750, -12.375)
and the like -- and `GetPath` only ever showed their whole part, which is
why stroking those whole numbers never matched (docs/notes-pixels.md).

With the flattener exact (`tools/hfd.py`) the polyline is known to the
sixteenth, and GDI will say what pixels it paints for the same curve
(`tools/gdiarc.c`, odd 11).  So the last step can be fitted on its own:
try a way of walking a line with fractional ends, and see whether the
pixels come out.

**Superseded.**  The rule this file fits -- step the longer axis a whole
pixel at a time from the rounded start, take the other axis off the line
through the *unrounded* ends, and leave the far end out -- was 10 of 10 on
the ten quadrant curves here and **21 of 60** on wild ones.  Ten symmetric
cases were not enough to tell it from the real thing.  `tools/gdiline.py`
has the real thing, `bLines` out of win32kfull.sys, at 120 of 120.

Kept because the measurement is still the record of what a rule of thumb
buys: 10/10 here, and what that was worth in the end.
"""
import io
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


def walk_round(x0, y0, x1, y1, out, last):
    """Even steps along the line -- the obvious way, and the wrong one."""
    dx, dy = x1 - x0, y1 - y0
    n = max(abs(dx), abs(dy))
    if n == 0:
        out.add(((x0 + 8) >> 4, (y0 + 8) >> 4))
        return
    steps = (n + 15) // 16
    for i in range(steps + (1 if last else 0)):
        t = float(i) / steps
        out.add((int(math.floor((x0 + dx * t) / 16.0 + 0.5)),
                 int(math.floor((y0 + dy * t) / 16.0 + 0.5))))


def walk_major(x0, y0, x1, y1, out, last):
    """Bresenham on whole pixels, but seeded from the fractional ends: step
    the longer axis one pixel at a time from the rounded start, and take the
    other axis off the true line."""
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
        for i in range(n + (1 if last else 0)):
            px = ax0 + sx * i
            yy = (y0 + (px * 16 - x0) * m) / 16.0
            out.add((px, int(math.floor(yy + 0.5))))
    else:
        n = abs(dyp)
        sy = 1 if dyp > 0 else -1
        m = (x1 - x0) / float(y1 - y0) if y1 != y0 else 0.0
        for i in range(n + (1 if last else 0)):
            py = ay0 + sy * i
            xx = (x0 + (py * 16 - y0) * m) / 16.0
            out.add((int(math.floor(xx + 0.5)), py))


def stroke(poly, how, close_last=0):
    out = set()
    for i in range(len(poly) - 1):
        how(poly[i][0], poly[i][1], poly[i + 1][0], poly[i + 1][1], out,
            1 if (close_last and i == len(poly) - 2) else 0)
    return out


def cases():
    out = []
    for rp in (14, 19, 24, 40, 61):
        k = int(round(4.0 / 3.0 * math.tan(math.pi / 8) * (rp + 0.5)))
        out.append(((rp, 0), (rp, -k), (k, -rp), (0, -rp)))
        out.append(((0, -rp), (-k, -rp), (-rp, -k), (-rp, 0)))
    return out


def main():
    cs = cases()
    ask = []
    for i, c in enumerate(cs):
        (x0, y0), (x1, y1), (x2, y2), (x3, y3) = c
        ask.append("A%d 900 11 %d %d %d %d %d %d %d %d"
                   % (i, x1, y1, x2, y2, x0, y0, x3, y3))
    got = gdi(ask)
    for name, how in (("longer axis, rounded", walk_major),
                      ("even steps, rounded", walk_round)):
        for close in (0, 1):
            same = n = tot = 0
            for i, c in enumerate(cs):
                g = set(got.get("A%d" % i, []))
                if not g:
                    continue
                n += 1
                fix = [(p[0] * 16, p[1] * 16) for p in c]
                poly = [fix[0]] + hfd.flatten(fix)
                m = stroke(poly, how, close)
                d = len(m ^ g)
                tot += d
                if d == 0:
                    same += 1
            print("%-22s %s: %2d / %d exact, %4d pixels out"
                  % (name, "with the far end" if close else "open   ",
                     same, n, tot))


if __name__ == "__main__":
    main()
