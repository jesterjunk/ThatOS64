<<<<<<< HEAD
gcc -ansi -masm=intel -std=c99 -O0 -pedantic-errors -Wall -Werror -Wno-unused-variable -m64 -nostdinc -nostdlib -ffreestanding -Wl,--oformat=binary -e main -c loader.c -o loader.bin
=======
gcc -ansi -masm=intel -std=c99 -O0 -pedantic-errors -Wall -Werror -m64 -nostdinc -nostdlib -ffreestanding -Wl,--oformat=binary -e main -c loader.c -o loader.bin
>>>>>>> 67547eac2c9558e537db0551d66ccee3f1d6a29b

pause
