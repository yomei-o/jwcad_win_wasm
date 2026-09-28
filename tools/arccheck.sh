#!/bin/sh
# Build tools/arccheck.c, which calls src/draw.c's own gdi_arc.
#
#   sh tools/arccheck.sh && python tools/arccheck.py
#
# `-Dstatic=` opens src/draw.c up so the harness can reach gdi_arc; the
# other sources are compiled as usual, so nothing else changes.
cd "$(dirname "$0")/.."
case ":$PATH:" in
    *:/c/prog/tools/w64devkit/bin:*) ;;
    *) PATH="$PATH:/c/prog/tools/w64devkit/bin" ;;
esac
mkdir -p tmp
gcc -O1 -w -std=c99 -Isrc -Dstatic= -c -o tmp/draw_open.o src/draw.c || exit 1
gcc -O1 -w -std=c99 -Isrc -o tmp/arccheck.exe tools/arccheck.c tmp/draw_open.o \
    src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c \
    src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c \
    src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c \
    src/houraku.c src/view.c src/text.c src/fontx.c \
    src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c -lm || exit 1
echo built tmp/arccheck.exe
