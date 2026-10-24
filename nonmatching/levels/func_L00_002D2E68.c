/* US, US2 and PAL, game -O2/-G8: 516 bytes versus 508; 0/27 placements
   in each release. Reconstructed from verified retail assembly. The initial
   shared-base form was 492 bytes; direct canonical resident references at the
   tail produced this 516-byte form. -mno-split-addresses did not change its size.
   Remaining differences include saved-register allocation, the repeated table
   count load, and mixed GP/absolute accesses to the same mode word. This attempt
   preserves one data identity; the historical suggestion below to introduce an
   absolute alias is not an allowed remedy. Reopen with a measured single-symbol
   mixed-addressing and lifetime idiom. No linked build or functional test run. */

/* Historical screening, superseded by the measured C attempt above. */
/* Not attempted - body read in full, no C written: a loop over seven slots, 508 bytes,
   27 places.

   The body: the state block's first object gets its halfword flag 0x34 set; the call
   to func_L00_002D6418 runs only on the first turn of the loop; the word at
   $gp-0x60F0 (0x001A8F00, the same word the `lui`/`addiu` pair loads a few words
   later) decides the branch; the two guards on the shorts at 0x001BCAC0+0x44 and at
   0x00152C00+0x20 pick the path; a walk over the table at 0x001BCAC0+0x18C keeps the
   last entry's flag with a `movz`; and the three pointers at the base of the state
   (+0x1220, +0x1224, +0x1228) each get their halfword flag 0x34 set when they are
   not null.

   The word at +0xF8 was rechecked during integration: it has rs=$s0, rt=$v0 and
   rd=$v1. R5900 mult supports a GPR destination, also described by the qualified
   GNU opcode table's `d,s,t` form with WR_d. Thus the following use of $v1 does not
   require mfhi/mflo and does not prove an unmatchable high-half multiply. The
   earlier two-operand disassembly omitted rd. No C candidate has been tested
   here, and this record does not establish a compiler limitation.
   The loop's other shapes (the `bnel`/`bnez`
   chain, the `sltiu` range test on the count, the `movz` of the walk) are ordinary
   C, and the word at $gp-0x60F0 needs the two-name pattern (an `sda` name for the
   $gp form and an absolute alias for the macro form) in a `-g8` unit. */

#include "common.h"

extern u8 D_00189E20[];
extern u8 D_00152C00[];
extern u8 D_L00_001BCAC0[];
extern s32 D_L00_001A8F00 __attribute__((sda));
extern s32 func_L00_002D6418(void);

void func_L00_002D2E68(void)
{
    u8 *base;
    u8 *table;
    u8 *guard;
    u8 *slot;
    u8 *obj;
    u8 **entries;
    s32 i;
    s32 count;
    s32 found;
    s32 mode;

    base = D_00189E20;
    table = D_L00_001BCAC0;
    guard = D_00152C00;
    obj = *(u8 **)(base + 0xC18);
    *(u16 *)(obj + 0x34) |= 1;
    for (i = 0; i < 7; i++) {
        if (i == 0 && func_L00_002D6418())
            continue;
        mode = D_L00_001A8F00;
        if (mode == 2 && *(s16 *)(table + 0x44) > 0) {
            found = 0;
            count = *(s16 *)(table + 0x44);
            entries = (u8 **)(table + 0x18C);
            do {
                if (*(s16 *)(*entries + 0xAA) == 0)
                    found = 1;
                entries++;
            } while (--count != 0);
            if (found)
                continue;
        }
        if (mode == 6 && (*(s16 *)(guard + 0x20) == 0 || *(s16 *)(guard + 0x20) == 3)
            && (u32)(i - 1) < 2)
            continue;
        slot = base + i * 0x50;
        obj = *(u8 **)(slot + 0x1220);
        if (obj) *(u16 *)(obj + 0x34) |= 1;
        obj = *(u8 **)(slot + 0x1224);
        if (obj) *(u16 *)(obj + 0x34) |= 1;
        obj = *(u8 **)(slot + 0x1228);
        if (obj) *(u16 *)(obj + 0x34) |= 1;
    }
    obj = *(u8 **)(D_00189E20 + 0x131C);
    if (obj) *(u16 *)(obj + 0x34) |= 1;
    if (D_00189E20[0x22B4] == 1) {
        obj = *(u8 **)(D_00189E20 + 0x1864);
        if (obj) *(u16 *)(obj + 0x34) |= 1;
    }
    if (*(s32 *)(D_00189E20 + 0x1248) == 10) {
        obj = *(u8 **)(D_00189E20 + 0x1220);
        if (obj && D_L00_001A8F00 == 0 && obj[0x20])
            *(u16 *)(obj + 0x34) &= ~0x41;
    }
}
