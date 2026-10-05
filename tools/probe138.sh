#!/bin/sh
# 割付 の「距離」は、平行でない二本ではどこで測っているのか。
#
#   sh tools/probe138.sh
#
# `tools/probe136.sh` は水平な二本で測ったので、始点どうしの距離・終点
# どうしの距離・垂線の距離がどれも同じでした。平行でない二本なら割れます。
#
#   Ａ (300,300)-(700,300)      水平、長さ 400 画素
#   Ｂ (300,600)-(700,700)      右下がり、始点どうしは 300 画素、
#                               終点どうしは 400 画素
#
# 距離 6000（紙で 60 mm）で割付して、出てくる線の位置を見ます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}
L='off:1333;300,300;700,300;300,600;700,700;cmd:32867;'

run base "${L}saveas:decomp/res/wari_xbase.jww"
run off  "${L}pb:1324;wait:800;ch:1412,6000;500,300;500,650;saveas:decomp/res/wari_xoff.jww"
run on   "${L}pb:1324;wait:800;pb:1326;wait:500;ch:1412,6000;500,300;500,650;saveas:decomp/res/wari_xon.jww"
idle
echo
echo "--- 平行でない二本、割付だけ"
python tools/whatdid.py decomp/res/wari_xbase.jww decomp/res/wari_xoff.jww 2>&1 | head -10
echo "--- 同じく 割付距離以下"
python tools/whatdid.py decomp/res/wari_xbase.jww decomp/res/wari_xon.jww 2>&1 | head -10
