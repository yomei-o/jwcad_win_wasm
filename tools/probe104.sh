#!/bin/sh
# 残りのつまみ、四つめの束 —— 文字位置･集計 (1071)・寸法の ＝ (1060) と
# 設定 (1071)・包絡の 建具線端点と包絡 (1357)。
#
#   sh tools/probe104.sh
#
# `tools/probe102.sh` の shuu は 範囲選択 のバーに 1120 が無くて落ちました
# （範囲確定は Enter で、釦ではありません）。probe95 の hani で分かった
# とおり、範囲を取ったあとは釦をそのまま押せます。
#
#   shuu   範囲選択 → 範囲 → 文字位置･集計 (1071)。問いかけと出る窓
#   eq     寸法 の ＝ (1060) を押して寸法を引く
#   set    寸法 の 設定 (1071) を押すと何が出るか
#   hou    包絡 の 建具線端点と包絡 (1357) を入れて包絡する
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved|^ *(kid|top) " | sed 's/^/    /'
}
R='read:59393;'
T='cmd:32806;type:ABC;400,300;type:DEF;400,400;type:GHI;400,500;'

run shuu "${T}cmd:32787;350,250;600,450;${R}pb:1071;wait:1500;${R}tops"
run eq   "cmd:32771;off:1333;300,300;700,300;cmd:32847;btn:1060;wait:600;${R}r300,300;r700,300;500,250;saveas:p104_eq"
run eq0  "cmd:32771;off:1333;300,300;700,300;cmd:32847;r300,300;r700,300;500,250;saveas:p104_eq0"
run set  "cmd:32847;${R}pb:1071;wait:1500;${R}tops"
run hou  "cmd:32771;off:1333;300,300;700,300;300,250;300,400;cmd:32846;btn:1357;wait:600;${R}250,250;750,450;saveas:p104_hou"
run hou0 "cmd:32771;off:1333;300,300;700,300;300,250;300,400;cmd:32846;250,250;750,450;saveas:p104_hou0"
idle
