"""作図コマンドのバーの釦が、原典で何をしているかを一覧にする。

    python tools/barwired.py            作図メニューの全部
    python tools/barwired.py 32772      一つだけ

原典の控え（decomp/res/bars.txt）にある押せる部品を拾い、MFC の
振り分け表（tools/msgmap.py と同じ読み方）で受け手を引いて、その関数の
逆コンパイルに **CColorDialog・CDialog の作り手・よく出る呼び先**が
あるかを見ます。移植の src/cmd.c と src/app.c がその id を名指して
いるかどうかも併せて出します。

**これは地図です。**「効いている」と言えるのは原典に訊いた試験だけ
です（tests/bardraw_test.c など）。
"""
import io
import re
import struct
import sys
import glob

DRAW = [32771, 32772, 32773, 32785, 32806, 32847, 32870, 32872,
        32873, 32874, 32883, 32892, 32894, 32908]

b = open('orig/Jw_win.exe', 'rb').read()
pe = struct.unpack_from('<I', b, 0x3c)[0]
nsec = struct.unpack_from('<H', b, pe + 6)[0]
optsz = struct.unpack_from('<H', b, pe + 20)[0]
base = struct.unpack_from('<I', b, pe + 24 + 28)[0]
secs = []
off = pe + 24 + optsz
for i in range(nsec):
    name = b[off:off + 8].rstrip(b'\0').decode('latin1')
    vsz, va, rsz, rof = struct.unpack_from('<IIII', b, off + 8)
    secs.append((name, va + base, vsz, rof, rsz))
    off += 40
text = [s for s in secs if s[0] == '.text'][0]
rdata = [s for s in secs if s[0] == '.rdata'][0]
tlo, thi = text[1], text[1] + text[2]

handlers = {}
_, va, vsz, rof, rsz = rdata
for o in range(rof, rof + rsz - 24, 4):
    msg, code, idf, idl, sig, pfn = struct.unpack_from('<6I', b, o)
    if msg == 0x111 and code == 0 and idf == idl and tlo <= pfn < thi \
            and sig < 100:
        handlers.setdefault(idf, []).append(pfn)

body = {}
for f in glob.glob('decomp/decomp/all_*.c'):
    s = io.open(f, encoding='utf-8', errors='replace').read()
    parts = re.split(r'\n/\* ([0-9a-f]{8})  FUN_[0-9a-f]+  \d+ bytes', s)
    for i in range(1, len(parts) - 1, 2):
        body[int(parts[i], 16)] = parts[i + 1]

port = (io.open('src/cmd.c', encoding='utf-8').read()
        + io.open('src/app.c', encoding='utf-8').read())

# bars.txt のほかに bars2/bars3 もあります。見出しは
# 「=== command 232785_1323」のような姿で、頭の 2 と後ろの _NNNN は
# そのバーの出方の違いです。命令そのものは真ん中の五桁。
bars = {}
on = None
for path in ('decomp/res/bars.txt', 'decomp/res/bars2.txt',
             'decomp/res/bars3.txt'):
    try:
        lines = io.open(path, encoding='utf-8')
    except IOError:
        continue
    for l in lines:
        l = l.rstrip('\n')
        if l.startswith('=== command '):
            tag = l.split()[2]
            m = re.match(r'2?(3\d{4})', tag)
            on = int(m.group(1)) if m else None
            continue
        f = l.split('|')
        if on and len(f) >= 10 and f[0] == 'Button' and f[8] == '1':
            if (int(f[1]), f[9]) not in bars.setdefault(on, []):
                bars[on].append((int(f[1]), f[9]))

# 引数が 'all' なら、バーを持つ命令を全部
if sys.argv[1:2] == ['all']:
    want = sorted(bars)
else:
    want = [int(a) for a in sys.argv[1:]] or DRAW
for cmd in want:
    print('=== %d' % cmd)
    for cid, label in bars.get(cmd, []):
        hs = handlers.get(cid, [])
        notes = []
        # 受け手そのものと、その呼び先を一段だけ見ます（tools/cmddlg.py
        # と同じ考え方）。窓を出す釦が、受け手の中で直に出すとは限り
        # ません —— 寸法 の 設定 のように一段下ることがあります。
        def look(addr, depth):
            t = body.get(addr, '')
            if 'CColorDialog' in t:
                notes.append('色の設定')
            for x in re.findall(r'FUN_00797f57\(0x([0-9a-f]+)', t):
                notes.append('窓 %d' % int(x, 16))
            if depth > 0:
                for c2 in set(re.findall(r'FUN_([0-9a-f]{8})\(', t)):
                    a2 = int(c2, 16)
                    if a2 != addr and a2 in body and len(body[a2]) < 30000:
                        look(a2, depth - 1)

        for h in hs:
            look(h, 1)
        named = re.search(r'\b%d\b' % cid, port) is not None
        print('  %5d %-18s %-4s %s'
              % (cid, label, '移植○' if named else '移植×',
                 ' '.join(sorted(set(notes)))))
