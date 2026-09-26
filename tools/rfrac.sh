#!/bin/sh
# Score the fifteen at a few JW_ARC_RFRAC thresholds.
#
# Of the three whole circles that can be fitted against the original's own
# ink (tools/circall.sh), the two in the 2r box lose 0.570 of a pixel to the
# rounding of the radius and the one in the 2r+1 box loses 0.744.  Two
# values are not a rule.  This says whether they are even a coincidence: if
# no threshold between them improves the fifteen, the guess is dead.
#
# Run on whatever box holds tmp/refs.
cd "$(dirname "$0")/.."
sh tools/build_tests.sh > /dev/null 2>&1 || { echo "build failed"; exit 1; }
echo built
for t in none 0.50 0.60 0.65 0.70 0.74 0.80; do
    if [ "$t" = none ]; then unset JW_ARC_RFRAC; else JW_ARC_RFRAC=$t; export JW_ARC_RFRAC; fi
    printf '%-5s ' "$t"
    sh tools/scoreall.sh 2>/dev/null \
        | awk 'NR > 1 { s += $2; line = line $1 "=" $2 " " }
               END { print line "  TOTAL " s }'
done
unset JW_ARC_RFRAC
echo RFRACDONE
