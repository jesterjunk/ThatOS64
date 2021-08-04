#ifndef STRING_H
#define STRING_H

void ClearScreen(uint32_t c);
int64_t strlen(int8_t* str);
void Print(uint8_t str[], const uint32_t a, const uint32_t b, const uint32_t FontSize, uint32_t c);
void PutCharacter(uint32_t chrNum, const uint32_t a, const uint32_t b, const uint32_t FontSize, uint32_t c);
void MakeRectangle(uint32_t a, uint32_t b, uint32_t w, uint32_t h, uint32_t c);

#endif // STRING_H