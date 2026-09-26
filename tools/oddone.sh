#!/bin/sh
# Which box did the original put each whole circle in?  One circle at a time.
#
#   sh tools/oddone.sh d14
#   sh tools/oddone.sh d09 d11 d12
#
# tools/circbox.py reads that off the original's own ink, but only for a
# circle that is big and on its own -- a small one has too few pixels and a
# concentric run catches its neighbours' ink.  The score can read every one
# of them instead: move **one** circle into the 2r+1 box (JW_ARC_ODDONE) and
# see which way the drawing's own count goes.
#
#   worse  -> that circle was in the 2r box (where the port already has it)
#   better -> it was in the 2r+1 box
#   same   -> its ring is under a text mask, or off the sheet
#
# Run on whatever box holds tmp/refs.
cd "$(dirname "$0")/.."
set -e

score() {   # $1 = drawing name; prints the mismatch count
    ./tests/shot.exe "tmp/$1.out.png" "tmp/$1.jww" >/dev/null
    cat docs/textareas.txt "tmp/$1.out.png.mask" > "tmp/$1.mask"
    python tools/cmp.py "tmp/refs/$1.png" "tmp/$1.out.png" --near \
        -i "tmp/$1.mask" > "tmp/$1.txt" 2>&1 || true
    sed -n '2p' "tmp/$1.txt" | grep -o '[0-9]* differ' | cut -d' ' -f1
}

which=$*
[ -n "$which" ] || which="d09 d11 d12 d14"
for n in $which; do
    [ -f "tmp/$n.jww" ] || { echo "$n: no tmp/$n.jww"; continue; }
    JW_SHOT_ELEMS=1 ./tests/shot.exe "tmp/$n.out.png" "tmp/$n.jww" >/dev/null
    base=$(score "$n")
    echo "$n base $base"
    # every whole circle with a solid line type, out of the element dump
    awk '$1 == "arc" {
            sweep = $7 < 0 ? -$7 : $7
            lt = $8 % 100
            if (sweep > 6.2831852 && $9 == 1 && lt == 1)
                print $2, $5, $14
         }' "tmp/$n.out.png.elems" |
    while read i rpx rmm; do
        got=$(JW_ARC_ODDONE=$i score "$n")
        d=$((got - base))
        if [ "$d" -gt 0 ]; then say="2r  (worse by $d)"
        elif [ "$d" -lt 0 ]; then say="2r+1 (better by $((-d)))"
        else say="--   (no pixels of its own)"
        fi
        printf '  %-6s r %8s px  %8s mm  %s\n' "$i" "$rpx" "$rmm" "$say"
    done
done
