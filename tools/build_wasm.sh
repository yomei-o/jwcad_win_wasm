#!/bin/sh
# Build the browser front end with emscripten, at low priority (tools/lowpri.sh).
#
# Output lands in the repository root because GitHub Pages serves main:/ .
set -e
cd "$(dirname "$0")/.."
EMSDK="${EMSDK:-/c/prog/emsdk/emsdk}"
EMCC="$EMSDK/upstream/emscripten/emcc.exe"
[ -f "$EMCC" ] || { echo "emcc not found at $EMCC" >&2; exit 1; }

EXPORTS=_main,_jw_resize,_jw_width,_jw_height,_jw_rgba,_malloc,_free
EXPORTS=$EXPORTS,_jw_open,_jw_error,_jw_nobj,_jw_zoom,_jw_pan,_jw_fit
EXPORTS=$EXPORTS,_jw_press,_jw_move
EXPORTS=$EXPORTS,_jw_save,_jw_saved_len,_jw_saved_free
EXPORTS=$EXPORTS,_jw_key,_jw_key_u,_jw_compose_u,_jw_text_in,_jw_cmd_id,_jw_box_focus,_jw_chrome_h,_jw_name
SRC="src/main_wasm.c src/cp932.c src/pick.c src/app.c src/cmd.c src/ui.c src/fb.c src/jww.c src/jwwrite.c src/view.c src/draw.c src/text.c src/fontx.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"

# `cmd /c start /WAIT` does not hand emcc's exit status back, so without the
# check at the end a compile error is announced as a successful build and the
# stale .wasm stays in place.
mkdir -p tmp
STAMP=tmp/.wasm-stamp
: > "$STAMP"

sh tools/lowpri.sh "$EMCC" -O2 -Wall -Wextra -Isrc \
   -o jwcad.js \
   $SRC \
   -s MODULARIZE=1 -s EXPORT_NAME=createJwcad \
   -s EXPORTED_RUNTIME_METHODS=HEAPU8,HEAPU16,ccall,cwrap,UTF8ToString \
   -s ALLOW_MEMORY_GROWTH=1 -s ENVIRONMENT=web,node \
   -s EXPORTED_FUNCTIONS="$EXPORTS"

if [ ! -f jwcad.wasm ] || [ ! jwcad.wasm -nt "$STAMP" ]; then
    echo "emcc did not rewrite jwcad.wasm - the build failed" >&2
    exit 1
fi
echo "built jwcad.js + jwcad.wasm"
