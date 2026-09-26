#!/usr/bin/env python3
u"""A candidate arc rasteriser, held against GDI's own pixels.

    tmp/gdiarc.exe < tmp/pix.txt > tmp/pix.out
    python tools/bezpix.py

GDI turns an Arc into cubic Beziers and strokes the flattened curve -- asked
from the inside (BeginPath / Arc / EndPath / GetPath) and confirmed by
flattening and stroking the path, which paints exactly what Arc paints.  The
port has to do the same, so the model has to be built and measured.

Measuring it through the fifteen-drawing score is too coarse to steer by: it
says 793 against 524 without saying which part is wrong.  Here the model is
run against GDI's own pixels for one arc at a time, so a change either moves
the count or it does not.

The model in `pixels` is the thing under test; everything round it is the
measuring rig.
"""
import io
import math
import sys

TWO = 2.0 * math.pi
HALF = math.pi / 2.0


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


def cases():
    out = []
    for rp in (7, 14, 19, 24, 40, 61):
        for k in range(16):
            a0 = TWO * k / 16.0
            for sw in (math.pi / 2, math.pi / 4, 1.0, 2.6):
                out.append(("%d_%d_%d" % (rp, k, int(sw * 1000)), rp, a0, sw))
    return out


def read_sets(path):
    got = {}
    lines = io.open(path, encoding="ascii", errors="replace").read().split("\n")
    k = 0
    while k < len(lines):
        head = lines[k].split()
        k += 1
        if len(head) != 2:
            continue
        tag, n = head[0], int(head[1])
        pts = set()
        for _ in range(n):
            if k >= len(lines):
                break
            p = lines[k].split()
            k += 1
            if len(p) == 2:
                pts.add((int(p[0]), int(p[1])))
        got[tag] = pts
    return got


def bres(x0, y0, x1, y1, out, last):
    """GDI's LineTo: every pixel but the far end, unless `last` is set."""
    dx = abs(x1 - x0)
    dy = abs(y1 - y0)
    sx = 1 if x1 > x0 else -1
    sy = 1 if y1 > y0 else -1
    x, y = x0, y0
    if dx >= dy:
        e = dx // 2
        for _ in range(dx):
            out.add((x, y))
            e -= dy
            if e < 0:
                y += sy
                e += dx
            x += sx
    else:
        e = dy // 2
        for _ in range(dy):
            out.add((x, y))
            e -= dx
            if e < 0:
                x += sx
                e += dy
            y += sy
    if last:
        out.add((x1, y1))
    if dx == 0 and dy == 0:
        out.add((x0, y0))


def bres_frac(x0, y0, x1, y1, out):
    """A line whose ends are not whole numbers.

    GDI strokes the flattened path with the fractions it still holds -- the
    path keeps fixed point and GetPath only rounds for the caller.  That is
    what lets its flattening be coarse (14 pieces for a 140 pixel arc, a
    sagitta of about a third of a pixel) and still land on the arc's own
    pixels: rounding the ends first would move the whole track by as much
    as the sagitta.

    Walk the longer axis a whole step at a time and take the other from the
    line, both ends included.
    """
    dx, dy = x1 - x0, y1 - y0
    n = int(math.ceil(max(abs(dx), abs(dy))))
    if n <= 0:
        out.add((rnd(x0), rnd(y0)))
        return
    for i in range(n + 1):
        t = float(i) / n
        out.add((rnd(x0 + dx * t), rnd(y0 + dy * t)))


def flat_enough(p, tol):
    """The classic test: how far the two inner control points stray from
    the chord.

    Measuring where GDI actually cuts (tools/bezcut.py) shows it halving
    recursively like this, and **adaptively** -- a full quadrant of radius
    61 comes out in eight equal pieces, while a 59 degree one keeps quarters
    except for its first, which goes to eighths.  An even split would not do
    that.  What was wrong before was the stopping test, not the halving: a
    sagitta through the middle of the curve is not what GDI asks.
    """
    (x0, y0), (x1, y1), (x2, y2), (x3, y3) = p
    ax, ay = x3 - x0, y3 - y0
    n = math.hypot(ax, ay)
    if n < 1e-12:
        return (math.hypot(x1 - x0, y1 - y0) <= tol
                and math.hypot(x2 - x0, y2 - y0) <= tol)
    d1 = abs(ax * (y0 - y1) - ay * (x0 - x1)) / n
    d2 = abs(ax * (y0 - y2) - ay * (x0 - x2)) / n
    return max(d1, d2) <= tol


def flatten(p, out, depth=0, tol=0.5):
    if depth < 24 and not flat_enough(p, tol):
        (x0, y0), (x1, y1), (x2, y2), (x3, y3) = p
        mx = (x0 + 3.0 * (x1 + x2) + x3) / 8.0
        my = (y0 + 3.0 * (y1 + y2) + y3) / 8.0
        ax, ay = (x0 + x1) / 2.0, (y0 + y1) / 2.0
        bx, by = (x1 + x2) / 2.0, (y1 + y2) / 2.0
        cx, cy = (x2 + x3) / 2.0, (y2 + y3) / 2.0
        dx2, dy2 = (ax + bx) / 2.0, (ay + by) / 2.0
        ex, ey = (bx + cx) / 2.0, (by + cy) / 2.0
        flatten(((x0, y0), (ax, ay), (dx2, dy2), (mx, my)), out, depth + 1,
                tol)
        flatten(((mx, my), (ex, ey), (cx, cy), (x3, y3)), out, depth + 1,
                tol)
        return
    out.append((p[3][0], p[3][1]))


def rnd(v):
    return int(math.floor(v + 0.5))


def control(rp, a0, sweep):
    """GDI's control points, as far as they have been worked out.

    Both ends are taken from the **ray through the point the caller gave**,
    measured from the rect's true middle -- not from the start plus the
    sweep.  That is what the port had wrong: the rounding of the far end
    was carried from the near one, so the error grew along the arc (radius
    40, sweep 2.6: GDI ends at (40,5) and the port ended at (40,6)).

    The cuts are at the quarter turns and each piece is the textbook arc
    Bezier, k = 4/3 tan(step/4), every point rounded to whole units.
    The points themselves sit on rp, but the **tangent step** is
    k*(rp + 0.5) -- read off GDI's own quadrant answers, where rp alone
    gives 10 at radius 19 and 13 at 24 where GDI has 11 and 14.
    """
    segs = []
    gx, gy = ray(rp, a0)
    ex, ey = ray(rp, a0 + sweep)
    a = math.atan2(-(gy - 0.5), gx - 0.5)
    b = math.atan2(-(ey - 0.5), ex - 0.5)
    d = 1.0 if sweep >= 0 else -1.0
    span = (b - a) * d
    while span <= 0:
        span += TWO
    while span > TWO:
        span -= TWO
    left = span
    guard = 0
    while left > 1e-12 and guard < 64:
        guard += 1
        q = a / HALF
        nxt = (math.floor(q) + 1.0) * HALF if d > 0 else (math.ceil(q) - 1.0) * HALF
        step = (nxt - a) if d > 0 else (a - nxt)
        if step < 1e-9:
            step = HALF
        if step > left:
            step = left
        b1 = a + d * step
        k = 4.0 / 3.0 * math.tan(step / 4.0) * d
        KR = k * (rp + 0.5)
        x0, y0 = rp * math.cos(a), -rp * math.sin(a)
        x3, y3 = rp * math.cos(b1), -rp * math.sin(b1)
        c1 = (x0 - KR * math.sin(a), y0 - KR * math.cos(a))
        c2 = (x3 + KR * math.sin(b1), y3 + KR * math.cos(b1))
        segs.append(((rnd(x0), rnd(y0)), (rnd(c1[0]), rnd(c1[1])),
                     (rnd(c2[0]), rnd(c2[1])), (rnd(x3), rnd(y3))))
        a = b1
        left -= step
    return segs


def pixels(rp, a0, sweep, tol=0.5):
    out = set()
    pts = []
    for seg in control(rp, a0, sweep):
        if not pts:
            pts.append((float(seg[0][0]), float(seg[0][1])))
        flatten(tuple((float(q[0]), float(q[1])) for q in seg), pts, 0, tol)
    for i in range(len(pts) - 1):
        bres_frac(pts[i][0], pts[i][1], pts[i + 1][0], pts[i + 1][1], out)
    return out


def show(rp, a0, sweep):
    """One arc, my flattened polyline against GDI's own (odd 9)."""
    gl = []
    lines = io.open("tmp/fl.out", encoding="ascii",
                    errors="replace").read().split("\n")
    k = 0
    while k < len(lines):
        head = lines[k].split()
        k += 1
        if len(head) != 2:
            continue
        n = int(head[1])
        for _ in range(n):
            if k >= len(lines):
                break
            q = lines[k].split()
            k += 1
            if len(q) == 2:
                gl.append((int(q[0]), int(q[1])))
    pts = []
    for seg in control(rp, a0, sweep):
        if not pts:
            pts.append((float(seg[0][0]), float(seg[0][1])))
        flatten(tuple((float(q[0]), float(q[1])) for q in seg), pts, 0, tol)
    mine = [(rnd(x), rnd(y)) for x, y in pts]
    print("GDI has %d points, mine %d" % (len(gl), len(mine)))
    for i in range(max(len(gl), len(mine))):
        a = str(gl[i]) if i < len(gl) else "-"
        b = str(mine[i]) if i < len(mine) else "-"
        print("   %-12s %-12s%s" % (a, b, "" if a == b else "   <="))


def main():
    if len(sys.argv) > 1 and sys.argv[1] == "tol":
        got = read_sets("tmp/pix.out")
        cs = cases()
        for tol in (1.2, 0.8, 0.6, 0.5, 0.4, 0.3):
            tot = same = n = 0
            small = smalln = 0
            for tag, rp, a0, sw in cs:
                g = got.get(tag)
                if g is None:
                    continue
                tot += 1
                m = pixels(rp, a0, sw, tol)
                d = len(m ^ g)
                n += d
                if not d:
                    same += 1
                if rp in (14, 19, 24):
                    small += d
                    smalln += len(g)
            print("tol %.1f: %3d of %d exact, %5d pixels out; radius 14-24:"
                  " %4d out of %5d (%4.1f%%)"
                  % (tol, same, tot, n, small, smalln,
                     100.0 * small / smalln if smalln else 0.0))
        return
    if len(sys.argv) > 3:
        show(int(sys.argv[1]), float(sys.argv[2]), float(sys.argv[3]))
        return
    got = read_sets("tmp/pix.out")
    cs = cases()
    tot = same = 0
    diffs = []
    for tag, rp, a0, sw in cs:
        g = got.get(tag)
        if g is None:
            continue
        tot += 1
        m = pixels(rp, a0, sw)
        d = m ^ g
        if not d:
            same += 1
        else:
            diffs.append((len(d), len(g), tag, rp, a0, sw))
    print("%d arcs: %d painted exactly like GDI" % (tot, same))
    if diffs:
        diffs.sort()
        n = sum(d[0] for d in diffs)
        print("%d pixels out over the rest, %.1f an arc"
              % (n, float(n) / len(diffs)))
        byrp = {}
        for d, ng, tag, rp, a0, sw in diffs:
            byrp[rp] = byrp.get(rp, [0, 0, 0])
            byrp[rp][0] += 1
            byrp[rp][1] += d
            byrp[rp][2] += ng
        print("")
        print("%5s %8s %10s %10s %8s"
              % ("rp", "wrong", "pixels out", "of", "a share"))
        for rp in sorted(byrp):
            k, d, ng = byrp[rp]
            print("%5d %8d %10d %10d %7.1f%%"
                  % (rp, k, d, ng, 100.0 * d / ng if ng else 0.0))


if __name__ == "__main__":
    main()
