#!/bin/sh
# 仮置きの図形は、何を出して何を出さないのか。
#
#   sh tools/probe82.sh
#
# probe80・probe81 で、読み込んだ図形がカーソルのところに ff0000 で出て、
# その赤はクリックして置かれる絵の**部分集合**だと分かりました
# （赤 141 画素はすべて黒くなり、黒 250 画素のうち 109 はもともと赤では
# なかった）。足りない分が何なのかを知るために、**種類の分かっている
# 小さな図形**で同じことをします。
#
# 図形は貼り付け (57637) で作ります。これは図形読込と同じ命令なので
# （probe56）、ファイル窓を通さずに済みます。中身は
#
#   横線・縦線・円・文字・点
#
# の五つ。カーソルを止めて撮り（仮表示）、そのままクリックして撮り
# （本置き）、どれが赤くなっていてどれがなっていないかを数えます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }

# 横線 300,250-420,250 / 縦線 300,250-300,340 / 円 中心 380,320 / 文字 / 点
MIX='cmd:32771;off:1333;300,250;420,250;300,250;300,340;'
MIX="${MIX}cmd:32773;380,320;410,320;"
MIX="${MIX}cmd:32785;340,360;"
MIX="${MIX}cmd:32806;type:AW;350,300;"
SEL='cmd:32787;280,230;r440,380;cmd:57634;'

idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
$PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks \
  "${MIX}${SEL}cmd:57637;m700,500;wait:1200;shot:tmp/mix_pre.png;700,500;wait:900;shot:tmp/mix_put.png;saveas:p82" 2>&1 |
  grep -E "frame|throw|no |saved|read 59393" | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
