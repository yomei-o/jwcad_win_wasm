// Frame rate and latency of the browser build on the biggest drawings.
//   node tools/web/cdp_perf.js [limit-ms]
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

  const LIMIT = +(process.argv[2] || process.env.PERF_LIMIT_MS || 40);     // a generous bound on a slow or loaded machine
  const files = (process.env.PERF_FILES ? process.env.PERF_FILES.split(',') : ['orig/天空率表.jww', 'orig/Test7.jww']);
  // In the page: run `n` frames of `step(i)`, one per animation frame, and say how long each frame took
  // (rAF to rAF, which is what the eye sees) -- the mean, the 95th percentile and the worst.
  const frames = `(async (kind, n) => {
    const c = document.getElementById('screen');
    const r = c.getBoundingClientRect();
    const cx = r.left + r.width / 2, cy = r.top + r.height / 2;
    const step = {
      wheel: i => c.dispatchEvent(new WheelEvent('wheel', { deltaY: i % 2 ? 120 : -120, clientX: cx + (i % 7) * 5, clientY: cy, bubbles: true, cancelable: true })),
      pan: i => {
        const o = { pointerId: 7, pointerType: 'mouse', button: 2, buttons: 2, bubbles: true, cancelable: true };
        if (i === 0) c.dispatchEvent(new PointerEvent('pointerdown', Object.assign({ clientX: cx, clientY: cy }, o)));
        c.dispatchEvent(new PointerEvent('pointermove', Object.assign({ clientX: cx + (i % 40) * 4, clientY: cy + (i % 30) * 3 }, o)));
        if (i === n - 1) c.dispatchEvent(new PointerEvent('pointerup', Object.assign({ clientX: cx, clientY: cy }, o)));
      },
    }[kind];
    const t = [];
    let last = await new Promise(res => requestAnimationFrame(res));
    for (let i = 0; i < n; i++) {
      step(i);
      const now = await new Promise(res => requestAnimationFrame(res));
      t.push(now - last); last = now;
    }
    t.sort((a, b) => a - b);
    return [t.reduce((a, b) => a + b, 0) / n, t[Math.floor(n * 0.95)], t[n - 1]];
  })`;
  // pick latency: the time of one pointer move (hit test / snap search) with the command in force, in wasm
  const latency = `((cmd, n) => {
    const m = window.__jw, r = document.getElementById('screen').getBoundingClientRect();
    m._jw_command(cmd);
    const t = [];
    for (let i = 0; i < n; i++) {
      const x = 100 + (i * 37) % 900, y = 120 + (i * 53) % 500;
      const a = performance.now();
      m._jw_move(x, y);
      t.push(performance.now() - a);
    }
    t.sort((a, b) => a - b);
    return [t.reduce((a, b) => a + b, 0) / n, t[Math.floor(n * 0.95)], t[n - 1]];
  })`;
  const fmt = a => a.map(v => v.toFixed(1)).join(' / ');
  try {
    await send('Page.enable');
    await send('Runtime.enable');
    await send('Emulation.setDeviceMetricsOverride', { width: 1264, height: 903, deviceScaleFactor: 1, mobile: false });
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(1000);
    for (const f of files) {
      const fp = path.join(root, f);
      if (!fs.existsSync(fp)) continue;
      const doc = (await send('DOM.getDocument')).result.root.nodeId;
      const inp = (await send('DOM.querySelector', { nodeId: doc, selector: '#pick' })).result.nodeId;
      await send('DOM.setFileInputFiles', { nodeId: inp, files: [path.normalize(fp)] });
      await sleep(1500);
      const tag = path.basename(f);
      const nobj = await ev('window.__jw._jw_nobj()');
      console.log('     ' + tag + ': ' + nobj + ' elements');
      const w = await ev(frames + "('wheel', 90)");
      console.log('     ' + tag + ' wheel zoom, ms per frame (mean / 95th / worst): ' + fmt(w));
      // drag pan with the real right button (CDP input events), while a recorder notes every animation frame
      await ev("window.__rec = []; window.__recOn = true; (function f(t) { if (!window.__recOn) return; window.__rec.push(t); requestAnimationFrame(f); })(0); 0");
      const b0 = await ev("(() => { const b = document.getElementById('screen').getBoundingClientRect(); return [b.left + b.width / 2, b.top + b.height / 2]; })()");
      await mouse('mousePressed', b0[0], b0[1], { button: 'right', buttons: 2 });
      for (let i = 1; i <= 120; i++) { await mouse('mouseMoved', b0[0] + (i % 40) * 4, b0[1] + (i % 30) * 3, { button: 'right', buttons: 2 }); if (i % 2) await sleep(8); }
      await mouse('mouseReleased', b0[0], b0[1], { button: 'right', buttons: 0 });
      const rec = await ev("(() => { window.__recOn = false; return window.__rec; })()");
      const dts = []; for (let i = 2; i < rec.length; i++) dts.push(rec[i] - rec[i - 1]);
      dts.sort((x, y) => x - y);
      const p = [dts.reduce((x, y) => x + y, 0) / dts.length, dts[Math.floor(dts.length * 0.95)], dts[dts.length - 1]];
      console.log('     ' + tag + ' drag pan, ms per frame (mean / 95th / worst): ' + fmt(p));
      // the work of one frame, undisturbed by vsync: wasm repaint after a zoom step, and handing it to the canvas
      const cost = await ev("(() => { const m = window.__jw, c = document.getElementById('screen'), ctx = c.getContext('2d'); const t = [], u = []; for (let i = 0; i < 60; i++) { let a = performance.now(); m._jw_zoom(i % 2 ? 0.8 : 1.25, 600, 400); const b = performance.now(); const w = m._jw_width(), h = m._jw_height(); const img = new ImageData(new Uint8ClampedArray(m.HEAPU8.buffer, m._jw_rgba(), w * h * 4), w, h); ctx.putImageData(img, 0, 0); u.push(performance.now() - b); t.push(b - a); } const f = x => { x.sort((p, q) => p - q); return [x.reduce((p, q) => p + q, 0) / x.length, x[Math.floor(x.length * 0.95)], x[x.length - 1]]; }; return [f(t), f(u)]; })()");
      console.log('     ' + tag + ' one zoom step, ms (mean / 95th / worst): paint in wasm ' + fmt(cost[0]) + ', putImageData ' + fmt(cost[1]));
      check(cost[0][1] + cost[1][1] < LIMIT, tag + ': a zoom step (paint + present) is well inside a frame budget (' + (cost[0][1] + cost[1][1]).toFixed(1) + ' ms at the 95th percentile)');
      for (const [cmd, nm] of [[32771, '線'], [32787, '範囲選択']]) {
        const l = await ev(latency + '(' + cmd + ', 200)');
        console.log('     ' + tag + ' pointer move under ' + nm + ' (' + cmd + '), ms (mean / 95th / worst): ' + fmt(l));
        check(l[1] < LIMIT, tag + ' ' + nm + ': pointer move 95th percentile under ' + LIMIT + ' ms (' + l[1].toFixed(1) + ')');
      }
      // the drawing must keep up with the hand: a frame of a sustained zoom/pan stays well under a second
      check(w[0] < 4 * LIMIT && p[0] < 4 * LIMIT, tag + ': zoom and pan frames are not stuck (' + w[0].toFixed(1) + ', ' + p[0].toFixed(1) + ' ms mean)');
      check(w[0] < 17 * 1.5 || process.env.PERF_STRICT !== '1', tag + ': zoom keeps 60 fps (strict mode only)');
    }
    check(jsErrors.length === 0, 'no script errors ' + jsErrors.slice(0, 2).join('|'));
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
