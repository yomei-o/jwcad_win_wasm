"""Minimal PE reader: sections, RVA->file offset, and the resource tree.

Only what the port needs.  Jw_win.exe is a 32-bit MSVC image with four
sections and a 2.1 MB .rsrc, and everything the UI looks like is in there.
"""
import struct

RT = {1:'CURSOR',2:'BITMAP',3:'ICON',4:'MENU',5:'DIALOG',6:'STRING',
      7:'FONTDIR',8:'FONT',9:'ACCELERATOR',10:'RCDATA',11:'MESSAGETABLE',
      12:'GROUP_CURSOR',14:'GROUP_ICON',16:'VERSION',17:'DLGINCLUDE',
      19:'PLUGPLAY',20:'VXD',21:'ANICURSOR',22:'ANIICON',23:'HTML',
      24:'MANIFEST'}


class PE:
    def __init__(self, path):
        self.path = path
        self.d = d = open(path, 'rb').read()
        pe = struct.unpack_from('<I', d, 0x3c)[0]
        self.machine, nsec, _, _, _, osz, _ = struct.unpack_from('<HHIIIHH', d, pe + 4)
        opt = pe + 24
        self.imagebase = struct.unpack_from('<I', d, opt + 28)[0]
        self.entry = struct.unpack_from('<I', d, opt + 16)[0]
        so = opt + osz
        self.sections = []
        for i in range(nsec):
            o = so + 40 * i
            name = d[o:o+8].rstrip(b'\0').decode('latin1')
            vs, va, rs, ra = struct.unpack_from('<IIII', d, o + 8)
            flags = struct.unpack_from('<I', d, o + 36)[0]
            self.sections.append(dict(name=name, vs=vs, va=va, rs=rs, ra=ra, flags=flags))
        nd = struct.unpack_from('<I', d, opt + 92)[0]
        self.dirs = [struct.unpack_from('<II', d, opt + 96 + 8 * i) for i in range(nd)]

    def off(self, rva):
        for s in self.sections:
            if s['va'] <= rva < s['va'] + max(s['vs'], s['rs']):
                return s['ra'] + (rva - s['va'])
        return None

    def at(self, rva, n):
        o = self.off(rva)
        return self.d[o:o+n]

    # ---- resources -------------------------------------------------------
    def resources(self):
        """[(type, name, lang, rva, size)] with type/name as int or str."""
        base = self.dirs[2][0]
        if not base:
            return []
        out = []
        self._walk(base, base, [], out)
        return out

    def _entries(self, off):
        d = self.d
        nnamed, nid = struct.unpack_from('<HH', d, off + 12)
        for i in range(nnamed + nid):
            yield struct.unpack_from('<II', d, off + 16 + 8 * i)

    def _name(self, base, nameval):
        if nameval & 0x80000000:
            o = self.off(base) + (nameval & 0x7fffffff)
            n = struct.unpack_from('<H', self.d, o)[0]
            return self.d[o+2:o+2+2*n].decode('utf-16-le')
        return nameval

    def _walk(self, base, rva, path, out):
        off = self.off(rva)
        for nameval, offval in self._entries(off):
            nm = self._name(base, nameval)
            if offval & 0x80000000:
                self._walk(base, base + (offval & 0x7fffffff), path + [nm], out)
            else:
                o = self.off(base + offval)
                dr, sz, _, _ = struct.unpack_from('<IIII', self.d, o)
                t, n, lang = (path + [nm] + [None, None, None])[:3]
                out.append((t, n, lang, dr, sz))

    def res_data(self, rva, size):
        o = self.off(rva)
        return self.d[o:o+size]
