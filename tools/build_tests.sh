#!/bin/sh
# Build the native test programs.  Nothing here opens a window.
set -e
cd "$(dirname "$0")/.."
# w64devkit's gcc needs its own bin on PATH -- without it gcc cannot find as
# and dies with "cannot execute 'as'".  Set CC to use another compiler.
if [ -z "$CC" ]; then
    for d in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
        [ -x "$d/gcc.exe" ] && { PATH="$d:$PATH"; export PATH; break; }
    done
    CC=gcc
fi
CFLAGS="-O2 -Wall -Wextra -Wno-unused-parameter -std=c99 -Isrc -Itests"
COMMON="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/dxf.c src/dxfread.c src/sfcread.c src/jwcread.c src/view.c src/draw.c src/text.c src/fontx.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
mkdir -p tests/out
$CC $CFLAGS -o tests/frame.exe    tests/frame.c    tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/shot.exe     tests/shot.c     tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/jww_test.exe tests/jww_test.c src/jww.c src/cp932.c
$CC $CFLAGS -o tests/write_test.exe tests/write_test.c src/jww.c src/jwwrite.c src/cp932.c
$CC $CFLAGS -o tests/pick_test.exe tests/pick_test.c $COMMON -lm
$CC $CFLAGS -o tests/read_test.exe tests/read_test.c $COMMON -lm
$CC $CFLAGS -o tests/click_test.exe tests/click_test.c tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/new_test.exe   tests/new_test.c   tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/sel_test.exe   tests/sel_test.c   tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/layer_test.exe tests/layer_test.c tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/sunpo_test.exe tests/sunpo_test.c tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/zoku_test.exe  tests/zoku_test.c  tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/session_test.exe tests/session_test.c tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/poly_test.exe  tests/poly_test.c  tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/mentori_test.exe tests/mentori_test.c tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/bunkatsu_test.exe tests/bunkatsu_test.c tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/nisen_test.exe tests/nisen_test.c tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/chushin_test.exe tests/chushin_test.c tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/zokuhen_test.exe tests/zokuhen_test.c $COMMON -lm
$CC $CFLAGS -o tests/xform_test.exe   tests/xform_test.c   $COMMON -lm
$CC $CFLAGS -o tests/dxf_test.exe     tests/dxf_test.c     $COMMON -lm
$CC $CFLAGS -o tests/dxfread_test.exe tests/dxfread_test.c $COMMON -lm
$CC $CFLAGS -o tests/sfcread_test.exe tests/sfcread_test.c $COMMON -lm
$CC $CFLAGS -o tests/jwcread_test.exe tests/jwcread_test.c $COMMON -lm
$CC $CFLAGS -o tests/block_test.exe   tests/block_test.c   $COMMON -lm
$CC $CFLAGS -o tests/menu_test.exe tests/menu_test.c tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/sessen_test.exe tests/sessen_test.c tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/sekien_test.exe tests/sekien_test.c tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/curve_test.exe tests/curve_test.c tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/hatch_test.exe tests/hatch_test.c tests/png.c $COMMON -lm
echo "built tests/frame.exe tests/shot.exe tests/jww_test.exe tests/pick_test.exe tests/read_test.exe tests/click_test.exe tests/write_test.exe tests/new_test.exe tests/sel_test.exe tests/layer_test.exe tests/sunpo_test.exe tests/zoku_test.exe tests/session_test.exe tests/poly_test.exe tests/mentori_test.exe tests/bunkatsu_test.exe tests/nisen_test.exe tests/chushin_test.exe tests/zokuhen_test.exe tests/xform_test.exe tests/dxf_test.exe tests/dxfread_test.exe tests/sfcread_test.exe tests/jwcread_test.exe tests/block_test.exe tests/menu_test.exe tests/sessen_test.exe tests/sekien_test.exe tests/curve_test.exe tests/hatch_test.exe"
