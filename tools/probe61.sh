#!/bin/sh
# 図形 (32862) のバーを控えに取る。
#
#   sh tools/probe61.sh
#
# `src/gen/bars.h` に 32862 がありません。図形読込 のバーは**図形を読んだ
# あとにしか出ない**ので、`tools/bars.ps1` の総当たり（命令を送ってバーを
# 読む）では届かなかったのです。そこは `figin:` で通せます。
#
# このバーは 貼り付け (57637) が出すものでもあります（tools/probe56.sh）。
# 倍率 (1431)・回転角 (1412) の箱がここにあるので、控えに入れば移植でも
# 打ち込めるようになります。
#
# 出てきたものは decomp/res/bars2.txt の末尾に足してください（平の
# `=== command 32862` 見出しのまま、tools/mkbars.py がそのまま読みます）。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
idle
sh tools/refenv.sh >/dev/null
cp decomp/res/new.jww tmp/rect.jww
FIG=decomp/res/fig.jws
$PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks \
  "figin:32862,$FIG;read:59393;bar:32862" 2>&1 |
  grep -vE "^\s*$" | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
