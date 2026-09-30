#!/bin/sh
# 間隔取得 (32948) again: does it set 複線's 前回値?
#
#   sh tools/probe48.sh
#
# What it is not, so far:
#   * not a 長さ -- the line drawn after it came out the same as the line
#     drawn without it (tools/probe44.sh)
#   * not in any box -- the 線 bar's two combos and the 複線 bar's two
#     came up empty with it and without (tools/probe46.sh, probe47.sh)
#   * not 複線's offset when the line is picked with (L) -- both walks
#     put the copy at the clicked distance (tools/probe47.sh)
#
# But 複線's own first prompt says 「複線にする図形を選択してください
# ﾏｳｽ(L)　前回値 ﾏｳｽ(R)」 -- picking with (R) uses the **前回値**, a
# number that is never shown.  That is the one place left that takes a
# distance without being typed.  So: grab 164.28 mm, then pick the line
# with (R) and see where the copy lands.  Without the grab the 前回値 is
# whatever the walk before left, so a plain 複線 runs first in both, to
# put the same thing there.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

L='cmd:32771;off:1333;300,300;700,500;'
G='cmd:32948;500,400;r300,600;'
R='read:59393;'
# one plain 複線 first, so the 前回値 is the same in both runs
F='cmd:32800;500,400;500,200;500,200;'

run r_k "${L}${F}${G}cmd:32800;${R}r500,400;${R}500,200;${R}saveas:p48_r_k"
run r_0 "${L}${F}cmd:32800;${R}r500,400;${R}500,200;${R}saveas:p48_r_0"
idle
sh tools/refenv.sh >/dev/null
