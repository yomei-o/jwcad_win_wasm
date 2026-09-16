"""Pull MFC's message maps out of the binary.

    python tools/msgmap.py            # every map, with the command ids
    python tools/msgmap.py 0x8003     # who handles this command

An MFC message map is an array of AFX_MSGMAP_ENTRY, 24 bytes each on x86:

    UINT nMessage, nCode, nID, nLastID;  UINT_PTR nSig;  AFX_PMSG pfn;

terminated by an all-zero entry (nSig == 0).  A WM_COMMAND handler has
nMessage 0x0111 and nCode 0, so the arrays are easy to find: look for a run
of entries whose nMessage is a real window message and whose pfn points into
.text.  That gives "this icon calls that function" straight from the
executable, with nothing guessed.
"""
import struct
import sys

from pe import PE

WM = {0x0111: 'COMMAND', 0x0112: 'SYSCOMMAND', 0x0113: 'TIMER',
      0x0114: 'HSCROLL', 0x0115: 'VSCROLL', 0x0020: 'SETCURSOR',
      0x0200: 'MOUSEMOVE', 0x0201: 'LBUTTONDOWN', 0x0202: 'LBUTTONUP',
      0x0203: 'LBUTTONDBLCLK', 0x0204: 'RBUTTONDOWN', 0x0205: 'RBUTTONUP',
      0x0206: 'RBUTTONDBLCLK', 0x0207: 'MBUTTONDOWN', 0x0208: 'MBUTTONUP',
      0x020a: 'MOUSEWHEEL', 0x0100: 'KEYDOWN', 0x0101: 'KEYUP',
      0x0102: 'CHAR', 0x000f: 'PAINT', 0x0005: 'SIZE', 0x0001: 'CREATE',
      0x0002: 'DESTROY', 0x0007: 'SETFOCUS', 0x0008: 'KILLFOCUS',
      0x0014: 'ERASEBKGND', 0x0084: 'NCHITTEST', 0x0024: 'GETMINMAXINFO',
      0x0006: 'ACTIVATE', 0x001c: 'ACTIVATEAPP', 0x0083: 'NCCALCSIZE',
      0x0047: 'WINDOWPOSCHANGED', 0x0046: 'WINDOWPOSCHANGING',
      0x0233: 'DROPFILES', 0x004e: 'NOTIFY', 0x0135: 'CTLCOLORSTATIC',
      0x0010: 'CLOSE', 0x0011: 'QUERYENDSESSION', 0x0016: 'ENDSESSION',
      0x0018: 'SHOWWINDOW', 0x0021: 'MOUSEACTIVATE', 0x00a0: 'NCMOUSEMOVE',
      0x00a1: 'NCLBUTTONDOWN', 0x0082: 'NCDESTROY', 0x0281: 'IME_SETCONTEXT',
      0x0282: 'IME_NOTIFY', 0x010f: 'IME_COMPOSITION', 0x010d: 'IME_STARTCOMPOSITION',
      0x010e: 'IME_ENDCOMPOSITION', 0x02a3: 'MOUSELEAVE', 0x0231: 'ENTERSIZEMOVE',
      0x0232: 'EXITSIZEMOVE'}
# 0 is the "command/update" pseudo message MFC uses for ON_COMMAND
SPECIAL = {0: 'COMMAND-RANGE-or-END'}


def sections(pe):
    out = {}
    for s in pe.sections:
        out[s['name']] = s
    return out


def main():
    pe = PE('orig/Jw_win.exe')
    sec = sections(pe)
    text = sec['.text']
    rdata = sec['.rdata']
    base = pe.imagebase
    tlo, thi = base + text['va'], base + text['va'] + text['vs']

    d = pe.d
    ro, rl = rdata['ra'], rdata['vs']
    entries = {}          # map start rva -> list of entries
    i = ro
    end = ro + rl - 24
    while i <= end:
        msg, code, nid, last, sig, pfn = struct.unpack_from('<IIIIII', d, i)
        # a plausible first entry of a map
        if (msg in WM or msg == 0) and sig != 0 and tlo <= pfn < thi and nid <= 0xffff:
            run = []
            j = i
            while j <= end:
                m, c, n, l, s, p = struct.unpack_from('<IIIIII', d, j)
                if s == 0 and p == 0 and m == 0:
                    break
                if not ((m in WM or m == 0) and s != 0 and tlo <= p < thi
                        and n <= 0xffff and l <= 0xffff and l >= n):
                    break
                run.append((m, c, n, l, s, p))
                j += 24
            if len(run) >= 2:
                entries[base + rdata['va'] + (i - ro)] = run
                i = j + 24
                continue
        i += 4

    want = None
    if len(sys.argv) > 1:
        want = int(sys.argv[1], 0)
    total = 0
    for addr, run in sorted(entries.items()):
        rows = []
        for m, c, n, l, s, p in run:
            if want is not None and not (m == 0x0111 and n <= want <= l):
                continue
            name = WM.get(m, SPECIAL.get(m, '0x%04x' % m))
            rng = '%d' % n if n == l else '%d..%d' % (n, l)
            rows.append('  %-14s %-12s sig %2d  %08x' % (name, rng, s, p))
        if rows:
            total += len(rows)
            print('map at %08x, %d entries' % (addr, len(run)))
            print('\n'.join(rows))
    print('%d maps, %d entries shown' % (len(entries), total))


main()
