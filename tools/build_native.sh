#!/bin/sh
# Build the native window, so the port can be held up against the original.
set -e
cd "$(dirname "$0")/.."
CC=${CC:-/c/prog/w64devkit/bin/gcc}
$CC -O2 -Wall -Wextra -Wno-unused-parameter -std=c99 -Isrc -municode -mwindows \
    -o jw_port.exe \
    src/main_win32.c src/app.c src/ui.c src/fb.c src/gen/jwres.c \
    -lgdi32 -luser32
echo "built jw_port.exe"
