#!/usr/bin/env python3
u"""One arc, pixel by pixel: GDI's partial ring against its whole ring.

    gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32
    python tools/arcone2.py 14 0.11 1.5708          # writes tmp/one.txt
    tmp/gdiarc.exe < tmp/one.txt > tmp/one.out
    python tools/arcone2.py 14 0.11 1.5708 tmp/one.out

tools/arcsub.py established that a partial Arc's ring is **not** a subset of
the whole circle's ring in the same box -- 213 of 224 arcs paint something
the whole ring does not have, and the difference carries across the seams
between eighths of a turn.  That kills the port's way of drawing arcs, which
cuts a stretch out of the ring it baked for the whole circle.

To put something in its place the shape of the difference has to be seen,
not just counted.  This prints the two rings side by side, in walking order,
with the radius of each pixel from the middle of the box's ellipse.
"""
import io
import math
import sys

NVAR = 8
TWO_PI = 2.0 * math.pi


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


def read(path):
    rings = {}
    lines = io.open(path, encoding="ascii", errors="replace").read().split("\n")
    k = 0
    while k < len(lines):
        head = lines[k].split()
        k += 1
        if len(head) != 2:
            continue
        tag, n = int(head[0]), int(head[1])
        pts = []
        for _ in range(n):
            if k >= len(lines):
                break
            p = lines[k].split()
            k += 1
            if len(p) == 2:
                pts.append((int(p[0]), int(p[1])))
        rings[tag] = pts
    return rings


def main():
    rp = int(sys.argv[1])
    a0 = float(sys.argv[2])
    sw = float(sys.argv[3])
    got = sys.argv[4] if len(sys.argv) > 4 else None

    x1, y1 = ray(rp, a0)
    x2, y2 = ray(rp, a0 + sw)
    if sw < 0:
        x1, y1, x2, y2 = x2, y2, x1, y1

    if not got:
        with io.open("tmp/one.txt", "w", encoding="ascii") as f:
            f.write("0 %d 1 %d %d %d %d\n" % (rp, x1, y1, x2, y2))
            f.write("%d %d 3 0 0 0 0\n" % (NVAR, rp))
        print("wrote tmp/one.txt  rp %d  ends %+d%+d %+d%+d"
              % (rp, x1, y1, x2, y2))
        return

    rings = read(got)
    part = rings.get(0, [])
    whole = set(rings.get(NVAR, []))
    ps = set(part)

    print("rp %d  start %.4f  sweep %.4f  ends %+d%+d -> %+d%+d"
          % (rp, a0, sw, x1, y1, x2, y2))
    print("the partial arc has %d pixels, the whole ring %d"
          % (len(part), len(whole)))
    print("%d of the arc's are not in the whole ring" % len(ps - whole))
    print("")
    print("%5s %6s %6s  %8s  %s" % ("i", "dx", "dy", "r", ""))
    # Walk the arc's own pixels in angle order from the start.
    lo = a0 if sw > 0 else a0 + sw
    def key(p):
        t = (math.atan2(-p[1], p[0]) - lo) % TWO_PI
        return t
    for i, (dx, dy) in enumerate(sorted(part, key=key)):
        r = math.hypot(dx - 0.5, dy - 0.5)
        mark = "" if (dx, dy) in whole else "   <= not in the whole ring"
        print("%5d %6d %6d  %8.3f%s" % (i, dx, dy, r, mark))

    print("")
    print("and the whole ring, in angle order, with the same radius:")
    for i, (dx, dy) in enumerate(sorted(whole,
                                        key=lambda p: math.atan2(-p[1], p[0]))):
        print("%5d %6d %6d  %8.3f   from (0,0) %8.3f"
              % (i, dx, dy, math.hypot(dx - 0.5, dy - 0.5),
                 math.hypot(dx, dy)))


if __name__ == "__main__":
    main()
