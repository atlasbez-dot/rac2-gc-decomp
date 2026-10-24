/* Nonmatching: -O2 -G0 -ffunction-sections. us: func_L00_0039B288: 0 of 27 places match (src/levels/shared/L00_0039B288.c); us2: func_L00_0039B288: 0 of 27 places match (src/levels/shared/L00_0039B288.c); pal: absent. Three source forms: if/else then switch and explicit RGB channels. Best 448/440 bytes, original frame0x30. Initial state dispatch and fifth-power factor reconstructed; remaining interpolation-call scheduling and extra return-color copy/channel extraction allocation. API banks and integer abs/helper bodies inspected directly. Reopen with natural color value lifetime hypothesis; no linked builds. */
#include "common.h"
extern float D_L00_001B19D0 MACRO_ADDR;
extern float D_L00_001B8FF0[4];
extern int func_00273B70(void *);
extern s32 func_002A77E0(s32);
extern void func_002A7750(u8 *, u8, s32);
extern void func_0029F338(void *);
extern float func_00282DB0(void *, void *);
extern float func_00282C48(float);
extern int func_00282C30(int);
extern int func_00283D38(int, int, float);
extern void func_002A0488(void *, int, int, int);
/* Fades a dying actor and modulates its color with orientation and short random pulses. */
void func_L00_0039B288(char *actor) {
    char *state = *(char **)(actor + 0x68);
    float factor;
    int color, red, green, blue;
    switch (*(unsigned char *)(actor + 0x20)) {
    case 0:
        if (func_00273B70(actor) || (D_L00_001B19D0 > 0.8f && func_002A77E0(10) == 0)) {
            func_002A7750((u8 *)actor, 1, -1);
            *(unsigned short *)(actor + 0x34) |= 0x2800;
        }
        break;
    case 1:
        func_00273B70(actor);
        if (*(unsigned char *)(actor + 0x23) < 2) { func_0029F338(actor); return; }
        *(unsigned char *)(actor + 0x23) -= 2;
        break;
    }
    factor = func_00282C48(func_00282DB0(actor + 0xC0, D_L00_001B8FF0));
    factor *= factor * factor * factor * factor;
    if (*(unsigned short *)(actor + 0x96)) {
        int amount = 10 - func_00282C30(*(unsigned short *)(actor + 0x96) - 10);
        *(unsigned short *)(actor + 0x96) -= 1;
        factor = (float)amount * 0.1f;
    } else if (func_002A77E0(45) == 0) *(unsigned short *)(actor + 0x96) = 20;
    color = *(int *)(state + 0x50);
    if ((u32)color >> 24) factor *= 0.8f;
    color = func_00283D38(color, -1, factor);
    blue = (color >> 16) & 0xFF;
    green = (color >> 8) & 0xFF;
    red = color & 0xFF;
    func_002A0488(actor, red, green, blue);
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_0039B288 - 440 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x0039b288. Screened with tools/w10_screen.py: 11 call(s)
   [func_00273B70@0039B2C0, func_002A77E0@0039B2F8, func_002A7750@0039B310,
   func_00273B70@0039B328, func_0029F338@0039B340, func_00282DB0@0039B35C,
   func_00282C48@0039B364, func_00282C30@0039B38C, func_002A77E0@0039B3C8,
   func_00283D38@0039B404, func_002A0488@0039B420]; data addresses
   materialised [0x1c0000, 0x1b0000, 0x3f4c0000, 0x1c0000, 0x1c0000,
   0x1c0000, 0x3dcc0000, 0x3f4c0000]; float constants [-]; $gp-relative
   small data: no   saves: -; callee-saved registers saved [-]; words plain
   C cannot emit [COP1 46800020@0x012c]. Head: addiu $sp, $sp, -0x30 ; sd
   $s0, 0x0($sp) ; sd $s1, 0x8($sp) ; daddu $s0, $a0, $zero ; sd $ra,
   0x10($sp) ; swc1 $f20, 0x20($sp). Not matched in this wave: the float
   code has to come out of the same expression tree to keep the FPU
   registers. What would unblock it: the exact source expression tree, so
   this cc1 picks the same registers in the same order. */
