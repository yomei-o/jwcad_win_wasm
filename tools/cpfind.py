#!/usr/bin/env python3
u"""Recover the POINTFIX control points GDI really uses for an arc.

    python tools/cpfind.py

`GetPath` shows a path's Bezier control points as whole POINTs, but the
flattener is handed POINTFIX -- sixteenths -- and the fractions are what the
port has been missing.  `bPartialQuadrantArc`, which computes them, is not
in the decompilation we have.

It does not have to be.  The flattener itself is now exact
(`tools/hfd.py`, 352 of 352 arc-shaped curves), so the control points can be
**solved for**: try the sixteenths around each whole number until the
flattening matches the one GDI produced for the same arc.  Each coordinate
is within half a pixel of what GetPath showed, so eight coordinates of
seventeen candidates each, walked a few times over, settles it.

What comes out is the exact input to the flattener, which is what a rule
can then be read off -- and unlike the whole numbers, these carry the
fractions that decide the pixels.
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


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


def flat_of(cp):
    """cp: four (x, y) in POINTFIX.  The POINTs GetPath would show -- the
    curve's own first point, which the path already holds, then the ones the
    flattener hands back."""
    pts = hfd.flatten(cp)
    out = [((cp[0][0] + 8) >> 4, (cp[0][1] + 8) >> 4)]
    out += [((p[0] + 8) >> 4, (p[1] + 8) >> 4) for p in pts]
    return out


def solve(seed, want):
    """Walk each sixteenth until the flattening is the one GDI made."""
    cur = [list(p) for p in seed]

    def score(c):
        got = flat_of([tuple(p) for p in c])
        if len(got) != len(want):
            return 10000 + abs(len(got) - len(want)) * 100
        return sum(abs(a[0] - b[0]) + abs(a[1] - b[1])
                   for a, b in zip(got, want))

    best = score(cur)
    for _ in range(6):
        moved = False
        for i in range(4):
            for j in range(2):
                base = cur[i][j]
                for d in range(-8, 9):
                    cur[i][j] = base + d
                    s = score(cur)
                    if s < best:
                        best, base, moved = s, cur[i][j], True
                cur[i][j] = base
        if best == 0 or not moved:
            break
    return [tuple(p) for p in cur], best


def main():
    # arcs that stay inside one quadrant, so the path holds one Bezier
    cs = []
    for rp in (14, 19, 24, 40, 61):
        for k in range(6):
            a0 = 0.06 + k * 0.21
            cs.append((rp, a0, 0.9))
    ask = []
    for i, (rp, a0, sw) in enumerate(cs):
        x1, y1 = ray(rp, a0)
        x2, y2 = ray(rp, a0 + sw)
        ask.append("P%d %d 7 %d %d %d %d" % (i, rp, x1, y1, x2, y2))
        ask.append("F%d %d 9 %d %d %d %d" % (i, rp, x1, y1, x2, y2))
    got = gdi(ask)

    print("%4s %8s  %-40s %s" % ("rp", "start", "the sixteenths GDI used",
                                 "off"))
    rows = []
    for i, (rp, a0, sw) in enumerate(cs):
        cp = got.get("P%d" % i)
        fl = got.get("F%d" % i)
        if not cp or len(cp) != 4 or not fl:
            continue
        seed = [(p[0] * 16, p[1] * 16) for p in cp]
        found, err = solve(seed, fl)
        rows.append((rp, a0, cp, found, err))
        print("%4d %8.4f  %-40s %d"
              % (rp, a0, " ".join("%d,%d" % p for p in found), err))
    ok = sum(1 for r in rows if r[4] == 0)
    print("")
    print("%d of %d solved exactly" % (ok, len(rows)))
    io.open("tmp/cpfound.txt", "w", encoding="ascii", newline="\n").write(
        "\n".join("%d %.6f %s %s" % (rp, a0,
                                     " ".join("%d,%d" % p for p in cp),
                                     " ".join("%d,%d" % p for p in f))
                  for rp, a0, cp, f, e in rows if e == 0) + "\n")


if __name__ == "__main__":
    main()
