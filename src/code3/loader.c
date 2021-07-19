// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#define BITS8   7
#define BITS16 15
#define BITS32 31

#define HSPACE 1
#define VSPACE 1
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
	Print(bi, 20, 20, 2, WHITE, "WE HAVE TXT");
	
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
	int fs = (((FontSize * FontSize) + (FontSize * FontSize) + 6) + HSPACE);  // This is an experiment
	for(int t = 0; t < 64; t++)
	{
		PutCharacter(bli, t, x, y, FontSize, c);
		x+=fs;
	}
}

void PutCharacter(BLOCKINFO* bli, unsigned char chr, const int a, const int b, const unsigned int FontSize, unsigned int c)
{
	// I'm not sure why, but splitting this up into groups of arrays works.
	// My guess is, this is a stack issue, and splitting it up solves the stack issue.
unsigned int asciifont[64] = {
9490608,2415924244,337379332,67372800, // 000  --  NUL
0,0,0,0,                               // 032  --  SPACE
56,1824966358,3603351148,939524096,    // 048  --  0
24,947394584,404232216,2113929216,     // 049  --  1

60,1724255256,811647174,4261412864,    // 050  --  2
124,3322283580,101058246,2080374784,   // 051  --  3
12,473722060,4262202380,503316480,     // 052  --  4
254,3233857788,101058246,2080374784,   // 053  --  5

56,1623245052,3334915782,2080374784,   // 054  --  6
254,3322283532,405811248,805306368,    // 055  --  7
124,3334915708,3334915782,2080374784,  // 056  --  8
124,3334915710,101058060,2013265920,   // 057  --  9

16,946652870,4274439878,3321888768,    // 065  --  A
252,1717986940,1717986918,4227858432,  // 066  --  B
60,1724039360,3233858150,1006632960,   // 067  --  C
248,1818650214,1717986924,4160749568,  // 068  --  D
};

unsigned int asciifont2[64] = {
254,1717725304,1751147110,4261412864,  // 069  --  E
254,1717725304,1751146592,4026531840,  // 070  --  F
60,1724039360,3737568870,973078528,    // 071  --  G
198,3334915838,3334915782,3321888768,  // 072  --  H

60,404232216,404232216,1006632960,     // 073  --  I
30,202116108,214748364,2013265920,     // 074  --  J
230,1717988472,2020370022,3858759680,  // 075  --  K
240,1616928864,1616929382,4261412864,  // 076  --  L

198,4009688790,3334915782,3321888768,  // 077  --  M
198,3874946782,3469133510,3321888768,  // 078  --  N
124,3334915782,3334915782,2080374784,  // 079  --  O
252,1717986940,1616928864,4026531840,  // 080  --  P

124,3334915782,3334919902,2081164800,  // 081  --  Q
252,1717986940,1818650214,3858759680,  // 082  --  R
124,3334889528,201770694,2080374784,   // 083  --  S
126,2119833624,404232216,1006632960,   // 084  --  T
};

unsigned int asciifont3[64] = {
198,3334915782,3334915782,2080374784,  // 085  --  U
198,3334915782,3334892600,268435456,   // 086  --  V
198,3334915798,3604414190,1811939328,  // 087  --  W
198,3328994360,946629830,3321888768,   // 088  --  X

102,1717986918,1008211992,1006632960,  // 089  --  Y
254,3330673688,811647686,4261412864,   // 090  --  Z
0,30732,2093796556,1979711488,         // 097  --  a
224,1616935020,1717986918,2080374784,  // 098  --  b

0,15462,1616928870,1006632960,         // 099  --  c
28,202128492,3435973836,1979711488,    // 100  --  d
0,31942,4274045126,2080374784,         // 101  --  e
28,909258872,808464432,2013265920,     // 102  --  f

0,30412,3435973756,214726656,          // 103  --  g
224,1616931958,1717986918,3858759680,  // 104  --  h
0,404226104,404232216,1006632960,      // 105  --  i
6,100666886,101058150,1715208192,      // 106  --  j
};

unsigned int asciifont4[64] = {
224,1616930412,2021157990,3858759680,  // 107  --  k
48,808464432,808464432,939524096,      // 108  --  l
0,60670,3604403926,3321888768,         // 109  --  m
0,56422,1717986918,1711276032,         // 110  --  n

0,30924,3435973836,2013265920,         // 111  --  o
0,15462,1719427168,1610612736,         // 112  --  p
0,30412,3435973756,202120704,          // 113  --  q
0,56438,1717592160,4026531840,         // 114  --  r

0,31942,1614286022,2080374784,         // 115  --  s
0,271593724,808464438,469762048,       // 116  --  t
0,52428,3435973836,1979711488,         // 117  --  u
0,27756,1819044920,268435456,          // 118  --  v

0,50902,3604403966,1811939328,         // 119  --  w
0,50796,943208556,3321888768,          // 120  --  x
0,50886,3334915710,101513216,          // 121  --  y
0,65228,405823686,4261412864,          // 122  --  z
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
