#!/bin/sh
# tools/asan.sh reads the damaged copies with the default seed only, so the
# sanitizer has seen 393,900 of them where the plain Windows build has seen
# 7.9 million.  This runs the other seeds under AddressSanitizer too -- that
# is where the sfcread and jw_parse_jws holes came from, on seed one.
#
#   sh tools/asanseeds.sh              the twenty primes below
#   sh tools/asanseeds.sh 2 3          just those seeds
#   JW_SEED_JOBS=1 sh tools/asanseeds.sh   one at a time
#
# Three run at once by default.  The build box has four cores and 14 GB and
# one of these holds about 2 GB under the sanitizer, so three fit with room
# to spare, and twenty seeds come down from two and a half hours to about
# one.  They share the compiled fuzz.js, which nothing writes to while they
# run.
#
# Everything this writes goes under tmp/seeds.$$, a directory of its own, so
# two runs on the same machine cannot read each other's output.  An earlier
# sweep shared tmp/seed.out with a second sweep started before it and
# reported faults that belonged to neither; the names were the whole bug.
set -e
cd "$(dirname "$0")/.."
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

RUN=tmp/seeds.$$
mkdir -p "$RUN"
trap 'rm -rf "$RUN"' EXIT
rm -f tmp/seedbad.*.txt          # the count at the end is however many are left

"$EMCC" -O1 -g -w -std=c99 -Isrc -Itests \
    -fsanitize=address -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=1GB \
    -sMAXIMUM_MEMORY=4GB -sNODERAWFS=1 -sENVIRONMENT=node -sEXIT_RUNTIME=1 \
    -o "$RUN/fuzz.js" tests/fuzz_test.c $COMMON
echo "built in $RUN"

SEEDS="$*"
[ -n "$SEEDS" ] || SEEDS="2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71"
JWS=$(ls decomp/res/*.jws 2>/dev/null)

# How many at once.  The build box has four cores and 14 GB, and one of
# these holds about 2 GB under the sanitizer, so three leaves room.  They
# share the compiled fuzz.js, which nothing writes to while they run, and
# each keeps its own output; the seeds do not talk to each other.
JOBS="${JW_SEED_JOBS:-3}"

one_seed() {
    s="$1"
    out="$RUN/out.$s"
    set +e
    ASAN_OPTIONS=quarantine_size_mb=16:malloc_context_size=6 \
    JW_FUZZ_SEED=$s JW_FUZZ_TRACE=1 \
        "$NODE" "$RUN/fuzz.js" orig/*.jww decomp/res/*.jww $JWS \
            decomp/res/*.dxf decomp/res/*.sfc decomp/res/*.jwc \
            > "$out" 2>&1
    set -e
    # grep -a: the damaged copies put raw bytes in the trace, and without it
    # grep answers "Binary file matches" instead of the line we want.
    if grep -qa "ERROR: AddressSanitizer" "$out"; then
        {
            echo "SEEDBAD $s -- last case tried:"
            grep -a "^try " "$out" | tail -1 | sed 's/^/    /'
            grep -am1 -A6 "ERROR: AddressSanitizer" "$out" | sed 's/^/    /'
            cp "$out" "tmp/seedbad.$s.txt"
            echo "    (whole run kept in tmp/seedbad.$s.txt)"
        } > "$RUN/say.$s"
    elif grep -qa "out of memory" "$out"; then
        echo "SEEDROOM $s -- the sanitizer ran out of room, not a fault" \
            > "$RUN/say.$s"
    else
        echo "  seed $s ok: $(grep -av '^try ' "$out" | tail -1)" \
            > "$RUN/say.$s"
    fi
    rm -f "$out"
}

# Say each seed's line as soon as its own run is over, but in seed order, so
# that a reader can tell at a glance how far along it is.
running=0
for s in $SEEDS; do
    one_seed "$s" &
    running=$((running + 1))
    if [ "$running" -ge "$JOBS" ]; then
        wait
        running=0
        for t in $SEEDS; do
            [ -f "$RUN/say.$t" ] || continue
            cat "$RUN/say.$t"
            rm -f "$RUN/say.$t"
        done
    fi
done
wait
for t in $SEEDS; do
    [ -f "$RUN/say.$t" ] || continue
    cat "$RUN/say.$t"
    rm -f "$RUN/say.$t"
done
bad=$(ls tmp/seedbad.*.txt 2>/dev/null | wc -l)
echo "SEEDSDONE $bad bad"
