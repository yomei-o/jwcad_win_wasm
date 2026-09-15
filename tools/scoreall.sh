#!/bin/sh
# Score every sample drawing against its reference screen.
#
#   sh tools/refshots.sh        # once, to take the references
#   sh tools/scoreall.sh
#
# The references have to be foreground captures (tools/refshots.sh takes
# them that way): a background one leaves most of the drawing out.  The port's
# text is masked out, since its glyphs are a different typeface.
cd "$(dirname "$0")/.."
refs=${1:-tmp/refs}
printf '%-6s %10s %10s %10s %10s\n' drawing mismatch '1px out' elsewhere 'of canvas'
for r in "$refs"/d*.png; do
    n=$(basename "$r" .png)
    ./tests/shot.exe "tmp/$n.out.png" "tmp/$n.jww" >/dev/null || continue
    cat docs/textareas.txt "tmp/$n.out.png.mask" > "tmp/$n.mask"
    # cmp.py exits non-zero when anything differs, which is the normal case
    python tools/cmp.py "$r" "tmp/$n.out.png" --near -i "tmp/$n.mask" \
        -d "tmp/$n.diff.png" > "tmp/$n.txt" 2>&1 || true
    bad=$(sed -n '2p' "tmp/$n.txt" | grep -o '[0-9]* differ' | cut -d' ' -f1)
    near=$(sed -n 's/^of those, \([0-9]*\) .*/\1/p' "tmp/$n.txt")
    els=$(sed -n 's/.*and \([0-9]*\) are somewhere.*/\1/p' "tmp/$n.txt")
    [ -n "$bad" ] || bad=0
    printf '%-6s %10s %10s %10s %9.3f%%\n' "$n" "$bad" "${near:-0}" \
        "${els:-0}" "$(python -c "print(100*$bad/760488)")"
done
