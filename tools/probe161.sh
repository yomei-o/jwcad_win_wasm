#!/bin/sh
# ２線 (32892) の 留線 (1323)・留線常駐 (1324)。
#
#   sh tools/probe161.sh
#
# つまみの掃き出しで、留線 は手前の端に蓋を一本、留線常駐 は両端に、と
# 出ました。そのとき二本の線は蓋のぶん伸びています。伸びた長さは
# 既定（片側 0.5 図寸mm）と同じ 0.5 でしたが、**間隔と同じなのか、
# 間隔の半分なのか**が分かれません。左右で違う間隔にして訊きます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 60 ] && { taskkill //F //IM Jw_win.exe >/dev/null 2>&1; break; }; sleep 1; done; }
BASE='cmd:32771;off:1333;300,300;700,500;300,500;700,300;cmd:32785;'
C='400,350;600,450;500,420;'

idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
$PS -Open tmp/rect.jww -NoSave -Clicks \
  "${BASE}cmd:32892;ch:1412,100,300;${C}saveas:p161_plain;cmd:32892;btn:1323;${C}saveas:p161_tome;cmd:32892;btn:1324;${C}saveas:p161_jochu;" 2>&1 |
  grep -aE "saved|no control" | sed 's/^/    /'
idle
echo
p=decomp/res/sweep_base.jww
for f in plain tome jochu; do
    echo "--- $f"
    python tools/whatdid.py "$p" "tmp/p161_$f.jww" 2>&1 | head -6
    p="tmp/p161_$f.jww"
done
