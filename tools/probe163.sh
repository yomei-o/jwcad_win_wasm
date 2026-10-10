#!/bin/sh
# 連続線 (32883) の 連続弧 (2492) を、素の状態から押して三点・四点・右クリック終了で。
#   sh tools/probe163.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "cmd:32883;pb:2492;dlgoff;$2saveas:p163_$1;" 2>&1 |
        grep -E "throw|no |saved" | sed 's/^/    /'
}
run c3   '400,350;600,450;500,420;'
run c4   '400,350;600,450;500,420;300,300;'
run c3r  '400,350;600,450;500,420;r500,420;'
run c2   '400,350;600,450;'
idle
for f in c3 c4 c3r c2; do
    echo "--- $f"
    python tools/whatdid.py decomp/res/new.jww "tmp/p163_$f.jww" 2>&1 | cut -c1-200 | head -8
done
