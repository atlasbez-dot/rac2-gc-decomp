/* func_L09_00403398 (872 bytes, 1 place: level 09_dobbo) - best attempt, NOT MATCHED.
 *
 * Built as a function of src/levels/09_dobbo/L09_003FEA48-g8.c (small-data floats through $gp),
 * this body is 872 bytes, the size of retail's, but only 177 of retail's 218 words line up
 * (aligned count with relocated fields loosened).  tools/check.py: "instruction at +0x8 differs"
 * (the prologue, from the allocation below).
 * The whole shape is recovered: the early exit for states 9 and 4 placed after the main code
 * (an if/else, not an early return), the three "chase" blends of the state's float at +0x294
 * (toward +0x288/+0x264 plus a constant, then toward the float of the entity at +0x230 for states
 * 6 to 8), the unrotated walk of the id list (second `p != 0` guard, the group byte and count
 * read through $gp in the branch delay slot) and its calls (vector subtract, length with the clamp,
 * func_002A7790 whose float result is dropped, scale, add), then the two calls with the state's
 * rotation words.  The float constants 0x3D088889, 0x3DCCCCCD, 0x3DB2B8C4, 0x3CD67752 and
 * 0x3E0EFA36 are spelled as below.
 *
 * What differs:
 *
 *  1. The 128-bit address wall, twice.  Retail copies the object's position into a local with
 *         addiu $v1,$s3,0x10 ; lq $v0,0($v1) ; sq $v0,0($sp)      (and later daddu $s6,$v1,$zero)
 *     and clears the second local with `addiu $v1,$sp,0x10 ; sq $zero,0($v1)`; this cc1 folds both
 *     displacements: `lq $v0,0x10($s3)` and `sq $zero,0x10($sp)`.  The address is used again
 *     afterwards (the pointer `pos` kept in $s6, the pointer to the vector kept in $s4), which is
 *     the case where retail materialises it.  Tried here: a named pointer used for both the copy
 *     and the calls, two names for the same pointer, and the pointer taken before or after the
 *     branch: find_best_addr substitutes the register-plus-constant of the same cost every time.
 *     That costs the `addiu`/`daddu` pair and moves the delay slot of the second `beq` of the
 *     state test (retail has the `addiu $v1,$s3,0x10` there; here the compiler makes the second
 *     branch a `beql`).
 *
 *  2. Register allocation: the object pointer is in $s2 and the copy of the vector's address in
 *     $s3, retail has them the other way round; retail loads the state's float at +0x294 into
 *     $f1 and subtracts the 1/30 step (in $f0) in place, this cc1 loads it into $f2 and writes
 *     the difference to $f0 (a temporary for the load, a compound assignment and the plain form
 *     were tried).
 *
 * The local at sp+0 (the copy of the position with its z replaced) is dead in retail too: it is
 * written and never read.
 */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s32 D_L09_001B2878;
extern u8 *D_L09_001B285C_1;
extern u16 *D_L09_001FB560[];

typedef int TI128 __attribute__((mode(TI)));

extern f32 D_L09_001B13B8 __attribute__((sda));
extern f32 D_L09_001B13BC __attribute__((sda));
extern f32 D_L09_001B13C4 __attribute__((sda));
extern f32 D_L09_001B13C8 __attribute__((sda));
extern f32 D_L09_001B13CC __attribute__((sda));
extern f32 D_L09_001B13D0 __attribute__((sda));
extern u8 *D_0018C0B0;

extern void func_00282CF0(void *, void *, void *);
extern f32 func_00282DF0(void *);
extern void func_00282F20(void *, void *, f32);
extern void func_00282CC0(void *, void *, void *);
extern f32 func_002A7790(f32);
extern void func_002AEE70(u8 *, void *, void *, f32, f32, f32);
extern void func_002AEF28(u8 *, void *, void *, f32, f32, f32);

void func_L09_00403398(u8 *a0)
{
    u8 *state = *(u8 **)(a0 + 0x68);
    f32 P[4] __attribute__((aligned(16)));
    f32 B[4] __attribute__((aligned(16)));
    f32 C[4] __attribute__((aligned(16)));
    u8 *pos;
    u8 *t;
    u16 *p;
    u8 *e;
    f32 f0, f2, len, w;
    f32 *r0, *r1, *r2, *r3;

    *(f32 *)(state + 0x288) = *(f32 *)(a0 + 0x18);
    if (a0[0x20] != 9 && a0[0x20] != 4) {
        f2 = *(f32 *)(state + 0x294);
        *(f32 *)(state + 0x294) = f2 - 0.033333335f;
        pos = a0 + 0x10;
        *(TI128 *)P = *(TI128 *)pos;
        P[2] = *(f32 *)(state + 0x294) + (D_L09_001B13C4 - D_L09_001B13BC);
        t = *(u8 **)(state + 0x188);
        if (t == 0 || (t != D_0018C0B0 && *(s16 *)(t + 0xAA) != 0xD57 &&
                       *(s16 *)(*(u8 **)(t + 0x24) + 0x46) >= 11)) {
            f0 = *(f32 *)(state + 0x288) + D_L09_001B13BC;
            f2 = *(f32 *)(state + 0x294);
            if (f2 < f0)
                *(f32 *)(state + 0x294) = f2 + (f0 - f2) * D_L09_001B13C8;
        }
        f0 = *(f32 *)(state + 0x264) + D_L09_001B13BC;
        f2 = *(f32 *)(state + 0x294);
        if (f2 < f0)
            *(f32 *)(state + 0x294) = f2 + (f0 - f2) * D_L09_001B13C8;
        if (a0[0x20] >= 6 && a0[0x20] <= 8) {
            f0 = *(f32 *)(*(u8 **)(state + 0x230) + 0x18) + D_L09_001B13B8;
            f2 = *(f32 *)(state + 0x294);
            if (f2 < f0)
                *(f32 *)(state + 0x294) = f2 + (f0 - f2) * D_L09_001B13CC;
        }
        *(f32 *)(a0 + 0x18) = *(f32 *)(state + 0x294);
        *(TI128 *)B = 0;
        r0 = (f32 *)(state + 0x278);
        r1 = (f32 *)(state + 0x27C);
        r2 = (f32 *)(state + 0x280);
        r3 = (f32 *)(state + 0x284);
        for (p = D_L09_001FB560[a0[0x21]];
             a0[0x21] != 0xFF && a0[0x21] <= D_L09_001B2878 && p != 0 &&
             ((p != 0 && (s16)p[-1] >= 0) || p == D_L09_001FB560[a0[0x21]]);
             p++) {
            e = D_L09_001B285C_1 + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            func_00282CF0(C, pos, e + 0x10);
            len = func_00282DF0(C);
            if (len > D_L09_001B13D0)
                len = D_L09_001B13D0;
            else if (len < 0.0f)
                len = 0.0f;
            w = 1.0f - len / D_L09_001B13D0;
            func_002A7790(w);
            func_00282F20(C, C, len * w);
            func_00282CC0(B, B, C);
        }
        func_00282CC0(pos, pos, B);
        func_002AEE70(a0, r0, r1, 0.1f, 0.087266475f, *(f32 *)(a0 + 0x18));
        func_002AEF28(a0, r2, r3, 0.13962635f, 0.026179943f, 0.026179943f);
    } else {
        *(f32 *)(state + 0x294) = *(f32 *)(a0 + 0x18);
    }
}
