#!/usr/bin/env python3
u"""Is a partial Arc's ring part of the whole circle's ring, in the same box?

    gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32
    python tools/arcsub.py            # writes tmp/subs.txt
    tmp/gdiarc.exe < tmp/subs.txt > tmp/subs.out
    python tools/arcsub.py tmp/subs.out

The port draws a part of a circle by taking the ring it baked for the whole
circle in the same box and walking the stretch between the two ends
(src/gen/circle.h, src/draw.c).  That is only right if GDI's own ring for a
partial Arc is a **subset** of its ring for the whole one -- and nobody has
asked.  `サンプル` says it may not be: three of its arcs leave pixels of
GDI's 2r+1 ring unpainted, and the missing ones sit in the middle of the
arc, not at its ends (docs/notes-pixels.md).

Nothing here needs the original or a reference picture: GDI answers both
halves of the question itself.  Every arc is asked in the 2r+1 box, which
is the one FUN_00421490 passes for a part of a circle.
"""
import io
import math
import os
import sys

NVAR = 8
TWO_PI = 2.0 * math.pi


def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))


def cases():
    """Radius, start angle and sweep, over a spread worth asking about."""
    out = []
    for rp in (7, 14, 19, 24, 40, 61, 100):
        for k in range(8):
            for off, tag in ((0.11, "off"), (0.0, "on")):
                a0 = TWO_PI * k / 8.0 + off
                for sw in (math.pi / 2, -math.pi / 2, math.pi / 4, 2.6):
                    out.append((rp, a0, sw, tag))
    return out


def main():
    got = sys.argv[1] if len(sys.argv) > 1 else None
    cs = cases()
    if not got:
        with io.open("tmp/subs.txt", "w", encoding="ascii") as f:
            for i, (rp, a0, sw, tag) in enumerate(cs):
                x1, y1 = ray(rp, a0)
                x2, y2 = ray(rp, a0 + sw)
                if sw < 0:
                    x1, y1, x2, y2 = x2, y2, x1, y1
                # 1 = one Arc in the 2r+1 box; 3 = two Arcs round the whole
                # ring in the same box.
                f.write("%d %d 1 %d %d %d %d\n" % (i * NVAR, rp, x1, y1,
                                                   x2, y2))
                f.write("%d %d 3 0 0 0 0\n" % (i * NVAR + 1, rp))
        print("wrote tmp/subs.txt: %d arcs" % len(cs))
        return

    rings = {}
    lines = io.open(got, encoding="ascii", errors="replace").read().split("\n")
    k = 0
    while k < len(lines):
        head = lines[k].split()
        k += 1
        if len(head) != 2:
            continue
        tag, n = int(head[0]), int(head[1])
        pts = set()
        for _ in range(n):
            if k >= len(lines):
                break
            p = lines[k].split()
            k += 1
            if len(p) == 2:
                pts.add((int(p[0]), int(p[1])))
        rings[tag] = pts

    outside = 0
    arcs = 0
    worst = []
    byseam = {}
    byrp = {}
    for i, (rp, a0, sw, tag) in enumerate(cs):
        part = rings.get(i * NVAR)
        whole = rings.get(i * NVAR + 1)
        if part is None or whole is None:
            continue
        arcs += 1
        extra = part - whole
        if extra:
            outside += 1
            worst.append((len(extra), rp, a0, sw, sorted(extra)[:6],
                          len(part)))
        byseam[tag] = byseam.get(tag, [0, 0])
        byseam[tag][0] += 1
        byseam[tag][1] += 1 if extra else 0
        byrp[rp] = byrp.get(rp, [0, 0, 0])
        byrp[rp][0] += 1
        byrp[rp][1] += 1 if extra else 0
        byrp[rp][2] += len(extra)
    print("%d arcs asked" % arcs)
    print("%d of them paint a pixel the whole circle's ring does not have"
          % outside)
    # Does an arc whose ends sit exactly on an eighth of a turn come out the
    # same as the whole circle?  The thirteen of `Ａマンション平面例` do sit
    # there (docs/notes-pixels.md), and they are the ones that are wrong.
    print("")
    print("by radius -- the drawings' own arcs are 14 to 24 pixels:")
    for rp in sorted(byrp):
        n, bad, ex = byrp[rp]
        print("   rp %4d: %3d of %3d differ, %5d extra pixels in all"
              % (rp, bad, n, ex))
    print("")
    for tag in sorted(byseam):
        n, bad = byseam[tag]
        print("   ends %-3s the eighth-of-a-turn seams: %3d of %3d differ"
              % (tag, bad, n))
    # Where do the extras sit?  GDI walks a curve an octant at a time, so if
    # the difference is only the error term the walk starts with, it should
    # die out once the walk crosses into the next octant.  If that holds,
    # the port can keep its baked ring and redo just the start octant.
    print("")
    print("which eighth of a turn the extras sit in, counted from the "
          "start's own eighth:")
    spread = {}
    for i, (rp, a0, sw, tag) in enumerate(cs):
        part = rings.get(i * NVAR)
        whole = rings.get(i * NVAR + 1)
        if part is None or whole is None:
            continue
        lo = a0 if sw > 0 else a0 + sw
        oct0 = int(math.floor((lo % TWO_PI) / (math.pi / 4.0)))
        for dx, dy in part - whole:
            t = math.atan2(-dy, dx) % TWO_PI
            o = int(math.floor(t / (math.pi / 4.0)))
            spread[(o - oct0) % 8] = spread.get((o - oct0) % 8, 0) + 1
    tot = sum(spread.values()) or 1
    for k2 in sorted(spread):
        print("   +%d eighths from the start: %5d extras (%4.1f%%)"
              % (k2, spread[k2], 100.0 * spread[k2] / tot))

    if worst:
        worst.sort(reverse=True)
        print("")
        print("%6s %5s %8s %8s  %s" % ("extra", "rp", "start", "sweep",
                                       "the first few"))
        for n, rp, a0, sw, pts, tot in worst[:12]:
            print("%6d %5d %8.4f %8.4f  %s   (of %d)"
                  % (n, rp, a0, sw,
                     " ".join("%+d%+d" % p for p in pts), tot))
    else:
        print("every partial arc's ring is inside the whole circle's ring")


if __name__ == "__main__":
    main()
