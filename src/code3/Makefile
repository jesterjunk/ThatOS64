# Makefile
CC        :=gcc
CFLAGS    :=-Wall -Werror -m64 -mabi=ms -ffreestanding
UNAME_S   :=$(shell uname -s)

ifeq ($(UNAME_S),Darwin)
CC        :=x86_64-w64-mingw32-gcc
endif
ifeq ($(UNAME_S),Linux)
CC        :=x86_64-w64-mingw32-gcc
endif

all: loader.bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

loader.bin: loader.c
	$(CC) $(CFLAGS) -ffreestanding -Wl,--oformat=binary -e main -c $< -o $@

clean:
	@echo "Cleaning files...."
	rm -f *.o *.bin
	@echo "Done."

.PHONY: clean
