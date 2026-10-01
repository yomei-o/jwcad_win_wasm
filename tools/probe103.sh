#!/bin/sh
# 複写 (2092) —— 外すと 図形複写 が「移動」になる。答えを二つ。
#
#   sh tools/probe103.sh
#
# `tools/probe102.sh` で分かりました。図形複写 (32804) の二段目のバーには
# 複写 (2092) という印があって、**初めから入っています**。外すと問いかけが
# 「移動先の点を指示して下さい」に変わり、図面は増えずに動きます。
# 図形移動 (32918) のバーでは同じ印が初めから外れています —— つまり
# 複写か移動かを決めているのは**命令ではなくこの印**です。
#
# 同じクリックで二通り取ります。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32772 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}
C='300,300;500,400;cmd:32804;250,250;550,450;m400,350;btn:1120;'
M='300,300;500,400;cmd:32918;250,250;550,450;m400,350;btn:1120;'

run copy "${C}700,500;saveas:decomp/res/copy2092on.jww"
run move "${C}pb:2092;wait:600;700,500;saveas:decomp/res/copy2092off.jww"
run mv0  "${M}700,500;saveas:decomp/res/move2092off.jww"
run mv1  "${M}pb:2092;wait:600;700,500;saveas:decomp/res/move2092on.jww"
idle
