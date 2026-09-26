#!/bin/sh
# Nudge one arc at a time and see which way the drawing's count goes.
#
#   sh tools/arcone.sh d14 1656 846 1070 974 1634 1468 1376
#   sh tools/arcone.sh d14            (every arc with a sweep short of a turn)
#
# The whole-drawing sweeps of "radius one more", "start one along" and "far
# end one along" are all in RESUME.md and none of them helps.  What has never
# been looked at is whether the arcs that *are* wrong want the same nudge as
# each other -- if they do, the rule is in whatever they have in common.
#
# Fitting a circle to the original's ink cannot answer this for a partial
# arc: a quarter of a ring fits a family of circles that slide along their
# own direction, so the middle and the radius come out correlated and both
# are wrong.  The score has no such trouble.
#
# Run on whatever box holds tmp/refs.
cd "$(dirname "$0")/.."
set -e

n=$1
shift
[ -n "$n" ] || { echo "usage: sh tools/arcone.sh <dNN> [element...]"; exit 1; }

score() {
    ./tests/shot.exe "tmp/$n.out.png" "tmp/$n.jww" >/dev/null
    cat docs/textareas.txt "tmp/$n.out.png.mask" > "tmp/$n.mask"
    python tools/cmp.py "tmp/refs/$n.png" "tmp/$n.out.png" --near \
        -i "tmp/$n.mask" > "tmp/$n.txt" 2>&1 || true
    sed -n '2p' "tmp/$n.txt" | grep -o '[0-9]* differ' | cut -d' ' -f1
}

JW_SHOT_ELEMS=1 ./tests/shot.exe "tmp/$n.out.png" "tmp/$n.jww" >/dev/null
base=$(score)
echo "$n base $base"

which=$*
if [ -z "$which" ]; then
    which=$(awk '$1 == "arc" {
                    s = $7 < 0 ? -$7 : $7
                    if (s < 6.2831852) print $2
                 }' "tmp/$n.out.png.elems")
fi

for i in $which; do
    line=$(grep -m1 "^arc $i " "tmp/$n.out.png.elems" || true)
    [ -n "$line" ] || { echo "  $i: not an arc here"; continue; }
    printf '  arc %-5s r %s  flags %s\n' "$i" \
        "$(echo "$line" | cut -d' ' -f5)" "$(echo "$line" | cut -d' ' -f15)"
    # commas as well as spaces, so the list survives a trip through ssh
    for what in $(echo "${ARCONE_WHAT:-RP:1 RP:-1 START:1 START:-1 END:1 END:-1}" | tr ',' ' '); do
        k=${what#*:}
        case "$what" in
            RP:*)    got=$(JW_ARC_ONE=$i JW_ARC_ONE_RP=$k score) ;;
            START:*) got=$(JW_ARC_ONE=$i JW_ARC_ONE_START=$k score) ;;
            END:*)   got=$(JW_ARC_ONE=$i JW_ARC_ONE_END=$k score) ;;
            DX:*)    got=$(JW_ARC_ONE=$i JW_ARC_ONE_DX=$k score) ;;
            DY:*)    got=$(JW_ARC_ONE=$i JW_ARC_ONE_DY=$k score) ;;
        esac
        d=$((got - base))
        [ "$d" -ne 0 ] && printf '      %-9s %+d\n' "$what" "$d"
    done
done
echo ARCONEDONE
