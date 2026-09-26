#!/usr/bin/env python3
u"""Which box did the original put each whole circle in?  Ask GDI.

    JW_SHOT_ELEMS=1 ./tests/shot.exe tmp/d11.out.png tmp/d11.jww
    python tools/circask.py tmp/refs/d11.png tmp/d11.out.png   # writes tmp/circs.txt
    tmp/gdiarc.exe < tmp/circs.txt > tmp/gdicirc.out
    python tools/circask.py tmp/refs/d11.png tmp/d11.out.png tmp/gdicirc.out

A whole circle is drawn by FUN_00421490 as **two** Arc calls round a box
2r across; a part of one goes in a box 2r+1 across.  `日影図`'s single
circle measures as though it had gone in the 2r+1 box -- 223 pixels of the
remaining score, and nothing in the element says why (docs/notes-pixels.md,「`日影図`
の円 1 つは「円弧の枠」で描かれています」).

Everything that has looked at this so far has gone through the port: the
fit of the original's ink, or the score with the box swapped.  This asks
**GDI itself** for both rings, with the same middle and the same radius the
original works out, and counts how much of each sits on the original's own
ink.  tools/gdiarc.c draws them into a memory bitmap, so the original is
never started and no desktop is needed.
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
NVAR = 32                       # tag = i * NVAR + variant
# (which box, middle dx, middle dy).  2 is the 2r box, 3 the 2r+1 box.
VARIANTS = [(box, dx, dy)
            for box in (2, 3)
            for dx in (0, 1, -1)
            for dy in (0, 1, -1)]


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


def circles_of(path):
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
        if a["lt"] % 100 != 1 or a["flat"] != 1.0:
            continue
        if abs(a["sw"]) <= TWO_PI - 1e-7:
            continue                        # a part of one: tools/arcask.py
        out.append(a)
    return out


def main():
    ref, out = sys.argv[1], sys.argv[2]
    got = sys.argv[3] if len(sys.argv) > 3 else None
    least = int(os.environ.get("CIRCASK_MIN", "40"))

    circs = circles_of(out + ".elems")
    if not circs:
        print("no whole solid circles in %s.elems" % out)
        return

    if not got:
        with io.open("tmp/circs.txt", "w", encoding="ascii") as f:
            for a in circs:
                rp = int(a["rpx"] + 0.5)
                if rp < 1 or rp > 9000:
                    continue
                for v, (box, dx, dy) in enumerate(VARIANTS):
                    f.write("%d %d %d 0 0 0 0\n"
                            % (a["i"] * NVAR + v, rp, box))
        print("wrote tmp/circs.txt: %d circles x %d ways"
              % (len(circs), len(VARIANTS)))
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

    def score(a, pts, ddx, ddy, pic):
        on = off = 0
        for dx, dy in pts:
            x, y = a["cx"] + dx + ddx, a["cy"] + dy + ddy
            if x < 0 or x >= w or y < 0 or y >= h or masked[y][x]:
                continue
            if pic[x, y] != bg:
                on += 1
            else:
                off += 1
        return on, off

    print("%-6s %8s  %-16s %-16s   %s"
          % ("circle", "radius", "2r box", "2r+1 box", "which fits"))
    for a in circs:
        p2 = rings.get(a["i"] * NVAR + 0)
        p3 = rings.get(a["i"] * NVAR + 9)
        if not p2 or not p3 or len(p2) < least:
            continue
        s2 = score(a, p2, 0, 0, pa)
        s3 = score(a, p3, 0, 0, pa)
        o2 = score(a, p2, 0, 0, pb)
        o3 = score(a, p3, 0, 0, pb)
        pick = "2r" if s2[0] - s2[1] > s3[0] - s3[1] else "2r+1"
        print("%-6d %8.3f  %5d on %5d off %5d on %5d off   %s"
              % (a["i"], a["rpx"], s2[0], s2[1], s3[0], s3[1], pick))
        print("       %8s  the port's own picture: %5d/%5d and %5d/%5d"
              % ("", o2[0], o2[1], o3[0], o3[1]))
        if a["ux"] is not None:
            print("       %8s  middle %+.3f,%+.3f of its pixel"
                  % ("", a["ux"] - a["cx"], a["uy"] - a["cy"]))
    print("\n'on' counts GDI's own pixels that are inked in the original's")
    print("picture; the port's line says the same against the port's own.")


if __name__ == "__main__":
    main()
