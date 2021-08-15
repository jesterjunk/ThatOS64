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

void PrintMemory(uint32_t m)
{
    if(m == 0)
	{
			uint8_t st[] = "0. EfiReservedMemoryType";
			Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 1)
	{
			uint8_t st[] = "1. EfiLoaderCode";
			Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 2)
	{
            uint8_t st[] = "2. EfiLoaderData";
			Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 3)
	{
		   uint8_t st[] = "3. EfiBootServicesCode";
		   Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 4)
	{
	       uint8_t st[] = "4. EfiBootServicesData";
	       Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 5)
	{
	       uint8_t st[] = "5. EfiRuntimeServicesCode";
	       Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 6)
	{
	       uint8_t st[] = "6. EfiRuntimeServicesData";
	       Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 7)
	{
		   uint8_t st[] = "7. EfiConventionalMemory";
		   Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 8)
	{
	       uint8_t st[] = "8. EfiUnusableMemory";
	       Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 9)
	{
	       uint8_t st[] = "9. EfiACPIReclaimMemory";
	       Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 10)
	{
		   uint8_t st[] = "10. EfiACPIMemoryNVS";
		   Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 11)
	{
		   uint8_t st[] = "11. EfiMemoryMappedIO";
		   Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 12)
	{
		   uint8_t st[] = "12. EfiMemoryMappedIOPortSpace";
		   Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 13)
	{
		   uint8_t st[] = "13. EfiPalCode";
		   Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 14)
	{
		   uint8_t st[] = "14. EfiPersistentMemory";
		   Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 15)
	{
		   uint8_t st[] = "15. EfiUnacceptedMemoryType";
		   Print(st, textPos->x, textPos->y, 1, CYAN);
	} else if(m == 16)
	{
		   uint8_t st[] = "16. EfiMaxMemoryType";
		   Print(st, textPos->x, textPos->y, 1, CYAN);
	} else
	{
		   uint8_t st[] = "UNKNOWN";
		   Print(st, textPos->x, textPos->y, 1, CYAN);
	}
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