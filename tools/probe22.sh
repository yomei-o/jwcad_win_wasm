#!/bin/sh
# 角度取得・長さ取得, fourth pass -- the rest of the family, and whether
# 長さ follows the same three rules 角度 does.
#
#   sh tools/probe22.sh
#
# What is settled so far (tools/probe20.sh, probe21.sh), with a reference
# line at -26.565 degrees and 273.804 long:
#
#   線角度 (32932)  the lines after it come out at -26.565 and their length
#                   is the click projected on to that way; it holds for the
#                   line after that too; leaving the command clears it; a
#                   number typed into the 傾き box beats it
#   線長   (32939)  the next line keeps the way it was clicked and comes out
#                   273.804 long
#
# Here: 線鉛直角度 (32935), ２点間角度 (32934), ２点間長 (32940), and the
# same three questions for 線長.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no " | sed 's/^/    /'
}

L='cmd:32771;off:1333;300,300;700,500;'
S='300,600;600,650;'
run suich     "${L}cmd:32935;500,400;${S}saveas:p22_suich"
run k2ten     "${L}cmd:32934;r300,300;r700,500;${S}saveas:p22_k2ten"
run n2ten     "${L}cmd:32940;r300,300;r700,500;${S}saveas:p22_n2ten"
run nagatwice "${L}cmd:32939;500,400;${S}300,660;600,680;saveas:p22_nagatwice"
run nagaleave "${L}cmd:32939;500,400;cmd:32773;cmd:32771;${S}saveas:p22_nagaleave"
run nagabox   "${L}cmd:32939;500,400;chr:1412,50;${S}saveas:p22_nagabox"
idle
