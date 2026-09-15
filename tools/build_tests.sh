#!/bin/sh
# Build the native test programs.  Nothing here opens a window.
set -e
cd "$(dirname "$0")/.."
CC=${CC:-/c/prog/w64devkit/bin/gcc}
CFLAGS="-O2 -Wall -Wextra -Wno-unused-parameter -std=c99 -Isrc -Itests"
COMMON="src/fb.c src/ui.c src/app.c src/jww.c src/view.c src/draw.c src/gen/jwres.c"
mkdir -p tests/out
$CC $CFLAGS -o tests/frame.exe    tests/frame.c    tests/png.c src/fb.c src/ui.c src/gen/jwres.c
$CC $CFLAGS -o tests/shot.exe     tests/shot.c     tests/png.c $COMMON -lm
$CC $CFLAGS -o tests/jww_test.exe tests/jww_test.c src/jww.c
echo "built tests/frame.exe tests/shot.exe tests/jww_test.exe"
