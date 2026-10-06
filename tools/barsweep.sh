#!/bin/sh
# 作図コマンドの**つまみを一つずつ押して**、原典に同じ三クリックで
# 引かせる。
#
#   sh tools/barsweep.sh             作図メニューの全部（一時間ほど）
#   sh tools/barsweep.sh 32773       一つだけ
#
# `tools/drawsweep.sh` は素の状態だけを見ます。こちらはそのバーの釦を
# 一つずつ押してから引かせるので、つまみが効いているかどうかの地図に
# なります。答えは `decomp/res/bsw_<cmd>_<id>.jww`。
#
# **つまみごとに Jw_cad を起動し直します。**まとめて押していくと、
# 矩形 (1332) のように押した途端にバーの姿が変わるものがあって、次の
# つまみが見つからなくなるからです（最初はそれで三つしか取れません
# でした）。そのぶん遅く、全部で一時間ほどかかります。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 120 ] && break; sleep 1; done; }

# 下敷き: 交わる二本と円一つ。最後に 線 へ戻しておきます —— 同じ命令を
# 続けて送ると別の姿のバーになることがあるので。
BASE='cmd:32771;off:1333;300,300;700,500;300,500;700,300;cmd:32773;500,250;560,250;cmd:32771;'
CLICKS='400,350;600,450;500,420;'

draw() {   # draw <cmd> <id> <押す手順>
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    printf '    %-6s ' "$2"
    $PS -Open tmp/rect.jww -NoSave \
        -Clicks "${BASE}cmd:$1;$3${CLICKS}saveas:bsw_$1_$2;" 2>&1 |
        grep -oE "saved tmp...[a-z0-9_]+\.jww|no control [0-9]+" | head -1
    echo
}

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
    ids=$(ids_of "$1")
    echo "=== $1  ($ids)"
    draw "$1" 0 ''
    for id in $ids; do
        draw "$1" "$id" "btn:${id};"
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
