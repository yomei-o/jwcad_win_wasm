#!/bin/sh
# 元に戻る on its own, before 進む can be read at all.
#
#   sh tools/probe52.sh
#
# tools/probe51.sh came back with two things that do not add up:
#
#   * three lines, two 元に戻る and **one** 進む gave all three back --
#     the same as two 進む did.  Either one 進む puts back everything, or
#     the second 元に戻る never happened.
#   * two lines, one 元に戻る, then two clicks for a new line, drew a
#     **vertical** from the second line's own start point to the first of
#     those two clicks.  That looks like 元に戻る putting the 線 command
#     back to「始点は置いた」as well as taking the line out.
#
# Neither can be sorted out without knowing what 元に戻る alone does, and
# that was never measured on its own.  So: three lines, and one, two and
# three 元に戻る with nothing after them.
#
# And the new-work question again, with the 線 command sent away and
# brought back in between, so its own state cannot be what is being read.
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
B='cmd:32847;cmd:32771;off:1333;'  # away and back, to clear the 線 walk

run u1 "${L3}${U}saveas:p52_u1"
run u2 "${L3}${U}${U}saveas:p52_u2"
run u3 "${L3}${U}${U}${U}saveas:p52_u3"
run after2 "${L3}${U}${U}${B}300,360;500,360;${W}${S}saveas:p52_after2"
idle
sh tools/refenv.sh >/dev/null
