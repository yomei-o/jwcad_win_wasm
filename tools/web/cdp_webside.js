// 表側の配線: 中身にあって表側から届かなかったもの。
//   node tools/web/cdp_webside.js
// * 文字を範囲選択して Ctrl+C: 字が text/plain でクリップボードへ（原典の
//   CF_UNICODETEXT。図形は web のカスタム形式で横に）
// * メニューの コピー（キーでなく jw_command）でも同じ
// * Ctrl+P（印刷）で PDF が出る、メニューの DXF形式で保存 で .dxf が出る
// * 文字 の 連 で画面をダブルクリック: 移動（LL) に入る（5311）
// Serves the repo root (WASM_DIR= for a wasm built elsewhere) and drives
// Chrome/Edge over the DevTools protocol, like the other cdp_*.js.
const http = require('http'), fs = require('fs'), path = require('path'), cp = require('child_process');
const root = path.resolve(__dirname, '..', '..');
const chrome = process.env.CHROME || ['C:/Program Files/Google/Chrome/Application/chrome.exe',
  'C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe', '/usr/bin/google-chrome', '/usr/bin/chromium'].find(p => fs.existsSync(p));
if (!chrome) { console.log('SKIP no Chrome or Edge found (set CHROME=...)'); process.exit(0); }
const WASM = path.resolve(process.env.WASM_DIR || root);
const PORT = process.env.CDP_PORT || '9337';
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
  ws.onmessage = ev => { const m = JSON.parse(ev.data);
    // 図面を変えたあとの 読み直し は beforeunload が問う: はい
    if (m.method === 'Page.javascriptDialogOpening') ws.send(JSON.stringify({ id: ++id, method: 'Page.handleJavaScriptDialog', params: { accept: true } }));
    if (m.method === 'Runtime.exceptionThrown') jsErrors.push(JSON.stringify(m.params.exceptionDetails.exception && m.params.exceptionDetails.exception.description || m.params.exceptionDetails.text)); if (m.id && waiting.has(m.id)) { waiting.get(m.id)(m); waiting.delete(m.id); } };
  const send = (method, params = {}) => new Promise(r => { const n = ++id; waiting.set(n, r); ws.send(JSON.stringify({ id: n, method, params })); });
  const ev = async expr => (await send('Runtime.evaluate', { expression: expr, returnByValue: true, awaitPromise: true })).result.result.value;
  const mouse = (type, x, y, extra = {}) => send('Input.dispatchMouseEvent', Object.assign({ type, x, y, button: 'left', clickCount: 1 }, extra));
  const key = (k, code, vk, mods = 0) => send('Input.dispatchKeyEvent', { type: 'rawKeyDown', key: k, code, windowsVirtualKeyCode: vk, modifiers: mods })
    .then(() => send('Input.dispatchKeyEvent', { type: 'keyUp', key: k, code, windowsVirtualKeyCode: vk, modifiers: mods }));
  // the canvas's pixel (x, y) -- with the chrome on top, which jw_press takes off -- in page coordinates
  const at = async (x, y) => ev(`(() => { const c = document.getElementById('screen'), r = c.getBoundingClientRect();
    const k = r.width / c.width; return [r.left + ${x} * k, r.top + ${y} * k]; })()`);
  const prompt = () => ev('window.__jw.UTF8ToString(window.__jw._jw_prompt())');

  const load = async () => {
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(500);
    // what the page hands the clipboard and the downloads, kept where the test can read it
    await ev(`(() => {
      window.__clip = []; window.__dl = [];
      Object.defineProperty(navigator, 'clipboard', { configurable: true, value: {
        writeText: t => { __clip.push(['writeText', t]); return Promise.resolve(); },
        write: async items => { for (const it of items) for (const ty of it.types) __clip.push([ty, await (await it.getType(ty)).text()]); },
        readText: () => Promise.resolve(''), read: () => Promise.resolve([]) } });
      window.showSaveFilePicker = undefined;
      HTMLAnchorElement.prototype.click = function () { __dl.push(this.download); };
      return true; })()`);
  };
  // 文字を二つ（AB と CD）置く。chrome の下の (400,300+ch)・(400,400+ch)
  const ch = async () => ev('window.__jw._jw_chrome_h()');
  const texts = async () => {
    const h = await ch();
    await ev(`(() => { const m = window.__jw; m._jw_command(0x8026);
      m._jw_key(65); m._jw_key(66); m._jw_press(400, ${300 + h}, 0);
      m._jw_key(67); m._jw_key(68); m._jw_press(400, ${400 + h}, 0); return m._jw_nobj(); })()`);
    return h;
  };
  try {
    await send('Page.enable'); await send('Runtime.enable');
    await send('Emulation.setDeviceMetricsOverride', { width: 1264, height: 903, deviceScaleFactor: 1, mobile: false });

    // ---- コピー: 範囲選択で字を含めて（二つ目の角を右で）選び、Ctrl+C
    await load();
    let h = await texts();
    await ev(`(() => { const m = window.__jw; m._jw_command(0x8013);
      m._jw_press(300, ${200 + h}, 0); m._jw_press(700, ${450 + h}, 1); return 1; })()`);
    await send('Page.bringToFront');
    await key('c', 'KeyC', 67, 2);
    await sleep(300);
    let clip = await ev('window.__clip');
    const plain = clip.find(c => c[0] === 'text/plain' || (c[0] === 'writeText' && !c[1].startsWith('JWCLIP:')));
    check(plain && /AB\r?\nCD/.test(plain[1]), 'Ctrl+C: 選んだ字が text/plain で出る (' + JSON.stringify(plain && plain[1]) + ')');
    const fig = clip.find(c => c[0] === 'web application/x-jwclip' || (c[0] === 'writeText' && c[1].startsWith('JWCLIP:')));
    check(!!fig || clip.length === 1, '  図形はカスタム形式で横に（使えないブラウザは字だけ）');

    // ---- メニューと同じ道（jw_command）のコピーも
    await ev('window.__clip.length = 0');
    const r = await ev('window.__jw._jw_command(57634)');
    check(r === 16, 'jw_command(コピー) は 16（クリップボードへ）を返す');

    // ---- 線だけを選んだコピーは JWCLIP: の字だけ
    await load();
    h = await ch();
    await ev(`(() => { const m = window.__jw; m._jw_command(0x8003);
      m._jw_press(400, ${300 + h}, 0); m._jw_press(600, ${300 + h}, 0);
      m._jw_command(0x8013); m._jw_press(300, ${200 + h}, 0); m._jw_press(700, ${450 + h}, 0); return 1; })()`);
    await key('c', 'KeyC', 67, 2);
    await sleep(300);
    clip = await ev('window.__clip');
    check(clip.length === 1 && clip[0][0] === 'writeText' && clip[0][1].startsWith('JWCLIP:'), '線だけのコピーは今までどおり JWCLIP:');

    // ---- Ctrl+P と メニューの DXF形式で保存
    await load();
    await key('p', 'KeyP', 80, 2);
    await sleep(500);
    let dl = await ev('window.__dl');
    check(dl.some(n => /\.pdf$/.test(n)), 'Ctrl+P で PDF (' + dl.join(',') + ')');
    await ev(`(() => { window.__dl.length = 0; return 1; })()`);
    const rc = await ev('window.__jw._jw_command(32961)');
    check(rc === 17, 'DXF形式で保存 (32961) は 17 を返す');

    // ---- 文字 の 連 で ダブルクリック
    await load();
    h = await texts();
    await ev(`(() => { const m = window.__jw; m._jw_command(0x8026); return 1; })()`);
    // 連 (1068) は文字のバーの釦: jw_bar_ctl で場所を探して押す
    const ren = await ev(`(() => { const m = window.__jw;
      for (let i = 0; ; i++) { const p = m._jw_bar_ctl(i); if (!p) return null;
        const v = new Int32Array(m.HEAPU8.buffer, p, 6); if (v[0] === 1068) return [v[2] + v[4] / 2, v[3] + v[5] / 2]; } })()`);
    check(!!ren, '文字のバーに 連 (1068) がある');
    if (ren) {
      let [x, y] = await at(ren[0], ren[1]);
      await mouse('mousePressed', x, y, { buttons: 1 }); await mouse('mouseReleased', x, y, { buttons: 0 });
      check(/連結/.test(await prompt()), '  連 が入る: ' + await prompt());
      [x, y] = await at(405, 300 + h);
      await mouse('mouseMoved', x, y, { buttons: 0 });
      await mouse('mousePressed', x, y, { buttons: 1, clickCount: 1 }); await mouse('mouseReleased', x, y, { buttons: 0, clickCount: 1 });
      await mouse('mousePressed', x, y, { buttons: 1, clickCount: 2 }); await mouse('mouseReleased', x, y, { buttons: 0, clickCount: 2 });
      check(/移動先/.test(await prompt()), '  ダブルクリックで 移動（LL): ' + await prompt());
    }
    check(!jsErrors.length, 'no JavaScript errors ' + jsErrors.join(' | '));
  } catch (e) {
    console.log('BAD  ' + (e && e.stack || e)); fails++;
  } finally {
    ws.close(); proc.kill(); server.close();
  }
  console.log(fails ? fails + ' BAD' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
