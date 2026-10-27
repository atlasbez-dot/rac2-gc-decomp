/* func_L00_003DE490 (376 bytes) - NEAR MISS (M22, 2026-10-26).
 * Profile: src/levels/shared/L00_003DE490-g8.c, "-O2 -G8 -ffunction-sections" (qcopy helper).
 * 376/376; the frame, calls and copies match.  Left: the callee-saved choice
 * (retail out $s0, i $s1, obj $s3; here i $s0, out $s3, obj $s4) and the i < 4
 * test is scheduled after its argument setup.  The table, floats and push vector
 * move between levels (ref_ names); the push vector is MACRO_ADDR so its la is
 * rebuilt in the loop like retail.  On the permuter.
 */
#include "include_asm.h"
#include "common.h"

typedef float L00_003DE490_V4[4] __attribute__((aligned(16)));

extern char ref_L00_003DE490_00[];
extern float ref_L00_003DE490_01 __attribute__((sda));
extern float ref_L00_003DE490_02 __attribute__((sda));
extern L00_003DE490_V4 ref_L00_003DE490_03 MACRO_ADDR;

extern void func_00282D30(void *, void *, float);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);

/* Builds the eight corner points of an object's box from its two axes into the
   level's point table: each corner is scaled, moved to the object and pushed out. */
void func_L00_003DE490(char *obj)
{
    L00_003DE490_V4 ax[4];
    L00_003DE490_V4 push;
    L00_003DE490_V4 tip;
    char *out = ref_L00_003DE490_00;
    int i;

    qcopy(ax[0], obj + 0xC0);
    qcopy(ax[3], obj + 0xD0);
    func_00282D30(ax[1], ax[0], -1.0f);
    func_00282D30(ax[2], ax[3], -1.0f);
    qcopy(out + 0x40, ax[0]);
    qcopy(out + 0x50, ax[1]);
    qcopy(out + 0x60, ax[2]);
    qcopy(out + 0x70, ax[3]);
    obj += 0x10;
    for (i = 0; i < 8; i++) {
        if (i < 4)
            func_00282CC0(out, ax[i >> 1], ax[2 + (i & 1)]);
        func_00282F20(out, out, ref_L00_003DE490_01);
        func_00282CC0(out, out, obj);
        func_00282F20(push, ref_L00_003DE490_03, -ref_L00_003DE490_02);
        func_00282CC0(out, out, push);
        out += 0x10;
        func_00282CC0(tip, push, obj);
    }
}
