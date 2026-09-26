#!/usr/bin/env python3
u"""Does a partial Arc's ring depend only on (radius, start)?

    python tools/arcsame.py            # writes tmp/same.txt
    tmp/gdiarc.exe < tmp/same.txt > tmp/same.out
    python tools/arcsame.py tmp/same.out

tools/arcsub.py showed the ring is not the whole circle's, and that the
extras start at the arc's start and fade along it -- which reads like a walk
whose error is seeded at the start.  If that is all it is, then two arcs
with the same start and different sweeps must paint the **same pixels over
the stretch they share**, and a replacement only has to get the walk right,
not the pair of ends together.
"""
import io
import math
import sys

NVAR = 8
TWO_PI = 2.0 * math.pi
SWEEPS = [math.pi / 4, math.pi / 2, 2.6]


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


def cases():
    out = []
    for rp in (14, 19, 24, 40, 61):
        for k in range(8):
            for off in (0.0, 0.11, 0.37):
                out.append((rp, TWO_PI * k / 8.0 + off))
    return out


def main():
    got = sys.argv[1] if len(sys.argv) > 1 else None
    cs = cases()
    if not got:
        with io.open("tmp/same.txt", "w", encoding="ascii") as f:
            for i, (rp, a0) in enumerate(cs):
                for v, sw in enumerate(SWEEPS):
                    x1, y1 = ray(rp, a0)
                    x2, y2 = ray(rp, a0 + sw)
                    f.write("%d %d 1 %d %d %d %d\n"
                            % (i * NVAR + v, rp, x1, y1, x2, y2))
        print("wrote tmp/same.txt: %d starts x %d sweeps"
              % (len(cs), len(SWEEPS)))
        return

    rings = {}
    lines = io.open(got, encoding="ascii", errors="replace").read().split("\n")
    k = 0
    while k < len(lines):
        head = lines[k].split()
        k += 1
        if len(head) != 2:
            continue
        tag, n = int(head[0]), int(head[1])
        pts = set()
        for _ in range(n):
            if k >= len(lines):
                break
            p = lines[k].split()
            k += 1
            if len(p) == 2:
                pts.add((int(p[0]), int(p[1])))
        rings[tag] = pts

    same = diff = 0
    worst = []
    for i, (rp, a0) in enumerate(cs):
        short = rings.get(i * NVAR)          # the pi/4 one
        if short is None:
            continue
        for v in (1, 2):
            long_ = rings.get(i * NVAR + v)
            if long_ is None:
                continue
            # the stretch they share is the short one's own angles
            cut = set()
            for dx, dy in long_:
                t = (math.atan2(-dy, dx) - a0) % TWO_PI
                if t <= SWEEPS[0] + 1e-9:
                    cut.add((dx, dy))
            head_ = set()
            for dx, dy in short:
                t = (math.atan2(-dy, dx) - a0) % TWO_PI
                if t <= SWEEPS[0] + 1e-9:
                    head_.add((dx, dy))
            if head_ == cut:
                same += 1
            else:
                diff += 1
                worst.append((len(head_ ^ cut), rp, a0, SWEEPS[v]))
    print("%d pairs agree over the shared stretch, %d do not" % (same, diff))
    if worst:
        worst.sort(reverse=True)
        print("%6s %5s %8s %8s" % ("differ", "rp", "start", "the longer"))
        for n, rp, a0, sw in worst[:10]:
            print("%6d %5d %8.4f %8.4f" % (n, rp, a0, sw))


if __name__ == "__main__":
    main()
