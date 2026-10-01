#!/bin/sh
# 進む (0xe12c) の端のほう —— 新しく引いたら進めなくなるのか。
#
#   sh tools/probe108.sh
#
# `tools/probe107.sh` で測り方が直りました。**命令を出入りさせて命令側の
# 段を空にしてから**投げれば、戻る も 進む も一回に一段ずつきれいに効きます
# （線 3 本 → 戻る×2 → 1 本 → 進む×2 → 3 本）。前の走り（probe51〜54）が
# ばらついたのは、デコンパイルのとおり **戻る がまず今の命令自身の一歩を
# 戻す**（vtable +0x40）からでした。
#
# 残りは端のほうです:
#
#   fresh  3 本 → 戻る×2 → **新しく一本引く** → 進む。進めるのか
#   none   3 本 → 戻らずに 進む。何か起きるのか
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
L='off:1333;300,300;700,500;300,550;700,650;300,200;700,250;cmd:32773;cmd:32771;wait:800;'
U='cmd:57643;wait:800;'
R='cmd:57644;wait:800;'
N='300,700;700,720;cmd:32773;cmd:32771;wait:800;'

run fresh "${L}${U}${U}${N}${R}saveas:p108_fresh"
run none  "${L}${R}saveas:p108_none"
idle
