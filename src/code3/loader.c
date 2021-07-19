// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#define BITS8   7
#define BITS16 15
#define BITS32 31
                  // A R G B             
#define ORANGE     0xffffa500
#define DARKORANGE 0xffaf5500
#define CYAN       0xff00ffff
#define RED        0xffff0000
#define GREEN      0xff00ff00
#define BLUE       0xff0000ff
#define GRAY       0xff888888
#define WHITE      0xffffffff
#define BLACK      0xff000000

// From the UEFI PDF Page 170
typedef struct EFI_MEMORY_DESCRIPTOR
{
	unsigned int        type;
	void*               PhysicalAddress;
	void*               VirtualAddress;
	unsigned long long  NumberOfPages;
	unsigned long long  Attributes;
} EFI_MEMORY_DESCRIPTOR;

typedef struct BLOCKINFO
{
    unsigned long long*     BaseAddress;
    unsigned long long      BufferSize;
    unsigned int            ScreenWidth;
    unsigned int            ScreenHeight;
    unsigned int            PixelsPerScanLine;
	unsigned long long*     LoaderFileSize;
	EFI_MEMORY_DESCRIPTOR*  MMap;
	unsigned long long      MMapSize;
	unsigned long long      MMapDescriptorSize;
} BLOCKINFO;

//void* memcpy(void* dst, const void* src, unsigned long long size);

void Print(BLOCKINFO* bli, const int x, const int y, const unsigned int FontSize, unsigned int c, char* str);
void PutCharacter(BLOCKINFO* bli, unsigned char chr, const int a, const int b, const unsigned int FontSize, unsigned int c);
void MakeRectangle(BLOCKINFO* bli, int a, int b, int w, int h, unsigned int c);

void tmain(BLOCKINFO* bi)
{
    MakeRectangle(bi, 1, 1, 80, 90, DARKORANGE);
	Print(bi, 20, 20, 1, WHITE, "WE HAVE TXT");
	
	while(1){__asm__ ("hlt");}
}

/*
void* memcpy(void* dst, const void* src, unsigned long long size)
{
    for ( unsigned long long i = 0; i < size; i++ )
        ((unsigned char*) dst)[i] = ((const unsigned char*) src)[i];
    return dst;
}
*/

void Print(BLOCKINFO* bli, const int a, const int b, const unsigned int FontSize, unsigned int c, char* str)
{
	// At this time, STR does nothing yet.
	int x = a;
	int y = b;
	int fs = ((FontSize * FontSize) + (FontSize * FontSize) + 6);  // This is an experiment
	PutCharacter(bli, 33, x, y, FontSize, c);  // W
	x+=fs;
	PutCharacter(bli, 15, x, y, FontSize, c);  // E
	x+=fs;
	PutCharacter(bli, 63, x, y, FontSize, c);  // SPACE
	x+=fs;
	PutCharacter(bli, 18, x, y, FontSize, c);  // H
	x+=fs;
	PutCharacter(bli, 11, x, y, FontSize, c);  // A
	x+=fs;
	PutCharacter(bli, 32, x, y, FontSize, c);  // V
	x+=fs;
	PutCharacter(bli, 15, x, y, FontSize, c);  // E
	x+=fs;
	PutCharacter(bli, 63, x, y, FontSize, c);  // SPACE
	x+=fs;
	PutCharacter(bli, 30, x, y, FontSize, c);  // T
	x+=fs;
	PutCharacter(bli, 15, x, y, FontSize, c);  // E
	x+=fs;
	PutCharacter(bli, 34, x, y, FontSize, c);  // X
	x+=fs;
	PutCharacter(bli, 30, x, y, FontSize, c);  // T
}

void PutCharacter(BLOCKINFO* bli, unsigned char chr, const int a, const int b, const unsigned int FontSize, unsigned int c)
{
	// I'm not sure why, but splitting this up into groups of arrays works.
	// My guess is, this is a stack issue, and splitting it up solves the stack issue.
unsigned int asciifont[64] = {
9490608,2415924244,337379332,67372800, // NUL
56,1824966358,3603351148,939524096,    // 0
24,947394584,404232216,2113929216,     // 1
14444,3322285080,811647174,4261412864, // 2

9490608,2415924244,337379332,67372800, // 3
9490608,2415924244,337379332,67372800, // 4
9490608,2415924244,337379332,67372800, // 5
9490608,2415924244,337379332,67372800, // 6

9490608,2415924244,337379332,67372800, // 7
9490608,2415924244,337379332,67372800, // 8
9490608,2415924244,337379332,67372800, // 9
16,946652870,4274439878,3321888768,    // A

9490608,2415924244,337379332,67372800, // B
9490608,2415924244,337379332,67372800, // C
9490608,2415924244,337379332,67372800, // D
254,1717725304,1751147110,4261412864,  // E
};

unsigned int asciifont2[64] = {
9490608,2415924244,337379332,67372800, // F
60,1724039360,3737568870,973078528,    // G
198,3334915838,3334915782,3321888768,  // H
9490608,2415924244,337379332,67372800, // I

9490608,2415924244,337379332,67372800, // J
9490608,2415924244,337379332,67372800, // K
9490608,2415924244,337379332,67372800, // L
9490608,2415924244,337379332,67372800, // M

9490608,2415924244,337379332,67372800, // N
9490608,2415924244,337379332,67372800, // O
9490608,2415924244,337379332,67372800, // P
9490608,2415924244,337379332,67372800, // Q

9490608,2415924244,337379332,67372800, // R
9490608,2415924244,337379332,67372800, // S
126,2119833624,404232216,1006632960,   // T
9490608,2415924244,337379332,67372800, // U
};

unsigned int asciifont3[64] = {
198,3334915782,3334892600,268435456,   // V
198,3334915798,3604414190,1811939328,  // W
198,3328994360,946629830,3321888768,   // X
9490608,2415924244,337379332,67372800, // Y

9490608,2415924244,337379332,67372800, // Z
9490608,2415924244,337379332,67372800, // a
9490608,2415924244,337379332,67372800, // b
9490608,2415924244,337379332,67372800, // c

9490608,2415924244,337379332,67372800, // d
9490608,2415924244,337379332,67372800, // e
9490608,2415924244,337379332,67372800, // f
9490608,2415924244,337379332,67372800, // g

9490608,2415924244,337379332,67372800, // h
9490608,2415924244,337379332,67372800, // i
9490608,2415924244,337379332,67372800, // j
9490608,2415924244,337379332,67372800, // k
};

unsigned int asciifont4[64] = {
9490608,2415924244,337379332,67372800, // l
9490608,2415924244,337379332,67372800, // m
9490608,2415924244,337379332,67372800, // n
9490608,2415924244,337379332,67372800, // o

9490608,2415924244,337379332,67372800, // p
9490608,2415924244,337379332,67372800, // q
9490608,2415924244,337379332,67372800, // r
9490608,2415924244,337379332,67372800, // s

9490608,2415924244,337379332,67372800, // t
9490608,2415924244,337379332,67372800, // u
9490608,2415924244,337379332,67372800, // v
9490608,2415924244,337379332,67372800, // w

9490608,2415924244,337379332,67372800, // x
9490608,2415924244,337379332,67372800, // y
9490608,2415924244,337379332,67372800, // z
0,0,0,0,                               // SPACE
};
    char togglearray = 0;
    if(chr > 15 && chr < 32){togglearray = 1; chr -= 16;}
	else if(chr > 31 && chr < 48){togglearray = 2; chr -= 32;}
	else if(chr > 47 && chr < 64){togglearray = 3; chr -= 48;}
    unsigned int character = (chr * 4);
	int x = a;
	int y = b;
	int temp = a;
	int xPos = 0;
	for(unsigned int fc = character; fc < (character + 4); fc++)
	{
		for(long t = BITS32; t >= 0; t--)
		{
			if(togglearray == 0)
			{
				if(asciifont[fc] & (1 << t))
				{
					MakeRectangle(bli, x, y, FontSize, FontSize, c);
				}
			} else if(togglearray == 1){
				if(asciifont2[fc] & (1 << t))
				{
					MakeRectangle(bli, x, y, FontSize, FontSize, c);
				}
			} else if(togglearray == 2){
				if(asciifont3[fc] & (1 << t))
				{
					MakeRectangle(bli, x, y, FontSize, FontSize, c);
				}
			} else if(togglearray == 3){
				if(asciifont4[fc] & (1 << t))
				{
					MakeRectangle(bli, x, y, FontSize, FontSize, c);
				}
			}
			x += FontSize;
			xPos++;
			if(xPos > 7)
			{
				x = temp;
				y += FontSize;
				xPos = 0;
			}
		}
	}
}

void MakeRectangle(BLOCKINFO* bli, int a, int b, int w, int h, unsigned int c)
{
	int width = (w + a);
	int height = (h + b);
	
	for(int y = b; y < height; y++)
    {
        for(int x = a; x < width; x++)
        {
            *(unsigned int*)(x + (y * bli->PixelsPerScanLine) + (unsigned int*)(bli->BaseAddress)) = c;
        }
    }
}

// -Wno-unused-variable -ansi -masm=intel -std=c99 -O0 -nostdinc -nostdlib -ffreestanding

// __asm__ __volatile__


/*   // PSEUDO EXAMPLE
 // 000  --  NULL 
00000000100100001101000010110000 ---> 9490608
10010000000000000001010000010100 ---> 2415924244
00010100000111000000000000000100 ---> 337379332
00000100000001000000011100000000 ---> 67372800

	for(long t = 31; t >= 0; t--)
    {
      	if(155 & (1<<t))
        {
            Bit number is SET
        } else
        {
            Bit number is not SET
        }
     }
*/
