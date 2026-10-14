// save and reload
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
  const proc = cp.spawn(chrome, ['--headless=new', '--remote-debugging-port=9342', '--user-data-dir=' + prof, '--no-first-run', '--disable-gpu', 'about:blank'], { stdio: 'ignore' });
  let targets;
  for (let i = 0; i < 50; i++) { try { targets = await (await fetch('http://127.0.0.1:9342/json')).json(); if (targets.length) break; } catch (e) {} await sleep(200); }
  const ws = new WebSocket(targets.find(t => t.type === 'page').webSocketDebuggerUrl);
  await new Promise(r => ws.onopen = r);
  let id = 0; const waiting = new Map(); const jsErrors = [];
  ws.onmessage = e => { const m = JSON.parse(e.data); if (m.id && waiting.has(m.id)) { waiting.get(m.id)(m); waiting.delete(m.id); } if (m.method === 'Runtime.exceptionThrown') jsErrors.push(JSON.stringify(m.params.exceptionDetails.text)); };
  const send = (method, params = {}) => new Promise(r => { const n = ++id; waiting.set(n, r); ws.send(JSON.stringify({ id: n, method, params })); });
  const ev = async expr => (await send('Runtime.evaluate', { expression: expr, returnByValue: true, awaitPromise: true })).result.result.value;
  const shot = async name => { const d = (await send('Page.captureScreenshot', { format: 'png' })).result.data; fs.writeFileSync(path.join(OUT, name), Buffer.from(d, 'base64')); return d; };
  try {
    await send('Page.enable'); await send('Runtime.enable');
    await send('Emulation.setDeviceMetricsOverride', { width: 1400, height: 900, deviceScaleFactor: 1, mobile: false });
    await send('Page.addScriptToEvaluateOnNewDocument', { source: 'delete window.showSaveFilePicker; delete window.showOpenFilePicker;' });
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug&lang=en' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(1000);
    const doc = (await send('DOM.getDocument')).result.root.nodeId;
    const inp = (await send('DOM.querySelector', { nodeId: doc, selector: '#pick' })).result.nodeId;
    await send('DOM.setFileInputFiles', { nodeId: inp, files: [path.normalize(path.join(root, 'orig', 'Test1.jww'))] });
    await sleep(1200);
    const txt = id => ev("document.getElementById('" + id + "').textContent.trim()");
    check(await ev("document.documentElement.lang") === 'en', 'the page says it is English');
    check((await txt('dxf')) === 'Save as DXF' && (await txt('pdf')) === 'Print to PDF', 'the buttons are in English: ' + await txt('dxf') + ' / ' + await txt('pdf'));
    check(/elements/.test(await txt('msg')), 'the message after opening a file is English: ' + await txt('msg'));
    check(/Wheel zooms/.test(await ev("document.getElementById('note').textContent")), 'the hint line is English');
    check(/rewritten in C/.test(await ev("document.querySelector('header').textContent")), 'the header is English');
    check(await ev("document.getElementById('screen').getAttribute('aria-label')") .then(x => /Jw_cad drawing/.test(x)), 'the drawing area label is English');
    // the original's own strings stay Japanese: the status line of the frame is drawn by the port
    check(await ev("localStorage.getItem('jw.lang')") === 'en', 'the choice is remembered');
    // the other way, by the link, back to Japanese
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug&lang=ja' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(500);
    check((await txt('dxf')) === 'DXF で保存', 'lang=ja brings the Japanese back: ' + await txt('dxf'));
    // a reload with nothing in the address keeps what was chosen last
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug&lang=en' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(500);
    check((await txt('sfc')) === 'Save as SFC', 'no lang in the address: the last choice is kept');
    check(jsErrors.length === 0, 'no script errors ' + jsErrors.join('|'));
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
