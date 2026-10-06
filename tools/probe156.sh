#!/bin/sh
# 円 (32773) の作図途中の 戻る。
#
#   sh tools/probe156.sh
#
# 作図途中の 戻る で残っているのは 円 だけです。`CZukeiEnko` の slot 16
# (FUN_006471c0) は点が置いてあれば +0x308 を 5 → 2、それ以外は 0 に
# しますが、+0x308 が移植の en_step のどれに当たるのかが分かりません。
# 原典に押させて、何段戻るのかを見ます。
#
# 見るのは状態行です —— 円 は 中心 を訊いてから 半径 を訊くので、
# 行が戻れば段が戻ったということです。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }

run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "$2" 2>&1 |
        grep -E "throw|no |saved|read 59393" | sed 's/^/    /'
}

# 素の円: 中心 → 半径。一点置いてから 戻る
run plain0 'cmd:32773;read:59393;cmd:57643;read:59393;'
run plain1 'cmd:32773;500,400;read:59393;cmd:57643;read:59393;'
# 円弧 (1318): 中心 → 半径と始角 → 終角
run arc1 'cmd:32773;btn:1318;500,400;read:59393;cmd:57643;read:59393;'
run arc2 'cmd:32773;btn:1318;500,400;600,400;read:59393;cmd:57643;read:59393;cmd:57643;read:59393;'
# 一つ描いたあとに 戻る を押すと、図面から消えるのか、描きかけに戻るのか
run after 'cmd:32773;500,400;600,400;read:59393;cmd:57643;read:59393;saveas:p156_after;'
run drawn 'cmd:32773;500,400;600,400;saveas:p156_drawn;'
idle

echo
echo "--- after vs drawn"
python tools/whatdid.py tmp/p156_drawn.jww tmp/p156_after.jww 2>&1 | head -5
