#include "include_asm.h"

/* The retail body builds the object's matrix from two others and copies two 128-bit
   fields into the object: the first copy only when the object's flag at +0x3C asks
   for it, the second one always.

   With -frac2-qcopy the two copies are the retail's `lq`/`sq` pairs with both
   addresses in registers, and everything else matches, except that this cc1 moves
   the epilogue's first restore (`ld $s0,0x100($sp)`) in front of the second pair
   while the retail keeps the pair together and the restore after it.  The source
   shapes tried here (the copy through a pointer variable, without one, the pointer
   declared inside the block, the second store volatile) do not change it.

   Without the flag the destination address is folded into the `sq` and the second
   copy is hoisted in front of the branch, so the flag is needed as well. */
#ifndef RAC2_T_V4_002AD6F0
#define RAC2_T_V4_002AD6F0
typedef int V4_002AD6F0 __attribute__((mode(TI)));
#endif

typedef struct { char pad[64]; } Matrix64_002AD6F0;

extern void F0e7bb6a8_FUN_00283410(char *dst, char *src);
extern void F0e7bb6a8_FUN_00283698(char *dst, char *src);
extern void F0e7bb6a8_FUN_00283788(char *a, char *b, char *c);
extern void F0e7bb6a8_FUN_002AB6D8(char *a, char *b);

void func_002AD6F0(void *obj, void *a1, void *a2, void *a3)
{
    Matrix64_002AD6F0 m0, m1, m2, m3;
    V4_002AD6F0 *p;

    F0e7bb6a8_FUN_00283410((char *)&m0, (char *)a2);
    F0e7bb6a8_FUN_00283698((char *)&m1, (char *)&m0);
    F0e7bb6a8_FUN_00283410((char *)&m2, (char *)a3);
    F0e7bb6a8_FUN_00283788((char *)&m3, (char *)&m1, (char *)&m2);
    F0e7bb6a8_FUN_002AB6D8((char *)&m3, (char *)obj);
    if (*(int *)((char *)obj + 0x3C) & 2) {
        p = (V4_002AD6F0 *)((char *)obj + 0x20);
        *p = *(V4_002AD6F0 *)a2;
    }
    p = (V4_002AD6F0 *)((char *)obj + 0x10);
    *p = *(V4_002AD6F0 *)a1;
}
