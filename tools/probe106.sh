#!/bin/sh
# $EDTBLK を走っているあいだに捕まえる。
#
#   sh tools/probe106.sh
#
# `tools/probe105.sh` では走り終わったあとに探して見つかりませんでした。
# 終了時に消しているのでしょう。そこで**走っている最中**に探します:
# 線を三本引いてから長く待たせ、そのあいだにフォルダを見ます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
( $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks \
    "off:1333;300,300;700,500;300,550;700,650;300,200;700,250;wait:25000;" >/dev/null 2>&1 ) &
sleep 12
echo "--- while it runs"
for d in . orig tmp "$TEMP" "$LOCALAPPDATA/Temp" "$USERPROFILE/Documents"; do
    [ -d "$d" ] || continue
    ls -a "$d" 2>/dev/null | grep -i 'EDTBLK' | sed "s|^|    $d/|"
done
echo "--- any file newer than the run, under orig and tmp"
find orig tmp . -maxdepth 1 -newermt '-30 seconds' -type f 2>/dev/null | head -20
wait
idle
