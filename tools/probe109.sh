#!/bin/sh
# 進む は戻したものを**前に**入れるのか、並びを**ひっくり返す**のか。
#
#   sh tools/probe109.sh
#
# `tools/probe107.sh` の答えを読むと、進む のあとは要素の並びが変わって
# います（線を 1・2・3 の順に引いて）:
#
#   戻る×2 → 進む×1   →  [2, 1]
#   戻る×2 → 進む×2   →  [3, 2, 1]
#
# 「戻したものを先頭に入れる」でも「全体をひっくり返す」でも、この二つは
# 同じ並びになります。分けるには**戻すのが一つで、前に二つ残っている**
# 形が要ります:
#
#   戻る×1 → 進む×1
#     先頭に入れる  →  [3, 1, 2]
#     ひっくり返す  →  [3, 2, 1]
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "throw|no |saved" | sed 's/^/    /'
}
L='off:1333;300,300;700,500;300,550;700,650;300,200;700,250;cmd:32773;cmd:32771;wait:800;'
U='cmd:57643;wait:800;'
R='cmd:57644;wait:800;'

run u1r1 "${L}${U}${R}saveas:decomp/res/redo_u1r1.jww"
run u3r1 "${L}${U}${U}${U}${R}saveas:decomp/res/redo_u3r1.jww"
idle
