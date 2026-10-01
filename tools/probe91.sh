#!/bin/sh
# 間隔取得 (32948) は 複線 の間隔を入れるのか。
#
#   sh tools/probe91.sh
#
# `tools/probe89.sh`・`probe90.sh` で:
#
#   * 複線 の問いかけには**もともと数が付いています** ——
#     「間隔を入力するか、複写する位置 … 13,690.212」。これは
#     まっさらな紙でも出るので、レジストリに残っている前回値です
#   * 間隔取得 を通すと 【間隔取得】の側に 16,428.254 が出ます
#     （線 (300,300)-(700,500) と点 (300,600) の垂線、164.28 mm × 100。
#     probe27 と同じ値）
#   * 間隔取得 は**終わりません**。続くクリックもそこへ吸い込まれるので、
#     複線 の途中で呼ぶとその複線は流れます
#   * 点 の命令の中では 32948 は**効きません**（問いかけが変わらない）
#
# 残るのは「取った値は 複線 の前回値になるのか」。なるなら、取ったあとに
# 複線 を入れ直して **(R) 前回値**で選べば 164.28 mm 離れた複写が出ます。
#
#   kan   間隔取得 してから 複線 の前回値
#   plain そのまま 複線 の前回値（くらべる元）
#   box   複線 の箱に 164.28 を打ち込んだ場合（答え合わせの形）
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

B='cmd:32771;off:1333;300,300;700,500;'
K='cmd:32948;500,400;300,600;'
R='read:59393;'
F='cmd:32800;r500,400;'

run kan   "${B}${K}${R}${F}${R}500,200;${R}saveas:p91_kan"
run plain "${B}${F}${R}500,200;${R}saveas:p91_plain"
run box   "${B}cmd:32800;chr:1411,164.28;500,400;${R}500,200;saveas:p91_box"
idle
