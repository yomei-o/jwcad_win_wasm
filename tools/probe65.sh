#!/bin/sh
# 文字の 連結 の順と、切断 の位置をもう一手。
#
#   sh tools/probe65.sh
#
# tools/probe64.sh:
#
#   連結  AB（-94.2857 から）と CD（-69.7959 から）を置き、**AB を先に**
#         (L) で指し、次に CD を指したら、**'CDAB' が AB の始点に**
#         一本だけ残りました。つまり後で指したほうが前に付く。
#         逆の順でも同じ規則か、ここで確かめます。
#   切断  ABCD を一本置いて px 417 を (R) で指したら、'AB'（元の始点）と
#         'CD'（-83.2857 = AB の終わり + 0.5 = 字間の半分）に割れました。
#         別の境目でも同じか確かめます。
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

# the other way round: CD first, then AB
run join2 "cmd:32806;type:AB;400,400;type:CD;440,400;btn:1068;445,395;405,395;saveas:p65_join2"
# (R) at the second pick, which the status line calls 複写
run joinR "cmd:32806;type:AB;400,400;type:CD;440,400;btn:1068;405,395;r445,395;saveas:p65_joinR"
# cut after the first character: A ends at px 400+8.5 = 408
run cut2  "cmd:32806;type:ABCD;400,400;btn:1068;r409,395;saveas:p65_cut2"
idle
sh tools/refenv.sh >/dev/null
