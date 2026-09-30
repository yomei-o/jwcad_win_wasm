#!/bin/sh
# Which lines 寸法の一括処理 takes.
#
#   sh tools/probe40.sh
#
# tools/probe39.sh watched it dimension all four gaps between five
# verticals.  What is not settled is **which** lines it picks up between
# the 始線 and the 終線: this adds a diagonal that crosses the row and a
# short vertical that stops short of it, and looks at what comes out.
cd "$(dirname "$0")/.."
set +e
CC=${CC:-gcc}
for dd in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$dd/gcc.exe" ] && { CCPATH="$dd"; break; }
done
SRC="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/houraku.c src/view.c src/draw.c src/text.c src/fontx.c src/plot.c src/png.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
(PATH="$CCPATH:$PATH"; $CC -O2 -Isrc -DJW_IKKATSU_MORE -o tmp/mkikkatsu2.exe tools/mkikkatsu.c $SRC -lm) || exit 1
./tmp/mkikkatsu2.exe || exit 1
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
idle
sh tools/refenv.sh >/dev/null
cp tmp/ikkatsu.jww tmp/rect.jww
echo "=== more"
R='read:59393;'
$PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks \
 "cmd:32847;300,250;300,280;r391,343;r464,343;btn:1072;391,320;717,320;r900,320;${R}saveas:p40_more" \
 2>&1 | grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
