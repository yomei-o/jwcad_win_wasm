#!/usr/bin/env python3
u"""Ask GDI for each arc's ring, and hold it against the original's ink.

    JW_SHOT_ELEMS=1 ./tests/shot.exe tmp/d14.out.png tmp/d14.jww
    python tools/arcask.py tmp/refs/d14.png tmp/d14.out.png    # writes tmp/arcs.txt
    tmp/gdiarc.exe < tmp/arcs.txt > tmp/gdiarc.out
    python tools/arcask.py tmp/refs/d14.png tmp/d14.out.png tmp/gdiarc.out

`Jw_win.exe` is decompiled but GDI is not, and the pixels come from GDI:
FUN_00421490 works out a box and two endpoints and then calls Arc().  The
port carries a table of the rings GDI draws (src/gen/circle.h) but the table
is keyed by the **radius**, and a part of a circle is one Arc call whose
ring depends on **where it starts and stops**.  That is why the remaining
score sits on partial arcs.

So ask GDI, one arc at a time, with the same box and the same endpoints the
original computes, and see whether the answer is what the original's picture
has.  If it is, the port's table is the thing to fix, and this says how.
Nothing here drives Jw_cad: tools/gdiarc.c draws into a memory bitmap.
"""
import io
import math
import os
import sys

try:
    from PIL import Image
except ImportError:
    sys.exit("this wants Pillow: pip install pillow")

TWO_PI = 2.0 * math.pi
# (radius nudge, middle dx, middle dy) -- the ways an arc is asked about
VARIANTS = [(k, dx, dy)
            for k in (0, 1, -1)
            for dx in (0, 1, -1)
            for dy in (0, 1, -1)]
NVAR = 64                       # the tag is i * NVAR + which variant


def rects(path):
    out = []
    if not os.path.exists(path):
        return out
    for line in io.open(path, encoding="utf-8", errors="replace"):
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        f = line.replace(",", " ").split()
        if len(f) >= 4:
            try:
                out.append(tuple(int(v) for v in f[:4]))
            except ValueError:
                pass
    return out


def arcs_of(path):
    out = []
    for line in io.open(path, encoding="utf-8", errors="replace"):
        f = line.split()
        if not f or f[0] != "arc":
            continue
        a = dict(i=int(f[1]), cx=int(f[2]), cy=int(f[3]), rpx=float(f[4]),
                 a0=float(f[5]), sw=float(f[6]), lt=int(f[7]),
                 flat=float(f[8]), tilt=float(f[9]),
                 ux=float(f[16]) if len(f) > 17 else None,
                 uy=float(f[17]) if len(f) > 17 else None)
        out.append(a)
    return out


def ray(rp, a):
    """Where FUN_00421490 puts the endpoint: truncated, and read as a ray."""
    x = int(rp * math.cos(a))
    y = int(rp * math.sin(a))
    return x, -y                      # screen y runs the other way


def wanted(a):
    """The arcs this one asks about: solid, round, and a *part* of a circle.
    A whole circle is two Arc calls and a question of its own -- that is
    tools/circask.py."""
    if a["lt"] % 100 != 1 or a["flat"] != 1.0:
        return False
    return abs(a["sw"]) <= TWO_PI - 1e-7


def main():
    ref, out = sys.argv[1], sys.argv[2]
    got = sys.argv[3] if len(sys.argv) > 3 else None

    arcs = [a for a in arcs_of(out + ".elems") if wanted(a)]
    if not arcs:
        sys.exit("no partial solid arcs in %s.elems" % out)

    if not got:
        # Each arc is asked about at three radii **and** nine middles.  Only
        # varying the radius is a trap: if the original's middle is a pixel
        # away, its ring is a shifted one, and of "r, r+1, r-1" the bigger
        # ring is simply the one that overlaps a shifted ring best.  Asking
        # both apart tells a bigger ring from a moved one.
        with io.open("tmp/arcs.txt", "w", encoding="ascii") as f:
            for a in arcs:
                rp0 = int(a["rpx"] + 0.5)
                for v, (k, dx, dy) in enumerate(VARIANTS):
                    rp = rp0 + k
                    if rp < 1 or rp > 9000:
                        continue
                    s = a["a0"] + a["tilt"]
                    x1, y1 = ray(rp, s)
                    x2, y2 = ray(rp, s + a["sw"])
                    if a["sw"] < 0:      # GDI always goes anticlockwise
                        x1, y1, x2, y2 = x2, y2, x1, y1
                    f.write("%d %d 1 %d %d %d %d\n"
                            % (a["i"] * NVAR + v, rp, x1, y1, x2, y2))
        print("wrote tmp/arcs.txt: %d arcs x %d ways"
              % (len(arcs), len(VARIANTS)))
        return

    # the pictures, and the mask, so that a text rectangle is left out
    a_im = Image.open(ref).convert("RGB")
    b_im = Image.open(out).convert("RGB")
    w, h = a_im.size
    pa, pb = a_im.load(), b_im.load()
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
            seen[pb[x, y]] = seen.get(pb[x, y], 0) + 1
    bg = max(seen, key=seen.get)

    by_i = dict((a["i"], a) for a in arcs)
    rings = {}
    with io.open(got, encoding="ascii", errors="replace") as f:
        lines = f.read().split("\n")
    k = 0
    while k < len(lines):
        head = lines[k].split()
        k += 1
        if len(head) != 2:
            continue
        i, n = int(head[0]), int(head[1])
        pts = []
        for _ in range(n):
            if k >= len(lines):
                break
            p = lines[k].split()
            k += 1
            if len(p) == 2:
                pts.append((int(p[0]), int(p[1])))
        rings[i] = pts

    def score_ring(a, pts, ddx, ddy):
        """How much of that ring is on the original's ink, and how much is
        not.  A ring that fits sits on ink and leaves nothing beside it."""
        on = off = 0
        for dx, dy in pts:
            x, y = a["cx"] + dx + ddx, a["cy"] + dy + ddy
            if x < 0 or x >= w or y < 0 or y >= h or masked[y][x]:
                continue
            if pa[x, y] != bg:
                on += 1
            else:
                off += 1
        return on, off

    # Only the arcs with a ring big enough to say something.  A ring of four
    # pixels can be beaten by chance: any of the twenty-seven ways will land
    # on a neighbour's ink now and then, and with twenty-seven tries one of
    # them will.  ARCASK_MIN sets the bar (24 pixels by default), and a
    # winner also has to beat the port's own answer by ARCASK_EDGE.
    least = int(os.environ.get("ARCASK_MIN", "24"))
    edge = int(os.environ.get("ARCASK_EDGE", "3"))
    tally = {}
    want = {}
    small = 0
    for i in sorted(by_i):
        best, bestv, base = None, None, None
        for v, (k, dx, dy) in enumerate(VARIANTS):
            pts = rings.get(i * NVAR + v)
            if not pts:
                continue
            if v == 0 and len(pts) < least:
                small += 1
                break
            on, off = score_ring(by_i[i], pts, dx, dy)
            if v == 0:
                base = on - off
            if best is None or on - off > best:
                best, bestv = on - off, v
        if base is None or bestv is None:
            continue
        if best - base < edge:
            bestv = 0               # nothing beat the port by enough
        k, dx, dy = VARIANTS[bestv]
        tally[(k, dx, dy)] = tally.get((k, dx, dy), 0) + 1
        want.setdefault((k, dx, dy), []).append(by_i[i])
    print("(%d arcs left out: fewer than %d ring pixels)" % (small, least))

    print("which way of asking GDI fits the original's ink best:")
    for key in sorted(tally, key=lambda kk: -tally[kk]):
        k, dx, dy = key
        name = "as the port has it" if key == (0, 0, 0) else \
               "r%+d, middle %+d,%+d" % (k, dx, dy)
        print("  %4d arcs   %s" % (tally[key], name))

    # And then what separates the groups, which is the whole question.
    big = sorted(want, key=lambda kk: -len(want[kk]))[:2]
    for k in big:
        g = want.get(k, [])
        if not g:
            continue
        print("\n== the %d that want %s" % (len(g), k))
        fr = sorted(set(round(a["rpx"] - math.floor(a["rpx"]), 3) for a in g))
        print("   radius fractions: %s" % fr[:16])
        print("   radii:  %s" % sorted(set(round(a["rpx"], 3)
                                           for a in g))[:12])
        print("   sweeps: %s" % sorted(set(round(abs(a["sw"]), 3)
                                           for a in g))[:12])
        print("   tilts:  %s" % sorted(set(round(a["tilt"], 3)
                                           for a in g))[:12])

    # The sharpest cut there is: take one radius that appears in both
    # groups, so that everything the element says is the same, and look at
    # where the middle falls inside its pixel.
    if len(big) < 2:
        return
    both = (set(round(a["rpx"], 3) for a in want[big[0]])
            & set(round(a["rpx"], 3) for a in want[big[1]]))
    for r in sorted(both, reverse=True)[:3]:
        print("\n== radius %.3f, which both of the two have" % r)
        for k in big:
            for a in want.get(k, []):
                if round(a["rpx"], 3) != r or a.get("ux") is None:
                    continue
                print("   %-12s arc %-5d  middle %+.3f,%+.3f"
                      "   a0 %+7.4f sw %+7.4f tilt %+7.4f"
                      % (k, a["i"], a["ux"] - a["cx"], a["uy"] - a["cy"],
                         a["a0"], a["sw"], a["tilt"]))


if __name__ == "__main__":
    main()
