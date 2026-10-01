#!/bin/sh
# 文字の 範囲選択 (2407) —— 範囲を取ったあと何ができるのか。
#
#   sh tools/probe96.sh
#
# `tools/probe95.sh` で、押すと**ふつうの範囲選択の歩き**になることが
# 分かりました:
#
#   【文字】　範囲選択の始点をﾏｳｽで指示してください。
#   ［文字］　　　　選択範囲の終点を指示して下さい。
#   追加・除外図形指示 … Enter-範囲確定
#
# 図形登録のときと違い「ShiftEnter-基点変更」はありません。では確定の
# あとどうなるのか。バーごと見ます。
#
#   after  範囲を取って 選択確定、そのあとの問いかけとバー
#   type   そのあと打ち込んでクリックしたら何が起きるか
#   attr   そのあと 属性変更 のような釦があるか（バーの中身で分かります）
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved|^ *Button|^ *bar" | sed 's/^/    /'
}
R='read:59393;'
T='cmd:32806;type:ABC;400,300;type:DEF;400,400;type:GHI;400,500;'
S='pb:2407;wait:800;350,250;600,450;'

run after "${T}${S}${R}btn:1120;wait:600;${R}bar"
run type  "${T}${S}btn:1120;wait:600;type:XY;700,300;${R}saveas:p96_type"
run esc   "${T}${S}btn:1120;wait:600;700,300;${R}saveas:p96_click"
idle
