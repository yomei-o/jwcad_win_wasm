#!/usr/bin/env python3
"""Write the two variants of orig/Test5.jww that tools/probe12.sh needs.

The layer buttons in the レイヤ設定 dialog carry eight different pictures:
four states times whether anything is drawn on the layer.  Six of them show
in pictures of that drawing as it comes, but not the two for a write layer
or a write group with nothing on it -- in Test5 both have plenty on them.

Rather than try to move the write layer with the mouse (the dialog takes a
right click on a button for that, which a posted BM_CLICK cannot do), the
longs that say who is written to are patched in the file the original
itself wrote.  The header lays them out like this, from offset 31:

  31        the write group's number
  35 + 148g each group: its state, its write layer, its scale (eight
            bytes), a colour, then sixteen layers of a state and a second
            state

  tmp/t5wl5.jww   layer 5 of group 0 -- empty -- is the write layer
  tmp/t5wg1.jww   group 1 -- empty -- is the write group

Nothing else in either file is touched, so whatever the original draws
differently is down to those longs alone.
"""
import io
import os
import sys

SRC = 'orig/Test5.jww'
WGROUP = 31
GROUP = 35
STRIDE = 148
LAYER = GROUP + 20                      # the first layer's state


def put_l(b, o, v):
    b[o] = v & 255
    b[o + 1] = (v >> 8) & 255
    b[o + 2] = (v >> 16) & 255
    b[o + 3] = (v >> 24) & 255


def get_l(b, o):
    return b[o] | (b[o + 1] << 8) | (b[o + 2] << 16) | (b[o + 3] << 24)


def main():
    if not os.path.exists(SRC):
        print('%s missing' % SRC, file=sys.stderr)
        return 1
    src = io.open(SRC, 'rb').read()
    if get_l(bytearray(src), WGROUP) != 0 or get_l(bytearray(src), GROUP) != 3:
        print('%s is not in the state this was written for' % SRC,
              file=sys.stderr)
        return 1
    if not os.path.isdir('tmp'):
        os.makedirs('tmp')

    b = bytearray(src)
    put_l(b, GROUP + 4, 5)              # group 0's write layer
    put_l(b, LAYER + 8 * 8, 2)          # layer 8 was it
    put_l(b, LAYER + 8 * 5, 3)          # layer 5 is now
    io.open('tmp/t5wl5.jww', 'wb').write(bytes(b))

    b = bytearray(src)
    put_l(b, WGROUP, 1)
    put_l(b, GROUP, 2)                  # group 0 was it
    put_l(b, GROUP + STRIDE, 3)         # group 1 is now
    io.open('tmp/t5wg1.jww', 'wb').write(bytes(b))

    print('tmp/t5wl5.jww, tmp/t5wg1.jww')
    return 0


if __name__ == '__main__':
    sys.exit(main())
