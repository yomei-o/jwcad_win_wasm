#!/usr/bin/env python3
"""The sixteen layer groups' states of two drawings, side by side.

    python tools/laystate.py a.jww b.jww

0 hidden, 1 shown, 2 editable, 3 the one being written to.  Only the rows
that differ are printed, so レイヤ非表示化 and friends can be read off.
"""
import importlib.util
import sys

spec = importlib.util.spec_from_file_location('jwwmod', 'tools/jww.py')
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)


def groups(path):
    ar = m.Ar(open(path, 'rb').read())
    return m.read_header(ar, note=lambda *a: None)[2]


a = groups(sys.argv[1])
b = groups(sys.argv[2])
same = 1
for g in range(16):
    ga, gb = a[g], b[g]
    la = [x[0] for x in ga[4]]
    lb = [x[0] for x in gb[4]]
    if ga[0] != gb[0] or la != lb:
        same = 0
        print('group %-2d  state %d -> %d' % (g, ga[0], gb[0]))
        print('   layers %s' % ' '.join(str(x) for x in la))
        print('       -> %s' % ' '.join(str(x) for x in lb))
if same:
    print('the layer states are the same')
