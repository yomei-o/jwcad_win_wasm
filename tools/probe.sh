#!/bin/sh
cd "$(dirname "$0")/.."
sh tools/score.sh 2>&1 | tail -2
echo "--- JW_ARC_BEZ=1"
JW_ARC_BEZ=1 sh tools/score.sh 2>&1 | tail -1
