/* from src/core/0011F938.c: the catalogue row is 52 bytes but the function is 48.
   Its first word is the linker's 0xCDCDCDCD fill between objects, and the USA v2.00
   symbol table has no func_0011F9E4 at all: it lists func_0011F9E8, the real entry.
   The C below is rac1-decomp's func_0011DD68 (exit.o's kCopy) and reproduces the 48
   bytes at 0x0011F9E8 exactly: tools/check.py prints "48 bytes, expected 52" and
   --diff lines the candidate up instruction for instruction one word behind retail.
   Unblocked by splitting the row in tools/levels.py, not by more C. */
#include "common.h"

/* kCopy: a byte copy loop returning 0. */
int func_0011F9E4(char *dst, char *src, unsigned int n) {
    unsigned int i;

    for (i = 0; i < n; i++) {
        *dst++ = *src++;
    }
    return 0;
}
