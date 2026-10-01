#!/bin/sh
# 仮表示のラスタオペレータ —— 既に描かれているものと重なったところ。
#
#   sh tools/probe77.sh
#
# デコンパイルで正体が割れました。`FUN_0079f1b8` は **CDC::SetROP2** で、
# 仮表示に入る `FUN_004bbad0` が **10 = R2_NOTXORPEN** を、出る
# `FUN_004bbaa0` が **0xd = R2_COPYPEN** を渡します
# （decomp/byclass/_unassigned.c）。同じ二つが +0x8444 の旗を立て下げし、
# それが大きな描画関数 FUN_00481d50 で読まれています。
#
# R2_NOTXORPEN は `dest = ~(pen ^ dest)` です。仮表示色のペンは
# COLORREF 0x0000ff（= RGB ff0000）なので:
#
#   白い紙 (ffffff) の上  ~ (0000ff ^ ffffff) = 0000ff → **赤**
#   黒い線 (000000) の上  ~ (0000ff ^ 000000) = ffff00 → **水色 00ffff**
#
# 一つ目は tools/probe75.sh で確かめました。**二つ目を確かめます** ——
# 黒い線がたくさんある Test5 の上で、それを横切るように仮の矩形を出して
# 窓を絵にし、00ffff があるかどうかを見ます。あれば、移植は赤く塗るので
# はなく本物のラスタオペレータを入れられます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
idle
sh tools/refenv.sh >/dev/null
cp orig/Test5.jww tmp/rect.jww
$PS -Open tmp/rect.jww -Cmd 32772 -NoSave \
  -Clicks 'off:1333;250,250;m850,600;wait:900;shot:tmp/pend_over.png' 2>&1 |
  grep -E "throw|no |wrote|frame" | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
