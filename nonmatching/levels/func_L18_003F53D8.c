/* Measured profile: -O2 -G0 -ffunction-sections. us: 18_damosel: 612 bytes, expected 632; us2:
   18_damosel: 612 bytes, expected 632; pal: absent pal. 612 bytes versus 632. Common stop paths,
   collision-state dispatch and address lifetimes differ. All current helper inputs are preserved,
   including the actual companion pointer passed to 003F8E30. Reopen with a matching branch/join source
   form. No linked build or functional execution run. */

/* Historical screening below; superseded by the measured C reconstruction. */
/* func_L18_003F53D8 - 632 bytes, 3 place(s), level 18_damosel, retail at
   0x003f53d8. Screened with tools/w10_screen.py: 12 call(s)
   [func_002A9640@003F53F8, func_002A7750@003F544C, func_002B0ED8@003F5464,
   func_L18_003F7AB8@003F54BC, func_L18_003F74B8@003F551C,
   func_L18_003F74B8@003F5538, func_002A6C58@003F5568,
   func_L18_0033B628@003F55B0, func_L18_003F74B8@003F55C4,
   func_002B3BA8@003F55E8, func_L18_003F8E30@003F55FC,
   func_002A7750@003F5630]; data addresses materialised [0x10000, 0x190000];
   float constants [0x42b40000, 0xbf800000]; $gp-relative small data: no
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [-]. Head: addiu $sp, $sp, -0x20 ; lui $a1, 0x1 ; sd $s0, 0x0($sp) ;
   addiu $a2, $zero, 0x1 ; sd $s2, 0x10($sp) ; daddu $s0, $a0, $zero. Not
   matched in this wave: the body is straight-line code whose register
   allocation and the materialisation of its constant addresses have to be
   reproduced word for word. What would unblock it: the exact source
   expression tree, so this cc1 picks the same registers in the same order. */

#include "common.h"
extern void *func_002A9640(void *, u32, s32);
extern void func_002A7750(u8 *, u8, s32);
extern s32 func_002B0ED8(void *, void *, s32);
extern void func_L18_003F7AB8(u8 *);
extern void func_L18_003F74B8(u8 *, s32);
extern void func_002A6C58(u8 *, s32, s32);
extern s32 func_L18_0033B628(s32, s32, s32);
extern s32 func_002B3BA8(u8 *, s32, void *, s32, float, float);
extern void func_L18_003F8E30(u8 *);
extern s32 D_0018C0B4;
void func_L18_003F53D8(u8 *object)
{
    u8 *state = *(u8 **)(object + 0x68);
    u8 *contact;
    u8 saved;
    contact = func_002A9640(object, 0x10000, 1);
    if (contact && *(u8 **)(contact + 0x20) && *(s16 *)(*(u8 **)(contact + 0x20) + 0xAA) == 0xF9E) {
        if (object[0x20] < 6 || object[0x20] == 19 || object[0x20] == 18) return;
        func_002A7750(object, 18, -1);
        return;
    }
    saved = object[0x94];
    if (func_002B0ED8(object, state + 0x50, 0)) {
        if (object[0x94] == 17 || object[0x94] == 8 || object[0x94] == 9 || object[0x94] == 16 || object[0x94] == 10 || object[0x94] == 7) object[0x94] = saved;
        if (object[0x94] != 14) func_L18_003F7AB8(object);
    }
    object[0xA8] = 255;
    if (*(float *)(object + 0x18) < 90.0f || (*(float *)(state + 0x2A0) != -1.0f && *(float *)(object + 0x18) < *(float *)(state + 0x2A0))) func_L18_003F74B8(object, 0);
    if (state[0x2E] == 2) {
        func_L18_003F74B8(object, 1);
        return;
    }
    contact = *(u8 **)(state + 0x188);
    if (contact && *(s16 *)(contact + 0xAA) == 0xF59) {
        func_002A6C58(object, 0, 1);
        goto stop;
    }
    if (*(s32 *)(state + 0x180) > 300 && object[0x20] != 2) goto stop;
    if (object[0x20] >= 6 && *(s32 *)(state + 0x260) != -1 && !func_L18_0033B628((s32)(object + 0x10), *(s32 *)(state + 0x260), 0)) goto stop;
    *(s32 *)(state + 0x248) = func_002B3BA8(object, *(s32 *)(state + 0x240), 0, 0, *(float *)(state + 0x244), 0.0f);
    if (*(u8 **)(state + 0x258)) func_L18_003F8E30(*(u8 **)(state + 0x258));
    if (D_0018C0B4 == 0x6F && (u32)(object[0x20] - 9) < 4) func_002A7750(object, 6, -1);
    return;
stop:
    func_L18_003F74B8(object, 0);
}
