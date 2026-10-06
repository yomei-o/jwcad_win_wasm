#!/bin/sh
# 作図コマンドを原典に一つずつ引かせて、答えの .jww を集める。
#
#   sh tools/drawsweep.sh            作図メニューの全部
#   sh tools/drawsweep.sh 32771      一つだけ
#
# 同じ三クリックを移植にもさせて突き合わせるためのものです
# （tests/drawsweep_test.c がその突き合わせ）。拾いもの（ハッチや接線の
# ように要素を指すもの）は下敷きを引いてから訊きます。
#
# 答えは decomp/res/sweep_<id>.jww に入ります。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }

# 下敷き: 交わる二本と円一つ。拾うコマンドのために置いておきます。
BASE='cmd:32771;off:1333;300,300;700,500;300,500;700,300;cmd:32773;500,250;560,250;'

# 三クリック。真ん中あたりで、下敷きの線の上を通ります。
CLICKS='400,350;600,450;500,420;'

one() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    printf '%s ' "$1"
    $PS -Open tmp/rect.jww -NoSave \
        -Clicks "${BASE}saveas:sweep_base;cmd:$1;${CLICKS}saveas:sweep_$1;" 2>&1 |
        grep -E "throw|no dialog|saved tmp.sweep_$1" | tr '\n' ' '
    echo
}

if [ $# -gt 0 ]; then
    for c in "$@"; do one "$c"; done
else
    for c in 32771 32772 32773 32785 32806 32847 32870 32872 32873 \
             32874 32883 32892 32894 32908; do
        one "$c"
    done
fi
idle
cp tmp/sweep_base.jww decomp/res/sweep_base.jww 2>/dev/null
for f in tmp/sweep_3*.jww; do
    [ -f "$f" ] && cp "$f" "decomp/res/$(basename "$f")"
done
echo
echo "--- 原典が引いたもの"
for f in decomp/res/sweep_3*.jww; do
    printf '%-28s ' "$f"
    python tools/whatdid.py decomp/res/sweep_base.jww "$f" 2>&1 | head -1
done
