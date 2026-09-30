#!/bin/sh
# ハッチの 図形 (1693) が出すファイル窓の中身。
#
#   sh tools/probe73.sh
#
# tools/probe72.sh は「no リスト表示 box in the file window」で止まりました。
# jwdraw の figin: は、図形読込 の窓にある「リスト表示」(1323) で右側の
# 図形の絵を SysListView32 に化けさせてから行を叩く作りです。ハッチの
# 図形 の窓にはその箱がありません。では何があるのか、開いたまま一覧します。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
idle
sh tools/refenv.sh >/dev/null
cp orig/Test5.jww tmp/rect.jww
$PS -Open tmp/rect.jww -Cmd 32772 -NoSave \
  -Clicks '300,300;800,600;cmd:32874;pb:1693;wait:2000;top' 2>&1 |
  sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
