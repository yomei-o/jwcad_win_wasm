"""Sort the decompiled C into one file per class.

Ghidra hands back 26,061 functions named FUN_<address> in ten shards.  The
vtables recovered by tools/rtti.py say which class each virtual function
belongs to, and the call graph says nothing yet, so this does the part that is
certain: every function that appears in a vtable goes to that class's file,
with its slot number, and the rest goes to unassigned.c.

    python tools/byclass.py decomp/decomp decomp/rtti/vftables.csv decomp/byclass
"""
import collections
import csv
import os
import re
import sys


def load_vftables(path):
    """func address -> [(class, slot), ...]"""
    owner = collections.defaultdict(list)
    with open(path, encoding='utf-8') as f:
        for r in csv.DictReader(f):
            owner[int(r['func'], 16)].append((r['class'], int(r['slot'])))
    return owner


HEAD = re.compile(r'^/\* ([0-9a-f]{8})  (\S+)  (\d+) bytes, (\d+) callers \*/$')


def functions(cdir):
    """Walk the shard files and yield (address, name, header, body)."""
    for fn in sorted(os.listdir(cdir)):
        if not (fn.startswith('all_') and fn.endswith('.c')):
            continue
        cur = None
        buf = []
        with open(os.path.join(cdir, fn), encoding='utf-8',
                  errors='replace') as f:
            for line in f:
                m = HEAD.match(line.rstrip('\n'))
                if m:
                    if cur:
                        yield cur + (''.join(buf),)
                    cur = (int(m.group(1), 16), m.group(2), line)
                    buf = []
                elif cur:
                    buf.append(line)
        if cur:
            yield cur + (''.join(buf),)


def safe(name):
    return re.sub(r'[^A-Za-z0-9_]', '_', name)


def main():
    cdir, vft, outdir = sys.argv[1], sys.argv[2], sys.argv[3]
    owner = load_vftables(vft)
    os.makedirs(outdir, exist_ok=True)

    files = {}
    count = collections.Counter()
    bytes_ = collections.Counter()
    total = 0
    for addr, name, head, body in functions(cdir):
        total += 1
        slots = owner.get(addr)
        cls = slots[0][0] if slots else '_unassigned'
        f = files.get(cls)
        if f is None:
            f = files[cls] = open('%s/%s.c' % (outdir, safe(cls)), 'w',
                                  encoding='utf-8')
            f.write('/* %s -- Ghidra decompilation, machine output.\n'
                    '   Slot numbers come from the class vtable in .rdata. */\n'
                    % cls)
        if slots:
            f.write('\n/* vtable slots: %s */\n'
                    % ', '.join('%s[%d]' % s for s in slots))
        f.write(head)
        f.write(body)
        count[cls] += 1
        m = HEAD.match(head.rstrip('\n'))
        bytes_[cls] += int(m.group(3)) if m else 0
    for f in files.values():
        f.close()

    print('%d functions -> %d files' % (total, len(files)))
    print('%-34s %6s %10s' % ('class', 'funcs', 'bytes'))
    for cls, n in count.most_common(30):
        print('%-34s %6d %10d' % (cls[:34], n, bytes_[cls]))


if __name__ == '__main__':
    main()
