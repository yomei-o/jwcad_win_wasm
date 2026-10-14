// Offline and install: load once online, then with the network off, reload.
//   node tools/web/cdp_pwa.js
const http = require('http'), fs = require('fs'), path = require('path'), cp = require('child_process');
// PWA_DIR=dist/web PWA_PREFIX=/jw/app/ checks a packaged build served under a subpath
const PREFIX = process.env.PWA_PREFIX || '/';
const root = process.env.PWA_DIR ? path.resolve(process.env.PWA_DIR) : path.resolve(__dirname, '..', '..');
const PRIVATE = !process.env.PWA_DIR;
const chrome = process.env.CHROME || ['C:/Program Files/Google/Chrome/Application/chrome.exe',
  'C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe', '/usr/bin/google-chrome', '/usr/bin/chromium'].find(p => fs.existsSync(p));
if (!chrome) { console.log('SKIP no Chrome or Edge found (set CHROME=...)'); process.exit(0); }
const WASM = path.resolve(process.env.WASM_DIR || root);   // where jwcad.js / jwcad.wasm come from
const OUT = path.join(root, 'tmp'); fs.mkdirSync(OUT, { recursive: true });
const PORT = process.env.CDP_PORT || '9334';
const types = { '.html': 'text/html; charset=utf-8', '.js': 'text/javascript', '.wasm': 'application/wasm', '.png': 'image/png', '.webmanifest': 'application/manifest+json', '.svg': 'image/svg+xml' };
let fails = 0;
const check = (c, m) => { console.log((c ? 'ok   ' : 'BAD  ') + m); if (!c) fails++; };
const sleep = ms => new Promise(r => setTimeout(r, ms));
const server = http.createServer((req, res) => {
  let p = decodeURIComponent(req.url.split('?')[0]);
  if (!p.startsWith(PREFIX)) { res.writeHead(404); return res.end(); }   // nothing outside the subpath
  p = '/' + p.slice(PREFIX.length);
  if (p === '/') p = '/index.html';
  let f = path.join(root, p);
  if (PRIVATE && (p === '/jwcad.js' || p === '/jwcad.wasm')) f = path.join(WASM, p);
  if (!f.startsWith(root) || !fs.existsSync(f) || fs.statSync(f).isDirectory()) { res.writeHead(404); return res.end(); }
  res.writeHead(200, { 'content-type': types[path.extname(f)] || 'application/octet-stream' });
  fs.createReadStream(f).pipe(res);
});

  const prof = fs.mkdtempSync(path.join(require('os').tmpdir(), 'jwchrome-'));
(async () => {
  await new Promise(r => server.listen(0, '127.0.0.1', r));
  const port = server.address().port;
  const proc = cp.spawn(chrome, ['--headless=new', '--remote-debugging-port=9338', '--user-data-dir=' + prof, '--no-first-run', '--disable-gpu', 'about:blank'], { stdio: 'ignore' });
  let targets;
  for (let i = 0; i < 50; i++) { try { targets = await (await fetch('http://127.0.0.1:9338/json')).json(); if (targets.length) break; } catch (e) {} await sleep(200); }
  const ws = new WebSocket(targets.find(t => t.type === 'page').webSocketDebuggerUrl);
  await new Promise(r => ws.onopen = r);
  let id = 0; const waiting = new Map();
  ws.onmessage = e => { const m = JSON.parse(e.data); if (m.id && waiting.has(m.id)) { waiting.get(m.id)(m); waiting.delete(m.id); } };
  const send = (method, params = {}) => new Promise(r => { const n = ++id; waiting.set(n, r); ws.send(JSON.stringify({ id: n, method, params })); });
  const ev = async expr => (await send('Runtime.evaluate', { expression: expr, returnByValue: true, awaitPromise: true })).result.result.value;
  try {
    await send('Page.enable'); await send('Runtime.enable'); await send('Network.enable');
    const url = 'http://127.0.0.1:' + port + PREFIX + '?debug';
    const nav = await send('Page.navigate', { url }); console.log('     navigate:', JSON.stringify(nav.result));
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(1500);
    const reg = await ev("navigator.serviceWorker.ready.then(r => !!r.active)");
    check(reg === true, 'the service worker is registered and active');
    // the first visit is enough: network off at once, reload, and it still comes up
    await send('Network.emulateNetworkConditions', { offline: true, latency: 0, downloadThroughput: 0, uploadThroughput: 0 });
    await send('Page.reload');
    let first = false;
    for (let i = 0; i < 50 && !first; i++) { await sleep(200); try { first = await ev('!!window.__jw'); } catch (e) {} }
    check(first, 'offline right after the first visit: the page loads');
    check(await ev("fetch('fonts/jwsubgothic.ttf').then(r => r.ok).catch(() => false)"), 'and a font that was never asked for is there too');
    await send('Network.emulateNetworkConditions', { offline: false, latency: 0, downloadThroughput: -1, uploadThroughput: -1 });
    // the worker takes control on the next load; load once more online so every file is kept
    await send('Page.reload');
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(1500);
    check(await ev('!!navigator.serviceWorker.controller'), 'the page is under the worker');
    const keys = await ev("caches.keys().then(ks => caches.open(ks.find(k => k.startsWith('jw-port-')))).then(c => c.keys()).then(k => k.map(r => new URL(r.url).pathname))");
    console.log('     kept:', keys.join(' '));
    check(keys.some(k => k.endsWith('/jwcad.wasm')) && keys.some(k => k.endsWith('/jwcad.js')), 'the program files are kept');
    check(keys.every(k => k.startsWith(PREFIX)), 'and everything kept is under ' + PREFIX);
    check((await ev('navigator.serviceWorker.getRegistration().then(r => new URL(r.scope).pathname)')) === PREFIX, 'the worker scope is ' + PREFIX);
    console.log('     icon fetch:', await ev("fetch('icon-192.png').then(r => r.status + ' ' + r.headers.get('content-type'))"), await ev("fetch('manifest.webmanifest').then(r => r.status + ' ' + r.headers.get('content-type'))"));
    await sleep(2000);
    console.log('     decode:', await ev("fetch('icon-192.png').then(r => r.blob()).then(b => createImageBitmap(b)).then(i => i.width + 'x' + i.height).catch(e => String(e))"));
    const inst = await send('Page.getInstallabilityErrors');
    const errs = (inst.result && inst.result.installabilityErrors || []).map(e => e.errorId);
    check(errs.length === 0, 'installable: ' + (JSON.stringify(inst.result) || 'no errors'));
    // the network off
    await send('Network.emulateNetworkConditions', { offline: true, latency: 0, downloadThroughput: 0, uploadThroughput: 0 });
    await send('Page.reload');
    let ok = false;
    for (let i = 0; i < 50 && !ok; i++) { await sleep(200); try { ok = await ev('!!window.__jw'); } catch (e) {} }
    await sleep(1500);
    check(ok, 'offline: the page and the program load again');
    const ink = await ev("(() => { const c = document.getElementById('screen'); const d = c.getContext('2d').getImageData(0,0,c.width,c.height).data; let n = 0; for (let i = 0; i < d.length; i += 4) if (d[i] !== 255 || d[i+1] !== 255 || d[i+2] !== 255) n++; return n; })()");
    check(ink > 1000, 'offline: the screen is painted (' + ink + ')');
    const fonts = await ev("fetch('fonts/' + 'x').then(r => r.status).catch(() => 'fail')");
    console.log('     (a font never fetched online is not there offline: ' + fonts + ')');
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
