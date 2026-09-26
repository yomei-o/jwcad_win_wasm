#!/bin/sh
# The control that was never run: does the **port's own** ring match the ring
# GDI draws for the box the port passes?
#
# tools/boxask.py has been reading "nine of thirteen arcs fit a 2r+2 ring
# better" as a fact about the original.  That only holds if the port itself
# sits exactly on GDI's 2r+1 ring -- and nobody checked.  The decompilation
# is flat that FUN_00421490 passes 2r+1 and nothing else (read again today:
# the rect is always middle +/- rp, with a +1 on the far corner), so if the
# port is off GDI's ring, the port is the odd one, not the original.
#
# BOXASK_MIN is dropped to 20 so `サンプル`'s smaller arcs come in too.
cd "$(dirname "$0")/.."
sh tools/score.sh > /dev/null 2>&1 || { echo "build failed"; exit 1; }
PATH="$PATH:/c/prog/tools/w64devkit/bin"
gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32 || exit 1
for d in d14 d08; do
    echo "================ $d"
    JW_SHOT_ELEMS=1 ./tests/shot.exe tmp/$d.out.png tmp/$d.jww > /dev/null 2>&1
    BOXASK_MIN=20 python tools/boxask.py tmp/refs/$d.png tmp/$d.out.png
    tmp/gdiarc.exe < tmp/boxes.txt > tmp/gdibox.out
    BOXASK_MIN=20 python tools/boxask.py tmp/refs/$d.png tmp/$d.out.png \
        tmp/gdibox.out 2>&1 | sed -n '1,80p'
done
