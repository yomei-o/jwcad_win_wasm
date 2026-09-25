#!/bin/sh
# Run the fuzzers under AddressSanitizer, and then under the undefined
# behaviour one.
#
#   sh tools/asan.sh
#
# tests/fuzz_test.c hands the readers copies of a file cut short, each one
# allocated at exactly its length, so a read that runs off the end lands in
# the malloc'd block next door.  Nothing on Windows notices that: w64devkit
# ships no libasan, and the plain build only catches a read far enough past
# the end to leave the heap block outright.
#
# Emscripten's clang does have AddressSanitizer, and the fuzzer is plain C
# with no Windows in it, so the whole thing builds for node and runs there
# with every byte watched.  That is how the two unguarded reads in
# src/sfcread.c's lexer were found (a file that stops right after `/*SXF`),
# and the 452-byte header a .jws copies whole even when the file is shorter.
#
# It is not in check.sh: the build takes a few minutes and the run is some
# thirty times slower than the native one.  Run it after touching a reader.
cd "$(dirname "$0")/.."
EMSDK="${EMSDK:-/c/prog/emsdk/emsdk}"
EMCC="$EMSDK/upstream/emscripten/emcc.exe"
[ -f "$EMCC" ] || { echo "emcc not found at $EMCC" >&2; exit 1; }
# node comes with emsdk and is not on PATH; where it sits inside the node
# package moved between the 22 and 24 series, so look in both places
NODE=""
for d in "$EMSDK"/node/*/bin "$EMSDK"/node/*; do
    [ -x "$d/node.exe" ] && { NODE="$d/node.exe"; break; }
done
[ -n "$NODE" ] || { echo "no node under $EMSDK/node" >&2; exit 1; }

COMMON="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c
        src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c
        src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c
        src/houraku.c src/view.c src/draw.c src/text.c src/fontx.c
        src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
mkdir -p tmp
# NODERAWFS so it can open the drawings where they are; the heap has to be
# big enough for the shadow map as well as the drawings, and the run makes
# some three hundred thousand allocations, so it needs room to spare
"$EMCC" -O1 -g -w -std=c99 -Isrc -Itests -fsanitize=address \
    -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=1GB -sMAXIMUM_MEMORY=4GB \
    -sNODERAWFS=1 -sENVIRONMENT=node -sEXIT_RUNTIME=1 \
    -o tmp/fuzz_asan.js tests/fuzz_test.c $COMMON || exit 1
echo "built tmp/fuzz_asan.js"

JWS=$(ls decomp/res/*.jws 2>/dev/null)
# JW_FUZZ_TRACE names each case before it is read: a sanitizer build stops
# at the fault with no stack worth reading, and the last line is what says
# which file, and how much of it, got there.
# freed blocks are held back to catch use-after-free, which this does not
# need: without a small quarantine the run fills memory and stops with
# "allocator is trying to allocate", which is not a fault in the port
ASAN_OPTIONS=quarantine_size_mb=16:malloc_context_size=6 \
JW_FUZZ_TRACE=1 "$NODE" tmp/fuzz_asan.js orig/*.jww decomp/res/*.jww $JWS \
    decomp/res/*.dxf decomp/res/*.sfc decomp/res/*.jwc > tmp/asan.out 2>&1
st=$?
if grep -q "out of memory" tmp/asan.out; then
    echo "BAD  the sanitizer ran out of room, not a fault in the port --"
    echo "     give it more INITIAL_MEMORY or a smaller quarantine"
    grep "^try " tmp/asan.out | tail -1 | sed 's/^/    /'
    exit 1
fi
if grep -q "AddressSanitizer" tmp/asan.out; then
    echo "BAD  AddressSanitizer stopped it -- the last case tried was:"
    grep "^try " tmp/asan.out | tail -1 | sed 's/^/    /'
    grep -m1 -A2 "ERROR: AddressSanitizer" tmp/asan.out | sed 's/^/    /'
    exit 1
fi
[ "$st" = 0 ] || { echo "BAD  it stopped with $st"; tail -5 tmp/asan.out; exit 1; }
grep -v "^try " tmp/asan.out | tail -2
echo "ok   the readers, no AddressSanitizer report"

# And the same for the command fuzzer, which walks the whole port rather
# than the readers: commands, the drawing code and the writers all run with
# every byte watched.
"$EMCC" -O1 -g -w -std=c99 -Isrc -Itests -fsanitize=address \
    -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=1GB -sMAXIMUM_MEMORY=4GB \
    -sNODERAWFS=1 -sENVIRONMENT=node -sEXIT_RUNTIME=1 \
    -o tmp/cmdfuzz_asan.js tests/cmdfuzz_test.c $COMMON || exit 1
echo "built tmp/cmdfuzz_asan.js"

bad=0
for s in 1 2 3; do
    for args in "orig/Test1.jww orig/Test5.jww orig/Test7.jww" ""; do
        ASAN_OPTIONS=quarantine_size_mb=16:malloc_context_size=6 \
        JW_CMDFUZZ_SEED=$s JW_CMDFUZZ_STEPS=600 \
            "$NODE" tmp/cmdfuzz_asan.js $args > tmp/asan_cmd.out 2>&1
        st=$?
        if grep -q "ERROR: AddressSanitizer" tmp/asan_cmd.out; then
            echo "BAD  seed $s ${args:-(from nothing)}:"
            grep -m1 -A4 "ERROR: AddressSanitizer" tmp/asan_cmd.out |
                sed 's/^/    /'
            bad=$((bad + 1))
        elif [ "$st" != 0 ]; then
            echo "BAD  seed $s ${args:-(from nothing)} stopped with $st"
            tail -4 tmp/asan_cmd.out | sed 's/^/    /'
            bad=$((bad + 1))
        fi
    done
done
[ "$bad" = 0 ] || exit 1
echo "ok   the commands, no AddressSanitizer report"

# UndefinedBehaviorSanitizer next.  It reports and carries on rather than
# stopping, so the count is what matters.  This is what found the misaligned
# short in jw_from_utf16 -- a .jww's strings start wherever they fall in the
# file, so pool_put was handing it odd addresses.
for t in fuzz cmdfuzz; do
    "$EMCC" -O1 -g -w -std=c99 -Isrc -Itests -fsanitize=undefined \
        -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=512MB -sNODERAWFS=1 \
        -sENVIRONMENT=node -sEXIT_RUNTIME=1 \
        -o "tmp/${t}_ub.js" "tests/${t}_test.c" $COMMON || exit 1
done
echo "built tmp/fuzz_ub.js and tmp/cmdfuzz_ub.js"

UBSAN_OPTIONS=print_stacktrace=1 \
    "$NODE" tmp/fuzz_ub.js orig/*.jww decomp/res/*.jww $JWS \
        decomp/res/*.dxf decomp/res/*.sfc decomp/res/*.jwc > tmp/ub.out 2>&1
for s in 1 2 3; do
    for args in "orig/Test1.jww orig/Test5.jww orig/Test7.jww" ""; do
        UBSAN_OPTIONS=print_stacktrace=1 JW_CMDFUZZ_SEED=$s \
            JW_CMDFUZZ_STEPS=1500 "$NODE" tmp/cmdfuzz_ub.js $args \
            >> tmp/ub.out 2>&1
    done
done
n=$(grep -c "runtime error" tmp/ub.out)
if [ "$n" != 0 ]; then
    echo "BAD  $n undefined-behaviour reports, the commonest first:"
    grep "runtime error" tmp/ub.out | sed 's/: runtime error/ ->/' |
        sort | uniq -c | sort -rn | head -8 | sed 's/^/    /'
    exit 1
fi
echo "ok   nothing undefined either"

# And the drawing itself, which neither fuzzer covers: a whole window, over
# every bundled drawing and a spread of window sizes.  The bars and buttons
# are laid out for 1264 pixels across, so a narrow window is what pushes
# them off the edge -- that is how ui.c's checker() was caught writing past
# the framebuffer.
for san in address undefined; do
    "$EMCC" -O1 -g -w -std=c99 -Isrc -Itests -fsanitize=$san \
        -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=1GB -sMAXIMUM_MEMORY=4GB \
        -sNODERAWFS=1 -sENVIRONMENT=node -sEXIT_RUNTIME=1 \
        -o tmp/shot_san.js tests/shot.c tests/png.c $COMMON || exit 1
    : > tmp/asan_shot.out
    mkdir -p tmp/sanshot
    for f in orig/*.jww; do
        ASAN_OPTIONS=quarantine_size_mb=16 UBSAN_OPTIONS=print_stacktrace=1 \
            "$NODE" tmp/shot_san.js \
            "tmp/sanshot/$(basename "$f" .jww).png" "$f" \
            >> tmp/asan_shot.out 2>&1
    done
    for wh in "1 1" "20 20" "100 80" "200 150" "640 480" "2000 1200"; do
        ASAN_OPTIONS=quarantine_size_mb=16 UBSAN_OPTIONS=print_stacktrace=1 \
            "$NODE" tmp/shot_san.js tmp/sanshot/sz.png orig/Test1.jww $wh \
            >> tmp/asan_shot.out 2>&1
    done
    n=$(grep -c "runtime error\|ERROR: AddressSanitizer" tmp/asan_shot.out)
    if [ "$n" != 0 ]; then
        echo "BAD  $n reports while drawing (-fsanitize=$san):"
        grep -m1 -A6 "ERROR: AddressSanitizer" tmp/asan_shot.out |
            sed 's/^/    /'
        grep "runtime error" tmp/asan_shot.out | sed 's/: runtime error/ ->/' |
            sort | uniq -c | sort -rn | head -6 | sed 's/^/    /'
        exit 1
    fi
done
echo "ok   the drawing too, at every window size"
