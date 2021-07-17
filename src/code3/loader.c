// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#define ORANGE 0xffffa500
#define CYAN   0xff00ffff

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

void SetCharacter(unsigned int a, unsigned int b, BLOCKINFO* bli, unsigned int c, unsigned int FontSize);
void MakeRectangle(unsigned int a, unsigned int b, unsigned int w, unsigned int h, BLOCKINFO* bli, unsigned int c);

void main(BLOCKINFO* bi)
{

	SetCharacter(0, 0, bi, ORANGE, 5);
	
	while(1){__asm__ ("hlt");}
}

void SetCharacter(unsigned int a, unsigned int b, BLOCKINFO* bli, unsigned int c, unsigned int FontSize)
{
	unsigned int x = a;
	unsigned int temp = x;
	unsigned int y = b;
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
				MakeRectangle(x, y, FontSize, FontSize, bli, c);
				break;
			}
		}
		x += FontSize;
		if(x > (FontSize * 8))
		{
			x = temp;
			y += FontSize;
		}
	}
}

void MakeRectangle(unsigned int a, unsigned int b, unsigned int w, unsigned int h, BLOCKINFO* bli, unsigned int c)
{
	unsigned int width = a + w;
	unsigned int height = b + w;
	
	for(unsigned int y = b; y < height; y++)
    {
        for(unsigned int x = a; x < width; x++)
        {
            *(unsigned int*)(x + (y * bli->PixelsPerScanLine) + (unsigned int*)(bli->BaseAddress)) = c;
        }
    }
}
// __asm__ __volatile__