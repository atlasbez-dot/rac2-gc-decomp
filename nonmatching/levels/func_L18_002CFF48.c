/* Measured profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: 18_damosel: 512
   bytes, expected 504; us2: absent us2; pal: absent pal. The 512-byte body reconstructs state
   restoration and resolves all three callback addresses canonically. Remaining callback argument
   ordering, state stores and address scheduling need a new source-shape hypothesis. No linked build or
   functional execution run. */

/* Historical screening below; superseded by the measured C reconstruction. */
/* func_L18_002CFF48 - 504 bytes, 2 place(s), level 18_damosel, retail at
   0x002cff48. Screened with tools/w10_screen.py: 12 call(s)
   [func_002AB1F0@002CFF78, func_0029B758@002CFFC8,
   func_L00_002B2BD0@002CFFD0, func_L00_002A53B8@002D0000,
   func_0028B3D0@002D0030, func_L00_002F6B90@002D0038,
   func_L00_002A6708@002D0058, func_L00_002D24B8@002D0084,
   func_L00_002A4DB0@002D00A8, func_L00_002A4DB0@002D00C8,
   func_L18_002E0070@002D0104, func_L00_002D9D98@002D0120]; data addresses
   materialised [0x190000, 0x310000, 0x310000, 0x310000, 0x1b0000,
   0x1b0000]; float constants [0x3f800000, 0x1b0000]; $gp-relative small
   data: no   saves: -; callee-saved registers saved [-]; words plain C
   cannot emit [COP1 46800020@0x0044, LQ/SQ 78620000@0x0058, LQ/SQ
   7C820000@0x005c, LQ/SQ 78A20000@0x0068, LQ/SQ 7C620000@0x006c, LQ/SQ
   78A20000@0x0128, LQ/SQ 7C620000@0x012c]. Head: addiu $sp, $sp, -0x20 ;
   lui $v0, 0x19 ; sd $s0, 0x0($sp) ; sd $s1, 0x8($sp) ; addiu $s0, $v0,
   -0x61E0 ; sd $s2, 0x10($sp). Not matched in this wave: the 128-bit copy
   needs an `lq`/`sq` pair; plain C reaches it only through a `mode(TI)`
   local, and this cc1 folds the destination offset into the `sq` where
   retail materialises the pointer first. What would unblock it: the exact
   source expression tree, so this cc1 picks the same registers in the same
   order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern u8 D_00189E20[];
extern u8 D_L18_001B4E00[], D_L18_001B5400[];
extern s32 D_L18_001A8F00;
extern s32 func_002AB1F0(u8 *);
extern void func_0029B758(s32, s32);
extern void func_L00_002B2BD0(void);
extern void func_L00_002A53B8(void);
extern void func_0028BDB0(u8 *);
extern void func_0028BE00(u8 *);
extern void func_0028C6D0(u8 *);
extern s32 func_0028B3D0(s32, s32, void (*)(u8 *), void (*)(u8 *), void (*)(u8 *), s32, s32);
extern s32 func_L00_002F6B90(u32);
extern void func_L00_002A6708(void);
extern void func_L00_002D24B8(void);
extern s32 func_L00_002A4DB0(char *, s32, s32, s32);
extern s32 func_L18_002E0070(s32, s32);
extern void func_L00_002D9D98(void);
void func_L18_002CFF48(s32 keep)
{
    u8 *base = D_00189E20;
    u8 *object;
    float *record;
    s32 value;
    if (base[0x22B4] == 4) {
        record = (float *)func_002AB1F0(*(u8 **)(base + 0x2290));
        if (record) *record = (float)*(s32 *)(base + 0x24CC);
        object = *(u8 **)(base + 0xC18);
        *(VectorBits *)(base + 0x80) = *(VectorBits *)(object + 0x10);
        *(VectorBits *)(base + 0x90) = *(VectorBits *)(object + 0xF0);
        *(s32 *)(base + 0x24CC) = *(s16 *)(base + 0x24D4);
        if (!keep) func_0029B758(0, 0);
        func_L00_002B2BD0();
        *(s16 *)(base + 0x34E) = 1;
        *(s32 *)(base + 0x3A4) &= ~1;
        *(s32 *)(base + 0x3A4) &= ~2;
        base[0x22B5] = 0;
        *(s32 *)(base + 0x3A0) = 0;
    }
    func_L00_002A53B8();
    D_00189E20[0x22B4] = 0;
    func_0028B3D0(35, 0, func_0028BDB0, func_0028BE00, func_0028C6D0, 0, 0);
    func_L00_002F6B90(3);
    object = *(u8 **)(D_00189E20 + 0xC14);
    if (object) *(u16 *)(object + 0x34) &= ~6;
    *(u8 **)(D_00189E20 + 0xC14) = 0;
    func_L00_002A6708();
    object = *(u8 **)(D_00189E20 + 0xC18);
    *(u8 **)(D_00189E20 + 0x2290) = object;
    *(VectorBits *)(object + 0x10) = *(VectorBits *)(D_00189E20 + 0x80);
    *(s32 *)(object + 0x9C) = 0;
    *(float *)(D_00189E20 + 0xC24) = 1.0f;
    func_L00_002D24B8();
    object = *(u8 **)(D_00189E20 + 0x2290);
    if (object[0x42] != 255) {
        value = func_L00_002A4DB0((char *)object, object[0x42], object[0x40], (s32)D_L18_001B4E00);
        *(s32 *)(*(u8 **)(D_00189E20 + 0x2290) + 0x58) = value;
    }
    object = *(u8 **)(D_00189E20 + 0x2290);
    value = func_L00_002A4DB0((char *)object, object[0x43], object[0x41], (s32)D_L18_001B5400);
    *(s32 *)(*(u8 **)(D_00189E20 + 0x2290) + 0x5C) = value;
    if (*(s32 *)(D_00189E20 + 0x2294) != 0x61 || (D_L18_001A8F00 != 2 && D_L18_001A8F00 != 6)) func_L18_002E0070(0, 1);
    if (D_00189E20[0x22B4] == 4) func_L00_002D9D98();
}
