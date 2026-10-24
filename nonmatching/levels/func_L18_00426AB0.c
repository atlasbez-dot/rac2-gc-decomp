/* Measured profile: -O2 -G8 -ffunction-sections. us: 18_damosel: 732 bytes, expected 740; us2:
   18_damosel: 732 bytes, expected 740; pal: absent pal. 732 bytes versus 740. Honest 16-byte text
   buffer, two-color array and scalar settings retained; formatter uses actual varargs. Early
   return/prologue and float layout scheduling remain. Reopen with a matching HUD call/lifetime
   witness. No linked build or functional execution run. */

/* Historical screening below; superseded by the measured C reconstruction. */
/* func_L18_00426AB0 - 740 bytes, 3 place(s), level 18_damosel, retail at
   0x00426ab0. Screened with tools/w10_screen.py: 14 call(s)
   [func_00336D50@00426AFC, func_00300A00@00426B54, func_00336D50@00426B68,
   func_00300A00@00426BBC, func_00283CE0@00426BCC, func_00283CE0@00426BD8,
   func_00283D38@00426BEC, func_00283D38@00426C00, func_0027EAE8@00426C60,
   func_0027EAE8@00426CA8, 0x115da8@00426CF8, func_L18_003044B8@00426D24,
   func_L18_003044B8@00426D50, func_L18_003044B8@00426D6C]; data addresses
   materialised [0x190000, 0x1a0000, 0x60440000, 0x1a0000, 0x55f00000,
   0x1a0000, 0xff0000, 0xff0000, 0x1b0000, 0x3f750000, 0x3f850000]; float
   constants [0x1b0000, 0x3f800000, 0x1b0000]; $gp-relative small data: no
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [COP1 46806320@0x008c, COP1 46806B60@0x009c, COP1 46806B60@0x00f4, COP1
   46806320@0x0104, COP1 46800860@0x0164, COP1 46800020@0x0198, COP1
   46000064@0x01a8, COP1 46800860@0x01c0, COP1 46800020@0x01e4, COP1
   46000064@0x01f0]. Head: addiu $sp, $sp, -0x50 ; lui $v0, 0x19 ; sd $s1,
   0x28($sp) ; addiu $a0, $zero, 0x4 ; sd $s0, 0x20($sp) ; addiu $s1, $v0,
   -0x61E0. Not matched in this wave: the float code has to come out of the
   same expression tree to keep the FPU registers. What would unblock it:
   the exact source expression tree, so this cc1 picks the same registers in
   the same order. */

#include "common.h"
extern u8 *D_L18_001A904C NOT_SDA;
extern u8 *D_0018C0B0 NOT_SDA;
extern u8 D_0018C0D4 NOT_SDA;
extern s32 D_001A7340 NOT_SDA;
extern u32 D_L18_001B12C4 __attribute__((sda)), D_L18_001B12C8 __attribute__((sda));
extern u32 D_L18_001B12CC __attribute__((sda)), D_L18_001B12D0 __attribute__((sda));
extern s32 D_L18_001B12D4 __attribute__((sda)), D_L18_001B12D8 __attribute__((sda));
extern s32 D_L18_001B12DC __attribute__((sda)), D_L18_001B12E0 __attribute__((sda));
extern s32 D_L18_001B12E4 __attribute__((sda)), D_L18_001B12E8 __attribute__((sda));
extern char D_L18_001B1300[];
extern s32 func_00336D50(u8 *, s32);
extern void func_00300A00(char *, s32, float, float, float, float, float);
extern float func_00283CE0(s32);
extern s32 func_00283D38(s32, s32, float);
extern void func_0027EAE8(s32, s32, s32, s32, s32, void *);
extern s32 func_00115DA8(char *, char *, ...);
extern void func_L18_003044B8(s32, s32, u32, char *, s32, float);
s32 func_L18_00426AB0(void)
{
    u32 colors[2];
    char text[16];
    u8 *state;
    s32 middle;
    float ratio;
    float amount;
    s32 handle;
    u16 remaining;
    if (D_0018C0D4 != 4 || !D_L18_001A904C) return 0;
    handle = func_00336D50(D_L18_001A904C + 0x8710, 0xDB);
    func_00300A00((char *)handle, 0x60442D00, (float)(D_001A7340 / 2), (float)(D_L18_001B12D8 + D_L18_001B12E8), 1.0f, 1.0f, 0.0f);
    handle = func_00336D50(D_L18_001A904C + 0x8710, 0xDC);
    func_00300A00((char *)handle, 0x55F0C070, (float)(D_001A7340 / 2), (float)(D_L18_001B12D8 + D_L18_001B12E8), 1.0f, 1.0f, 0.0f);
    state = *(u8 **)(D_0018C0B0 + 0x68);
    amount = func_00283CE0(*(s16 *)(state + 0x3BC));
    ratio = amount / func_00283CE0(*(s16 *)(state + 0x3BE));
    colors[0] = func_00283D38(D_L18_001B12C4, D_L18_001B12CC, ratio);
    colors[1] = func_00283D38(D_L18_001B12C8, D_L18_001B12D0, ratio);
    middle = D_001A7340 / 2;
    func_0027EAE8(middle + D_L18_001B12D4, D_L18_001B12D8,
                  (s32)((float)(middle + D_L18_001B12D4) + (float)D_L18_001B12DC * ratio),
                  D_L18_001B12D8 + D_L18_001B12E0, 0xFFFFF1, colors);
    func_0027EAE8(middle - D_L18_001B12D4, D_L18_001B12D8,
                  (s32)((float)(middle - D_L18_001B12D4) - (float)D_L18_001B12DC * ratio),
                  D_L18_001B12D8 + D_L18_001B12E0, 0xFFFFF1, colors);
    remaining = *(u16 *)(state + 0x3BC);
    if ((u32)(remaining - 32) > 268 || (remaining & 24)) {
        func_00115DA8(text, D_L18_001B1300, (s16)remaining / 60);
        func_L18_003044B8(middle, D_L18_001B12E4 + 1, 0xFF000000, text, 3, 0.96f);
        func_L18_003044B8(middle, D_L18_001B12E4 - 1, 0xFF000000, text, 3, 1.04f);
        func_L18_003044B8(middle, D_L18_001B12E4, colors[0], text, 3, 1.0f);
    }
    return 1;
}
