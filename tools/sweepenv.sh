#!/bin/sh
# Score the fifteen once for each value of one environment knob.
#
#   sh tools/sweepenv.sh JW_ARC_RPADD 1 -1
#   sh tools/sweepenv.sh JW_ARC_RFRAC 0.6 0.7
#
# src/draw.c carries a handful of knobs for measuring a guess before it is
# believed (JW_ARC_ODDBOX, _RFRAC, _DIMBOX, _RPADD, ...).  This runs them.
# The first line is always the drawing as it stands, with the knob unset.
#
# Run on whatever box holds tmp/refs.
cd "$(dirname "$0")/.."
set -e
var=$1
shift
[ -n "$var" ] || { echo "usage: sh tools/sweepenv.sh <VAR> <value...>"; exit 1; }

total() {
    sh tools/scoreall.sh 2>/dev/null |
        awk 'NR > 1 { s += $2; line = line $1 "=" $2 " " }
             END { print line "  TOTAL " s }'
}

printf '%-8s ' "none"
total
for v in "$@"; do
    printf '%-8s ' "$v"
    export "$var=$v"
    total
    unset "$var"
done
echo SWEEPDONE
