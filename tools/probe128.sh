#!/bin/sh
# 距離指定点 (32930) —— 箱の距離で点を置く。
#
#   sh tools/probe128.sh
#
# バーは 仮点 (1323)・距離 (1412)・連続 (1066) の三つだけ
# （`tools/probe125.sh`）。一点目を打つと問いかけが
#
#   線上･円周距離は線･円指示 ﾏｳｽ(L) 、 距離の方向は読取点指示 ﾏｳｽ(R)
#
# に変わります。つまり (L) は線や円を指して**その上の距離**、(R) は
# 読取点で**向き**。線を一本引いてから、その端点を読ませてみます。
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
R='read:59393;'
L='off:1333;300,300;700,500;'

run base "${L}saveas:p128_base"
# 距離 1000 (real mm), start at the line's near end, direction = its far end
run dir  "${L}raw:f,273,32930,0;wait:800;ch:1412,1000;${R}r300,300;${R}r700,500;${R}saveas:p128_dir"
# and (L) on the line itself: 線上距離
run onln "${L}raw:f,273,32930,0;wait:800;ch:1412,1000;${R}r300,300;${R}500,400;${R}saveas:p128_onln"
# 仮点 on
run kari "${L}raw:f,273,32930,0;wait:800;pb:1323;wait:400;ch:1412,1000;r300,300;r700,500;${R}saveas:p128_kari"
idle
echo
for f in p128_dir p128_onln p128_kari; do
    echo "--- $f"
    python tools/whatdid.py tmp/p128_base.jww "tmp/$f.jww" 2>&1 | head -6
done
