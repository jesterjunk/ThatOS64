#ifndef STRING_H
#define STRING_H

unsigned long long strlen(char* str);
void Print(BLOCKINFO* bli, char str[], const int screenWidth, const int a, const int b, const unsigned int FontSize, unsigned int c);
void PutCharacter(BLOCKINFO* bli, unsigned short chrNum, const int a, const int b, const unsigned int FontSize, unsigned int c);
void MakeRectangle(BLOCKINFO* bli, int a, int b, int w, int h, unsigned int c);

#endif // STRING_H