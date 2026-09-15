"""Print one decompiled function by address.

    python tools/func.py 42ea30 [42e7f0 ...]
    python tools/func.py --grep CArchive        # which functions mention it

The decompilation is 26 MB across ten shard files, so grep on the whole tree
is slow and gives no context; this finds the function a line belongs to.
"""
import glob
import os
import re
import sys

HEAD = re.compile(r'^/\* ([0-9a-f]{8})  (\S+)  (\d+) bytes, (\d+) callers \*/$')
DIR = 'decomp/decomp'


def iter_functions():
    for fn in sorted(glob.glob(os.path.join(DIR, 'all_*.c'))):
        cur, buf = None, []
        with open(fn, encoding='utf-8', errors='replace') as f:
            for line in f:
                m = HEAD.match(line.rstrip('\n'))
                if m:
                    if cur:
                        yield cur, ''.join(buf)
                    cur, buf = m, [line]
                elif cur:
                    buf.append(line)
        if cur:
            yield cur, ''.join(buf)


def main():
    args = sys.argv[1:]
    if not args:
        print(__doc__)
        return
    if args[0] == '--grep':
        pat = re.compile(args[1])
        for m, body in iter_functions():
            hits = [l for l in body.splitlines() if pat.search(l)]
            if hits:
                print('%s  %s  %s bytes, %s callers  (%d hits)'
                      % (m.group(1), m.group(2), m.group(3), m.group(4),
                         len(hits)))
        return
    want = {a.lower().lstrip('0').rjust(8, '0') for a in args}
    for m, body in iter_functions():
        if m.group(1) in want:
            print(body)


if __name__ == '__main__':
    main()
