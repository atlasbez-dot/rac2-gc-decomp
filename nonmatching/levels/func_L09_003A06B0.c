/* func_L09_003A06B0, 292 bytes, 3 places (09_dobbo, 12_todano, 20_yeedil).
 * NEAR MISS - the candidate is retail's exact size and every instruction is present, but
 * eleven of them sit in a different order.  The body is right: the level's own object from
 * func_0029EFD0(0x3A6), the three byte flags and the 0xFFFF one, the 64-bit word copied
 * from the caller's object, the two 16-byte copies (the caller's vector into the level's
 * object and the level's vector into the object's own), the 0xF0 word, the caller's angle,
 * the two distance calls (the second one negated into the object's 0xF4), the level's
 * table entry and the flag word.
 *
 * The residue is the schedule of the first block and one word in the middle: retail
 * reloads the first distance from the field it has just stored (`mov.s $f12,$f0` - the
 * store and the load are adjacent, so the load is a copy), this cc1 keeps the distance in
 * a register across the vector-length call and so the load stays a load
 * (`lwc1 $f12,0xF8($s1)`).  Both orders were measured: with the load after the call the
 * word is right and the call's place in the block is wrong; with the call last (and the
 * load folded) the call's place is still wrong, because this compiler does not move a
 * call.  Marking the vector-length function `const` deletes the call outright (its result
 * is unused), so that is not the way either.
 *
 * The two 16-byte copies need the grouped lq/sq pattern, so this unit must be built
 * with -frac2-qcopy.
 */

#include "include_asm.h"

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long long u64;

typedef int TI128 __attribute__((mode(TI)));

extern void *func_0029EFD0(int id);

extern float func_00283248(float x, float y);

extern float func_00282E20(char *a);

extern void func_002A0F48(char *a);

extern char *func_L09_003364E0(char *object, int a1, int a2, int a3, float f12, float f13);

/* Builds the level's own object for the run and hands it the two vectors it rides on. */
char *func_L09_003A06B0(char *object, char *a1, char *a2, float f12)
{
    char *s1 = func_0029EFD0(0x3A6);
    char *s0;
    float d;

    if (s1 != 0) {
        *(u8 *)(s1 + 0x30) = 0xFF;
        *(u16 *)(s1 + 0x32) = 0xFF;
        *(u8 *)(s1 + 0x31) = 1;
        *(u8 *)(s1 + 0x20) = 0;
        *(u64 *)(s1 + 0x38) = *(u64 *)(object + 0x38);
        *(TI128 *)(s1 + 0x10) = *(TI128 *)a2;
        s0 = *(char **)(s1 + 0x68);
        *(TI128 *)s0 = *(TI128 *)a1;
        *(u32 *)(s0 + 0x3C) = (u32)object;
        *(u32 *)(s0 + 0x38) = 0xF0;
        *(float *)(s0 + 0x40) = f12;
        *(float *)(s1 + 0xF8) = func_00283248(*(float *)a1, *(float *)(a1 + 4));
        func_00282E20(a1);
        *(float *)(s1 + 0xF4) =
            -func_00283248(*(float *)(s1 + 0xF8), *(float *)(a1 + 8));
        *(u32 *)(s0 + 0x48) =
            (u32)func_L09_003364E0(s1, -1, 0xF0208080, 0x60, 0.1f, 0.01f);
        func_002A0F48(s1);
        *(u8 *)(s1 + 0x31) = 0;
        *(u16 *)(s1 + 0x34) |= 1;
    }
    return s1;
}
