#!/bin/sh
# 寸法設定 (32925) の箱が、引かれる寸法のどこを動かすのか。
#
#   sh tools/probe147.sh
#
# 移植はこの窓を**絵としてしか**持っていません。中身は `src/gen/sunpo.h`
# に定数として焼き付けてあり（原典の設定から読んだもの）、窓から変えら
# れません。箱の札はこうです（`src/gen/sunpodlg.h`、【設定値は図寸(mm)】）:
#
#   1488 文字種類   1423 フォント   1489 寸法線色   2083 引出線色
#   1473 矢印・点色 1475 寸法線と文字の間隔        1477 矢印の長さ
#   1479 引出線の突出寸法  1481 矢印の角度  2080 逆矢印の突出
#   2084 小数点以下桁数    1486 引出線位置  2082 円半径
#
# 一つずつ変えて同じ寸法を引かせ、差を見ます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
D='300,600;700,600;cmd:32847;ch:1411,0;400,500;400,450;r300,600;r700,600;'
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2${D}saveas:p147_$1" 2>&1 |
        grep -E "throw|no |saved|=== dialog" | sed 's/^/    /'
}

run base ""
run mojino "dlgin:32925,1488=5;wait:600;"
run sencol "dlgin:32925,1489=4;wait:600;"
run hikicol "dlgin:32925,2083=5;wait:600;"
run tencol "dlgin:32925,1473=6;wait:600;"
run hanare "dlgin:32925,1475=3;wait:600;"
run yalen  "dlgin:32925,1477=8;wait:600;"
run tsuki  "dlgin:32925,1479=4;wait:600;"
run yaang  "dlgin:32925,1481=30;wait:600;"
run keta   "dlgin:32925,2084=3;wait:600;"
idle
echo
for f in mojino sencol hikicol tencol hanare yalen tsuki yaang keta; do
    echo "--- $f"
    python tools/whatdid.py tmp/p147_base.jww "tmp/p147_$f.jww" 2>&1 | head -8
done
