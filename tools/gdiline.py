#!/usr/bin/env python3
u"""`bLines`: how GDI turns a POINTFIX polyline into pixels.

Out of `win32kfull.sys` at 1401210c0 (see `decomp/gdi/`).  Every line GDI
paints -- a stroked path, a `LineTo`, the flattened pieces of an arc --
goes through this one function, and it works in sixteenths, not in whole
pixels, which is why stroking the rounded points never matched.

What it does, once the bookkeeping is unwound:

1. **Put the line in the first octant.**  Swap the ends so x grows (flag
   0x20 remembers that), mirror y if it falls (0x08), and swap the axes if
   y is the longer one (0x05).  `gaflRound` then says, for that octant,
   which way a tie rounds (0x8000) and which end pixel is in (0x80).
2. **Bresenham in sixteenths.**  The error starts at
   `((mf + 8) * G - Mf * g) >> 4`, where G and g are the two deltas and Mf,
   mf the fractional parts of the start; the `+ 8` is the half pixel that
   makes the minor axis round to nearest.
3. **Decide the two ends.**  Whether the first and last whole major
   coordinate are painted depends on where the ends sit inside their
   pixels -- which is the part no rule of thumb gets right.

Measured against GDI itself (`tools/gdiarc.c` odd 11): see `main`.
"""
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

# gaflRound at 14036ec80, indexed by (flags >> 2) & 7 -- that is
# (major is y) | (y mirrored) << 1 | (diagonal) << 2.  The two impossible
# combinations hold -1.
GAFL_ROUND = (0x8080, 0x8080, 0x80, 0x8000, 0x8000, 0xffffffff,
              0x80, 0xffffffff)


def seg(p0, p1, out):
    """One line of the polyline, in POINTFIX, painted into `out`."""
    x0, y0 = p0
    x1, y1 = p1
    if x0 <= x1:
        fl = 0
        xlo, ylo, xhi, yhi = x0, y0, x1, y1
    else:
        fl = 0x20
        xlo, ylo, xhi, yhi = x1, y1, x0, y0
    if yhi < ylo:
        ylo = -ylo
        yhi = -yhi
        fl |= 8
    big = xhi - xlo                       # the x delta
    small = yhi - ylo                     # the y delta
    major, minor = xlo, ylo
    if big <= small:
        if big == small:
            fl |= 0x10                    # exactly diagonal
        else:
            fl |= 5                       # y is the longer axis
            big, small = small, big
            major, minor = ylo, xlo
    fl |= GAFL_ROUND[(fl >> 2) & 7]
    down = 1 if fl & 0x80 else 0

    mw = major >> 4
    nw = minor >> 4
    mf = major & 0xf
    nf = minor & 0xf

    num = (nf + 8) * big - mf * small
    if fl & 0x8000:
        num -= 1
    err = num >> 4

    end_mf = (big + mf) & 0xf
    end_nf = (small + nf) & 0xf
    n = (big + mf) >> 4

    if (fl & 0x20) == 0:
        top = n - 1
        if end_mf != 0:
            if end_nf == 0:
                if (end_mf - down) + 8 > 0xf:
                    top = n
            elif abs(end_nf - 8) <= end_mf:
                top = n
        first = None
        if (fl & 0x90) == 0x90:
            if end_mf != 0 and end_nf == end_mf + 8:
                top -= 1
            if mf != 0 and nf == mf + 8:
                first = 0
        if first is None:
            first = 0
            if mf != 0:
                if nf == 0:
                    first = 1 if (mf - down) + 8 > 0xf else 0
                elif abs(nf - 8) <= mf:
                    first = 1
    else:
        top = n
        if end_nf == 0:
            if (end_mf - down) + 8 > 0xf:
                top += 1
        elif abs(end_nf - 8) + end_mf > 0x10:
            top += 1
        first = None
        if (fl & 0x90) == 0x10:
            if end_nf != 0 and end_mf == end_nf + 8:
                top += 1
            if nf != 0 and mf == nf + 8:
                first = 2
        if first is None:
            first = 1
            if nf == 0:
                if (mf - down) + 8 >= 0x10:
                    first = 2
            elif abs(nf - 8) + mf > 0x10:
                first = 2

    if top < first:
        return
    base = (err + first * small) // big
    if base < 0:
        base = 0
    ref = (err + first * small) // big
    for i in range(first, top + 1):
        b = nw + base + (err + i * small) // big - ref
        a = mw + i
        if fl & 5:
            x, y = b, a
        else:
            x, y = a, b
        out.add((x, -y if fl & 8 else y))


def stroke(poly):
    out = set()
    for i in range(len(poly) - 1):
        seg(poly[i], poly[i + 1], out)
    return out


def gdi(lines):
    text = subprocess.run([os.path.join("tmp", "gdiarc.exe")],
                          input="\n".join(lines) + "\n",
                          capture_output=True, text=True).stdout
    got, k = {}, 0
    rows = text.split("\n")
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


def main():
    import random
    import hfd
    random.seed(7)
    cs = []
    for _ in range(120):
        cs.append(tuple((random.randint(-60, 60), random.randint(-60, 60))
                        for _ in range(4)))
    ask = []
    for i, c in enumerate(cs):
        (x0, y0), (x1, y1), (x2, y2), (x3, y3) = c
        ask.append("A%d 900 11 %d %d %d %d %d %d %d %d"
                   % (i, x1, y1, x2, y2, x0, y0, x3, y3))
    got = gdi(ask)
    same = n = tot = 0
    for i, c in enumerate(cs):
        g = set(got.get("A%d" % i, []))
        if not g:
            continue
        n += 1
        fix = [(p[0] * 16, p[1] * 16) for p in c]
        poly = [fix[0]] + hfd.flatten(fix)
        d = len(stroke(poly) ^ g)
        tot += d
        if d == 0:
            same += 1
    print("bLines のとおりに引くと: %d / %d 本が画素まで一致、外れは合計 %d 画素"
          % (same, n, tot))


if __name__ == "__main__":
    main()
