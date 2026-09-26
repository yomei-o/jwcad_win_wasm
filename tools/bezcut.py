#!/usr/bin/env python3
u"""Where does GDI cut a Bezier when it flattens it?

    tmp/gdiarc.exe < tmp/cut.txt > tmp/cut.out 2> /dev/null
    python tools/bezcut.py

GDI's flattening is coarse -- a 140 pixel arc comes back as 14 points, a
sagitta of about a third of a pixel -- and the port's own subdivision does
not land on the same places, which is most of what is still wrong
(docs/notes-pixels.md,「模型はまだ合いません」).

Guessing at subdivision rules is slow.  The points themselves are readable
with FlattenPath and GetPath, and so are the control points (odd 7), so the
parameter each cut sits at can simply be measured: for every point GDI
produced, find the t on the curve closest to it.  If those t come out at
halves, quarters and eighths, GDI is halving like the port does and the
difference is only where it stops; if they come out evenly spaced, it is
walking the curve by arc length instead.
"""
import io
import math
import sys

TWO = 2.0 * math.pi


def read(path):
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


def at(seg, t):
    (x0, y0), (x1, y1), (x2, y2), (x3, y3) = seg
    u = 1.0 - t
    x = u * u * u * x0 + 3 * u * u * t * x1 + 3 * u * t * t * x2 + t * t * t * x3
    y = u * u * u * y0 + 3 * u * u * t * y1 + 3 * u * t * t * y2 + t * t * t * y3
    return x, y


def nearest(seg, p):
    """The t whose point on the curve is closest to p, to four places."""
    best, bt = 1e18, 0.0
    for i in range(0, 4001):
        t = i / 4000.0
        x, y = at(seg, t)
        d = (x - p[0]) ** 2 + (y - p[1]) ** 2
        if d < best:
            best, bt = d, t
    return bt, math.sqrt(best)


def main():
    got = read(sys.argv[1] if len(sys.argv) > 1 else "tmp/cut.out")
    cps = got.get("C")
    fl = got.get("F")
    if not cps or not fl:
        print("want both the control points (C) and the flattening (F)")
        return
    segs = []
    for i in range(1, len(cps) - 2, 3):
        segs.append((cps[i - 1], cps[i], cps[i + 1], cps[i + 2]))
    print("%d Bezier pieces, %d points in the flattening" % (len(segs),
                                                             len(fl)))
    for k, seg in enumerate(segs):
        print("")
        print("piece %d: %s" % (k, " ".join(str(q) for q in seg)))
        print("   %-12s %8s %8s %8s" % ("point", "t", "step", "off curve"))
        last = None
        for p in fl:
            t, d = nearest(seg, p)
            if d > 1.5:
                continue
            step = "" if last is None else "%8.4f" % (t - last)
            print("   %-12s %8.4f %8s %8.3f" % (str(p), t, step, d))
            last = t


if __name__ == "__main__":
    main()
