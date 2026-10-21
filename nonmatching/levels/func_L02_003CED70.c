/* func_L02_003CED70 - 208 bytes, 2 place(s), level 02_maktar_nebula (also 15_gorn),
   retail at 0x003ced70. Not matched in wave 14: 180 bytes against the retail's 208.
   The body, the guard, the flag word and the call sequence are the retail's; what is
   left is how the two 16-byte copies are addressed. The retail materialises the
   addresses in registers (`daddu $s3, $sp, $zero ; lq $v0,0($s3) ; sq $v0,0($v1)`),
   while this cc1 always folds a frame-derived address back into the instruction's
   offset field - the same wall as func_L00_00396288 and func_L20_00449338. The
   float reads of the second quadword (`lwc1 $f12,0x10($sp) ; lwc1 $f13,0x4($s2)`)
   need the same register form. What would unblock it: a source spelling whose
   address this cc1 cannot fold, or a cc1 change that keeps a MEM_LOCAL address in
   a register instead of folding it into the offset. */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750_1(char *a0, int a1, int a2, char *a3);

extern int func_002B6318(unsigned char *object);

extern float func_00283248(float, float);

void func_L02_003CED70(char *a0, char *a1, char *a2)
{
    TI128 v0, v1;
    TI128 *p0 = &v0;
    TI128 *p1 = &v1;
    TI128 *q;
    char *p;
    unsigned short h;
    int t;

    v0 = *(TI128 *)a1;
    v1 = *(TI128 *)a2;
    p = *(char **)(a0 + 0x68);
    if (*(unsigned char *)(a0 + 0x20) != 0xD)
        return;
    h = *(unsigned short *)(a0 + 0x34);
    h &= 0xFFBE;
    h |= 0x1000;
    *(unsigned short *)(a0 + 0x34) = h;
    *(int *)(a0 + 0x98) = *(int *)(*(char **)(a0 + 0x24) + 0x10);
    func_002A7750_1(a0, 0xE, -1, *(char **)(a0 + 0x24));
    q = (TI128 *)(a0 + 0x10);
    *q = *p0;
    *(float *)(a0 + 0xF8) = func_00283248(*(float *)&v1, *(float *)((char *)p1 + 4));
    func_002B6318((unsigned char *)a0);
    q = (TI128 *)(p + 0x1A0);
    *q = *p1;
    t = *(int *)(p + 0x138);
    *(int *)(p + 0x124) = 0;
    t |= 0x11;
    *(int *)(p + 0x120) = 0;
    *(int *)(p + 0x138) = t;
}
