#!/usr/bin/env python3
"""python tools/mkbmp.py <out.bmp> <w> <h> [bpp] -- a test pattern as a BMP (24 or 8 bit or 1)."""
import struct, sys
out, w, h = sys.argv[1], int(sys.argv[2]), int(sys.argv[3])
bpp = int(sys.argv[4]) if len(sys.argv) > 4 else 24
pal = b''
rows = b''
for y in range(h):
    r = bytearray()
    if bpp == 24:
        for x in range(w):
            r += bytes([(x * 255 // max(w - 1, 1)) & 255, (y * 255 // max(h - 1, 1)) & 255, 200 if (x // 5 + y // 5) % 2 else 20])
    elif bpp == 8:
        for x in range(w):
            r.append(((x // 5 + y // 5) % 2) * 255 if False else (x // 5 + y // 5) % 4)
    elif bpp == 1:
        for x in range(0, w, 8):
            b = 0
            for k in range(8):
                if x + k < w and ((x + k) // 4 + y // 4) % 2:
                    b |= 0x80 >> k
            r.append(b)
    r += b'\0' * ((4 - len(r) % 4) % 4)
    rows += bytes(r)
if bpp == 8:
    pal = b''.join(bytes(c) + b'\0' for c in [(255, 255, 255), (255, 0, 0), (0, 0, 255), (0, 128, 0)] + [(0, 0, 0)] * 252)
if bpp == 1:
    pal = bytes([0, 0, 0, 0, 255, 255, 255, 0])
off = 54 + len(pal)
hdr = struct.pack('<2sIHHI', b'BM', off + len(rows), 0, 0, off)
hdr += struct.pack('<IiiHHIIiiII', 40, w, h, 1, bpp, 0, len(rows), 2835, 2835, len(pal) // 4, 0)
open(out, 'wb').write(hdr + pal + rows)
