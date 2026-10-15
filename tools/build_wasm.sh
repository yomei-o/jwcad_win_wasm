#!/bin/sh
# Build the browser front end with emscripten, at low priority (tools/lowpri.sh).
#
# Output lands in the repository root because GitHub Pages serves main:/ .
# WASM_OUT=<dir> builds somewhere else instead (tools/ci.sh does, so the
# shipped jwcad.js and jwcad.wasm are left alone).
set -e
cd "$(dirname "$0")/.."
EMSDK="${EMSDK:-/c/prog/emsdk/emsdk}"
EMCC="$EMSDK/upstream/emscripten/emcc.exe"
[ -f "$EMCC" ] || { echo "emcc not found at $EMCC" >&2; exit 1; }

EXPORTS=_main,_jw_resize,_jw_width,_jw_height,_jw_rgba,_malloc,_free
EXPORTS=$EXPORTS,_jw_open,_jw_error,_jw_nobj,_jw_zoom,_jw_pan,_jw_fit,_jw_save_dxf,_jw_save_sfc,_jw_save_jwc,_jw_save_env,_jw_open_env,_jw_open_dxf,_jw_open_sfc,_jw_open_jwc,_jw_figure,_jw_bunyomi,_jw_save_fig,_jw_save_coord,_jw_coord,_jw_image,_jw_image_store,_jw_image_out_count,_jw_image_out_name,_jw_image_out_ptr,_jw_image_out_len
EXPORTS=$EXPORTS,_jw_press,_jw_move,_jw_command,_jw_modified,_jw_new,_jw_new_count
EXPORTS=$EXPORTS,_jw_save,_jw_saved_len,_jw_saved_free,_jw_plot
EXPORTS=$EXPORTS,_jw_key,_jw_key_u,_jw_compose_u,_jw_text_in,_jw_cmd_id,_jw_box_focus,_jw_chrome_h,_jw_name,_jw_shift_enter
EXPORTS=$EXPORTS,_jw_font_pending,_jw_font_file,_jw_font_put,_jw_font_fail,_jw_repaint
SRC="src/main_wasm.c src/cp932.c src/pick.c src/app.c src/cmd.c src/ui.c src/fb.c src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/houraku.c src/tategu.c src/senkigou.c src/takaku.c src/hikage.c src/tenku.c src/tenku_sansha.c src/d25view.c src/view.c src/draw.c src/text.c src/fontx.c src/outfont.c src/image.c src/imgpic.c src/plot.c src/png.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"

# `cmd /c start /WAIT` does not hand emcc's exit status back, so without the
# check at the end a compile error is announced as a successful build and the
# stale .wasm stays in place.
OUT="${WASM_OUT:-.}"
mkdir -p tmp "$OUT"
STAMP=tmp/.wasm-stamp
: > "$STAMP"

sh tools/lowpri.sh "$EMCC" -O2 -Wall -Wextra -Isrc \
   -o "$OUT/jwcad.js" \
   $SRC \
   -s MODULARIZE=1 -s EXPORT_NAME=createJwcad \
   -s EXPORTED_RUNTIME_METHODS=HEAPU8,HEAPU16,ccall,cwrap,UTF8ToString \
   -s ALLOW_MEMORY_GROWTH=1 -s ENVIRONMENT=web,node \
   -s EXPORTED_FUNCTIONS="$EXPORTS"

if [ ! -f "$OUT/jwcad.wasm" ] || [ ! "$OUT/jwcad.wasm" -nt "$STAMP" ]; then
    echo "emcc did not rewrite jwcad.wasm - the build failed" >&2
    exit 1
fi
echo "built jwcad.js + jwcad.wasm"
