"""Recover the class layout from MSVC RTTI.

Jw_cad is C++ built with RTTI on, so .rdata still carries a type descriptor
per class and, next to every vtable, a complete-object locator pointing at it.
Walking that gives the class names, the inheritance graph, and which function
sits in which vtable slot -- that is, which methods belong to which class.

    python tools/rtti.py orig/Jw_win.exe decomp/rtti
"""
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pe import PE


def demangle(raw):
    """'.?AVCJw_winView@@' -> 'CJw_winView'.  Nested names come out
    innermost-first in the mangled form, so they are reversed."""
    body = raw[4:-2] if raw.endswith('@@') else raw[4:]
    parts = [p for p in body.split('@') if p]
    return '::'.join(reversed(parts)) if parts else raw


class Rtti:
    def __init__(self, path):
        self.pe = p = PE(path)
        self.base = p.imagebase
        self.text = next(s for s in p.sections if s['name'] == '.text')
        self.rdata = next(s for s in p.sections if s['name'] == '.rdata')
        self.d = p.d

    def va_ok(self, va, sec):
        lo = self.base + sec['va']
        return lo <= va < lo + max(sec['vs'], sec['rs'])

    def u32(self, va):
        o = self.pe.off(va - self.base)
        return struct.unpack_from('<I', self.d, o)[0] if o is not None else None

    def sec_words(self, sec):
        """(va, value) for every 4-aligned dword in a section."""
        o, n = sec['ra'], min(sec['vs'], sec['rs'])
        vals = struct.unpack_from('<%dI' % (n // 4), self.d, o)
        first = self.base + sec['va']
        return first, vals

    def run(self):
        d = self.d
        # 1. type descriptors: the name string, less the vfptr and spare word.
        tds = {}
        for m in re.finditer(rb'\.\?A[VU][A-Za-z0-9_@\?\$]{1,250}@@\x00', d):
            off = m.start()
            va = None
            for s in self.pe.sections:
                if s['ra'] <= off < s['ra'] + s['rs']:
                    va = self.base + s['va'] + (off - s['ra'])
                    break
            if va is None:
                continue
            tds[va - 8] = m.group()[:-1].decode('latin1')

        # 2. complete-object locators reference a type descriptor at +12.
        first, vals = self.sec_words(self.rdata)
        byva = {}
        for i, v in enumerate(vals):
            byva[first + 4 * i] = v
        cols = {}
        for va, v in byva.items():
            if v in tds and va >= 12:
                col = va - 12
                sig = byva.get(col)
                if sig in (0, 1):
                    cols[col] = tds[v]

        # 3. a vtable is the dword after a pointer to its locator.
        tlo = self.base + self.text['va']
        thi = tlo + self.text['vs']
        out = {}
        for va, v in byva.items():
            if v not in cols:
                continue
            vtab = va + 4
            slots = []
            a = vtab
            while True:
                fn = byva.get(a)
                if fn is None or not (tlo <= fn < thi):
                    break
                slots.append(fn)
                a += 4
            if slots:
                out.setdefault(cols[v], []).append((vtab, slots))
        # 4. the locator also points at a class hierarchy descriptor, which
        #    lists the bases in most-derived-first order.
        bases = {}
        for col, raw in cols.items():
            chd = byva.get(col + 16)
            if chd is None:
                continue
            h = self.u32(chd)
            if h is None:
                continue
            n = self.u32(chd + 8)
            arr = self.u32(chd + 12)
            if not n or n > 64 or not arr:
                continue
            names = []
            for i in range(n):
                bcd = self.u32(arr + 4 * i)
                if not bcd:
                    break
                td = self.u32(bcd)
                if td in tds:
                    names.append(tds[td])
            if names:
                bases[raw] = names
        return tds, cols, out, bases


def main():
    exe, outdir = sys.argv[1], sys.argv[2]
    os.makedirs(outdir, exist_ok=True)
    r = Rtti(exe)
    tds, cols, vts, bases = r.run()
    print('type descriptors %d, locators %d, classes with vtables %d'
          % (len(tds), len(cols), len(vts)))

    nslot = 0
    with open(outdir + '/vftables.csv', 'w', encoding='utf-8') as f:
        f.write('class,vftable,slot,func\n')
        for raw in sorted(vts, key=demangle):
            for vtab, slots in sorted(vts[raw]):
                for i, fn in enumerate(slots):
                    f.write('%s,0x%08x,%d,0x%08x\n'
                            % (demangle(raw), vtab, i, fn))
                    nslot += 1
    with open(outdir + '/classes.txt', 'w', encoding='utf-8') as f:
        for raw in sorted(tds.values(), key=demangle):
            f.write('%-60s %s\n' % (demangle(raw), raw))
    with open(outdir + '/hierarchy.txt', 'w', encoding='utf-8') as f:
        for raw in sorted(bases, key=demangle):
            chain = [demangle(x) for x in bases[raw]]
            f.write('%s : %s' % (chain[0], ' <- '.join(chain[1:])) + chr(10))
    print('vftable slots %d -> %s/vftables.csv' % (nslot, outdir))
    print('hierarchies %d -> %s/hierarchy.txt' % (len(bases), outdir))


if __name__ == '__main__':
    main()
