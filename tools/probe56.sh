#!/bin/sh
# 切り取り・コピー・貼り付け (57635 / 57634 / 57637): the walk.
#
#   sh tools/probe56.sh
#
# Nothing is known about these three beyond their menu ids.  Before any
# of it can be written the original has to say:
#
#   * what wakes them up -- a range has to be picked first, presumably,
#     and the menu entries are probably dead until it is
#   * what 貼り付け does when it is chosen: which command comes up, what
#     the status line asks for, what the bar looks like
#   * where the pasted copy lands relative to the click, which is the one
#     number an implementation cannot guess
#
# So: draw three lines, pick them with 範囲選択, read the menu state,
# copy, read it again, paste, read the status line and the bar, click
# once, and save.  The same again for 切り取り, which should also take
# the original away.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|=== |Button|ComboBox|Static|throw|no |saved" |
        sed 's/^/    /'
}

R='read:59393;'
# three lines, then 範囲選択 with a box round them and (R) to settle it
L='cmd:32771;off:1333;300,300;500,300;300,320;500,320;300,340;500,340;'
SEL='cmd:32787;280,280;r520,360;'

run pick  "${L}${SEL}${R}bar:32787"
run copy  "${L}${SEL}cmd:57634;${R}bar"
run paste "${L}${SEL}cmd:57634;cmd:57637;${R}bar;400,500;saveas:p56_paste"
run cut   "${L}${SEL}cmd:57635;${R}saveas:p56_cut"
idle
sh tools/refenv.sh >/dev/null
