#!/usr/bin/env python3
"""Print C string literals (CP932 bytes) for the strings on the command line."""
import sys


def esc(s):
    b = s.encode('cp932')
    out = ''
    prev_hex = False
    for c in b:
        ch = chr(c)
        if 32 <= c < 127 and ch not in '"\\?':
            if prev_hex and ch in '0123456789abcdefABCDEF':
                out += '" "'
            out += ch
            prev_hex = False
        else:
            out += '\\x%02x' % c
            prev_hex = True
    return '"' + out + '"'


for s in sys.argv[1:]:
    print(esc(s))
