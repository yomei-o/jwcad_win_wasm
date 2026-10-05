#!/bin/sh
# 測定の残り三釦 —— ○単独円指定 (1068)・測定結果書込 (1071)・書込設定 (1072)。
#
#   sh tools/probe142.sh
#
# 1071 は `pb:`（投げる）で押したら、押した途端に読み出しが 24.490 から
# 0.000 に戻り、書かれた文字も 0.000 でした（`tools/probe129.sh`）。
# 投げた押しが先に届いたのかもしれないので、今度は `btn:`（送る）で。
# 1072 は窓が出るなら `dlg:b` で中身ごと取れます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|=== dialog|throw|no |saved|^(Button|ComboBox|Edit|Static)\|" |
        sed 's/^/    /'
}
R='read:59393;'
S='raw:f,273,32897,0;wait:800;'
# a circle of radius 100 px about (500,400), then back to 測定
C='cmd:32773;500,400;600,400;'

# ○単独円指定: the circle itself
run tandoku "${C}${S}pb:1068;wait:600;${R}600,400;${R}500,400;${R}"
# 測定結果書込 with a sent click
run write "${S}300,300;700,300;${R}btn:1071;${R}500,600;${R}saveas:p142_write"
# 書込設定
run setup "${S}dlg:b1072,tmp/p142_setup.png"
idle
echo
echo "--- 測定結果書込 が置いたもの"
python tools/whatdid.py decomp/res/new.jww tmp/p142_write.jww 2>&1 | head -4
