#!/bin/sh
# ハッチの 図形 —— 格子はどこに留まっているのか。
#
#   sh tools/probe86.sh
#
# tools/probe85.sh で歩きが通りました:
#
#     ハッチ (32874) → 図形 (1693) → 範囲選択 (1067) → 範囲の二隅
#            → 選択図形登録 (1068) → 角度・縦ピッチ・横ピッチ
#            → 境界 (R) → 実行 (1148)
#
# L 字（横 36.735・縦 18.367）を 角度 0・縦 60・横 80 で敷いたら、
# 3x3 の九つが出て、間隔は横が 80、縦が 60 でした。**どこを起点に
# 並んでいるか**がまだ分かりません。素のハッチは原点（0）に留まって
# いますが、今度の九つは 0 の倍数のところにいません。
#
#   base    probe85 の a と同じ（較べる元）
#   region  矩形だけ (50,50) 動かす
#   pat     L 字だけ下へ動かす
#   p40     ピッチを 40/40 に
#   ang     角度 30
#
# 矩形を動かして九つも同じだけ動けば境界が起点、L を動かして動けば
# 図形自身が起点、どちらでも動かなければ原点です。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32772 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

# $1 rect corner 1, $2 rect corner 2, $3 L corner, $4 L right, $5 L down,
# $6 range corner 1, $7 range corner 2, $8 boundary click, $9 settings
mk() {
    echo "$1;$2;cmd:32771;off:1333;$3;$4;$3;$5;cmd:32874;pb:1693;wait:800;pb:1067;wait:800;$6;$7;pb:1068;wait:1000;$9r$8;btn:1148;"
}

S='set:1419,0;set:1411,60;set:1412,80;'
run base   "$(mk 300,300 800,600 880,180 940,180 880,210 850,150 970,240 550,300 "$S")saveas:p86_base"
run region "$(mk 350,350 850,650 880,180 940,180 880,210 850,150 970,240 600,350 "$S")saveas:p86_region"
run pat    "$(mk 300,300 800,600 880,260 940,260 880,290 850,230 970,320 550,300 "$S")saveas:p86_pat"
run p40    "$(mk 300,300 800,600 880,180 940,180 880,210 850,150 970,240 550,300 'set:1419,0;set:1411,40;set:1412,40;')saveas:p86_p40"
run ang    "$(mk 300,300 800,600 880,180 940,180 880,210 850,150 970,240 550,300 'set:1419,30;set:1411,60;set:1412,80;')saveas:p86_ang"
idle
sh tools/refenv.sh >/dev/null
