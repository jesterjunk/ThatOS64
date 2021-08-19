// A 64-Bit Operating System written from scratch - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#ifndef STRUCTS_H
#define STRUCTS_H

// From the UEFI PDF Page 170
typedef struct EFI_MEMORY_DESCRIPTOR
{
	uint32_t  Type;
	uint64_t* PhysicalAddress;
	uint64_t* VirtualAddress;
	uint64_t  NumberOfPages;
	uint64_t  Attributes;
} EFI_MEMORY_DESCRIPTOR;

typedef struct BLOCKINFO
{
    uint64_t               BaseAddress;
    uint64_t               BufferSize;
    uint32_t               ScreenWidth;
    uint32_t               ScreenHeight;
    uint32_t               PixelsPerScanLine;
    uint64_t               LoaderFileSize;
    EFI_MEMORY_DESCRIPTOR* MMap;
    uint64_t               MMapSize;
    uint64_t               MMapDescriptorSize;
    uint64_t*              rsdp;
} __attribute__((__packed__)) BLOCKINFO;

typedef struct TEXTPOSITION
{
    uint32_t     x;
    uint32_t     y;
} TEXTPOSITION;

#endif // STRUCTS_H


