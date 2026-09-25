u"""Which radius, in pixels, did the original draw each arc at?

    python tmp/arcrp.py tmp/refs/d14.png tmp/d14.out.png

For every arc in tests/shot.exe's dump it walks the reference picture along
the arc's own angles at each candidate radius and counts how many of those
places are inked.  The radius with the most ink is the one the original
used.  Then it prints the arcs where that is not what the port worked out,
next to the ones where it is, so the rule can be read off.
"""
import math
import os
import sys

from PIL import Image


def elements(path):
    arcs = []
    for line in open(path):
        f = line.split()
        if not f or f[0].startswith("#") or f[0] != "arc":
            continue
        arcs.append(dict(i=int(f[1]), cx=int(f[2]), cy=int(f[3]),
                         rpx=float(f[4]), a0=float(f[5]), sweep=float(f[6]),
                         ltype=int(f[7]), flat=float(f[8]), tilt=float(f[9]),
                         colour=int(f[10]), grp=int(f[11]), lay=int(f[12]),
                         rmm=float(f[13]),
                         flags=int(f[14]) if len(f) > 14 else 0,
                         n=int(f[15]) if len(f) > 15 else 0))
    return arcs


def main():
    ref, out = sys.argv[1], sys.argv[2]
    img = Image.open(ref).convert("RGB")
    w, h = img.size
    px = img.load()
    seen = {}
    for y in range(0, h, 3):
        for x in range(0, w, 3):
            seen[px[x, y]] = seen.get(px[x, y], 0) + 1
    bg = max(seen, key=seen.get)

    same = bad = 0
    tally = {}
    for a in elements(out + ".elems"):
        port = int(a["rpx"] + 0.5)
        if port < 3 or a["flat"] != 1.0 or a["ltype"] != 1:
            continue
        sweep = a["sweep"] or 2 * math.pi
        lo = a["a0"] + a["tilt"]
        best, bestn, scores = None, -1, {}
        for rp in range(max(1, port - 2), port + 3):
            hit = 0
            n = max(8, int(abs(sweep) * rp))
            for k in range(n + 1):
                t = lo + sweep * k / n
                x = a["cx"] + int(round(rp * math.cos(t)))
                y = a["cy"] - int(round(rp * math.sin(t)))
                if 0 <= x < w and 0 <= y < h and px[x, y] != bg:
                    hit += 1
            score = hit / float(n + 1)
            scores[rp] = score
            if score > bestn:
                bestn, best = score, rp
        if bestn < 0.9:                 # not clearly on any ring: skip
            continue
        # a short arc can sit next to a concentric one; only call it a
        # mismatch when the other radius is plainly better
        if best != port and bestn - scores.get(port, 0.0) < 0.3:
            continue
        tally[a["flags"]] = tally.get(a["flags"], [0, 0])
        tally[a["flags"]][0 if best == port else 1] += 1
        if best == port:
            same += 1
        else:
            bad += 1
            print("arc %5d  port %3d  theirs %3d  r=%9.4f px %9.4f mm"
                  "  sweep %8.4f  tilt %8.4f  col %d  lay %d/%d"
                  "  flags %d  n %d"
                  % (a["i"], port, best, a["rpx"], a["rmm"], a["sweep"],
                     a["tilt"], a["colour"], a["grp"], a["lay"], a["flags"],
                     a["n"]))
    print("%d arcs agree, %d do not" % (same, bad))
    print("  by the element's flags at +0x44:")
    for k in sorted(tally):
        print("    flags %6d (0x%04x): %3d agree, %3d do not"
              % (k, k, tally[k][0], tally[k][1]))


main()
