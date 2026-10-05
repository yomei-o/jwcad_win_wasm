#!/bin/sh
# 円の 作図途中の 戻る —— 機械語で読んだ 5 → 2 → 0 を押して確かめます。
#
#   sh tools/probe139.sh
#
# `CZukeiEnko` の +0x40 はこうなっています:
#
#   点が置いてあれば  +0x308 = (+0xe8 == 0 && +0x308 == 5) ? 2 : 0
#   置いていなければ  +0xf8 が 0 なら何もしない
#
# つまり二段。問いかけを一手ごとに読めば、どの状態がどれに当たるか
# 分かります。円 (32773) の素の歩きと、円弧 (1318) を入れた三点の歩きで。
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
# 戻る is Ctrl+Z; the frame takes the key (0xe12b is the menu id)
U='raw:f,273,57643,0;wait:500;'

run plain "${R}400,400;${R}${U}${R}${U}${R}500,500;600,500;saveas:p139_plain"
run arc   "pb:1318;wait:600;${R}400,400;${R}500,400;${R}${U}${R}${U}${R}${U}${R}"
idle
echo
echo "--- 素の円で 戻る を二回したあと引いた円"
python tools/whatdid.py decomp/res/new.jww tmp/p139_plain.jww 2>&1 | head -4
