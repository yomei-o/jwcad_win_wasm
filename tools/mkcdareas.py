"""docs/colordlg_textareas.txt —— 色の設定 で採点から外すところ。

    python tools/mkcolordlg.py && python tools/mkcdareas.py

外すのは二つだけです:

  * **窓の縁と見出し**。`docs/ref_colordlg.png` は PrintWindow で撮った
    ものなので、見えない縁が黒く写ります（ほかのダイアログと同じ）
  * **Windows の字で描いてあるところ**。移植の字形は原典のものでは
    ないので、ここは採点しません —— `docs/sunpodlg_textareas.txt` と
    同じ扱いです

升目・虹・明るさの帯・見本枠はどれも**外しません**。そこは原典と
一画素も違わないので、外す理由がありません。
"""
import io
import re

SRC = 'src/gen/colordlg.h'
OUT = 'docs/colordlg_textareas.txt'


def val(name):
    m = re.search(r'#define %s\s+(\d+)' % name,
                  io.open(SRC, encoding='utf-8').read())
    return int(m.group(1))


W, H = val('JW_CD_W'), val('JW_CD_H')
B, C = val('JW_CD_BORDER'), val('JW_CD_CAPTION')
CW, CH = val('JW_CD_CW'), val('JW_CD_CH')

rows = []
for m in re.finditer(r'\{\s*(-?\d+),\s*(-?\d+),\s*(-?\d+),\s*(-?\d+),'
                     r'\s*(\d+), (JW_CD_\w+)\s*, (\d), "(.*)" \},',
                     io.open(SRC, encoding='utf-8').read()):
    x, y, w, h, cid, kind, en, text = m.groups()
    rows.append((int(x), int(y), int(w), int(h), int(cid), kind, text))

out = ['# 色の設定 (comdlg32 の ChooseColor) で採点から外すところ。',
       '# docs/ref_colordlg.png の座標（窓まるごと %dx%d）。' % (W, H),
       '# tools/mkcdareas.py が書きます。',
       '',
       '# 窓の縁と見出し -- PrintWindow が黒く写すところ',
       '0 0 %d %d' % (W, C),
       '0 %d %d %d' % (C, B, H - C),
       '%d %d %d %d' % (W - B, C, B, H - C),
       '0 %d %d %d' % (H - B, W, B),
       '',
       '# Windows の字で描いてあるところ']
for x, y, w, h, cid, kind, text in rows:
    if kind == 'JW_CD_STATIC' and cid in (720, 721, 710, 702, 709):
        continue                        # 絵。ここは合っています
    if y + h > CH:
        continue                        # クライアントの外（部品 713）
    out.append('%d %d %d %d' % (B + x, C + y, w, h))
io.open(OUT, 'w', encoding='utf-8', newline='\n').write('\n'.join(out) + '\n')
print('%s: %d areas' % (OUT, len(out) - 11))
