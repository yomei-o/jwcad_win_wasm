#!/bin/sh
# ハッチの 図形 —— 縮尺で割るのか。
#
#   sh tools/probe88.sh
#
# 敷く一つ一つを作っているのは `FUN_00676210` で、そこは
#
#     新しい座標 = 元の座標 / dVar1 + (param_1, param_2)
#     dVar1 = *(doc + 0x2578 + 書込レイヤグループ * 8)    （縮尺）
#
# と読めます。囲みを測る `FUN_006765a0` も同じ割り算をしています。
# これまでの走り（probe85〜87）はどれも 1/1 の紙なので、割っても割らなく
# ても同じで、確かめられていません。**書込グループが 1/200 の Test5** で
# 同じことをして、敷かれたものが図形と同じ大きさか 200 分の一かを見ます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
idle; sh tools/refenv.sh >/dev/null; cp orig/Test5.jww tmp/rect.jww
$PS -Open tmp/rect.jww -Cmd 32772 -NoSave -Clicks \
  "300,300;800,600;cmd:32771;off:1333;880,180;980,180;880,180;880,210;cmd:32874;pb:1693;wait:800;pb:1067;wait:800;840,140;1000,330;pb:1068;wait:1000;set:1419,0;set:1411,60;set:1412,80;r550,300;btn:1148;saveas:p88" 2>&1 |
  grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
