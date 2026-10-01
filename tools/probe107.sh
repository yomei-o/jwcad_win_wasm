#!/bin/sh
# 元に戻る は何回効くのか —— 命令の段を空にしてから数え直す。
#
#   sh tools/probe107.sh
#
# デコンパイルによると 戻る (0xe12b) の入口 `FUN_00504100` は
# **今の命令の vtable +0x40 に先に訊き**、1 を返さなかったときだけ図面の
# 戻る (`FUN_00458a80`) を呼びます。つまり命令が途中なら、まず命令自身の
# 一歩が戻ります。`tools/probe51.sh` 〜 `probe54.sh` で回数と効き目が
# 噛み合わなかったのは、これかもしれません。
#
# そこで**線を三本引いたあと命令を出入りさせて**（円へ行って線へ戻る）
# 命令側の段を空にしてから、元に戻る を n 回投げて数えます。
#
#   n0  戻らない（くらべる元、線 3 本）
#   n1  1 回
#   n2  2 回
#   n3  3 回
#
# さらに 進む (0xe12c) も同じ形で:
#
#   u2r1  2 回戻してから 1 回進む
#   u2r2  2 回戻してから 2 回進む
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
# three lines, then out of the command and back in so its own step is empty
L='off:1333;300,300;700,500;300,550;700,650;300,200;700,250;cmd:32773;cmd:32771;wait:800;'
U='cmd:57643;wait:800;'
R='cmd:57644;wait:800;'

run n0   "${L}saveas:p107_n0"
run n1   "${L}${U}saveas:p107_n1"
run n2   "${L}${U}${U}saveas:p107_n2"
run n3   "${L}${U}${U}${U}saveas:p107_n3"
run u2r1 "${L}${U}${U}${R}saveas:p107_u2r1"
run u2r2 "${L}${U}${U}${R}${R}saveas:p107_u2r2"
idle
