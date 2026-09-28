#!/usr/bin/env python3
"""Which controls of each command bar src/cmd.c names, bar by bar.

This is a reading of the source, not a measurement: tests/barprobe_test.exe
presses every control and says which of them change what gets drawn, and that
is the number to go by.  What this is good for is looking at one bar and
seeing which of its controls the port has anything to say about at all.


    python tools/barcover.py [--all]

Every command puts up a bar of its own, and Jw_cad is operated through those
boxes and checkboxes as much as through the drawing area: a rectangle 1000 mm
across is typed into 寸法, not dragged.  This walks src/gen/bars.h (which is
read out of the running original) and marks each control by whether src/cmd.c
mentions its id for that command:

    box   a number the port gives a starting value to
    chk   a checkbox whose id src/cmd.c names
    btn   a button whose id src/cmd.c names
    --    not named there at all

It is a rough measure -- it looks for the id near the command's name -- but
it is honest about the shape of what is left.
"""
import re
import sys

BARS = 'src/gen/bars.h'
CMD = 'src/cmd.c'
CMDS = 'src/gen/cmds.h'

KIND = {'JW_CTL_CHECK': 'check', 'JW_CTL_BUTTON': 'button',
        'JW_CTL_STATIC': 'static', 'JW_CTL_COMBO': 'combo'}


BS = chr(92)


def dec(txt):
    """the C string literal in bars.h, back to readable text"""
    # mkbars.py splits the literal wherever a CP932 trailing byte would
    # otherwise eat the escape -- "..." "bh" is one string in C, so
    # the break between the two halves is not part of the text
    txt = txt.replace('" "', '')
    out = bytearray()
    i = 0
    while i < len(txt):
        if txt[i] == BS and i + 1 < len(txt) and txt[i + 1] == 'x':
            out.append(int(txt[i + 2:i + 4], 16))
            i += 4
        elif txt[i] == '"':
            i += 1
        else:
            out.append(ord(txt[i]))
            i += 1
    try:
        return out.decode('cp932')
    except UnicodeDecodeError:
        return txt


def bars():
    """{command id: [(ctl id, kind, label), ...]}"""
    out, cur = {}, None
    src = open(BARS, 'rb').read().decode('latin-1')
    for line in src.splitlines():
        m = re.match(r'static const jw_ctl_t jw_bar_(\d+)\[\]', line)
        if m:
            cur = int(m.group(1))
            out[cur] = []
            continue
        m = re.match(r'\s*\{\s*-?\d+,\s*-?\d+,\s*-?\d+,\s*-?\d+,\s*(-?\d+),'
                     r'\s*(JW_CTL_\w+)\s*,[^"]*"(.*)"\s*\},', line)
        if m and cur is not None:
            out[cur].append((int(m.group(1)), KIND[m.group(2).strip()],
                             dec(m.group(3))))
    return out


def names():
    """{command id: its name, from the toolbar table}"""
    out = {}
    src = open(CMDS, 'rb').read().decode('utf-8', 'replace')
    for line in src.splitlines():
        m = re.match(r'\s*(\d+),\s*/\* (.*?) \*/', line)
        if m:
            out.setdefault(int(m.group(1)), m.group(2))
    return out


def main():
    show_all = '--all' in sys.argv
    cmd = open(CMD, encoding='utf-8', errors='replace').read()
    boxes = set()
    m = re.search(r'} box\[\] = \{(.*?)\n\};', cmd, re.S)
    for line in m.group(1).splitlines():
        b = re.match(r'\s*\{\s*(\w+),\s*(\d+),', line)
        if b:
            boxes.add((b.group(1), int(b.group(2))))
    nm = names()
    total = done = 0
    for c, ctls in sorted(bars().items()):
        rows, n, k = [], 0, 0
        for cid, kind, label in ctls:
            if kind == 'static':
                continue
            n += 1
            # the port answers to an id when cmd.c names it; the box table is
            # keyed by command as well, so that one is exact
            hit = ''
            if kind == 'combo':
                for cmdname, bid in boxes:
                    if bid == cid:
                        hit = 'box'
            if not hit and re.search(r'\b%d\b' % cid, cmd):
                hit = {'check': 'chk', 'button': 'btn'}.get(kind, 'yes')
            if hit:
                k += 1
            rows.append('    %-6s %-6s %-4s %s'
                        % (cid, kind, hit or '--', label))
        total += n
        done += k
        if n and (show_all or k < n):
            print('=== %s  %s  (%d/%d)' % (c, nm.get(c, ''), k, n))
            for r in rows:
                print(r)
    print()
    print('%d of %d controls are named somewhere in src/cmd.c' % (done, total))
    print('(what they actually do: tests/barprobe_test.exe --list)')


main()
