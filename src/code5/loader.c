// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#include "stdint.h"
#include "typedefs.h"
#include "structs.h"
#include "globals.h"
#include "string.h"
#include "stdlib.h"
#include "cr_registers.h"
#include "mmap.h"

void main(BLOCKINFO* bi)
{
	block = bi;
	block->BaseAddress = (bi->BaseAddress - 128);
	
	ClearScreen(DARKGRAY);
	
	textPos->x  = 20;
	textPos->y  = 10;
	
    uint64_t MMapEntries = block->MMapSize / block->MMapDescriptorSize;
	for(uint32_t i = 0; i < MMapEntries; i++)
	{
		EFI_MEMORY_DESCRIPTOR* desc = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)block->MMap + (i * block->MMapDescriptorSize));
		
		PrintMemory(desc->Type);

		textPos->y += 16;
		textPos->x  = 20;
	}
	
	uint8_t st3[] = "End Program";
	Print(st3, textPos->x, textPos->y, 1, GREEN);
	
	while(1){__asm__ ("hlt");}
}

#include "stdlib.c"
#include "string.c"
#include "cr_registers.c"
#include "mmap.c"
