#!/bin/sh
# 移植に影も形もない小粒の命令を、一つずつ原典に訊きます。
#
#   sh tools/probe120.sh
#
# `tmp/miss.txt` の一覧のうち、メニューから出せて一手か二手で済みそうな
# ものです。各命令について「何か窓が出るか」「問いかけが変わるか」
# 「バーが変わるか」を見ます。
#
#   32938 設定>角度取得>数値角度      32962 同         軸角
#   32941 設定>長さ取得>数値長        32912 設定>環境設定ファイル>目盛基準点
#   32936 同 レイヤ非表示化           32923/32924 同 読込み/書出し
#   32928 その他>寸法図形化           32929 同 寸法図形解除
#   32897 その他>測定                32930 同 距離指定点
#   32987 ファイル操作>図面情報コピー   32967 同 タグジャンプ
#   32915 作図>AUTOモード
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
ask() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks \
        "300,300;700,500;read:59393;raw:f,273,$1,0;wait:900;read:59393;bar;tops" \
        2>&1 | grep -E "read 59393|^(Button|ComboBox|Edit|Static)\||top .* vis=1|throw" |
        sed 's/^/    /'
}

for id in 32938 32962 32941 32912 32936 32923 32924 32928 32929 32897 32930 32987 32967 32915; do
    ask $id
done
idle
