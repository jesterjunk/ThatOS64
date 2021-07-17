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

unsigned int asciifont[128] = {

1,1,1,1,1,1,1,1, // 000  --  NUL 
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,0,0,1,1,0,1,1,
1,1,1,1,1,1,1,1
};

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
void PutCharacter(BLOCKINFO* bli, unsigned int a, unsigned int b, unsigned int FontSize);
void MakeSizedPixel(BLOCKINFO* bli, const unsigned int a, const unsigned int b, const unsigned int f);
void MakeRectangle(BLOCKINFO* bli, unsigned int a, unsigned int b, unsigned int w, unsigned int h, unsigned int c);

void main(BLOCKINFO* bi)
{
    MakeRectangle(bi, 1, 1, 100, 100, DARKORANGE);
	// MakeSizedPixel(bi, 1, 1, 10);
	//Print(bi, "NA");
	
	while(1){__asm__ ("hlt");}
}

void Print(BLOCKINFO* bli, char* str)
{
	PutCharacter(bli, 0, 0, 5);
}

void PutCharacter(BLOCKINFO* bli, unsigned int a, unsigned int b, unsigned int FontSize)
{
	unsigned int x = a;
	unsigned int y = b;
	unsigned int temp = x;
	for(unsigned int fc = 0; fc < 128; fc++)
	{
		unsigned int asci = asciifont[fc];
		switch(asci)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				MakeSizedPixel(bli, x, y, 5);
				break;
			}
		}
		x += FontSize;
		if(x > (FontSize * 7))
		{
			x = temp;
			y += FontSize;
		}
	}
}

void MakeSizedPixel(BLOCKINFO* bli, const unsigned int a, const unsigned int b, const unsigned int f)
{
	unsigned int fs1 = f + a;
	unsigned int fs2 = f + b;

	for(unsigned int y = b; y < fs2; y++)
    {
        for(unsigned int x = a; x < fs1; x++)
        {
            *(unsigned int*)(x + (y * bli->PixelsPerScanLine) + (unsigned int*)(bli->BaseAddress)) = CYAN;
        }
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