#!/bin/sh
# One test, under AddressSanitizer, without the six stages of tools/asan.sh.
#
#   sh tools/asanone.sh bigcirc_test
#   sh tools/asanone.sh click_test orig/Test1.jww
#   JW_SAN=undefined sh tools/asanone.sh fuzz_test orig/Test1.jww
#
# tools/asan.sh takes hours because it builds every test twice.  When only
# one of them is in question -- checking a fix, or showing that the thing it
# fixed really did report -- this builds that one and runs it.
set -e
cd "$(dirname "$0")/.."
T="$1"
[ -n "$T" ] || { echo "usage: sh tools/asanone.sh <name>_test [args...]"; exit 1; }
shift
SAN="${JW_SAN:-address}"
EMSDK="${EMSDK:-/c/prog/emsdk/emsdk}"
EMCC="$EMSDK/upstream/emscripten/emcc.exe"
NODE=""
for d in "$EMSDK"/node/*/bin "$EMSDK"/node/*; do
    [ -x "$d/node.exe" ] && { NODE="$d/node.exe"; break; }
done
[ -n "$NODE" ] || { echo "no node under $EMSDK"; exit 1; }

COMMON="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c
        src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c
        src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c
        src/houraku.c src/view.c src/draw.c src/text.c src/fontx.c
        src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
EXTRA=""
grep -q '"png.h"' "tests/$T.c" && EXTRA="tests/png.c"

RUN=tmp/one.$$
mkdir -p "$RUN"
trap 'rm -rf "$RUN"' EXIT
"$EMCC" -O1 -g -w -std=c99 -Isrc -Itests -fsanitize=$SAN \
    -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=1GB -sMAXIMUM_MEMORY=4GB \
    -sNODERAWFS=1 -sENVIRONMENT=node -sEXIT_RUNTIME=1 \
    -o "$RUN/t.js" "tests/$T.c" $EXTRA $COMMON
echo "built $T (-fsanitize=$SAN)"
set +e
ASAN_OPTIONS=quarantine_size_mb=16 UBSAN_OPTIONS=print_stacktrace=1 \
    "$NODE" "$RUN/t.js" "$@" > "$RUN/out" 2>&1
code=$?
set -e
# grep -a: a test that prints bytes of a damaged file makes grep call the
# output binary, and then it says so instead of showing the line.
if grep -qa "ERROR: AddressSanitizer\|runtime error" "$RUN/out"; then
    echo "REPORTED:"
    grep -am1 -A12 "ERROR: AddressSanitizer" "$RUN/out" | sed 's/^/    /'
    grep -a "runtime error" "$RUN/out" | head -6 | sed 's/^/    /'
    exit 1
fi
grep -a "BAD" "$RUN/out" | head -6 | sed 's/^/    /'
echo "CLEAN $T (exit $code)"
