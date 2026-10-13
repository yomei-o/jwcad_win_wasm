#!/bin/sh
# 天空図 (32971) の探り: バーの状態と答え。
#   sh tools/tnprobe.sh <名前> '<手順>'   → tmp/tn_<名前>.jww
# 下地は new.jww に 箱（線 4 本、画面 400,250〜550,400）と その四隅の高さ 10 m。
# 手順のあいだに bar（バーの子を書き出す）・R（案内を読む）を挟める。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
BOX='cmd:32771;off:1333;400,250;550,250;r550,250;550,400;r550,400;400,400;r400,400;400,250;'
H='cmd:32971;wait:1200;400,250;550,250;550,400;400,400;wait:400;'
st=$(echo "$2" | sed 's/\bR;/wait:250;read:59393;/g')
idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/tn_$1.jww
echo "=== $1"
$PS -Open tmp/tn_$1.jww -NoSave -Clicks "${BOX}${H}${st}saveas:tn_$1;" 2>&1 | tr -d '\r' | grep -E "${TNGREP:-throw|no |saved|read 59393|^Button|^Edit|^Static|^ComboBox|^=== }" | sed 's/read 59393: //'
idle
