"""Which PDB a PE was built with, and where Microsoft keeps it.

    python tmp/pdbid.py /c/Windows/System32/win32kfull.sys
"""
import struct
import sys


def pdb_of(path):
    d = open(path, 'rb').read()
    pe = struct.unpack_from('<I', d, 0x3c)[0]
    assert d[pe:pe + 4] == b'PE\0\0', path
    nsec, = struct.unpack_from('<H', d, pe + 6)
    opthdr, = struct.unpack_from('<H', d, pe + 20)
    opt = pe + 24
    magic, = struct.unpack_from('<H', d, opt)
    dd = opt + (96 if magic == 0x10b else 112)
    drva, dsize = struct.unpack_from('<II', d, dd + 6 * 8)
    sec = opt + opthdr

    def off(rva):
        for i in range(nsec):
            s = sec + i * 40
            # VirtualSize, VirtualAddress, SizeOfRawData, PointerToRawData
            vs, va, rs, pr = struct.unpack_from('<IIII', d, s + 8)
            if va <= rva < va + max(vs, rs):
                return pr + rva - va
        return None

    o = off(drva)
    for i in range(dsize // 28):
        e = o + i * 28
        typ, = struct.unpack_from('<I', d, e + 12)
        praw, = struct.unpack_from('<I', d, e + 24)
        if typ != 2 or d[praw:praw + 4] != b'RSDS':
            continue
        g = d[praw + 4:praw + 20]
        age, = struct.unpack_from('<I', d, praw + 20)
        name = d[praw + 24:d.index(b'\0', praw + 24)].decode()
        guid = '%08X%04X%04X%s%X' % (
            struct.unpack_from('<I', g, 0)[0],
            struct.unpack_from('<H', g, 4)[0],
            struct.unpack_from('<H', g, 6)[0],
            g[8:16].hex().upper(), age)
        return name, guid
    return None, None


for p in sys.argv[1:]:
    name, guid = pdb_of(p)
    print('%-22s %s' % (p.rsplit('/', 1)[-1], name))
    if name:
        print('   https://msdl.microsoft.com/download/symbols/%s/%s/%s'
              % (name, guid, name))
