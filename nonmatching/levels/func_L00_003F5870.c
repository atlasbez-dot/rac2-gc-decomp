/* func_L00_003F5870 (384 bytes, 27 places) - NEAR MISS (M22, 2026-10-26).
 * Profile: src/levels/shared/L00_003F5870-g8.c, "-O2 -G8 -ffunction-sections -frac2-zero-ti-por".
 * 384/384 bytes, about 8 words off.  The per-level globals are ref_ names (they move
 * between levels).  Left: retail keeps the 0x30*index product in $s0 across the
 * func_00282C48 call and rebuilds base+product-0x20 for func_00282CF0's third
 * argument, where this C reuses rec-0x20 (CSE); the final rec then lands in $s2 not
 * $s0.  Tried (index-1)*0x30+0x10, (base-0x20)+off, an int sum, a row-array index,
 * and the else arm without rec.  On the permuter.
 */
#include "include_asm.h"
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern s32 ref_L00_003F5870_00 MACRO_ADDR;
extern float ref_L00_003F5870_01 __attribute__((sda));
extern int func_002AFFD8(void *, void *, int);
extern float func_00282C48(float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_002AB668(void *, void *, float);
extern void func_002ACDE8(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);

/* One joint of a 0x30-byte-per-joint chain: its offset is the chain's up axis, or its
   direction from the joint before it, scaled by the joint's length. */
void func_L00_003F5870(char *base, int index)
{
    float up[4] __attribute__((aligned(16)));
    float dir[4] __attribute__((aligned(16)));
    float diff[4] __attribute__((aligned(16)));
    float normal[4] __attribute__((aligned(16)));
    char *rec;

    *(TI128 *)up = 0;
    up[2] = 1.0f;
    if (ref_L00_003F5870_00 != 0)
        func_002AFFD8(up, base + index * 0x30 + 0x10, 1);
    if ((float)index == 0.0f
        || func_00282C48(*(float *)(base + index * 0x30 + 0x20)) < 0.00001f) {
        func_00282D30(dir, up, *(float *)(base + index * 0x30 + 0x24));
    } else {
        rec = base + index * 0x30;
        func_00282CF0(diff, rec + 0x10, base + index * 0x30 - 0x20);
        func_00282F20(normal, diff, 1.0f);
        func_002AB668(normal, normal, *(float *)(rec + 0x20));
        func_002ACDE8(dir, up, normal);
        func_00282D30(dir, dir, *(float *)(rec + 0x24));
    }
    rec = base + index * 0x30;
    func_00282CC0(rec, rec + 0x10, dir);
    *(float *)(rec + 0xC) = ref_L00_003F5870_01;
}
