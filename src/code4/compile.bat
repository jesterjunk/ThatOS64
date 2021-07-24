gcc -O0 -Wall -Werror -pedantic -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs -Winline -Wno-long-long -Wuninitialized -Wconversion -Wstrict-prototypes -Wunsafe-loop-optimizations -fno-builtin -fno-stack-protector -std=c99 -nostdinc -nostdlib -ffreestanding -m64 -Wl,--oformat=binary -e main -c loader.c -o loader.bin

pause
