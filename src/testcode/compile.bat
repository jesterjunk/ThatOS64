gcc -Wall -m64 -ffreestanding -Werror -O0 -nostdinc -nostdlib  -c main.c -o main.o
gcc -o test.exe main.o  -m64 -s  

@echo off
del /Q *.o
@echo on

test.exe

pause
