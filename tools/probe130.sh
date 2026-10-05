#!/bin/sh
# 測定 のバーは押すと札も変わるのか。
#
#   sh tools/probe130.sh
#
# `tools/probe129.sh` で読み出しの変わり方は分かりました。入れるには
# **釦の見た目**も要ります —— 小数桁 の札は「小数桁 3」なので、回したら
# 「小数桁 4」になるはず。mm /【ｍ】 も、四択のどれが凹むかも同じです。
# 押すたびにバーを書き出させて較べます。
#
# ついでに、面積測定 を mm にしたときの単位（ｍ2 が mm2 になるのか）も。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|^Button\|10(6|7)[0-9]\||throw|no " | sed 's/^/    /'
}
R='read:59393;'
S='raw:f,273,32897,0;wait:800;'

run digitcap "${S}bar;pb:1070;wait:500;bar;pb:1070;wait:500;bar;pb:1070;wait:500;bar;pb:1070;wait:500;bar"
run unitcap  "${S}pb:1069;wait:500;bar;pb:1069;wait:500;bar"
run pickcap  "${S}pb:1065;wait:500;bar;pb:1067;wait:500;bar"
run areamm   "${S}pb:1065;wait:400;pb:1069;wait:400;${R}300,300;700,300;700,500;300,500;${R}"
idle
