#!/bin/sh
# What 寸法's 円周 (1067) and 寸法値 (1069) want, asked of the original.
#
#   sh tools/probe13.sh
#
# Six gestures were tried on 円周 before and none of them drew anything,
# so this asks instead of guessing: press the button and read the status
# line (59393) after every step -- the original says there what it wants
# next -- and list the top level windows (tops) in case a dialog is up.
#
# The drawings that do come out land in tmp/probe13/ for tools/jww.py.
cd "$(dirname "$0")/.."
set +e
mkdir -p tmp/probe13
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    shift
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$1" 2>&1 | sed 's/^/    /'
}

# a circle of radius 100 at (500,400), then 寸法 with 円周 pressed, then
# the same clicks a 半径 dimension takes
run 'enshu: 円を描いてから 円周 を押し、一手ごとに状態行を読む' \
 'cmd:32773;chr:1411,100;500,400;cmd:32847;read:59393;btn:1067;read:59393;tops;600,400;read:59393;700,300;read:59393;tops;saveas:probe13_enshu'

run 'enshu_r: 同じ手を右クリックで' \
 'cmd:32773;chr:1411,100;500,400;cmd:32847;btn:1067;r600,400;read:59393;r700,300;read:59393;saveas:probe13_enshur'

run 'sunpochi: 線を引いてから 寸法値 (1069)' \
 'cmd:32771;300,300;700,300;cmd:32847;read:59393;btn:1069;read:59393;tops;r300,300;read:59393;r700,300;read:59393;saveas:probe13_sunpochi'

run 'ikkatsu: 一括処理 (1072) が出すもの' \
 'cmd:32847;btn:1072;read:59393;tops;bar'
idle
