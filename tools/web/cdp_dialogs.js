// The settings dialogs, probed from the page: what Esc throws away, what Enter keeps.
//   node tools/web/cdp_dialogs.js
// Serves the repo root, but with the wasm built in tmp/features_wasm, then
// drives Chrome over the DevTools protocol (node's built-in WebSocket).
const http = require('http'), fs = require('fs'), path = require('path'), cp = require('child_process');
const root = path.resolve(__dirname, '..', '..');
const chrome = process.env.CHROME || ['C:/Program Files/Google/Chrome/Application/chrome.exe',
  'C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe', '/usr/bin/google-chrome', '/usr/bin/chromium'].find(p => fs.existsSync(p));
if (!chrome) { console.log('SKIP no Chrome or Edge found (set CHROME=...)'); process.exit(0); }
const WASM = path.resolve(process.env.WASM_DIR || root);   // where jwcad.js / jwcad.wasm come from
const OUT = path.join(root, 'tmp'); fs.mkdirSync(OUT, { recursive: true });
const PORT = process.env.CDP_PORT || '9334';
const types = { '.html': 'text/html; charset=utf-8', '.js': 'text/javascript', '.wasm': 'application/wasm', '.png': 'image/png' };
let fails = 0;
const check = (c, m) => { console.log((c ? 'ok   ' : 'BAD  ') + m); if (!c) fails++; };
const sleep = ms => new Promise(r => setTimeout(r, ms));

const server = http.createServer((req, res) => {
  let p = decodeURIComponent(req.url.split('?')[0]);
  if (p === '/') p = '/index.html';
  let f = path.join(root, p);
  if (p === '/jwcad.js' || p === '/jwcad.wasm') f = path.join(WASM, p);
  if (!f.startsWith(root) || !fs.existsSync(f) || fs.statSync(f).isDirectory()) { res.writeHead(404); return res.end(); }
  res.writeHead(200, { 'content-type': types[path.extname(f)] || 'application/octet-stream' });
  fs.createReadStream(f).pipe(res);
});

(async () => {
  await new Promise(r => server.listen(0, '127.0.0.1', r));
  const port = server.address().port;
  const prof = fs.mkdtempSync(path.join(require('os').tmpdir(), 'jwchrome-'));
  const proc = cp.spawn(chrome, ['--headless=new', '--remote-debugging-port=' + PORT + '', '--user-data-dir=' + prof,
    '--no-first-run', '--disable-gpu', '--window-size=1400,900', 'about:blank'], { stdio: 'ignore' });
  let targets;
  for (let i = 0; i < 50; i++) {
    try { targets = await (await fetch('http://127.0.0.1:' + PORT + '/json')).json(); if (targets.length) break; } catch (e) {}
    await sleep(200);
  }
  const page = targets.find(t => t.type === 'page');
  const ws = new WebSocket(page.webSocketDebuggerUrl);
  await new Promise(r => ws.onopen = r);
  let id = 0; const waiting = new Map();
  const jsErrors = [];
  ws.onmessage = ev => { const m = JSON.parse(ev.data); if (m.method === 'Runtime.exceptionThrown') jsErrors.push(JSON.stringify(m.params.exceptionDetails.exception && m.params.exceptionDetails.exception.description || m.params.exceptionDetails.text)); if (m.id && waiting.has(m.id)) { waiting.get(m.id)(m); waiting.delete(m.id); } };
  const send = (method, params = {}) => new Promise(r => { const n = ++id; waiting.set(n, r); ws.send(JSON.stringify({ id: n, method, params })); });
  const ev = async expr => (await send('Runtime.evaluate', { expression: expr, returnByValue: true, awaitPromise: true })).result.result.value;
  const shot = async () => (await send('Page.captureScreenshot', { format: 'png' })).result.data;
  const mouse = (type, x, y, extra = {}) => send('Input.dispatchMouseEvent', Object.assign({ type, x, y, button: 'left', clickCount: 1 }, extra));

  // The page-side probe: opens the dialog, finds its controls by pressing a grid of points and seeing what the picture
  // does, then checks what OK (Enter) keeps and what Esc throws away.
  const PROBE = `(async (id, step, maxCtl) => {
    const m = window.__jw;
    const W = () => m._jw_width(), H = () => m._jw_height();
    const px = () => new Uint32Array(m.HEAPU8.buffer, m._jw_rgba(), W() * H());
    const hashR = r => { const a = px(), w = W(); let h = 2166136261 >>> 0; for (let y = r.y0; y < r.y1; y++) { const o = y * w; for (let x = r.x0; x < r.x1; x++) h = Math.imul(h ^ a[o + x], 16777619) >>> 0; } return h; };
    const closeAll = () => { for (let k = 0; k < 4 && m._jw_modal(); k++) m._jw_key(27); };
    const open = () => { closeAll(); m._jw_command(id); return m._jw_modal(); };
    const press = (x, y) => { m._jw_press(x, y, 0); m._jw_release(x, y); };
    const res = { id, ok: true, notes: [], controls: [] };
    closeAll();
    const w = W(), h = H(), ch = m._jw_chrome_h();
    const closed = px().slice();
    if (!open()) { res.ok = false; res.notes.push('does not open'); return res; }
    const opened = px();
    let x0 = w, y0 = h, x1 = 0, y1 = 0;
    for (let y = ch; y < h; y++) for (let x = 0; x < w; x++) if (opened[y * w + x] !== closed[y * w + x]) { if (x < x0) x0 = x; if (x > x1) x1 = x; if (y < y0) y0 = y; if (y > y1) y1 = y; }
    if (x1 <= x0) { res.notes.push('no visible change when opened'); return res; }
    const R = { x0: Math.max(0, x0 - 2), y0: Math.max(ch, y0 - 2), x1: Math.min(w, x1 + 3), y1: Math.min(h, y1 + 3) };
    res.rect = [R.x0, R.y0, R.x1, R.y1];
    const S0 = hashR(R);
    // 1. what each point does
    const seen = new Map();            // hash after the press -> first point
    let closers = 0;
    for (let y = R.y0 + 3; y < R.y1 - 2; y += step) for (let x = R.x0 + 3; x < R.x1 - 2; x += step) {
      if (!m._jw_modal()) open();
      const before = hashR(R);
      press(x, y);
      if (!m._jw_modal()) { closers++; open(); continue; }
      const after = hashR(R);
      if (after !== before && !seen.has(before + ':' + after)) seen.set(before + ':' + after, [x, y, before, after]);
      if (after !== before && after !== S0) { open(); }       // go back to the pristine dialog for the next point
    }
    res.closers = closers;
    const reps = []; const used = new Set();
    for (const [, v] of seen) { if (v[2] !== S0) continue; if (used.has(v[3])) continue; used.add(v[3]); reps.push(v); }
    res.nchanging = reps.length;
    for (const [x, y] of reps.slice(0, maxCtl)) {
      const c = { x, y };
      // Esc: the change must be thrown away
      open(); const a0 = hashR(R); press(x, y); const a1 = hashR(R);
      m._jw_key(27); const closedEsc = !m._jw_modal();
      open(); const a2 = hashR(R);
      c.changed = a1 !== a0; c.escClosed = closedEsc; c.escReverts = a2 === a0;
      // Enter: OK; what comes back when it is opened again
      open(); const b0 = hashR(R); press(x, y); const b1 = hashR(R);
      m._jw_key(13); if (m._jw_modal()) m._jw_key(13);     // the first Enter may only be taking what was typed in a box
      c.enterClosed = !m._jw_modal();
      open(); const b2 = hashR(R);
      c.enterKeeps = b2 === b1 && b1 !== b0; c.enterReverts = b2 === b0;
      // put it back the way it was: press again and OK
      press(x, y); m._jw_key(13); if (m._jw_modal()) m._jw_key(13);
      res.controls.push(c);
    }
    closeAll();
    return res;
  })`;
  // live: changes apply at once (Esc keeps them); pick: the dialog is a chooser that closes by itself (no OK to press)
  const DIALOGS = [['線属性', 32807, 'pick'], ['基本設定', 32891], ['寸法設定', 32925], ['軸角・目盛・オフセット', 32842], ['レイヤ', 32808, 'live'], ['画面倍率・文字表示', 32811], ['縮尺・読取', 32944]];
  const only = process.env.DLG ? process.env.DLG.split(',').map(Number) : null;
  try {
    await send('Page.enable'); await send('Runtime.enable');
    await send('Emulation.setDeviceMetricsOverride', { width: 1264, height: 903, deviceScaleFactor: 1, mobile: false });
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(800);
    const doc = (await send('DOM.getDocument')).result.root.nodeId;
    const inp = (await send('DOM.querySelector', { nodeId: doc, selector: '#pick' })).result.nodeId;
    await send('DOM.setFileInputFiles', { nodeId: inp, files: [path.normalize(path.join(root, 'orig', 'Test1.jww'))] });
    await sleep(800);
    for (const [name, cid, kind] of DIALOGS) {
      if (only && !only.includes(cid)) continue;
      const t0 = Date.now();
      const r = await ev(PROBE + '(' + cid + ', ' + (process.env.STEP || 6) + ', ' + (process.env.MAXCTL || 30) + ')');
      const cs = r.controls || [];
      const esc = cs.filter(c => c.changed);
      console.log('     ' + name + ' (' + cid + '): ' + (r.rect ? 'rect ' + r.rect.join(',') : '') + ', ' + r.nchanging + ' controls change the picture, '
        + cs.filter(c => c.enterKeeps).length + ' kept by Enter, ' + cs.filter(c => c.enterReverts).length + ' not kept, '
        + 'closers hit ' + r.closers + ' times (' + ((Date.now() - t0) / 1000).toFixed(0) + ' s)' + (r.notes.length ? ' ' + r.notes.join('; ') : ''));
      check(r.ok && !!r.rect, name + ' opens and paints');
      check(esc.every(c => c.escClosed), name + ': Esc closes the dialog');
      if (kind !== 'live') check(esc.every(c => c.escReverts), name + ': Esc throws away every change (' + esc.filter(c => !c.escReverts).map(c => c.x + ',' + c.y).join(' ') + ')');
      if (kind !== 'pick') check(cs.every(c => c.enterClosed), name + ': Enter closes the dialog');
      check(jsErrors.length === 0, name + ': no script errors ' + jsErrors.slice(0, 1).join('|'));
      if (kind !== 'pick') check(cs.filter(c => c.enterKeeps).length >= 1, name + ': what is ticked is still ticked after OK and reopening (' + cs.filter(c => c.enterKeeps).length + ' of ' + cs.length + ' controls; the rest are tab headers, list rows and text carets)');
      const odd = cs.filter(c => c.changed && !c.enterKeeps && !c.enterReverts);
      if (odd.length) console.log('     ' + name + ': Enter then reopen gives neither the new nor the old picture at ' + odd.map(c => c.x + ',' + c.y).join(' '));
      if (process.env.VERBOSE) console.log(JSON.stringify(cs));
    }
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
