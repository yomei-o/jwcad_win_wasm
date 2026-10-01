#!/bin/sh
# 円の 終点半径 (1319) と、連続線の 連続弧 (2492)・手書線 (1774)。
#
#   sh tools/probe98.sh
#
# `python tools/barcover.py` が出した「src/cmd.c に名前も出てこない」
# つまみのうち、作図そのものを変えそうなものです。
#
#   r_plain  円弧 (1318) だけ、くらべる元
#   r_shu    円弧 ＋ 終点半径 (1319)。名前からすると終点側の半径を別に
#            取る（＝楕円の弧になる？）はずで、四つ目のクリックを足して
#            みます
#   r_shu3   同じで三クリックのまま（四つ目が要るのかどうか）
#   ren_arc  連続線 (32883) ＋ 連続弧 (2492)
#   ren_te   連続線 ＋ 手書線 (1774)
#   ren_0    連続線のまま、くらべる元
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
R='read:59393;'
E='cmd:32773;'
N='cmd:32883;'

run r_plain "${E}btn:1318;300,300;500,400;500,200;saveas:p98_r_plain"
run r_shu   "${E}btn:1318;btn:1319;${R}300,300;${R}500,400;${R}500,200;${R}700,300;${R}saveas:p98_r_shu"
run r_shu3  "${E}btn:1318;btn:1319;300,300;500,400;500,200;saveas:p98_r_shu3"
run ren_0   "${N}300,300;500,400;600,300;r600,300;saveas:p98_ren_0"
run ren_arc "${N}btn:2492;${R}300,300;${R}500,400;${R}600,300;${R}r600,300;saveas:p98_ren_arc"
run ren_te  "${N}btn:1774;${R}300,300;${R}500,400;${R}600,300;${R}r600,300;saveas:p98_ren_te"
idle
