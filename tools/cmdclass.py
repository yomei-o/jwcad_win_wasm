"""Which class each command runs.

    python tools/cmdclass.py

FUN_004fdc40 is the switch the view runs when a command is entered.  Each arm
constructs that command's object and parks it at view+0x8590:

    case 0x8005:
        ...
        local_e40c = FUN_00646230(local_e270);
        *(undefined4 *)(local_e270 + 0x8590) = local_e40c;

and the constructor's first job is to store its vftable, which Ghidra has
already named.  Following those two links turns the switch into a table of
"this icon runs that class", with nothing guessed.
"""
import re
import subprocess
import sys

SRC = 'tmp/f4fdc40.c'


def switch_arms(text):
    """command id -> the constructor addresses its arm calls"""
    out = {}
    cur = None
    for line in text.split('\n'):
        m = re.search(r'case (0x[0-9a-f]+):', line)
        if m:
            cur = int(m.group(1), 16)
            out.setdefault(cur, [])
            continue
        if cur is None:
            continue
        for f in re.findall(r'= FUN_([0-9a-f]{8})\(', line):
            out[cur].append(f)
    return out


def class_of(addr, cache={}):
    if addr in cache:
        return cache[addr]
    try:
        body = subprocess.run([sys.executable, 'tools/func.py', addr],
                              capture_output=True, text=True).stdout
    except Exception:
        body = ''
    m = re.search(r'= (\w+)::vftable', body)
    cache[addr] = m.group(1) if m else ''
    return cache[addr]


def main():
    text = open(SRC, encoding='utf-8', errors='replace').read()
    arms = switch_arms(text)
    names = {}
    for line in open('decomp/res/string.txt', encoding='utf-8'):
        m = re.match(r'\s*(\d+) 0x[0-9a-f]+  (.*)$', line)
        if m:
            names.setdefault(int(m.group(1)), m.group(2))
    rows = []
    for cmd in sorted(arms):
        if not (0x8000 <= cmd <= 0x80ff):
            continue
        cls = ''
        for a in arms[cmd]:
            c = class_of(a)
            if c.startswith('CZukei'):
                cls = c
                break
        if cls:
            rows.append((cmd, cls, names.get(cmd, '')))
    for cmd, cls, name in rows:
        print('0x%04x  %-24s %s' % (cmd, cls, name))
    print('%d commands with a class' % len(rows))


main()
