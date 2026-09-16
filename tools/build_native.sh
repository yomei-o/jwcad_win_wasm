#!/bin/sh
# Build the native window, so the port can be held up against the original.
set -e
cd "$(dirname "$0")/.."
CC=${CC:-/c/prog/w64devkit/bin/gcc}
SRC="src/main_win32.c src/cp932.c src/pick.c src/app.c src/cmd.c src/ui.c src/fb.c src/jww.c src/jwwrite.c src/view.c src/draw.c src/text.c src/fontx.c src/gen/jwres.c src/gen/jwfont.c"
$CC -O2 -Wall -Wextra -Wno-unused-parameter -std=c99 -Isrc -municode -mwindows \
    -o jw_port.exe $SRC -lgdi32 -luser32 -lcomdlg32 -limm32
echo "built jw_port.exe"
