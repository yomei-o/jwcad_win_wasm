#!/bin/sh
# 分割の 振分 (1325) —— 割付 の余りをどうするか。
#
#   sh tools/probe137.sh
#
# `tools/probe136.sh` で割れました:
#
#   割付 だけ        線Ａから**ちょうど 距離**ずつ置いていき、Ｂ側に余りが
#                    出ます（間 183.673 mm に 距離 60 mm → 60,60,60,3.674）
#   割付距離以下 付き 余りが出ないように**等分**します。距離を超えない
#                    いちばん少ない等分（183.673/4 = 45.918 ≤ 60）
#
# 残る 振分 (1325) は、名前からすると余りを両端に振り分けるのでしょう。
# 同じ形で訊きます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}
L='off:1333;300,300;700,300;300,600;700,600;cmd:32867;'

run furi  "${L}pb:1324;wait:800;pb:1325;wait:500;ch:1412,6000;500,300;500,600;saveas:decomp/res/wari_furi.jww"
run both  "${L}pb:1324;wait:800;pb:1325;wait:400;pb:1326;wait:400;ch:1412,6000;500,300;500,600;saveas:decomp/res/wari_both.jww"
idle
echo
echo "--- 振分 だけ"
python tools/whatdid.py decomp/res/wari_base.jww decomp/res/wari_furi.jww 2>&1 | head -8
echo "--- 振分 ＋ 割付距離以下"
python tools/whatdid.py decomp/res/wari_base.jww decomp/res/wari_both.jww 2>&1 | head -8
