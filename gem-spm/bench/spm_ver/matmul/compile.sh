COMPILER=arm-linux-gnueabi-gcc
SRC=$1.c
OUT=$1

$COMPILER -static -Wl,--section-start=.dspm=100000 $SRC -o $OUT
