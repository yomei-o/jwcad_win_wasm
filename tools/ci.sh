#!/bin/sh
# One entry for "does everything still build and hold together", in minutes
# rather than the half hour of tools/check.sh.
#
#   sh tools/ci.sh            all the steps
#   sh tools/ci.sh fast       leave out the sanitizer pass (the slow one)
#   sh tools/ci.sh qtest wasm run just those steps (names below)
#
# Steps, in order:
#   tests    tools/build_tests.sh   every tests/*_test.c, with warnings on
#   qtest    tools/qtest.sh         the quick answer tests + offline fuzz cases
#   native   tools/build_native.sh  jw_port.exe (and src/main_win32.c compiles)
#   wasm     tools/build_wasm.sh    into tmp/wasmci (the shipped jwcad.* in the
#                                   repository root is not touched)
#   smoke    tools/smoke_wasm.js    that wasm under node: open, draw, save,
#                                   reopen, exports, plot, pictures, bad input
#   fuzz     the three damaged-input fuzzers, native, a few seconds each
#   browser  tools/web/cdp*.js      the same wasm in headless Chrome/Edge over DevTools
#                                   (SKIP: no browser found)
#   asan     tools/asanone.sh on the fuzzers and a few answer tests, under
#            AddressSanitizer and UndefinedBehaviorSanitizer (emscripten, node)
#
# Each step's output goes to tmp/ci/<step>.log.  The summary at the end says
# PASS, FAIL or SKIP (a tool that is not installed) for each, with its time,
# and the exit status is the number of steps that failed.
#
# It does not replace tools/check.sh (the comparison against the original's
# own answers, pixel for pixel) or tools/asan.sh / asanseeds.sh (hours).
cd "$(dirname "$0")/.." || exit 1
mkdir -p tmp/ci

# where the tools live, the same places the other scripts look
# (at the END of PATH: in front, w64devkit's busybox sh would replace the sh the
# build scripts run under, and its //c start /LOW wrapper then fails in cmd)
for d in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$d/gcc.exe" ] && { PATH="$PATH:$d"; export PATH; break; }
done
EMSDK="${EMSDK:-/c/prog/emsdk/emsdk}"
export EMSDK
NODE=""
if command -v node >/dev/null 2>&1; then
    NODE=$(command -v node)
else
    for d in "$EMSDK"/node/*/bin "$EMSDK"/node/*; do
        [ -x "$d/node.exe" ] && { NODE="$d/node.exe"; PATH="$PATH:$d"; export PATH; break; }
    done
fi
# emcc wants the python that came with emsdk when there is no other
if [ -z "$EMSDK_PYTHON" ]; then
    for p in "$EMSDK"/python/*/python.exe; do
        [ -x "$p" ] && { EMSDK_PYTHON="$p"; export EMSDK_PYTHON; break; }
    done
fi
HAVE_EMCC=0
[ -f "$EMSDK/upstream/emscripten/emcc.exe" ] && HAVE_EMCC=1
HAVE_GCC=0
command -v gcc >/dev/null 2>&1 && HAVE_GCC=1

want="$*"
[ "$1" = fast ] && want="tests qtest native wasm smoke browser fuzz"
[ -z "$want" ] && want="tests qtest native wasm smoke browser fuzz asan"

RESULTS=""
FAILS=0

# run <name> <needs: gcc|emcc|node|-> <command...>
run() {
    name=$1; needs=$2; shift 2
    case " $want " in *" $name "*) ;; *) return ;; esac
    skip=""
    case "$needs" in
        gcc)  [ $HAVE_GCC = 1 ] || skip="no gcc" ;;
        emcc) [ $HAVE_EMCC = 1 ] || skip="no emcc under $EMSDK" ;;
        node) [ -n "$NODE" ] || skip="no node" ;;
        emnode) [ $HAVE_EMCC = 1 ] && [ -n "$NODE" ] || skip="no emcc/node" ;;
    esac
    if [ -n "$skip" ]; then
        RESULTS="$RESULTS$(printf '%-8s SKIP  %s' "$name" "$skip")
"
        return
    fi
    printf '== %s ...\n' "$name"
    t0=$(date +%s)
    if "$@" > "tmp/ci/$name.log" 2>&1; then st=PASS; else st=FAIL; FAILS=$((FAILS + 1)); fi
    t1=$(date +%s)
    RESULTS="$RESULTS$(printf '%-8s %s  %4ss  tmp/ci/%s.log' "$name" "$st" "$((t1 - t0))" "$name")
"
    if [ $st = FAIL ]; then
        grep -a "BAD\|FAIL\|error\|Error\|REPORTED" "tmp/ci/$name.log" | head -5 | sed 's/^/     /'
    fi
}

step_qtest() {
    # qtest's own exit status is the answer tests; the last line is the
    # offline fuzz-case comparison, informational
    sh tools/qtest.sh
}

step_fuzz() {
    SRC=$(sed -n 's/^COMMON_SRC="\(.*\)"$/\1/p' tools/build_tests.sh)
    rc=0
    gcc -O2 -w -std=c99 -Isrc -Itests -o tmp/ci/fuzz.exe tests/fuzz_test.c $SRC -lm || return 1
    ls orig/*.jww decomp/res/*.jwf orig/*.jwf decomp/res/aci1.dxf decomp/res/geo.sfc decomp/res/t5.jwc \
        > tmp/ci/fuzz_files.txt
    xargs ./tmp/ci/fuzz.exe < tmp/ci/fuzz_files.txt || rc=1
    gcc -O2 -w -std=c99 -Isrc -Itests -o tmp/ci/cmdfuzz.exe tests/cmdfuzz_test.c $SRC -lm || return 1
    JW_CMDFUZZ_STEPS=800 ./tmp/ci/cmdfuzz.exe orig/Test1.jww orig/Test5.jww orig/Test7.jww || rc=1
    if ls tmp/img/dec_rgb.png >/dev/null 2>&1; then
        JW_CMDFUZZ_IMG=tmp/img/dec_rgb.png,tmp/img/dec_q95.jpg,tmp/img/dec_pal8.bmp \
            JW_CMDFUZZ_STEPS=800 ./tmp/ci/cmdfuzz.exe orig/Test1.jww || rc=1
        gcc -O1 -w -std=c99 -Isrc -o tmp/ci/imgfuzz.exe tests/imgfuzz_test.c src/image.c src/imgpic.c \
            src/jww.c src/cp932.c || return 1
        JW_FUZZ_ROUNDS=300 ./tmp/ci/imgfuzz.exe tmp/img/dec_*.bmp tmp/img/dec_*.png tmp/img/dec_*.jpg || rc=1
    fi
    gcc -O2 -w -std=c99 -Isrc -Itests -o tmp/ci/miscfuzz.exe tests/miscfuzz_test.c $SRC -lm || return 1
    JW_FUZZ_ROUNDS=100 ./tmp/ci/miscfuzz.exe orig/*.BAT orig/Test1.jww || rc=1
    gcc -O2 -w -std=c99 -Isrc -Itests -o tmp/ci/boxfuzz.exe tests/boxfuzz_test.c $SRC -lm || return 1
    ./tmp/ci/boxfuzz.exe orig/Test1.jww || rc=1
    gcc -O2 -w -std=c99 -Isrc -Itests -o tmp/ci/undoall.exe tests/undoall_test.c $SRC -lm || return 1
    ./tmp/ci/undoall.exe 12 || rc=1
    gcc -O2 -w -std=c99 -Isrc -Itests -o tmp/ci/newcode.exe tests/newcode_test.c $SRC -lm || return 1
    ./tmp/ci/newcode.exe tmp/img/dec_rgb.png tmp/img/dec_q95.jpg tmp/img/dec_pal8.bmp || rc=1
    JW_CMDFUZZ_EXTREME=1 JW_CMDFUZZ_STEPS=800 ./tmp/ci/cmdfuzz.exe orig/Test1.jww orig/Test7.jww || rc=1
    ! grep -a "^ *BAD" tmp/ci/fuzz.log || rc=1
    return $rc
}

step_asan() {
    rc=0
    for san in address undefined; do
        JW_SAN=$san sh tools/asanone.sh fuzz_test orig/Test1.jww orig/Test5.jww decomp/res/aci1.dxf \
            decomp/res/geo.sfc decomp/res/t5.jwc orig/Sample.jwf || rc=1
        if ls tmp/img/dec_rgb.png >/dev/null 2>&1; then
            JW_SAN=$san JW_FUZZ_ROUNDS=100 sh tools/asanone.sh imgfuzz_test tmp/img/dec_rgb24.bmp \
                tmp/img/dec_rgb.png tmp/img/dec_q95.jpg tmp/img/dec_prog.jpg || rc=1
        fi
        JW_SAN=$san JW_FUZZ_ROUNDS=60 sh tools/asanone.sh miscfuzz_test orig/*.BAT orig/Test1.jww || rc=1
        JW_SAN=$san JW_CMDFUZZ_STEPS=400 sh tools/asanone.sh cmdfuzz_test orig/Test1.jww || rc=1
        for t in flow promptsweep image env gaibu; do
            JW_SAN=$san sh tools/asanone.sh ${t}_test || rc=1
        done
    done
    # asanone says REPORTED: when a sanitizer fired, CLEAN otherwise
    ! grep -a "REPORTED" tmp/ci/asan.log || rc=1
    return $rc
}

# the pictures the image tests and fuzzers use, if python and Pillow are there
if [ ! -f tmp/img/dec_rgb.png ]; then
    python tools/mkimgs.py >/dev/null 2>&1 || true
fi

run tests  gcc    sh tools/build_tests.sh
run qtest  gcc    step_qtest
run native gcc    sh tools/build_native.sh
run wasm   emcc   env WASM_OUT=tmp/wasmci sh tools/build_wasm.sh
step_smoke() {
    [ -f tmp/wasmci/jwcad.js ] || { echo "no tmp/wasmci/jwcad.js: run the wasm step first"; return 1; }
    "$NODE" tools/smoke_wasm.js tmp/wasmci
}
run smoke  node   step_smoke
run fuzz   gcc    step_fuzz
step_browser() {
    [ -f tmp/wasmci/jwcad.js ] || { echo "no tmp/wasmci/jwcad.js: run the wasm step first"; return 1; }
    rc=0
    for t in cdp cdp_lang cdp_freehand cdp_auto cdp_robust cdp_pwa; do
        echo "== $t"
        WASM_DIR=tmp/wasmci CDP_PORT=9433 "$NODE" tools/web/$t.js || rc=1
    done
    ! grep -a "^BAD" tmp/ci/browser.log || rc=1
    return $rc
}
run asan   emnode step_asan
run browser node  step_browser


echo
echo "================ tools/ci.sh summary ================"
printf '%s' "$RESULTS"
if [ "$FAILS" = 0 ]; then
    echo "all steps passed (or were skipped for a missing tool)"
else
    echo "$FAILS step(s) FAILED -- see the logs named above"
fi
exit "$FAILS"
