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
	uint64_t TotalRam = 0;
	for(uint32_t i = 0; i < MMapEntries; i++)
	{
		EFI_MEMORY_DESCRIPTOR* desc = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)block->MMap + (i * block->MMapDescriptorSize));
		
		TotalRam += (desc->NumberOfPages * 4096);

		textPos->y += 16;
		textPos->x  = 20;
	}
	
	uint8_t st2[] = "TOTAL RAM :";
	Print(st2, textPos->x, textPos->y, 1, YELLOW);
	
	textPos->x  = 124;
		
	uint8_t pTr[1024] = {'\0'};
	itoa(*(uint64_t*)&TotalRam, (uint64_t*)pTr, DECIMAL);
	uint8_t* test = (uint8_t*)pTr;
	int o = 0;
	while(1)
	{
		uint8_t j = *test;
		if(j == '\0')
		{
			o++;
			if(o > 7){break;}
		} else 
		{
			o = 0;
		}
		Print(&j, textPos->x, textPos->y, 1, WHITE);
		test++;
		textPos->x++;
	};

	uint8_t st3[] = " Bytes";
	Print(st3, textPos->x, textPos->y, 1, GRAY);
	
	textPos->y += 16;
	textPos->x  = 20;
		
	uint8_t st4[] = "End Program";
	Print(st4, textPos->x, textPos->y, 1, GREEN);
	
	while(1){__asm__ ("hlt");}
}

#include "stdlib.c"
#include "string.c"
#include "cr_registers.c"
#include "mmap.c"
