#!/bin/sh
# Whether 一括処理 takes the lines its two clicks' segment crosses.
#
#   sh tools/probe42.sh
#
# tools/probe41.sh drew verticals whose tops are at 20, 19, 15, 10 and 0
# and pressed 一括処理 with two clicks at screen y=320.  The four at 20,
# 19, 15 came out and the two at 10 and 0 did not.  Screen y=320 is sheet
# y=14.08 (49/30 pixels to the millimetre, the origin at 554.33,343 --
# the 寸法線 landed at 38.5714 and the 引出線 at 56.9388, which is where
# clicks at y=280 and y=250 fall, so the mapping is exact).  So the four
# that were taken are exactly the four the clicks' own segment crosses.
#
# That is a hypothesis with one number in it, and a fixed height of, say,
# 12 mm would have done as well.  So this presses it again with the two
# clicks at y=330 -- sheet y=7.96 -- which the top-10 line does cross.
# If the crossing is what matters, the top-10 line comes out this time.
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
echo "=== lower"
$PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks \
 'cmd:32847;300,250;300,280;r391,343;r464,343;btn:1072;391,330;717,330;r900,330;saveas:p42_low' \
 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
