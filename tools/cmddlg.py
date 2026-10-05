"""Which command opens which dialog, out of orig/Jw_win.exe itself.

    python tools/cmddlg.py [out.txt]      (needs decomp/decomp)

MFC keeps a class's WM_COMMAND handlers in an AFX_MSGMAP_ENTRY table in
.rdata -- six dwords: nMessage, nCode, nID, nLastID, nSig, pfn.  Every entry
with nMessage 0x111 (WM_COMMAND) names a command and the function that
handles it.  The decompilation then says which dialog template a function
builds: FUN_00797f57(<template>, parent) is CDialog's constructor.
"""
import io
import re
import struct
import glob
import sys

b = open('orig/Jw_win.exe', 'rb').read()
pe = struct.unpack_from('<I', b, 0x3c)[0]
nsec = struct.unpack_from('<H', b, pe + 6)[0]
optsz = struct.unpack_from('<H', b, pe + 20)[0]
base = struct.unpack_from('<I', b, pe + 24 + 28)[0]
secs = []
off = pe + 24 + optsz
for i in range(nsec):
    name = b[off:off + 8].rstrip(b'\0').decode('latin1')
    vsz, va, rsz, rof = struct.unpack_from('<IIII', b, off + 8)
    secs.append((name, va + base, vsz, rof, rsz))
    off += 40
text = [s for s in secs if s[0] == '.text'][0]
rdata = [s for s in secs if s[0] == '.rdata'][0]
tlo, thi = text[1], text[1] + text[2]

# command -> handler
handlers = {}
_, va, vsz, rof, rsz = rdata
for o in range(rof, rof + rsz - 24, 4):
    msg, code, idf, idl, sig, pfn = struct.unpack_from('<6I', b, o)
    if msg == 0x111 and code == 0 and 32768 <= idf <= 65535 and idf == idl \
            and tlo <= pfn < thi and sig < 100:
        handlers.setdefault(idf, set()).add(pfn)

# function -> its body, from the decompilation
body = {}
for f in glob.glob('decomp/decomp/all_*.c'):
    s = io.open(f, encoding='utf-8', errors='replace').read()
    parts = re.split(r'\n/\* ([0-9a-f]{8})  FUN_[0-9a-f]+  \d+ bytes', s)
    for i in range(1, len(parts) - 1, 2):
        body[int(parts[i], 16)] = parts[i + 1]


def templates(addr, depth):
    t = body.get(addr, '')
    found = set(int(x, 16) for x in re.findall(r'FUN_00797f57\(0x([0-9a-f]+)', t))
    if depth > 0:
        for callee in set(re.findall(r'FUN_([0-9a-f]{8})\(', t)):
            c = int(callee, 16)
            if c != addr and c in body and len(body[c]) < 20000:
                found |= templates(c, depth - 1)
    return found


out = io.open(sys.argv[1] if len(sys.argv) > 1 else "tmp/cmd_dialog.txt", "w", encoding="utf-8")
for cmd in sorted(handlers):
    tp = set()
    for h in handlers[cmd]:
        tp |= templates(h, 2)
    if tp:
        out.write('%d %s %s\n' % (cmd, ' '.join('%08x' % h for h in sorted(handlers[cmd])),
                                  ' '.join(str(x) for x in sorted(tp))))
out.write('# %d commands with handlers\n' % len(handlers))
out.close()
