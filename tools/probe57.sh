#!/bin/sh
# 円弧 (32773) と 文字 (32806) を原典に描かせる。
#
#   sh tools/probe57.sh
#
# 移植にはどちらも入っていますが、**原典が描いたものと突き合わせたことが
# 一度もありません**。ダイアログ（書込み文字種・画面倍率）や、円を使う
# ほかの命令（接線・接円・曲線・ハッチ）は突き合わせてありますが、
# 円弧そのものと文字そのものは素通りでした。
#
# バーのつまみは全部で次の通り（tools/mkbars.py の控えから）:
#
#   円弧  半径(1411) 扁平率(1412) 傾き(1413) 円弧(1318) 終点半径(1319,
#         初めから無効) 半円(1320) ３点指示(1321) 基点(1064) 多重円(1417)
#   文字  文字種(1843) 水平(1323) 垂直(1324) 角度(1411) 範囲選択(2407)
#         基点(1064) 行間(1418) 縦字(1325) 連(1068) 貼付(1065, 無効)
#         文読(1069) 文書(1070, 無効) 外部ｴﾃﾞｨﾀ(1067)
#
# ここでは図面に出るものだけを訊きます。画面は 49 画素 = 30 mm、
# 紙の原点がビューの (554.333, 343) です。
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

E='cmd:32773;'
M='cmd:32806;'

# --- 円弧 ---------------------------------------------------------------
run en_plain "${E}300,300;500,400;saveas:p57_en_plain"
run en_arc   "${E}btn:1318;300,300;500,400;500,200;saveas:p57_en_arc"
run en_half  "${E}btn:1320;300,300;500,400;saveas:p57_en_half"
run en_3p    "${E}btn:1321;300,300;500,400;400,200;saveas:p57_en_3p"
run en_flat  "${E}chr:1412,0.5;300,300;500,400;saveas:p57_en_flat"
run en_tilt  "${E}chr:1412,0.5;chr:1413,30;300,300;500,400;saveas:p57_en_tilt"
run en_r50   "${E}chr:1411,50;300,300;saveas:p57_en_r50"
run en_multi "${E}chr:1417,3;300,300;500,400;saveas:p57_en_multi"
run en_afl   "${E}btn:1318;chr:1412,0.5;300,300;500,400;500,200;saveas:p57_en_afl"

# --- 文字 ---------------------------------------------------------------
run mo_plain "${M}type:ABC;400,400;saveas:p57_mo_plain"
run mo_ang   "${M}chr:1411,30;type:ABC;400,400;saveas:p57_mo_ang"
run mo_tate  "${M}btn:1325;type:ABC;400,400;saveas:p57_mo_tate"
run mo_base  "${M}btn:1064;type:ABC;400,400;saveas:p57_mo_base"
run mo_base2 "${M}btn:1064;btn:1064;type:ABC;400,400;saveas:p57_mo_base2"
idle
sh tools/refenv.sh >/dev/null
