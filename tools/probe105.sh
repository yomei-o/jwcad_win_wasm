#!/bin/sh
# 戻る・進む の下書きファイル ($EDTBLK) はどこに出るのか。
#
#   sh tools/probe105.sh
#
# デコンパイルによると 進む (0xe12c) は `FUN_00453bd0`、戻る (0xe12b) は
# `FUN_00458a80` で、どちらも `FUN_0044ea50` が組み立てる
#
#     $EDTBLK<n>.<nnn>
#
# という名前のファイルを読み書きします（`FUN_007a6256(..,1,0x1000,0)` は
# fread）。つまり Jw_cad の 戻る は**取っておいた下書きを読み直す**作りで、
# 元に戻る を投げたときの挙動がばらついた（RESUME の「進む は測り方から
# 作り直し」）のは、この下書きが前の走りのぶん残っていたから、という
# 見当がつきます。
#
# まずは**どこに出るのか**を押さえます。走る前と走ったあとで、原典の
# フォルダと図面のフォルダと %TEMP% を見比べます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
look() {
    echo "--- $1"
    for d in orig tmp "$TEMP" "$LOCALAPPDATA/Temp"; do
        [ -d "$d" ] || continue
        ls -a "$d" 2>/dev/null | grep -i 'EDTBLK' | sed "s|^|    $d/|"
    done
}
idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
look before
$PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks \
  "off:1333;300,300;700,500;300,550;700,650;300,200;700,250;wait:2000;read:59393;" 2>&1 |
  grep -E "read 59393|throw|no " | sed 's/^/    /'
look after
idle
