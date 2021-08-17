#ifndef GLOBALS_H
#define GLOBALS_H

// https://gcc.gnu.org/onlinedocs/gcc-3.2/gcc/Variable-Attributes.html
// EXAMPLE : unsigned int MYTEST_P __attribute__ ((section (".text")));

BLOCKINFO* block __attribute__ ((section (".text"))) = {0};
TEXTPOSITION* textPos __attribute__ ((section (".text"))) = {0};

#endif // GLOBALS_H