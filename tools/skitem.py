"""線記号変形の JW_OPT4?.DAT から、一つの記号だけの DAT を作る（探りの道具）。

    python tools/skitem.py <文字 A〜J> <番号 1〜> <出力フォルダ>   → <出力フォルダ>/JW_OPT4.DAT
    python tools/skitem.py <文字> list                          → 記号の一覧
ファイル選択の窓に一つだけ並ぶので、いつも同じ位置を押せば選べる。
"""
import os
import re
import sys


def items(path):
    raw = open(path, 'rb').read()
    lines = raw.split(b'\n')
    head = lines[:3]
    out = []
    cur = None
    for ln in lines[3:]:
        s = ln.strip()
        if cur is None:
            if not s or s.startswith(b'#'):
                continue
            # 説明の区切り（=====）が来たら終わり
            if s.startswith(b'===') or s.startswith(b'='):
                break
            cur = [ln]
            continue
        cur.append(ln)
        m = re.match(rb'^\s*99\d', ln)
        if m and len(s.split()[0]) == 3:
            out.append(cur)
            cur = None
    return head, out


def main():
    letter = sys.argv[1]
    src = 'orig/JW_OPT4%s.DAT' % ('' if letter == 'A' else letter)
    head, its = items(src)
    if sys.argv[2] == 'list':
        for i, it in enumerate(its):
            print(i + 1, it[0].decode('cp932', 'replace').rstrip())
        return
    n = int(sys.argv[2])
    out = sys.argv[3]
    os.makedirs(out, exist_ok=True)
    body = b'\n'.join(its[n - 1])
    data = head[0].rstrip(b'\r') + b'\n1\n999\n\n' + body + b'\n'
    open(os.path.join(out, 'JW_OPT4.DAT'), 'wb').write(data)
    print(its[n - 1][0].decode('cp932', 'replace').rstrip())


main()
