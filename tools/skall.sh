#!/bin/sh
# tools/skall.py が作った。全記号を原典に置かせる
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
only="$*"
S="sh tools/skprobe.sh"
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A01.jww ] || $S A01 A 1 '' 'wait:900;450,400;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A02.jww ] || $S A02 A 2 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A03.jww ] || $S A03 A 3 '' 'wait:900;500,450;wait:700;580,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A04.jww ] || $S A04 A 4 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A05.jww ] || $S A05 A 5 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A06.jww ] || $S A06 A 6 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A07.jww ] || $S A07 A 7 '' 'wait:900;450,400;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A08.jww ] || $S A08 A 8 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A09.jww ] || $S A09 A 9 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A10.jww ] || $S A10 A 10 '' 'wait:900;500,450;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A11.jww ] || $S A11 A 11 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A12.jww ] || $S A12 A 12 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A13.jww ] || $S A13 A 13 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A14.jww ] || $S A14 A 14 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A15.jww ] || $S A15 A 15 '' 'wait:900;500,450;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A16.jww ] || $S A16 A 16 '' 'wait:900;500,450;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A17.jww ] || $S A17 A 17 '' 'wait:900;500,450;wait:700;700,300;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A18.jww ] || $S A18 A 18 '' 'wait:900;500,450;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A19.jww ] || $S A19 A 19 '' 'wait:900;500,450;wait:700;700,300;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A20.jww ] || $S A20 A 20 '' 'wait:900;500,450;wait:700;700,300;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A21.jww ] || $S A21 A 21 '' 'wait:900;500,450;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A22.jww ] || $S A22 A 22 '' 'wait:900;500,450;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A23.jww ] || $S A23 A 23 '' 'wait:900;500,450;wait:700;580,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A24.jww ] || $S A24 A 24 '' 'wait:900;500,450;wait:700;580,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A25.jww ] || $S A25 A 25 '' 'wait:900;500,450;wait:700;580,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A26.jww ] || $S A26 A 26 '' 'wait:900;500,450;wait:700;580,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A27.jww ] || $S A27 A 27 '' 'wait:900;500,450;wait:700;580,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A28.jww ] || $S A28 A 28 '' 'wait:900;500,450;wait:700;580,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A29.jww ] || $S A29 A 29 '' 'wait:900;500,450;wait:700;580,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " A "; then
  [ -f decomp/res/sk_A30.jww ] || $S A30 A 30 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B01.jww ] || $S B01 B 1 '' 'wait:900;500,450;wait:700;580,350;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B02.jww ] || $S B02 B 2 '' 'wait:900;500,450;wait:700;580,350;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B03.jww ] || $S B03 B 3 '' 'wait:900;500,450;wait:700;580,350;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B04.jww ] || $S B04 B 4 '' 'wait:900;500,450;wait:700;580,350;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B05.jww ] || $S B05 B 5 '' 'wait:900;500,450;wait:700;580,350;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B06.jww ] || $S B06 B 6 '' 'wait:900;500,450;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B07.jww ] || $S B07 B 7 '' 'wait:900;500,450;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B08.jww ] || $S B08 B 8 '' 'wait:900;500,450;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B09.jww ] || $S B09 B 9 '' 'wait:900;500,450;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B10.jww ] || $S B10 B 10 '' 'wait:900;500,450;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B11.jww ] || $S B11 B 11 '' 'wait:900;500,450;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B12.jww ] || $S B12 B 12 '' 'wait:900;450,400;wait:700;500,470;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B13.jww ] || $S B13 B 13 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B14.jww ] || $S B14 B 14 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B15.jww ] || $S B15 B 15 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B16.jww ] || $S B16 B 16 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B17.jww ] || $S B17 B 17 '' 'wait:900;500,450;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B18.jww ] || $S B18 B 18 '' 'wait:900;500,450;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B19.jww ] || $S B19 B 19 '' 'wait:900;500,450;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " B "; then
  [ -f decomp/res/sk_B20.jww ] || $S B20 B 20 '' 'wait:900;500,450;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C01.jww ] || $S C01 C 1 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C02.jww ] || $S C02 C 2 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C03.jww ] || $S C03 C 3 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C04.jww ] || $S C04 C 4 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C05.jww ] || $S C05 C 5 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C06.jww ] || $S C06 C 6 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C07.jww ] || $S C07 C 7 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C08.jww ] || $S C08 C 8 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C09.jww ] || $S C09 C 9 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C10.jww ] || $S C10 C 10 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C11.jww ] || $S C11 C 11 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C12.jww ] || $S C12 C 12 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C13.jww ] || $S C13 C 13 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C14.jww ] || $S C14 C 14 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C15.jww ] || $S C15 C 15 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " C "; then
  [ -f decomp/res/sk_C16.jww ] || $S C16 C 16 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D01.jww ] || $S D01 D 1 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D02.jww ] || $S D02 D 2 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D03.jww ] || $S D03 D 3 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D04.jww ] || $S D04 D 4 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D05.jww ] || $S D05 D 5 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D06.jww ] || $S D06 D 6 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D07.jww ] || $S D07 D 7 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D08.jww ] || $S D08 D 8 '' 'wait:900;450,400;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D09.jww ] || $S D09 D 9 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D10.jww ] || $S D10 D 10 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D11.jww ] || $S D11 D 11 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D12.jww ] || $S D12 D 12 '' 'wait:900;450,400;wait:700;500,470;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D13.jww ] || $S D13 D 13 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D14.jww ] || $S D14 D 14 '' 'wait:900;450,400;wait:700;500,470;wait:700;700,300;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D15.jww ] || $S D15 D 15 '' 'wait:900;450,400;wait:700;500,470;wait:700;700,300;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " D "; then
  [ -f decomp/res/sk_D16.jww ] || $S D16 D 16 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E01.jww ] || $S E01 E 1 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E02.jww ] || $S E02 E 2 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E03.jww ] || $S E03 E 3 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E04.jww ] || $S E04 E 4 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E05.jww ] || $S E05 E 5 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E06.jww ] || $S E06 E 6 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E07.jww ] || $S E07 E 7 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E08.jww ] || $S E08 E 8 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E09.jww ] || $S E09 E 9 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E10.jww ] || $S E10 E 10 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E11.jww ] || $S E11 E 11 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E12.jww ] || $S E12 E 12 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E13.jww ] || $S E13 E 13 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E14.jww ] || $S E14 E 14 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E15.jww ] || $S E15 E 15 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E16.jww ] || $S E16 E 16 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " E "; then
  [ -f decomp/res/sk_E17.jww ] || $S E17 E 17 '' 'wait:900;500,450;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F01.jww ] || $S F01 F 1 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F02.jww ] || $S F02 F 2 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F03.jww ] || $S F03 F 3 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F04.jww ] || $S F04 F 4 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F05.jww ] || $S F05 F 5 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F06.jww ] || $S F06 F 6 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F07.jww ] || $S F07 F 7 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F08.jww ] || $S F08 F 8 '' 'wait:900;450,400;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F09.jww ] || $S F09 F 9 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F10.jww ] || $S F10 F 10 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F11.jww ] || $S F11 F 11 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F12.jww ] || $S F12 F 12 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F13.jww ] || $S F13 F 13 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " F "; then
  [ -f decomp/res/sk_F14.jww ] || $S F14 F 14 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G01.jww ] || $S G01 G 1 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G02.jww ] || $S G02 G 2 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G03.jww ] || $S G03 G 3 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G04.jww ] || $S G04 G 4 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G05.jww ] || $S G05 G 5 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G06.jww ] || $S G06 G 6 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G07.jww ] || $S G07 G 7 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G08.jww ] || $S G08 G 8 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G09.jww ] || $S G09 G 9 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G10.jww ] || $S G10 G 10 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G11.jww ] || $S G11 G 11 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G12.jww ] || $S G12 G 12 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " G "; then
  [ -f decomp/res/sk_G13.jww ] || $S G13 G 13 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " H "; then
  [ -f decomp/res/sk_H01.jww ] || $S H01 H 1 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " H "; then
  [ -f decomp/res/sk_H02.jww ] || $S H02 H 2 '' 'wait:900;450,400;wait:700;500,470;wait:700;700,300;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " H "; then
  [ -f decomp/res/sk_H03.jww ] || $S H03 H 3 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " H "; then
  [ -f decomp/res/sk_H04.jww ] || $S H04 H 4 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " H "; then
  [ -f decomp/res/sk_H05.jww ] || $S H05 H 5 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " H "; then
  [ -f decomp/res/sk_H06.jww ] || $S H06 H 6 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " H "; then
  [ -f decomp/res/sk_H07.jww ] || $S H07 H 7 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " H "; then
  [ -f decomp/res/sk_H08.jww ] || $S H08 H 8 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I01.jww ] || $S I01 I 1 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I02.jww ] || $S I02 I 2 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I03.jww ] || $S I03 I 3 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I04.jww ] || $S I04 I 4 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I05.jww ] || $S I05 I 5 '' 'wait:900;450,400;wait:700;500,470;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I06.jww ] || $S I06 I 6 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I07.jww ] || $S I07 I 7 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I08.jww ] || $S I08 I 8 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I09.jww ] || $S I09 I 9 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I10.jww ] || $S I10 I 10 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I11.jww ] || $S I11 I 11 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I12.jww ] || $S I12 I 12 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I13.jww ] || $S I13 I 13 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I14.jww ] || $S I14 I 14 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " I "; then
  [ -f decomp/res/sk_I15.jww ] || $S I15 I 15 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " J "; then
  [ -f decomp/res/sk_J01.jww ] || $S J01 J 1 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " J "; then
  [ -f decomp/res/sk_J02.jww ] || $S J02 J 2 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " J "; then
  [ -f decomp/res/sk_J03.jww ] || $S J03 J 3 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " J "; then
  [ -f decomp/res/sk_J04.jww ] || $S J04 J 4 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " J "; then
  [ -f decomp/res/sk_J05.jww ] || $S J05 J 5 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " J "; then
  [ -f decomp/res/sk_J06.jww ] || $S J06 J 6 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " J "; then
  [ -f decomp/res/sk_J07.jww ] || $S J07 J 7 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
if [ -z "$only" ] || echo " $only " | grep -q " J "; then
  [ -f decomp/res/sk_J08.jww ] || $S J08 J 8 '600,500;600,300;' 'wait:900;400,400;wait:700;600,350;wait:700;'
fi
echo done
