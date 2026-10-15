#!/bin/sh
# Quick check: build and run only the named tests (tests/<name>_test.c), then
# the offline fuzz cases.  Uses the same object cache as replay.sh, so only
# the sources you touched are recompiled.
#
#   sh tools/qtest.sh                 # a default handful for the edit commands
#   sh tools/qtest.sh bunkatsu hk     # just these
#
# tools/check.sh (everything, ~25 min) is for before a push, not every edit.
cd "$(dirname "$0")/.."
sh tools/replay.sh >/dev/null || exit 1
for d in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$d/gcc.exe" ] && { PATH="$d:$PATH"; export PATH; break; }
done
[ $# -eq 0 ] && set -- bunkatsu nisen mentori mentori2 mentoriarc renzoku chushin waritsuke undostep poly renarc env image flow promptsweep bunkpar hk gaibu mojisel cmdcover dxfsynth jwwver longtext blkcycle rtsynth imgedge perf leak house boxfuzz dxfextreme undoall gaibuwalk mojiwalk boxfresh imgopt tdlg status rchain shinshuku zokumoji param numpos curve workflow prefs kihonfx
OBJ=$(ls tmp/ob/*.o | grep -v replay)
bad=0
for t in "$@"; do
    gcc -O1 -w -std=c99 -Isrc -Itests -o tmp/q_$t.exe tests/${t}_test.c tests/png.c $OBJ -lm -lpsapi || { echo "BUILD FAIL $t"; bad=1; continue; }
    if ./tmp/q_$t.exe >tmp/q_$t.log 2>&1; then echo "ok   $t"; else echo "FAIL $t (tmp/q_$t.log)"; bad=1; fi
done
if python -c 1 >/dev/null 2>&1; then PYTHONIOENCODING=utf-8 python tools/fzcheck.py | tail -1; else echo "fuzz check skipped (no python)"; fi
exit $bad
