#!/bin/sh
# The point again, with the two kinds the other way round.
#
#   sh tools/probe36.sh
#
# tools/probe35.sh printed a point whose trailing long is 1 and one whose
# long is 0, and only the second came out.  That is the opposite way round
# from what src/draw.c reads the long as (1 = 実点, which wears a ring on
# screen), so it is worth one more run with the two swapped: if the dot
# still lands where the 0 is, the long and not the place is what decides.
cd "$(dirname "$0")/.."
set +e
CC=${CC:-gcc}
for dd in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$dd/gcc.exe" ] && { CCPATH="$dd"; break; }
done
SRC="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/houraku.c src/view.c src/draw.c src/text.c src/fontx.c src/plot.c src/png.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
(PATH="$CCPATH:$PATH"; $CC -O2 -Isrc -DJW_SWAP_POINTS -o tmp/mkpoints2.exe tools/mkpoints.c $SRC -lm) || exit 1
./tmp/mkpoints2.exe || exit 1
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
idle
sh tools/refenv.sh >/dev/null
cp tmp/points.jww tmp/rect.jww
echo "=== swapped"
$PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks \
 'raw:f,273,57607,0;wait:2000;pb:1;wait:1500;pb:1065;savedlg:tmp/orig_pts2.pdf' \
 2>&1 | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
