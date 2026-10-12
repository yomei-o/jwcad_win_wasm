cd /c/prog/claude2/jwcad_win_wasm
for d in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do [ -x "$d/gcc.exe" ] && PATH="$d:$PATH" && break; done
OBJ=$(ls tmp/ob/*.o | grep -v replay)
gcc -O1 -w -std=c99 -Isrc -Itests -o tmp/q_e2.exe tools/escprobe_port.c tests/png.c $OBJ -lm || exit 1
# JWFILE=decomp/res/new.jww sh tools/escprobe_port.sh  (then run tmp/q_e2.exe "name|steps")
