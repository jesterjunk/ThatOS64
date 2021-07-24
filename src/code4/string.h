#ifndef STRING_H
#define STRING_H

void ClearScreen(unsigned int c);
long long strlen(char* str);
void Print(unsigned char str[], const unsigned int a, const unsigned int b, const unsigned int FontSize, unsigned int c);
void PutCharacter(unsigned int chrNum, const unsigned int a, const unsigned int b, const unsigned int FontSize, unsigned int c);
void MakeRectangle(unsigned int a, unsigned int b, unsigned int w, unsigned int h, unsigned int c);

#endif // STRING_H