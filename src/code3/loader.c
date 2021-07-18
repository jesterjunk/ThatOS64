// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

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

void Print(BLOCKINFO* bli, char* str);
void PutCharacter(BLOCKINFO* bli, int chr, const unsigned int a, const unsigned int b, const unsigned int FontSize, unsigned int c);
void MakeSizedPixel(BLOCKINFO* bli, const unsigned int a, const unsigned int b, const unsigned int f);
void MakeRectangle(BLOCKINFO* bli, unsigned int a, unsigned int b, unsigned int w, unsigned int h, unsigned int c);

void main(BLOCKINFO* bi)
{
    MakeRectangle(bi, 1, 1, 80, 90, DARKORANGE);
	Print(bi, "NA");
	
	while(1){__asm__ ("hlt");}
}

void Print(BLOCKINFO* bli, char* str)
{
	PutCharacter(bli, 0, 40, 20, 6, WHITE);
	PutCharacter(bli, 1, 10, 200, 4, GREEN);
}

void PutCharacter(BLOCKINFO* bli, int chr, const unsigned int a, const unsigned int b, const unsigned int FontSize, unsigned int c)
{
unsigned char asciifont[256] = {
0,144,208,176,144,0,20,20,20,28,0,4,4,4,7,0,
0,0,0,126,129,165,129,129,189,153,129,129,126,0,0,0,
255,155,155,155,155,155,155,155,155,155,155,155,155,155,155,255,
255,155,155,155,155,155,155,155,155,155,155,155,155,155,155,222,

10,144,208,176,144,155,155,155,155,155,155,155,155,155,155,255,
255,155,155,155,155,144,208,176,144,155,155,155,155,155,155,8,
255,155,155,155,155,155,155,155,155,155,155,155,155,155,155,79,
255,155,155,155,155,155,155,155,155,155,155,155,155,155,155,54,

1,144,208,176,144,155,155,155,155,155,155,155,155,155,155,255,
255,155,155,155,155,144,208,176,144,155,155,155,155,155,155,5,
255,155,155,155,155,155,155,155,155,155,155,155,155,155,155,21,
255,155,155,155,155,155,155,155,155,155,155,155,155,155,155,222,

10,144,208,176,144,155,155,155,155,155,155,155,155,155,155,255,
255,155,155,155,155,144,208,176,144,155,155,155,155,155,155,8,
255,155,155,155,155,155,155,155,155,155,155,155,155,155,155,79,
255,155,155,155,155,155,155,155,155,155,155,155,155,155,155,54
};
    int character = (chr * 16);
	unsigned int x = a;
	unsigned int y = b;
	unsigned int temp = a;
	for(int fc = character; fc < (character + 16); fc++)
	{
		for(int t = 7; t >= 0; t--)
		{
			if(asciifont[fc] & (1 << t))
			{
				MakeRectangle(bli, x, y, FontSize, FontSize, c);
			}
			x += FontSize;
		}
		x = temp;
		y += FontSize;
	}
}

void MakeRectangle(BLOCKINFO* bli, unsigned int a, unsigned int b, unsigned int w, unsigned int h, unsigned int c)
{
	unsigned int width = (w + a);
	unsigned int height = (h + b);
	
	for(unsigned int y = b; y < height; y++)
    {
        for(unsigned int x = a; x < width; x++)
        {
            *(unsigned int*)(x + (y * bli->PixelsPerScanLine) + (unsigned int*)(bli->BaseAddress)) = c;
        }
    }
}

// __asm__ __volatile__


/*   // PSEUDO EXAMPLE

	255 = 11111111  ( 255 ---> ff ---> 11111111 )
	155 = 10011011  ( 155 ---> 9b ---> 10011011 )
	155 = 10011011
	155 = 10011011
	155 = 10011011
	155 = 10011011
	155 = 10011011
	155 = 10011011
	155 = 10011011
	155 = 10011011
	155 = 10011011
	155 = 10011011
	155 = 10011011
	155 = 10011011
	155 = 10011011
	255 = 11111111

    
	for(int t = 7; t >= 0; t--)
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
