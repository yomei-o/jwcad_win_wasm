// Render the frame in the WASM build and write it out, so tools/cmp.py can
// hold it against the native build's PNG.  Both go through the same src/*.c,
// so any difference is the port depending on its environment.
//
//   node tests/wasm_check.js tests/out/wasm.png [w h] [--chrome]
//                             [--open drawing.jww]
//
// With --open the drawing goes in first, so a whole picture can be held
// against the native build's, not just the empty frame.
//
// The browser build draws its own caption and menu bar above the client
// (the native window gets those from Windows).  By default they are left
// off the picture so it can be held against the native one pixel for
// pixel; --chrome keeps them, which is how the chrome itself is scored.
const fs = require('fs');
const path = require('path');
/* JW_WASM points at another build of the module -- a sanitized one, say.
   Without it the module beside the repository root is used. */
const createJwcad = require(process.env.JW_WASM ||
                            path.resolve(__dirname, '..', 'jwcad.js'));

function crcTable() {
  const t = new Uint32Array(256);
  for (let n = 0; n < 256; n++) {
    let c = n;
    for (let k = 0; k < 8; k++) c = (c & 1) ? (0xedb88320 ^ (c >>> 1)) : (c >>> 1);
    t[n] = c >>> 0;
  }
  return t;
}
const TAB = crcTable();
function crc32(buf) {
  let c = 0xffffffff;
  for (let i = 0; i < buf.length; i++) c = TAB[(c ^ buf[i]) & 0xff] ^ (c >>> 8);
  return (c ^ 0xffffffff) >>> 0;
}
function chunk(tag, data) {
  const len = Buffer.alloc(4);
  len.writeUInt32BE(data.length);
  const body = Buffer.concat([Buffer.from(tag, 'latin1'), data]);
  const crc = Buffer.alloc(4);
  crc.writeUInt32BE(crc32(body));
  return Buffer.concat([len, body, crc]);
}

// One drawing: open it if given, render, write the PNG.
function shot(mod, drawing, out, w, h, withChrome) {
  const ch = mod.ccall('jw_chrome_h', 'number', [], []);
  const skip = withChrome ? 0 : ch;
  const rows = withChrome ? h + ch : h;     /* what goes in the picture */
  mod.ccall('jw_resize', 'number', ['number', 'number'], [w, h + ch]);
  if (drawing) {
    const bytes = fs.readFileSync(drawing);
    const buf = mod._malloc(bytes.length);
    mod.HEAPU8.set(bytes, buf);
    const ok = mod.ccall('jw_open', 'number', ['number', 'number'],
                         [buf, bytes.length]);
    mod._free(buf);
    if (!ok) {
      console.error('cannot read ' + drawing);
      return false;
    }
  }
  const p = mod.ccall('jw_rgba', 'number', [], []);
  const px = mod.HEAPU8.subarray(p, p + w * (h + ch) * 4);

  const raw = Buffer.alloc(rows * (1 + w * 3));
  let o = 0;
  for (let y0 = 0; y0 < rows; y0++) {
    const y = y0 + skip;
    raw[o++] = 0;
    for (let x = 0; x < w; x++) {
      const i = (y * w + x) * 4;
      raw[o++] = px[i]; raw[o++] = px[i + 1]; raw[o++] = px[i + 2];
    }
  }
  const zlib = require('zlib');
  const ihdr = Buffer.alloc(13);
  ihdr.writeUInt32BE(w, 0); ihdr.writeUInt32BE(rows, 4);
  ihdr[8] = 8; ihdr[9] = 2;
  fs.mkdirSync(path.dirname(out), { recursive: true });
  fs.writeFileSync(out, Buffer.concat([
    Buffer.from([137, 80, 78, 71, 13, 10, 26, 10]),
    chunk('IHDR', ihdr),
    chunk('IDAT', zlib.deflateSync(raw)),
    chunk('IEND', Buffer.alloc(0)),
  ]));
  console.log('wrote ' + out + ' (' + w + 'x' + rows + ')');
  return true;
}

/* The entry points the page calls that nothing else drives.  The native
   tests all go straight at app_*, so src/main_wasm.c's own code -- the
   UTF-16 that comes off an IME, and the file name that goes in the caption
   -- is only ever reached from here.  jw_from_utf16 returns what the text
   WOULD take rather than what fitted, and jw_name once wrote its NUL off
   the end of a 128-byte frame on the strength of that. */
function api(mod) {
  let bad = 0;
  const say = function (ok, what) {
    if (!ok) { console.log('BAD  ' + what); bad++; }
    else console.log('ok   ' + what);
  };
  const utf16 = function (str) {
    const n = str.length;
    const p = mod.ccall('malloc', 'number', ['number'], [2 * n]);
    for (let i = 0; i < n; i++)
      mod.HEAPU16[(p >> 1) + i] = str.charCodeAt(i);
    return { p: p, n: n };
  };
  mod.ccall('jw_resize', 'number', ['number', 'number'], [1264, 741]);

  /* a name far longer than the caption buffer, in characters that are two
     CP932 bytes each, so what it "would take" is four times the length */
  let s = '';
  for (let i = 0; i < 400; i++) s += String.fromCharCode(0x3042 + (i % 80));
  let a = utf16(s);
  mod.ccall('jw_name', null, ['number', 'number'], [a.p, a.n]);
  mod.ccall('free', null, ['number'], [a.p]);
  say(true, 'jw_name survives a 400-character name');

  /* and one just over: the caption buffer is 128 bytes, so 70 two-byte
     characters put the NUL a dozen past the end -- which is where a
     sanitizer's red zone is.  A much longer name overshoots the red zone
     into other live stack and is not noticed, so this is the length that
     has teeth. */
  let just = '';
  for (let i = 0; i < 70; i++) just += String.fromCharCode(0x3042 + (i % 80));
  a = utf16(just);
  mod.ccall('jw_name', null, ['number', 'number'], [a.p, a.n]);
  mod.ccall('free', null, ['number'], [a.p]);
  say(true, 'jw_name survives one just over the caption buffer');

  a = utf16('');
  mod.ccall('jw_name', null, ['number', 'number'], [a.p, 0]);
  mod.ccall('free', null, ['number'], [a.p]);
  say(true, 'jw_name survives an empty one');

  /* text straight in, longer than its 512-byte buffer */
  a = utf16(s);
  mod.ccall('jw_text_in', 'number', ['number', 'number'], [a.p, a.n]);
  mod.ccall('free', null, ['number'], [a.p]);
  say(true, 'jw_text_in survives more than it can hold');

  /* one unit at a time, the way an IME sends it, including the edges */
  for (const c of [0x41, 0x3042, 0xff9f, 0xd800, 0xdfff, 0xffff, 0]) {
    mod.ccall('jw_key_u', 'number', ['number'], [c]);
    mod.ccall('jw_compose_u', 'number', ['number'], [c]);
  }
  mod.ccall('jw_compose_u', 'number', ['number'], [-1]);
  say(true, 'jw_key_u and jw_compose_u take every kind of unit');

  /* junk at the file readers, which the page hands straight over */
  const junk = mod.ccall('malloc', 'number', ['number'], [64]);
  for (let i = 0; i < 64; i++) mod.HEAPU8[junk + i] = (i * 37) & 255;
  for (const f of ['jw_open', 'jw_open_dxf', 'jw_open_sfc', 'jw_open_jwc',
                   'jw_figure', 'jw_coord']) {
    mod.ccall(f, 'number', ['number', 'number'], [junk, 64]);
    mod.ccall(f, 'number', ['number', 'number'], [junk, 0]);
  }
  mod.ccall('free', null, ['number'], [junk]);
  say(true, 'the readers take junk and nothing of it');

  return bad;
}

(async function () {
  const mod = await createJwcad();

  if (process.argv[2] === '--api') {
    process.exit(api(mod) ? 1 : 0);
  }

  /* --each <list> <dir> [w h]: every drawing named in the list file, one
     PNG each in that directory, all from one start of the module.  Starting
     node and loading the WebAssembly costs more than the drawing does, so
     doing the lot in one go is what makes the whole-set check bearable. */
  if (process.argv[2] === '--each') {
    const list = fs.readFileSync(process.argv[3], 'utf8')
                   .split(String.fromCharCode(10))
                   .map(function (t) { return t.trim(); });
    const dir = process.argv[4];
    const w = parseInt(process.argv[5] || '1264', 10);
    const h = parseInt(process.argv[6] || '741', 10);
    let bad = 0;
    fs.mkdirSync(dir, { recursive: true });
    for (const name of list) {
      if (!name) continue;
      const out = path.join(dir, path.basename(name) + '.png');
      if (!shot(mod, name, out, w, h, false))
        bad++;
    }
    process.exit(bad ? 1 : 0);
  }

  const out = process.argv[2] || 'tests/out/wasm.png';
  const w = parseInt(process.argv[3] || '1264', 10);
  const h = parseInt(process.argv[4] || '741', 10);
  const withChrome = process.argv.indexOf('--chrome') >= 0;
  const openAt = process.argv.indexOf('--open');
  if (!shot(mod, openAt >= 0 ? process.argv[openAt + 1] : null, out, w, h,
            withChrome))
    process.exit(1);
})();
