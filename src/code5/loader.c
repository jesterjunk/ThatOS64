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

	textPos->x = 20;
	textPos->y = 10;
	
	uint64_t testingme = READ_cr2();
	uint8_t st2[] = "CR2 has been read successfully !!!";
	Print(st2, textPos->x, textPos->y, 1, ORANGE);

	uint8_t testMap = 9; //  00001001 == 9
	                     //  Result should be Bit 0 and 3
	
	bitmap8 = &testMap;
	
	uint8_t g0 = GET_8BIT(0);
	uint8_t g1 = GET_8BIT(1);
	uint8_t g2 = GET_8BIT(2);
	uint8_t g3 = GET_8BIT(3);
	uint8_t g4 = GET_8BIT(4);
	uint8_t g5 = GET_8BIT(5);
	uint8_t g6 = GET_8BIT(6);
	uint8_t g7 = GET_8BIT(7);
	if(g0 == 1)
	{
		textPos->y+=16;
	    textPos->x = 20;
		uint8_t st5[] = "Bit 0 = 1";
		Print(st5, textPos->x, textPos->y, 1, ORANGE);
	}
	if(g1 == 1)
	{
		textPos->y+=16;
	    textPos->x = 20;
		uint8_t st5[] = "Bit 1 = 1";
		Print(st5, textPos->x, textPos->y, 1, ORANGE);
	}
    if(g2 == 1)
	{
		textPos->y+=16;
	    textPos->x = 20;
		uint8_t st5[] = "Bit 2 = 1";
		Print(st5, textPos->x, textPos->y, 1, ORANGE);
	}
	if(g3 == 1)
	{
		textPos->y+=16;
	    textPos->x = 20;
		uint8_t st5[] = "Bit 3 = 1";
		Print(st5, textPos->x, textPos->y, 1, ORANGE);
	}
	if(g4 == 1)
	{
		textPos->y+=16;
	    textPos->x = 20;
		uint8_t st5[] = "Bit 4 = 1";
		Print(st5, textPos->x, textPos->y, 1, ORANGE);
	}
	if(g5 == 1)
	{
		textPos->y+=16;
	    textPos->x = 20;
		uint8_t st5[] = "Bit 5 = 1";
		Print(st5, textPos->x, textPos->y, 1, ORANGE);
	}
	if(g6 == 1)
	{
		textPos->y+=16;
	    textPos->x = 20;
		uint8_t st5[] = "Bit 6 = 1";
		Print(st5, textPos->x, textPos->y, 1, ORANGE);
	}
	if(g7 == 1)
	{
		textPos->y+=16;
	    textPos->x = 20;
		uint8_t st5[] = "Bit 7 = 1";
		Print(st5, textPos->x, textPos->y, 1, ORANGE);
	}
	
    textPos->y+=16;
	textPos->x = 20;
	
	uint8_t st3[] = "End Program";
	Print(st3, textPos->x, textPos->y, 1, CYAN);

	while(1){__asm__ ("hlt");}
}

#include "stdlib.c"
#include "string.c"
#include "cr_registers.c"
#include "mmap.c"
