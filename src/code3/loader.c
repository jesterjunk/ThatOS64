// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#define ORANGE 0xffffa500
#define CYAN   0xff00ffff

unsigned int asciifont[32768] = {

1,0,0,0,0,0,0,0, // 000  --  NUL 
1,0,0,1,0,0,0,0,
1,1,0,1,0,0,0,0,
1,0,1,1,0,0,0,0,
1,0,0,1,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,1,0,1,0,0,
0,0,0,1,0,1,0,0,
0,0,0,1,0,1,0,0,
0,0,0,1,1,1,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,1,0,0,
0,0,0,0,0,1,0,0,
0,0,0,0,0,1,0,0,
0,0,0,0,0,1,1,1,
0,0,0,0,0,0,0,1
};

typedef struct GRAPHICS_COLOR_PIXEL
{
    unsigned char   Blue;
    unsigned char   Green;
    unsigned char   Red;
    unsigned char   Alpha;
} GRAPHICS_COLOR_PIXEL;

typedef struct BLOCKINFO
{
    int                  MagicNumber;
    unsigned long long*  BaseAddress;
    unsigned long long   BufferSize;
    unsigned int         ScreenWidth;
    unsigned int         ScreenHeight;
    unsigned int         PixelsPerScanLine;
} BLOCKINFO;

GRAPHICS_COLOR_PIXEL* SetGraphicsColor(unsigned int color);
void CreateBufferFilledBox(unsigned int xPos, unsigned int yPos, unsigned int w, unsigned int h, GRAPHICS_COLOR_PIXEL* gc, BLOCKINFO* bli);
void GetCharacter(unsigned int xPos, unsigned int yPos, BLOCKINFO* block);

void main(int argc, BLOCKINFO* bi)
{
	BLOCKINFO* biStruct = bi;
	
	if(biStruct->MagicNumber == 31337)
	{
		GRAPHICS_COLOR_PIXEL* GraphicsColor = SetGraphicsColor(ORANGE);
		CreateBufferFilledBox(0, 0, 150, 150, GraphicsColor, biStruct);
	}
	GetCharacter(0, 0, biStruct);
	
	while(1){}
}

GRAPHICS_COLOR_PIXEL* SetGraphicsColor(unsigned int color)
{
    GRAPHICS_COLOR_PIXEL* GColor = ((void*)0);
    GColor->Alpha    = color >> 24;
    GColor->Red      = color >> 16;
    GColor->Green    = color >> 8;
    GColor->Blue     = color;
    return GColor;
}

void CreateBufferFilledBox(unsigned int xPos, unsigned int yPos, unsigned int w, unsigned int h, GRAPHICS_COLOR_PIXEL* gc, BLOCKINFO* bli)
{
    unsigned int x;
    unsigned int y      = yPos;
    unsigned int width  = xPos + w;
    unsigned int height = yPos + h;

    for(y = yPos; y < height; y++)
    {
        for(x = xPos; x < width; x++)
        {
            *(x + (y * bli->PixelsPerScanLine) + (unsigned int*)(bli->BaseAddress)) = *(unsigned int*)gc;
        }
    }
}

void GetCharacter(unsigned int xPos, unsigned int yPos, BLOCKINFO* block)
{
    unsigned int initPos  = xPos;
    unsigned int mcX      = initPos;
    unsigned int mcY      = yPos;
    unsigned int xCounter = 0;
    unsigned int yCounter = 0;
    unsigned int fontsz   = 8;

	for(unsigned int t = 0; t < 128; t++)
	{
		if(xCounter > 7)
		{
			xCounter = 0;
			mcY += fontsz;
			mcX = initPos;
			yCounter++;
			if(yCounter > 15)
			{
				yCounter = 0;
				mcY += fontsz;
			}
		}

		switch(asciifont[t])
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				CreateBufferFilledBox(mcX, mcY, fontsz, fontsz, SetGraphicsColor(CYAN), block);
				break;
			}
			default:
			{
				break;
			}
		}
		mcX += fontsz;
		xCounter++;
	}
}

