// Operating System from Scratch Tutorials - ThatOSDev ( 2021 )
// https://github.com/ThatOSDev/ThatOS64

#include "stdint.h"

             // ARGB             
#define ORANGE 0xffffa500
#define CYAN   0xff00ffff
#define RED    0xffff0000
#define GREEN  0xff00ff00
#define BLUE   0xff0000ff
#define GRAY   0xff888888
#define WHITE  0xffffffff
#define BLACK  0xff000000

typedef struct GRAPHICS_COLOR_PIXEL
{
    uint8_t   Blue;
    uint8_t   Green;
    uint8_t   Red;
    uint8_t   Alpha;
} GRAPHICS_COLOR_PIXEL;

// Forward declare
void* memcpy(void* dst, const void* src, unsigned long long size);
GRAPHICS_COLOR_PIXEL SetGraphicsColor(uint32_t color);

//int main()
//int main(int argc)
int main(int argc, char* argv[])
{
	int* m;
	memcpy(&m, (int*)&argc, 4);
	
	GRAPHICS_COLOR_PIXEL GraphicsColor = SetGraphicsColor(ORANGE);
	if(m == (int*)3456)
	{
		if(GraphicsColor.Alpha == 0xff)
		{
            return 349587;
		} else {
			return 6666;
		}
	} else {
        return 7777;
	}
}

void* memcpy(void* dst, const void* src, unsigned long long size)
{
    for ( unsigned long long i = 0; i < size; i++ )
        ((unsigned char*) dst)[i] = ((const unsigned char*) src)[i];
    return dst;
}

GRAPHICS_COLOR_PIXEL SetGraphicsColor(uint32_t color)
{
    GRAPHICS_COLOR_PIXEL GColor;
    GColor.Alpha    = color >> 24;
    GColor.Red      = color >> 16;
    GColor.Green    = color >> 8;
    GColor.Blue     = color;
    return GColor;
}