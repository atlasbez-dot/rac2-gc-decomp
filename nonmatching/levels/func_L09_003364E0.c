/* func_L09_003364E0, 280 bytes, 5 places (09_dobbo, 12_todano, 18_damosel, 19_grelbin,
 * 20_yeedil).
 * NEAR MISS - the candidate is 272 bytes against retail's 280.  The body is right: the
 * level's slot from func_002B9030, the two words the caller passes, the three byte
 * flags, the level's flag byte, the run's own copy of the object's position, the two
 * angles and the object's id - but the register assignment is one out.  Retail keeps the
 * object in $s3, the first int in $s4, the second in $s2, the third in $s0 and the slot
 * pointer in $s1; this cc1 keeps them in $s1, $s3, $s4, $s2 and $s0.  That one register
 * out costs two words: retail computes the base of the last three stores once
 * (`addiu $v0,$s1,0x30`) and the second quadword copy's address once
 * (`addiu $v1,$s1,0x20`), and it fills the branch's delay slot with a copy of the
 * else's first word, where this cc1 duplicates the store of the second angle instead.
 *
 * The two 16-byte copies need the grouped lq/sq pattern, so this unit must be built
 * with -frac2-qcopy; the copy from the object to the slot and the copy from the slot to
 * the slot's second half are both plain `mode(TI)` assignments.
 *
 * What is needed: the source shape that makes this compiler hand out the callee-saved
 * registers the way retail does.  The store order, the parameter types (int or pointer),
 * the pointer variable for the last three stores and the position of the two word stores
 * around the 0.4f call were all measured; the register assignment did not move.
 */

#include "include_asm.h"

typedef unsigned int u32;

typedef unsigned char u8;

typedef int TI128 __attribute__((mode(TI)));

/* the level's pointer to the object's table entry */
extern u32 D_L09_001FF65C;

extern char *func_002B9030(int kind);

extern void func_00283CF0(float f);

extern void func_0029FCC0(char *object, int a, void *b);

/* Builds the object's table entry: the run's own copy of the object's position,
   the level's slot flags and the two angles the caller passed. */
char *func_L09_003364E0(char *object, int a1, char *a2, char *a3, float f12, float f13)
{
    char *s1 = func_002B9030(0x37);

    if (s1 != 0) {
        *(u32 *)(s1 + 0xC) = (u32)a3;
        *(u32 *)(s1 + 4) = (u32)a2;
        func_00283CF0(0.4f);
        *(u8 *)(s1 + 9) = (u8)(s1 + 0x20);
        *(u8 *)(s1 + 3) = 0x48;
        *(u8 *)(s1 + 1) = 3;
        *(u8 *)(s1 + 2) = *(u8 *)(D_L09_001FF65C);
        if (a1 > 0) {
            func_0029FCC0(object, a1, s1 + 0x10);
        } else {
            *(TI128 *)(s1 + 0x10) = *(TI128 *)(object + 0x10);
            *(TI128 *)(s1 + 0x20) = *(TI128 *)(s1 + 0x10);
        }
        *(float *)(s1 + 0x2C) = f13;
        *(float *)(s1 + 0x1C) = f12;
        *(u32 *)(s1 + 0x30) = (u32)object;
        {
            char *q = s1 + 0x30;

            *(float *)(q + 0xC) = f12;
            *(int *)(q + 0x8) = *(short *)(object + 0xAA);
            *(u32 *)(q + 0x4) = a1;
        }
    }
    return s1;
}
