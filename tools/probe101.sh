#!/bin/sh
# 仮表示の円は、置いた円とどう違うのか。
#
#   sh tools/probe101.sh
#
# `tools/probe82.sh` で、仮表示の円と置いた円が所々一画素ずれていること
# が分かりました（半径 30 画素）。ずれ方を見るには小さすぎるので、
# **大きい円**で撮り直します。
#
# 円 (32773) の中心を置いてカーソルを遠くへ動かすと、仮表示の円が
# ff0000 で出ます（紙は白なので、ff0000 はその円だけです）。そのまま
# クリックして置き、もう一度撮れば、同じ中心・同じ半径の円が黒で出ます。
# 二枚の画素を較べれば、原典が仮表示をどう描いているか（同じラスタ化か、
# 多角形の近似か）が見えます。
#
#   r200  半径 200 画素ほど
#   r80   半径 80 画素ほど
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "frame|throw|no " | sed 's/^/    /'
}

run r200 "cmd:32773;600,400;m800,400;wait:1200;shot:tmp/cir_pre200.png;800,400;wait:900;m300,650;wait:900;shot:tmp/cir_put200.png"
run r80  "cmd:32773;600,400;m680,400;wait:1200;shot:tmp/cir_pre80.png;680,400;wait:900;m300,650;wait:900;shot:tmp/cir_put80.png"
idle
sh tools/refenv.sh >/dev/null
