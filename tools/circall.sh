#!/bin/sh
# Every whole circle of every sample drawing, and which box the original put
# it in.  Run on whatever box holds tmp/refs (tools/refshots.sh makes those).
#
#   sh tools/circall.sh            all fifteen
#   sh tools/circall.sh d11 d14    just those
#
# tools/circbox.py does one drawing; this walks them and puts the lines in
# one table, so the rule -- if there is one -- can be read off.  See
# RESUME.md 「`日影図` の円 1 つは「円弧の枠」で描かれています」.
cd "$(dirname "$0")/.."
set -e
which=$*
[ -n "$which" ] || which="d01 d02 d03 d04 d05 d06 d07 d08 d09 d10 d11 d12 d13 d14 d15"
for n in $which; do
    [ -f "tmp/$n.jww" ] || { echo "$n: no tmp/$n.jww"; continue; }
    [ -f "tmp/refs/$n.png" ] || { echo "$n: no tmp/refs/$n.png"; continue; }
    JW_SHOT_ELEMS=1 ./tests/shot.exe "tmp/$n.out.png" "tmp/$n.jww" >/dev/null
    python tools/circbox.py "tmp/refs/$n.png" "tmp/$n.out.png" || true
done
