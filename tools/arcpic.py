#!/usr/bin/env python3
u"""Print the pixels round one arc, the original beside the port.

    JW_SHOT_ELEMS=1 ./tests/shot.exe tmp/d14.out.png tmp/d14.jww
    python tools/arcpic.py tmp/refs/d14.png tmp/d14.out.png 1656

Every reading of the remaining arcs has gone through a tally -- how many of
some ring's pixels land on ink.  A tally cannot tell "the original drew this
arc a pixel bigger" from "the original drew something else there", and the
two have opposite answers.  So look at the pixels.

Each picture is the square of side 2r+7 about the middle the port worked
out.  `#` is ink, `.` is paper, `+` marks the middle, and in the third
picture `O` is ink only the original has and `P` ink only the port has.
"""
import io
import math
import os
import sys

TWO_PI = 2.0 * math.pi

try:
    from PIL import Image
except ImportError:
    sys.exit("this wants Pillow: pip install pillow")


def arcs_of(path):
    out = {}
    for line in io.open(path, encoding="utf-8", errors="replace"):
        f = line.split()
        if not f or f[0] != "arc":
            continue
        out[int(f[1])] = dict(i=int(f[1]), cx=int(f[2]), cy=int(f[3]),
                              rpx=float(f[4]), a0=float(f[5]), sw=float(f[6]),
                              lt=int(f[7]), flat=float(f[8]),
                              tilt=float(f[9]), col=int(f[10]),
                              grp=int(f[11]), lay=int(f[12]))
    return out


def main():
    ref, out, which = sys.argv[1], sys.argv[2], int(sys.argv[3])
    arcs = arcs_of(out + ".elems")
    a = arcs.get(which)
    if not a:
        sys.exit("no arc %d in %s.elems" % (which, out))
    a_im = Image.open(ref).convert("RGB")
    b_im = Image.open(out).convert("RGB")
    w, h = a_im.size
    pa, pb = a_im.load(), b_im.load()
    seen = {}
    for y in range(0, h, 3):
        for x in range(0, w, 3):
            seen[pb[x, y]] = seen.get(pb[x, y], 0) + 1
    bg = max(seen, key=seen.get)

    rp = int(a["rpx"] + 0.5)
    m = rp + 3
    cx, cy = a["cx"], a["cy"]
    print("arc %d  middle %d,%d  r %.4f px (rp %d)  sweep %.4f  tilt %.4f"
          % (which, cx, cy, a["rpx"], rp, a["sw"], a["tilt"]))
    print("colour %d  layer %d/%d  line type %d  flat %.3f"
          % (a["col"], a["grp"], a["lay"], a["lt"], a["flat"]))

    def cell(pic, x, y):
        if x < 0 or x >= w or y < 0 or y >= h:
            return " "
        return "#" if pic[x, y] != bg else "."

    for title, pic in (("the original", pa), ("the port", pb)):
        print("")
        print("--- %s" % title)
        for y in range(cy - m, cy + m + 1):
            row = []
            for x in range(cx - m, cx + m + 1):
                c = cell(pic, x, y)
                if x == cx and y == cy:
                    c = "+"
                row.append(c)
            print("   " + "".join(row))

    print("")
    print("--- O = only the original, P = only the port")
    for y in range(cy - m, cy + m + 1):
        row = []
        for x in range(cx - m, cx + m + 1):
            ca, cb = cell(pa, x, y), cell(pb, x, y)
            if x == cx and y == cy:
                row.append("+")
            elif ca == "#" and cb == "#":
                row.append("#")
            elif ca == "#":
                row.append("O")
            elif cb == "#":
                row.append("P")
            else:
                row.append(".")
        print("   " + "".join(row))

    # And the radius each side's ink sits at, measured from the middle the
    # port used, over the arc's own angles only.
    print("")
    print("ink by distance from the middle (the arc's own quarter only):")
    st = a["a0"] + a["tilt"]
    en = st + a["sw"]
    lo, hi = (en, st) if a["sw"] < 0 else (st, en)
    for r in range(max(1, rp - 3), rp + 4):
        na = nb = 0
        for k in range(0, 721):
            t = lo + (hi - lo) * k / 720.0
            x = int(round(cx + r * math.cos(t)))
            y = int(round(cy - r * math.sin(t)))
            if 0 <= x < w and 0 <= y < h:
                na += cell(pa, x, y) == "#"
                nb += cell(pb, x, y) == "#"
        print("   r %3d   original %4d / 721   port %4d / 721" % (r, na, nb))

    # Fit the middle and the radius together.  Reading the ink at the port's
    # own middle cannot tell a ring a pixel bigger from a ring a pixel
    # across, and the two have different causes: FUN_004b8250 works the
    # radius out, FUN_004b6d60 the middle.  So walk both.
    # Is it a quarter, or the whole ring?  The 2r+2 box the original's ink
    # measures as wanting is the same rectangle as a **whole circle's** box
    # (middle +/- rp with no +1) taken about (cx+1, cy+1) with rp+1 -- and a
    # whole circle is the one thing FUN_00421490 draws that way.  If the
    # original really went round the whole ring, the ink is there to see.
    print("")
    print("the whole ring, not just the arc's own quarter:")
    for r in range(max(1, rp - 2), rp + 3):
        na = nb = 0
        for k in range(0, 1440):
            t = TWO_PI * k / 1440.0
            x = int(round(cx + r * math.cos(t)))
            y = int(round(cy - r * math.sin(t)))
            if 0 <= x < w and 0 <= y < h:
                na += cell(pa, x, y) == "#"
                nb += cell(pb, x, y) == "#"
        print("   r %3d   original %5d / 1440   port %5d / 1440" % (r, na, nb))

    print("")
    print("the middle and the radius that fit the original's ink best:")
    best = None
    for sy in range(-2, 3):
        for sx in range(-2, 3):
            for r in range(max(1, rp - 2), rp + 3):
                n = 0
                for k in range(0, 721):
                    t = lo + (hi - lo) * k / 720.0
                    x = int(round(cx + sx + r * math.cos(t)))
                    y = int(round(cy + sy - r * math.sin(t)))
                    if 0 <= x < w and 0 <= y < h and cell(pa, x, y) == "#":
                        n += 1
                if best is None or n > best[0]:
                    best = (n, sx, sy, r)
    print("   the original: middle %+d%+d  radius %d   %d / 721"
          % (best[1], best[2], best[3], best[0]))
    best = None
    for sy in range(-2, 3):
        for sx in range(-2, 3):
            for r in range(max(1, rp - 2), rp + 3):
                n = 0
                for k in range(0, 721):
                    t = lo + (hi - lo) * k / 720.0
                    x = int(round(cx + sx + r * math.cos(t)))
                    y = int(round(cy + sy - r * math.sin(t)))
                    if 0 <= x < w and 0 <= y < h and cell(pb, x, y) == "#":
                        n += 1
                if best is None or n > best[0]:
                    best = (n, sx, sy, r)
    print("   the port:     middle %+d%+d  radius %d   %d / 721"
          % (best[1], best[2], best[3], best[0]))


if __name__ == "__main__":
    main()
