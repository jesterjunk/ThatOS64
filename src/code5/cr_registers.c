#include "cr_registers.h"

unsigned long long READ_cr0() {
    unsigned long long ret;
    __asm__ __volatile__("mov %%cr0, %0" : "=r"(ret));
    return ret;
}

unsigned long long READ_cr2() {
    unsigned long long ret;
    __asm__ __volatile__("mov %%cr2, %0" : "=r"(ret));
    return ret;
}

unsigned long long READ_cr3() {
    unsigned long long ret;
    __asm__ __volatile__("mov %%cr3, %0" : "=r"(ret));
    return ret;
}

unsigned long long READ_cr4() {
    unsigned long long ret;
    __asm__ __volatile__("mov %%cr4, %0" : "=r"(ret));
    return ret;
}

unsigned long long READ_cr8() {
    unsigned long long ret;
    __asm__ __volatile__("mov %%cr8, %0" : "=r"(ret));
    return ret;
}

void WRITE_cr0(unsigned long long value) {
    __asm__ __volatile__("mov %0, %%cr0" :: "r"(value));
}

void WRITE_cr3(unsigned long long value) {
    __asm__ __volatile__("mov %0, %%cr3" :: "r"(value));
}

void WRITE_cr4(unsigned long long value) {
    __asm__ __volatile__("mov %0, %%cr4" :: "r"(value));
}

void WRITE_cr8(unsigned long long value) {
    __asm__ __volatile__("mov %0, %%cr8" :: "r"(value));
}