#!/bin/sh
# tools/skall_t.py が作った。文字を打って置かせる
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
only="$*"
S="sh tools/skprobe.sh"
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A10t.jww ] || $S A10t A 10 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A15t.jww ] || $S A15t A 15 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A16t.jww ] || $S A16t A 16 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A17t.jww ] || $S A17t A 17 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A18t.jww ] || $S A18t A 18 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A19t.jww ] || $S A19t A 19 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A20t.jww ] || $S A20t A 20 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A21t.jww ] || $S A21t A 21 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A22t.jww ] || $S A22t A 22 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B01t.jww ] || $S B01t B 1 '' 'wait:900;500,450;wait:700;580,350;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B02t.jww ] || $S B02t B 2 '' 'wait:900;500,450;wait:700;580,350;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B03t.jww ] || $S B03t B 3 '' 'wait:900;500,450;wait:700;580,350;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B04t.jww ] || $S B04t B 4 '' 'wait:900;500,450;wait:700;580,350;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B05t.jww ] || $S B05t B 5 '' 'wait:900;500,450;wait:700;580,350;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B06t.jww ] || $S B06t B 6 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B11t.jww ] || $S B11t B 11 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B12t.jww ] || $S B12t B 12 '' 'wait:900;450,400;wait:700;500,470;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B17t.jww ] || $S B17t B 17 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B18t.jww ] || $S B18t B 18 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B19t.jww ] || $S B19t B 19 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B20t.jww ] || $S B20t B 20 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D12t.jww ] || $S D12t D 12 '' 'wait:900;450,400;wait:700;500,470;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D14t.jww ] || $S D14t D 14 '' 'wait:900;450,400;wait:700;500,470;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D15t.jww ] || $S D15t D 15 '' 'wait:900;450,400;wait:700;500,470;wait:700;type::AB;wait:500;700,300;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E17t.jww ] || $S E17t E 17 '' 'wait:900;500,450;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " H "; then
  [ -f decomp/res/sk_H02t.jww ] || $S H02t H 2 '' 'wait:900;450,400;wait:700;500,470;wait:700;type::AB;wait:500;700,300;wait:700;'
fi
echo done
