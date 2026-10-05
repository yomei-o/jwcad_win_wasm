#!/bin/sh
# 小粒の命令の第一陣、その二 —— 一度目で測り損ねた三つ。
#
#   sh tools/probe122.sh
#
# `tools/probe121.sh` で 数値角度 と 数値長 は取れました:
#
#   数値角度 (32938)  文字「30」を指すと、次の線が 30 度に。長さは
#                     クリックをその向きへ落としたぶん（線角度と同じ）
#   数値長 (32941)    同じ文字で、次の線が紙の上で 0.3 mm。縮尺 1/100 の
#                     図面なので、**30 は実寸**で、紙には 30/100 が出る
#
# 取れなかったのが次の三つで、こちらは測り方が悪かったほうです:
#
#   軸角 (32962)      線を指したあと 水平･垂直 を**入れて**引かないと差が
#                     出ません
#   レイヤ非表示化 (32936) 書込レイヤは消せません。他のレイヤに要素のある
#                     図面（orig/Test5.jww）で訊きます
#   寸法図形化 (32928) 一度目は寸法が一つも引けていませんでした
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp "$3" tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}
R='read:59393;'
N=decomp/res/new.jww
T=orig/Test5.jww
# the dimension of tools/refanswers.sh, line and all
S='300,600;700,600;cmd:32847;ch:1411,0;400,500;400,450;r300,600;r700,600;'

run jikbase "off:1333;300,300;700,500;on:1333;500,600;800,650;saveas:p122_jikbase" $N
run jik     "off:1333;300,300;700,500;raw:f,273,32962,0;wait:700;500,400;on:1333;500,600;800,650;saveas:p122_jik" $N
run hidebase "saveas:p122_hidebase" $T
run hide     "raw:f,273,32936,0;wait:700;${R}600,300;${R}saveas:p122_hide" $T
run dimbase "${S}saveas:p122_dimbase" $N
run dimfig  "${S}raw:f,273,32928,0;wait:700;${R}500,450;${R}saveas:p122_dimfig" $N
run dimoff  "${S}raw:f,273,32928,0;wait:700;500,450;raw:f,273,32929,0;wait:700;${R}500,450;${R}saveas:p122_dimoff" $N
idle
echo
echo "--- 軸角: 水平･垂直 で引いた線"
python tools/whatdid.py tmp/p122_jikbase.jww tmp/p122_jik.jww 2>&1 | head -6
echo "--- レイヤ非表示化: レイヤの状態"
python tools/laystate.py tmp/p122_hidebase.jww tmp/p122_hide.jww 2>&1 | head -20
echo "--- 寸法図形化"
python tools/whatdid.py tmp/p122_dimbase.jww tmp/p122_dimfig.jww 2>&1 | head -20
echo "--- 寸法図形解除"
python tools/whatdid.py tmp/p122_dimfig.jww tmp/p122_dimoff.jww 2>&1 | head -20
