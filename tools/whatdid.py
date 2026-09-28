#!/usr/bin/env python3
"""What one drawing has that another has not.

    python tools/whatdid.py decomp/res/a.jww decomp/res/b.jww

Every answer the original draws starts from the same orig/Test5.jww, so what
a command did is the objects that were not there before.  Two answers drawn
the same way but for one checkbox differ by exactly what that checkbox does,
which is how the command bars are read: press it, draw it again, look here.

    +  only in the second file
    -  only in the first
"""
import io
import sys

sys.path.insert(0, 'tools')
import jww                                          # noqa: E402


def objects(path):
    ar = jww.Ar(open(path, 'rb').read())
    keep, sys.stdout = sys.stdout, io.StringIO()   # read_header talks
    try:
        v, _, _ = jww.read_header(ar)
        load = [None]
        out = jww.read_objects(ar, v, note=lambda s: None, load=load)
        if v > 0x13:
            out += jww.read_objects(ar, v, note=lambda s: None, load=load)
    finally:
        sys.stdout = keep
    return out


def key(o):
    """everything the reader kept, as one comparable line"""
    bits = [o['class']]
    for k in sorted(o):
        if k in ('class', 'members'):
            continue
        v = o[k]
        if isinstance(v, float):
            bits.append('%s=%.6f' % (k, v))
        elif isinstance(v, list):
            bits.append('%s=[%s]' % (k, ' '.join(
                '%.6f' % x if isinstance(x, float) else str(x) for x in v)))
        else:
            bits.append('%s=%s' % (k, v))
    return ' '.join(bits)


def main():
    a, b = [objects(p) for p in sys.argv[1:3]]
    ka, kb = [key(o) for o in a], [key(o) for o in b]
    left = list(ka)
    for k in kb:
        if k in left:
            left.remove(k)
        else:
            print('+ ' + k)
    for k in left:
        print('- ' + k)
    if not left and len(ka) == len(kb) and sorted(ka) == sorted(kb):
        print('(the same drawing)')


main()
