"""線記号変形: 文字入力の行のある記号を、『AB』と打って置かせる。

    python tools/skall_t.py          → tools/skall_t.sh と tests/skauto_t.inc
    sh tools/skall_t.sh [A B ...]    → decomp/res/sk_<文字><番号 2 桁>t.jww

tools/skall.py と同じ押し方で、入力の数だけ「AB を打って (700,300) で確定」を繰り返す。
文字の長さで決まる枠の基準点（制御コード 300 台）や、打つと続く行（25006）を確かめる。
"""
import sys

sys.path.insert(0, 'tools')
src = open('tools/skall.py', encoding='utf-8').read()
# skall.py の main() を呼ばずに feats・recipe・items だけ使う
src = src.replace('\nmain()\n', '\n')
ns = {}
exec(compile(src, 'skall', 'exec'), ns)
items, feats, recipe = ns['items'], ns['feats'], ns['recipe']

NL = chr(10)


def main():
    sh = ['#!/bin/sh', '# tools/skall_t.py が作った。文字を打って置かせる',
          'cd "$(dirname "$0")/.."',
          'export PATH="$PATH:/c/prog/tools/w64devkit/bin"',
          'only="$*"', 'S="sh tools/skprobe.sh"']
    inc = ['/* tools/skall_t.py が作った */']
    for L in 'ABCDEFGHIJ':
        head, its = items('orig/JW_OPT4%s.DAT' % ('' if L == 'A' else L))
        for i, rows in enumerate(its):
            n = i + 1
            hdr = rows[0].decode('cp932', 'replace').split()
            ptr = int(hdr[0]) if hdr and hdr[0].isdigit() else 0
            need1, need2, mouse, nin = feats(rows)
            if not nin:
                continue
            pre, post = recipe(ptr, need1, need2, mouse, nin)
            post = post.replace('700,300;', 't:AB;700,300;')
            name = '%s%02dt' % (L, n)
            clicks = post.replace(';', ';wait:700;')
            clicks = clicks.replace('t:AB;wait:700;', 'type::AB;wait:500;')
            sh.append('if [ -z "$only" ] || echo " $only " | grep -q " %s "; then' % L)
            sh.append("  [ -f decomp/res/sk_%s.jww ] || $S %s %s %d '%s' 'wait:900;%s'" %
                      (name, name, L, n, pre, clicks))
            sh.append('fi')
            inc.append('    { "%s", \'%s\', %d, "%s", "%s" },' % (name, L, n, pre, post))
    sh.append('echo done')
    open('tools/skall_t.sh', 'w', encoding='utf-8', newline=NL).write(NL.join(sh) + NL)
    open('tests/skauto_t.inc', 'w', encoding='utf-8', newline=NL).write(NL.join(inc) + NL)
    print('typed items', len(inc) - 1)


main()
