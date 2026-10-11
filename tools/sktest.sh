#!/bin/sh
# 線記号変形の試験だけを手早く作って走らせる。
#   sh tools/sktest.sh [記号の名前]
# 全体の試験は tools/build_tests.sh（遅い）。ここは tmp/ob に .o を置き、
# 新しい .c だけ作り直す（.h を変えたら tmp/ob を消す）。
cd "$(dirname "$0")/.."
for d in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$d/gcc.exe" ] && { PATH="$d:$PATH"; export PATH; break; }
done
CFLAGS="-O1 -w -std=c99 -Isrc -Itests"
SRC="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/houraku.c src/tategu.c src/senkigou.c src/takaku.c src/hikage.c src/view.c src/draw.c src/text.c src/fontx.c src/plot.c src/png.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
mkdir -p tmp/ob
OBJ=""
pids=""
for f in $SRC; do
    o="tmp/ob/$(basename "$f" .c).o"
    if [ ! -f "$o" ] || [ "$f" -nt "$o" ] || [ -n "$(find src tests -name '*.h' -newer "$o" | head -1)" ]; then
        gcc $CFLAGS -c -o "$o" "$f" || exit 1 &
    fi
    OBJ="$OBJ $o"
done
wait
gcc $CFLAGS -o tmp/senkigou_test.exe tests/senkigou_test.c $OBJ -lm || exit 1
./tmp/senkigou_test.exe "$@"
