#!/bin/sh
# 作図コマンドの**つまみを一つずつ押して**、原典に同じ三クリックで
# 引かせる。
#
#   sh tools/barsweep.sh             作図メニューの全部（五分ほど）
#   sh tools/barsweep.sh 32773       一つだけ
#
# `tools/drawsweep.sh` は素の状態だけを見ます。こちらはそのバーの釦を
# 一つずつ押してから引かせるので、つまみが効いているかどうかの地図に
# なります。答えは `decomp/res/bsw_<cmd>_<id>.jww`。
#
# **一つの命令につき Jw_cad は一度だけ起動します。**つまみごとに
# 起動し直していたときは八十七回で四十分かかりました。起動と終了が
# ほとんどの時間だったので、一回の中で
#
#     命令を送り直す → つまみを押す → 窓が出たら閉じる → 三クリック
#     → 保存
#
# を繰り返します。**押し戻しはしません。**`off:` で戻そうとすると、
# 原典には押しても BM_GETCHECK が立たないまま効くつまみ（円 の 円弧
# など）があって、戻るものと戻らないものが混じります。移植の側から
# それを言い当てられないので、どちらも素直に積み上げる形に揃えました。
# つまみが見つからない段は飛ばします（矩形 を押すと線のバーの他の
# つまみが消えるので、そのあとの段は「答えなし」になります）。
#
# **押すのは `pb:`（投げる）で、そのあと `dlgoff` を入れます。**
# 寸法 の 設定 (1071) のように窓を出す釦があって、`btn:`（送る）だと
# 窓が閉じるまで戻ってこず、そこで全部止まってしまいます。
#
# 絵は消さずに積み上がっていきます。だから一枚ごとの中身は「そこまでに
# 引いた全部」で、**そのつまみが引いたものは一つ前との差**です。
# `tests/barsweep_test.c` がそう読みます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 60 ] && { taskkill //F //IM Jw_win.exe >/dev/null 2>&1; break; }; sleep 1; done; }

# 下敷き: 交わる二本と円一つ。最後に 点 へ逃がしておきます —— 同じ命令を
# 続けて送ると別の姿のバーになることがあり（線 を二度送ると 矩形 の
# つまみが見えなくなりました）、点 はどれとも重ならないので。
BASE='cmd:32771;off:1333;300,300;700,500;300,500;700,300;cmd:32773;500,250;560,250;cmd:32785;'
CLICKS='400,350;600,450;500,420;'

ids_of() {
    python - "$1" <<'PYEOF'
import io, sys
want = sys.argv[1]
out, on = [], False
for l in io.open('decomp/res/bars.txt', encoding='utf-8'):
    l = l.rstrip('\n')
    if l.startswith('=== command '):
        on = l.split()[2] == want
        continue
    if not on:
        continue
    f = l.split('|')
    # 押せる釦だけ。コンボは打ち込むもので、押すものではありません
    if len(f) >= 10 and f[0] == 'Button' and f[8] == '1':
        out.append(f[1])
print(' '.join(out[:24]))
PYEOF
}

one() {
    cmd=$1
    ids=$(ids_of "$cmd")
    echo "=== $cmd  ($ids)"
    steps="cmd:${cmd};${CLICKS}saveas:bsw_${cmd}_0;"
    for id in $ids; do
        steps="${steps}cmd:${cmd};pb:${id};dlgoff;${CLICKS}saveas:bsw_${cmd}_${id};"
    done
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -NoSave -Clicks "${BASE}${steps}" 2>&1 |
        grep -aoE "saved tmp...bsw_[0-9_]+\.jww|no control [0-9]+" |
        sed 's/^/    /' | tee tmp/bsw_one.txt

    # **一人ずつの採り直し。**つまみの中には、押すとバーそのものを
    # 差し替えてしまうものがあります —— 曲線 で ベジェ曲線 (1692) を
    # 押すと 連結線指定 (1068) が消え、連続線 で 連続弧 (2492) を押すと
    # 基準角度 (1065)・基点 (1066)・手書線 (1774) が消えて 弧反転 (1067)
    # が出てきます。積み上げ式の一本道では、そのあとのつまみに手が
    # 届きません。消えていたものは**素の状態からそれ一つだけ**押して
    # 採り直し、`bsw_<cmd>_<id>_solo.jww` に残します。
    # 試験はこの綴りを見て、一つ前ではなく**下敷きとの差**で読みます。
    for id in $(sed -n 's/.*no control \([0-9]*\).*/\1/p' tmp/bsw_one.txt | sort -u); do
        idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
        $PS -Open tmp/rect.jww -NoSave -Clicks \
            "${BASE}cmd:${cmd};pb:${id};dlgoff;${CLICKS}saveas:bsw_${cmd}_${id}_solo;" \
            2>&1 | grep -aoE "no control [0-9]+" | sed 's/^/    solo /'
    done
}

if [ $# -gt 0 ]; then
    for c in "$@"; do one "$c"; done
else
    for c in 32771 32772 32773 32785 32806 32847 32870 32872 32873 \
             32874 32883 32892 32894 32908; do
        one "$c"
    done
fi
idle
for f in tmp/bsw_*.jww; do
    [ -f "$f" ] && cp "$f" "decomp/res/$(basename "$f")"
done
echo "collected: $(ls decomp/res/bsw_*.jww 2>/dev/null | wc -l)"
