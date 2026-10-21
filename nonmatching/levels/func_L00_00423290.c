/* func_L00_00423290 - 360 bytes, 27 place(s), level 00_aranos_tutorial (and every
   other level), retail at 0x00423290. Not matched in wave 14: 340 bytes against the
   retail's 360. The frame (0x60), the seven saved registers, the guard, the twelve
   calls with their argument lists, the float constant (-1.0) and the call order are
   the retail's. What is left is the register allocation and the address
   materialisation:
     - the retail keeps the hero's facing direction in $s0 and takes the hero's
       position 0x240 below it with a separate `addiu $s0,$s0,-0x240`; this cc1 folds
       the -0x240 into the `lq` offset (and a plain `D_00189EA0` symbol gives two
       `lui` pairs instead of one);
     - the retail keeps the object in $s2, its +0x60 in $s1 and copies them with a
       `daddu $s2,$s1,$zero`; this cc1 allocates $s0/$s1/$s2 differently;
     - the retail materialises the three copy destinations (`addiu $v1,$s2,0xC0 ;
       sq $v0,0($v1)`) where this cc1 folds the offset into the `sq`.
   The `mode(TI)` copy through two pointer variables is the pattern that reproduces
   retail's `lq`/`sq` pair. What would unblock it: the source expression tree, so
   this cc1 picks the same registers and keeps the copy addresses in registers. */

#include "include_asm.h"

#ifndef RAC2_T_V4_F0FBA48D3
#define RAC2_T_V4_F0FBA48D3
typedef int V4_F0fba48d3 __attribute__((mode(TI)));
#endif

extern void func_00282CF0_2(void *b, void *c, void *d);

extern void func_00282CC0(void *c, void *c2, void *s);

extern void func_00282D30(void *dst, void *src, float k);

extern float func_00282DB0_1(char *local, char *p);

extern void func_00282C88(void *a);

extern char D_0018A0E0[];

extern char D_00189EA0[];

void func_L00_00423290(char *a0)
{
    char *obj;
    char *v60;
    char *vB0;
    char *vF0;
    char *v160;
    char *hero;
    char *pos;
    V4_F0fba48d3 *dst;
    char buf0[16];
    char buf1[16];

    if (*(short *)(a0 + 0x86) != 0)
        return;

    hero = D_0018A0E0;
    obj = *(char **)(a0 + 0x70);
    v60 = obj + 0x60;
    vB0 = obj + 0xB0;
    vF0 = obj + 0xF0;
    v160 = obj + 0x160;

    func_00282D30(buf0, hero, -1.0f);
    /* The hero's position, 0x240 below the facing direction the call above uses. */
    hero = hero - 0x240;
    *(V4_F0fba48d3 *)v160 = *(V4_F0fba48d3 *)hero;
    dst = (V4_F0fba48d3 *)(obj + 0xC0);
    *dst = *(V4_F0fba48d3 *)v60;
    func_00282D30(obj + 0x70, buf0, func_00282DB0_1(v60, buf0));
    func_00282C88(obj + 0xD0);
    func_00282C88(obj + 0xE0);
    func_00282C88(obj + 0x100);
    func_00282D30(buf1, buf0, *(float *)(v160 + 0x30));
    func_00282CC0(vB0, buf1, v60);
    func_00282D30(buf1, buf0, *(float *)(v60 + 0xB0));
    func_00282CC0(vF0, buf1, v60);
    dst = (V4_F0fba48d3 *)(obj + 0xA0);
    *dst = *(V4_F0fba48d3 *)vF0;
    func_00282CF0_2(v160, a0 + 0x30, vB0);
    dst = (V4_F0fba48d3 *)(obj + 0x170);
    *dst = *(V4_F0fba48d3 *)v160;
    *(V4_F0fba48d3 *)obj = *(V4_F0fba48d3 *)(a0 + 0x30);
    func_00282CC0(obj + 0x210, vB0, v160);
    *(int *)(obj + 0x240) = 0;
}
