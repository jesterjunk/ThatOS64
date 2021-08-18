void init8Bit(void)
{
	CLEAR_8BIT(0);
	CLEAR_8BIT(1);
	CLEAR_8BIT(2);
	CLEAR_8BIT(3);
	CLEAR_8BIT(4);
	CLEAR_8BIT(5);
	CLEAR_8BIT(6);
	CLEAR_8BIT(7);
}

uint64_t GetTotalRam()
{
    uint64_t MMapEntries = block->MMapSize / block->MMapDescriptorSize;
	uint64_t TotalRam = 0;
	for(uint32_t i = 0; i < MMapEntries; i++)
	{
		EFI_MEMORY_DESCRIPTOR* desc = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)block->MMap + (i * block->MMapDescriptorSize));
		
		TotalRam += (desc->NumberOfPages * 4096);
	}
	return TotalRam;
}


/*
	uint8_t testMap = 9; //  00001001 == 9
	                     //  Result should be Bit 0 and 3
	
	bitmap8 = &testMap;
	
	uint8_t g0 = GET_8BIT(0);

	if(g0 == 1)
	{
		textPos->y+=16;
	    textPos->x = 20;
		uint8_t st5[] = "Bit 0 = 1";
		Print(st5, textPos->x, textPos->y, 1, ORANGE);
	}
*/

/*
	uint8_t st2[] = "TOTAL RAM :";
	Print(st2, textPos->x, textPos->y, 1, YELLOW);
	
	textPos->x  = 124;
		
	uint8_t pTr[1024] = {'\0'};
	itoa(GetTotalRam(), (uint64_t*)pTr, DECIMAL);
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
*/