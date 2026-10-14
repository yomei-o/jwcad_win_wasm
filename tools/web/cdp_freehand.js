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
  const proc = cp.spawn(chrome, ['--headless=new', '--remote-debugging-port=9344', '--user-data-dir=' + prof, '--no-first-run', '--disable-gpu', 'about:blank'], { stdio: 'ignore' });
  let targets;
  for (let i = 0; i < 50; i++) { try { targets = await (await fetch('http://127.0.0.1:9344/json')).json(); if (targets.length) break; } catch (e) {} await sleep(200); }
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
    const mouse = (type, x, y, extra = {}) => send('Input.dispatchMouseEvent', Object.assign({ type, x, y, button: 'left', clickCount: 1 }, extra));
    const click = async (x, y) => { await mouse('mouseMoved', x, y, { button: 'none', clickCount: 0 }); await mouse('mousePressed', x, y); await mouse('mouseReleased', x, y); await sleep(150); };
    const r = await ev("(() => { const b = document.getElementById('screen').getBoundingClientRect(); return [b.left, b.top]; })()");
    const chh = await ev('window.__jw._jw_chrome_h()');
    // 連続線 from its toolbar button
    const cmds = fs.readFileSync(path.join(root, 'src/gen/cmds.h'), 'utf8');
    const a0 = cmds.indexOf('jw_btn_cmd');
    const ids = [...cmds.slice(a0, cmds.indexOf('};', a0)).matchAll(/^\s*(\d+),/gm)].map(m => +m[1]);
    const layout = fs.readFileSync(path.join(root, 'src/gen/layout.h'), 'utf8');
    const body = layout.slice(layout.indexOf('jw_buttons[]'), layout.indexOf('#define JW_NBUTTONS'));
    const btns = [...body.matchAll(/\{\s*(\d+),\s*(\d+),\s*\d+,\s*\d+,\s*\d+\s*\}/g)].map(m => [+m[1], +m[2]]);
    const k = ids.indexOf(32883);
    await click(r[0] + btns[k][0] + 15, r[1] + chh + btns[k][1] + 11);
    check(await ev('window.__jw._jw_cmd_id()') === 0x8073, '連続線 is in force');
    // the 手書線 box of its bar (x 598, y 10 on the bar)
    await click(r[0] + 598 + 8, r[1] + chh + 5 + 10);
    const n0 = await ev('window.__jw._jw_nobj()');
    // press, drag 300 px along a wave with the button held, release
    await mouse('mouseMoved', r[0] + 300, r[1] + 300, { button: 'none', clickCount: 0 });
    await mouse('mousePressed', r[0] + 300, r[1] + 300, { buttons: 1 });
    for (let i = 1; i <= 300; i += 3) await mouse('mouseMoved', r[0] + 300 + i, r[1] + 300 + Math.round(40 * Math.sin(i / 25)), { button: 'left', buttons: 1, clickCount: 0 });
    const during = await ev('window.__jw._jw_nobj()');
    await mouse('mouseReleased', r[0] + 600, r[1] + 300, { buttons: 0 });
    await sleep(200);
    const n1 = await ev('window.__jw._jw_nobj()');
    check(during > n0 + 30, 'lines appear while the button is down (' + (during - n0) + ')');
    check(n1 >= during && n1 - n0 > 40 && n1 - n0 < 200, 'and the stroke ends with the button (' + (n1 - n0) + ' lines)');
    // moving with the button up draws nothing more
    await mouse('mouseMoved', r[0] + 700, r[1] + 400, { button: 'none', clickCount: 0 });
    await mouse('mouseMoved', r[0] + 760, r[1] + 450, { button: 'none', clickCount: 0 });
    check(await ev('window.__jw._jw_nobj()') === n1, 'a move after the button is up draws nothing');
    // one Ctrl+Z takes the whole stroke
    await send('Input.dispatchKeyEvent', { type: 'keyDown', key: 'z', code: 'KeyZ', windowsVirtualKeyCode: 90, modifiers: 2 });
    await send('Input.dispatchKeyEvent', { type: 'keyUp', key: 'z', code: 'KeyZ', windowsVirtualKeyCode: 90, modifiers: 2 });
    await sleep(300);
    check(await ev('window.__jw._jw_nobj()') === n0, 'one Ctrl+Z takes the whole stroke');
    check(jsErrors.length === 0, 'no script errors ' + jsErrors.join('|'));
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
