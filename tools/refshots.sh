#!/bin/sh
# Take a reference screen of every sample drawing, without disturbing anyone.
#
#   sh tools/refshots.sh [outdir]
#
# This one has to run in the foreground (-Screen), which takes the screen for
# a few seconds per drawing, so do not run it while someone is working.
#
# -StableMs waits until Jw_cad's CPU time stops climbing rather than guessing
# a delay: it paints a big drawing slowly here (an x86 binary under emulation)
# and a fixed five-second wait catches a third of Test1.jww.  Watching the
# picture instead of the process does not work -- the paint comes in phases
# with a pause between them, so "the picture stopped changing" fires in the
# gap before the text is drawn.
#
# -Cmd 32835 is the 全体再表示 menu command.  The paint Jw_cad does when it
# first opens a file can stop part way -- 木造平面例.jww came out with 5,341
# ink pixels of its 13,613 however long the wait -- and asking for the redraw
# finishes it.  -Repaint (hide and show) is needed as well: Test6.jww stops
# at 8,903 of its 18,213 without it.  And even then it is not reliable --
# Ａマンション25d.jww comes out whole on one run and a fifth drawn on the
# next, with the same registry and the same file -- so -Tries 3 takes three
# and keeps the fullest.
#
# Background capture (PrintWindow) is not good enough for drawings.  It is
# exact for the frame, but the drawing area comes back stale or half drawn:
# 日影図.jww gives 7,979 ink pixels that way against 46,283 in the foreground,
# and asking for a RedrawWindow with RDW_UPDATENOW | RDW_ALLCHILDREN first
# changes nothing.  Whatever Jw_cad blits the view from, WM_PRINT does not
# reach it.
# Run tools/refenv.sh first: the original's toolbar layout has to match the
# one docs/ref_start.png was taken with, or the frame comes out different.
set -e
cd "$(dirname "$0")/.."
sh tools/refenv.sh
out=${1:-tmp/refs}
mkdir -p "$out"
i=0
for f in orig/*.jww; do
    i=$((i + 1))
    n=$(printf '%02d' $i)
    cp "$f" "tmp/d$n.jww"
    powershell -ExecutionPolicy Bypass -File tools/shot.ps1 \
        -Exe orig/Jw_win.exe -Open "tmp/d$n.jww" -Out "$out/d$n.png" \
        -Client -Screen -SettleMs 1500 -Repaint -Cmd 32835 -Tries 3 -StableMs 120000 >/dev/null
    echo "$out/d$n.png  <-  $f"
done
