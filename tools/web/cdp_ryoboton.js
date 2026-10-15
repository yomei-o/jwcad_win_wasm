// 両ボタンドラッグ・両ボタンクリック（src/ryoboton.h、原典の CZoom）を画布で。
//   node tools/web/cdp_ryoboton.js
// 左を押したまま右（Pointer Events では buttons が 3 になった pointermove）、
// 右を押したまま左、の両方で両ボタンになり、向きで判定が替わり、二つとも
// 離すと画面が替わる。右ドラッグのパン・左クリックの点はこれまでどおり。
// Serves the repo root, but with the wasm built in tmp/features_wasm, then
// drives Chrome over the DevTools protocol (node's built-in WebSocket).
const http = require('http'), fs = require('fs'), path = require('path'), cp = require('child_process');
const root = path.resolve(__dirname, '..', '..');
const chrome = process.env.CHROME || ['C:/Program Files/Google/Chrome/Application/chrome.exe',
  'C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe', '/usr/bin/google-chrome', '/usr/bin/chromium'].find(p => fs.existsSync(p));
if (!chrome) { console.log('SKIP no Chrome or Edge found (set CHROME=...)'); process.exit(0); }
const WASM = path.resolve(process.env.WASM_DIR || root);   // where jwcad.js / jwcad.wasm come from
const OUT = path.join(root, 'tmp'); fs.mkdirSync(OUT, { recursive: true });
const PORT = process.env.CDP_PORT || '9342';
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
    await load();
    check(await ev('!!(window.__jw && window.__jw._jw_ryo_begin)'), 'jwcad.wasm に jw_ryo_* がある');
    const now = () => ev('window.__jw._jw_ryo_now()');
    const base = await canvasData();
    const both = async (x0, y0, x1, y1, rightFirst) => {
      if (rightFirst) {
        await mouse('mousePressed', x0, y0, { button: 'right', buttons: 2 });
        await mouse('mousePressed', x0, y0, { button: 'left', buttons: 3 });
      } else {
        await mouse('mousePressed', x0, y0, { button: 'left', buttons: 1 });
        await mouse('mousePressed', x0, y0, { button: 'right', buttons: 3 });
      }
      await mouse('mouseMoved', (x0 + x1) >> 1, (y0 + y1) >> 1, { button: 'none', buttons: 3 });
      await mouse('mouseMoved', x1, y1, { button: 'none', buttons: 3 });
      await sleep(50);
      const k = await now();
      const during = await canvasData();
      await mouse('mouseReleased', x1, y1, { button: 'right', buttons: 1 });
      await mouse('mouseMoved', x1, y1, { button: 'none', buttons: 1 });
      const stillOn = await now();
      await mouse('mouseReleased', x1, y1, { button: 'left', buttons: 0 });
      await sleep(100);
      return { k, during, stillOn, after: await canvasData(), off: await now() };
    };
    let r = await both(500, 400, 700, 600, false);
    check(r.k === 1, '左→右で両ボタン、↘ は 範囲拡大 (1) : ' + r.k);
    check(r.during !== base, '  ドラッグ中は枠と字が出る');
    check(r.stillOn === 1, '  右だけ離してもまだ両ボタン');
    check(r.off === -1 && r.after !== base && r.after !== r.during, '  二つとも離すと拡大して終わる');
    const zoomed = r.after;
    r = await both(600, 450, 550, 500, false);
    check(r.k === 3, '↙ は 前倍率 (3) : ' + r.k);
    check(r.after === base, '  用紙全体に戻る');
    r = await both(600, 450, 640, 410, true);
    check(r.k === 4, '右→左でも両ボタン、↗ は 全体 (4) : ' + r.k);
    check(r.after === base, '  全体は用紙全体のまま');
    r = await both(600, 450, 520, 380, true);
    check(r.k === 2, '↖ は 縮小 (2) : ' + r.k);
    check(r.after !== base && r.after !== zoomed, '  縮小した');
    r = await both(640, 470, 643, 472, false);
    check(r.k === 5, 'しきいの内は 移動 (5) : ' + r.k);
    const moved = r.after;
    check(moved !== base, '  押した点が真ん中へ');
    r = await both(600, 450, 602, 520, false);
    check(r.k === 0 && r.after === moved, '真下は何もしない (0)');

    // 右だけのドラッグはパンのまま、右クリックは点のまま
    await load();
    const b2 = await canvasData();
    await mouse('mousePressed', 600, 450, { button: 'right', buttons: 2 });
    await mouse('mouseMoved', 650, 480, { button: 'none', buttons: 2 });
    await mouse('mouseMoved', 700, 500, { button: 'none', buttons: 2 });
    check(await now() === -1, '右だけのドラッグは両ボタンにならない');
    await mouse('mouseReleased', 700, 500, { button: 'right', buttons: 0 });
    await sleep(100);
    check(await canvasData() !== b2, '  画面が動く（パン）');

    // 左を押したまま動かせば、押した点を渡してから動く（手書線などのドラッグ）
    await load();
    await mouse('mousePressed', 500, 420, { button: 'left', buttons: 1 });
    await mouse('mouseMoved', 520, 430, { button: 'none', buttons: 1 });
    await mouse('mouseMoved', 650, 520, { button: 'none', buttons: 1 });
    await mouse('mouseReleased', 650, 520, { button: 'left', buttons: 0 });
    await sleep(100);
    const c0 = await canvasData();
    // 左クリックはこれまでどおり命令へ（離した時点で渡る）。線の始点 → 動かすと仮表示
    await load();
    const b3 = await canvasData();
    await mouse('mousePressed', 500, 420, { button: 'left', buttons: 1 });
    await mouse('mouseReleased', 500, 420, { button: 'left', buttons: 0 });
    await mouse('mouseMoved', 650, 520, { button: 'none', buttons: 0 });
    await sleep(100);
    const c1 = await canvasData();
    check(c1 !== b3, '左クリックで始点、動かすと線の仮表示');
    check(c0 === c1, '左ドラッグは押した点を渡してから動く（クリックして動かしたのと同じ絵）');
    const n0 = await ev('window.__jw._jw_nobj()');
    await mouse('mousePressed', 650, 520, { button: 'left', buttons: 1 });
    await mouse('mouseReleased', 650, 520, { button: 'left', buttons: 0 });
    await sleep(100);
    check(await ev('window.__jw._jw_nobj()') === n0 + 1, '  二つ目の左クリックで線が一本増える');
    check(jsErrors.length === 0, 'no script errors ' + jsErrors.slice(0, 2).join('|'));
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
