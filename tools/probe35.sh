#!/bin/sh
# What points and カラー印刷 come out as on paper.
#
#   sh tools/probe35.sh
#
# src/plot.c puts a small cross where a point is, which is what
# jwcad_dos_wasm does, and takes カラー印刷's colours from print_rgb.
# Neither was asked of the original.  This asks: tools/mkpoints.c draws a
# 実点, a 仮点, one line of each pen and a solid, and the original prints
# it twice -- once as the bar comes up (black) and once with カラー印刷
# (1343) ticked.
cd "$(dirname "$0")/.."
set +e
# gcc needs w64devkit on PATH to find `as`, but putting it there
# makes `sh` resolve to its busybox, which cannot fork here.  So
# the compiler gets it and nothing else does.
CC=${CC:-gcc}
for dd in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$dd/gcc.exe" ] && { CCPATH="$dd"; break; }
done
SRC="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/houraku.c src/view.c src/draw.c src/text.c src/fontx.c src/plot.c src/png.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
(PATH="$CCPATH:$PATH"; $CC -O2 -Isrc -o tmp/mkpoints.exe tools/mkpoints.c $SRC -lm) || exit 1
./tmp/mkpoints.exe || exit 1
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp tmp/points.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 | sed 's/^/    /'
}
P='raw:f,273,57607,0;wait:2000;pb:1;wait:1500;'
run mono   "${P}pb:1065;savedlg:tmp/orig_pts.pdf"
run colour "${P}btn:1343;wait:500;pb:1065;savedlg:tmp/orig_col.pdf"
idle
sh tools/refenv.sh >/dev/null
