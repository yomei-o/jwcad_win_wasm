#!/bin/sh
# What the nine line types come out as on paper.
#
#   sh tools/probe34.sh
#
# On screen a line type's pattern is counted in **pixels** (src/draw.c's
# LTYPE, and jw_mm_per_bit is 0), so there is nothing there to say what a
# dash is in millimetres.  The print has to.  tools/mkdash.c writes nine
# lines, one of each type, and this has the original print them; what
# comes back is decomp/res/print_dash.txt, and src/plot.c's dash_of is
# measured off it.
cd "$(dirname "$0")/.."
set +e
CC=${CC:-gcc}
SRC="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/houraku.c src/view.c src/draw.c src/text.c src/fontx.c src/plot.c src/png.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
$CC -O2 -Isrc -o tmp/mkdash.exe tools/mkdash.c $SRC -lm || exit 1
./tmp/mkdash.exe || exit 1
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
idle
sh tools/refenv.sh >/dev/null
cp tmp/dash.jww tmp/rect.jww
echo "=== dash"
$PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks \
 'raw:f,273,57607,0;wait:2000;pb:1;wait:1500;pb:1065;savedlg:tmp/orig_dash.pdf' \
 2>&1 | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
