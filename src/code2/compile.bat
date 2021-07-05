gcc -Wall -Werror -m64 -masm=intel -mabi=ms -ffreestanding -Wl,--oformat=binary -e main -c loader.c -o loader.bin

pause
