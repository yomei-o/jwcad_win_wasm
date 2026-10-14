#!/bin/sh
# One test under AddressSanitizer with the report symbolized: the function and
# source line of every frame, which tools/asanone.sh does not do (node prints
# bare wasm offsets).
#
#   sh tools/asansym.sh nisen_test
#   JW_MOVE=1 sh tools/asansym.sh nisen_test          every growth of the element
#                                                     array moves it, so a pointer
#                                                     into it kept across a jw_add
#                                                     is a use after free here
#   JW_SAN=undefined sh tools/asansym.sh fuzz_test orig/Test1.jww
cd "$(dirname "$0")/.." || exit 1
T="$1"
[ -n "$T" ] || { echo "usage: sh tools/asansym.sh <name>_test [args...]"; exit 1; }
shift
SAN="${JW_SAN:-address}"
EMSDK="${EMSDK:-/c/prog/emsdk/emsdk}"
EMCC="$EMSDK/upstream/emscripten/emcc.exe"
SYM="$EMSDK/upstream/bin/llvm-symbolizer.exe"
NODE=""
for d in "$EMSDK"/node/*/bin "$EMSDK"/node/*; do
    [ -x "$d/node.exe" ] && { NODE="$d/node.exe"; break; }
done
[ -n "$NODE" ] || { echo "no node under $EMSDK"; exit 1; }
COMMON=$(sed -n '/^COMMON=/,/newjww.c"/p' tools/asanone.sh | sed 's/COMMON="//; s/"$//' | tr '\n' ' ')
EXTRA=""
grep -q '"png.h"' "tests/$T.c" && EXTRA="tests/png.c"
grep -q "plot.h" "tests/$T.c" && EXTRA="$EXTRA src/plot.c src/png.c"
case "$T" in imgfuzz_test) COMMON="src/image.c src/imgpic.c src/jww.c src/cp932.c" ;; esac
RUN=tmp/sym.$$
mkdir -p "$RUN"
trap 'rm -rf "$RUN"' EXIT
"$EMCC" -O1 -g -w -std=c99 -Isrc -Itests -fsanitize=$SAN ${JW_MOVE:+-DJW_ALWAYS_MOVE} \
    -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=1GB -sMAXIMUM_MEMORY=4GB \
    -sNODERAWFS=1 -sENVIRONMENT=node -sEXIT_RUNTIME=1 \
    -o "$RUN/t.js" "tests/$T.c" $EXTRA $COMMON || exit 1
ASAN_OPTIONS=quarantine_size_mb=16:symbolize=0:detect_leaks=0 UBSAN_OPTIONS=print_stacktrace=1 \
    "$NODE" "$RUN/t.js" "$@" > "$RUN/out" 2>&1
grep -a "ERROR: AddressSanitizer\|runtime error\|^BAD" "$RUN/out" | head -5
grep -a "^ *#[0-9]* 0x" "$RUN/out" | head -24 | while read -r line; do
    a=$(echo "$line" | sed -n 's/.*+\(0x[0-9a-f]*\))$/\1/p')
    if [ -n "$a" ] && [ -x "$SYM" ]; then
        f=$("$SYM" --obj="$RUN/t.wasm" "$a" 2>/dev/null | head -2 | tr '\n' ' ')
        echo "   $(echo "$line" | sed 's/ (C:.*//')  $f"
    else
        echo "   $line"
    fi
done
if ! grep -aq "ERROR: AddressSanitizer\|runtime error" "$RUN/out"; then
    echo "CLEAN $T"
fi
