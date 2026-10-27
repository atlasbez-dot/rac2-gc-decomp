/* Carried from rac3-decomp (src/levels/shared/L01_004453B8.c, func_L01_00445D30): the
   same instructions. Steps the cursor D_001B1D38 through the record list of START's group
   (D_001EE5A0[start[0x21]]) to the next record that fits A2/A3 (the sign of byte 0x20 of
   the 256-byte record at D_001B1B5C), putting it in *OUT: 0 when found, -1 at the list's
   end. The records reached are kept in D_001B1D40 and their index in D_001B1D3C.
   Near miss (26 October 2026, xcarry): 348 of 356 bytes. Retail stores the cursor
   (D_001B1D38 = p + 1) before it reads p[1], and reads p[1] again (lh) for the sign test after
   storing the index and record; cc1 hoists the read above the cursor store and reuses it
   (sll 16 / bltz). The rac3 compiler keeps the source order. */

#include "common.h"

extern u8 *D_001B1D40 MACRO_ADDR;
extern s32 D_001B1B78 MACRO_ADDR;
extern s16 *D_001B1D38 MACRO_ADDR;
extern s16 *D_001EE5A0[];
extern u8 *D_001B1B5C MACRO_ADDR;
extern u16 D_001B1D3C MACRO_ADDR;

s32 func_002A86E8(u8 **out, u8 *start, s32 a2, s32 a3) {
    s16 *p;
    s32 neg;
    s32 idx;
    *out = 0;
    if (start != D_001B1D40) {
        if (D_001B1B78 < start[33]) {
            goto fail;
        }
        D_001B1D40 = 0;
        D_001B1D38 = D_001EE5A0[start[33]];
        if (D_001B1D38 == 0) {
        fail:
            return -1;
        }
        D_001B1D38 = D_001B1D38 - 1;
        do {
            p = D_001B1D38;
            D_001B1D38 = p + 1;
            idx = p[1] & 0x7FFF;
            D_001B1D3C = idx;
            D_001B1D40 = D_001B1B5C + (idx << 8);
            if (p[1] < 0) {
                goto fail;
            }
        } while (start != D_001B1D40);
    } else if (*D_001B1D38 < 0) {
        goto fail;
    }
    do {
        p = D_001B1D38;
        D_001B1D38 = p + 1;
        idx = p[1] & 0x7FFF;
        D_001B1D3C = idx;
        D_001B1D40 = D_001B1B5C + (idx << 8);
        *out = D_001B1D40;
        neg = (s8)D_001B1D40[32] < 0;
        if (!a2) {
            if (a3) {
                continue;
            }
            if (!neg) {
                goto ret0;
            }
        } else if (!a3 || neg) {
        ret0:
            return 0;
        }
    } while (*D_001B1D38 >= 0);
    *out = 0;
    return -1;
}
