// A 64-Bit Operating System written from scratch - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#ifndef MMAP_H
#define MMAP_H

void init8Bit(void);

uint8_t* bitmap8 __attribute__ ((section (".text"))) = 0;

#define SET_8BIT(sBit)   (bitmap8[(sBit) / 8] |= (1 << ((sBit) % 8)))
#define CLEAR_8BIT(cBit) (bitmap8[(cBit) / 8] &= (1 << ((cBit) % 8)))
#define GET_8BIT(gBit)  ((bitmap8[(gBit) / 8] >> ((gBit) % 8)) & 1)
#define FLIP_8BIT(fBit)  (bitmap8[(fBit) / 8] ^= (1 << ((fBit) % 8)))

void PrintMemory(uint32_t m);

#endif  // MMAP_H