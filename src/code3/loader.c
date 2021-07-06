// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#include "stdint.h"
#include "tosdfont.h"

             // ARGB             
#define ORANGE 0xffffa500
#define CYAN   0xff00ffff
#define RED    0xffff0000
#define GREEN  0xff00ff00
#define BLUE   0xff0000ff
#define GRAY   0xff888888
#define WHITE  0xffffffff
#define BLACK  0xff000000

#define CHARBITS  128
#define FONTSIZE8 8
#define ZERO      0x0

typedef struct GRAPHICS_COLOR_PIXEL
{
    uint8_t   Blue;
    uint8_t   Green;
    uint8_t   Red;
    uint8_t   Alpha;
} GRAPHICS_COLOR_PIXEL;

typedef struct BLOCKINFO
{
	int32_t    MagicNumber;
    uint64_t*  BaseAddress;
    uint64_t   BufferSize;
    uint32_t   ScreenWidth;
    uint32_t   ScreenHeight;
    uint32_t   PixelsPerScanLine;
} BLOCKINFO;

GRAPHICS_COLOR_PIXEL* SetGraphicsColor(uint32_t color);
void CreateBufferFilledBox(uint32_t xPos, uint32_t yPos, uint32_t w, uint32_t h, GRAPHICS_COLOR_PIXEL* gc, BLOCKINFO* bli);
void GetCharacter(uint32_t character, uint32_t xPos, uint32_t yPos, BLOCKINFO* block);

void main(int32_t argc, BLOCKINFO* bi)
{
	BLOCKINFO* biStruct = bi;
	
	if(biStruct->MagicNumber == 31337)
	{
		GRAPHICS_COLOR_PIXEL* GraphicsColor = SetGraphicsColor(ORANGE);
		CreateBufferFilledBox(0, 0, 150, 150, GraphicsColor, biStruct);
	}
	
	GetCharacter(0, 0, 0, biStruct);
	
	while(1){}
}

GRAPHICS_COLOR_PIXEL* SetGraphicsColor(uint32_t color)
{
    GRAPHICS_COLOR_PIXEL* GColor = ((void*)0);
    GColor->Alpha    = color >> 24;
    GColor->Red      = color >> 16;
    GColor->Green    = color >> 8;
    GColor->Blue     = color;
    return GColor;
}

void CreateBufferFilledBox(uint32_t xPos, uint32_t yPos, uint32_t w, uint32_t h, GRAPHICS_COLOR_PIXEL* gc, BLOCKINFO* bli)
{
    uint32_t x;
    uint32_t y      = yPos;
    uint32_t width  = xPos + w;
    uint32_t height = yPos + h;

    for(y = yPos; y < height; y++)
    {
        for(x = xPos; x < width; x++)
        {
            *(x + (y * bli->PixelsPerScanLine) + (uint32_t*)(bli->BaseAddress)) = *(uint32_t*)gc;
        }
    }
}

void GetCharacter(uint32_t character, uint32_t xPos, uint32_t yPos, BLOCKINFO* block)
{
    uint32_t initPos = xPos;
	uint32_t mcX = initPos;
	uint32_t mcY = yPos;
	uint32_t xCounter = ZERO;
	uint32_t yCounter = ZERO;
	uint32_t fontsz   = FONTSIZE8;

	for(uint32_t t = (character * CHARBITS); t < ((character * CHARBITS) + CHARBITS); t++)
	{
		if(xCounter > 7)
		{
			xCounter = ZERO;
			mcY += fontsz;
			mcX = initPos;
			yCounter++;
			if(yCounter > 15)
			{
				yCounter = ZERO;
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
				CreateBufferFilledBox(mcX, mcY, fontsz, fontsz, SetGraphicsColor(WHITE), block);
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

