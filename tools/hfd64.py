#!/usr/bin/env python3
u"""GDI's **64-bit** Bezier flattener, `BEZIER64`, written out from the
decompilation.

    python tools/hfd64.py           # hold it against GDI itself

`BEZIER32` (tools/hfd.py) keeps its differences in a 32-bit accumulator and
holds the control points relative to the curve's own bounding box in
fourteen bits, so it takes a curve up to 1023 pixels a side and no further.
`pprFlattenRec` tries it first and falls to this one when `bInit` says no --
which is every arc over 1023 pixels of radius, and zooming into any drawing
far enough gets there.

The shape is different.  `BEZIER32` walks the curve once; `BEZIER64` keeps
**two** walks: a coarse one over the whole curve (the *parent*), and, for
each of its steps, a fine one over the piece that step covers (the *child*).
The parent's state is turned back into four control points
(`HFDBASIS64::vUntransform`) and the child is started from those.  Both are
Hermite forward differences at **POINTFIX << 28**, and the two use different
limits: the parent splits until its second differences fall under
0x300000000001, the child until they fall under the tolerance
`pprFlattenRec` hands in (`gpeqErrorLow`).

    HFDBASIS64::vInit(a, b, c, d)
        e0 = a << 28                     e1 = (d - a) << 28
        e2 = 6 * (d - 2c + b) << 28      e3 = 6 * (a - 2b + c) << 28

    HFDBASIS64::vUntransform()  ->  the four points back again
        t  = 6*e1 - e2
        p0 = (e0 + 2^27) >> 28
        p1 = (e0 + 2^27 + trunc((t - 2*e3) / 18)) >> 28
        p2 = (e0 + 2^27 + trunc((2*t - e3) / 18)) >> 28
        p3 = (e0 + 2^27 + e1) >> 28

    HFDBASIS64::vParentError()  ->  max(|8*e2 - 4*e3|, |4*e3|)
"""
import os
import subprocess
import sys

PARENT_LIMIT = 0x300000000001
SHIFT = 28
HALF = 1 << (SHIFT - 1)


def _big(a, b):
    a = -a if a < 0 else a
    b = -b if b < 0 else b
    return a if a > b else b


class HFD64(object):
    def __init__(self, a, b, c, d):
        self.e0 = a << SHIFT
        self.e1 = (d - a) << SHIFT
        self.e2 = 6 * (d - 2 * c + b) << SHIFT
        self.e3 = 6 * (a - 2 * b + c) << SHIFT

    def err(self):
        return _big(self.e2, self.e3)

    def parent_err(self):
        return _big(8 * self.e2 - 4 * self.e3, 4 * self.e3)

    def take(self):
        e2 = self.e2
        self.e0 += self.e1
        self.e1 += e2
        self.e2 = 2 * e2 - self.e3
        self.e3 = e2

    def halve(self):
        e2 = (self.e2 + self.e3) >> 3
        self.e1 = (self.e1 - e2) >> 1
        self.e3 = self.e3 >> 2
        self.e2 = e2

    def double(self):
        self.e3 = self.e3 << 2
        e2 = self.e2
        self.e1 = e2 + self.e1 * 2
        self.e2 = e2 * 8 - self.e3

    def untransform(self):
        """The four control points this state stands for."""
        t = self.e1 * 6 - self.e2
        u = t * 2 - self.e3
        v = t - self.e3 * 2
        v = -((-v) // 18) if v < 0 else v // 18
        u = -((-u) // 18) if u < 0 else u // 18
        base = self.e0 + HALF
        return (base >> SHIFT, (base + v) >> SHIFT, (base + u) >> SHIFT,
                (base + self.e1) >> SHIFT)


def flatten(pts, err):
    """pts: four (x, y) in POINTFIX.  Returns the points bNext hands back --
    the curve's own first point is not among them, the way `BEZIER32` leaves
    it out too."""
    px = HFD64(pts[0][0], pts[1][0], pts[2][0], pts[3][0])
    py = HFD64(pts[0][1], pts[1][1], pts[2][1], pts[3][1])
    parent = 1
    while not (px.err() < PARENT_LIMIT and py.err() < PARENT_LIMIT):
        px.halve()
        py.halve()
        parent <<= 1
    child = 0
    cx = cy = None
    out = []
    while True:
        if child == 0:
            ux = px.untransform()
            uy = py.untransform()
            cx = HFD64(ux[0], ux[1], ux[2], ux[3])
            cy = HFD64(uy[0], uy[1], uy[2], uy[3])
            child = 1
            while not (cx.err() <= err and cy.err() <= err):
                child *= 2
                cx.halve()
                cy.halve()
            parent -= 1
            if parent != 0:
                px.take()
                py.take()
                if not (px.err() < PARENT_LIMIT and py.err() < PARENT_LIMIT):
                    parent <<= 1
                    px.halve()
                    py.halve()
                while ((parent & 1) == 0
                       and px.parent_err() < PARENT_LIMIT
                       and py.parent_err() < PARENT_LIMIT):
                    px.double()
                    py.double()
                    parent >>= 1
        cx.take()
        cy.take()
        out.append(((cx.e0 + HALF) >> SHIFT, (cy.e0 + HALF) >> SHIFT))
        child -= 1
        if child == 0 and parent == 0:
            return out
        if not (cx.err() <= err and cy.err() <= err):
            child *= 2
            cx.halve()
            cy.halve()
        while (child & 1) == 0:
            if cx.parent_err() > err or cy.parent_err() > err:
                break
            cx.double()
            cy.double()
            child >>= 1


def ask_gdi(cases, size):
    """GDI's own flattening of the same curves (tools/gdiarc.c, odd 10)."""
    lines = []
    for i, c in enumerate(cases):
        (x0, y0), (x1, y1), (x2, y2), (x3, y3) = c
        lines.append("C%d %d 10 %d %d %d %d %d %d %d %d"
                     % (i, size, x1, y1, x2, y2, x0, y0, x3, y3))
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


def cases(rp):
    """Quarter-circle curves of the size `BEZIER64` is for."""
    import math
    out = []
    k = int(round(4.0 / 3.0 * math.tan(math.pi / 8) * (rp + 0.5)))
    out.append(((rp, 0), (rp, -k), (k, -rp), (0, -rp)))
    out.append(((0, -rp), (-k, -rp), (-rp, -k), (-rp, 0)))
    out.append(((0, rp), (k, rp), (rp, k), (rp, 0)))
    return out


def main():
    """The tolerance is the one number that is not in the decompilation --
    `gpeqErrorLow` is a pointer, and what it points at is not laid out.  So
    it is measured: try the ones the code makes plausible and see which
    reproduces GDI."""
    want = [0x7fe00 << 15, 0x300000000001, 0x300000000000, 0x7fe00 << 14,
            0x7fe00 << 16, 1 << 40, 3 << 40, 1 << 41, 0x3f800000000,
            0x7fe00 << 13, 0x7fe00 << 17]
    cs = []
    for rp in (1100, 1400, 1800):
        cs.extend(cases(rp))
    got = ask_gdi(cs, 1900)
    best = None
    for err in want:
        same = n = 0
        for i, c in enumerate(cs):
            g = got.get("C%d" % i)
            if not g:
                continue
            n += 1
            fix = [(p[0] * 16, p[1] * 16) for p in c]
            mine = [c[0]] + [((p[0] + 8) >> 4, (p[1] + 8) >> 4)
                             for p in flatten(fix, err)]
            if mine == g:
                same += 1
        print("tolerance 0x%x: %d / %d" % (err, same, n))
        if best is None or same > best[0]:
            best = (same, err)
    print("best: 0x%x with %d" % (best[1], best[0]))


if __name__ == "__main__":
    main()
