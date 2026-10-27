/* OF2 (2026-10-26): 168/168 bytes, default profile, own unit. `D_L05_00221D10 MACRO_ADDR`
   read through a pointer local set in each arm gives retail's `lui ; addiu` in one register
   (the table address as the assembler macro). Only allocation is left: retail has the base
   in $v1 and the two values in $v0/$a0, ours the base in $a0 and the values in $v0/$v1
   (4 lines per arm). Int-returning callees, load-order locals, struct views and char-pointer
   forms all keep ours. Twin of func_L05_00421860; queued for the permuter. */
#include "common.h"

typedef struct {
    char pad[0x10];
    int f10;
    int f14;
    char pad2[0x10];
} Entry;

extern Entry D_L05_002A1800[];
extern int D_L05_00221D10[] MACRO_ADDR;
extern int func_002ED8A0(int);
extern void func_L05_0041C118(char *);
extern void func_L05_0041D498(char *);

void func_L05_003CFC48(char *object)
{
    int index = func_002ED8A0(1);
    int *counts;

    if (index < 0 || D_L05_002A1800[index].f14 == D_L05_002A1800[index].f10) {
        func_L05_0041C118(object);
        counts = D_L05_00221D10;
        counts[0x5C / 4]++;
        counts[0x70 / 4]++;
    } else {
        func_L05_0041D498(object);
        counts = D_L05_00221D10;
        counts[0x64 / 4]++;
        counts[0x70 / 4]++;
    }
}

#if 0
/* func_L05_003CFC48 (168 o) - best attempt, not a match.
   Structure and size are exact (168 bytes, same instructions); the residual is pure
   register allocation: retail keeps the D_L05_00221D10 base in v1 and the loaded value
   in v0, this source allocates them the other way round, and the two loads at +0x10/+0x14
   are taken in the opposite order.  'D[i] = D[i] + 1' vs 'D[i]++' changes nothing.
   verified with: python3 tools/check.py func_L05_003CFC48 --diff (instruction at +0x38 differs)
*/

void func_L05_003CFC48(char *object)
{
    int index = func_002ED8A0(1);

    if (index < 0 || D_L05_002A1800[index].f10 == D_L05_002A1800[index].f14) {
        func_L05_0041C118(object);
        D_L05_00221D10[23] = D_L05_00221D10[23] + 1;
        D_L05_00221D10[28] = D_L05_00221D10[28] + 1;
    } else {
        func_L05_0041D498(object);
        D_L05_00221D10[25] = D_L05_00221D10[25] + 1;
        D_L05_00221D10[28] = D_L05_00221D10[28] + 1;
    }
}

#endif
