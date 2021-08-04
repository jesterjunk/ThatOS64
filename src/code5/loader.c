// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#include "stdint.h"
#include "typedefs.h"
#include "structs.h"
#include "globals.h"
#include "string.h"
#include "stdlib.h"
#include "cr_registers.h"


void main(BLOCKINFO* bi)
{
	block = bi;
	
	uint64_t testingme = READ_cr2();
	
	ClearScreen(DARKGRAY);
	
	textPos->x = 20;
	textPos->y = 10;
	
	uint8_t st2[] = "CR2 has been read successfully !!!";
	Print(st2, textPos->x, textPos->y, 1, ORANGE);

    textPos->y+=16;
	
	uint8_t st3[] = "End Program";
	Print(st3, textPos->x, textPos->y, 1, CYAN);
	
	while(1){__asm__ ("hlt");}
}

#include "stdlib.c"
#include "string.c"
#include "cr_registers.c"

