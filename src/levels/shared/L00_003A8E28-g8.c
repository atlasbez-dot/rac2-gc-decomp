#include "include_asm.h"

/* Small-data sibling of L00_003A8E28.c: the body below reaches the level's
   globals through $gp (the file gets -G8 by its name, see config/cflags.txt). */

extern char D_L00_0023BB78[];

extern unsigned char D_L00_001AF810 __attribute__((sda));

extern unsigned char D_L00_001AF811 __attribute__((sda));

extern void func_2EDE88();

typedef int TI128 __attribute__((mode(TI)));

extern float D_L00_001AF7A4 __attribute__((sda));

extern void func_00283098(void *, void *, void *);

extern void func_00282CC0(void *, void *, void *);

/* Builds the local vector {scale, 0, 0, 1}, transforms its copy, then adds the object position. */
void func_L00_003ACC88(char *a0, char *a1)
{
    float other[4];
    float local[4];
    TI128 zero = 0;

    *(TI128 *)local = zero;
    local[0] = D_L00_001AF7A4;
    local[3] = 1.0f;
    *(TI128 *)other = *(TI128 *)local;
    func_00283098(other, other, a0 + 0xC0);
    func_00282CC0(a1, other, a0 + 0x10);
}

/* Resets the two slot cursors, then releases the 256-entry slot table. */
void func_L00_003B09F8(void)
{
    D_L00_001AF811 = 0;
    D_L00_001AF810 = 0;
    func_2EDE88(D_L00_0023BB78, 0x1C00);
}
