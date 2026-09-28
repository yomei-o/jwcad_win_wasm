u"""Where a drawing's remaining mismatches are, and what they sit on.

    python tools/diffwhere.py d14

Reads the diff image tools/scoreall.sh leaves in tmp/, clusters the pixels
that differ into blobs, and prints the biggest ones with their middle and
size.  The score says how far the port is; this says where to look.
"""
import collections
import sys

from PIL import Image


def main():
    name = sys.argv[1] if len(sys.argv) > 1 else "d14"
    ref = Image.open("tmp/refs/%s.png" % name).convert("RGB")
    got = Image.open("tmp/%s.out.png" % name).convert("RGB")
    ignore = []
    for path in ("docs/textareas.txt", "tmp/%s.out.png.mask" % name):
        try:
            for line in open(path, encoding="utf-8"):
                line = line.split("#")[0].split()
                if len(line) == 4:
                    ignore.append(tuple(int(v) for v in line))
        except IOError:
            pass

    def masked(x, y):
        for rx, ry, rw, rh in ignore:
            if rx <= x < rx + rw and ry <= y < ry + rh:
                return True
        return False

    pa, pb = ref.load(), got.load()
    w, h = ref.size
    bad = set()
    for y in range(h):
        for x in range(w):
            if pa[x, y] != pb[x, y] and not masked(x, y):
                bad.add((x, y))
    print("%s: %d pixels differ" % (name, len(bad)))
    seen = set()
    blobs = []
    for p in bad:
        if p in seen:
            continue
        stack = [p]
        seen.add(p)
        blob = []
        while stack:
            q = stack.pop()
            blob.append(q)
            for dx in (-1, 0, 1):
                for dy in (-1, 0, 1):
                    r = (q[0] + dx, q[1] + dy)
                    if r in bad and r not in seen:
                        seen.add(r)
                        stack.append(r)
        blobs.append(blob)
    blobs.sort(key=len, reverse=True)
    print("%d blobs" % len(blobs))
    for b in blobs[:20]:
        xs = [q[0] for q in b]
        ys = [q[1] for q in b]
        only_mine = sum(1 for q in b if pa[q] == (255, 255, 255))
        print("  %4d px  x %4d..%-4d y %4d..%-4d  %d only in the port"
              % (len(b), min(xs), max(xs), min(ys), max(ys), only_mine))


if __name__ == "__main__":
    main()
