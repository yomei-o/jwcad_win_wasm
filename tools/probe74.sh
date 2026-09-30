#!/bin/sh
# ハッチの 図形 (1693) は何を敷くのか。
#
#   sh tools/probe74.sh
#
# tools/probe73.sh で分かったこと: **押してもファイル窓は出ません**。
# ほかの四つと同じ「モード」で、押すとバーが 角度(1419)・縦ﾋﾟｯﾁ(1411)・
# 横ﾋﾟｯﾁ(1412) の三つ立てになります（┬┴┬ と同じ顔）。出てくるのは
# 224x16 の小さな窓ひとつだけで、ファイル選択ではありません。
#
# では何を敷くのか。手順は tools/refanswers.sh の hatch_rect_base と
# 同じで、図形 を押してから 基点変 → 境界 (R) → 実行。図形を先に
# 読み込んでおいた場合（図形読込 で fig.jws）も見ます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp orig/Test5.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32772 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}
R='read:59393;'

run plain "300,300;800,600;cmd:32874;pb:1693;wait:1200;${R}pb:1147;300,300;r550,300;${R}btn:1148;${R}saveas:p74_plain"
run withfig "figin:32862,decomp/res/fig.jws;300,300;800,600;cmd:32874;pb:1693;wait:1200;pb:1147;300,300;r550,300;btn:1148;saveas:p74_withfig"
idle
sh tools/refenv.sh >/dev/null
