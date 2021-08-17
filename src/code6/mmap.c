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