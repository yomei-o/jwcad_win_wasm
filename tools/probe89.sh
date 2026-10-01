#!/bin/sh
# 間隔取得 (32948) の行き先、もう一度 —— 前の六回は点が取れていませんでした。
#
#   sh tools/probe89.sh
#
# `tools/probe44.sh`・`probe46.sh`〜`probe48.sh` は六か所あたって全部
# 外れました。見直すと、**どれも二つ目のクリックが (R) です**:
#
#     cmd:32948;500,400;r300,600;
#
# (R) は Read なので、読む点が無ければ何も起きません。まっさらな紙に線を
# 一本引いただけの図面で (300,600) には何もありませんから、**値そのものが
# 取れていなかった**はずです。実際に状態行に数が出たのは `probe27.sh` で、
# そこは二つ目も**左クリック**でした:
#
#     cmd:32948;500,400;300,600;     →  16,428.254
#
# それと、メニューでの居場所も見落としていました。32948 は 設定 の
# **長さ取得** の下にあります（線長・２点間長・数値長 と同じ並び）。
# なので行き先は 寸法 の箱と同じところのはずです。
#
# もう一つ、デコンパイルが言っていること: 取得の類は `+0x9088` にモード
# （間隔取得は 15）を置いて、**今の命令の vtable +0xbc** に渡します
# （`FUN_0050d8e0`）。つまり受け取るのは命令のほうなので、**命令を出ると
# 消えます**（線長で測ったとおり）。前の走りは 間隔取得 のあとに
# `cmd:32800` で複線へ移っていたので、そこでも落ちていたはずです。
#
#   plain  くらべる元
#   len    間隔取得 のあとそのまま線を引く（寸法と同じ働きなら 164.28 mm）
#   stay   間隔取得 のあと命令を出入りしてから引く（消えるはず）
#   fuku   複線に入って**から**間隔取得して、それから写す
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

L='cmd:32771;off:1333;300,300;700,500;'
K='cmd:32948;500,400;300,600;'
S='300,600;600,650;'
R='read:59393;'

run plain "${L}${S}saveas:p89_plain"
run len   "${L}${K}${R}${S}saveas:p89_len"
run stay  "${L}${K}cmd:32773;cmd:32771;${S}saveas:p89_stay"
run fuku  "${L}cmd:32800;500,400;${R}${K}${R}500,200;saveas:p89_fuku"
run fuku0 "${L}cmd:32800;500,400;500,200;saveas:p89_fuku0"
idle
