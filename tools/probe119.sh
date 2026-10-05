#!/bin/sh
# 状態表示の 用紙 の箱は何を出すのか。
#
#   sh tools/probe119.sh
#
# 移植はこの箱で 縮尺・読取 のダイアログを開いていました。原典に
# WM_COMMAND 32825 を投げると上がってくるのは **#32768 のポップアップ**
# です（`popcmd:` を足しました）—— 用紙サイズ の十二項目で、いまの用紙に
# 印。窓は 127x270 で、移植の `JW_POPUP_ITEM_H` 22 と `JW_POPUP_BORDER` 3
# のまま 12 * 22 + 6 = 270 ちょうどです。
#
# 出る所は**ポインタに付いてきます**。カーソルを二箇所に置いて同じ命令を
# 投げると、窓の左上はどちらも (カーソル - 63, カーソル) でした。63 は
# (127-1)/2 なので、横はカーソルの真ん中・縦はカーソルから下です。
#
# 縮尺 (32827)・レイヤ (32829) の箱はポップアップを出しません（ダイアログ
# のまま）。メニューバーの 設定 の popup も撮ります —— そちらは札の末尾の
# 「(S)」まで出ているのに、用紙サイズ のポップアップには「(0)」が
# 付きません。同じ資源の札ではないということです。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "popup|throw|no " | sed 's/^/    /'
}

run youshi "cursor:400,300;popcmd:32825,docs/ref_youshi.png"
run follow "cursor:900,650;popcmd:32825,tmp/pop_b.png"
run settei "menu:S,tmp/menu_s.png"
idle
