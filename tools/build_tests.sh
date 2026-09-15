#!/bin/sh
# Build the native test programs.  Nothing here opens a window.
set -e
CC=${CC:-/c/prog/w64devkit/bin/gcc}
CFLAGS="-O2 -Wall -Wextra -Wno-unused-parameter -std=c99 -Isrc -Itests"
mkdir -p tests/out
$CC $CFLAGS -o tests/frame.exe \
    tests/frame.c tests/png.c src/fb.c src/ui.c src/gen/jwres.c
echo "built tests/frame.exe"
