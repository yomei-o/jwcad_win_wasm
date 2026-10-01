#!/bin/sh
# 文字位置･集計 (1071) と、文字の 範囲選択 (2407) の行き先。
#
#   sh tools/probe112.sh
#
# `tools/probe104.sh` では 範囲選択 の 文字位置･集計 を押しても何も
# 起きませんでした。ただし押したのは**範囲を確定する前**です。
# 問いかけは「追加・除外図形指示 … Enter-範囲確定」なので、確定は
# Enter。キーはフレームの PreTranslateMessage を通るので
# `raw:f,256,13,0`（WM_KEYDOWN の VK_RETURN）で送れます。
#
#   hani1  範囲選択 (32787) → 範囲 → Enter → 問いかけと窓
#   shuu   そのあと 文字位置･集計 (1071) → 問いかけと窓
#   moji   文字 (32806) の 範囲選択 (2407) → 範囲 → Enter → 問いかけ
#
# 文字は数の入ったものを三つ置きます（集計なら足せるように）。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved|^ *kid .* id=(1|2|3)[0-9]* " |
        sed 's/^/    /'
}
R='read:59393;'
E='raw:f,256,13,0;wait:800;'
T='cmd:32806;type:12;400,300;type:34;400,400;type:56;400,500;'

run hani1 "${T}cmd:32787;350,250;600,550;${R}${E}${R}tops"
run shuu  "${T}cmd:32787;350,250;600,550;${E}pb:1071;wait:1500;${R}tops"
run moji  "${T}pb:2407;wait:800;350,250;600,550;${R}${E}${R}tops"
idle
