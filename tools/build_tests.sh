#!/bin/sh
# Build the native test programs.  Nothing here opens a window.
set -e
cd "$(dirname "$0")/.."
CC=${CC:-/c/prog/w64devkit/bin/gcc}
CFLAGS="-O2 -Wall -Wextra -Wno-unused-parameter -std=c99 -Isrc -Itests"
COMMON="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/view.c src/draw.c src/text.c src/fontx.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
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
echo "built tests/frame.exe tests/shot.exe tests/jww_test.exe tests/pick_test.exe tests/read_test.exe tests/click_test.exe tests/write_test.exe tests/new_test.exe tests/sel_test.exe tests/layer_test.exe"
