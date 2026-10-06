#!/bin/sh
# 点 (32785) の 交点 (1066) と 仮点 (1323)。
#
#   sh tools/probe151.sh
#
# 交点 は「線・円（Ａ）を指示してください。」から始まります
# （tools/probe150.sh で読みました）。交わる二本を引いてから訊きます。
# 仮点 はファイルに入らないので、画面を撮って見ます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }

# 交わる二本。斜めにして交点が端点に乗らないようにします。
CROSS='cmd:32771;off:1333;300,300;700,500;300,500;700,300;'

run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "$2" 2>&1 |
        grep -E "throw|no |saved|read 59393" | sed 's/^/    /'
}

# 下敷きの二本だけ
run cross "${CROSS}saveas:p151_cross;"
# 交点: 一本目を指して、二本目を指す
run kouten "${CROSS}cmd:32785;btn:1066;read:59393;400,350;read:59393;400,450;read:59393;saveas:p151_kouten;"
# 二本のあと (R) で指したら
run koutenr "${CROSS}cmd:32785;btn:1066;r400,350;r400,450;saveas:p151_koutenr;"
# 仮点: ファイルに入るか
run kariten "${CROSS}cmd:32785;btn:1323;450,420;550,420;saveas:p151_kariten;"
idle

echo
for f in kouten koutenr kariten; do
    echo "--- $f vs cross"
    python tools/whatdid.py tmp/p151_cross.jww "tmp/p151_$f.jww" 2>&1 | head -10
done

# 仮点消去 (1064) と 全仮点消去 (1065)。仮点を三つ置いてから。
K3='cmd:32785;btn:1323;400,350;500,350;600,350;'
run kari3   "${CROSS}${K3}saveas:p151_kari3;"
run karidel "${CROSS}${K3}btn:1064;read:59393;500,350;saveas:p151_karidel;"
run kariall "${CROSS}${K3}btn:1065;saveas:p151_kariall;"
# 仮点を置いたあと 1323 を押し直すと本点に戻るか
run kariback "${CROSS}${K3}off:1323;450,450;saveas:p151_kariback;"
idle
echo
for f in kari3 karidel kariall kariback; do
    echo "--- $f vs cross"
    python tools/whatdid.py tmp/p151_cross.jww "tmp/p151_$f.jww" 2>&1 | head -8
done
