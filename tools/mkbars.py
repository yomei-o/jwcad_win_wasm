#!/usr/bin/env python3
"""Generate src/gen/bars.h -- the command bar for each command.

The command bar across the top is a CDialogBar, so what is on it are
ordinary Windows controls, and their positions are whatever Windows worked
out from the dialog template and the dialog font.  Rather than guess at that
conversion, tmp/bars.ps1 asks the running original: it starts Jw_cad, sends
each command in turn, and walks the frame's child windows with
EnumChildWindows, writing down each control's class, id, style, text and
rectangle in the frame's own client coordinates.  Nothing is drawn or
captured -- the window is shown but never read back.

What comes out (decomp/res/bars.txt) is exact.  It reproduces every position
that had been measured off the reference screen by hand: the 矩形 checkbox at
x=18 y=11, the two comboboxes at 185 and 319, the 端部点 button at 517 y=5
h=24, and the rest.
"""
import os
import re

# decomp/res/bars.txt is every command's bar as it is entered; bars2.txt is
# the one a few of them put up once a range is settled, which tools/bars.ps1
# cannot reach.  Those come in headed `=== command 1<cmd>` -- the command
# with a 1 in front -- and go into the same table, so the port looks the
# second stage up by 100000 + the command.
# bars4.txt (the bar after each step) is captured but not baked in yet: what
# it holds is almost all enabled/disabled, which the port answers for itself
# in jw_cmd_bar_enabled, and putting it in would need a step counter that
# means the same thing as the capture's.  See docs/notes-commands.md.
# bars5.txt is 図形 (32862): its bar only exists once a figure has been
# read, so tools/bars.ps1's sweep (send a command, read the bar) never
# reached it.  tools/probe61.sh goes in through the file window instead.
# 貼り付け (57637) puts the same bar up, so 倍率 (1431) and 回転角 (1412)
# come with it.
SRC = ['decomp/res/bars.txt', 'decomp/res/bars2.txt',
       'decomp/res/bars3.txt', 'decomp/res/bars5.txt']
OUT = 'src/gen/bars.h'

# the windows that make up the frame itself, not the bar
SKIP = ('AfxFrameOrView', 'AfxControlBar', 'ToolbarWindow32', '#32770',
        'Edit')            # the edit inside a combobox, drawn with it

KIND = {'check': 0, 'button': 1, 'static': 2, 'combo': 3}


def esc(s):
    BS = chr(92)
    keep = '"' + BS + '?'
    out = []
    b = s.encode('cp932')
    for i, c in enumerate(b):
        if c > 0x7e or c < 0x20 or chr(c) in keep:
            out.append(BS + 'x%02x' % c)
            if i + 1 < len(b) and chr(b[i + 1]) in '0123456789abcdefABCDEF':
                out.append('" "')
        else:
            out.append(chr(c))
    return ''.join(out)


def kind_of(cls, style):
    if cls == 'ComboBox':
        return 'combo'
    if cls == 'Static':
        return 'static'
    if cls == 'Button':
        low = style & 0x0f
        if low == 3:            # BS_AUTOCHECKBOX
            return 'check'
        return 'button'         # BS_PUSHBUTTON, BS_DEFPUSHBUTTON, owner-draw
    return None


def read():
    bars, cur = [], None
    lines = []
    for p in SRC:
        if os.path.exists(p):
            lines += list(open(p, encoding='utf-8'))
    for line in lines:
        line = line.rstrip('\n')
        # `=== command <n>` is a command's own bar; `=== command 2<n>_<id>`
        # is the same bar with checkbox <id> ticked, which is a different set
        # of controls -- 矩形's ソリッド takes 多重 away and brings
        # (対角線)・任意色・the colour button.
        m = re.match(r'=== command (\d+)_(\d+)$', line)
        if m:
            tag, num = m.group(1), int(m.group(2))
            if tag.startswith('3'):
                # `3<cmd>_<step>`: the bar after that many points have gone
                # down.  A command is not one bar either -- 寸法 shows a
                # different row once the dimension line is placed.
                cur = (int(tag[1:]), 0, num, [])
            else:
                # `2<cmd>_<id>`: the bar with that checkbox ticked
                cur = (int(tag[1:]), num, 0, [])
            bars.append(cur)
            continue
        m = re.match(r'=== command (\d+)$', line)
        if m:
            cur = (int(m.group(1)), 0, 0, [])
            bars.append(cur)
            continue
        if cur is None or '|' not in line:
            continue
        cls, cid, x, y, w, h, style, chk, en, text = line.split('|', 9)
        if any(cls.startswith(s) for s in SKIP):
            continue
        k = kind_of(cls, int(style, 16))
        if k is None:
            continue
        cur[3].append((k, int(x), int(y), int(w), int(h),
                       (int(style, 16) & 0x0f) if cls == 'Static'
                       else 9 if (cls == 'Button'
                                  and (int(style, 16) & 0x0f) == 9) else 0,
                       int(chk), int(en), int(cid), text))
    return bars


def drop_the_same(bars):
    """A variant that came out the same as the command's own bar is not a
    variant at all -- most boxes only tick.  Keeping them would put 44 copies
    in the header for the two or three that matter."""
    def shape(ctls):
        # everything but the tick itself: a box that only ticks is not a
        # different bar, and the port keeps the ticks of its own accord
        return [(k, x, y, w, h, al, en, cid, text)
                for k, x, y, w, h, al, chk, en, cid, text in ctls]

    plain = {}
    for cmd, on, st, ctls in bars:
        if not on and not st:
            plain[cmd] = shape(ctls)
    out = []
    for cmd, on, st, ctls in bars:
        if (on or st) and plain.get(cmd) == shape(ctls):
            continue
        out.append((cmd, on, st, ctls))
    return out


def main():
    bars = drop_the_same(read())
    os.makedirs('src/gen', exist_ok=True)
    with open(OUT, 'w', encoding='ascii', newline='\n') as f:
        f.write('/* generated by tools/mkbars.py from decomp/res/bars.txt --\n'
                '   read out of the running original, see that script */\n')
        f.write('#ifndef JW_GEN_BARS_H\n#define JW_GEN_BARS_H\n\n')
        f.write('enum { JW_CTL_CHECK, JW_CTL_BUTTON, JW_CTL_STATIC,\n'
                '       JW_CTL_COMBO };\n\n')
        f.write('typedef struct {\n'
                '    short x, y, w, h;\n'
                '    unsigned short id;     /* the control id the original\n'
                '                              gives it -- what a press is\n'
                '                              dispatched on */\n'
                '    unsigned char kind;\n'
                '    unsigned char align;   /* a static\'s SS_ bits */\n'
                '    unsigned char checked; /* how the original has it when\n'
                '                              the command is entered */\n'
                '    unsigned char enabled;\n'
                '    const char *text;      /* CP932 */\n'
                '} jw_ctl_t;\n\n')
        for cmd, on, st, ctls in bars:
            f.write('static const jw_ctl_t jw_bar_%d%s%s[] = {\n'
                    % (cmd, '_%d' % on if on else '',
                       '_s%d' % st if st else ''))
            for k, x, y, w, h, al, chk, en, cid, text in ctls:
                f.write('    { %4d, %3d, %4d, %3d, %5d, JW_CTL_%-6s,'
                        ' %d, %d, %d, "%s" },\n'
                        % (x, y, w, h, cid, KIND_NAME[k], al, chk, en,
                           esc(text)))
            f.write('};\n\n')
        f.write('typedef struct {\n'
                '    unsigned int cmd;      /* 100000 + it for the bar the\n'
                '                              command puts up once a range\n'
                '                              is settled */\n'
                '    unsigned short on;     /* 0, or the checkbox that\n'
                '                              has to be ticked for this\n'
                '                              to be the bar -- a command\n'
                '                              bar is not one fixed row */\n'
                '    unsigned char step;    /* 0, or how many points have\n'
                '                              gone down for this to be the\n'
                '                              bar */\n'
                '    unsigned short n;\n'
                '    const jw_ctl_t *c;\n'
                '} jw_bar_t;\n\n')
        f.write('static const jw_bar_t jw_bars[] = {\n')
        for cmd, on, st, ctls in bars:
            f.write('    { %6d, %4d, %d, %2d, jw_bar_%d%s%s },\n'
                    % (cmd, on, st, len(ctls), cmd,
                       '_%d' % on if on else '', '_s%d' % st if st else ''))
        f.write('};\n#define JW_NBARS %d\n\n' % len(bars))
        f.write('#endif\n')
    print('%s: %d bars, %d controls'
          % (OUT, len(bars), sum(len(c) for _, _, _, c in bars)))


KIND_NAME = {'check': 'CHECK', 'button': 'BUTTON', 'static': 'STATIC',
             'combo': 'COMBO'}

if __name__ == '__main__':
    main()
