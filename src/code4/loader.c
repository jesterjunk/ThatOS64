// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#include "typedefs.h"
#include "blockinfo.h"
#include "string.h"
#include "stdlib.h"

void main(BLOCKINFO* bi)
{
	unsigned char st3[] = "Graphics Memory Address : ";
	Print(bi, st3, bi->ScreenWidth, 20, 10, 1, ORANGE);
	
	unsigned short int pTr2[13] = {'\0'};
	pTr2[0] = '0';
	pTr2[1] = 'x';
	unsigned long int pTr[11] = {'\0'};
	itoa(*(unsigned long int*)&bi->BaseAddress, pTr, 16);
	int s = 2;
	for(int k = 0; k < 11; k++)
	{
		pTr2[s++] = (unsigned short int)pTr[k];
	}
	unsigned char* test = (unsigned char*)pTr2;
	unsigned int x = 250;
	for(int u = 1; u < 21; u++)
	{
		unsigned char j = *test;
		Print(bi, &j, bi->ScreenWidth, x, 10, 1, BADCYAN);
		test++;
		x+=4;
	}
	
	unsigned char st2[] = "End Program";
	Print(bi, st2, bi->ScreenWidth, 20, 50, 1, CYAN);
	
	while(1){__asm__ ("hlt");}
}

#include "stdlib.c"
#include "string.c"

