/* Measured profile: -O2 -G0 -ffunction-sections. us: 18_damosel: 500 bytes, expected 496; us2:
   18_damosel: 500 bytes, expected 496; pal: absent pal. Two source forms produced 496 then 500 bytes.
   Resident rematerialization, an additional saved register and branch/store scheduling remain. Reopen
   with a matching resident-state predicate and address lifetime idiom. No linked build or functional
   execution run. */

/* Historical screening below; superseded by the measured C reconstruction. */
/* func_L18_002C4000 - 496 bytes, 3 place(s), level 18_damosel, retail at
   0x002c4000. Screened with tools/w10_screen.py: 6 call(s)
   [func_L00_002D2168@002C4084, func_L00_002D2168@002C40CC,
   func_L00_002D2168@002C40E8, func_L18_00428428@002C416C,
   func_L18_00428428@002C419C, func_L18_00428428@002C41D4]; data addresses
   materialised [0x190000, 0x140000, 0xbff0000]; float constants
   [0x40a00000, 0x40400000, 0x41000000, 0x41100000, 0x40400000]; $gp-
   relative small data: no   saves: -; callee-saved registers saved [-];
   words plain C cannot emit [-]. Head: addiu $sp, $sp, -0x20 ; lui $v0,
   0x19 ; sd $s0, 0x0($sp) ; addiu $v1, $zero, 0xEC0 ; sd $s1, 0x8($sp) ;
   addiu $s0, $v0, -0x61E0. Not matched in this wave: the body is straight-
   line code whose register allocation and the materialisation of its
   constant addresses have to be reproduced word for word. What would
   unblock it: the exact source expression tree, so this cc1 picks the same
   registers in the same order. */

#include "common.h"
extern u8 D_00189E20[];
extern u32 D_00138320;
extern s32 D_L18_001AFBB0 MACRO_ADDR;
extern void func_L00_002D2168(s32, s32, float);
extern void func_L18_00428428(u8 *, s32);
void func_L18_002C4000(void)
{
    u8 *base = D_00189E20;
    u8 *object = *(u8 **)(base + 0x2290);
    if (*(s16 *)(object + 0xAA) != 0xEC0) {
        if ((D_00138320 & 0x80) && D_L18_001AFBB0 == 0 && *(s16 *)(base + 0x1E0) == 0 && *(s32 *)(base + 0x2294) != 0x6F) {
            base[0x22B8] = 1;
            base[0x22BA] = 1;
            if (object[0x43] != 11) {
                func_L00_002D2168(11, 1, 5.0f);
                *(float *)(base + 0xC20) = 3.0f;
            }
        } else if (*(s32 *)(base + 0xC28) & 2) {
            base[0x22B8] = 0;
            base[0x22BA] = 0;
            if (*(s32 *)(base + 0x2294) == 0x8E) func_L00_002D2168(14, 0, 8.0f);
            else func_L00_002D2168(13, 0, 9.0f);
        }
    }
    object = *(u8 **)(D_00189E20 + 0x2290);
    if (object[0x42] == 11 || (*(u64 *)(object + 0x40) & 0xFFFF0000ULL) == 0x0BFF0000ULL) {
        *(float *)(D_00189E20 + 0xC20) = 3.0f;
        if (*(s16 *)(object + 0xAA) == 0xEE1) {
            if (*(s32 *)(D_00189E20 + 0x1D8) > 3) {
                if (*(s32 *)(D_00189E20 + 0x1D8) % 6 == 0) func_L18_00428428(object, 0);
                if ((*(s32 *)(D_00189E20 + 0x1D8) + 3) % 6 == 0) func_L18_00428428(*(u8 **)(D_00189E20 + 0x2290), 1);
            }
        } else if (*(s16 *)(object + 0xAA) == 0xED4 && *(s32 *)(D_00189E20 + 0x1D8) % 6 != 0) {
            func_L18_00428428(object, 0);
        }
    }
}
