#!/bin/sh
# ハッチの 図形 (1693) は何を敷くのか —— きれいな紙で撮り直し。
#
#   sh tools/probe84.sh
#
# tools/probe73.sh・probe74.sh で、ここまでは分かっています:
#
#   * 押してもファイル窓は出ない。ほかの四つと同じ「モード」で、押すと
#     バーが 角度(1419)・縦ﾋﾟｯﾁ(1411)・横ﾋﾟｯﾁ(1412) の三つ立てになる
#   * 図形読込 で図形を読んでおくと、読まないときより線が増える
#
# 前の走りは Test5 の上でやったので、原典の図形と Test5 自身の線が
# 混ざって読めませんでした。**まっさらな紙**に矩形を一つだけ描いて
# やり直します。読む図形は decomp/res/fig.jws（六本の線で 6mm の箱に
# 十字、1/100）。
#
#   none    図形を読まずに 図形 モードで敷く
#   fig     fig.jws を読んでから同じこと
#   pitch   同じで ピッチだけ倍
#   ang     同じで 角度 30
#
# 読んだものと敷かれたものを数えて較べれば、敷いているのが図形かどうか、
# ピッチが何の間隔なのかが分かります。
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

RECT='300,300;800,600;'
H='cmd:32874;pb:1693;wait:1000;'
P='set:1419,0;set:1411,50;set:1412,50;'
GO='r550,300;btn:1148;'

run none  "${RECT}${H}${P}${GO}saveas:p84_none"
run fig   "figin:32862,decomp/res/fig.jws;${RECT}${H}${P}${GO}saveas:p84_fig"
run pitch "figin:32862,decomp/res/fig.jws;${RECT}${H}set:1419,0;set:1411,100;set:1412,100;${GO}saveas:p84_pitch"
run ang   "figin:32862,decomp/res/fig.jws;${RECT}${H}set:1419,30;set:1411,50;set:1412,50;${GO}saveas:p84_ang"
idle
sh tools/refenv.sh >/dev/null
