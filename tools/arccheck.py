#!/usr/bin/env python3
u"""Hold `src/draw.c`'s own gdi_arc against the Python model, arc for arc.

    sh tools/arccheck.sh && python tools/arccheck.py

`tools/arcfull.py` settles the **model** -- 472 of 472 arcs come out exactly
as GDI's own `Arc` paints them.  It says nothing about whether the C that
went into the port is the same thing, and the fifteen-drawing score cannot
tell a slip in one quadrant from a drawing that was always going to differ.
This runs both over the same arcs and says where they part.
"""
import math
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gdimath
import gdiline
import hfd


def model(l, t, r, b, x1, y1, x2, y2):
    box = gdimath.Box(l, t, r, b)
    poly = []
    for seg in gdimath.arc(box, x1, y1, x2, y2):
        if not poly:
            poly.append(seg[0])
        poly.extend(hfd.flatten(seg))
    return gdiline.stroke(poly)


def cases():
    """Arcs the drawings actually ask for, plus the awkward ones: a sweep
    that stops inside one quadrant, one that crosses every boundary, the
    two ends in the same pixel, and the 2rp box a whole circle goes in."""
    import random
    random.seed(23)
    out = []
    mid = 420
    for rp in (2, 3, 5, 9, 14, 24, 40, 61, 100, 160, 260, 380):
        for k in range(14):
            a0 = random.uniform(0, 2 * math.pi)
            sw = random.choice([random.uniform(0.11, 0.9),
                                random.uniform(0.9, 6.2),
                                -random.uniform(0.11, 6.2)])
            for hi in (1, 0):
                gx = mid + int(rp * math.cos(a0))
                gy = mid - int(rp * math.sin(a0))
                ex = mid + int(rp * math.cos(a0 + sw))
                ey = mid - int(rp * math.sin(a0 + sw))
                if sw < 0:
                    gx, gy, ex, ey = ex, ey, gx, gy
                out.append((mid - rp, mid - rp, mid + rp + hi, mid + rp + hi,
                            gx, gy, ex, ey))
    return out


def main():
    cs = cases()
    ask = []
    for i, c in enumerate(cs):
        ask.append("A%d %s" % (i, " ".join(str(v) for v in c)))
    text = subprocess.run([os.path.join("tmp", "arccheck.exe")],
                          input="\n".join(ask) + "\n",
                          capture_output=True, text=True).stdout
    got, k = {}, 0
    rows = text.split("\n")
    while k < len(rows):
        h = rows[k].split()
        k += 1
        if len(h) != 2:
            continue
        tag, n = h[0], int(h[1])
        pts = set()
        for _ in range(n):
            p = rows[k].split()
            k += 1
            if len(p) == 2:
                pts.add((int(p[0]), int(p[1])))
        got[tag] = pts

    same = n = tot = 0
    worst = []
    for i, c in enumerate(cs):
        mine = model(*c)
        theirs = got.get("A%d" % i)
        if theirs is None:
            continue
        n += 1
        d = len(mine ^ theirs)
        tot += d
        if d == 0:
            same += 1
        else:
            worst.append((d, c, len(mine)))
    print("%d / %d のアークで C と模型が画素まで同じ、外れは合計 %d 画素"
          % (same, n, tot))
    worst.sort(reverse=True)
    for d, c, m in worst[:6]:
        print("   box %d %d %d %d  ends %d %d -> %d %d: %d / %d"
              % (c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], d, m))


if __name__ == "__main__":
    main()
