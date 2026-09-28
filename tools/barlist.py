#!/usr/bin/env python3
"""Print a command bar's controls the way a person can read them.

    python tools/barlist.py 32771 32772 32773

src/gen/bars.h keeps the labels as CP932 byte escapes, which is what the C
wants and no use to anyone reading.  This turns them back into text, so the
bars can be gone through control by control when working out what the port
still has to answer to.
"""
import re
import sys

BARS = 'src/gen/bars.h'
BS = chr(92)


def dec(txt):
    """the C string literal in bars.h, back to text"""
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


def names():
    out = {}
    src = open('src/gen/cmds.h', 'rb').read().decode('utf-8', 'replace')
    for line in src.splitlines():
        m = re.match(r'\s*(\d+),\s*/\* (.*?) \*/', line)
        if m:
            out.setdefault(int(m.group(1)), m.group(2))
    return out


def main():
    lines = open(BARS, 'rb').read().decode('latin-1').splitlines()
    nm = names()
    for bar in sys.argv[1:]:
        at = [k for k, l in enumerate(lines)
              if l.startswith('static const jw_ctl_t jw_bar_%s[]' % bar)]
        if not at:
            print('=== %s: no bar captured' % bar)
            continue
        print('=== %s %s' % (bar, nm.get(int(bar), '')))
        for l in lines[at[0] + 1:]:
            if l.startswith('};'):
                break
            m = re.match(r'\s*\{\s*(-?\d+),\s*(-?\d+),\s*(-?\d+),\s*(-?\d+),'
                         r'\s*(-?\d+),\s*(JW_CTL_\w+)\s*,\s*\d+,\s*\d+,\s*\d+,'
                         r'\s*"(.*)"\s*\},', l)
            if not m:
                continue
            print('  id=%-6s %-11s %s'
                  % (m.group(5), m.group(6).strip().replace('JW_CTL_', ''),
                     dec(m.group(7))))


main()
