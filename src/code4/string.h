#ifndef STRING_H
#define STRING_H

long long strlen(char* str);
void Print(BLOCKINFO* bli, unsigned char str[], const unsigned int screenWidth, const unsigned int a, const unsigned int b, const unsigned int FontSize, unsigned int c);
void PutCharacter(BLOCKINFO* bli, unsigned int chrNum, const unsigned int a, const unsigned int b, const unsigned int FontSize, unsigned int c);
void MakeRectangle(BLOCKINFO* bli, unsigned int a, unsigned int b, unsigned int w, unsigned int h, unsigned int c);

#endif // STRING_H