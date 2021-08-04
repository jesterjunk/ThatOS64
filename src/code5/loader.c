// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#include "stdint.h"
#include "typedefs.h"
#include "structs.h"
#include "globals.h"
#include "string.h"
#include "stdlib.h"

void main(BLOCKINFO* bi)
{
	block = bi;
	
	ClearScreen(DARKGRAY);
	
	textPos->x = 20;
	textPos->y = 10;
	
	uint8_t st2[] = "We have text !!!";
	Print(st2, textPos->x, textPos->y, 1, ORANGE);

    textPos->y+=16;
	
	uint8_t st3[] = "End Program";
	Print(st3, textPos->x, textPos->y, 1, CYAN);
	
	while(1){__asm__ ("hlt");}
}

#include "stdlib.c"
#include "string.c"

