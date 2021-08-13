cd gdt
fasm gdt.asm
cd ..

gcc -Wall -Werror -Wno-unused-variable -std=c99 -O0 -nostdinc -nostdlib -ffreestanding -m64 -Wl,--oformat=binary -e main -c loader.c -o loader.bin

pause
