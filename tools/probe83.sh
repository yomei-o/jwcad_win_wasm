#!/bin/sh
# 仮表示の文字は箱か字か、そして図形は置いたあとも付いてくるか。
#
#   sh tools/probe83.sh
#
# probe82 で、図形の仮置きは**文字を箱で出す**ことが分かりました
# （字の代わりに文字の外枠が ff0000 で出る）。では
#
#   moji  文字命令 (32806) で打ち込んで置く前の字も箱なのか
#   again 図形を一つ置いたあと、カーソルを動かすとまた付いてくるのか
#         （probe81 では置いたあと赤が出ませんでした）
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "frame|throw|no |saved" | sed 's/^/    /'
}

run moji "cmd:32806;type:AW;m700,500;wait:1200;shot:tmp/p83_moji.png"

MIX='cmd:32771;off:1333;300,250;420,250;300,250;300,340;'
SEL='cmd:32787;280,230;r440,380;cmd:57634;'
run again "${MIX}${SEL}cmd:57637;m700,500;wait:900;700,500;wait:900;m900,620;wait:1500;shot:tmp/p83_again.png"
idle
sh tools/refenv.sh >/dev/null
