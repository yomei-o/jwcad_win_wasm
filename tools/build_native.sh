#!/bin/sh
# Build the native window, so the port can be held up against the original.
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
SRC="src/main_win32.c src/cp932.c src/pick.c src/app.c src/cmd.c src/ui.c src/fb.c src/jww.c src/jwwrite.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/view.c src/draw.c src/text.c src/fontx.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
$CC -O2 -Wall -Wextra -Wno-unused-parameter -std=c99 -Isrc -municode -mwindows \
    -o jw_port.exe $SRC -lgdi32 -luser32 -lcomdlg32 -limm32
echo "built jw_port.exe"
