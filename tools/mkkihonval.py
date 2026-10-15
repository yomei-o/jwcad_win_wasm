#!/usr/bin/env python3
"""Generate src/gen/kihonval.h -- what the 基本設定 dialog's boxes hold.

    python tools/mkkihonval.py

src/gen/kihon.h (tools/mkkihon.py) has the dialog's controls but not what
is written in the edit boxes and drop lists.  This is that: for each box
of each tab, the text the original shows on a fresh start, and whether
the box centres it (ES_CENTER, the style's low bit in decomp/res/kihon.txt).

Where the text comes from:

  * most of it is the original's own settings, HKCU\\Software\\Jw_cad\\jw_win
    as tools/refenv.reg saved it -- the key is named beside each one below.
    Each was checked against docs/ref_kihon1.png .. 8.png, the dialog as
    the original painted it on that start;
  * a few are not in the registry and are taken from those pictures
    ('pic'), with the reason;
  * the screen and printer pens of 色・画面 and the ten text sizes of 文字
    are the drawing's own, so they are not here -- src/app.c (kh_live)
    reads and writes them (and the box only gets its alignment from here).

Boxes are named by tab, id and which one of that id it is in the tab
(the line pattern boxes are all 1001, the edit inside each combo).
"""
import io

REG = 'tools/refenv.reg'
SRC = 'decomp/res/kihon.txt'
OUT = 'src/gen/kihonval.h'


def reg():
    out, cur = {}, None
    for line in io.open(REG, encoding='utf-16', errors='replace'):
        line = line.strip()
        if line.startswith('['):
            cur = line.strip('[]').split(chr(92))[-1]
            out.setdefault(cur, {})
        elif cur and '=' in line:
            k, v = line.split('=', 1)
            v = v.strip()
            if v.startswith('dword:'):
                n = int(v[6:], 16)
                if n >= 0x80000000:
                    n -= 1 << 32
                v = n
            else:
                v = v.strip('"')
            out[cur][k.strip('"')] = v
    return out


def boxes():
    """(tab, id, nth, style) of every Edit and ComboBox, in the order
    tools/mkkihon.py puts them in src/gen/kihon.h"""
    tabs, sec = [], None
    for line in io.open(SRC, encoding='utf-8'):
        line = line.rstrip('\n')
        if line.startswith('=== dialog'):
            sec = []
            tabs.append(sec)
            continue
        if sec is None or '|' not in line:
            continue
        sec.append(line.split('|', 9))
    out = []
    t = 0
    for sec in tabs:
        at = [i for i, r in enumerate(sec) if r[0] == '#32770']
        if not at:
            continue
        end = at[1] if len(at) > 1 else len(sec)
        seen = {}
        for r in sec[at[0] + 1:end]:
            if r[0] not in ('Edit', 'ComboBox'):
                continue
            cid = int(r[1])
            nth = seen.get(cid, 0)
            seen[cid] = nth + 1
            out.append((t, cid, nth, int(r[6], 16)))
        t += 1
    return out


def pattern(hexbits, on, off):
    """a line type as the 線種 tab writes it: 32 characters, the top bit
    first (docs/ref_kihon4.png: ランダム線 ccb2b32a starts '' ,, '' ,,)"""
    v = int(hexbits, 16)
    return ''.join(on if v & (1 << (31 - i)) else off for i in range(32))


def values(R):
    V = {}

    def r(tab, cid, sec, key, nth=0):
        V[(tab, cid, nth)] = str(R[sec][key])

    def lit(tab, cid, text, nth=0):
        V[(tab, cid, nth)] = text

    # ---- 一般(1)
    # 外部エディタ: Tool\GAIBUEditor is empty and the page puts the
    # system's notepad in its place (pic)
    lit(0, 1052, 'C:\\WINDOWS\\NOTEPAD.EXE')
    r(0, 1788, 'Screen', 'SizeX')                 # 画面横寸法 246
    # 画面横ドット数: the width of the screen the original ran on (pic);
    # the port has no screen of its own size to show
    lit(0, 1490, '1920')
    r(0, 1049, 'AutoSave', 'Time')                # オートセーブ 30
    r(0, 1055, 'AutoSave', 'Back')                # バックアップ 1
    r(0, 1934, 'Undo', 'MaxCount')                # Undo 100
    r(0, 1054, 'Drag', 'Minimum')                 # クロックメニュー移行 35
    r(0, 1058, 'MOJI', 'FrameDotMax')             # 文字と枠の切替ドット 6
    r(0, 1053, 'MOJI', 'Extra')                   # 文字フォント表示倍率 1
    # ---- 一般(2)
    r(1, 1957, 'AutoMode', 'Change')              # AUTO クロック切替 900
    r(1, 1951, 'Zoom', 'KeyM')                    # 移動率 0.5
    r(1, 1952, 'Zoom', 'KeyZ')                    # 拡大縮小率 1.5
    r(1, 1954, 'Zoom', 'ShiftLSlideBorder')       # 切替移動量 3
    r(1, 1946, 'Zoom', 'LR_0')                    # 両ボタン 上（縮小）
    r(1, 1947, 'Zoom', 'LR_3')                    #          右
    r(1, 1948, 'Zoom', 'LR_6')                    #          下（前倍率）
    r(1, 1949, 'Zoom', 'LR_9')                    #          左
    r(1, 1950, 'Zoom', 'Move')                    # [移動] の範囲 10
    r(1, 1953, 'Zoom', 'Jump')                    # マークジャンプ 900
    # 1958 作図時間 (0 : 36 in the picture) is the time since the drawing
    # was opened; the port does not keep it, so it is left empty
    # ---- 色・画面: the pens are the drawing's (src/app.c); the rest
    for k in range(8):                            # 点半径 Point1..8
        r(2, 2533 + k, 'Point', 'Point%d' % (k + 1))
    r(2, 1057, 'Line', 'MaxWidth')                # 線描画の最大幅 100
    # ズーム枠色: Pen\ColorZl, a COLORREF (0x00bbggrr) -- 128 128 128
    zl = int(R['Pen']['ColorZl'], 16)
    for k in range(3):
        lit(2, 2483 + k, str((zl >> (8 * k)) & 255))
    lit(2, 2223, '丸')                            # 端点の形状 (pic)
    # ---- 線種: Line\Type_01..09 and _11..15, Unit, Pitch, PrPit, RandW, PrRnd
    for k in range(9):
        lit(3, 1001, pattern(R['Line']['Type_%02d' % (k + 1)], '-', ' '), k)
        r(3, 1776 + k, 'Line', 'Unit_%02d' % (k + 1))
        r(3, 1651 + k, 'Line', 'Pitch%02d' % (k + 1))
        r(3, 1665 + k, 'Line', 'PrPit%02d' % (k + 1))
    for k in range(5):
        lit(3, 1001, pattern(R['Line']['Type_%02d' % (k + 11)], "'", ','),
            9 + k)
        r(3, 2495 + k, 'Line', 'RandW%02d' % (k + 11))
        r(3, 1660 + k, 'Line', 'Pitch%02d' % (k + 11))
        r(3, 1681 + k, 'Line', 'PrRnd%02d' % (k + 11))
        r(3, 1674 + k, 'Line', 'PrPit%02d' % (k + 11))
    r(3, 1679, 'Line', 'SelectFrame')             # 範囲選択枠の線種 1
    r(3, 1680, 'Line', 'CrossLine')               # クロスライン 1
    # ---- 文字: the sizes are the drawing's (src/app.c)
    axis = {1: 'X', 2: 'Y', 3: 'XY'}
    for k, key in enumerate(('ShiftKey', 'CtrlKey', 'AltKey')):
        lit(4, 1001, axis[R['MOJI'][key]], k)
    # 日影用の文字種 2 and 範囲増寸法 0 are not under MOJI (pic)
    lit(4, 1562, '2')
    lit(4, 1563, '0')
    # ---- AUTO: AutoMode\LD_AMn, LD_PMn, RD_AMn, RD_PMn, the clock's hours
    r(5, 2404, 'AutoMode', 'SearchRatio')         # サーチ倍率 0.8
    hours = '0123456789AB'
    for cid, h in zip(range(2364, 2369), (0, 1, 2, 3, 4)):
        r(5, cid, 'AutoMode', 'LD_AM%s' % hours[h])
    for cid, h in zip(range(2369, 2374), (7, 8, 9, 10, 11)):
        r(5, cid, 'AutoMode', 'LD_AM%s' % hours[h])
    for k in range(12):
        r(5, 2374 + k, 'AutoMode', 'LD_PM%s' % hours[k])
        r(5, 2386 + k, 'AutoMode', 'RD_PM%s' % hours[k])
    for cid, h in zip(range(2398, 2404), (1, 2, 7, 8, 10, 11)):
        r(5, cid, 'AutoMode', 'RD_AM%s' % hours[h])
    # ---- KEY: KeyCom\A..Z, S_A..S_Z, F2..F9, SF2..SF9, SP
    keys = [chr(ord('A') + k) for k in range(26)]
    for k, ch in enumerate(keys):
        r(6, 2004 + k, 'KeyCom', ch)
    shift = list(range(2038, 2064)) + list(range(2065, 2073))
    for k, ch in enumerate(keys):
        r(6, shift[k], 'KeyCom', 'S_' + ch)
    for k in range(8):
        r(6, 2030 + k, 'KeyCom', 'F%d' % (k + 2))
        r(6, shift[26 + k], 'KeyCom', 'SF%d' % (k + 2))
    r(6, 2064, 'KeyCom', 'SP')                    # スペース 76
    # ---- DXF・SXF・JWC: SXF\...
    r(7, 2443, 'SXF', 'PenWidthTolerance')        # 線幅 15
    r(7, 2442, 'SXF', 'RGBTolerance')             # RGB 5
    r(7, 2441, 'SXF', 'LyneTypeTolerance')        # 線種要素長 5
    names = {1: 'continuous', 2: 'dashed', 3: 'dashed spaced', 7: 'dotted',
             8: 'chain', 9: 'chain double dash', 10: 'dashed dotted',
             12: 'dashed double-dotted'}            # the SXF names (pic)
    for k, n in enumerate(R['SXF']['WriteLType'].split(',')):
        lit(7, 2322 + k, n)
        lit(7, 2314 + k, names.get(int(n), ''))
    return V


def esc(s):
    b = s.encode('cp932')
    out = ''
    for c in b:
        if c == 0x5c:
            out += '\\\\'
        elif c == 0x22:
            out += '\\"'
        elif 0x20 <= c < 0x7f:
            out += chr(c)
        else:
            out += '\\x%02x""' % c
    return out


def main():
    R = reg()
    V = values(R)
    rows = []
    used = set()
    for t, cid, nth, style in boxes():
        v = V.get((t, cid, nth))
        if v is not None:
            used.add((t, cid, nth))
        rows.append((t, cid, nth, style & 1, v))
    left = set(V) - used
    if left:
        raise SystemExit('no such box: %r' % sorted(left))
    with io.open(OUT, 'w', encoding='ascii', newline='\n') as o:
        o.write('/* generated by tools/mkkihonval.py from tools/refenv.reg and\n'
                '   decomp/res/kihon.txt -- see that script */\n')
        o.write('#ifndef JW_GEN_KIHONVAL_H\n#define JW_GEN_KIHONVAL_H\n\n')
        o.write('typedef struct {\n'
                '    unsigned char tab;\n'
                '    short id;\n'
                '    unsigned char nth;     /* which one of that id in the tab */\n'
                '    unsigned char center;  /* ES_CENTER */\n'
                '    const char *text;      /* CP932, 0 = not known here */\n'
                '} jw_khv_t;\n\n')
        o.write('static const jw_khv_t jw_kihonval[] = {\n')
        for t, cid, nth, c, v in rows:
            o.write('    { %d, %5d, %2d, %d, %s },\n'
                    % (t, cid, nth, c, '"%s"' % esc(v) if v is not None else '0'))
        o.write('};\n#define JW_NKIHONVAL %d\n\n#endif\n' % len(rows))
    print('wrote', OUT, len(rows), 'boxes,', len(V), 'with text')


main()
