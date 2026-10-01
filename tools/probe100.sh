#!/bin/sh
# 連続線の 連続弧 (2492) —— 終わらせ方が分かったので取り直し。
#
#   sh tools/probe100.sh
#
# `tools/probe99.sh` で歩きの全部が読めました:
#
#   始点を指示してください
#   　　◎　円弧の中間点を指示してください
#   ◆　　終点を指示してください
#   ◆　　終点を指示してください  << 同一点再指示で終了 ﾏｳｽ（L) >>
#
# 終わらせるのは**同じ点をもう一度左クリック**です（(R) ではありません。
# probe99 はそこで外しました）。
#
#   one    始点・中間点・終点、そこで終わり（弧一つ）
#   two    そのあともう一点（弧二つ？　それとも直線？）
#   plain  連続弧なしの同じクリック
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
N='cmd:32883;btn:2492;'

run one   "${N}300,300;400,250;500,300;500,300;saveas:p100_one"
run two   "${N}300,300;400,250;500,300;600,350;600,350;saveas:p100_two"
run plain "cmd:32883;300,300;400,250;500,300;500,300;saveas:p100_plain"
idle
