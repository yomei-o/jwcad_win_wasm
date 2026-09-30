#!/bin/sh
# 半円 (1320) と、文字の 基点・行間・連.
#
#   sh tools/probe60.sh
#
# tools/probe57.sh left four things unasked:
#
#   半円 (1320)   two clicks drew nothing, so it wants more.  The status
#                 line is read after each click to see what it is after.
#   基点 (1064)   pressing it puts a modal window up, which held the
#                 script.  `dlg:b` opens it, writes its children out and
#                 cancels, so at least its controls can be read.
#   行間 (1418)   and 連 (1068), which is what 行間 is for: one text after
#                 another down the page.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|kid |Button|Static|throw|no |saved|wrote" |
        sed 's/^/    /'
}

R='read:59393;'
E='cmd:32773;'
M='cmd:32806;'

run han3   "${E}btn:1320;${R}300,300;${R}500,400;${R}500,200;${R}saveas:p60_han3"
run kijun  "${M}dlg:b1064,tmp/mojikijun.png"
run ren    "${M}chr:1418,20;btn:1068;type:AB;400,400;type:CD;saveas:p60_ren"
run ren0   "${M}btn:1068;type:AB;400,400;type:CD;saveas:p60_ren0"
idle
sh tools/refenv.sh >/dev/null
