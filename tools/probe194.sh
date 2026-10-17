#!/bin/sh
# 寸法 ＝ の段 7 —— 基準点と同じ画素のクリックは反転するか（nokori.md
# 「2-0. 原典との総点検」で 実マウスの動きが 未測定のまま残っていた一手）。
#
#   sh tools/probe194.sh
#
# 線の途中の点や 遠い自由点は 原典の読取り（jw_read 相当）に 拾えず
# クリックごと捨てられる（最初に 500,250 のような画面の空いた所を使って
# 嵌まった）。ここは 水平線を二本（上下）引いて その四つの頂点だけを
# 基準点・始点・終点に使う。
#
#   vtest   基準点を **実カーソルで** 押したあと **同じ画素** をもう一度
#           押してから 始点・終点
#   vtest2  同じく（繰り返して 決まった結果か確かめる）
#   posted  同じく、ただし 同じ画素への二回目のクリックは 投げメッセージ
#           だけ（SetCursorPos なし。基準点のほうは 実カーソル）
#   direct  対照: 基準点のあと **別の頂点** へすぐクリック（＝「ﾏｳｽ移動で
#           確定」の軸、段 7 を経ない）
#   movedv  基準点のあと 実カーソルを 2 画素を超えて離し、基準点の画素へ
#           戻してからクリック（段 7 の「2 画素動けば段 3」が 戻っても
#           効いたままか）
#   eq2flip ＝(2) でも 同じ画素のクリックで反転するか
#
# 結果（tmp/p194_*.jww、./tmp/jwdump.exe で読む。原典で測った、2026-10-18）:
#
#   direct   基準点 y=26.3268 → 寸法線 y=16.3268（基準点 − 10 = SUNPOSEN1）
#   vtest/vtest2/posted
#            同じ基準点 → 寸法線 y=36.3268（基準点 + 10）―― **反転した**。
#   movedv   基準点のあと 実カーソルを 2 画素超え離してから 戻すと、戻る
#            途中の WM_MOUSEMOVE だけで 既に「寸法の始点を指示して下さい」
#            に変わり（クリックしていないのに段 7 を抜ける）、戻って押した
#            クリックは 反転しない（y=16.3268、direct と同じ）
#   eq2flip  ＝(2) も 基準点 + 5（SUNPOSEN2 の反対側）―― 同じ反転
#
# **注意（2026-10-18 に さらに切り分けた）**: 上の vtest/posted の「反転した」
# は、どちらも **基準点のクリックに実カーソル（c300,300,r）を使っていた**
# ことが効いていた。基準点・同じ画素への二回目クリックとも **座標だけの
# 投げメッセージ**（SetCursorPos を一度も呼ばない）にすると、同じ画素を
# 二回押しても 反転しない（基準点 − 10 のまま）―― これは
# `tools/fuzzcases/505.txt`〜`508.txt`（答え `decomp/res/fz_505.jww` ほか、
# 以前からの実測）と一致する。つまり 反転の判定は 読みどおり GetCursorPos
# を見ていて、投げメッセージだけでは 実カーソルが そこに無いため「動いた
# まま」に見え、反転しない。基準点の段階で 一度でも 実カーソルを その画素へ
# 置いていれば（あとの再クリックが投げメッセージでも）、GetCursorPos は
# 一致するので 反転する。
#
# 移植の `jw_cmd_point` は 座標と釦だけを受け、呼び手が実際にカーソルを
# 動かしたかを渡す道が無い（fuzzcases の答えも 座標だけで原典と照らして
# いる）。そのため **座標だけの場合に原典が実際にする（反転しない）ほうに
# 合わせ**、`sun_eq_flip` は立てないまま残した（src/cmd.c の `sun_eq_wait`
# の分岐のコメント、`tests/sunpoeq_test.c`「同一点クリック（座標だけ）は
# 反転しない」）。実カーソルでだけ起きる反転は 道が無く 入れていない。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() {
    k=0
    while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do
        k=$((k+1)); [ $k -gt 90 ] && break; sleep 1
    done
}
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
    idle
}
# 32771 (線) で 水平線を二本: 上 (300,300)-(700,300)、下 (300,500)-(700,500)
LINES='300,300;700,300;300,500;700,500;'
EQ='cmd:32847;btn:1060;'
EQ2='cmd:32847;btn:1060;btn:1060;'

run vtest   "${LINES}${EQ}c300,300,r;c300,300;c300,500;c700,500;saveas:p194_vtest"
run vtest2  "${LINES}${EQ}c300,300,r;c300,300;c300,500;c700,500;saveas:p194_vtest2"
run posted  "${LINES}${EQ}c300,300,r;300,300;c300,500;c700,500;saveas:p194_posted"
run direct  "${LINES}${EQ}c300,300,r;c300,500;c700,500;saveas:p194_direct"
run movedv  "${LINES}${EQ}c300,300,r;m600,450;m300,300;c300,300;c300,500;c700,500;saveas:p194_movedv"
run eq2flip "${LINES}${EQ2}c300,300,r;c300,300;c300,500;c700,500;saveas:p194_eq2flip"
