#!/bin/sh
# 一括処理's third prompt: what the 追加・除外 clicks do.
#
#   sh tools/probe50.sh
#
# 「■  一括処理する追加・除外線をﾏｳｽ(L)で指示してください。 (R)確定」 --
# the name says add or drop, but which of the two a click does must
# depend on whether the line is in already, and nothing has been measured.
#
# The drawing is tools/mkikkatsu.c -DJW_IKKATSU_BAND and the walk is
# tools/probe42.sh's, whose clicks at y=330 take the lines at
# x = -100, -70, -55, -35, -20, 10, 40, 100 and leave out the one at 70,
# whose top stops at y=0 (sheet y at that click is 7.96, so the segment
# misses it).  So:
#
#   add   (L) on the line at x=70, which is out.  If it comes in, a click
#         on a line that is not taken adds it.
#   drop  (L) on the line at x=-70, which is in.  If it goes, a click on
#         a line that is taken drops it.
#   both  one of each.
#
# 49 pixels to 30 millimetres, the paper origin at view 554.333,343, so
# x=70 is at px 669, x=-70 at px 440, and sheet y=-12 is at py 363 --
# well clear of the wall at y=0, which is py 343.
cd "$(dirname "$0")/.."
set +e
CC=${CC:-gcc}
for dd in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$dd/gcc.exe" ] && { CCPATH="$dd"; break; }
done
SRC="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/houraku.c src/view.c src/draw.c src/text.c src/fontx.c src/plot.c src/png.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
(PATH="$CCPATH:$PATH"; $CC -O2 -Isrc -DJW_IKKATSU_BAND -o tmp/mkikkatsu3.exe tools/mkikkatsu.c $SRC -lm) || exit 1
./tmp/mkikkatsu3.exe || exit 1
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp tmp/ikkatsu.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

W='cmd:32847;300,250;300,280;r391,343;r464,343;btn:1072;391,330;717,330;'
R='read:59393;'

run add  "${W}669,363;${R}r900,330;saveas:p50_add"
run drop "${W}440,363;${R}r900,330;saveas:p50_drop"
run both "${W}669,363;440,363;r900,330;saveas:p50_both"
idle
sh tools/refenv.sh >/dev/null
