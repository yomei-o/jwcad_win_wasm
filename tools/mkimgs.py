#!/usr/bin/env python3
"""Make the pictures tests/image_test.c decodes: tmp/img/dec_*.{bmp,png,jpg} and,
beside each, dec_*.rgb -- what Pillow reads out of it (w*h*3 bytes, with a
16-bit header of width and height).  Needs Pillow.

    python tools/mkimgs.py
"""
import os
import struct
from PIL import Image

os.makedirs('tmp/img', exist_ok=True)
W, H = 67, 45          # not a multiple of 8 or 16, on purpose


def pattern(mode='RGB'):
    im = Image.new('RGB', (W, H))
    px = im.load()
    for y in range(H):
        for x in range(W):
            r = x * 255 // (W - 1)
            g = y * 255 // (H - 1)
            b = 200 if ((x // 6) + (y // 6)) % 2 else 30
            if (x - 33) ** 2 + (y - 22) ** 2 < 150:
                r, g, b = 250, 20, 20
            px[x, y] = (r, g, b)
    return im


def save(im, name, **kw):
    path = 'tmp/img/dec_%s' % name
    im.save(path, **kw)
    back = Image.open(path).convert('RGB')
    with open(path.rsplit('.', 1)[0] + '.rgb', 'wb') as f:
        f.write(struct.pack('<HH', back.width, back.height))
        f.write(back.tobytes())


p = pattern()
save(p, 'rgb24.bmp')
save(p.convert('P', palette=Image.ADAPTIVE, colors=64), 'pal8.bmp')
save(p.convert('1'), 'mono.bmp')
save(p, 'rgb.png')
save(p.convert('P', palette=Image.ADAPTIVE, colors=32), 'pal.png')
save(p.convert('L'), 'grayp.png')
save(p.convert('RGBA'), 'rgba.png')
save(p, 'q95.jpg', quality=95, subsampling=0)
save(p, 'q80_420.jpg', quality=80, subsampling=2)
save(p, 'q80_422.jpg', quality=80, subsampling=1)
save(p, 'prog.jpg', quality=85, progressive=True)
save(p.convert('L'), 'gray.jpg', quality=90)
print('made', len(os.listdir('tmp/img')), 'files in tmp/img')
