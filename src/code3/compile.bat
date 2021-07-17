gcc -ansi -masm=intel -std=c99 -O0 -pedantic-errors -Wall -Werror -m64 -nostdinc -nostdlib -ffreestanding -Wl,--oformat=binary -e main -c loader.c -o loader.bin

pause
