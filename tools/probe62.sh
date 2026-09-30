#!/bin/sh
# 文字の 基点 (1064): 九つのどれを選ぶと文字がどこに落ちるか。
#
#   sh tools/probe62.sh
#
# 押すと出るのは一枚のダイアログで、中身は tools/probe60.sh で読めました。
# 3×3 の 文字基点 が 1689 左上 / 1690 左中 / 1691 左下（初期値）/
# 1692 中上 / 1693 中中 / 1694 中下 / 1695 右上 / 1696 右中 / 1697 右下。
#
# 絵の話より先に**図面に出るほう**を測ります。九つそれぞれで ABC を
# 同じ場所 (400,400) に置かせて、文字の始点がどう動くかを見ます。
# 初期値の 左下 は tools/probe57.sh の mo_plain が押さえてあって、
# 始点はクリックそのもの (-94.2857, -34.898)、走りは 16 mm でした。
#
# ついでにダイアログの控えと、原典が塗った絵も取ります。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

for id in 1689 1690 1691 1692 1693 1694 1695 1696 1697; do
    run "kij$id" "cmd:32806;dlgin:b1064,$id=!;type:ABC;400,400;saveas:p62_$id"
done

# and the dialog itself, the way tools/gen.sh takes the others
idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
echo "=== dialog"
$PS -Open tmp/rect.jww -Cmd 0 -NoSave -Out decomp/res/mojikijun.txt \
    -Clicks 'cmd:32806;dlg:b1064,docs/ref_mojikijun.png' 2>&1 |
    grep -E "throw|no |wrote|dialog" | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
