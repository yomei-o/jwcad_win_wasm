"""線記号変形: 全ファイル（A〜J）の全記号を、自然な押し方で原典に置かせる。

    python tools/skall.py            → tools/skall.sh（原典に押させる）と tests/skauto.inc（移植の試験の表）
    sh tools/skall.sh [A B ...]      → decomp/res/sk_<文字><番号 2 桁>.jww

押し方は記号の作りから決める（tools/skitem.py と同じ読み方）:
  線１だけ（頭 0）      : 線を左の端のそば (450,400) で押す
  線１だけ（頭 1 以上） : 線 (450,400) → 位置 (500,470)
  線１・線２            : 壁と 縦線 (600,500)-(600,300) を引き、(400,400) → (600,350)
  線なし                : 位置 (500,450)、倍率位置があれば (580,350)
  文字入力の行          : そのあとに 入力の数だけ (700,300)（打たない）
"""
import os
import re
import sys

sys.path.insert(0, 'tools')
src = open('tools/skitem.py', encoding='utf-8').read().replace('\nmain()\n', '\n')
ns = {}
exec(compile(src, 'skitem', 'exec'), ns)
items = ns['items']

SPECIAL = {500, 700, 750, 751, 800, 10000, 11400, 12930}


def feats(rows):
    need1 = need2 = mouse = 0
    nin = 0
    for ln in rows[1:]:
        t = ln.decode('cp932', 'replace').split()
        if not t or t[0].startswith('#'):
            continue
        try:
            c1 = int(t[0])
        except ValueError:
            continue
        if c1 in SPECIAL or 760 <= c1 <= 768:
            if 760 <= c1 <= 768:
                mouse = c1
            continue
        if re.match(r'^99\d$', t[0]) and len(t) <= 3:
            continue
        if len(t) < 6:
            continue
        try:
            c2 = int(t[1])
        except ValueError:
            continue
        isarc = any(x in ('e', 'E') for x in t[6:12])
        issol = any(re.match(r'^a[1-7]$', x) for x in t[6:14])
        if 20000 <= c1 < 22000 or 25000 <= c1 < 27000:
            nin += 1
        if not isarc and not issol:
            if c1 % 100 == 10 or c2 == 10:
                need1 = 1
            if c1 % 100 == 20 or c2 == 20:
                need2 = 1
    return need1, need2, mouse, nin


def recipe(ptr, need1, need2, mouse, nin):
    pre, post = '', ''
    if need1 and need2:
        pre = '600,500;600,300;'
        post = '400,400;600,350;'
    elif need1 and ptr == 0:
        post = '450,400;'
    elif need1:
        post = '450,400;500,470;'
    else:
        post = '500,450;'
        if mouse:
            post += '580,350;'
    post += '700,300;' * nin
    return pre, post


def main():
    sh = ['#!/bin/sh', '# tools/skall.py が作った。全記号を原典に置かせる',
          'cd "$(dirname "$0")/.."',
          'export PATH="$PATH:/c/prog/tools/w64devkit/bin"',
          'only="$*"', 'S="sh tools/skprobe.sh"']
    inc = ['/* tools/skall.py が作った */']
    for L in 'ABCDEFGHIJ':
        head, its = items('orig/JW_OPT4%s.DAT' % ('' if L == 'A' else L))
        for i, rows in enumerate(its):
            n = i + 1
            hdr = rows[0].decode('cp932', 'replace').split()
            ptr = int(hdr[0]) if hdr and hdr[0].isdigit() else 0
            need1, need2, mouse, nin = feats(rows)
            pre, post = recipe(ptr, need1, need2, mouse, nin)
            name = '%s%02d' % (L, n)
            clicks = post.replace(';', ';wait:700;')
            sh.append('if [ -z "$only" ] || echo " $only " | grep -q " %s "; then' % L)
            sh.append('  [ -f decomp/res/sk_%s.jww ] || $S %s %s %d \'%s\' \'wait:900;%s\'' %
                      (name, name, L, n, pre, clicks))
            sh.append('fi')
            inc.append('    { "%s", \'%s\', %d, "%s", "%s" },' % (name, L, n, pre, post))
    sh.append('echo done')
    open('tools/skall.sh', 'w', encoding='utf-8', newline='\n').write('\n'.join(sh) + '\n')
    open('tests/skauto.inc', 'w', encoding='utf-8', newline='\n').write('\n'.join(inc) + '\n')
    print('items', len(inc) - 1)


main()
