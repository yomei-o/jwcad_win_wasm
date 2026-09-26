#!/bin/sh
# A scratch script for one-off questions on the build box.
#
#   sh sync.sh 'sh tools/probe.sh'
cd "$(dirname "$0")/.."
sh tools/score.sh > /dev/null 2>&1 || { echo "build failed"; exit 1; }
echo "--- where the walk ends"
sh tools/sweepenv.sh JW_ARC_ENDADD 1 -1 2 -2
echo "--- where it starts"
sh tools/sweepenv.sh JW_ARC_STARTADD 1 -1
