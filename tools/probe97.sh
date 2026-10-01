#!/bin/sh
# 文字の 垂直 (1324) —— 答えを probe57 と同じ所で取り直し。
#
#   sh tools/probe97.sh
#
# tools/probe95.sh で 垂直 と 垂直＋縦字 が分かりましたが、クリックが
# (400,300) で、ほかの文字の答え（probe57 の mo_*）は (400,400) です。
# tests/mojidraw_test.c は一か所で突き合わせるので、同じ (400,400) で
# 取り直します。
#
#   vert       垂直 (1324)
#   vert_tate  垂直 と 縦字 (1325) の両方 —— 走りが**下へ**向きます
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "throw|no |saved" | sed 's/^/    /'
}
M='cmd:32806;'
run vert      "${M}btn:1324;type:ABC;400,400;saveas:decomp/res/moji_vert.jww"
run vert_tate "${M}btn:1324;btn:1325;type:ABC;400,400;saveas:decomp/res/moji_vert_tate.jww"
idle
