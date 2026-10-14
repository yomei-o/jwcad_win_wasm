// Smoke test: drive a built jwcad.js under node the way index.html does --
// open, draw, save, reopen, every export, plot, picture insert, damaged input.
//   node tools/smoke_wasm.js [dir containing jwcad.js]      (default: the repo root)
// tools/ci.sh builds into tmp/ci/wasm and runs this on it.
const fs = require('fs');
const path = require('path');
const root = path.resolve(__dirname, '..');
const wasmDir = path.resolve(process.argv[2] || root);
const outDir = path.join(root, 'tmp');
const createJwcad = require(path.join(wasmDir, 'jwcad.js'));
let fails = 0;
function check(c, msg) { console.log((c ? 'ok   ' : 'BAD  ') + msg); if (!c) fails++; }

(async () => {
  const mod = await createJwcad();
  const f = (n, r, a) => mod.cwrap(n, r, a);
  const resize = f('jw_resize', 'number', ['number', 'number']);
  const open = f('jw_open', 'number', ['number', 'number']);
  const nobj = f('jw_nobj', 'number', []);
  const rgba = f('jw_rgba', 'number', []);
  const W = f('jw_width', 'number', []), H = f('jw_height', 'number', []);
  const press = f('jw_press', 'number', ['number', 'number', 'number']);
  const move = f('jw_move', 'number', ['number', 'number']);
  const command = f('jw_command', 'number', ['number']);
  const save = f('jw_save', 'number', []);
  const savedLen = f('jw_saved_len', 'number', []);
  const savedFree = f('jw_saved_free', null, []);
  const modified = f('jw_modified', 'number', []);
  const fit = f('jw_fit', null, []);
  const zoom = f('jw_zoom', null, ['number', 'number', 'number']);
  const pan = f('jw_pan', null, ['number', 'number']);

  function put(buf) {
    const p = mod._malloc(buf.length || 1);
    mod.HEAPU8.set(buf, p);
    return p;
  }
  function out(ptr) {
    if (!ptr) return null;
    const b = mod.HEAPU8.slice(ptr, ptr + savedLen());
    savedFree();
    return b;
  }
  function inkCount() {
    const p = rgba(), n = W() * H();
    const a = mod.HEAPU8.subarray(p, p + n * 4);
    let c = 0;
    for (let i = 0; i < n; i++) if (a[i * 4] !== 255 || a[i * 4 + 1] !== 255 || a[i * 4 + 2] !== 255) c++;
    return c;
  }
  const u16 = (s) => { const p = mod._malloc(s.length * 2 + 2); for (let i = 0; i < s.length; i++) mod.HEAPU16[(p >> 1) + i] = s.charCodeAt(i); return p; };

  check(resize(1264, 741 + 0) !== undefined, 'resize');
  const jww = fs.readFileSync(path.join(root, 'orig', 'Test1.jww'));
  let p = put(jww);
  const r = open(p, jww.length);
  check(r === 1, 'open Test1.jww -> ' + r);
  check(nobj() > 0, 'nobj ' + nobj());
  fit();
  const ink0 = inkCount();
  check(ink0 > 1000, 'painted pixels ' + ink0);
  zoom(1.5, 400, 300); pan(10, -10); fit();

  // draw: select the line command, click twice
  const before = nobj();
  command(0x8003);
  press(300, 400, 0); move(500, 450); press(500, 450, 0);
  press(600, 300, 0); press(700, 500, 0);
  command(0x8005);
  press(500, 400, 0); press(560, 400, 0);
  console.log('objects ' + before + ' -> ' + nobj());
  check(nobj() > before, 'drawing added objects');
  check(modified() === 1, 'modified');

  // save and reopen
  const sp = save();
  const saved = out(sp);
  check(saved && saved.length > 1000, 'save -> ' + (saved && saved.length));
  fs.writeFileSync(path.join(outDir, 'smoke_saved.jww'), saved);
  const n1 = nobj();
  p = put(saved);
  check(open(p, saved.length) === 1, 'reopen saved');
  // saving puts the six hidden settings records on, as the original does
  check(nobj() === n1 || nobj() === n1 + 6, 'object count kept ' + nobj() + ' vs ' + n1);

  // exports
  for (const [nm, args] of [['jw_save_dxf', []], ['jw_save_jwc', []], ['jw_save_fig', []], ['jw_save_coord', []]]) {
    let g;
    try { g = f(nm, 'number', args)(); } catch (e) { console.log('BAD  ' + nm + ' threw ' + e); fails++; continue; }
    const b = out(g);
    console.log(nm + ' -> ' + (b ? b.length : 'null'));
    if (nm === 'jw_save_dxf' || nm === 'jw_save_jwc') check(b && b.length > 100, nm);
    if (nm === 'jw_save_dxf' && b) {
      fs.writeFileSync(path.join(outDir, 'smoke_saved.dxf'), b);
      const q = put(b);
      check(f('jw_open_dxf', 'number', ['number', 'number'])(q, b.length) === 1, 'reopen dxf');
    }
    if (nm === 'jw_save_jwc' && b) {
      const q = put(b);
      check(f('jw_open_jwc', 'number', ['number', 'number'])(q, b.length) === 1, 'reopen jwc');
    }
  }
  {
    const nm = mod._malloc(16); mod.HEAPU8.set(Buffer.from('test\0'), nm);
    const g = f('jw_save_sfc', 'number', ['number'])(nm);
    const b = out(g);
    check(b && b.length > 100, 'save sfc ' + (b && b.length));
    if (b) check(f('jw_open_sfc', 'number', ['number', 'number'])(put(b), b.length) === 1, 'reopen sfc');
    const e = f('jw_save_env', 'number', ['number'])(nm);
    const eb = out(e);
    check(eb && eb.length > 10, 'save env ' + (eb && eb.length));
    if (eb) check(f('jw_open_env', 'number', ['number', 'number'])(put(eb), eb.length) === 1, 'reopen env');
  }
  // plot
  for (const as of [0, 1]) {
    const b = out(f('jw_plot', 'number', ['number', 'number'])(as, 1));
    check(b && b.length > 100, 'plot as_png=' + as + ' ' + (b && b.length));
  }
  // image: insert a generated PNG/BMP/JPEG
  const imgdir = path.join(root, 'tmp', 'img');
  for (const fn of ['dec_rgb.png', 'dec_rgb24.bmp', 'dec_q95.jpg']) {
    const fp = path.join(imgdir, fn);
    if (!fs.existsSync(fp)) { console.log('skip ' + fn); continue; }
    const b = fs.readFileSync(fp);
    const np = u16('C:\\pics\\' + fn);
    const ok = f('jw_image', 'number', ['number', 'number', 'number', 'number'])(np, ('C:\\pics\\' + fn).length, put(b), b.length);
    check(ok === 1, 'image insert ' + fn);
  }
  command(0x80f5);
  press(300, 300, 0); press(500, 500, 0);
  const sv = out(save());
  check(sv && sv.length > 1000, 'save with images ' + (sv && sv.length));
  const oc = f('jw_image_out_count', 'number', [])();
  console.log('image_out_count ' + oc);
  // damaged inputs through the page entry points
  for (const [nm, name] of [['jw_open', 'orig/Test1.jww'], ['jw_open_dxf', null], ['jw_open_sfc', null], ['jw_open_jwc', null], ['jw_open_env', null]]) {
    const src = name ? fs.readFileSync(path.join(root, name)) : Buffer.from('garbage\n0\nSECTION\n');
    for (const cut of [0, 1, 7, 100, src.length >> 1]) {
      const b = src.subarray(0, Math.min(cut, src.length));
      try { f(nm, 'number', ['number', 'number'])(put(b), b.length); } catch (e) { console.log('BAD  ' + nm + ' cut ' + cut + ' threw ' + e); fails++; }
    }
  }
  check(true, 'damaged inputs came back');
  console.log(fails ? 'FAILED ' + fails : 'ALL OK');
  process.exit(fails ? 1 : 0);
})().catch(e => { console.log('BAD  exception ' + (e && e.stack || e)); process.exit(2); });
