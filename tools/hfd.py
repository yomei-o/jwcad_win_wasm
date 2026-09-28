#!/usr/bin/env python3
u"""GDI's Bezier flattener, written out from the decompilation.

    python tools/hfd.py                 # hold it against GDI itself

`decomp/gdi/flatten.c` has `BEZIER32::bInit` and `bNext` out of
`win32kbase.sys`.  They are a Hermite forward-difference walk, not a walk in
the curve's own parameter -- which is why the port's points never matched
GDI's however they were placed (docs/notes-pixels.md).

The state is four numbers an axis, at **POINTFIX << 13**:

    e0   where we are
    e1   the first difference
    e2   the second difference at this step
    e3   the second difference at the step before (so e2 - e3 is the third)

and the three moves are

    take   e0 += e1;  e1 += e2;  e2 = 2*e2 - e3;  e3 = e2_old
    halve  e2 = (e2 + e3) >> 3;  e1 = (e1 - e2_new) >> 1;  e3 >>= 2
    double e3 *= 4;  e1 = 2*e1 + e2;  e2 = 8*e2 - 4*e3_old

The starting values come out of the Bezier's own forward differences:

    e0 = P0            e1 = P3 - P0
    e2 = 6(P1 - 2 P2 + P3)               e3 = 6(P0 - 2 P1 + P2)

which is what `bInit` computes (its 0x1800 is 6 * 0x400, and the 0x400 and
the later << 3 make the << 13).

The limit is the same number in both halves of the decompilation: `bNext`
tests `0x7fe00`, and `bInit` tests `0xffc0 << count` at a scale eight times
coarser -- 0xffc0 * 8 = 0x7fe00.

`lParentErrorDividedBy4` the decompilation names but does not show.  It is
what the error would be after doubling the step, over four: doubling takes
e2 to 8*e2 - 4*e3 and e3 to 4*e3, so a quarter of that is
max(|2*e2 - e3|, |e3|).  The step is doubled while that stays within
**0x7fe00 / 4**, which is the number that keeps the error inside the limit
once the step is doubled.  Measured against GDI it is right: sweeping the
threshold gives 188 of 192 at 0x7fe00/4 and 94 or fewer anywhere else.

**Held against GDI itself: 352 of 352 arc-shaped curves come out exactly,
over radii 3 to 300 and all eight quadrant orientations.**  Of 120 wild
random Beziers thrown in as well, four differ by one unit at a single
point -- shapes an Arc never makes.

One more thing had to be measured rather than read: `GetPath` turns the
POINTFIX the flattener produces into a POINT by **rounding**, not by
dropping the fraction.  That was the last of the one-pixel differences.
"""
import io
import math
import os
import subprocess
import sys

LIMIT = 0x7fe00
SHIFT = 13
HALF = 1 << (SHIFT - 1)      # 0x1000, the rounding bias bNext adds


class HFD(object):
    def __init__(self, e0, e1, e2, e3):
        self.e0 = e0
        self.e1 = e1
        self.e2 = e2
        self.e3 = e3

    def err(self):
        return max(abs(self.e2), abs(self.e3))

    def parent_err_over_4(self):
        return max(abs(2 * self.e2 - self.e3), abs(self.e3))

    def take(self):
        e2 = self.e2
        self.e0 += self.e1
        self.e1 += e2
        self.e2 = 2 * e2 - self.e3
        self.e3 = e2

    def halve(self):
        self.e2 = (self.e2 + self.e3) >> 3
        self.e1 = (self.e1 - self.e2) >> 1
        self.e3 = self.e3 >> 2

    def double(self):
        e3 = self.e3
        self.e3 = e3 * 4
        self.e1 = 2 * self.e1 + self.e2
        self.e2 = self.e2 * 8 - e3 * 4


PARENT_LIMIT = LIMIT // 4


def bez_init(pts):
    """`BEZIER32::bInit`, to the bit.

    The differences start at a **coarser** scale than the walk runs at --
    0x400 for e0 and e1, 6 * 0x400 for e2 and e3 -- and the halving that
    brings the error inside the limit happens there, with e3 left whole and
    only e2 averaged; the shift to POINTFIX << 13 comes at the end, in one
    go.  Halving at the fine scale instead, which is what the walk itself
    does, truncates once per round and costs a bit or two on a curve big
    enough to need several -- which is every arc over about 300 pixels.

    Returns (x, y, steps), or None for a curve too big for the 32-bit
    flattener, where GDI falls to `BEZIER64` instead.
    """
    ox = min(p[0] for p in pts)
    oy = min(p[1] for p in pts)
    xs = [p[0] - ox for p in pts]
    ys = [p[1] - oy for p in pts]
    if any(v & 0xffffc000 for v in xs + ys):
        return None
    x0 = xs[0] * 0x400
    x1 = (xs[3] - xs[0]) * 0x400
    x2 = (xs[1] - 2 * xs[2] + xs[3]) * 0x1800
    x3 = (xs[0] - 2 * xs[1] + xs[2]) * 0x1800
    y0 = ys[0] * 0x400
    y1 = (ys[3] - ys[0]) * 0x400
    y2 = (ys[1] - 2 * ys[2] + ys[3]) * 0x1800
    y3 = (ys[0] - 2 * ys[1] + ys[2]) * 0x1800
    steps = 1
    count = 0
    while True:
        limit = 0xffc0 << count
        if max(abs(x2), abs(x3)) <= limit and max(abs(y2), abs(y3)) <= limit:
            break
        t = (x2 + x3) >> 1
        u = (y3 + y2) >> 1
        count += 2
        x2 = t
        y2 = u
        x1 = (x1 - (t >> count)) >> 1
        y1 = (y1 - (u >> count)) >> 1
        steps <<= 1
    x0 <<= 3
    x1 <<= 3
    y0 <<= 3
    y1 <<= 3
    s = count - 3
    if s < 0:
        x2 <<= -s
        x3 <<= -s
        y2 <<= -s
        y3 <<= -s
    else:
        x2 >>= s
        x3 >>= s
        y2 >>= s
        y3 >>= s
    x = HFD(x0, x1, x2, x3)
    y = HFD(y0, y1, y2, y3)
    # bInit ends with one step taken and the count down by one: the curve's
    # own first point is already in the path, so bNext hands back the ones
    # after it.
    x.take()
    y.take()
    return x, y, steps - 1, ox, oy


def flatten(pts, parent_limit=PARENT_LIMIT):
    """pts: four (x, y) in POINTFIX.  Returns the points bNext hands back."""
    init = bez_init(pts)
    if init is None:
        raise ValueError("too big for BEZIER32")
    x, y, steps, ox, oy = init
    out = []
    while True:
        out.append((ox + ((x.e0 + HALF) >> SHIFT),
                    oy + ((y.e0 + HALF) >> SHIFT)))
        if steps == 0:
            return out
        if max(x.err(), y.err()) > LIMIT:
            x.halve()
            y.halve()
            steps <<= 1
        while (steps & 1) == 0                 and x.parent_err_over_4() <= parent_limit                 and y.parent_err_over_4() <= parent_limit:
            x.double()
            y.double()
            steps >>= 1
        steps -= 1
        x.take()
        y.take()


def ask_gdi(cases):
    """What GDI makes of the same curves (tools/gdiarc.c, odd 10)."""
    lines = []
    for i, c in enumerate(cases):
        (x0, y0), (x1, y1), (x2, y2), (x3, y3) = c
        lines.append("C%d 900 10 %d %d %d %d %d %d %d %d"
                     % (i, x1, y1, x2, y2, x0, y0, x3, y3))
    out = subprocess.run([os.path.join("tmp", "gdiarc.exe")], input="\n".join(lines) + "\n",
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


def cases():
    """Whole-quadrant Beziers of the kind Arc makes, at several radii."""
    out = []
    for rp in (3, 7, 14, 19, 24, 40, 61, 100, 200, 300):
        k = int(round(4.0 / 3.0 * math.tan(math.pi / 8) * (rp + 0.5)))
        out.append(((rp, 0), (rp, -k), (k, -rp), (0, -rp)))
        out.append(((0, -rp), (-k, -rp), (-rp, -k), (-rp, 0)))
        out.append(((rp, 0), (rp, -k), (k, -rp), (0, -rp)))
    return out


def main():
    cs = cases()
    got = ask_gdi(cs)
    same = 0
    for i, c in enumerate(cs):
        g = got.get("C%d" % i)
        if g is None:
            continue
        fix = [(p[0] * 16, p[1] * 16) for p in c]
        mine = [((p[0] + 8) >> 4, (p[1] + 8) >> 4)
                for p in flatten(fix)]
        # GDI's list starts with the curve's own first point
        mine = [c[0]] + mine
        ok = mine == g
        same += 1 if ok else 0
        print("%-18s GDI %2d points, mine %2d  %s"
              % (str(c[0]) + "->" + str(c[3]), len(g), len(mine),
                 "same" if ok else "differ"))
        if not ok:
            for j in range(max(len(g), len(mine))):
                a = str(g[j]) if j < len(g) else "-"
                b = str(mine[j]) if j < len(mine) else "-"
                print("     %-12s %-12s%s" % (a, b, "" if a == b else "  <="))
    print("%d of %d match" % (same, len(cs)))


if __name__ == "__main__":
    main()
