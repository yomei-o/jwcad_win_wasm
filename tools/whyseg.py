#!/usr/bin/env python3
u"""Which straight line does each wrong pixel belong to?

    JW_SHOT_ELEMS=1 ./tests/shot.exe tmp/d06.out.png tmp/d06.jww
    python tools/whyseg.py tmp/refs/d06.png tmp/d06.out.png

tools/why.py sorts the wrong pixels into "arc", "line", "point" and so on,
and then lists the *arcs* with the most of them.  There has never been the
same listing for lines, which is what is left in `Test6` and in the dash
starts of `日影図`.  This is that listing: the segment, how many pixels are
wrong on it, which side they fall on, and the ends before they were rounded.

The seg line of shot.exe's dump carries the rounded ends and then the
unrounded ones, which is what says whether a pixel is a rounding question or
something else.
"""
import io
import math
import os
import sys

try:
    from PIL import Image
except ImportError:
    sys.exit("this wants Pillow: pip install pillow")

NEAR = 1.6                      # how far off a line still counts as on it


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


def segments(path):
    out = []
    for line in io.open(path, encoding="utf-8", errors="replace"):
        f = line.split()
        if not f or f[0] != "seg":
            continue
        s = dict(i=int(f[1]), x0=int(f[2]), y0=int(f[3]),
                 x1=int(f[4]), y1=int(f[5]), lt=int(f[6]))
        if len(f) > 10:
            s.update(ux0=float(f[7]), uy0=float(f[8]),
                     ux1=float(f[9]), uy1=float(f[10]))
        out.append(s)
    return out


def short(c):
    """A colour in as few letters as will still tell them apart."""
    named = {(255, 255, 255): "white", (0, 0, 0): "black",
             (0, 192, 192): "cyan", (192, 192, 192): "grey",
             (192, 0, 192): "pink", (0, 192, 0): "green",
             (255, 0, 0): "red", (0, 0, 255): "blue"}
    return "=" + named.get(tuple(c), "%02x%02x%02x" % tuple(c))


def dist_to(s, x, y):
    ax, ay, bx, by = s["x0"], s["y0"], s["x1"], s["y1"]
    dx, dy = bx - ax, by - ay
    n = dx * dx + dy * dy
    if n == 0:
        return math.hypot(x - ax, y - ay)
    t = ((x - ax) * dx + (y - ay) * dy) / float(n)
    if t < 0.0:
        t = 0.0
    elif t > 1.0:
        t = 1.0
    return math.hypot(x - (ax + t * dx), y - (ay + t * dy))


def main():
    ref, out = sys.argv[1], sys.argv[2]
    a = Image.open(ref).convert("RGB")
    b = Image.open(out).convert("RGB")
    w, h = a.size
    pa, pb = a.load(), b.load()

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

    segs = segments(out + ".elems")
    if not segs:
        sys.exit("no %s.elems -- run shot.exe with JW_SHOT_ELEMS=1" % out)

    per = {}
    loose = 0
    for y in range(h):
        for x in range(w):
            if masked[y][x] or pa[x, y] == pb[x, y]:
                continue
            side = 0 if pb[x, y] != bg else 1     # 0 = ours only, 1 = theirs
            best, bd = None, 1e9
            for s in segs:
                d = dist_to(s, x, y)
                if d < bd:
                    bd, best = d, s
            if best is None or bd > NEAR:
                loose += 1
                continue
            k = best["i"]
            e = per.setdefault(k, {"seg": best, "ours": [], "theirs": []})
            # both colours, because "ours" only says the port drew something
            # there -- the original may have drawn something else rather
            # than nothing, and the two cases want different answers
            e["theirs" if side else "ours"].append(
                (x, y, pb[x, y], pa[x, y]))

    total = sum(len(e["ours"]) + len(e["theirs"]) for e in per.values())
    print("%s: %d wrong pixels on lines, %d on nothing in particular"
          % (os.path.basename(out), total, loose))
    for k, e in sorted(per.items(), key=lambda kv: -(len(kv[1]["ours"])
                                                     + len(kv[1]["theirs"])))[:12]:
        s = e["seg"]
        print("  seg %-5d %4d,%-4d -> %4d,%-4d  lt %d   ours %d  theirs %d"
              % (k, s["x0"], s["y0"], s["x1"], s["y1"], s["lt"],
                 len(e["ours"]), len(e["theirs"])))
        if "ux0" in s:
            print("        before the rounding: %.3f,%.3f -> %.3f,%.3f"
                  % (s["ux0"], s["uy0"], s["ux1"], s["uy1"]))
        for name in ("ours", "theirs"):
            if e[name]:
                pts = "  ".join("%d,%d port%s orig%s"
                                % (x, y, short(c), short(d))
                                for x, y, c, d in e[name][:6])
                print("        %-6s %s%s" % (name, pts,
                                             " ..." if len(e[name]) > 6 else ""))
        if os.environ.get("WHYSEG_BOX") and e["ours"] + e["theirs"]:
            x, y = (e["ours"] + e["theirs"])[0][:2]
            box(pa, pb, masked, w, h, x, y)


def box(pa, pb, masked, w, h, cx, cy, rad=9):
    """Both pictures side by side around one place, a letter to a colour.

    Reading "ours" and "theirs" off a tally is not enough: "ours" only says
    the port drew something the original did not draw *the same*, and the
    answer differs a great deal between "the original left it white" and
    "the original had another element's colour there".
    """
    letter = {(255, 255, 255): ".", (0, 0, 0): "#", (0, 192, 192): "c",
              (192, 192, 192): "g", (192, 0, 192): "p", (0, 0, 255): "b",
              (0, 192, 0): "G", (255, 0, 0): "r"}
    other = {}

    def ch(c):
        c = tuple(c)
        if c in letter:
            return letter[c]
        if c not in other:
            other[c] = "0123456789"[len(other) % 10]
        return other[c]

    print("  around %d,%d -- the original on the left, the port on the right"
          % (cx, cy))
    print("        %s   %s" % ("".join(str((cx + i) % 10)
                                       for i in range(-rad, rad + 1)),
                               "".join(str((cx + i) % 10)
                                       for i in range(-rad, rad + 1))))
    for y in range(cy - 3, cy + 4):
        if y < 0 or y >= h:
            continue
        a_row = b_row = ""
        for x in range(cx - rad, cx + rad + 1):
            if x < 0 or x >= w:
                a_row += " "
                b_row += " "
                continue
            a_row += "~" if masked[y][x] else ch(pa[x, y])
            b_row += "~" if masked[y][x] else ch(pb[x, y])
        print("  %5d %s   %s" % (y, a_row, b_row))
    for c, k in sorted(other.items(), key=lambda kv: kv[1]):
        print("        %s = %02x%02x%02x" % (k, c[0], c[1], c[2]))


if __name__ == "__main__":
    main()
