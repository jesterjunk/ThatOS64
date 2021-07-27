// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#include "typedefs.h"
#include "structs.h"
#include "cr_registers.h"
#include "globals.h"
#include "string.h"
#include "stdlib.h"

void main(BLOCKINFO* bi)
{
	block = bi;
	
	unsigned long long ourCR0 = READ_cr0();
	
	ClearScreen(DARKGRAY);
	
	textPos->x = 20;
	textPos->y = 10;
	
	unsigned char st3[] = "End Program";
	Print(st3, textPos->x, textPos->y, 1, CYAN);
	
	while(1){__asm__ ("hlt");}
}

#include "stdlib.c"
#include "string.c"
#include "cr_registers.c"
