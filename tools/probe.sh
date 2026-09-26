#!/bin/sh
cd "$(dirname "$0")/.."
sh tools/score.sh > /dev/null 2>&1 || { echo "build failed"; exit 1; }
JW_SHOT_ELEMS=1 ./tests/shot.exe tmp/d14.out.png tmp/d14.jww > /dev/null 2>&1
for i in 1656 846 53; do
    python tools/arcpic.py tmp/refs/d14.png tmp/d14.out.png $i 2>&1 \
        | grep -E '^arc |whole ring|^   r |the original: |the port:     '
done
