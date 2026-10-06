#!/bin/sh
# 作図コマンドの**つまみを一つずつ押して**、原典に同じ三クリックで
# 引かせる。
#
#   sh tools/barsweep.sh             作図メニューの全部
#   sh tools/barsweep.sh 32773       一つだけ
#
# `tools/drawsweep.sh` は素の状態だけを見ます。こちらはそのバーの釦と
# チェックを一つずつ押してから引かせるので、つまみが効いているかどうかの
# 地図になります。答えは `decomp/res/bsw_<cmd>_<id>.jww`。
#
# 一つの命令につき Jw_cad を一度だけ起動して、押しては引き、押しては
# 引きを繰り返します（毎回起動すると何時間もかかるので）。**押した
# ものは次に持ち越されます**ので、ここで取れるのは「順に押していった
# ときの絵」です。素の絵との差があれば、そのつまみは効いています。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 120 ] && break; sleep 1; done; }

BASE='cmd:32771;off:1333;300,300;700,500;300,500;700,300;cmd:32773;500,250;560,250;'
CLICKS='400,350;600,450;500,420;'

one() {
    cmd=$1
    # そのバーの、押せる部品の id（静的なものは除く）
    ids=$(python - "$cmd" <<'PYEOF'
import io, re, sys
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
    if len(f) >= 10 and f[0] in ('Button', 'ComboBox') and f[8] == '1':
        out.append(f[1])
print(' '.join(out[:24]))
PYEOF
)
    [ -z "$ids" ] && { echo "$cmd: no controls"; return; }
    steps=""
    for id in $ids; do
        steps="${steps}btn:${id};${CLICKS}saveas:bsw_${cmd}_${id};"
    done
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $cmd  ($ids)"
    $PS -Open tmp/rect.jww -NoSave \
        -Clicks "${BASE}cmd:${cmd};${CLICKS}saveas:bsw_${cmd}_0;${steps}" 2>&1 |
        grep -cE "saved tmp" | sed 's/^/    saved /'
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
