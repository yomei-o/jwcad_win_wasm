#!/bin/sh
# 作図中の仮の図形は何色で出るのか。
#
#   sh tools/probe75.sh
#
# 使う人から「四角形や線を描いている途中の、まだ確定していない図形は
# **赤** で出るはずなのにそうなっていない」。移植は `src/app.c` で
# `jw_cmd_pending` が返したものを `jw_draw` にそのまま渡していて、
# 要素自身のペンの色で描いてしまいます（そこのコメントも「原典は
# SetROP2 を通すが、まだ追えていない」と白状しています）。
#
# 原典の基本設定には **仮表示色 (1122)** という設定があり
# （decomp/res/dialog.txt）、その三つの箱は HKCU の Pen\Color11 のはず
# です。手元の値は "ff" —— COLORREF (0x00bbggrr) なので **ff0000、赤**。
# 範囲枠の色として移植がもう使っている JW_RANGE_RGB と同じ値です。
#
# それを原典自身に確かめます。矩形の一隅を置いてからマウスを動かすと
# 仮の四角が出るので、そこで窓を PrintWindow で絵にします（画面は
# 読みません）。範囲枠を撮ったときと同じ手です。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |wrote|shot" | sed 's/^/    /'
}

# 矩形: one corner down, then the cursor somewhere else, then a picture
run kukei "cmd:32772;off:1333;300,300;m700,500;wait:600;shot:tmp/pend_kukei.png"
# 線: the same
run sen   "cmd:32771;off:1333;300,300;m700,500;wait:600;shot:tmp/pend_sen.png"
# 円: and the same again
run enko  "cmd:32773;300,300;m700,500;wait:600;shot:tmp/pend_enko.png"
idle
sh tools/refenv.sh >/dev/null
