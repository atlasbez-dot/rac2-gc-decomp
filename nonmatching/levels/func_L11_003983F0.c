/* 0 of 1 places match - last line: 11_joba: 276 bytes, expected 280
   G8: the body reads its counters through $gp, so it needs the
   src/levels/11_joba/L11_002DE9E0-g8.c unit (-G8).
   The body is recovered: the object's mode byte at +0x20 selects the first
   mode, which arms the level's effect once (D_001A7A72, func_002E5E58,
   func_002B0A18 and D_L11_001A903C) when D_L11_001B30C8 is at least 6,
   D_L11_001AED04 is clear, D_L11_001AED00 is set and D_001A7A72 is clear;
   the second mode clears the object's byte at +0x30 and D_L11_001AED08 and
   re-arms the object; the shared tail then re-arms the effect through
   D_001A7A74.  The first eight words (the mode test, the else branch and the
   object's re-arm) match.  Four differences are left in the first mode's
   tests: retail merges the two "< 12" tests (on D_L11_001AED04 and on the byte
   D_001A7A72) into one shared block while this cc1 computes each one in its
   branch's delay slot, retail tests D_L11_001AED00 == 0 with `beqz $v1` while
   this cc1 tests it with `bnez`, retail's delay slot of that branch holds a
   dead `slti` of D_L11_001AED08, and retail loads D_L11_001AED00 before
   D_L11_001AED04 while this cc1 loads them the other way round.  The `< 12`
   test of the byte needs an int temporary: a u8 compares with sltu here.
   The source's shape (the "if (mode != 1)" test first, the else branch
   inline) is what puts retail's branch-likely `beql` and its `bnez` in place. */

#include "common.h"

extern void func_002A7750(u8 *a0, u8 a1, s32 a2);

extern int func_002E5E58(int a0, unsigned int a1, void *a2);

extern void func_002B0A18(int a0, int a1);

extern s32 D_L11_001B30C8;

extern s32 D_L11_001AED00 __attribute__((sda));

extern s32 D_L11_001AED04 __attribute__((sda));

extern s32 D_L11_001AED08 __attribute__((sda));

extern s32 D_L11_001A903C;

extern u8 D_001A7A72;

extern u8 D_001A7A74;

void func_L11_003983F0(u8 *arg0) {
    u8 *v1 = arg0;
    int s0 = v1[0x20];

    if (s0 != 1) {
        if (s0 < 2) {
            if (s0 == 0) {
                v1[0x30] = 0xFF;
                D_L11_001AED08 = 0;
                func_002A7750(v1, 1, -1);
            }
        }
        return;
    }
    if (D_L11_001B30C8 < 6) {
        if (D_L11_001AED08 < 12)
            return;
    } else if (D_L11_001AED04 != 0) {
        if (D_L11_001AED04 < 12)
            return;
    } else if (D_L11_001AED00 == 0) {
        if (D_L11_001AED08 != 0)
            return;
    } else {
        int c = D_001A7A72;

        if (c != 0) {
            if (c < 12)
                return;
        } else {
            D_001A7A72 = 1;
            func_002E5E58(1, 0, 0);
            func_002B0A18(0x1233, -1);
            D_L11_001A903C = 1;
            if (D_L11_001AED08 < 12)
                return;
        }
    }
    if (D_001A7A74 != 0)
        return;
    D_001A7A74 = 1;
    func_002E5E58(1, 0, 0);
    func_002B0A18(0x1233, -1);
    D_L11_001A903C = 1;
}
