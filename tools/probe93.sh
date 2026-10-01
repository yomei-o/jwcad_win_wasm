#!/bin/sh
# 間隔取得 (32948) —— 残りの二つ。
#
#   sh tools/probe93.sh
#
# `tools/probe90.sh`・`probe92.sh` で行き先は割れました（複線の間隔）。
# まだ訊いていないのは:
#
#   box   複線間隔 (1411) に数が入っているとき、どちらが勝つのか。
#         長さ取得 のときは「打ち込んだ箱が勝ち」でした（probe22）が、
#         こちらは別物なので訊き直します。箱に 50 を打ってから
#         間隔取得 で 164.28 を取り、どちらで複写されるかを見ます
#   keep  取った値は次の複線にも残るのか。一本複写してから、同じ命令で
#         もう一本複写してみます
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

B='cmd:32771;off:1333;300,300;700,500;cmd:32785;300,600;'
K='cmd:32948;500,400;r300,600;'
R='read:59393;'

run box  "${B}cmd:32800;chr:1411,50;500,400;${R}${K}${R}500,200;${R}saveas:p93_box"
run keep "${B}cmd:32800;500,400;${K}500,200;${R}500,400;${R}500,200;${R}saveas:p93_keep"
idle
