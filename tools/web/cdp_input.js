// The right button where there is none: Shift/Ctrl+click and a long press.
//   node tools/web/cdp_input.js
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

  const canvasData = () => ev(`(() => { const c = document.getElementById('screen'); return c.toDataURL(); })()`);
  const load = async () => {
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(700);
    const doc = (await send('DOM.getDocument')).result.root.nodeId;
    const inp = (await send('DOM.querySelector', { nodeId: doc, selector: '#pick' })).result.nodeId;
    await send('DOM.setFileInputFiles', { nodeId: inp, files: [path.normalize(path.join(root, 'orig', 'Test1.jww'))] });
    await sleep(700);
  };
  try {
    await send('Page.enable'); await send('Runtime.enable');
    await send('Emulation.setDeviceMetricsOverride', { width: 1264, height: 903, deviceScaleFactor: 1, mobile: false });
    // The layer-group grid: the right button makes a group the one written to, the left one only cycles its display.  A
    // browser with no right button has to reach the same thing: Shift+click (mouse) and a long press (finger).
    const X = +(process.env.GX || 1207), Y = 51 + +(process.env.GY || 520);
    await load();
    const base = await canvasData();
    await mouse('mousePressed', X, Y, { button: 'left', buttons: 1 }); await mouse('mouseReleased', X, Y, { button: 'left', buttons: 0 });
    const left = await canvasData();
        await load();
    await mouse('mousePressed', X, Y, { button: 'right', buttons: 2 }); await mouse('mouseReleased', X, Y, { button: 'right', buttons: 0 });
    const right = await canvasData();
    check(right !== base && right !== left, 'a right click on the layer-group grid does something else than a left click');
    await load();
    await mouse('mousePressed', X, Y, { button: 'left', buttons: 1, modifiers: 8 }); await mouse('mouseReleased', X, Y, { button: 'left', buttons: 0, modifiers: 8 });
    check(await canvasData() === right, 'Shift+click is the right button');
    await load();
    await mouse('mousePressed', X, Y, { button: 'left', buttons: 1, modifiers: 2 }); await mouse('mouseReleased', X, Y, { button: 'left', buttons: 0, modifiers: 2 });
    check(await canvasData() === right, 'Ctrl+click is the right button');
    await load();
    await send('Emulation.setEmitTouchEventsForMouse', { enabled: false });
    await send('Input.dispatchTouchEvent', { type: 'touchStart', touchPoints: [{ x: X, y: Y, id: 1 }] });
    await sleep(700);
    await send('Input.dispatchTouchEvent', { type: 'touchEnd', touchPoints: [] });
    await sleep(100);
    check(await canvasData() === right, 'a long press with one finger is the right button');
    await load();
    await send('Input.dispatchTouchEvent', { type: 'touchStart', touchPoints: [{ x: X, y: Y, id: 1 }] });
    await sleep(60);
    await send('Input.dispatchTouchEvent', { type: 'touchEnd', touchPoints: [] });
    await sleep(100);
    check(await canvasData() === left, 'a short tap with one finger is still the left button (it does not do what the right one does)');
    check(jsErrors.length === 0, 'no script errors ' + jsErrors.slice(0, 2).join('|'));
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
