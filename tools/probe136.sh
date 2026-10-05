#!/bin/sh
# 割付距離以下 (1326) —— 最後に残った、訊いていないつまみ。
#
#   sh tools/probe136.sh
#
# `tools/probe115.sh` で 分割 (32867) の 割付 (1324) の歩きが取れました:
#
#   線・円（Ａ）指示 ﾏｳｽ(L)　分割始点指示 ﾏｳｽ(R)　連続点分割 (RR)
#   → □ 線【B】指示 ﾏｳｽ(L)　　● 分割終点指示 ﾏｳｽ(R)
#
# つまり**二本の線を指す**だけ。割付 を押すとバーの箱が 分割数 (1411) から
# 距離 (1412) に変わり、振分 (1325) と 割付距離以下 (1326) が現れます。
#
# 水平な線を二本、紙で 183.673 mm（実寸 18,367 mm）離して引きます。
# 距離 6000 なら 18367/6000 = 3.06 —— いちばん近いのは 3 等分（間隔
# 6,122）で、6000 以下にするなら 4 等分（間隔 4,592）。印の有無で割れる
# はずです。
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
R='read:59393;'
L='off:1333;300,300;700,300;300,600;700,600;cmd:32867;'

run base "${L}saveas:p136_base"
run off  "${L}pb:1324;wait:800;ch:1412,6000;${R}500,300;${R}500,600;${R}saveas:p136_off"
run on   "${L}pb:1324;wait:800;pb:1326;wait:500;ch:1412,6000;500,300;500,600;saveas:p136_on"
idle
echo
echo "--- 割付（印なし）が置いたもの"
python tools/whatdid.py tmp/p136_base.jww tmp/p136_off.jww 2>&1 | head -12
echo "--- 割付距離以下 を入れたとき"
python tools/whatdid.py tmp/p136_base.jww tmp/p136_on.jww 2>&1 | head -12
