/* Near miss: the whole body is recovered, eight bytes (two words) still differ.

   func_L01_00333FA8 (level 01, 0x00333FA8, 312 bytes) creates the moby of type
   0x57, fills it from its four arguments and returns it.  The candidate is 304
   bytes and differs from retail in three places:

     - retail computes the tail's address once (`addiu $v1,$s1,0x20`) and stores
       the two tail words through it (`sw $s3,0x8($v1)` ; `sh $s0,0x6($v1)`);
       this cc1 folds the offsets back into the object pointer
       (`sw $s3,0x28($s1)` ; `sh $s0,0x26($s1)`).  A volatile pointer to the tail
       (`volatile char *t = (volatile char *)&obj->tail;`) keeps the base register
       and gives retail's three words, but it also stops this cc1 from filling the
       delay slots of the two calls around it, where retail has
       `daddu $a1,$sp,$zero`.
     - retail reloads the moby's first word before the call to func_0029FCC0
       (`lw $a0,0x20($s1)`); this cc1 forwards the store into the call's argument.
       Only a volatile load (`*(void *volatile *)&obj->tail.f20`) keeps the reload,
       and it again constrains the scheduler.
     - retail's tail (the byte stores at +1, +2, +3, +8 and +9 and the word at
       +0x0C) is emitted in another order: retail hoists `lui $a1,0x20` (the
       address of D_L01_001FF19C) before the shift chain and keeps the constant
       0x48 in $a0, this cc1 in $v1.

   What is measured:
     - the 128-bit copy in the `(short)arg2 == -1` arm needs the file's TI128
       type (`typedef int TI128 __attribute__((mode(TI)));`): it gives retail's
       `lq $v0,0($v1)` / `sq $v0,0($a0)` pair, and plain C never emits lq/sq.
     - the argument of func_00282F20 is a fourth one (the retail sets $a2 as
       well as $a0/$a1/$f12), so the prototype here has four parameters.
     - the moby's byte at +8 is the result of func_001163B0 (the store sits in
       the delay slot of the next call), and the byte at +9 is
       `((short)*(unsigned short *)(arg0 + 0x32) >> 5) * 16` plus the result of
       func_00283CF0(4.0f).

   The remaining wall is the scheduler's freedom around the volatile accesses:
   retail has both the tail's base register and free delay slots, and no plain C
   spelling tried (struct field, nested struct, volatile pointer, volatile load)
   gives both at once. */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void *func_002B9030(int);

extern void func_0029FCC0(void *, int, void *);

extern void func_00282CF0(void *, void *, void *);

extern void func_00282F20(void *, void *, void *, float);

extern void func_00282CC0(void *, void *, void *);

extern int func_00283CF0(float);

extern int func_001163B0(void);

extern char D_L01_001B94C0[];

extern char *D_L01_001FF19C;

typedef struct {
    void *f20;
    char pad3[2];
    short f26;
    void *f28;
} L01_00333FA8_TAIL;

typedef struct {
    char pad0[1];
    char f01;
    char f02;
    char f03;
    int f04;
    char f08;
    char f09;
    char pad2[2];
    float f0C;
    TI128 f10;
    L01_00333FA8_TAIL tail;
} L01_00333FA8_OBJ;

void *func_L01_00333FA8(void *arg0, void *arg1, int arg2, float arg3)
{
    L01_00333FA8_OBJ *obj;
    char buf0[16];
    char buf1[16];
    volatile char *t;
    int r;

    obj = func_002B9030(0x57);
    if (obj != 0) {
        obj->tail.f20 = arg0;
        t = (volatile char *)&obj->tail;
        *(short *)(t + 6) = arg2;
        *(void **)(t + 8) = arg1;
        if ((short)arg2 == -1) {
            obj->f10 = *(TI128 *)(arg0 + 0x10);
        } else {
            func_0029FCC0(*(void *volatile *)&obj->tail.f20, (short)arg2, buf0);
            func_00282CF0(buf1, D_L01_001B94C0, buf0);
            func_00282F20(buf1, buf1, buf1, 0.4f);
            func_00282CC0(&obj->f10, buf0, buf1);
        }
        obj->f08 = (char)func_001163B0();
        obj->f04 = (int)arg1;
        r = func_00283CF0(4.0f);
        obj->f03 = 0x48;
        obj->f0C = arg3;
        obj->f01 = 0;
        obj->f09 = (char)((((short)*(unsigned short *)(arg0 + 0x32) >> 5) * 16) + r);
        obj->f02 = *D_L01_001FF19C;
    }
    return obj;
}
