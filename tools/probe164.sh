#!/bin/sh
# 連続線 (32883) の「ひとつ手前の線だけ画面にある」状態で、釦を押す／命令を送り直すと
# その線が図面に入るか。
#   sh tools/probe164.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "cmd:32883;400,350;600,450;500,420;$2saveas:p164_$1;" 2>&1 |
        grep -E "throw|no |saved" | sed 's/^/    /'
}
run base   ''
run jitsu  'pb:2096;dlgoff;'
run resend 'cmd:32883;'
run other  'cmd:32771;'
idle
for f in base jitsu resend other; do
    echo "--- $f"
    python tools/whatdid.py decomp/res/new.jww "tmp/p164_$f.jww" 2>&1 | cut -c1-120 | head -5
done
