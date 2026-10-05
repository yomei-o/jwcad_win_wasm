#!/bin/sh
# 円の作図途中に 戻る を押すと、図面のほうが戻るのか。
#
#   sh tools/probe140.sh
#
# `tools/probe139.sh` で分かったこと: 円 の中心を置いてから 戻る を
# 押しても、**問いかけも置いた中心も変わりません**。そのあとクリック
# すると、戻る を押す前の中心から円が引かれます。円弧 でも同じで、
# 三回押しても「◆終点を指示してください」のままでした。
#
# 機械語の +0x40 は「点が置いてあれば 0 に戻して return 1」と読めたので、
# 読み違えたか、そこへ届いていないかのどちらかです。後者なら、押した分は
# **図面の一歩**を戻しているはず —— 円を一つ引いてから次の中心を置き、
# そこで押して確かめます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32773 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}
R='read:59393;'
U='raw:f,273,57643,0;wait:600;'

# one circle, then a centre, then 戻る -- and nothing more
run base "300,300;400,300;saveas:p140_base"
run undo "300,300;400,300;600,400;${R}${U}${R}saveas:p140_undo"
idle
echo
echo "--- 円を一つ引き、次の中心を置いて 戻る"
python tools/whatdid.py tmp/p140_base.jww tmp/p140_undo.jww 2>&1 | head -4
