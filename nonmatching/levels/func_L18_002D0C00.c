/* Measured profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: 18_damosel: 564
   bytes, expected 572; us2: 18_damosel: 564 bytes, expected 572; pal: absent pal. 564 bytes versus
   572. Reconstructs signed ring indices, input fallback and matrix update. Early-exit prologue
   scheduling and resident address allocation differ. Reopen with a matching resident rematerialization
   lifetime. No linked build or functional execution run. */

/* Historical screening below; superseded by the measured C reconstruction. */
/* func_L18_002D0C00 - 572 bytes, 3 place(s), level 18_damosel, retail at
   0x002d0c00. Screened with tools/w10_screen.py: 13 call(s)
   [func_L00_002B2BD0@002D0C1C, func_00282978@002D0C74,
   func_L00_002D3400@002D0C94, func_L00_002B3900@002D0CB0,
   func_00282E20@002D0CBC, func_L00_002B3900@002D0D2C,
   func_L18_002D7650@002D0D34, func_00283410@002D0DF0,
   func_00283388@002D0DFC, func_00283698@002D0E08,
   func_L18_002D0850@002D0E10, func_L00_002C2DE8@002D0E18,
   func_L18_002DEFF8@002D0E20]; data addresses materialised [0x1b0000,
   0x190000, 0x140000, 0x190000, 0x190000]; float constants [0x3e800000];
   $gp-relative small data: no   saves: -; callee-saved registers saved [-];
   words plain C cannot emit [LQ/SQ 78820000@0x0038, LQ/SQ 7CA20000@0x003c,
   COP1 46800020@0x0114, COP1 46800860@0x0120, LQ/SQ 78C20000@0x01a8, LQ/SQ
   7C620000@0x01ac]. Head: addiu $sp, $sp, -0x20 ; lui $v0, 0x1B ; lw $v0,
   -0x450($v0) ; sd $s0, 0x0($sp) ; sd $s1, 0x8($sp) ; beqz $v0, . + 4 +
   (0x5 << 2). Not matched in this wave: the 128-bit copy needs an `lq`/`sq`
   pair; plain C reaches it only through a `mode(TI)` local, and this cc1
   folds the destination offset into the `sq` where retail materialises the
   pointer first. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern s32 D_L18_001AFBB0;
extern u8 D_00189E20[];
extern u32 D_00138320, D_00138330;
extern float D_00138288, D_0013828C;
extern void func_L00_002B2BD0(void);
extern s32 func_00282978(void *);
extern s32 func_L00_002D3400(void);
extern float func_L00_002B3900(void);
extern float func_00282E20(void *);
extern void func_L18_002D7650(void);
extern void func_00283410(void *, void *);
extern void func_00283388(void *);
extern void func_00283698(void *, void *);
extern void func_L18_002D0850(void);
extern void func_L00_002C2DE8(void);
extern void func_L18_002DEFF8(void);
void func_L18_002D0C00(void)
{
    u8 *base;
    s32 index;
    if (D_L18_001AFBB0) {
        func_L00_002B2BD0();
        return;
    }
    base = D_00189E20;
    *(VectorBits *)(base + 0x2030) = *(VectorBits *)(base + 0x80);
    if (!(D_00138320 & 3)) func_00282978(base + 0x1454);
    else if (*(s16 *)(base + 0x1454) < 1) *(s16 *)(base + 0x1454) = 1;
    if (*(s32 *)(base + 0x2294) == 16) *(s16 *)(base + 0x1454) = 0;
    base[0x22C3] = func_L00_002D3400();
    *(float *)(base + 0x1FB4) = D_0013828C;
    *(float *)(base + 0x1FB0) = D_00138288;
    *(s32 *)(base + 0x270) = 0;
    *(float *)(base + 0x24BC) = func_L00_002B3900();
    if (func_00282E20(base + 0x1FB0) < 0.25f) {
        *(float *)(base + 0x1FB0) = (float)((s32)((D_00138330 >> 13) & 1) - (s32)((D_00138330 >> 15) & 1));
        *(float *)(base + 0x1FB4) = (float)((s32)((D_00138330 >> 14) & 1) - (s32)((D_00138330 >> 12) & 1));
    }
    *(float *)(base + 0x24B8) = func_L00_002B3900();
    func_L18_002D7650();
    index = *(s32 *)(base + 0x23BC);
    *(float *)(base + 0x233C + index * 4) = *(float *)(base + 0x98);
    *(s32 *)(base + 0x23BC) = (index + 1) % 32;
    if (++*(s32 *)(base + 0x23C0) > 32) *(s32 *)(base + 0x23C0) = 32;
    index = *(s32 *)(base + 0x23C4);
    *(VectorBits *)(base + 0x1D90 + index * 16) = *(VectorBits *)(base + 0x80);
    *(s32 *)(base + 0x23C4) = (index + 1) % 32;
    if (++*(s32 *)(base + 0x23C8) > 32) *(s32 *)(base + 0x23C8) = 32;
    func_00283410(base, base + 0x90);
    func_00283388(base + 0x40);
    func_00283698(base + 0x40, base);
    func_L18_002D0850();
    func_L00_002C2DE8();
    func_L18_002DEFF8();
}
