#include "include_asm.h"

/* func_00313678 - 84 bytes, 28 places.  qcopy needs the copy source kept in a
 * char * local while the call passes the same pointer; folding the load made
 * the source address a constant offset.  Matches in all three releases. */

typedef int TI128 __attribute__((mode(TI)));

extern void func_002B00D8(void *p, float *a1, float *a2, float f);
extern int func_002761F8(void *a, void *b, int mode, void *self, int flag);
extern char D_00189F00[];

int func_00313678(char *x)
{
    char local[16];
    char *p = x + 0x10;

    *(TI128 *)local = *(TI128 *)p;
    func_002B00D8(p, (float *)local, (float *)local, -0.5f);
    return func_002761F8(local, D_00189F00, 0x12, 0, 0) == 0;
}
