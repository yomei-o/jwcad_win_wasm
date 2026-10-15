// 設定が起動をまたいで残る（ブラウザ）: localStorage の jw.prefs（基本設定 の箱など、app_prefs_write）と
// jw.env（.jwf、寸法設定 の数・文字基点のずれ）を pagehide で書き、読み込み直しで読む。
// localStorage が投げても頁は動く。  node tools/web/cdp_prefs.js（WASM_DIR=tmp/wasm で作り直したもの）
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
  const proc = cp.spawn(chrome, ['--headless=new', '--remote-debugging-port=9347', '--user-data-dir=' + prof, '--no-first-run', '--disable-gpu', 'about:blank'], { stdio: 'ignore' });
  let targets;
  for (let i = 0; i < 50; i++) { try { targets = await (await fetch('http://127.0.0.1:9347/json')).json(); if (targets.length) break; } catch (e) {} await sleep(200); }
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
    const url = 'http://127.0.0.1:' + port + '/?debug';
    const load = async () => {
      await send('Page.navigate', { url });
      for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
      await sleep(800);
    };
    // what the page leaves in localStorage when it is hidden, as text
    const envText = "(() => { const m = window.__jw; const p = m.ccall('jw_save_env', 'number', ['string'], ['x.jwf']);" +
      " const n = m._jw_saved_len(); const s = String.fromCharCode.apply(null, m.HEAPU8.subarray(p, p + n)); m._jw_saved_free(); return s; })()";
    const prefsText = "(() => { const m = window.__jw; const p = m._jw_save_prefs(); const s = p ? m.UTF8ToString(p) : ''; m._jw_saved_free(); return s; })()";
    await load();
    check(await ev("localStorage.getItem('jw.prefs')") === null, 'nothing kept to start with');
    // 基本設定 の箱 と 寸法設定 の数: as OK would leave them
    check(await ev("window.__jw.ccall('jw_open_prefs', 'number', ['string'], ['[KIHON]\\nT0.1788.0=321\\nT0.1052.0=D:\\\\x8a\\\\xdb\\n'])") === 2,
      'two boxes go in as OK would leave them');
    await ev("(() => { const t = 'S_SET3 =     6.00   11.00    1.00    4.00    2.00    7.00 \\r\\nMOFST =     1  -2.5   0.0   1.0  -4.0   0.0   3.0     0 \\r\\n';" +
      " const m = window.__jw; const p = m._malloc(t.length); for (let i = 0; i < t.length; i++) m.HEAPU8[p + i] = t.charCodeAt(i); m.ccall('jw_open_env', 'number', ['number', 'number'], [p, t.length]); m._free(p); })()");
    check(/S_SET3 =     6\.00   11\.00/.test(await ev(envText)), 'the dimension numbers are in the .jwf');
    await ev("window.dispatchEvent(new Event('pagehide'))");
    check(/T0\.1788\.0=321/.test(await ev("localStorage.getItem('jw.prefs')") || ''), 'pagehide keeps them in localStorage');
    // a new start of the page
    await load();
    const pf = await ev(prefsText);
    check(/T0\.1788\.0=321\n/.test(pf) && /T0\.1052\.0=D:\\x8a\\xdb\n/.test(pf), 'a reload reads them back: ' + JSON.stringify(pf));
    const env = await ev(envText);
    check(/S_SET3 =     6\.00   11\.00    1\.00    4\.00    2\.00    7\.00/.test(env), 'and the dimension numbers');
    check(/MOFST =     1  -2\.5   0\.0   1\.0  -4\.0   0\.0   3\.0/.test(env), 'and the 文字基点 ずれ');
    // storage that throws: the page still comes up
    await send('Page.addScriptToEvaluateOnNewDocument', { source: "Object.defineProperty(window, 'localStorage', { get() { throw new Error('blocked'); } });" });
    await load();
    check(await ev('!!window.__jw && window.__jw._jw_width() > 0'), 'with localStorage blocked the page still runs');
    check(jsErrors.length === 0, 'no script errors ' + jsErrors.join('|'));
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
