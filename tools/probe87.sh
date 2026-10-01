#!/bin/sh
# ハッチの 図形 —— 格子のどこに図形のどこが載るのか。
#
#   sh tools/probe87.sh
#
# tools/probe86.sh で分かったこと: 格子は**動かない**。境界を動かしても
# 図形自身を動かしても、置かれる場所は一画素も変わりませんでした
# （ピッチ 80/60 でも 40/40 でも同じ剰余）。つまり格子は原点に留まって
# いて、そこに図形の「どこか」が載ります。
#
# 測った L 字は 横 36.7347・縦 18.3673 で、置かれた L の角は
#
#     x ≡ -9.1837 (mod ピッチ)   -9.1837 = -横/4
#     y ≡ +4.5918 (mod ピッチ)   +4.5918 = +縦/4
#
# でした。ただしこの L は**横がちょうど縦の二倍**なので、横/4 と 縦/2 が
# 同じ値になってしまい、どちらなのか決まりません。そこで**縦横の比が
# 単純でない** L を三つ使って測り直します。
#
#   a   横 100 画素・縦 30 画素   (61.224 x 18.367)
#   b   横  40 画素・縦 70 画素   (24.490 x 42.857)
#   c   b と同じ形を**描く順を逆**にして（角がどちらの線の端かを変える）
#
# a と b で角のずれが 横/4・縦/4 のまま動けば、基準は図形の囲みの
# 四半分の点です。c が a・b と同じなら、描いた順は関係ありません。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32772 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

# $1 is the two lines that make the pattern
go() {
    echo "300,300;800,600;cmd:32771;off:1333;$1cmd:32874;pb:1693;wait:800;pb:1067;wait:800;840,140;1000,330;pb:1068;wait:1000;set:1419,0;set:1411,60;set:1412,80;r550,300;btn:1148;"
}

run a "$(go '880,180;980,180;880,180;880,210;')saveas:p87_a"
run b "$(go '880,180;920,180;880,180;880,250;')saveas:p87_b"
run c "$(go '920,180;880,180;880,250;880,180;')saveas:p87_c"
idle
sh tools/refenv.sh >/dev/null
