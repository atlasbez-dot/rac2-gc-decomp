/* Near miss (M36, 26 October 2026): 628/632 bytes at -O2 -G0 -ffunction-sections, 3 places
   (us 18/19/20, us2 the same, pal absent). The stop call is written inline as the then-arm of the
   0033B628 test (goto stop from the two earlier exits), which fixes every branch and tail.
   Only difference: retail re-zero-extends object[0x20] (andi v0,v1,0xFF) before the sltiu 6 of
   the ">= 6" test, though the value comes from the lbu in the preceding bnez slot. A u8/int local,
   (u8) casts and "> 5" were neutral. Reopen with a source form whose value has unknown high bits
   at that test. */
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
    if (object[0x20] >= 6 && *(s32 *)(state + 0x260) != -1 && !func_L18_0033B628((s32)(object + 0x10), *(s32 *)(state + 0x260), 0)) {
stop:
        func_L18_003F74B8(object, 0);
        return;
    }
    *(s32 *)(state + 0x248) = func_002B3BA8(object, *(s32 *)(state + 0x240), 0, 0, *(float *)(state + 0x244), 0.0f);
    if (*(u8 **)(state + 0x258)) func_L18_003F8E30(*(u8 **)(state + 0x258));
    if (D_0018C0B4 == 0x6F && (u32)(object[0x20] - 9) < 4) func_002A7750(object, 6, -1);
}
