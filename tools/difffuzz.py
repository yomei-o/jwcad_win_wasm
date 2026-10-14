#!/usr/bin/env python
"""Differential fuzzer: original Jw_win.exe  vs  the C port.

  python tools/difffuzz.py run    --n 130 --seed 1     generate + run + compare (resumable)
  python tools/difffuzz.py one "<steps>"               compare one jwdraw-style step string
  python tools/difffuzz.py shrink                      delta-debug every divergence in tmp/fz/results.json
  python tools/difffuzz.py report                      write tmp/difffuzz_report.md (+ decomp/res/fz_<n>.jww,
                                                       tools/fuzzcases/<n>.txt for the minimal repros)

Needs tools/replay.sh run once (tmp/replay.exe) and decomp/res/new.jww.  The original is driven one
launch at a time through tools/orig1.sh (-> tools/jwdraw.ps1); never run two of these at once.

Sequence = list of "ops"; an op is a few jwdraw steps (cmd:<id>;x,y;...).  Plain left clicks
(and r<x>,<y> to end a polyline), default bar settings except 水平・垂直 which is switched off,
as in the probes.  Objects are compared ignoring Printer_/View_D/Draw_B junk text, 1e-3 mm
tolerance, class/ltype/colour/layer/flags exact.  The original is flaky (picks occasionally
miss), so a divergence is only believed once two runs of the original agree with each other.
"""
import sys, os, math, random, subprocess, hashlib, json, re, argparse

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
SH = r'C:\Program Files\Git\usr\bin\sh.exe'
REPLAY = os.environ.get('JW_REPLAY') or os.path.join(ROOT, 'tmp', 'replay.exe')   # 走らせている間 qtest が作り直せるよう コピーを指せる
FZ = os.path.join(ROOT, 'tmp', 'fz')
os.makedirs(os.path.join(FZ, 'orig'), exist_ok=True)
os.makedirs(os.path.join(FZ, 'port'), exist_ok=True)
TOL = 1e-3

# ---------------------------------------------------------------- generator
X0, X1, Y0, Y1 = 250, 900, 250, 600


def clampi(v, lo, hi):
    return max(lo, min(hi, int(round(v))))


class Gen:
    def __init__(self, rng):
        self.r = rng
        self.lines = []      # (x1,y1,x2,y2)
        self.circs = []      # (cx,cy,r)
        self.arcmode = False

    def pt(self):
        return (self.r.randint(X0, X1), self.r.randint(Y0, Y1))

    def elems(self):
        return [('L', l) for l in self.lines] + [('C', c) for c in self.circs]

    def pick(self, e, t=None):
        k, g = e
        if k == 'L':
            t = self.r.uniform(.15, .85) if t is None else t
            return (clampi(g[0] + (g[2] - g[0]) * t, 0, 1100), clampi(g[1] + (g[3] - g[1]) * t, 0, 680))
        a = self.r.uniform(0, 2 * math.pi)
        return (clampi(g[0] + g[2] * math.cos(a), 0, 1100), clampi(g[1] + g[2] * math.sin(a), 0, 680))

    def side_pt(self, e, p):
        k, g = e
        d = self.r.randint(25, 120)
        s = self.r.choice((-1, 1))
        if k == 'L':
            dx, dy = g[2] - g[0], g[3] - g[1]
            n = math.hypot(dx, dy) or 1
            return (clampi(p[0] - dy / n * d * s, 0, 1100), clampi(p[1] + dx / n * d * s, 0, 680))
        dx, dy = p[0] - g[0], p[1] - g[1]
        n = math.hypot(dx, dy) or 1
        return (clampi(g[0] + dx / n * (g[2] + d * s), 0, 1100), clampi(g[1] + dy / n * (g[2] + d * s), 0, 680))

    @staticmethod
    def S(p):
        return '%d,%d' % p

    # ---- drawing ops
    def op_line(self):
        a = self.pt()
        while True:
            b = self.pt()
            if math.hypot(a[0] - b[0], a[1] - b[1]) > 70:
                break
        self.lines.append(a + b)
        return ('line', ['cmd:32771', 'off:1333', self.S(a), self.S(b)])

    def op_rect(self):
        while True:
            a, b = self.pt(), self.pt()
            if abs(a[0] - b[0]) > 50 and abs(a[1] - b[1]) > 50:
                break
        x1, y1, x2, y2 = a + b
        # the original draws bottom-left start; use its order (L,B,R,T edges as seen in files)
        self.lines += [(x1, y1, x2, y1), (x2, y1, x2, y2), (x2, y2, x1, y2), (x1, y2, x1, y1)]
        return ('rect', ['cmd:32772', 'off:1333', self.S(a), self.S(b)])

    def op_circle(self):
        c = self.pt()
        r = self.r.randint(30, 150)
        a = self.r.choice((0, 0, math.pi / 2, self.r.uniform(0, 6.28)))
        p = (clampi(c[0] + r * math.cos(a), 0, 1100), clampi(c[1] + r * math.sin(a), 0, 680))
        rr = max(1, int(round(math.hypot(p[0] - c[0], p[1] - c[1]))))
        self.circs.append((c[0], c[1], rr))
        return ('circle', ['cmd:32773', self.S(c), self.S(p)])

    def op_arc(self):
        a, b, c = self.pt(), self.pt(), self.pt()
        self.arcmode = True
        return ('arc', ['cmd:32773', 'btn:1321', self.S(a), self.S(b), self.S(c)])

    def op_poly(self):
        n = self.r.randint(3, 4)
        ps = [self.pt() for _ in range(n)]
        for i in range(n - 1):
            self.lines.append(ps[i] + ps[i + 1])
        return ('poly', ['cmd:32883'] + [self.S(p) for p in ps] + ['r' + self.S(ps[-1])])

    # ---- editing ops
    def two_lines_near_crossing(self):
        L = self.lines
        cand = []
        for i in range(len(L)):
            for j in range(i + 1, len(L)):
                a, b = L[i], L[j]
                d1 = (a[2] - a[0], a[3] - a[1]); d2 = (b[2] - b[0], b[3] - b[1])
                den = d1[0] * d2[1] - d1[1] * d2[0]
                if abs(den) < 1e-6:
                    continue
                t = ((b[0] - a[0]) * d2[1] - (b[1] - a[1]) * d2[0]) / den
                s = ((b[0] - a[0]) * d1[1] - (b[1] - a[1]) * d1[0]) / den
                cand.append((i, j, t, s))
        if not cand:
            return None
        good = [c for c in cand if -0.3 < c[2] < 1.3 and -0.3 < c[3] < 1.3] or cand
        return self.r.choice(good)

    def pair(self, near=True):
        if len(self.lines) < 2:
            return None
        if near and self.r.random() < .75:
            c = self.two_lines_near_crossing()
            if c:
                return c[0], c[1]
        i, j = self.r.sample(range(len(self.lines)), 2)
        return i, j

    def op_erase(self):
        es = self.elems()
        if not es:
            return None
        e = self.r.choice(es)
        p = self.pick(e)
        if e[0] == 'L':
            self.lines.remove(e[1])
        else:
            self.circs.remove(e[1])
        return ('erase', ['cmd:32794', self.S(p)])

    def op_fukusen(self):
        es = self.elems()
        if not es:
            return None
        e = self.r.choice(es)
        p = self.pick(e)
        q = self.side_pt(e, p)
        toks = ['cmd:32800', self.S(p)]
        # typed before the first pick the original ignores the value (harness
        # limit); after it, it takes it
        if self.r.random() < .3:
            toks.append('chr:1411,%d' % self.r.choice((500, 1000, 3000, 7000)))
        toks += [self.S(q)]
        return ('fukusen', toks)

    def op_corner(self):
        pr = self.pair()
        if not pr:
            return None
        a, b = self.lines[pr[0]], self.lines[pr[1]]
        return ('corner', ['cmd:32786', self.S(self.pick(('L', a))), self.S(self.pick(('L', b)))])

    def op_mentori(self):
        pr = self.pair()
        if not pr:
            return None
        a, b = self.lines[pr[0]], self.lines[pr[1]]
        return ('mentori', ['cmd:32859'] + (['ch:1411,%d' % self.r.choice((1000, 2000, 5000))] if self.r.random() < .5 else []) + [self.S(self.pick(('L', a))), self.S(self.pick(('L', b)))])

    def op_shinshuku(self):
        pr = self.pair(near=False)
        if not pr:
            return None
        a, b = self.lines[pr[0]], self.lines[pr[1]]
        t = self.r.choice((.08, .12, .88, .92))
        if self.r.random() < .5:
            q = self.pick(('L', b))
        else:
            q = self.pt()
        return ('shinshuku', ['cmd:32791', self.S(self.pick(('L', a), t)), self.S(q)])

    def op_bunkatsu(self):
        pr = self.pair(near=False)
        if not pr:
            return None
        a, b = self.lines[pr[0]], self.lines[pr[1]]
        return ('bunkatsu', ['cmd:32867'] + (['ch:1411,%d' % self.r.choice((2, 3, 4))] if self.r.random() < .6 else []) + [self.S(self.pick(('L', a))), self.S(self.pick(('L', b)))])

    def op_bk2(self):
        """分割 の いろいろ: 線線・円円の扇、点(R)＋線/円(L)、２点(R)(R)＋線/円(L)。
        分割数 か 割付(振分・割付距離以下)。"""
        r = self.r
        es = self.elems()
        if not es:
            return None
        toks = ['cmd:32867']
        mode = r.choice(['n', 'n', 'wari', 'furi', 'ika'])
        if mode == 'n':
            toks.append('chr:1411,%d' % r.choice((2, 3, 4, 5)))
        else:
            toks.append('pb:1324')
            if mode == 'furi':
                toks.append('pb:1325')
            if mode == 'ika':
                toks.append('pb:1326')
            toks.append('chr:1412,%d' % r.choice((1000, 1500, 2500, 4000)))
        ends = []
        for g in self.lines:
            ends += [(g[0], g[1]), (g[2], g[3])]
        kind = r.choice(['ee', 'pe', 'p2'])
        if kind == 'ee':
            Ls = [e for e in es if e[0] == 'L']
            Cs = [e for e in es if e[0] == 'C']
            pool = Ls if len(Ls) >= 2 and (len(Cs) < 2 or r.random() < .5) else Cs
            if len(pool) < 2:
                return None
            a, b = r.sample(pool, 2)
            toks += [self.S(self.pick(a)), self.S(self.pick(b))]
        elif kind == 'pe':
            if not ends:
                return None
            pnt = r.choice(ends)
            e = r.choice(es)
            toks += ['r' + self.S((clampi(pnt[0], 0, 1100), clampi(pnt[1], 0, 680))), self.S(self.pick(e))]
        else:
            if len(ends) < 2:
                return None
            p1, p2 = r.sample(ends, 2)
            e = r.choice(es)
            toks += ['r' + self.S((clampi(p1[0], 0, 1100), clampi(p1[1], 0, 680))),
                     'r' + self.S((clampi(p2[0], 0, 1100), clampi(p2[1], 0, 680))), self.S(self.pick(e))]
        return ('bk2', toks)

    def rng_box(self):
        es = self.elems()
        if not es:
            return None
        e = self.r.sample(es, min(len(es), self.r.randint(1, 2)))
        xs, ys = [], []
        for k, g in e:
            if k == 'L':
                xs += [g[0], g[2]]; ys += [g[1], g[3]]
            else:
                xs += [g[0] - g[2], g[0] + g[2]]; ys += [g[1] - g[2], g[1] + g[2]]
        m = 10
        return (clampi(min(xs) - m, 5, 1100), clampi(min(ys) - m, 5, 680),
                clampi(max(xs) + m, 5, 1100), clampi(max(ys) + m, 5, 680))

    def op_range_erase(self):
        b = self.rng_box()
        if not b:
            return None
        return ('range_erase', ['cmd:32787', '%d,%d' % b[:2], '%d,%d' % b[2:], 'cmd:32794'])

    def op_move(self, copy=False):
        b = self.rng_box()
        if not b:
            return None
        bp = self.pt()
        dp = (clampi(bp[0] + self.r.randint(-200, 200), 0, 1100), clampi(bp[1] + self.r.randint(-150, 150), 0, 680))
        return ('copy' if copy else 'move',
                ['cmd:32804' if copy else 'cmd:32918', '%d,%d' % b[:2], '%d,%d' % b[2:],
                 'm%d,%d' % bp, 'btn:1120', 'pb:1066', self.S(bp), self.S(dp)])

    def op_copy(self):
        return self.op_move(True)


DRAW = ['line', 'line', 'line', 'rect', 'circle', 'poly', 'arc']
EDIT = ['erase', 'fukusen', 'fukusen', 'corner', 'corner', 'shinshuku', 'bunkatsu', 'mentori', 'bk2', 'bk2', 'bk2', 'bk2',
        'range_erase', 'move', 'copy']


def gen_seq(seed):
    g = Gen(random.Random(seed))
    r = g.r
    nd = r.randint(2, 4)
    ne = r.randint(1, 2)
    ops = []
    guard = 0
    while len([o for o in ops if o[0] in DRAW]) < nd and guard < 20:
        guard += 1
        k = r.choice(DRAW)
        if k == 'circle' and g.arcmode:
            continue
        if k == 'arc' and (g.arcmode or g.circs):
            continue
        ops.append(getattr(g, 'op_' + k)())
    guard = 0
    while len([o for o in ops if o[0] in EDIT]) < ne and guard < 30:
        guard += 1
        k = r.choice(EDIT)
        o = getattr(g, 'op_' + k)()
        if o:
            ops.append(o)
    return ops


def steps_of(ops):
    return ';'.join(';'.join(t) for _, t in ops)


# ---------------------------------------------------------------- running
def run_port(steps, tag):
    out = os.path.join(FZ, 'port', tag + '.jww')
    subprocess.run([REPLAY, 'run', steps, out], cwd=ROOT, capture_output=True, timeout=60)
    return out


def dump(path):
    if not os.path.exists(path):
        return None
    r = subprocess.run([REPLAY, 'dump', path], cwd=ROOT, capture_output=True, timeout=60)
    lines = [l for l in r.stdout.decode('utf-8', 'replace').splitlines() if l.startswith('cls')]
    out = []
    for l in lines:
        m = re.match(r'(cls.*?) d=(.*?)\s*(text\[.*\])?$', l)
        if not m:
            continue
        out.append((m.group(1), [float(x) for x in m.group(2).split()], m.group(3) or ''))
    return out


def run_orig(steps, key, k):
    name = 'fzo_%s_%d' % (key, k)
    dst = os.path.join(FZ, 'orig', '%s_%d.jww' % (key, k))
    if os.path.exists(dst):
        return dst
    for attempt in range(3):
        p = os.path.join(ROOT, 'tmp', name + '.jww')
        if os.path.exists(p):
            os.remove(p)
        try:
            subprocess.run([SH, 'tools/orig1.sh', name, steps], cwd=ROOT, capture_output=True, timeout=180)
        except subprocess.TimeoutExpired:
            subprocess.run(['taskkill', '/F', '/IM', 'Jw_win.exe'], capture_output=True)
        if os.path.exists(p) and os.path.getsize(p) > 1000:
            os.replace(p, dst)
            return dst
        subprocess.run(['taskkill', '/F', '/IM', 'Jw_win.exe'], capture_output=True)
    return None


def match(A, B):
    """A,B lists of objs.  returns (only_a, only_b, same_order)"""
    used = [False] * len(B)
    pairs = []
    only_a = []
    for i, a in enumerate(A):
        hit = -1
        for j, b in enumerate(B):
            if used[j] or a[0] != b[0] or a[2] != b[2]:
                continue
            if all(abs(x - y) <= TOL for x, y in zip(a[1], b[1])):
                hit = j
                break
        if hit < 0:
            only_a.append(a)
        else:
            used[hit] = True
            pairs.append((i, hit))
    only_b = [B[j] for j in range(len(B)) if not used[j]]
    order = all(pairs[k][1] < pairs[k + 1][1] for k in range(len(pairs) - 1))
    return only_a, only_b, order


def fmt(o):
    return '%s d=%s %s' % (o[0], ' '.join('%.3f' % x for x in o[1][:6]), o[2])


def key_of(steps):
    return hashlib.md5(steps.encode()).hexdigest()[:12]


def compare(steps, max_orig=4):
    """returns dict(status, ...).  status: agree | agree_order | diverge | flaky | orig_fail"""
    key = key_of(steps)
    P = dump(run_port(steps, key))
    if P is None:
        return dict(status='port_fail', key=key)
    runs = []
    for k in range(max_orig):
        f = run_orig(steps, key, k)
        if f is None:
            if not runs:
                return dict(status='orig_fail', key=key)
            break
        O = dump(f)
        runs.append(O)
        oa, pb, order = match(O, P)
        if not oa and not pb:
            return dict(status='agree' if order else 'agree_order', key=key, orig_run=k)
        # need a second orig run agreeing with this one before believing it
        for j in range(len(runs) - 1):
            a2, b2, _ = match(runs[j], O)
            if not a2 and not b2:
                return dict(status='diverge', key=key, only_orig=[fmt(o) for o in oa],
                            only_port=[fmt(o) for o in pb], orig_run=k, n_orig=len(O), n_port=len(P))
    return dict(status='flaky', key=key)


# ---------------------------------------------------------------- driver
RES = os.path.join(FZ, 'results.json')


def load_res():
    return json.load(open(RES)) if os.path.exists(RES) else {}


def save_res(r):
    json.dump(r, open(RES, 'w'), ensure_ascii=False, indent=1)


def cmd_run(a):
    res = load_res()
    for i in range(a.n):
        sid = 's%d_%d' % (a.seed, i)
        if sid in res and res[sid]['status'] in ('agree', 'agree_order', 'diverge'):
            continue
        ops = gen_seq(a.seed * 100003 + i)
        steps = steps_of(ops)
        c = compare(steps)
        c.update(id=sid, steps=steps, ops=ops, last=[o[0] for o in ops if o[0] in EDIT][-1:] or ['-'])
        res[sid] = c
        save_res(res)
        print(sid, c['status'], c['last'], flush=True)
        if c['status'] == 'diverge':
            for s in c['only_orig'][:3]:
                print('   orig only:', s)
            for s in c['only_port'][:3]:
                print('   port only:', s)


def cmd_one(a):
    c = compare(a.steps)
    print(json.dumps(c, ensure_ascii=False, indent=1))


def diverges(ops):
    c = compare(steps_of(ops))
    return c['status'] == 'diverge', c


def shrink(ops):
    """drop whole ops while a divergence persists (ddmin-ish, greedy)"""
    cur = list(ops)
    changed = True
    while changed:
        changed = False
        for i in range(len(cur)):
            if len(cur) <= 1:
                break
            cand = cur[:i] + cur[i + 1:]
            ok, _ = diverges(cand)
            if ok:
                cur = cand
                changed = True
                break
    return cur


def cmd_shrink(a):
    res = load_res()
    mins = json.load(open(os.path.join(FZ, 'mins.json'))) if os.path.exists(os.path.join(FZ, 'mins.json')) else {}
    for sid, c in res.items():
        if c['status'] != 'diverge' or sid in mins:
            continue
        if a.only and not re.match(a.only, sid):
            continue
        m = shrink([tuple(o) for o in c['ops']])
        ok, cc = diverges(m)
        mins[sid] = dict(steps=steps_of(m), ops=m, cmp=cc)
        json.dump(mins, open(os.path.join(FZ, 'mins.json'), 'w'), ensure_ascii=False, indent=1)
        print(sid, '->', steps_of(m), flush=True)


def cmd_report(a):
    res = load_res()
    mins = json.load(open(os.path.join(FZ, 'mins.json'))) if os.path.exists(os.path.join(FZ, 'mins.json')) else {}
    cnt = {}
    for c in res.values():
        cnt[c['status']] = cnt.get(c['status'], 0) + 1
    os.makedirs(os.path.join(ROOT, 'tools', 'fuzzcases'), exist_ok=True)
    seen = {}
    n = 0
    L = ['# difffuzz report', '', 'sequences: %d  %s' % (len(res), cnt), '']
    for sid, m in mins.items():
        if m['steps'] in seen:
            continue
        seen[m['steps']] = 1
        n += 1
        cc = m['cmp']
        key = cc['key']
        src = os.path.join(FZ, 'orig', '%s_%d.jww' % (key, cc.get('orig_run', 0)))
        if os.path.exists(src):
            import shutil
            shutil.copy(src, os.path.join(ROOT, 'decomp', 'res', 'fz_%d.jww' % n))
        open(os.path.join(ROOT, 'tools', 'fuzzcases', '%d.txt' % n), 'w', encoding='utf-8').write(m['steps'] + '\n')
        L += ['## case %d  (%s)' % (n, sid), '', '    ' + m['steps'], '',
              'original only:'] + ['    ' + s for s in cc['only_orig']] + ['', 'port only:'] + \
             ['    ' + s for s in cc['only_port']] + ['']
    open(os.path.join(ROOT, 'tmp', 'difffuzz_report.md'), 'w', encoding='utf-8').write('\n'.join(L))
    print('\n'.join(L))


if __name__ == '__main__':
    ap = argparse.ArgumentParser()
    sp = ap.add_subparsers(dest='cmd', required=True)
    p = sp.add_parser('run'); p.add_argument('--n', type=int, default=130); p.add_argument('--seed', type=int, default=1)
    p = sp.add_parser('one'); p.add_argument('steps')
    p = sp.add_parser('shrink'); p.add_argument('--only', default='')
    sp.add_parser('report')
    a = ap.parse_args()
    {'run': cmd_run, 'one': cmd_one, 'shrink': cmd_shrink, 'report': cmd_report}[a.cmd](a)
