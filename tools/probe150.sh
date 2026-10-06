#!/bin/sh
# 点 (32785) のバーの三つの釦が何をするのか。
#
#   sh tools/probe150.sh
#
# 1064 仮点作図・1065 全仮点消去・1066 基準点。移植はどれも配線して
# いません（一クリックで点を置くだけ）。原典に同じ場所をクリックさせて、
# 出てきた .jww の差で決めます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }

run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "$2saveas:p150_$1" 2>&1 |
        grep -E "throw|no |saved|read 59393" | sed 's/^/    /'
}

# 素の点、三つ
run base 'cmd:32785;400,400;500,400;600,400;'
# 仮点作図を押してから
run kari 'cmd:32785;btn:1064;read:59393;400,400;500,400;600,400;'
# 仮点を三つ置いてから 全仮点消去
run clear 'cmd:32785;btn:1064;400,400;500,400;600,400;btn:1065;'
# 基準点
run kijun 'cmd:32785;btn:1066;read:59393;400,400;500,400;600,400;'
idle

echo
for f in base kari clear kijun; do
    echo "--- $f"
    python tools/whatdid.py decomp/res/new.jww "tmp/p150_$f.jww" 2>&1 | head -12
done
