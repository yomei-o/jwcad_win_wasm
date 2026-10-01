#!/bin/sh
# 連続線の 連続弧 (2492) —— 三点を通る弧を繋ぐ。
#
#   sh tools/probe99.sh
#
# `tools/probe98.sh` で歩きが変わることが分かりました:
#
#   始点を指示してください
#   　　◎　円弧の中間点を指示してください
#   ◆　　終点を指示してください
#
# クリックの数が足りずに図面には何も残らなかったので、数を合わせて
# 取り直します。弧のあとまた「中間点」を訊くのか、それとも直線に
# 戻るのかを、問いかけを一手ごとに読んで確かめます。
#
#   arc3   三点だけ（弧一つ）
#   arc5   五点（弧二つ？）
#   plain  くらべる元（連続弧なし）
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
N='cmd:32883;btn:2492;'

run arc3  "${N}${R}300,300;${R}400,250;${R}500,300;${R}r500,300;${R}saveas:p99_arc3"
run arc5  "${N}300,300;400,250;500,300;${R}600,350;${R}700,300;${R}r700,300;${R}saveas:p99_arc5"
run plain "cmd:32883;300,300;400,250;500,300;r500,300;saveas:p99_plain"
idle
