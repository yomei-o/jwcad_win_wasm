"""src/gen/colordlg.h —— 色の設定（ChooseColor）の窓を**資源から**起こす。

    python tools/mkcolordlg.py

原典の 基本設定（32891）の 色・画面 の 色１ が出す窓です。**これは
Jw_cad 自身の窓ではなく Windows の共通ダイアログ**（comdlg32 の
ChooseColor、CC_FULLOPEN 付き）なので、雛形は Jw_win.exe ではなく
comdlg32.dll.mui が持っています:

    decomp/res/comdlg32.txt   その DIALOG 資源（tools/rsrc.py で読んだもの）

単位から画素への直しは Windows 自身の MapDialogRect と同じ足し算で、
`tools/mkdlgtpl.py` が Jw_win.exe の窓にしているのと同じです:

    x px = MulDiv(x, base_x, 4)      y px = MulDiv(y, base_y, 8)

**Yu Gothic UI 9 の基準は 7 と 15** —— これは当てずっぽうではなく、
原典にその窓を出させて撮った控えから決まります。その基準で直した
画素が、控えの**全部品と一致する**ことをこの道具が毎回確かめていて、
一つでも違えば止まります:

    decomp/res/colordlg.txt   EnumChildWindows の控え（tools/gen.sh）
    docs/ref_colordlg.png     その窓を PrintWindow で撮ったもの

升目の寸法と、基本色 48・作成した色 16 は資源に入っていません
（comdlg32 の中の表です）。そこだけ、撮った絵から数えています。
"""
import io
import re
import sys

from PIL import Image

TPL = 'decomp/res/comdlg32.txt'
DUMP = 'decomp/res/colordlg.txt'
SHOT = 'docs/ref_colordlg.png'
OUT = 'src/gen/colordlg.h'

BASE_X, BASE_Y = 7, 15                  # Yu Gothic UI 9、控えで確かめた値
BORDER, CAPTION = 8, 31                 # 捕った窓がそうなっている

WS_DISABLED = 0x08000000
BS_MASK = 0x0000000f


def muldiv(a, b, c):
    """Windows の MulDiv。四捨五入で、半分はゼロから遠いほうへ。"""
    v = a * b
    return (v + c // 2) // c if v >= 0 else -((-v + c // 2) // c)


def esc(s):
    """CP932 のバイト列を C の文字列に。"""
    out = []
    for b in s.encode('cp932'):
        if 32 <= b < 127 and chr(b) not in '"\\?':
            out.append(chr(b))
        else:
            out.append('\\x%02x' % b)
    t = ''.join(out)
    return re.sub(r'(\\x[0-9a-f]{2})([0-9a-fA-F])', r'\1" "\2', t)


def read_template():
    """CHOOSECOLOR の雛形を、単位のまま読む。"""
    lines = io.open(TPL, encoding='utf-8').read().split('\n')
    i = next(k for k, t in enumerate(lines) if t.startswith('=== DIALOG CHOOSECOLOR'))
    m = re.match(r'DIALOGEX (\d+), (\d+), (\d+), (\d+)', lines[i + 1].strip())
    if not m:
        sys.exit('no DIALOGEX line after ' + lines[i])
    du_w, du_h = int(m.group(3)), int(m.group(4))
    cap = re.match(r'CAPTION "(.*)"', lines[i + 2].strip())
    out = []
    for t in lines[i + 3:]:
        if t.startswith('==='):
            break
        c = re.match(r'\s*CONTROL (\w+)\s+id=(\d+)\s+(-?\d+),\s*(-?\d+),'
                     r'\s*(-?\d+),\s*(-?\d+)\s+style=0x([0-9a-f]+)\s+"(.*)"$',
                     t)
        if c:
            out.append(dict(cls=c.group(1), id=int(c.group(2)) & 0xffff,
                            x=int(c.group(3)), y=int(c.group(4)),
                            w=int(c.group(5)), h=int(c.group(6)),
                            style=int(c.group(7), 16), text=c.group(8)))
    return du_w, du_h, cap.group(1) if cap else '', out


def read_dump():
    """原典に出させた窓の控え。画素で入っています。"""
    rows = {}
    head = None
    for line in io.open(DUMP, encoding='utf-8'):
        line = line.rstrip('\n')
        if line.startswith('==='):
            head = head or line
            continue
        f = line.split('|')
        if len(f) >= 10:
            rows.setdefault(int(f[1]), []).append(
                (int(f[2]), int(f[3]), int(f[4]), int(f[5]), int(f[8])))
    m = re.search(r'window (\d+)x(\d+) client (\d+)x(\d+)', head or '')
    if not m:
        sys.exit('cannot read the size out of ' + DUMP)
    return tuple(int(x) for x in m.groups()), rows


def main():
    du_w, du_h, caption, tpl = read_template()
    (ww, wh, cw, ch), dump = read_dump()

    # 単位から画素へ。まず窓そのもの
    want_cw = muldiv(du_w, BASE_X, 4)
    want_ch = muldiv(du_h, BASE_Y, 8)
    if (want_cw, want_ch) != (cw, ch):
        sys.exit('the template lays out %dx%d but the original showed %dx%d'
                 % (want_cw, want_ch, cw, ch))
    if (ww, wh) != (cw + 2 * BORDER, ch + CAPTION + BORDER):
        sys.exit('window %dx%d does not fit client %dx%d with a %d border'
                 % (ww, wh, cw, ch, BORDER))

    rows = []
    bad = 0
    for c in tpl:
        x = muldiv(c['x'], BASE_X, 4)
        y = muldiv(c['y'], BASE_Y, 8)
        w = muldiv(c['w'], BASE_X, 4)
        h = muldiv(c['h'], BASE_Y, 8)
        # 使えるかどうかは**資源ではなく走っている窓**から取ります。
        # CC_FULLOPEN で開くと comdlg32 自身が 色の作成 (719) を殺し、
        # ヘルプ (1038) も Jw_cad が渡す旗で消えます。資源の style だけ
        # 見ていると、原典が灰色で出すものを黒で描いてしまいます。
        en = 0 if (c['style'] & WS_DISABLED) else 1
        kind = {'BUTTON': 'JW_CD_PUSH', 'STATIC': 'JW_CD_STATIC',
                'EDIT': 'JW_CD_EDIT'}[c['cls']]
        # 控えと突き合わせる（同じ id が二つある静的部品は、位置で選ぶ）
        seen = dump.get(c['id'], [])
        hit = [s for s in seen if (s[0], s[1], s[2], s[3]) == (x, y, w, h)]
        if hit:
            en = hit[0][4]
        if seen and not hit:
            print('  id %5d: template %4d,%4d %3dx%3d, the original showed %s'
                  % (c['id'], x, y, w, h, seen))
            bad += 1
        rows.append((kind, c['id'], x, y, w, h, en, c['text']))
    if bad:
        sys.exit('%d controls do not match %s -- the base units are wrong'
                 % (bad, DUMP))

    im = Image.open(SHOT).convert('RGB')
    if im.size != (ww, wh):
        sys.exit('%s is %dx%d, the dump says %dx%d'
                 % ((SHOT,) + im.size + (ww, wh)))

    # 升目は 基本色 の静的部品 (id 720) の中。画像から数えた寸法 --
    # 一つの升は 23x20 で、縁は mj_sunken とまったく同じ四色
    # (a0a0a0 / 696969 を内へ、e3e3e3 / ffffff を外へ)、中身は 19x16。
    # 枠の左上から最初の升まで 4,3、升の間隔は 30,25。
    basic = next(r for r in rows if r[1] == 720)
    cust = next(r for r in rows if r[1] == 721)
    MEASURED = dict(x0=4, y0=3, cw=23, chh=20, px=30, py=25)
    cols, brows, crows = 8, 6, 2

    def cell(host, c, r):
        x = BORDER + host[2] + MEASURED['x0'] + c * MEASURED['px']
        y = CAPTION + host[3] + MEASURED['y0'] + r * MEASURED['py']
        return im.getpixel((x + MEASURED['cw'] // 2,
                            y + MEASURED['chh'] // 2))

    basics = [cell(basic, c, r) for r in range(brows) for c in range(cols)]
    custs = [cell(cust, c, r) for r in range(crows) for c in range(cols)]

    o = []
    w = o.append
    w('/* generated by tools/mkcolordlg.py from %s' % TPL)
    w('   -- the Windows common colour dialog\'s own DIALOG resource, laid')
    w('   out with MapDialogRect (base units %d and %d), and checked'
      % (BASE_X, BASE_Y))
    w('   against %s, which is the window the original put up. */' % DUMP)
    w('#ifndef JW_GEN_COLORDLG_H')
    w('#define JW_GEN_COLORDLG_H')
    w('')
    w('#define JW_CD_W   %d' % ww)
    w('#define JW_CD_H   %d' % wh)
    w('#define JW_CD_CW  %d' % cw)
    w('#define JW_CD_CH  %d' % ch)
    w('#define JW_CD_BORDER %d' % BORDER)
    w('#define JW_CD_CAPTION %d' % CAPTION)
    w('#define JW_CD_TITLE "%s"' % esc(caption))
    w('')
    w('/* 升目。絵から数えたもの: 枠の左上から最初の升まで %d,%d、'
      % (MEASURED['x0'], MEASURED['y0']))
    w('   升は %dx%d（縁二重で中身 %dx%d）、間隔 %d,%d */'
      % (MEASURED['cw'], MEASURED['chh'], MEASURED['cw'] - 4,
         MEASURED['chh'] - 4, MEASURED['px'], MEASURED['py']))
    w('#define JW_CD_CHH %d' % MEASURED['chh'])
    w('#define JW_CD_CELLW %d' % MEASURED['cw'])
    w('#define JW_CD_PX %d' % MEASURED['px'])
    w('#define JW_CD_PY %d' % MEASURED['py'])
    w('#define JW_CD_X0 %d' % MEASURED['x0'])
    w('#define JW_CD_Y0 %d' % MEASURED['y0'])
    w('#define JW_CD_COLS %d' % cols)
    w('#define JW_CD_BROWS %d' % brows)
    w('#define JW_CD_CROWS %d' % crows)
    w('')
    w('/* 虹の升と明るさの帯。どちらも段で塗ってあり、段の数も刻みも')
    w('   原典に出させた絵から当てました（色相 60 段・彩度 30 段で')
    w('   中身 205x216 を塗ると、印の十字 35 画素を除いて一致）。')
    w('   明るさの帯は 31 段。明るさ→色は Windows の HLS です。 */')
    w('#define JW_CD_NHUE  60         /* 色相 0,4,8,… 236 */')
    w('#define JW_CD_HSTEP 4')
    w('#define JW_CD_NSAT  30         /* 彩度 239,231,… 7 */')
    w('#define JW_CD_SAT0  239')
    w('#define JW_CD_SSTEP 8')
    w('#define JW_CD_NLUM  31         /* 明るさ 240,232,… 0 */')
    w('#define JW_CD_LUM0  240')
    w('#define JW_CD_LSTEP 8')
    w('#define JW_CD_RAINBOW_L 120    /* 虹の升はこの明るさで塗る */')
    w('')
    w('enum { JW_CD_PUSH, JW_CD_STATIC, JW_CD_EDIT };')
    w('')
    w('typedef struct {')
    w('    short x, y, w, h;      /* the dialog\'s client area */')
    w('    short id;')
    w('    unsigned char kind;')
    w('    unsigned char enabled;')
    w('    const char *text;      /* CP932 */')
    w('} jw_cd_t;')
    w('')
    w('static const jw_cd_t jw_colordlg[] = {')
    for kind, cid, x, y, cwid, chei, en, text in rows:
        w('    { %4d, %4d, %4d, %3d, %5d, %-13s, %d, "%s" },'
          % (x, y, cwid, chei, cid, kind, en, esc(text)))
    w('};')
    w('#define JW_NCOLORDLG (int)(sizeof jw_colordlg / sizeof jw_colordlg[0])')
    w('')
    w('/* 基本色 の 48。原典に出させた窓の升の真ん中を読んだものです */')
    w('static const unsigned int jw_cd_basic[%d] = {' % len(basics))
    for i in range(0, len(basics), 4):
        w('    ' + ' '.join('0x%02x%02x%02xu,' % c for c in basics[i:i + 4]))
    w('};')
    w('')
    w('/* 作成した色 の 16。Jw_cad が ChooseColor に渡してくる控えで、')
    w('   撮ったときの中身です */')
    w('static const unsigned int jw_cd_custom[%d] = {' % len(custs))
    for i in range(0, len(custs), 4):
        w('    ' + ' '.join('0x%02x%02x%02xu,' % c for c in custs[i:i + 4]))
    w('};')
    w('')
    w('#endif')
    io.open(OUT, 'w', encoding='utf-8', newline='\n').write('\n'.join(o) + '\n')
    print('%s: %d controls from the resource, all matching %s'
          % (OUT, len(rows), DUMP))


main()
