#!/bin/sh
# How far out of line a line may be and still be taken by 一括処理.
#
#   sh tools/probe41.sh
#
# tools/probe40.sh found that a line whose near end stops 30 mm short of
# the others is left out, while one that reaches the same height as them
# is taken.  This puts four in between -- short by 1, 5, 10 and 20 -- and
# reads off which of them come out.
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
idle
sh tools/refenv.sh >/dev/null
cp tmp/ikkatsu.jww tmp/rect.jww
echo "=== band"
$PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks \
 'cmd:32847;300,250;300,280;r391,343;r464,343;btn:1072;391,320;717,320;r900,320;saveas:p41_band' \
 2>&1 | grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
