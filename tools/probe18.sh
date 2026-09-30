#!/bin/sh
# 角度取得 and 長さ取得 -- the 設定 menu's two little families, asked of
# the original.
#
#   sh tools/probe18.sh
#
# 設定 > 角度取得 has 線角度 (32932)・線鉛直角度 (32935)・X軸角度 (32933)
# ・２点間角度 (32934)・数値角度 (32938)・軸角 (32962); 設定 > 長さ取得
# has 線長 (32939)・２点間長 (32940)・数値長 (32941)・間隔取得 (32948).
# None of them draws anything: they put a number into the command bar --
# the 傾き box or the 寸法 box -- taken off something already drawn.  This
# asks what each wants and what it leaves in the boxes.
#
# The line drawn first runs from (300,300) to (700,500) in view pixels,
# which is down the screen and so up in paper terms by -26.565 degrees.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|ComboBox|Edit\||throw|no |top " | sed 's/^/    /'
}

L='cmd:32771;300,300;700,500;'
run kakudo_sen   "${L}cmd:32932;read:59393;500,400;read:59393;bar"
run kakudo_suich "${L}cmd:32935;read:59393;500,400;read:59393;bar"
run kakudo_x     "${L}cmd:32933;read:59393;bar"
run kakudo_2ten  "${L}cmd:32934;read:59393;r300,300;read:59393;r700,500;read:59393;bar"
run nagasa_sen   "${L}cmd:32939;read:59393;500,400;read:59393;bar"
run nagasa_2ten  "${L}cmd:32940;read:59393;r300,300;read:59393;r700,500;read:59393;bar"
run kankaku      "${L}cmd:32948;read:59393;tops;bar"
run suchi_kaku   "${L}cmd:32938;read:59393;tops"
run suchi_naga   "${L}cmd:32941;read:59393;tops"
idle
