#!/bin/sh
# Re-ask the end sweeps.  src/draw.c says the table of these was taken
# before the box of a whole circle and the adding-up of a dash were put
# right, and the score has gone 814 -> 524 since.  Two thirds of what is
# left of `サンプル` is ends.
cd "$(dirname "$0")/.."
sh tools/score.sh > /dev/null 2>&1 || { echo "build failed"; exit 1; }
echo "--- base"
sh tools/score.sh | tail -1
echo "--- where the walk stops"
sh tools/sweepenv.sh JW_ARC_ENDADD 1 -1 2 -2
echo "--- where it starts"
sh tools/sweepenv.sh JW_ARC_STARTADD 1 -1 2 -2
echo "--- no ray snapping"
JW_ARC_NORAY=1 sh tools/score.sh | tail -1
