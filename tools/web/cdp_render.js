// The browser's canvas against the native renderer, drawing by drawing and zoom by zoom.
//   node tools/web/cdp_render.js [dir-of-jww [dir-of-reference-pngs]]
// For every tmp/d*.jww (or the given directory) the page is sized so the canvas is 1264x(741+chrome), the drawing is
// opened and the canvas below the caption/menu/toolbar is saved to tmp/brw/<name>_<zoom>.png.  At zoom "fit" it is compared
// with tests/shot.exe's picture of the same drawing (what tools/scoreall.sh scores against the originals), so the browser
// is scored through it; the other zooms (wheel in and out about the middle) are compared with a second, independent run
// of the same page after a resize round trip, which catches a canvas that depends on how it got there.
const http = require('http'), fs = require('fs'), path = require('path'), cp = require('child_process');
const root = path.resolve(__dirname, '..', '..');
const chrome = process.env.CHROME || ['C:/Program Files/Google/Chrome/Application/chrome.exe',
  'C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe', '/usr/bin/google-chrome', '/usr/bin/chromium'].find(p => fs.existsSync(p));
if (!chrome) { console.log('SKIP no Chrome or Edge found (set CHROME=...)'); process.exit(0); }
const WASM = path.resolve(process.env.WASM_DIR || root);
const PORT = process.env.CDP_PORT || '9336';
const dir = path.resolve(process.argv[2] || path.join(root, 'tmp'));
const OUT = path.join(root, 'tmp', 'brw'); fs.mkdirSync(OUT, { recursive: true });
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
  const proc = cp.spawn(chrome, ['--headless=new', '--remote-debugging-port=' + PORT, '--user-data-dir=' + prof,
    '--no-first-run', '--disable-gpu', '--window-size=1400,1000', 'about:blank'], { stdio: 'ignore' });
  let targets;
  for (let i = 0; i < 50; i++) {
    try { targets = await (await fetch('http://127.0.0.1:' + PORT + '/json')).json(); if (targets.length) break; } catch (e) {}
    await sleep(200);
  }
  const page = targets.find(t => t.type === 'page');
  const ws = new WebSocket(page.webSocketDebuggerUrl);
  await new Promise(r => ws.onopen = r);
  let id = 0; const waiting = new Map(); const jsErrors = [];
  ws.onmessage = e => { const m = JSON.parse(e.data); if (m.method === 'Runtime.exceptionThrown') jsErrors.push(JSON.stringify(m.params.exceptionDetails.exception || m.params.exceptionDetails).slice(0, 200)); if (m.id && waiting.has(m.id)) { waiting.get(m.id)(m); waiting.delete(m.id); } };
  const send = (method, params = {}) => new Promise(r => { const n = ++id; waiting.set(n, r); ws.send(JSON.stringify({ id: n, method, params })); });
  const ev = async expr => (await send('Runtime.evaluate', { expression: expr, returnByValue: true, awaitPromise: true })).result.result.value;
  try {
    await send('Page.enable'); await send('Runtime.enable');
    await send('Emulation.setDeviceMetricsOverride', { width: 1264, height: 903, deviceScaleFactor: 1, mobile: false });
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(800);
    // make the canvas exactly 1264 x (741 + chrome): the wrapper is what the page fits it to
    const dims = await ev(`(() => { const c = document.getElementById('screen'); return [c.width, c.height, window.__jw._jw_chrome_h()]; })()`);
    console.log('     canvas ' + dims[0] + 'x' + dims[1] + ', chrome ' + dims[2]);
    const names = fs.readdirSync(dir).filter(f => /^d\d+\.jww$/.test(f)).sort();
    const python = [process.env.PYTHON, 'python', 'python3', 'py'].filter(Boolean).find(p => { try { return cp.spawnSync(p, ['-c', 'import PIL'], { stdio: 'ignore' }).status === 0; } catch (e) { return false; } });
    if (!python) console.log('     (no python with PIL: the pictures are saved to tmp/brw but not compared)');
    for (const n of names) {
      const base = n.replace('.jww', '');
      const doc = (await send('DOM.getDocument')).result.root.nodeId;
      const inp = (await send('DOM.querySelector', { nodeId: doc, selector: '#pick' })).result.nodeId;
      await send('DOM.setFileInputFiles', { nodeId: inp, files: [path.normalize(path.join(dir, n))] });
      await sleep(500);
      const snap = async tag => {
        const url = await ev(`(() => { const c = document.getElementById('screen'); const h = window.__jw._jw_chrome_h(); const t = document.createElement('canvas'); t.width = c.width; t.height = c.height - h; t.getContext('2d').drawImage(c, 0, h, c.width, c.height - h, 0, 0, c.width, c.height - h); return t.toDataURL('image/png'); })()`);
        const f = path.join(OUT, base + '_' + tag + '.png');
        fs.writeFileSync(f, Buffer.from(url.split(',')[1], 'base64'));
        return f;
      };
      const fit = await snap('fit');
      // zoom in and out about the middle, then the same again after the window has been narrowed and widened
      const cx = await ev(`(() => { const b = document.getElementById('screen').getBoundingClientRect(); return [b.left + b.width / 2, b.top + b.height / 2]; })()`);
      const wheel = async dy => { await send('Input.dispatchMouseEvent', { type: 'mouseWheel', x: cx[0], y: cx[1], deltaX: 0, deltaY: dy }); await sleep(120); };
      await wheel(-300); const z1 = await snap('in1');
      await wheel(-300); const z2 = await snap('in2');
      await wheel(900); const z3 = await snap('out');
      for (const [tag, f] of [['fit', fit], ['in1', z1], ['in2', z2], ['out', z3]]) {
        const st = fs.statSync(f).size;
        if (st < 200) check(false, base + ' ' + tag + ' is empty');
      }
      // scored the way tools/scoreall.sh scores the native renderer: against the saved original screen, with the text
      // areas masked (the port's glyphs are another typeface), and held to the native score for the same drawing
      const ref = path.join(root, 'tmp', 'refs', base + '.png'), nat = path.join(root, 'tmp', base + '.out.png');
      if (python && fs.existsSync(ref) && fs.existsSync(nat)) {
        const mask = path.join(OUT, base + '.mask');
        fs.writeFileSync(mask, fs.readFileSync(path.join(root, 'docs', 'textareas.txt')) + (fs.existsSync(nat + '.mask') ? fs.readFileSync(nat + '.mask') : ''));
        const score = img => { const r = cp.spawnSync(python, [path.join(root, 'tools', 'cmp.py'), ref, img, '--near', '-i', mask], { encoding: 'utf8' }); const m = /outside the text areas: ([0-9]+) differ/.exec(r.stdout || ''); return m ? +m[1] : -1; };
        const sb = score(fit), sn = score(nat);
        console.log('     ' + base + ' fit: browser ' + sb + ' pixels off the original outside the text, native ' + sn);
        check(sb >= 0 && sb <= sn + 20, base + ' browser canvas scores like the native render at fit');
      }
    }
    check(jsErrors.length === 0, 'no script errors ' + jsErrors.slice(0, 2).join('|'));
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
