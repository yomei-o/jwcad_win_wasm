#!/bin/sh
# 図形がカーソルに付いてくるところ —— 原典は出す、移植は出さない。
#
#   sh tools/probe80.sh
#
# tools/probe76.sh の zukei で、カーソルのところに赤い画素が出ました。
# ただ十字カーソル自身も赤いので、図形の分と分けられませんでした。
# そこで**要素の多い図形**（17対面キッチン.jws、95 KB）を読んで、
# カーソルを二か所に置いて撮り、図形を読んでいない絵との差分を取ります。
# 図形が付いてくるなら、赤い画素が何百も出て、しかもカーソルと一緒に
# 動くはずです。
#
# 仮表示のラスタオペレータは R2_NOTXORPEN と分かっているので
# （tools/probe77.sh〜probe79.sh）、白地の上なら ffffff -> ff0000 です。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |wrote|frame" | sed 's/^/    /'
}

run none "m600,400;wait:800;shot:tmp/fig_none.png"
run at1  "figin:32862,tmp/bigfig.jws;m600,400;wait:1000;shot:tmp/fig_at1.png"
run at2  "figin:32862,tmp/bigfig.jws;m800,500;wait:1000;shot:tmp/fig_at2.png"
idle
sh tools/refenv.sh >/dev/null
