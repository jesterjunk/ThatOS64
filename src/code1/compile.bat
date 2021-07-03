gcc -Wall -Werror -m64 -mabi=ms -ffreestanding -IThatCLib -Wl,--oformat=binary -e main -c loader.c -o loader.bin

pause
