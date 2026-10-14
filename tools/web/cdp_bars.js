// Every control of every command bar, pressed once, in headless Chrome.
//   node tools/web/cdp_bars.js [quick]
// Serves the repo root with the wasm from WASM_DIR (it needs the jw_bar_ctl, jw_prompt and jw_modal exports), then
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

  ws.addEventListener('message', e => { const m = JSON.parse(e.data); if (m.method === 'Page.javascriptDialogOpening') send('Page.handleJavaScriptDialog', { accept: false }); });
  const quick = process.argv.includes('quick');
  const key = async (k, vk) => { await send('Input.dispatchKeyEvent', { type: 'keyDown', key: k, code: k, windowsVirtualKeyCode: vk }); await send('Input.dispatchKeyEvent', { type: 'keyUp', key: k, code: k, windowsVirtualKeyCode: vk }); };
  try {
    await send('Page.enable');
    await send('Runtime.enable');
    await send('Page.setInterceptFileChooserDialog', { enabled: true });       // a button that wants a file gets none
    await send('Browser.setDownloadBehavior', { behavior: 'deny' });
    await send('Page.navigate', { url: 'http://127.0.0.1:' + port + '/?debug' });
    for (let i = 0; i < 50; i++) { await sleep(200); if (await ev('!!window.__jw')) break; }
    await sleep(800);
    if (!(await ev('typeof window.__jw._jw_bar_ctl === "function" && typeof window.__jw._jw_prompt === "function"'))) {
      console.log('SKIP this wasm has no jw_bar_ctl / jw_prompt (build it from the current sources)');
      try { ws.close(); } catch (e) {} proc.kill(); server.close();
      process.exit(0);
    }
    const doc = (await send('DOM.getDocument')).result.root.nodeId;
    const openTest = async () => {
      const inp = (await send('DOM.querySelector', { nodeId: (await send('DOM.getDocument')).result.root.nodeId, selector: '#pick' })).result.nodeId;
      await send('DOM.setFileInputFiles', { nodeId: inp, files: [path.normalize(path.join(root, 'orig', 'Test1.jww'))] });
      await sleep(250);
    };
    await openTest();
    const r = await ev("(() => { const b = document.getElementById('screen').getBoundingClientRect(); return [b.left, b.top]; })()");

    // the commands to walk: what the toolbar's buttons and the menu start, but not the file ones
    const cmdsH = fs.readFileSync(path.join(root, 'src/gen/cmds.h'), 'utf8');
    const a0 = cmdsH.indexOf('jw_btn_cmd');
    const ids = new Set([...cmdsH.slice(a0, cmdsH.indexOf('};', a0)).matchAll(/^\s*(\d+),/gm)].map(m => +m[1]));
    const cov = fs.readFileSync(path.join(root, 'docs/command-coverage.md'), 'utf8');
    for (const m of cov.matchAll(/^\|\s*(\d+)\s*\|[^|]*\|\s*動く\s*\|/gm)) ids.add(+m[1]);
    const skip = new Set([57600, 57601, 57603, 57604, 57606, 57607, 57612, 57664, 57665, 57667, 57616, 32809, 32810, 32960, 32961, 32975, 32976]);
    let list = [...ids].filter(i => !skip.has(i) && !(i >= 57345 && i <= 57359)).sort((a, b) => a - b);
    if (quick) list = list.filter((_, i) => i % 6 === 0);
    console.log('     commands to walk: ' + list.length + (quick ? ' (quick)' : ''));

    const errBefore = () => jsErrors.length;
    const ctls = async () => {
      const out = [];
      for (let i = 0; i < 80; i++) {
        const c = await ev('(() => { const p = window.__jw._jw_bar_ctl(' + i + '); if (!p) return null; return Array.from(new Int32Array(window.__jw.HEAPU8.buffer, p, 6)); })()');
        if (!c) break;
        out.push(c);
      }
      return out;
    };
    const prompt = () => ev('window.__jw.UTF8ToString(window.__jw._jw_prompt())');
    const modal = () => ev('window.__jw._jw_modal()');
    const cmdid = () => ev('window.__jw._jw_cmd_id()');
    const sane = s => s.length <= 300 && !/[�\u0000-\u001f]/.test(s) && !/\?{3,}/.test(s);
    let controls = 0, clicks = 0, dialogs = 0, bad = 0, emptyPrompts = [], commands = 0;
    const note = m => { console.log('BAD  ' + m); bad++; fails++; };
    for (const cid of list) {
      await openTest();
      await ev('window.__jw._jw_command(' + cid + ')');
      await sleep(30);
      const e0 = errBefore();
      if (await modal()) { for (let k = 0; k < 3; k++) await key('Escape', 27); }
      const p0 = await prompt();
      if (!sane(p0)) note('command ' + cid + ': the prompt is not sane: ' + JSON.stringify(p0.slice(0, 80)));
      if (!p0) emptyPrompts.push(cid);
      const first = await ctls();
      commands++;
      for (const [bid, kind] of first) {
        if (kind > 2 && kind !== 5) continue;                // buttons, checks, combos only (kinds 0..2 and the like)
        await openTest();
        await ev('window.__jw._jw_command(' + cid + ')');
        if (await modal()) { for (let k = 0; k < 3; k++) await key('Escape', 27); }
        const now = (await ctls()).find(c => c[0] === bid);
        if (!now) continue;                                  // a variant bar replaced it: fine
        const x = r[0] + now[2] + Math.floor(now[4] / 2), y = r[1] + now[3] + Math.floor(now[5] / 2);
        controls++;
        await mouse('mouseMoved', x, y, { button: 'none', clickCount: 0 });
        await mouse('mousePressed', x, y);
        await mouse('mouseReleased', x, y);
        clicks++;
        await sleep(25);
        const where = 'command ' + cid + ', control ' + bid;
        if (!(await ev('window.__jw._jw_nobj() >= 0'))) { note(where + ': the page is gone'); break; }
        if (jsErrors.length > e0) { note(where + ': a script error: ' + jsErrors[jsErrors.length - 1].slice(0, 120)); jsErrors.length = e0; }
        const p = await prompt();
        if (!sane(p)) note(where + ': the prompt is not sane: ' + JSON.stringify(p.slice(0, 80)));
        if (await modal()) {
          dialogs++;
          for (let k = 0; k < 3 && (await modal()); k++) await key('Escape', 27);
          if (await modal()) note(where + ': a dialog stays up after Esc');
        }
        // back to a plain command: nothing may hold on to the press
        await ev('window.__jw._jw_command(32771)');
        if (await cmdid() !== 0x8003) note(where + ': 線 cannot be chosen afterwards');
      }
    }
    console.log('     ' + commands + ' commands, ' + controls + ' controls pressed (' + clicks + ' clicks), ' + dialogs + ' of them put a dialog up and Esc closed it');
    if (emptyPrompts.length) console.log('     commands with an empty prompt: ' + emptyPrompts.join(' '));
    check(bad === 0, 'every control of every bar pressed: no script error, nothing stuck, every prompt sane');
    check(controls > (quick ? 50 : 500), 'a good many controls were reached (' + controls + ')');
    check(jsErrors.length === 0, 'no script errors left over ' + jsErrors.slice(0, 2).join('|'));
  } catch (e) { console.log('BAD  ' + (e && e.stack || e)); fails++; }
  try { ws.close(); } catch (e) {}
  proc.kill(); server.close();
  console.log(fails ? 'FAILED' : 'all ok');
  process.exit(fails ? 1 : 0);
})();
