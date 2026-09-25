#!/bin/sh
# Build the shot taker and print the fifteen-drawing total in one line.
#
#   sh tools/score.sh
#
# The references (tmp/refs/d*.png) and the drawings (tmp/d*.jww) are not in
# the repository -- tools/refshots.sh takes them from the original, and they
# have to be copied to whatever box does the scoring.
cd "$(dirname "$0")/.."
case ":$PATH:" in
    *:/c/prog/tools/w64devkit/bin:*) ;;
    *) PATH="$PATH:/c/prog/tools/w64devkit/bin" ;;
esac
[ -d tmp/refs ] || { echo "no tmp/refs here"; exit 1; }
COMMON="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c
        src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c
        src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c
        src/houraku.c src/view.c src/draw.c src/text.c src/fontx.c
        src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
gcc -O1 -w -std=c99 -Isrc -Itests -o tests/shot.exe tests/shot.c tests/png.c \
    $COMMON -lm || exit 1
sh tools/scoreall.sh | tail -15 |
    awk '{s += $2; printf "%s=%s ", $1, $2} END {printf "total %d\n", s}'
