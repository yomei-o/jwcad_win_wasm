#!/bin/sh
# Packaging, no installer:
#   sh tools/package.sh            build both and make dist/
#   sh tools/package.sh --no-wasm  use the jwcad.js/.wasm already in the repository root
#
# dist/jw_port-win64.zip   jw_port.exe, fonts/, README.md, readme.txt -- unzip anywhere and run
# dist/web/                index.html, jwcad.js, jwcad.wasm, sw.js, manifest.webmanifest, icons, fonts/
#                          every path in it is relative, so the folder can be put under any URL
#                          (GitHub Pages: copy dist/web to the branch it serves; .nojekyll is in it)
# dist/jwcad-web.zip       the same folder as one file
cd "$(dirname "$0")/.."
set -e
NOWASM=0
[ "$1" = "--no-wasm" ] && NOWASM=1

rm -rf dist
mkdir -p dist/web/fonts dist/win/fonts

# ---- the Windows program
sh tools/build_native.sh
cp jw_port.exe dist/win/
cp fonts/*.ttf fonts/*.txt dist/win/fonts/ 2>/dev/null || true
cp README.md dist/win/
cat > dist/win/readme.txt <<'EOF'
Jw_cad for Windows (port)  --  jw_port.exe

Unzip anywhere and run jw_port.exe (keep the fonts folder beside it).
  jw_port.exe [drawing.jww]       .jww, .dxf, .sfc, .jwc can also be dropped on the window
Settings, the recent files and the autosave copy are kept in %APPDATA%\jw_port.
README.md says what it does and how it was checked.
EOF

# ---- the web build
if [ "$NOWASM" = 0 ]; then
    for d in /c/prog/emsdk/emsdk/python/*/ ; do [ -d "$d" ] && PATH="$d:$PATH"; done
    for n in /c/prog/emsdk/emsdk/node/*/ ; do [ -d "$n" ] && PATH="$n:$PATH"; done
    export PATH
    WASM_OUT=dist/web sh tools/build_wasm.sh
else
    cp jwcad.js jwcad.wasm dist/web/
fi
cp index.html cmdlist.js sw.js manifest.webmanifest icon.svg icon-192.png icon-512.png dist/web/
cp fonts/*.ttf fonts/*.txt dist/web/fonts/ 2>/dev/null || true
: > dist/web/.nojekyll
# the page loads jwcad.js?v=N: the number is the build, so a new build is not served from a cache
STAMP=$(date +%Y%m%d%H%M)
sed -i "s|jwcad.js?v=[0-9a-z]*|jwcad.js?v=$STAMP|" dist/web/index.html
# the service worker's cache name follows it, so a new build replaces the old one's files
sed -i "s|const CACHE = 'jw-port-[^']*'|const CACHE = 'jw-port-$STAMP'|" dist/web/sw.js

# ---- zips (PowerShell is what a Windows machine has)
ZIPWIN=$(cygpath -w "$PWD/dist/jw_port-win64.zip")
ZIPWEB=$(cygpath -w "$PWD/dist/jwcad-web.zip")
powershell.exe -NoProfile -Command "Compress-Archive -Force -Path '$(cygpath -w "$PWD/dist/win")\\*' -DestinationPath '$ZIPWIN'"
powershell.exe -NoProfile -Command "Compress-Archive -Force -Path '$(cygpath -w "$PWD/dist/web")\\*' -DestinationPath '$ZIPWEB'"
ls -la dist dist/web | sed 's/^/    /'
echo "packaged: dist/jw_port-win64.zip dist/jwcad-web.zip dist/web/"
