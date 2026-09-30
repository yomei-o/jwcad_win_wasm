#!/bin/sh
# 文字基点設定 の 下線作図 (1327)・上線作図 (1328)・左右縦線 (1329)。
#
#   sh tools/probe71.sh
#
# 絵は合っていますが（tests/mojikijun_test.c）、何をするかは訊いて
# いませんでした。名前からすると文字のまわりに線を引くのでしょう。
# 素の文字は (-94.2857,-34.898)-(-78.2857,-34.898)、走り 16 mm・
# 高さ 10 mm（decomp/res/moji_plain.jww）。線が出るなら、その四辺の
# どこにどう引かれるかが読めます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no control|saved" | sed 's/^/    /'
}

run under "cmd:32806;dlgin:b1064,1327=!;type:ABC;400,400;saveas:p71_under"
run over  "cmd:32806;dlgin:b1064,1328=!;type:ABC;400,400;saveas:p71_over"
run side  "cmd:32806;dlgin:b1064,1329=!;type:ABC;400,400;saveas:p71_side"
run all3  "cmd:32806;dlgin:b1064,1327=!,1328=!,1329=!;type:ABC;400,400;saveas:p71_all3"
idle
sh tools/refenv.sh >/dev/null
