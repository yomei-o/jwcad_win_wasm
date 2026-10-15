/* Offline support: whatever the page fetches from this site is kept, and used
   when the network is not there.  Online, the network answers first, so a
   new build shows up on the next load. */
const CACHE = 'jw-port-v1';
// everything the page needs, so the first visit is enough: the program, the fonts, the icons
const FIRST = ['./', 'index.html', 'cmdlist.js', 'jwcad.js', 'jwcad.wasm', 'manifest.webmanifest', 'icon.svg', 'icon-192.png', 'icon-512.png',
  'fonts/jwsubgothic.ttf', 'fonts/jwsubmincho.ttf', 'fonts/bizudgothic-sub.ttf',
  'fonts/jwsubsans.ttf', 'fonts/jwsubserif.ttf'];

self.addEventListener('install', e => {
  e.waitUntil(caches.open(CACHE).then(c => c.addAll(FIRST)).then(() => self.skipWaiting()));
});

self.addEventListener('activate', e => {
  e.waitUntil(caches.keys()
    .then(ks => Promise.all(ks.filter(k => k !== CACHE).map(k => caches.delete(k))))
    .then(() => self.clients.claim()));
});

self.addEventListener('fetch', e => {
  const req = e.request;
  if (req.method !== 'GET' || new URL(req.url).origin !== location.origin) return;
  e.respondWith(
    fetch(req).then(res => {
      if (res && res.ok) {
        const copy = res.clone();
        caches.open(CACHE).then(c => c.put(req, copy));
      }
      return res;
    }).catch(() => caches.match(req).then(r => r || caches.match(req, { ignoreSearch: true }))
      .then(r => r || (req.mode === 'navigate' ? caches.match('index.html') : Response.error()))));
});
