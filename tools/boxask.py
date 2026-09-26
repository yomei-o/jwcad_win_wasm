#!/usr/bin/env python3
u"""Which box does each *part* of a circle go in?  Ask GDI.

    JW_SHOT_ELEMS=1 ./tests/shot.exe tmp/d14.out.png tmp/d14.jww
    python tools/boxask.py tmp/refs/d14.png tmp/d14.out.png   # writes tmp/boxes.txt
    tmp/gdiarc.exe < tmp/boxes.txt > tmp/gdibox.out
    python tools/boxask.py tmp/refs/d14.png tmp/d14.out.png tmp/gdibox.out

tools/circask.py asked this of whole circles and got a clean answer -- 2r
for 天空率表's twenty-seven, 2r+1 for 日影図's one, with the ink under
GDI's own pixels counted 206 to 4 one way and 97 to 108 the other.  The
same question has never been put for a **part** of a circle: the port puts
every one of them in the 2r+1 box, because that is what FUN_00421490's
partial arm passes, and nobody has checked.

Three boxes are asked about, all at the radius the port works out:

    2r      the whole-circle box
    2r+1    what the port uses
    2r+2    a ring half a pixel bigger, which is what the arcs of
            `Ａマンション平面例` measure as wanting

Asking three things about a big ring is a different matter from asking
twenty-seven about a small one: an earlier sweep over radius *and* middle
came out scattered across sixteen answers because a four-pixel ring will
land on a neighbour's ink by luck given enough tries.  Rings under
BOXASK_MIN pixels (60 by default) are left out for the same reason.
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
NVAR = 8   # room for the variants above
# (box mode for tools/gdiarc.c, how much to add to rp, what to call it).
# The decompilation leaves exactly one quantity free.  FUN_00421490 builds
# the rect as middle +/- rp with a +1 on the far corner for a part of a
# circle, and rp is never touched again -- so a ring that measures bigger
# than the port's cannot be a bigger *box*, it has to be a bigger **rp**.
# tools/arcrp.py says the same from the other side: the original's ink sits
# at rp+1, and on four arcs at rp+2.  These are the boxes those would make.
BOXES = [(0, 0, "2r"),
         (1, 0, "2r+1 (port)"),
         (4, 0, "2r+2"),
         (1, 1, "2r+1 @rp+1"),
         (0, 1, "2r @rp+1"),
         (1, 2, "2r+1 @rp+2")]


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


def pens_of(path):
    """The drawing's own pen widths, off the second line of the dump.

    The original hands GDI the selected pen, and a pen two pixels wide
    draws a thicker ring -- which this probe, always asking with a one
    pixel pen, would read as "the bigger box fits better".  So the width
    has to be in front of anyone reading the table.
    """
    for line in io.open(path, encoding="utf-8", errors="replace"):
        if line.startswith("# pen widths"):
            return [int(v) for v in line.split(":")[1].split()]
    return []


def arcs_of(path):
    out = []
    for line in io.open(path, encoding="utf-8", errors="replace"):
        f = line.split()
        if not f or f[0] != "arc":
            continue
        a = dict(i=int(f[1]), cx=int(f[2]), cy=int(f[3]), rpx=float(f[4]),
                 a0=float(f[5]), sw=float(f[6]), lt=int(f[7]),
                 flat=float(f[8]), tilt=float(f[9]), col=int(f[10]),
                 grp=int(f[11]), lay=int(f[12]),
                 ux=float(f[16]) if len(f) > 17 else None,
                 uy=float(f[17]) if len(f) > 17 else None)
        if a["lt"] % 100 != 1 or a["flat"] != 1.0:
            continue
        if abs(a["sw"]) > TWO_PI - 1e-7:
            continue                    # a whole one: tools/circask.py
        out.append(a)
    return out


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


def main():
    ref, out = sys.argv[1], sys.argv[2]
    got = sys.argv[3] if len(sys.argv) > 3 else None
    least = int(os.environ.get("BOXASK_MIN", "60"))

    arcs = arcs_of(out + ".elems")
    if not arcs:
        print("no partial solid arcs in %s.elems" % out)
        return

    if not got:
        with io.open("tmp/boxes.txt", "w", encoding="ascii") as f:
            for a in arcs:
                rp = int(a["rpx"] + 0.5)
                if rp < 1 or rp > 9000:
                    continue
                s = a["a0"] + a["tilt"]
                x1, y1 = ray(rp, s)
                x2, y2 = ray(rp, s + a["sw"])
                if a["sw"] < 0:
                    x1, y1, x2, y2 = x2, y2, x1, y1
                for v, (mode, dr, _) in enumerate(BOXES):
                    # The ends are rays worked out from rp, so a variant
                    # that asks about rp+1 has to ask with rp+1's ends too
                    # -- FUN_00421490 makes both from the same number.
                    if dr:
                        e1 = ray(rp + dr, s)
                        e2 = ray(rp + dr, s + a["sw"])
                        if a["sw"] < 0:
                            e1, e2 = e2, e1
                    else:
                        e1, e2 = (x1, y1), (x2, y2)
                    f.write("%d %d %d %d %d %d %d\n"
                            % (a["i"] * NVAR + v, rp + dr, mode,
                               e1[0], e1[1], e2[0], e2[1]))
        print("wrote tmp/boxes.txt: %d arcs x %d boxes" % (len(arcs),
                                                           len(BOXES)))
        return

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

    rings = {}
    lines = io.open(got, encoding="ascii", errors="replace").read().split("\n")
    k = 0
    while k < len(lines):
        head = lines[k].split()
        k += 1
        if len(head) != 2:
            continue
        tag, n = int(head[0]), int(head[1])
        pts = []
        for _ in range(n):
            if k >= len(lines):
                break
            p = lines[k].split()
            k += 1
            if len(p) == 2:
                pts.append((int(p[0]), int(p[1])))
        rings[tag] = pts

    def score(a, pts, pic=None, sx=0, sy=0):
        pic = pic or pa
        on = off = 0
        for dx, dy in pts:
            x, y = a["cx"] + dx + sx, a["cy"] + dy + sy
            if x < 0 or x >= w or y < 0 or y >= h or masked[y][x]:
                continue
            if pic[x, y] != bg:
                on += 1
            else:
                off += 1
        return on, off

    tally = {}
    rows = []
    for a in arcs:
        row = [rings.get(a["i"] * NVAR + v) for v in range(len(BOXES))]
        if not row[1] or len(row[1]) < least:
            continue
        sc = [score(a, p) if p else None for p in row]
        best = max(range(len(BOXES)),
                   key=lambda v: (sc[v][0] - sc[v][1]) if sc[v] else -1e9)
        tally[BOXES[best][2]] = tally.get(BOXES[best][2], 0) + 1
        # The control nobody ran: does the **port's own** ink match the ring
        # GDI draws for the box the port passes?  Every reading here so far
        # has compared GDI against the original and concluded the original
        # wants a bigger box.  That only means anything if the port itself
        # sits exactly on GDI's 2r+1 ring.  If it does not, the port is not
        # drawing what it thinks it is, and the original is not the odd one.
        mine = [score(a, p, pb) if p else None for p in row]
        best_mine = max(range(len(BOXES)),
                        key=lambda v: (mine[v][0] - mine[v][1])
                        if mine[v] else -1e9)
        rows.append((a, sc, best, mine, best_mine))

    pens = pens_of(out + ".elems")
    print("the drawing's pen widths 1..9: %s" % pens)
    print("%-6s %8s %3s %3s %3s %7s  %s  %s"
          % ("arc", "radius", "pen", "grp", "lay", "sweep",
             " ".join("%-13s" % b[2] for b in BOXES), "fits"))
    for a, sc, best, mine, best_mine in rows:
        cells = ["%5d/%-5d" % s if s else "%11s" % "-" for s in sc]
        c = a["col"]
        print("%-6d %8.3f %3d %3d %3d %7.4f  %s  %s"
              % (a["i"], a["rpx"], c, a["grp"], a["lay"], a["sw"],
                 " ".join("%-13s" % t for t in cells), BOXES[best][2]))
    print("\nof the %d arcs with a ring of %d pixels or more:" % (len(rows),
                                                                  least))
    for k2 in sorted(tally, key=lambda kk: -tally[kk]):
        print("   %4d fit the %s box best" % (tally[k2], k2))

    # The control nobody ran.  Every reading above compares GDI's rings with
    # the **original's** ink and concludes the original wants a bigger box.
    # That only means anything if the port itself sits exactly on the ring
    # GDI draws for the box the port passes.  FUN_00421490 passes 2r+1 and
    # nothing else, so if the port is off that ring, the port is the odd one.
    print("")
    print("the control -- the port's own ink against the same rings:")
    ctl = {}
    bad = []
    for a, sc, best, mine, best_mine in rows:
        ctl[BOXES[best_mine][2]] = ctl.get(BOXES[best_mine][2], 0) + 1
        if mine[1] and mine[1][1] > 0:
            bad.append((a, mine[1]))
    for k2 in sorted(ctl, key=lambda kk: -ctl[kk]):
        print("   %4d of the port's own arcs fit the %s box best"
              % (ctl[k2], k2))
    if bad:
        print("   the port misses some of GDI's own 2r+1 pixels:")
        for a, m in bad:
            print("      arc %-6d radius %8.3f   %4d on %4d off"
                  % (a["i"], a["rpx"], m[0], m[1]))
            # Where do the missed ones sit?  If they are all within a pixel
            # of an end, the port's end rule is what differs from GDI's; if
            # they are scattered round the ring, the ring itself is.
            pts = rings.get(a["i"] * NVAR + 1) or []
            st = a["a0"] + a["tilt"]
            en = st + a["sw"]
            lo, hi = (en, st) if a["sw"] < 0 else (st, en)
            for dx, dy in pts:
                x, y = a["cx"] + dx, a["cy"] + dy
                if x < 0 or x >= w or y < 0 or y >= h or masked[y][x]:
                    continue
                if pb[x, y] != bg:
                    continue
                t = math.atan2(-dy, dx)
                d0 = min(abs(t - lo), abs(t - lo + TWO_PI),
                         abs(t - lo - TWO_PI))
                d1 = min(abs(t - hi), abs(t - hi + TWO_PI),
                         abs(t - hi - TWO_PI))
                r = math.hypot(dx, dy)
                print("         missed %+4d%+4d  r %6.2f  %5.1f deg from "
                      "the near end" % (dx, dy, r,
                                        math.degrees(min(d0, d1))))
    else:
        print("   every arc: the port sits exactly on GDI's 2r+1 ring")

    # Bigger ring, or the same ring one pixel across?  A ring of radius rp
    # whose middle is a pixel out overlaps a concentric ring of rp+1 on the
    # side it moved to, so "2r+2 fits better" and "the middle is one out"
    # look the same from the tally above.  They are told apart by scoring
    # the port's own 2r+1 ring at a few offsets.  FUN_004b6d60 is what works
    # the middle out, and it truncates toward zero, so a sign or a half
    # pixel there would show up as exactly this.
    print("")
    print("bigger ring, or the same ring moved?  the 2r+1 ring at offsets:")
    SHIFTS = [(0, 0), (1, 0), (0, 1), (1, 1), (-1, 0), (0, -1), (-1, -1)]
    move = {}
    for a, sc, best, mine, best_mine in rows:
        row = [rings.get(a["i"] * NVAR + v) for v in range(len(BOXES))]
        if not row[1]:
            continue
        got = [(score(a, row[1], pa, sx, sy), (sx, sy)) for sx, sy in SHIFTS]
        (on, off), at = max(got, key=lambda g: g[0][0] - g[0][1])
        move[at] = move.get(at, 0) + 1
        # And the thing that would say **why**: how close the middle's
        # unrounded place is to a whole pixel.  Both the original and the
        # port work the middle out as (int)((cx - ox) / mmpp) + bx -- the
        # same expression -- so the only way they part company is a quotient
        # that lands on a whole number, where a last-bit difference (x87
        # against SSE) throws the truncation a pixel.  Arc middles sit on
        # round millimetres, so they land there far more often than a
        # scattering of points would.  If the arcs wanting +1 are the ones
        # whose fraction is near 0 or near 1, that is the reason.
        fx = a["ux"] - math.floor(a["ux"]) if a["ux"] is not None else -1.0
        fy = a["uy"] - math.floor(a["uy"]) if a["uy"] is not None else -1.0
        print("      arc %-6d radius %8.3f  best at %+d%+d  %4d on %4d off"
              "   frac x %.6f  y %.6f"
              % (a["i"], a["rpx"], at[0], at[1], on, off, fx, fy))
    for k2 in sorted(move, key=lambda kk: -move[kk]):
        print("   %4d arcs sit best with the middle at %+d%+d"
              % (move[k2], k2[0], k2[1]))

    # GDI walks a curve an octant at a time, so an end that sits close to an
    # octant boundary (a multiple of pi/4) could fall either side of it and
    # take a different run of pixels with it.  Nothing has looked at that.
    print("\nhow far each end is from the nearest eighth of a turn:")
    for a, sc, best, mine, best_mine in rows:
        s = a["a0"] + a["tilt"]
        e = s + a["sw"]
        def off(t):
            q = t / (math.pi / 4.0)
            return abs(q - round(q)) * (math.pi / 4.0)
        # and the same for the ray the truncated endpoint really makes
        rp = int(a["rpx"] + 0.5)
        rs = math.atan2(-ray(rp, s)[1], ray(rp, s)[0])
        re = math.atan2(-ray(rp, e)[1], ray(rp, e)[0])
        print("   arc %-5d %-16s start %.4f (ray %.4f)  end %.4f (ray %.4f)"
              % (a["i"], BOXES[best][2], off(s), off(rs), off(e), off(re)))


if __name__ == "__main__":
    main()
