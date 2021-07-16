// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

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

void main(BLOCKINFO* bi)
{
	*(unsigned int*)(20 + (20 * bi->PixelsPerScanLine) + (unsigned int*)(bi->BaseAddress)) = 0xffffa500;
	while(1){__asm__ ("hlt");}
}

// __asm__ __volatile__