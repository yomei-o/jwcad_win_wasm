#!/bin/sh
# ダイアログの × は OK なのか キャンセル なのか。
#
#   sh tools/probe118.sh
#
# 縮尺・読取設定 (32944) の分母 (1471) に 2 を打ってから、OK と × の
# 二通りで閉じ、保存した図面の縮尺を見ます。
#
#   ok     scales 2 100 100 100     打った 1/2 が入る
#   cross  scales 100 100 100 100   打ったものは捨てられる
#
# **× は キャンセル でした。**だから移植の当たり判定は、キャンセル釦の
# id である 2 を返します（`src/ui.c` の `dlg_close_hit`）。
#
# ついでに分かったこと: **投げたメッセージでは × を押せません。**
# WM_NCLBUTTONDOWN/UP も WM_SYSCOMMAND SC_CLOSE も WM_CLOSE も、窓は
# 出たままでした。効いたのは本物のポインタを動かして押したときだけです
# （`dlgx:` はその順に試します）。Windows 11 の見出しの釦は DWM 側が
# 握っているからでしょう。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "cross was|SC_CLOSE|WM_CLOSE|pointer|filled|throw|no |saved" |
        sed 's/^/    /'
}

run ok     "dlgin:32944,1471=2;300,300;700,500;saveas:p118_ok"
run cross  "dlgx:32944,1471=2;300,300;700,500;saveas:p118_x"
idle
for f in p118_ok p118_x; do
    printf '%-10s ' "$f"
    python tools/jww.py "tmp/$f.jww" 2>/dev/null | grep -i "scales" || echo '(no scale line)'
done
