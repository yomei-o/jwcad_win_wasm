#!/bin/sh
# ダイアログの外枠と × —— 移植の二つの欠陥を原典に訊きます。
#
#   sh tools/probe116.sh
#
# 一つめ。`docs/ref_*.png` は PrintWindow の絵で、外の八画素が **000000**
# です。移植はそれをそのまま塗ったので、枠が真っ黒に見えます。ほんとうに
# 黒いのか、それとも見えない枠（Windows 10 以降の、掴んで大きさを変える
# ためだけの透明な縁）なのかは、GetWindowRect と
# DwmGetWindowAttribute(DWMWA_EXTENDED_FRAME_BOUNDS) を較べれば分かります。
#
# 二つめ。移植は × を描いているのに、どの `ui_*_hit` もそこを拾いません。
# × がどこにあるかは **WM_NCHITTEST** が答えます（HTCLOSE = 20）。画面を
# 読まずに済みます。
#
# 四つの窓に訊きます: 縮尺・読取 (32944)・基本設定 (32891)・
# レイヤ設定 (32808)・寸法設定 (32925)。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "nc |visible|client |HT |throw|no " | sed 's/^/    /'
}

run shakudo "dlgnc:32944"
run kihon   "dlgnc:32891"
run layer   "dlgnc:32808"
run sunpo   "dlgnc:32925"
idle
