"""Compare two screens pixel for pixel.

This is the measuring stick for the whole port: the number it prints is how
far the port is from the original.  A run writes a diff image next to the
output so it is obvious *where* the mismatch is, not just how much.

    python tools/cmp.py docs/ref_start.png tests/out/frame.png [-d tmp/diff.png]

Exit status is 0 only when every pixel matches.
"""
import argparse
import collections
import sys

from PIL import Image


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('a')
    ap.add_argument('b')
    ap.add_argument('-d', '--diff', default=None,
                    help='write a diff image here (default: <b>.diff.png)')
    ap.add_argument('-n', '--top', type=int, default=8,
                    help='how many mismatching colour pairs to list')
    ap.add_argument('-i', '--ignore', default=None,
                    help='file of "x y w h  # what it is" rectangles to leave '
                         'out of a second score -- the places where the '
                         'original draws text with the system font, which the '
                         'port is not expected to match')
    args = ap.parse_args()

    a = Image.open(args.a).convert('RGB')
    b = Image.open(args.b).convert('RGB')
    if a.size != b.size:
        print('size differs: %s is %dx%d, %s is %dx%d'
              % (args.a, a.width, a.height, args.b, b.width, b.height))
        return 2

    ignore = []
    if args.ignore:
        for line in open(args.ignore, encoding='utf-8'):
            line = line.split('#')[0].split()
            if len(line) == 4:
                ignore.append(tuple(int(v) for v in line))

    def masked(x, y):
        for rx, ry, rw, rh in ignore:
            if rx <= x < rx + rw and ry <= y < ry + rh:
                return True
        return False

    pa, pb = a.load(), b.load()
    w, h = a.size
    diff = Image.new('RGB', (w, h))
    pd = diff.load()
    bad = 0
    bad_unmasked = 0
    masked_total = 0
    pairs = collections.Counter()
    rows = collections.Counter()
    cols = collections.Counter()
    for y in range(h):
        for x in range(w):
            ca, cb = pa[x, y], pb[x, y]
            if ca == cb:
                # keep the matching picture visible, but faint
                g = (ca[0] * 3 + ca[1] * 6 + ca[2]) // 10
                g = 200 + g // 5
                pd[x, y] = (g, g, g)
            else:
                bad += 1
                if ignore and masked(x, y):
                    masked_total += 1
                    pd[x, y] = (255, 190, 190)
                    continue
                bad_unmasked += 1
                pd[x, y] = (255, 0, 0)
                pairs[(ca, cb)] += 1
                rows[y] += 1
                cols[x] += 1

    total = w * h
    print('%s vs %s: %dx%d, %d of %d differ (%.3f%%)'
          % (args.a, args.b, w, h, bad, total, 100.0 * bad / total))
    if ignore:
        print('outside the text areas: %d differ (%.3f%%)'
              % (bad_unmasked, 100.0 * bad_unmasked / total))
    if bad:
        print('worst rows:', ', '.join('y=%d(%d)' % r for r in rows.most_common(6)))
        print('worst cols:', ', '.join('x=%d(%d)' % c for c in cols.most_common(6)))
        print('commonest mismatches (want -> got):')
        for (ca, cb), n in pairs.most_common(args.top):
            print('  %-16s -> %-16s %d' % (ca, cb, n))
    out = args.diff or (args.b + '.diff.png')
    diff.save(out)
    print('diff -> %s' % out)
    return 0 if bad == 0 else 1


if __name__ == '__main__':
    sys.exit(main())
