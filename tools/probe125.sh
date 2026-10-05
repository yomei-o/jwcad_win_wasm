#!/bin/sh
# 測定 (32897) と 距離指定点 (32930) —— 問いかけを一手ずつ追います。
#
#   sh tools/probe125.sh
#
# `tools/probe120.sh` で、測定 は問いかけの末尾に
# 「S = 1 / 100 【 0.000ｍ 】 0ｍ」を足し、距離指定点 は角度の印を落とす
# ことまで分かりました。どちらも**一手ごとに状態表示が変わる**たちの
# 命令なので、クリックのたびに読みます。測定は四角形を一周させて、
# 長さの足し算と面積がどこに出るかを見ます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|^(Button|ComboBox|Edit|Static)\||throw|no |saved" |
        sed 's/^/    /'
}
R='read:59393;'

# 測定: the bar it puts up, then four corners of a 400x200 px box
run sokutei-bar "raw:f,273,32897,0;wait:800;${R}bar"
run sokutei "raw:f,273,32897,0;wait:800;300,300;${R}700,300;${R}700,500;${R}300,500;${R}300,300;${R}"
# 距離指定点: the bar, then two clicks
run kyori-bar "raw:f,273,32930,0;wait:800;${R}bar"
run kyori "raw:f,273,32930,0;wait:800;300,300;${R}700,500;${R}saveas:p125_kyori"
idle
echo
echo "--- 距離指定点 が何を置いたか"
python tools/whatdid.py decomp/res/new.jww tmp/p125_kyori.jww 2>&1 | head -10
