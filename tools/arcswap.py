#!/usr/bin/env python3
u"""Where does an arc's ring swap a pixel against the whole circle's?

    tmp/gdiarc.exe < tmp/sw.txt > tmp/sw.out
    python tools/arcswap.py

Chasing GDI's flattening ran out: its polyline is not the curve sampled at
any parameter, nor the curve subdivided in whole numbers
(docs/notes-pixels.md).  So come at it from the pixels instead.

The difference between an arc's ring and the whole circle's is small and
tidy -- for radius 24 it was four swaps, each one pixel, in 34.  If where
those swaps fall follows from the ends, the port can keep its baked ring
and patch it, which needs no flattening at all.

For every arc this prints the swaps: the ring pixel that is dropped, the
arc pixel that takes its place, and how far round from the arc's start each
sits.
"""
import io
import math
import sys

TWO = 2.0 * math.pi


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


def cases():
    out = []
    for rp in (14, 19, 24):
        for k in range(12):
            a0 = TWO * k / 12.0 + 0.07
            out.append((rp, a0, math.pi / 2))
    return out


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


def main():
    if len(sys.argv) < 2:
        with io.open("tmp/sw.txt", "w", encoding="ascii") as f:
            seen = set()
            for rp, a0, sw in cases():
                if rp not in seen:
                    f.write("W%d %d 3 0 0 0 0\n" % (rp, rp))
                    seen.add(rp)
            for i, (rp, a0, sw) in enumerate(cases()):
                x1, y1 = ray(rp, a0)
                x2, y2 = ray(rp, a0 + sw)
                f.write("A%d %d 1 %d %d %d %d\n" % (i, rp, x1, y1, x2, y2))
        print("wrote tmp/sw.txt: %d arcs" % len(cases()))
        return

    got = read(sys.argv[1])
    print("%5s %8s  %-22s %-22s %s"
          % ("rp", "start", "the ring's", "the arc's", "how far round"))
    for i, (rp, a0, sw) in enumerate(cases()):
        arc = got.get("A%d" % i)
        ring = got.get("W%d" % rp)
        if arc is None or ring is None:
            continue
        a, w = set(arc), set(ring)
        extra = sorted(a - w)
        if not extra:
            print("%5d %8.4f  (nothing swapped, %d pixels)" % (rp, a0,
                                                               len(arc)))
            continue
        lo = a0
        for p in extra:
            t = (math.atan2(-p[1], p[0]) - lo) % TWO
            # the ring pixel it stands in for: the nearest one not in the arc
            near, nd = None, 1e9
            for q in w - a:
                d = (q[0] - p[0]) ** 2 + (q[1] - p[1]) ** 2
                if d < nd:
                    near, nd = q, d
            print("%5d %8.4f  %-22s %-22s %6.1f deg of %.0f"
                  % (rp, a0, str(near), str(p), math.degrees(t),
                     math.degrees(sw)))


if __name__ == "__main__":
    main()
