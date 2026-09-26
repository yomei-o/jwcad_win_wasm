#!/usr/bin/env python3
u"""Which box did the original put each whole circle in?

    JW_SHOT_ELEMS=1 ./tests/shot.exe tmp/d11.out.png tmp/d11.jww
    python tools/circbox.py tmp/refs/d11.png tmp/d11.out.png

FUN_00421490 draws a whole circle into a box 2r across and a part of one
into a box 2r+1 across, so the two rings sit half a pixel apart.  The port
puts every whole circle in the 2r box, and for `日影図` that is wrong by 223
pixels -- its one circle measures as though it had gone in the 2r+1 box.
Nothing in that element says so (docs\notes-pixels.md, 「`日影図` の円 1 つ」).

This fits the original's own ink around **every** whole circle in a drawing,
not only the ones the port gets wrong, and prints the fitted middle next to
everything the element carries.  A 2r box shows up as about -0.5,-0.5 of the
port's middle and a 2r+1 box as about 0,0.  With every circle of all fifteen
drawings in one table the rule, if there is one, can be read off.

tools/why.py has the same fit; this one runs it over the whole list.
"""
import math
import os
import sys

try:
    from PIL import Image
except ImportError:
    sys.exit("this wants Pillow: pip install pillow")

TWO_PI = 2.0 * math.pi


def elements(path):
    arcs = []
    for line in open(path):
        f = line.split()
        if not f or f[0] != "arc":
            continue
        arcs.append(dict(i=int(f[1]), cx=int(f[2]), cy=int(f[3]),
                         rpx=float(f[4]), a0=float(f[5]), sweep=float(f[6]),
                         ltype=int(f[7]), flat=float(f[8]), tilt=float(f[9]),
                         colour=int(f[10]), grp=int(f[11]), lay=int(f[12]),
                         rmm=float(f[13]),
                         flags=int(f[14]) if len(f) > 14 else 0,
                         n=int(f[15]) if len(f) > 15 else 0,
                         ux=float(f[16]) if len(f) > 16 else None,
                         uy=float(f[17]) if len(f) > 17 else None))
    return arcs


def rects(path):
    """The text rectangles, which are scored separately and so are skipped."""
    out = []
    if not os.path.exists(path):
        return out
    for line in open(path):
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        f = line.replace(",", " ").split()
        if len(f) >= 4:
            out.append(tuple(int(v) for v in f[:4]))
    return out


def fit(px, w, h, masked, bg, cx, cy, r):
    """The algebraic least-squares circle through the ink near that ring."""
    pts = []
    lo, hi = r - 2.5, r + 2.5
    for yy in range(max(0, int(cy - hi - 2)), min(h, int(cy + hi + 3))):
        for xx in range(max(0, int(cx - hi - 2)), min(w, int(cx + hi + 3))):
            if masked[yy][xx] or px[xx, yy] == bg:
                continue
            d = math.hypot(xx - cx, yy - cy)
            if lo <= d <= hi:
                pts.append((xx - cx, yy - cy))
    if len(pts) < 20:
        return None
    sxx = sxy = syy = sx = sy = n = 0.0
    sxz = syz = sz = 0.0
    for X, Y in pts:
        Z = X * X + Y * Y
        sxx += X * X; sxy += X * Y; syy += Y * Y
        sx += X; sy += Y; n += 1
        sxz += X * Z; syz += Y * Z; sz += Z
    m = [[sxx, sxy, sx], [sxy, syy, sy], [sx, sy, n]]
    v = [-sxz, -syz, -sz]
    for i in range(3):
        p = max(range(i, 3), key=lambda k: abs(m[k][i]))
        if abs(m[p][i]) < 1e-12:
            return None
        m[i], m[p] = m[p], m[i]
        v[i], v[p] = v[p], v[i]
        for k in range(i + 1, 3):
            f = m[k][i] / m[i][i]
            for j in range(i, 3):
                m[k][j] -= f * m[i][j]
            v[k] -= f * v[i]
    z = [0.0, 0.0, 0.0]
    for i in (2, 1, 0):
        t = v[i] - sum(m[i][j] * z[j] for j in range(i + 1, 3))
        z[i] = t / m[i][i]
    D, E, F = z
    ox, oy = -D / 2.0, -E / 2.0
    rr = ox * ox + oy * oy - F
    if rr <= 0:
        return None
    rad = math.sqrt(rr)
    # how well it fits: the worst distance from the fitted ring
    worst = max(abs(math.hypot(X - ox, Y - oy) - rad) for X, Y in pts)
    return ox, oy, rad, len(pts), worst


def main():
    ref, out = sys.argv[1], sys.argv[2]
    img = Image.open(ref).convert("RGB")
    w, h = img.size
    px = img.load()

    masked = [[False] * w for _ in range(h)]
    for path in ("docs/textareas.txt", out + ".mask"):
        for x0, y0, rw, rh in rects(path):
            for yy in range(max(0, y0), min(h, y0 + rh)):
                row = masked[yy]
                for xx in range(max(0, x0), min(w, x0 + rw)):
                    row[xx] = True

    seen = {}
    for y in range(0, h, 3):
        for x in range(0, w, 3):
            seen[px[x, y]] = seen.get(px[x, y], 0) + 1
    bg = max(seen, key=seen.get)

    arcs = elements(out + ".elems")
    if not arcs:
        sys.exit("no %s.elems -- run shot.exe with JW_SHOT_ELEMS=1" % out)

    name = os.path.basename(out).split(".")[0]
    circles = [a for a in arcs
               if abs(a["sweep"]) > TWO_PI - 1e-7 and a["flat"] == 1.0]
    if not circles:
        print("%-4s no whole circles" % name)
        return
    for a in circles:
        # Only a solid one goes through GDI's own ring; a dashed one is a
        # chord polyline, and its ring says nothing about the box.
        if a["ltype"] % 100 != 1:
            continue
        # A radius under about ten pixels has too few pixels to fit, and one
        # with another arc within four pixels of its ring catches that arc's
        # ink as well -- the concentric runs of d09 are all like that.
        if a["rpx"] < 10.0:
            continue
        near = [b for b in arcs
                if b is not a
                and abs(b["cx"] - a["cx"]) < 3 and abs(b["cy"] - a["cy"]) < 3
                and abs(b["rpx"] - a["rpx"]) < 4.0]
        g = fit(px, w, h, masked, bg, a["cx"], a["cy"], a["rpx"])
        if not g:
            continue
        ox, oy, rad, n, worst = g
        # -0.5,-0.5 is the 2r box (the port's own); 0,0 is the 2r+1 box
        box = "2r  " if ox < -0.35 and oy < -0.35 else \
              "2r+1" if ox > -0.15 and oy > -0.15 else "?   "
        # Where the middle falls inside its own pixel, and how wide the box
        # would be if the original took its corners from the unrounded
        # numbers rather than from a rounded radius either side of a rounded
        # middle.  If that is the rule, `span` is 2r for one and 2r+1 for the
        # other; if it is not, span will not line up with `box`.
        span = ""
        if a["ux"] is not None:
            rp = int(a["rpx"] + 0.5)
            wide = math.floor(a["ux"] + a["rpx"]) - math.floor(a["ux"] - a["rpx"])
            tall = math.floor(a["uy"] + a["rpx"]) - math.floor(a["uy"] - a["rpx"])
            span = ("  mid %+.3f,%+.3f  rfrac %.3f  span %d,%d vs 2r=%d"
                    % (a["ux"] - math.floor(a["ux"]) - 0.5,
                       a["uy"] - math.floor(a["uy"]) - 0.5,
                       a["rpx"] - math.floor(a["rpx"]), wide, tall, 2 * rp))
        print("%-4s arc %-5d %s  off %+.2f,%+.2f  rfit %7.3f  rpx %8.4f"
              "  rmm %9.4f  lt %2d  col %2d  g%d/l%-2d  flags %d  n %d"
              "  a0 %.6f  fit<=%.2f  (%d px)%s%s"
              % (name, a["i"], box, ox, oy, rad, a["rpx"], a["rmm"],
                 a["ltype"], a["colour"], a["grp"], a["lay"], a["flags"],
                 a["n"], a["a0"], worst, n, span,
                 "  [%d others on this ring]" % len(near) if near else ""))


if __name__ == "__main__":
    main()
