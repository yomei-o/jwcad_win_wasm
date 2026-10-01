#!/bin/sh
# 仮表示色 は どこまで及ぶのか —— 複写のゴーストと、図形の仮置き。
#
#   sh tools/probe76.sh
#
# tools/probe75.sh で、作図中の仮の図形が ff0000（仮表示色）だと
# 分かりました。同じ「まだ確定していないもの」がほかにも二つあります:
#
#   複写・移動 の、範囲がマウスに付いてくるゴースト
#   図形読込 の、図形がマウスに付いてくるところ
#
# 移植はどちらも要素自身のペンで描いています。原典はどうか、同じ手
# （PrintWindow で窓を絵にする。画面は読みません）で確かめます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp orig/Test5.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |wrote" | sed 's/^/    /'
}

# 複写: a range, then the ghost under the cursor
run fukusha "cmd:32804;250,250;r850,550;m700,600;wait:800;shot:tmp/pend_fukusha.png"
# 図形読込: the figure under the cursor
run zukei   "figin:32862,decomp/res/fig.jws;m700,500;wait:800;shot:tmp/pend_zukei.png"
idle
sh tools/refenv.sh >/dev/null
