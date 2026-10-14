// Headless Chrome walk of the browser build.
//   node tools/web/cdp.js
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

  try {
    await send('Page.enable');
    await send('Runtime.enable');
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev("document.getElementById('msg') && document.getElementById('screen').width > 0")) break; }
    await sleep(1500);
    const errs = [];
    check(await ev("!!document.getElementById('screen')"), 'page loaded');
    const ink = async () => ev(`(() => { const c = document.getElementById('screen'); const d = c.getContext('2d').getImageData(0,0,c.width,c.height).data; let n = 0; for (let i = 0; i < d.length; i += 4) if (d[i] !== 255 || d[i+1] !== 255 || d[i+2] !== 255) n++; return n; })()`);
    const ink0 = await ink();
    check(ink0 > 1000, 'the screen is painted (' + ink0 + ' pixels)');

    // open a file through the file input
    const doc = (await send('DOM.getDocument')).result.root.nodeId;
    const inp = (await send('DOM.querySelector', { nodeId: doc, selector: '#pick' })).result.nodeId;
    await send('DOM.setFileInputFiles', { nodeId: inp, files: [path.join(root, 'orig', 'Test1.jww').replace(/\//g, '\\')] });
    await sleep(1500);
    const msg = await ev("document.getElementById('msg').textContent");
    check(/個の要素/.test(msg), 'Test1.jww opens: ' + msg);
    const ink1 = await ink();
    check(ink1 !== ink0, 'the picture changed after opening (' + ink1 + ')');

    // wheel zoom about the pointer
    const r = await ev("(() => { const b = document.getElementById('screen').getBoundingClientRect(); return [b.left, b.top]; })()");
    const before = await shot();
    await send('Input.dispatchMouseEvent', { type: 'mouseWheel', x: r[0] + 600, y: r[1] + 400, deltaX: 0, deltaY: -300 });
    await sleep(500);
    const afterZoom = await shot();
    check(afterZoom !== before, 'the wheel zooms');

    // touch: a one-finger drag is a click/drag, two fingers pinch
    const touch = (type, pts) => send('Input.dispatchTouchEvent', { type, touchPoints: pts.map((p, i) => ({ x: p[0], y: p[1], id: i })) });
    await touch('touchStart', [[r[0] + 500, r[1] + 400], [r[0] + 700, r[1] + 400]]);
    for (let k = 1; k <= 6; k++)
      await touch('touchMove', [[r[0] + 500 - k * 20, r[1] + 400], [r[0] + 700 + k * 20, r[1] + 400]]);
    await touch('touchEnd', []);
    await sleep(500);
    const afterPinch = await shot();
    check(afterPinch !== afterZoom, 'a two-finger pinch changes the view');

    // keyboard: Home refits
    await send('Input.dispatchKeyEvent', { type: 'keyDown', key: 'Home', code: 'Home', windowsVirtualKeyCode: 36 });
    await send('Input.dispatchKeyEvent', { type: 'keyUp', key: 'Home', code: 'Home', windowsVirtualKeyCode: 36 });
    await sleep(500);
    const afterHome = await shot();
    check(afterHome !== afterPinch, 'Home refits');
    fs.writeFileSync(path.join(OUT, 'cdp_last.png'), Buffer.from(afterHome, 'base64'));

    // draw: the 線 key (h), two clicks in the sheet
    {
      const inkA = await ink();
      await send('Input.dispatchKeyEvent', { type: 'keyDown', text: 'h', key: 'h', code: 'KeyH', windowsVirtualKeyCode: 72 });
      await mouse('mouseMoved', r[0] + 300, r[1] + 300, { button: 'none', clickCount: 0 });
      await mouse('mousePressed', r[0] + 300, r[1] + 300);
      await mouse('mouseReleased', r[0] + 300, r[1] + 300);
      await mouse('mouseMoved', r[0] + 700, r[1] + 350, { button: 'none', clickCount: 0 });
      await mouse('mousePressed', r[0] + 700, r[1] + 350);
      await mouse('mouseReleased', r[0] + 700, r[1] + 350);
      await sleep(500);
      check(await ink() !== inkA, 'two clicks with 線 draw something');
    }
    // 文字: the a key, Japanese typed through the input box, a click puts it down; Ctrl+Z takes it back
    {
      const keyDown = (k, extra = {}) => send('Input.dispatchKeyEvent', Object.assign({ type: 'keyDown', key: k, code: k }, extra));
      const inkBefore = await ink();
      await send('Input.dispatchKeyEvent', { type: 'keyDown', text: 'a', key: 'a', code: 'KeyA', windowsVirtualKeyCode: 65 });
      await sleep(300);
      const focused = await ev("document.activeElement && document.activeElement.tagName");
      check(focused === 'INPUT', 'the 文字 command puts the focus on the input box (' + focused + ')');
      await send('Input.insertText', { text: 'あいう漢字ABC' });
      await sleep(300);
      await mouse('mouseMoved', r[0] + 500, r[1] + 500, { button: 'none', clickCount: 0 });
      await mouse('mousePressed', r[0] + 500, r[1] + 500);
      await mouse('mouseReleased', r[0] + 500, r[1] + 500);
      await sleep(500);
      const inkText = await ink();
      fs.writeFileSync(path.join(OUT, 'cdp_text.png'), Buffer.from(await shot(), 'base64'));
      check(inkText !== inkBefore, 'the Japanese text is put down');
      await keyDown('z', { modifiers: 2, windowsVirtualKeyCode: 90 });
      await send('Input.dispatchKeyEvent', { type: 'keyUp', key: 'z', code: 'z', modifiers: 2, windowsVirtualKeyCode: 90 });
      await sleep(500);
      await send('Input.dispatchKeyEvent', { type: 'keyDown', key: 'Escape', code: 'Escape', windowsVirtualKeyCode: 27 });
      await send('Input.dispatchKeyEvent', { type: 'keyUp', key: 'Escape', code: 'Escape', windowsVirtualKeyCode: 27 });
      await mouse('mouseMoved', r[0] + 20, r[1] + 20, { button: 'none', clickCount: 0 });
      await sleep(300);
      fs.writeFileSync(path.join(OUT, 'cdp_undo.png'), Buffer.from(await shot(), 'base64'));
      const inkUndo = await ink();
      check(inkUndo < inkText, 'Ctrl+Z takes it back (before ' + inkBefore + ', with text ' + inkText + ', undone ' + inkUndo + ')');
      // Ctrl+Y puts it back, Alt+Backspace takes it back once more
      await keyDown('y', { modifiers: 2, windowsVirtualKeyCode: 89 });
      await send('Input.dispatchKeyEvent', { type: 'keyUp', key: 'y', code: 'y', modifiers: 2, windowsVirtualKeyCode: 89 });
      await sleep(400);
      const inkRedo = await ink();
      check(inkRedo > inkUndo, 'Ctrl+Y puts the text back (' + inkRedo + ' vs ' + inkUndo + ')');
      await keyDown('Backspace', { modifiers: 1, windowsVirtualKeyCode: 8 });
      await send('Input.dispatchKeyEvent', { type: 'keyUp', key: 'Backspace', code: 'Backspace', modifiers: 1, windowsVirtualKeyCode: 8 });
      await sleep(400);
      check(await ink() < inkRedo, 'Alt+Backspace is 戻る too');
    }
    // 範囲選択 (y), Ctrl+C: the copy lands on the system clipboard for another window
    {
      await send('Browser.grantPermissions', { origin: 'http://127.0.0.1:' + port, permissions: ['clipboardReadWrite', 'clipboardSanitizedWrite'] });
      const kd = (k, code, vk, mod = 0) => send('Input.dispatchKeyEvent', { type: 'keyDown', key: k, code, windowsVirtualKeyCode: vk, modifiers: mod, text: mod ? undefined : k });
      await mouse('mousePressed', 58, 361);
      await mouse('mouseReleased', 58, 361);
      await sleep(300);
      await mouse('mouseMoved', r[0] + 100, r[1] + 100, { button: 'none', clickCount: 0 });
      await mouse('mousePressed', r[0] + 100, r[1] + 100);
      await mouse('mouseReleased', r[0] + 100, r[1] + 100);
      await mouse('mouseMoved', r[0] + 1000, r[1] + 600, { button: 'none', clickCount: 0 });
      await mouse('mousePressed', r[0] + 1000, r[1] + 600);
      await mouse('mouseReleased', r[0] + 1000, r[1] + 600);
      await sleep(300);
      await kd('c', 'KeyC', 67, 2);
      await sleep(800);
      fs.writeFileSync(path.join(OUT, 'cdp_clip.png'), Buffer.from(await shot(), 'base64'));
      const clip = await ev("navigator.clipboard.readText().then(t => t.slice(0, 20) + ' len ' + t.length).catch(e => 'ERR ' + e)");
      check(/^JWCLIP:/.test(clip), 'Ctrl+C puts the copy on the system clipboard (' + clip + ')');
    }
    check(jsErrors.length === 0, 'no script errors' + (jsErrors.length ? ': ' + jsErrors[0] : ''));
    // 外部変形 from the menu command: the page says it cannot run a BAT
    const consoleErr = await ev("window.__errs || 0");
  } catch (e) {
    console.log('BAD  ' + (e && e.stack || e)); fails++;
  }
  try { ws.close(); } catch (e) {}
  proc.kill();
  server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
