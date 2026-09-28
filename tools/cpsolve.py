#!/usr/bin/env python3
u"""Solve for the control points GDI uses, with the pixels as the target.

    python tools/cpsolve.py

Three of the four steps are exact now, so the fourth can be solved rather
than derived: walk the sixteenths around the whole numbers `GetPath` shows
until the pixels come out as GDI's.

The pixels are a far sharper target than the flattened polyline, which is
rounded to whole POINTs and so has many control points giving the same
answer (`tools/cpfind.py`).  If the pixel set pins the control points down
to one value for arc after arc, the rule can be read off those values --
and unlike the whole numbers, they carry the fractions that decide
everything downstream.
"""
import io
import math
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import hfd
import arcpipe


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


def solve(seed, want, rounds=8, span=8):
    """seed: the Bezier pieces as POINTFIX; want: GDI's pixels."""
    cur = [[list(p) for p in seg] for seg in seed]

    def score(c):
        segs = [[tuple(p) for p in seg] for seg in c]
        got = arcpipe.pixels(segs)
        return len(got ^ want)

    best = score(cur)
    for _ in range(rounds):
        if best == 0:
            break
        moved = False
        for si in range(len(cur)):
            for i in range(4):
                for j in range(2):
                    base = cur[si][i][j]
                    for d in range(-span, span + 1):
                        if d == 0:
                            continue
                        cur[si][i][j] = base + d
                        s = score(cur)
                        if s < best:
                            best, base, moved = s, cur[si][i][j], True
                    cur[si][i][j] = base
                    # the joins have to stay joins
                    if i == 3 and si + 1 < len(cur):
                        cur[si + 1][0][j] = base
                    if i == 0 and si > 0:
                        cur[si - 1][3][j] = base
        if not moved:
            break
    return cur, best


def main():
    cs = []
    for rp in (14, 19, 24):
        for k in range(6):
            cs.append((rp, 0.06 + k * 0.5, math.pi / 2))
    ask = []
    for i, (rp, a0, sw) in enumerate(cs):
        x1, y1 = ray(rp, a0)
        x2, y2 = ray(rp, a0 + sw)
        ask.append("P%d %d 7 %d %d %d %d" % (i, rp, x1, y1, x2, y2))
        ask.append("A%d %d 1 %d %d %d %d" % (i, rp, x1, y1, x2, y2))
    got = arcpipe.gdi(ask)

    rows = []
    for i, (rp, a0, sw) in enumerate(cs):
        cp = got.get("P%d" % i)
        px = set(got.get("A%d" % i, []))
        if not cp or not px or (len(cp) - 1) % 3:
            continue
        seed = []
        for j in range(1, len(cp) - 2, 3):
            seed.append([(p[0] * 16, p[1] * 16)
                         for p in (cp[j - 1], cp[j], cp[j + 1], cp[j + 2])])
        found, err = solve(seed, px)
        rows.append((rp, a0, sw, found, err))
        flat = [q for seg in found for q in seg]
        print("rp %3d start %6.3f  err %3d   %s"
              % (rp, a0, err,
                 " ".join("%.3f,%.3f" % (q[0] / 16.0, q[1] / 16.0)
                          for q in flat[:4])))
    ok = sum(1 for r in rows if r[4] == 0)
    print("")
    print("%d of %d solved to the pixel" % (ok, len(rows)))
    with io.open("tmp/cpsolved.txt", "w", encoding="ascii",
                 newline="\n") as f:
        for rp, a0, sw, found, err in rows:
            if err:
                continue
            for seg in found:
                f.write("%d %.6f %.6f %s\n"
                        % (rp, a0, sw,
                           " ".join("%d,%d" % (q[0], q[1]) for q in seg)))


if __name__ == "__main__":
    main()
