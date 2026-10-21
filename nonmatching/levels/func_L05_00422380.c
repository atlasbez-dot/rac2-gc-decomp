/* func_L05_00422380, 324 bytes, 1 placement (level 05).  Candidate is 304 bytes.
   The body is recovered: the +0x20 test, the 0xFF byte at +0x30, the
   func_00379860 test, func_L05_004224C8, the two branches on the word at
   +0x264 of the owner, the func_00379E60/func_0037B538 pair, the
   func_003062A0 test on the owner's +0x26C, the func_0037B3A0 result, the
   bounded walk over the D_L05_001FB220 list (the id list word masked with
   0x7FFF, the count from func_00332AF8), the D_001B251C base scaled by the
   index and the 0x78 the owner stores at +0x26C.
   The residue is the allocation of the target pointer: retail keeps it in the
   callee-saved $s2 and still carries its zero initialisation
   (`daddu $s2,$zero,$zero` in the delay slot of the func_0037B3A0 call), so
   the pointer is live across the func_00332AF8 call; this cc1 removes the
   zeroing as a dead store and keeps the pointer in $a0 (20 bytes short).
   Guarding the assignment on the index (the shape that does keep the
   initialisation alive and allocates $s2) reproduces retail's allocation but
   adds a branch retail does not have.  The loop's exit branch and the
   register numbers of the counter and the index also differ.  */

#include "include_asm.h"

typedef signed int s32;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern s32 func_00379860(u8 *a0);
extern void func_00379E60(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_0037B538(u8 *a0, s32 a1, s32 a2, s32 a3);
extern s32 func_0037B3A0(u8 *a0);
extern s32 func_003062A0(u8 *a0);
extern s32 func_00332AF8(s32 a0, s32 a1);
extern void func_L05_004224C8(u8 *a0);
extern void func_L05_00422540(u8 *a0);
extern u8 *D_001B251C;
extern u32 D_L05_001FB220[];

void func_L05_00422380(u8 *arg0)
{
    u8 *s1 = *(u8 **)(arg0 + 0x68);
    u8 *target;
    s32 n;

    if (arg0[0x20] == 0) {
        arg0[0x30] = 0xFF;
        if (func_00379860(arg0) == 0)
            return;
        func_L05_004224C8(arg0);
        if (*(s32 *)(s1 + 0x264) == 0)
            return;
        func_00379E60(arg0, 0, 0, 0);
        return;
    }

    func_0037B538(arg0, 0, 1, 1);
    if (*(s32 *)(s1 + 0x264) == 0)
        return;
    if (func_003062A0(s1 + 0x26C) == 0)
        return;
    n = func_0037B3A0(arg0);

    if (n < 2) {
        target = arg0;
    } else {
        u32 count = func_00332AF8(0, n - 1);
        u16 *p = (u16 *)D_L05_001FB220[arg0[0x21]];
        s32 idx;
        s32 i = 0;

        for (;;) {
            u16 v = *p;

            idx = v & 0x7FFF;
            if (i == count)
                break;
            i++;
            p++;
            if ((s16)v < 0)
                break;
        }
        target = (u8 *)D_001B251C + (idx << 8);
    }
    if (target != 0)
        func_L05_00422540(target);
    *(s32 *)(s1 + 0x26C) = 0x78;
}
