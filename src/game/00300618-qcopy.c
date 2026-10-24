#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void *func_0029EFD0(int id);
extern void func_002A0F48(char *object);

/* Finds the object with the fixed id, marks it and gives it the caller's position. */
int func_00302A20(void *object)
{
    void *found = func_0029EFD0(0x3EF);

    if (found != 0) {
        *(unsigned short *)((char *)found + 0x34) |= 0x41;
        *(unsigned char *)((char *)found + 0x30) = 0xFF;
        *(TI128 *)((char *)found + 0x10) = *(TI128 *)object;
        func_002A0F48(found);
    }
    return (int)found;
}
