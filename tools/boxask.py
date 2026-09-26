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
NVAR = 8
BOXES = [(0, "2r"), (1, "2r+1 (the port)"), (4, "2r+2")]


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
                for v, (mode, _) in enumerate(BOXES):
                    f.write("%d %d %d %d %d %d %d\n"
                            % (a["i"] * NVAR + v, rp, mode, x1, y1, x2, y2))
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

    def score(a, pts):
        on = off = 0
        for dx, dy in pts:
            x, y = a["cx"] + dx, a["cy"] + dy
            if x < 0 or x >= w or y < 0 or y >= h or masked[y][x]:
                continue
            if pa[x, y] != bg:
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
        tally[BOXES[best][1]] = tally.get(BOXES[best][1], 0) + 1
        rows.append((a, sc, best))

    pens = pens_of(out + ".elems")
    print("the drawing's pen widths 1..9: %s" % pens)
    print("%-6s %8s %4s %4s  %-15s %-15s %-15s  %s"
          % ("arc", "radius", "pen", "wide", BOXES[0][1], BOXES[1][1],
             BOXES[2][1], "fits"))
    for a, sc, best in rows:
        cells = ["%4d on %4d off" % s if s else "%15s" % "-" for s in sc]
        c = a["col"]
        wide = pens[c - 1] if 1 <= c <= len(pens) else 0
        print("%-6d %8.3f %4d %4d  %s %s %s  %s"
              % (a["i"], a["rpx"], c, wide, cells[0], cells[1], cells[2],
                 BOXES[best][1]))
    print("\nof the %d arcs with a ring of %d pixels or more:" % (len(rows),
                                                                  least))
    for k2 in sorted(tally, key=lambda kk: -tally[kk]):
        print("   %4d fit the %s box best" % (tally[k2], k2))

    # GDI walks a curve an octant at a time, so an end that sits close to an
    # octant boundary (a multiple of pi/4) could fall either side of it and
    # take a different run of pixels with it.  Nothing has looked at that.
    print("\nhow far each end is from the nearest eighth of a turn:")
    for a, sc, best in rows:
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
              % (a["i"], BOXES[best][1], off(s), off(rs), off(e), off(re)))


if __name__ == "__main__":
    main()
