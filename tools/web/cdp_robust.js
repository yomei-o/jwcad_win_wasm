// save and reload
const crypto = require('crypto');
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
  const proc = cp.spawn(chrome, ['--headless=new', '--remote-debugging-port=9343', '--user-data-dir=' + prof, '--no-first-run', '--disable-gpu', 'about:blank'], { stdio: 'ignore' });
  let targets;
  for (let i = 0; i < 50; i++) { try { targets = await (await fetch('http://127.0.0.1:9343/json')).json(); if (targets.length) break; } catch (e) {} await sleep(200); }
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
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(1000);
    const doc = (await send('DOM.getDocument')).result.root.nodeId;
    const inp = (await send('DOM.querySelector', { nodeId: doc, selector: '#pick' })).result.nodeId;
    await send('DOM.setFileInputFiles', { nodeId: inp, files: [path.normalize(path.join(root, 'orig', 'Test1.jww'))] });
    await sleep(1200);
    const work = fs.mkdtempSync(path.join(require('os').tmpdir(), 'jwrob-'));
    const put = (name, data) => { const f = path.join(work, name); fs.writeFileSync(f, data); return f; };
    const setFile = async (f) => {
      const d2 = (await send('DOM.getDocument')).result.root.nodeId;
      const i2 = (await send('DOM.querySelector', { nodeId: d2, selector: '#pick' })).result.nodeId;
      await send('DOM.setFileInputFiles', { nodeId: i2, files: f ? [f] : [] });
    };
    const mouse = (type, x, y, extra = {}) => send('Input.dispatchMouseEvent', Object.assign({ type, x, y, button: 'left', clickCount: 1 }, extra));
    const alive = async () => { try { return (await ev('window.__jw._jw_nobj() >= 0')) === true; } catch (e) { return false; } };
    const msg = () => ev("document.getElementById('msg').textContent");
    const heap = () => ev('window.__jw.HEAPU8.length / 1048576');
    ws.addEventListener('message', e => { const m = JSON.parse(e.data); if (m.method === 'Page.javascriptDialogOpening') send('Page.handleJavaScriptDialog', { accept: true }); });
    const h0 = await heap();
    console.log('     heap at the start: ' + h0.toFixed(0) + ' MB');

    // files that are not what their name says, and empty ones
    const odd = {
      'random.jww': crypto.randomBytes(5000),
      'empty.jww': Buffer.alloc(0),
      'empty.dxf': Buffer.alloc(0),
      'empty.sfc': Buffer.alloc(0),
      'empty.jwc': Buffer.alloc(0),
      'notes.pdf': Buffer.from('%PDF-1.4\n1 0 obj<<>>endobj\n'),
      'picture.jww': Buffer.from('89504e470d0a1a0a0000000d49484452ffffffffffffffff08020000', 'hex'),
      'text.txt': Buffer.from('12 34 56\n'.repeat(1000)),
      'figure.jws': crypto.randomBytes(900),
      'lines.dxf': Buffer.from('0\nSECTION\n2\nENTITIES\n' + '0\nLINE\n8\n0\n10\n1e308\n20\n-1e308\n11\nnan\n21\ninf\n'.repeat(50) + '0\nENDSEC\n0\nEOF\n'),
      'bad.png': crypto.randomBytes(3000),
      'null.jww': Buffer.alloc(100000),
    };
    for (const [name, data] of Object.entries(odd)) {
      await setFile(put(name, data));
      await sleep(400);
      const ok = await alive();
      check(ok, name + ' (' + data.length + ' bytes): the page is still alive -- ' + (await msg()).slice(0, 50));
    }
    // cancel: no file at all, and a picker that is cancelled
    await setFile(null);
    await ev("document.getElementById('pick').dispatchEvent(new Event('change'))");
    await sleep(200);
    check(await alive(), 'a change with no file does nothing');
    await ev("window.showOpenFilePicker = () => Promise.reject(new DOMException('cancelled', 'AbortError'))");
    await send('Page.setInterceptFileChooserDialog', { enabled: true });
    let chooser = false;
    ws.addEventListener('message', e => { if (JSON.parse(e.data).method === 'Page.fileChooserOpened') chooser = true; });
    const rr = await ev("(() => { const b = document.getElementById('pick').getBoundingClientRect(); return [b.left + 5, b.top + 5]; })()");
    await mouse('mousePressed', rr[0], rr[1]); await mouse('mouseReleased', rr[0], rr[1]);
    await sleep(500);
    check(await alive() && !chooser, 'a cancelled native picker neither errors nor falls back to the old chooser');
    await send('Page.setInterceptFileChooserDialog', { enabled: false });

    // a big DXF: 150,000 lines of drawing (about 17 MB of text)
    {
      const parts = ['0\nSECTION\n2\nENTITIES\n'];
      for (let i = 0; i < 150000; i++) parts.push('0\nLINE\n8\n0\n10\n' + (i % 1000) + '\n20\n' + ((i * 7) % 1000) + '\n11\n' + ((i + 5) % 1000) + '\n21\n' + ((i * 3) % 1000) + '\n');
      parts.push('0\nENDSEC\n0\nEOF\n');
      const f = put('big.dxf', parts.join(''));
      const t = Date.now();
      await setFile(f);
      for (let i = 0; i < 100 && !/elements|個/.test(await msg()); i++) await sleep(300);
      check(await alive(), 'a 17 MB DXF with 150,000 lines: the page is alive (' + (Date.now() - t) + ' ms) -- ' + (await msg()).slice(0, 40));
      console.log('     heap after it: ' + (await heap()).toFixed(0) + ' MB');
    }
    // the drawing opened and closed 200 times
    {
      const t1 = path.normalize(path.join(root, 'orig', 'Test1.jww'));
      const before = await heap();
      const t = Date.now();
      for (let i = 0; i < 200; i++) { await setFile(t1); await sleep(60); }
      await sleep(500);
      const after = await heap();
      check(await alive(), '200 openings: the page is alive (' + (Date.now() - t) + ' ms)');
      check(after - before < 80, 'and the memory did not run away (' + before.toFixed(0) + ' -> ' + after.toFixed(0) + ' MB)');
      check(/Test1/.test(await msg()), 'the last opening shows: ' + await msg());
    }
    // a file too big for the program's memory (a zero file of 1.5 GB)
    {
      const big = path.join(work, 'huge.jww');
      cp.execSync('fsutil file createnew "' + big + '" 1610612736', { stdio: 'ignore' });
      const was = await msg();
      const t = Date.now();
      await setFile(big);
      for (let i = 0; i < 100 && (await msg()) === was; i++) await sleep(300);
      await sleep(500);
      console.log('     the 1.5 GB file was answered in ' + (Date.now() - t) + ' ms: ' + await msg());
      check(await alive(), '1.5 GB file: the page is alive -- ' + (await msg()).slice(0, 60));
      fs.unlinkSync(big);
    }
    // and after all that the drawing still opens and draws
    await setFile(path.normalize(path.join(root, 'orig', 'Test1.jww')));
    await sleep(800);
    check(/1686|Test1/.test(await msg()), 'a normal file still opens afterwards: ' + await msg());
    check(jsErrors.length === 0, 'no script errors ' + jsErrors.slice(0, 3).join('|'));
    fs.rmSync(work, { recursive: true, force: true });
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
