#!/bin/sh
# 進む (57644), with the messages and the clicks kept apart.
#
#   sh tools/probe51.sh
#
# tools/probe24.sh asked this and its second run came back nonsense -- a
# vertical line nobody drew, from the start of one click pair to the
# start of another.  The 元に戻る was posted while the 線 command was
# between its two clicks, so the walk fell apart.  Every message here has
# a wait on both sides of it.
#
# Three questions, in order of what an implementation needs to know:
#
#   back2    three lines, two 元に戻る, two 進む -- probe24 got all three
#            back and this says it again with the timing fixed
#   one      three lines, two 元に戻る, one 進む -- two lines, and which
#            two says whether 進む walks the stack in order
#   after    two lines, one 元に戻る, **a new line**, then 進む -- if the
#            undone line comes back the stack survives new work, and if
#            it does not it is thrown away, which is what most programs
#            do and is exactly why it has to be asked rather than assumed
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

W='wait:700;'
U="${W}raw:f,273,57643,0;${W}"     # 元に戻る
S="${W}raw:f,273,57644,0;${W}"     # 進む
L3='cmd:32771;off:1333;300,300;500,300;300,320;500,320;300,340;500,340;'
L2='cmd:32771;off:1333;300,300;500,300;300,320;500,320;'

run back2 "${L3}${U}${U}${S}${S}saveas:p51_back2"
run one   "${L3}${U}${U}${S}saveas:p51_one"
run after "${L2}${U}300,360;500,360;${W}${S}saveas:p51_after"
idle
sh tools/refenv.sh >/dev/null
