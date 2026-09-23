"""Read a .jww far enough to say where the drawing starts.

Follows CJw_winDoc::Serialize (0x004d2820, body 0x00575010) read for read.
It is written in Python first because the header is a long single-file
sequence with a version test on nearly every field: getting it wrong puts
everything after it out of step, and the quickest way to see that is to print
where each stage ended and look at what follows.

    python tools/jww.py orig/Test1.jww
"""
import struct
import sys


class Ar:
    """CArchive, reading."""

    def __init__(self, data):
        self.d = data
        self.o = 0

    def raw(self, n):
        v = self.d[self.o:self.o + n]
        if len(v) != n:
            raise EOFError('want %d bytes at %#x, file is %#x'
                           % (n, self.o, len(self.d)))
        self.o += n
        return v

    def l(self):
        return struct.unpack('<i', self.raw(4))[0]

    def w(self):
        return struct.unpack('<H', self.raw(2))[0]

    def b(self):
        return self.raw(1)[0]

    def dbl(self):
        return struct.unpack('<d', self.raw(8))[0]

    def strlen(self):
        """MFC's ReadStringLength: (count, unicode)."""
        n = self.b()
        if n < 0xff:
            return n, False
        n = self.w()
        uni = False
        if n == 0xfffe:
            uni = True
            n = self.b()
            if n < 0xff:
                return n, True
            n = self.w()
        if n == 0xffff:
            return struct.unpack('<I', self.raw(4))[0], uni
        return n, uni

    def s(self):
        n, uni = self.strlen()
        b = self.raw(n * 2 if uni else n)
        return b.decode('utf-16-le' if uni else 'cp932', 'replace')


TABLES = {}


def read_header(ar, note=print):
    sig = ar.raw(8)
    if sig != b'JwwData.':
        raise ValueError('not a .jww: %r' % sig)
    v = ar.l()
    note('version %d' % v)
    name = ar.s() if v > 0x40 else ''
    note('name %r  -> %#x' % (name, ar.o))

    groups = []
    if v > 9:
        ar.l()                          # +0x2f98
        ar.l()                          # +0x24e4
        for g in range(16):
            a = ar.l()                  # +0x23a4  group state
            b = ar.l()                  # +0x2464
            scale = ar.dbl()            # +0x24f0  the group's scale
            c = ar.l() if v > 0xd3 else 0
            layers = []
            for _ in range(16):
                s1 = ar.l()             # +0x17a4  layer state
                s2 = ar.l() if v > 0xd3 else 0
                layers.append((s1, s2))
            groups.append((a, b, scale, c, layers))
    note('16 groups -> %#x  (scales %s)'
         % (ar.o, ' '.join('%g' % g[2] for g in groups[:4])))

    if v > 0xd3:
        ar.l()                          # +0xce
        for _ in range(13):             # local_9e54[0..12]
            ar.l()
        for _ in range(5):              # +0xcf .. +0xd3
            ar.l()
        ar.l()                          # local_9e54[0x12]
        ar.l()                          # the printer scale
    if v > 0x3b:
        ar.dbl(); ar.dbl()
    if v > 0xc9:
        ar.dbl(); ar.l()
    if v > 0x3d:
        ar.l()
        for _ in range(5):
            ar.dbl()
    note('settings -> %#x' % ar.o)

    layer_names, group_names = [], []
    if v > 0x3f:
        for _ in range(16):
            layer_names.append([ar.s() for _ in range(16)])
        group_names = [ar.s() for _ in range(16)]
    note('names -> %#x  (group 0 %r, layers %r)'
         % (ar.o, group_names[0] if group_names else '',
            [n for n in (layer_names[0] if layer_names else []) if n][:4]))

    if v > 99:
        ar.dbl(); ar.dbl(); ar.l()
    if v > 100:
        ar.dbl()
        if v > 299:
            ar.dbl(); ar.dbl()
        ar.l()
    if v > 199:
        for _ in range(6):
            ar.dbl()
        if v < 300:
            for _ in range(4):
                ar.dbl(); ar.dbl(); ar.dbl()
        else:
            for _ in range(8):
                ar.dbl(); ar.dbl(); ar.dbl(); ar.l()
            ar.dbl(); ar.dbl(); ar.dbl(); ar.l()
            ar.dbl(); ar.dbl(); ar.dbl(); ar.l()
        for _ in range(10):
            ar.dbl()
        ar.dbl()
    note('pen table -> %#x' % ar.o)

    if v > 200:
        # the ten screen pens: a COLORREF and a width
        TABLES['pen'] = [(ar.l(), ar.l()) for _ in range(10)]
        # and the ten printing pens: a COLORREF, a flag and a width in mm
        TABLES['ppen'] = [(ar.l(), ar.l(), ar.dbl()) for _ in range(10)]
        TABLES['b1'] = [tuple(ar.l() for _ in range(4)) for _ in range(2, 10)]
        TABLES['b2'] = [tuple(ar.l() for _ in range(5))
                        for _ in range(0xb, 0x10)]
        TABLES['b3'] = [tuple(ar.l() for _ in range(4))
                        for _ in range(0x10, 0x14)]
        ar.l(); ar.l()
        if v > 0xd8:
            for _ in range(3):
                ar.l(); ar.l(); ar.l()
        if v >= 0xdf:
            ar.l()
            for _ in range(4):
                ar.l()
            for _ in range(5):
                ar.dbl()
        if v >= 0xe1:
            for _ in range(4):
                ar.dbl()
        if v > 0xe1:
            ar.l(); ar.l()
        if v > 0x1a3:
            # 257 line colours and 257 line types -- more than the eight pens
            # the dialogs offer, because reading a DXF makes a new one for
            # every colour and every linetype it does not already have.
            TABLES['color'] = [(ar.l(), ar.l()) for _ in range(0x101)]
            TABLES['ltype'] = [(ar.s(), ar.l(), ar.l(), ar.dbl())
                               for _ in range(0x101)]
            TABLES['pcolor'] = [(ar.l(), ar.l(), ar.l(), ar.l())
                                for _ in range(0x21)]
            TABLES['pltype'] = [(ar.s(), ar.l(),
                                 [ar.dbl() for _ in range(10)])
                                for _ in range(0x21)]
    note('pens and line types -> %#x' % ar.o)

    # FUN_004eee80, called from CJw_winDoc::Serialize just before the object
    # list: the hatch and dimension settings.
    if v > 0x14:
        for _ in range(10):
            ar.dbl(); ar.dbl(); ar.dbl(); ar.l()
        ar.dbl(); ar.dbl(); ar.dbl(); ar.l(); ar.l()
        ar.dbl(); ar.dbl()
    if v > 0xd5:
        ar.l()
        for _ in range(6):
            ar.dbl()
    note('hatch and dimensions -> %#x' % ar.o)
    return v, name, groups


def read_base(ar, v):
    """CData::Serialize -- 15 bytes at version 600."""
    o = {}
    if v > 0x13:
        o['id'] = ar.l()
    o['pen'] = ar.b()               # +0x28  colour, 100.. means something else
    o['type'] = ar.w()              # +0x2a  line type
    if v > 0x15e:
        o['width'] = ar.w()         # +0x2c
    o['f2e'] = ar.w()               # +0x2e
    o['f2f'] = ar.w()               # +0x2f
    if v > 0x13:
        o['flags'] = ar.w()         # +0x44
    return o


def read_sen(ar, v, o):
    o['x0'], o['y0'], o['x1'], o['y1'] = (ar.dbl() for _ in range(4))


def read_enko(ar, v, o):
    o['d'] = [ar.dbl() for _ in range(7)]
    o['n'] = ar.l()


def read_ten(ar, v, o):
    o['x'], o['y'] = ar.dbl(), ar.dbl()
    if v > 0x15:
        o['kind'] = ar.l()
    if v == 0xfc or (v > 299 and o['pen'] == 100):
        ar.l(); ar.dbl(); ar.dbl()


def read_moji(ar, v, o):
    o['x0'], o['y0'], o['x1'], o['y1'] = (ar.dbl() for _ in range(4))
    if v > 0x13:
        o['font'] = ar.l()
    o['w'], o['h'] = ar.dbl(), ar.dbl()
    if v > 0x13:
        ar.dbl()
    ar.dbl()
    if v > 0x27:
        o['face'] = ar.s()
    o['text'] = ar.s()


def read_solid(ar, v, o):
    o['pts'] = [ar.dbl() for _ in range(8)]
    if o['type'] == 10:
        o['rgb'] = ar.l()


def read_block(ar, v, o):
    # CDataBlock::Serialize (0x0049b2c0): five doubles -- where the figure
    # sits, how big and which way round -- and the number of the definition
    # it stands for.
    o['d'] = [ar.dbl() for _ in range(5)]
    o['block'] = ar.l()


def read_list(ar, v, o, load=None):
    # CDataList::Serialize (0x0049b410): three numbers, a name, and then the
    # elements of the definition itself, as a list of their own inside the
    # list that holds this.
    o['longs'] = [ar.l() for _ in range(3)]
    o['name'] = ar.s()
    o['members'] = read_objects(ar, v, note=lambda s: None, load=load)


BODY = {
    'CDataBlock': read_block,
    'CDataList': read_list,
    'CDataSen': read_sen,
    'CDataEnko': read_enko,
    'CDataTen': read_ten,
    'CDataMoji': read_moji,
    'CDataSolid': read_solid,
}


def read_objects(ar, v, note=print, load=None):
    """CObList::Serialize, then CArchive's tagged objects.

    The numbering runs through the whole file rather than through one list,
    so `load` is handed on: the block definitions refer back to a class the
    drawing itself introduced, and a definition's own elements are read in
    the middle of the list that holds it.
    """
    n = ar.w()
    if n == 0xffff:
        n = struct.unpack('<I', ar.raw(4))[0]
    note('%d objects at %#x' % (n, ar.o))
    # CArchive's load array holds classes and objects in one numbering, one
    # based, so an object's tag and a class's tag are indices into the same
    # list.  0x8000 marks a class; 0xffff means "a class not seen before".
    if load is None:
        load = [None]
    out = []
    for i in range(n):
        tag = ar.w()
        if tag == 0:
            out.append(None)
            continue
        if tag == 0xffff:
            ar.w()                              # schema
            name = ar.raw(ar.w()).decode('latin1')
            load.append(('class', name))
        elif tag & 0x8000:
            kind, name = load[tag & 0x7fff]
            if kind != 'class':
                raise ValueError('tag %#x at %#x is not a class'
                                 % (tag, ar.o - 2))
        else:
            kind, o = load[tag]                 # a second reference to one
            out.append(o)                       # object already read
            continue
        body = BODY.get(name)
        if body is None:
            raise ValueError('%s at %#x: body not decoded yet' % (name, ar.o))
        o = read_base(ar, v)
        o['class'] = name
        load.append(('obj', o))
        if name == 'CDataList':
            body(ar, v, o, load)
        else:
            body(ar, v, o)
        out.append(o)
    return out


def show(objs):
    """One line per object, everything the reader kept."""
    for i, o in enumerate(objs):
        bits = ['%3d %-10s' % (i, o['class'])]
        for k in ('pen', 'type', 'width', 'f2e', 'f2f', 'flags', 'kind',
                  'font', 'n', 'block'):
            if k in o:
                bits.append('%s=%s' % (k, o[k]))
        for k in ('x0', 'y0', 'x1', 'y1', 'x', 'y', 'w', 'h', 'rgb'):
            if k in o:
                bits.append('%s=%g' % (k, o[k]))
        if 'd' in o:
            bits.append('d=[%s]' % ' '.join('%g' % v for v in o['d']))
        if 'pts' in o:
            bits.append('pts=[%s]' % ' '.join('%g' % v for v in o['pts']))
        if 'members' in o:
            bits.append('members=%d' % len(o['members']))
        for k in ('longs',):
            if k in o:
                bits.append('%s=%s' % (k, o[k]))
        for k in ('name', 'face', 'text'):
            if k in o:
                bits.append('%s=%r' % (k, o[k]))
        print(' '.join(bits))


def main():
    """python tools/jww.py <file> [-l]  -- -l lists the objects as well."""
    data = open(sys.argv[1], 'rb').read()
    ar = Ar(data)
    v, name, groups = read_header(ar)
    load = [None]
    objs = read_objects(ar, v, load=load)
    if v > 0x13:
        # the second list (piStack_bc95c[0x40]): the block definitions
        objs += read_objects(ar, v, note=lambda s: print('block list: ' + s),
                             load=load)
    if '-l' in sys.argv[2:]:
        show(objs)
    if '-t' in sys.argv[2:]:
        for k in ('pen', 'ppen', 'b1', 'b2', 'b3', 'color', 'ltype', 'pcolor', 'pltype'):
            for i, e in enumerate(TABLES.get(k, [])):
                print('%-7s %3d %s' % (k, i, e))
    import collections
    print('  ' + ', '.join('%s %d' % kv for kv in
                           collections.Counter(o['class'] for o in objs).items()))
    print('file is %#x bytes; stopped at %#x (%+d)'
          % (len(data), ar.o, ar.o - len(data)))
    if ar.o != len(data):
        print('next 48 bytes: %s' % data[ar.o:ar.o + 48].hex(' '))


if __name__ == '__main__':
    main()
