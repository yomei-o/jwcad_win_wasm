#!/bin/sh
# Fit the middle and the radius of the original's ink, arc by arc.
#
# Reading the ink at the port's own middle cannot tell "a ring a pixel
# bigger" from "the same ring a pixel across", and those have different
# causes -- FUN_004b8250 for the radius, FUN_004b6d60 for the middle.  The
# tallies so far have been inconsistent because of it: arcs of 6.0 mm come
# out on both sides, and the radius cannot depend on where a thing is.
#
# So walk both at once, over every arc of `Ａマンション平面例` that has a
# ring to speak of, and print what the original's ink fits.
cd "$(dirname "$0")/.."
sh tools/score.sh > /dev/null 2>&1 || { echo "build failed"; exit 1; }
JW_SHOT_ELEMS=1 ./tests/shot.exe tmp/d14.out.png tmp/d14.jww > /dev/null 2>&1
for i in 1656 53 444 182 194 571 583 846 974 1236 1364 1376; do
    python tools/arcpic.py tmp/refs/d14.png tmp/d14.out.png $i 2>&1 \
        | grep -E '^arc |the original: |the port:     '
done
