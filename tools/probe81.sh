#!/bin/sh
# 仮置きの図形は、クリックしたときに置かれるところと同じか。
#
#   sh tools/probe81.sh
#
# probe80 で、読み込んだ図形がカーソルのところに ff0000 で出ることが
# 分かりました。あとは**その赤い絵が、クリックしたら置かれる黒い絵と
# 同じ場所か**です。同じ所でカーソルを止めて撮り、そのままクリックして
# もう一度撮って、赤かった画素と黒くなった画素を見比べます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
$PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks \
  "figin:32862,tmp/bigfig.jws;m600,400;wait:1000;shot:tmp/fig_pre.png;600,400;wait:600;m900,650;wait:600;shot:tmp/fig_put.png" 2>&1 |
  grep -E "frame|throw|no " | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
