#!/bin/sh
# 同一線種選択: the (R) at 一括処理's first two prompts.
#
#   sh tools/probe55.sh
#
# The last thing about 一括処理 that is not measured.  Both prompts end
# with 「(R)同一線種選択」 and the name says it picks by line type, but
# nothing says what it picks or where the walk goes afterwards.
#
# The drawing is tools/mkikkatsu.c -DJW_IKKATSU_BAND -DJW_IKKATSU_TYPES:
# the same nine verticals as probe41, with the ones at -70, -35 and 10 on
# 点線1 and the rest on 実線.  The (R) goes on a 実線 in one run and on a
# 点線 in the other, and the status line is read at every step.
cd "$(dirname "$0")/.."
set +e
CC=${CC:-gcc}
for dd in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$dd/gcc.exe" ] && { CCPATH="$dd"; break; }
done
SRC="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/houraku.c src/view.c src/draw.c src/text.c src/fontx.c src/plot.c src/png.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
(PATH="$CCPATH:$PATH"; $CC -O2 -Isrc -DJW_IKKATSU_BAND -DJW_IKKATSU_TYPES -o tmp/mkikkatsu4.exe tools/mkikkatsu.c $SRC -lm) || exit 1
./tmp/mkikkatsu4.exe || exit 1
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp tmp/ikkatsu.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

R='read:59393;'
W="cmd:32847;300,250;300,280;r391,343;r464,343;btn:1072;${R}"

# 実線 at x=-100 (px 391), x=100 (px 717); 点線 at x=-70 (px 440) and
# x=10 (px 571).  Sheet y=7.96 is py 330.
#
# The first go at this only pressed (R) once and then right-clicked empty
# space, which is not a 終線 at all, so the walk sat at the second prompt
# and nothing was drawn.  (R) there is 同一線種選択 too, so both ends get
# one, and the third (R) is the 確定.
run sol  "${W}r391,330;${R}r717,330;${R}r900,330;${R}saveas:p55_sol"
run dash "${W}r440,330;${R}r571,330;${R}r900,330;${R}saveas:p55_dash"
run mix  "${W}391,330;${R}r717,330;${R}r900,330;${R}saveas:p55_mix"
# and the plain walk over the same drawing, to have something to compare
run base "${W}391,330;717,330;r900,330;saveas:p55_base"
idle
sh tools/refenv.sh >/dev/null
