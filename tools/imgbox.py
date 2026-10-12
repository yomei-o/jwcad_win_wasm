#!/usr/bin/env python3
"""python tools/imgbox.py shot.png -- bounding box (frame px) of non-white pixels inside the drawing area."""
import sys
sys.path.insert(0, 'tests')
import struct, zlib
def load(p):
    d = open(p, 'rb').read(); i = 8; idat = b''
    while i < len(d):
        n, t = struct.unpack('>I4s', d[i:i + 8]); b = d[i + 8:i + 8 + n]
        if t == b'IHDR': w, h, bd, ct = struct.unpack('>IIBB', b[:10])
        if t == b'IDAT': idat += b
        i += 12 + n
    raw = zlib.decompress(idat); bpp = {2: 3, 6: 4}[ct]; st = w * bpp; rows = []; prev = bytearray(st); o = 0
    for y in range(h):
        f = raw[o]; line = bytearray(raw[o + 1:o + 1 + st]); o += 1 + st
        for x in range(st):
            a = line[x - bpp] if x >= bpp else 0; b = prev[x]; c = prev[x - bpp] if x >= bpp else 0
            if f == 1: line[x] = (line[x] + a) & 255
            elif f == 2: line[x] = (line[x] + b) & 255
            elif f == 3: line[x] = (line[x] + ((a + b) >> 1)) & 255
            elif f == 4:
                p = a + b - c; pa, pb, pc = abs(p - a), abs(p - b), abs(p - c)
                pr = a if pa <= pb and pa <= pc else (b if pb <= pc else c); line[x] = (line[x] + pr) & 255
        rows.append(line); prev = line
    return w, h, bpp, rows
w, h, bpp, rows = load(sys.argv[1])
x0, y0, x1, y1 = (int(v) for v in (sys.argv[2:6] if len(sys.argv) > 5 else (90, 90, 1190, 765)))
xs = []; ys = []
for y in range(y0, y1):
    for x in range(x0, x1):
        p = rows[y][x * bpp:x * bpp + 3]
        if p != b'\xff\xff\xff': xs.append(x); ys.append(y)
print(min(xs), min(ys), max(xs), max(ys), 'w', max(xs) - min(xs) + 1, 'h', max(ys) - min(ys) + 1)
