#ifndef CR_REGISTERS_H
#define CR_REGISTERS_H

unsigned long long READ_cr0(void);
unsigned long long READ_cr2(void);
unsigned long long READ_cr3(void);
unsigned long long READ_cr4(void);
unsigned long long READ_cr8(void);

void WRITE_cr0(unsigned long long value);
void WRITE_cr3(unsigned long long value);
void WRITE_cr4(unsigned long long value);
void WRITE_cr8(unsigned long long value);

#endif  // CR_REGISTERS_H
