#!/bin/sh
# Take a reference screen of every sample drawing, without disturbing anyone.
#
#   sh tools/refshots.sh [outdir]
#
# This one has to run in the foreground (-Screen), which takes the screen for
# a few seconds per drawing, so do not run it while someone is working.
#
# Background capture (PrintWindow) is not good enough for drawings.  It is
# exact for the frame, but the drawing area comes back stale or half drawn:
# 日影図.jww gives 7,979 ink pixels that way against 46,283 in the foreground,
# and asking for a RedrawWindow with RDW_UPDATENOW | RDW_ALLCHILDREN first
# changes nothing.  Whatever Jw_cad blits the view from, WM_PRINT does not
# reach it.
set -e
cd "$(dirname "$0")/.."
out=${1:-tmp/refs}
mkdir -p "$out"
i=0
for f in orig/*.jww; do
    i=$((i + 1))
    n=$(printf '%02d' $i)
    cp "$f" "tmp/d$n.jww"
    powershell -ExecutionPolicy Bypass -File tools/shot.ps1 \
        -Exe orig/Jw_win.exe -Open "tmp/d$n.jww" -Out "$out/d$n.png" \
        -Client -Screen -SettleMs 5000 >/dev/null
    echo "$out/d$n.png  <-  $f"
done
