#!/usr/bin/env python3
u"""Which element does each wrong pixel belong to?

    JW_SHOT_ELEMS=1 ./tests/shot.exe tmp/d14.out.png tmp/d14.jww
    python tools/why.py tmp/refs/d14.png tmp/d14.out.png

The score (tools/scoreall.sh) says how many pixels are wrong; this says what
they are sitting on.  For every pixel that differs outside the text
rectangles it looks for the nearest element in tests/shot.exe's dump
(<out>.elems) and sorts the pixel into:

  * on an arc, near one of its two ends
  * on an arc, away from the ends
  * on a straight line
  * on a point or inside a solid
  * on nothing anyone drew

The three classes want different work: the ends are the rule for where the
walk starts and stops, the middle is the ring itself, and "on nothing" is a
pixel the port drew that the original did not (or the other way round).
"""
import math
import os
import sys

try:
    from PIL import Image
except ImportError:
    sys.exit("this wants Pillow: pip install pillow")

NEAR = 1.6                      # how far off a ring still counts as on it
ENDNEAR = 3.0                   # pixels along the ring from an end


def rects(path):
    out = []
    if not os.path.exists(path):
        return out
    for line in open(path):
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        f = line.split()[:4]            # anything past the four is a note
        out.append(tuple(int(v) for v in f))
    return out


def elements(path):
    arcs, segs, dots, blobs = [], [], [], []
    if not os.path.exists(path):
        return arcs, segs, dots, blobs
    for line in open(path):
        f = line.split()
        if not f or f[0].startswith("#"):
            continue
        if f[0] == "arc":
            arcs.append((int(f[1]), float(f[2]), float(f[3]), float(f[4]),
                         float(f[5]), float(f[6]), int(f[7]),
                         " ".join(f[1:])))
        elif f[0] == "seg":
            segs.append((int(f[1]), float(f[2]), float(f[3]), float(f[4]),
                         float(f[5]), int(f[6])))
        elif f[0] == "dot":
            dots.append((int(f[1]), float(f[2]), float(f[3])))
        elif f[0] == "blob":
            blobs.append((int(f[1]), float(f[2]), float(f[3]), float(f[4]),
                          float(f[5])))
    return arcs, segs, dots, blobs


def on_arc(px, py, a):
    """(distance from the ring, distance along it from the nearer end)."""
    _, cx, cy, r, a0, sweep = a[:6]
    dx, dy = px - cx, -(py - cy)
    d = math.hypot(dx, dy)
    off = abs(d - r)
    if off > NEAR:
        return None
    if sweep == 0.0:
        return off, 1e9                      # a whole circle has no ends
    t = math.atan2(dy, dx)
    lo, hi = (a0, a0 + sweep) if sweep > 0 else (a0 + sweep, a0)
    span = hi - lo
    u = (t - lo) % (2 * math.pi)
    if u > span:                             # outside the sweep altogether
        past = min(u - span, 2 * math.pi - u)
        return off, -past * r
    return off, min(u, span - u) * r


def best_arc(x, y, arcs):
    """The arc the pixel most likely belongs to.  One whose sweep covers the
    pixel beats one whose ring merely passes through it, however close that
    other ring is -- otherwise a pixel that is plainly part of a door swing
    gets blamed on a circle somewhere else that happens to graze it."""
    best = None
    for a in arcs:
        r = on_arc(x, y, a)
        if r is None:
            continue
        key = (r[1] < 0, r[0])               # covering first, then nearest
        if best is None or key < best[0]:
            best = (key, r[0], r[1], a[0])
    return best


def on_seg(px, py, s):
    _, x0, y0, x1, y1, _ = s
    vx, vy = x1 - x0, y1 - y0
    n = vx * vx + vy * vy
    if n == 0:
        return math.hypot(px - x0, py - y0)
    t = ((px - x0) * vx + (py - y0) * vy) / n
    t = max(0.0, min(1.0, t))
    return math.hypot(px - (x0 + t * vx), py - (y0 + t * vy))


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    ref, out = sys.argv[1], sys.argv[2]
    a = Image.open(ref).convert("RGB")
    b = Image.open(out).convert("RGB")
    if a.size != b.size:
        sys.exit("different sizes: %s %s" % (a.size, b.size))
    w, h = a.size
    pa, pb = a.load(), b.load()

    masked = [[False] * w for _ in range(h)]
    for path in ("docs/textareas.txt", out + ".mask"):
        for x, y, rw, rh in rects(path):
            for yy in range(max(0, y), min(h, y + rh)):
                row = masked[yy]
                for xx in range(max(0, x), min(w, x + rw)):
                    row[xx] = True

    arcs, segs, dots, blobs = elements(out + ".elems")
    if not arcs and not segs:
        sys.exit("no %s.elems -- run shot.exe with JW_SHOT_ELEMS=1" % out)

    # the background of the drawing area, so that a wrong pixel can be called
    # one the port put down (and the original did not) or the other way round
    seen = {}
    for y in range(0, h, 3):
        for x in range(0, w, 3):
            seen[pb[x, y]] = seen.get(pb[x, y], 0) + 1
    bg = max(seen, key=seen.get)

    order = ("arc end", "arc middle", "arc outside the sweep", "line",
             "point", "solid", "nothing")
    tally = dict((k, [0, 0]) for k in order)    # [ours only, theirs only]
    worst = []
    for y in range(h):
        for x in range(w):
            if masked[y][x] or pa[x, y] == pb[x, y]:
                continue
            side = 0 if pb[x, y] != bg else 1
            best = best_arc(x + 0.0, y + 0.0, arcs)
            if best is not None:
                _, off, along, which = best
                if along < 0:
                    tally["arc outside the sweep"][side] += 1
                elif along <= ENDNEAR:
                    tally["arc end"][side] += 1
                else:
                    tally["arc middle"][side] += 1
                worst.append((x, y, "arc %d" % which, off, along))
                continue
            near = min((on_seg(x, y, s), s[0]) for s in segs) if segs \
                else (1e9, -1)
            if near[0] <= NEAR:
                tally["line"][side] += 1
                worst.append((x, y, "seg %d" % near[1], near[0], 0.0))
                continue
            # a point wears a ring of up to 3 pixels; a solid fills a box
            hit = None
            for i2, px2, py2 in dots:
                if abs(x - px2) <= 4 and abs(y - py2) <= 4:
                    hit = ("point", "dot %d" % i2)
                    break
            if hit is None:
                for i2, x0, y0, x1, y1 in blobs:
                    if x0 - 1 <= x <= x1 + 1 and y0 - 1 <= y <= y1 + 1:
                        hit = ("solid", "blob %d" % i2)
                        break
            if hit is not None:
                tally[hit[0]][side] += 1
                worst.append((x, y, hit[1], 0.0, 0.0))
            else:
                tally["nothing"][side] += 1
                worst.append((x, y, "-", 0.0, 0.0))

    total = sum(sum(v) for v in tally.values())
    print("%s against %s: %d wrong pixels outside the text" % (out, ref, total))
    print("  %-22s %5s %7s %7s" % ("", "all", "ours", "theirs"))
    for k in order:
        n = sum(tally[k])
        if n:
            print("  %-22s %5d %7d %7d  (%4.1f%%)"
                  % (k, n, tally[k][0], tally[k][1], 100.0 * n / max(1, total)))
    # The circle the original actually drew, fitted to its own ink: take
    # every inked pixel of the reference within a couple of pixels of the
    # ring the port drew and solve the least squares circle through them
    # (the algebraic fit: x^2+y^2 + Dx + Ey + F = 0).  If the middle or the
    # radius comes out somewhere else, that is where to look.
    def fit(a):
        _, cx, cy, r = a[0], a[1], a[2], a[3]
        pts = []
        lo, hi = r - 2.5, r + 2.5
        for yy in range(max(0, int(cy - hi - 2)), min(h, int(cy + hi + 3))):
            for xx in range(max(0, int(cx - hi - 2)), min(w, int(cx + hi + 3))):
                if masked[yy][xx] or pa[xx, yy] == bg:
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
        # Gauss with partial pivoting, three unknowns
        for i2 in range(3):
            p2 = max(range(i2, 3), key=lambda k: abs(m[k][i2]))
            if abs(m[p2][i2]) < 1e-12:
                return None
            m[i2], m[p2] = m[p2], m[i2]
            v[i2], v[p2] = v[p2], v[i2]
            for k in range(i2 + 1, 3):
                f = m[k][i2] / m[i2][i2]
                for j2 in range(i2, 3):
                    m[k][j2] -= f * m[i2][j2]
                v[k] -= f * v[i2]
        z = [0.0, 0.0, 0.0]
        for i2 in (2, 1, 0):
            t = v[i2] - sum(m[i2][j2] * z[j2] for j2 in range(i2 + 1, 3))
            z[i2] = t / m[i2][i2]
        D, E, F = z
        ox, oy = -D / 2.0, -E / 2.0
        rr = ox * ox + oy * oy - F
        if rr <= 0:
            return None
        return ox, oy, math.sqrt(rr), len(pts)

    # and which arcs the ring pixels belong to, worst first: a ring that is
    # a pixel out shows up as a long run on one element
    per = {}
    for x, y, what, off, along in worst:
        if what.startswith("arc "):
            per[int(what[4:])] = per.get(int(what[4:]), 0) + 1
    if per:
        by = dict((a[0], a) for a in arcs)
        print("  the arcs with the most wrong pixels:")
        for i, n in sorted(per.items(), key=lambda kv: -kv[1])[:8]:
            a = by.get(i)
            print("    %4d pixels  arc %s" % (n, a[7] if a else "?"))
            if not a:
                continue
            # the radius the two sides imply, to say whether the original's
            # ring is bigger, smaller or just turned
            for side, name in ((0, "ours  "), (1, "theirs")):
                rs = [math.hypot(x - a[1], y - a[2])
                      for x, y, what, off, along in worst
                      if what == "arc %d" % i
                      and (0 if pb[x, y] != bg else 1) == side]
                if rs:
                    print("        %s %3d pixels, radius %.2f..%.2f"
                          " (the port drew %.2f, rounded to %d)"
                          % (name, len(rs), min(rs), max(rs), a[3],
                             int(a[3] + 0.5)))
            g = fit(a)
            if g:
                print("        the original's own ink fits a circle at"
                      " %+.2f,%+.2f of the port's middle, radius %.2f"
                      " (%d pixels)" % (g[0], g[1], g[2], g[3]))

    # every wrong pixel of one arc, as offsets from its centre, so that the
    # two rings can be laid out side by side (WHY_ARC=<i>)
    if os.environ.get("WHY_ARC") and per:
        i = int(os.environ["WHY_ARC"])
        a = dict((q[0], q) for q in arcs).get(i)
        if a:
            print("  arc %d at %d,%d, the port's radius %.4f:" %
                  (i, a[1], a[2], a[3]))
            for side, name in ((0, "ours"), (1, "theirs")):
                pts = sorted((x - a[1], y - a[2]) for x, y, what, o2, l2
                             in worst if what == "arc %d" % i
                             and (0 if pb[x, y] != bg else 1) == side)
                print("    %s:" % name)
                for dx, dy in pts:
                    print("      %4d %4d   r=%.3f" % (dx, dy,
                                                      math.hypot(dx, dy)))

    # a picture of one patch of both, for when the numbers are not enough
    #   WHY_BOX=x0,y0,x1,y1 python tools/why.py ref out
    if os.environ.get("WHY_BOX"):
        x0, y0, x1, y1 = (int(v) for v in os.environ["WHY_BOX"].split(","))
        print("  # both drew it, T theirs only, O ours only  (%d,%d)-(%d,%d)"
              % (x0, y0, x1, y1))
        for yy in range(max(0, y0), min(h, y1 + 1)):
            row = ""
            for xx in range(max(0, x0), min(w, x1 + 1)):
                ta = pa[xx, yy] != bg
                tb = pb[xx, yy] != bg
                row += "#" if ta and tb else "T" if ta else "O" if tb else "."
            print("  %5d %s" % (yy, row))

    if os.environ.get("WHY_LIST"):
        for x, y, what, off, along in worst[:int(os.environ["WHY_LIST"])]:
            print("  %4d,%-4d %-10s off=%.2f along=%.1f" %
                  (x, y, what, off, along))


main()
