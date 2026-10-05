#!/usr/bin/env python3
"""Turn the CP932 \\xNN escapes of a generated header back into Japanese.

    python tools/unesc.py src/gen/jikkaku.h CHECK

The second argument, if given, keeps only the lines that hold it.  The
generated tables stay plain ASCII so the headers are portable; this is for
reading them.
"""
import io
import sys

B = chr(92)


def unesc(line):
    out = bytearray()
    i = 0
    n = len(line)
    while i < n:
        if line[i] == B and i + 3 < n and line[i + 1] == 'x':
            try:
                out.append(int(line[i + 2:i + 4], 16))
                i += 4
                continue
            except ValueError:
                pass
        if line[i:i + 3] == '" "':      # the splice the generators insert
            i += 3
            continue
        out.append(ord(line[i]) if ord(line[i]) < 128 else 0x3f)
        i += 1
    try:
        return out.decode('cp932')
    except Exception:
        return out.decode('cp932', 'replace')


def main():
    path = sys.argv[1]
    want = sys.argv[2] if len(sys.argv) > 2 else ''
    s = io.open(path, encoding='utf-8', errors='replace').read()
    out = []
    for ln in s.split('\n'):
        if want and want not in ln:
            continue
        out.append(unesc(ln.rstrip()))
    io.open('tmp/unesc.txt', 'w', encoding='utf-8').write('\n'.join(out))
    print('wrote tmp/unesc.txt (%d lines)' % len(out))


main()
