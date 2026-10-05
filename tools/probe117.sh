#!/bin/sh
# × のある窓とない窓 —— 残りの三つに訊きます。
#
#   sh tools/probe117.sh
#
# `tools/probe116.sh` で レイヤ設定 (32808) には HTCLOSE がない（＝× が
# ない）と分かりました。PrintWindow の絵でも 軸角 (32842) の見出しには
# × が写っていません。線属性 (32898) は見出しの作りがそもそも違います。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "nc |visible|client |HT |throw|no " | sed 's/^/    /'
}

run jikkaku  "dlgnc:32842"
run bairitsu "dlgnc:32811"
run zoku     "dlgnc:32898"
idle
