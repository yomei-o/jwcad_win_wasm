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
  const proc = cp.spawn(chrome, ['--headless=new', '--remote-debugging-port=9341', '--user-data-dir=' + prof, '--no-first-run', '--disable-gpu', 'about:blank'], { stdio: 'ignore' });
  let targets;
  for (let i = 0; i < 50; i++) { try { targets = await (await fetch('http://127.0.0.1:9341/json')).json(); if (targets.length) break; } catch (e) {} await sleep(200); }
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
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug&autosave=1' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(1000);
    const doc = (await send('DOM.getDocument')).result.root.nodeId;
    const inp = (await send('DOM.querySelector', { nodeId: doc, selector: '#pick' })).result.nodeId;
    await send('DOM.setFileInputFiles', { nodeId: inp, files: [path.normalize(path.join(root, 'orig', 'Test1.jww'))] });
    await sleep(1200);
    ws.addEventListener('message', e => { const m = JSON.parse(e.data); if (m.method === 'Page.javascriptDialogOpening') send('Page.handleJavaScriptDialog', { accept: true }); });   // the leave-page warning
    const dl = fs.mkdtempSync(path.join(require('os').tmpdir(), 'jwdl-'));
    await send('Browser.setDownloadBehavior', { behavior: 'allow', downloadPath: dl });
    const mouse = (type, x, y, extra = {}) => send('Input.dispatchMouseEvent', Object.assign({ type, x, y, button: 'left', clickCount: 1 }, extra));
    const click = async (x, y) => { await mouse('mouseMoved', x, y, { button: 'none', clickCount: 0 }); await mouse('mousePressed', x, y); await mouse('mouseReleased', x, y); await sleep(120); };
    const r = await ev("(() => { const b = document.getElementById('screen').getBoundingClientRect(); return [b.left, b.top]; })()");
    const rec = () => ev("new Promise(ok => { const q = indexedDB.open('jw_autosave', 1); q.onsuccess = () => { const g = q.result.transaction('d').objectStore('d').get('last'); g.onsuccess = () => { ok(g.result ? g.result.bytes.length + ':' + g.result.name : ''); q.result.close(); }; g.onerror = () => ok('err'); }; q.onerror = () => ok('err'); })");
    const reload = async () => { await send('Page.reload'); for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; } await sleep(800); };
    const loadTest1 = async () => {
      const d2 = (await send('DOM.getDocument')).result.root.nodeId;
      const i2 = (await send('DOM.querySelector', { nodeId: d2, selector: '#pick' })).result.nodeId;
      await send('DOM.setFileInputFiles', { nodeId: i2, files: [path.normalize(path.join(root, 'orig', 'Test1.jww'))] });
      await sleep(1000);
    };
    check((await rec()) === '', 'nothing is kept at the start');
    const n0 = await ev('window.__jw._jw_nobj()');
    // an unchanged drawing leaves no copy
    await sleep(2500);
    check((await rec()) === '', 'an unchanged drawing leaves no copy');
    // two lines: a copy appears within a couple of seconds
    for (const [x0, y0, x1, y1] of [[300, 300, 700, 350], [300, 400, 700, 450]])
      for (const [x, y] of [[x0, y0], [x1, y1]]) await click(r[0] + x, r[1] + y);
    check(await ev('window.__jw._jw_nobj()') === n0 + 2, 'two lines drawn');
    let got = '';
    for (let i = 0; i < 20 && !got; i++) { await sleep(300); got = await rec(); }
    check(/^\d+:Test1\.jww$/.test(got), 'a copy is kept in IndexedDB (' + got + ')');
    // the tab dies: reload; the bar offers it back
    const nBefore = await ev('window.__jw._jw_nobj()');
    await reload();
    check(await ev("!!document.getElementById('recover')"), 'after a reload the page offers to bring it back');
    const text = await ev("document.getElementById('recover').textContent");
    check(/Test1\.jww/.test(text), 'and names it: ' + text.slice(0, 60));
    await ev("[...document.querySelectorAll('#recover button')].find(b => b.textContent === '復元').click()");
    await sleep(800);
    const nAfter = await ev('window.__jw._jw_nobj()');
    check(nAfter >= nBefore && nAfter - nBefore <= 8, 'Restore brings back the drawing (' + nAfter + ' elements, ' + nBefore + ' before: a saved file carries a few hidden ones more)');
    check(await ev('window.__jw._jw_modified()') === 1, 'and the drawing counts as changed');
    check(!(await ev("!!document.getElementById('recover')")), 'the bar goes away');
    // saving it (Ctrl+S, a download) removes the copy at the next tick
    await send('Input.dispatchKeyEvent', { type: 'keyDown', key: 's', code: 'KeyS', windowsVirtualKeyCode: 83, modifiers: 2 });
    await send('Input.dispatchKeyEvent', { type: 'keyUp', key: 's', code: 'KeyS', windowsVirtualKeyCode: 83, modifiers: 2 });
    let gone = false;
    for (let i = 0; i < 20 && !gone; i++) { await sleep(300); gone = (await rec()) === ''; }
    check(gone, 'a saved drawing takes its copy away');
    // discard: draw again, reload, press 破棄
    for (const [x, y] of [[300, 500], [700, 540]]) await click(r[0] + x, r[1] + y);
    got = '';
    for (let i = 0; i < 20 && !got; i++) { await sleep(300); got = await rec(); }
    check(got !== '', 'a new change makes a new copy');
    await reload();
    await ev("[...document.querySelectorAll('#recover button')].find(b => b.textContent === '破棄').click()");
    await sleep(500);
    check((await rec()) === '', 'Discard deletes it');
    check(jsErrors.length === 0, 'no script errors ' + jsErrors.join('|'));
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
