// 指（タッチ）で: (LL) の幅と間、ソフトキーボードの出し入れ、二本指の長押しの両ボタン。
//   node tools/web/cdp_touch.js
// (LL) は原典が WM_LBUTTONDBLCLK で受け、２線 は 2 画素動くまで待つ（src/app.c の ll_*）。
// 指は同じ画素に二度は落ちないので、index.html はタッチのときだけ幅を 16 CSS 画素に、
// 間が 500ms（Windows の既定のダブルクリック時間）より空けば (L) 二つに。
// WASM_DIR に作り直した jwcad.js / jwcad.wasm を置いて流す（無ければ repo の根のもの）。
const http = require('http'), fs = require('fs'), path = require('path'), cp = require('child_process');
const root = path.resolve(__dirname, '..', '..');
const chrome = process.env.CHROME || ['C:/Program Files/Google/Chrome/Application/chrome.exe',
  'C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe', '/usr/bin/google-chrome', '/usr/bin/chromium'].find(p => fs.existsSync(p));
if (!chrome) { console.log('SKIP no Chrome or Edge found (set CHROME=...)'); process.exit(0); }
const WASM = path.resolve(process.env.WASM_DIR || root);
const PORT = process.env.CDP_PORT || '9346';
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
  // 描いたあとの読み直しは beforeunload が問う: はい
  ws.addEventListener('message', e => { const m = JSON.parse(e.data); if (m.method === 'Page.javascriptDialogOpening') send('Page.handleJavaScriptDialog', { accept: true }); });
  const ev = async expr => (await send('Runtime.evaluate', { expression: expr, returnByValue: true, awaitPromise: true })).result.result.value;
  const mouse = (type, x, y, extra = {}) => send('Input.dispatchMouseEvent', Object.assign({ type, x, y, button: 'left', clickCount: 1 }, extra));
  const canvasData = () => ev(`document.getElementById('screen').toDataURL()`);
  const imeFocused = () => ev(`document.activeElement && document.activeElement.tagName === 'INPUT' && document.activeElement.getAttribute('aria-label') !== null && document.activeElement.id !== 'pick'`);
  let ox = 0, oy = 0;                   /* 画布の client の左上（ページの座標） */
  const load = async () => {
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(700);
    const doc = (await send('DOM.getDocument')).result.root.nodeId;
    const inp = (await send('DOM.querySelector', { nodeId: doc, selector: '#pick' })).result.nodeId;
    await send('DOM.setFileInputFiles', { nodeId: inp, files: [path.normalize(path.join(root, 'orig', 'Test1.jww'))] });
    await sleep(700);
    const r = await ev("(() => { const b = document.getElementById('screen').getBoundingClientRect(); return [b.left, b.top]; })()");
    ox = r[0]; oy = r[1] + await ev('window.__jw._jw_chrome_h()');
  };
  const tap = async (x, y, hold = 40) => {
    await send('Input.dispatchTouchEvent', { type: 'touchStart', touchPoints: [{ x: ox + x, y: oy + y, id: 1 }] });
    await sleep(hold);
    await send('Input.dispatchTouchEvent', { type: 'touchEnd', touchPoints: [] });
    await sleep(60);
  };
  const click = async (x, y) => {
    await mouse('mouseMoved', ox + x, oy + y, { button: 'none', clickCount: 0 });
    await mouse('mousePressed', ox + x, oy + y, { buttons: 1 });
    await mouse('mouseReleased', ox + x, oy + y, { buttons: 0 });
    await sleep(40);
  };
  // 白紙に線を二本（横・縦）引いて ２線、横を基準線に、縦の上で (LL) で角を回る。
  // second(): 縦の線の上の二度目。最後はマウスを同じ所へ動かして絵をそろえる
  const nisen = async second => {
    await load();
    await ev('window.__jw._jw_new()');
    await ev('window.__jw._jw_command(0x8003)');
    await click(200, 300); await click(700, 300);
    await click(600, 100); await click(600, 550);
    await ev('window.__jw._jw_command(0x807c)');
    await click(300, 300);
    await click(250, 300);
    await second();
    await click(600, 450);
    await mouse('mouseMoved', ox + 400, oy + 200, { button: 'none', clickCount: 0 });
    await mouse('mouseMoved', ox + 380, oy + 180, { button: 'none', clickCount: 0 });
    await sleep(100);
    return [await canvasData(), await ev('window.__jw._jw_nobj()')];
  };
  try {
    await send('Page.enable'); await send('Runtime.enable');
    await send('Emulation.setDeviceMetricsOverride', { width: 1264, height: 903, deviceScaleFactor: 1, mobile: false });
    await send('Emulation.setEmitTouchEventsForMouse', { enabled: false });

    const [ll, nll] = await nisen(async () => { await click(600, 200); await click(600, 200); });
    const [two, ntwo] = await nisen(async () => { await click(600, 200); await click(606, 205); });
    check(ll !== two, 'マウスで同じ画素に二度（(LL)）と 6,5 ずらした二度（(L) 二つ）は違う図 (' + nll + ' / ' + ntwo + ')');
    const [t1] = await nisen(async () => { await tap(600, 200); await tap(606, 205); });
    check(t1 === ll, '指なら 6,5 ずれた二度もすぐなら (LL)');
    const [t2] = await nisen(async () => { await tap(600, 200); await sleep(700); await tap(606, 205); });
    check(t2 === two, '指でも間が 500ms より空けば (L) 二つ');
    const [m2] = await nisen(async () => { await tap(600, 200); await click(606, 205); });
    check(m2 === two, '指のあとでもマウスで押せば幅は 2 画素（(L) 二つ）');

    // ソフトキーボード: 指で図面を叩いても、隠した入力欄にはフォーカスしない
    await load();
    await tap(400, 300);
    check(!(await imeFocused()), '線の命令で図面を叩いても入力欄にフォーカスしない（キーボードは出ない）');
    await ev('window.__jw._jw_command(0x8026)');
    await tap(400, 300);
    check(await imeFocused(), '文字の命令では叩くと入力欄にフォーカス（キーボードが出る）');
    await ev('window.__jw._jw_command(0x8003)');
    await tap(400, 300);
    check(!(await imeFocused()), '線に戻って叩けば入力欄は外れる（キーボードはしまう）');
    // マウスはこれまでどおり（文字の命令で入力欄）
    await ev('window.__jw._jw_command(0x8026)');
    await click(420, 320);
    await sleep(50);
    check(await imeFocused(), 'マウスでも文字の命令では入力欄にフォーカス');

    // 二本指の長押し → 両ボタンドラッグ。↘ に動かして離すと範囲拡大（画面が替わる）
    await load();
    const base = await canvasData();
    const two0 = [{ x: ox + 400, y: oy + 300, id: 1 }, { x: ox + 440, y: oy + 300, id: 2 }];
    await send('Input.dispatchTouchEvent', { type: 'touchStart', touchPoints: two0 });
    await sleep(750);
    check(await ev('window.__jw._jw_ryo_now()') >= 0, '二本指を動かさずに長押しすると両ボタン');
    for (let i = 1; i <= 4; i++)
      await send('Input.dispatchTouchEvent', { type: 'touchMove', touchPoints: two0.map(p => ({ x: p.x + 20 * i, y: p.y + 20 * i, id: p.id })) });
    await sleep(50);
    check(await ev('window.__jw._jw_ryo_now()') === 1, '  ↘ に動かすと 範囲拡大');
    await send('Input.dispatchTouchEvent', { type: 'touchEnd', touchPoints: [] });
    await sleep(150);
    check(await ev('window.__jw._jw_ryo_now()') === -1, '  離せば終わる');
    check(await canvasData() !== base, '  画面が替わった');
    // 二本指ですぐ離すのは右（これまでどおり）、二本指で動かすのはパン
    await load();
    await send('Input.dispatchTouchEvent', { type: 'touchStart', touchPoints: two0 });
    await sleep(60);
    for (let i = 1; i <= 4; i++)
      await send('Input.dispatchTouchEvent', { type: 'touchMove', touchPoints: two0.map(p => ({ x: p.x + 15 * i, y: p.y, id: p.id })) });
    await sleep(700);
    check(await ev('window.__jw._jw_ryo_now()') === -1, '動かしてからの二本指は両ボタンにならない（パン）');
    await send('Input.dispatchTouchEvent', { type: 'touchEnd', touchPoints: [] });
    check(jsErrors.length === 0, 'no script errors ' + jsErrors.slice(0, 2).join('|'));
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
