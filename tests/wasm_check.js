// Render the frame in the WASM build and write it out, so tools/cmp.py can
// hold it against the native build's PNG.  Both go through the same src/*.c,
// so any difference is the port depending on its environment.
//
//   node tests/wasm_check.js tests/out/wasm.png [w h]
const fs = require('fs');
const path = require('path');
const createJwcad = require(path.resolve(__dirname, '..', 'jwcad.js'));

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

(async function () {
  const out = process.argv[2] || 'tests/out/wasm.png';
  const w = parseInt(process.argv[3] || '1264', 10);
  const h = parseInt(process.argv[4] || '741', 10);
  const mod = await createJwcad();

  mod.ccall('jw_resize', 'number', ['number', 'number'], [w, h]);
  const p = mod.ccall('jw_rgba', 'number', [], []);
  const px = mod.HEAPU8.subarray(p, p + w * h * 4);

  const raw = Buffer.alloc(h * (1 + w * 3));
  let o = 0;
  for (let y = 0; y < h; y++) {
    raw[o++] = 0;
    for (let x = 0; x < w; x++) {
      const i = (y * w + x) * 4;
      raw[o++] = px[i]; raw[o++] = px[i + 1]; raw[o++] = px[i + 2];
    }
  }
  const zlib = require('zlib');
  const ihdr = Buffer.alloc(13);
  ihdr.writeUInt32BE(w, 0); ihdr.writeUInt32BE(h, 4);
  ihdr[8] = 8; ihdr[9] = 2;
  fs.mkdirSync(path.dirname(out), { recursive: true });
  fs.writeFileSync(out, Buffer.concat([
    Buffer.from([137, 80, 78, 71, 13, 10, 26, 10]),
    chunk('IHDR', ihdr),
    chunk('IDAT', zlib.deflateSync(raw)),
    chunk('IEND', Buffer.alloc(0)),
  ]));
  console.log('wrote ' + out + ' (' + w + 'x' + h + ')');
})();
