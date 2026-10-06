#!/bin/sh
# 多角形 (32894) の 1068「中央」—— 基点の釦。
#
#   sh tools/probe160.sh
#
# つまみの掃き出しで、一度押すと多角形がクリック点から
# (+辺/2, +内接半径) ずれる（＝クリックが頂点になる）と出ました。
# 押し釦なので何度も押せます。何段あるのかを訊きます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 60 ] && { taskkill //F //IM Jw_win.exe >/dev/null 2>&1; break; }; sleep 1; done; }

# 一度の起動で、押しては一つ引く、を八回。辺寸法指定にしておきます。
steps='cmd:32894;btn:1692;500,400;saveas:p160_0;'
i=1
while [ $i -le 8 ]; do
    steps="${steps}btn:1068;500,400;saveas:p160_$i;read:59393;"
    i=$((i+1))
done
idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
$PS -Open tmp/rect.jww -NoSave -Clicks "$steps" 2>&1 |
    grep -aE "saved|read 59393|no control" | sed 's/^/    /'
idle
echo
prev=decomp/res/new.jww
for i in 0 1 2 3 4 5 6 7 8; do
    [ -f "tmp/p160_$i.jww" ] || continue
    echo "--- $i"
    python tools/whatdid.py "$prev" "tmp/p160_$i.jww" 2>&1 | head -6
    prev="tmp/p160_$i.jww"
done
