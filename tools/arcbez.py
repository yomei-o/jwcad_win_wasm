#!/usr/bin/env python3
u"""Does GDI's Arc paint the same pixels as a PolyBezier of the same arc?

    gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32
    python tools/arcbez.py                       # writes tmp/bez.txt
    tmp/gdiarc.exe < tmp/bez.txt > tmp/bez.out
    python tools/arcbez.py tmp/bez.out

tools/arcsame.py showed the ring depends on **both** ends together: with
the start fixed, stretching the far end moves pixels near the near one.  A
walk that accumulates from the start cannot do that.  Splitting the curve
into cubic Beziers can, because the control points depend on the whole
sweep -- which is a plain reason to suspect GDI turns an Arc into Beziers.

If it does, the port has a way in: flatten the same Beziers and hand the
pieces to its own line drawing, which is already exact against GDI.
"""
import io
import math
import sys

NVAR = 8
TWO_PI = 2.0 * math.pi


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


def cases():
    out = []
    for rp in (14, 19, 24, 40, 61):
        for k in range(8):
            for off in (0.0, 0.11, 0.37):
                for sw in (math.pi / 4, math.pi / 2, 2.6):
                    out.append((rp, TWO_PI * k / 8.0 + off, sw))
    return out


def main():
    got = sys.argv[1] if len(sys.argv) > 1 else None
    cs = cases()
    if not got:
        with io.open("tmp/bez.txt", "w", encoding="ascii") as f:
            for i, (rp, a0, sw) in enumerate(cs):
                x1, y1 = ray(rp, a0)
                x2, y2 = ray(rp, a0 + sw)
                f.write("%d %d 1 %d %d %d %d\n" % (i * NVAR, rp, x1, y1,
                                                   x2, y2))
                f.write("%d %d 6 %d %d %d %d\n" % (i * NVAR + 1, rp, x1, y1,
                                                   x2, y2))
        print("wrote tmp/bez.txt: %d arcs" % len(cs))
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

    same = 0
    tot = 0
    off = []
    for i, (rp, a0, sw) in enumerate(cs):
        a = rings.get(i * NVAR)
        b = rings.get(i * NVAR + 1)
        if a is None or b is None:
            continue
        tot += 1
        d = a ^ b
        if not d:
            same += 1
        else:
            off.append((len(d), len(a), rp, a0, sw))
    print("%d of %d arcs: Arc and PolyBezier paint exactly the same pixels"
          % (same, tot))
    if off:
        off.sort()
        print("")
        print("%8s %8s %5s %8s %8s" % ("differ", "of", "rp", "start",
                                       "sweep"))
        for n, na, rp, a0, sw in off[:6]:
            print("%8d %8d %5d %8.4f %8.4f" % (n, na, rp, a0, sw))
        print("   ... and the worst:")
        for n, na, rp, a0, sw in off[-4:]:
            print("%8d %8d %5d %8.4f %8.4f" % (n, na, rp, a0, sw))


if __name__ == "__main__":
    main()
