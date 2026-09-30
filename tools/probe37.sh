#!/bin/sh
# What turns 寸法's 一括処理 (1072) and 実行 (1120) on.
#
#   sh tools/probe37.sh
#
# Both come up **disabled** (src/gen/bars.h has their enabled flag at 0),
# and pressing them does nothing.  Something else must wake them.  This
# presses the other buttons of the 寸法 bar one at a time and dumps the
# bar after each, so the run can be read for the moment those two turn on.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "^=== |Button\|(1072|1120)\||read 59393|throw|no " |
        sed 's/^/    /'
}

# a line to measure, then 寸法, then each button in turn
L='cmd:32771;off:1333;300,300;700,500;cmd:32847;'
run press "${L}bar:1;btn:1070;bar:2;btn:1060;bar:3;btn:1059;bar:4;btn:1065;bar:5;btn:1064;bar:6;btn:1067;bar:7;btn:1068;bar:8;btn:1069;bar:9;btn:1066;bar:10;btn:1061;bar:11;btn:1062;bar:12"
# and with a dimension already drawn
run drawn "${L}r300,300;r700,500;300,400;bar:20"
# and with a range picked first
run range "cmd:32771;off:1333;300,300;700,500;cmd:32787;200,200;r800,600;cmd:32847;bar:30"
idle
