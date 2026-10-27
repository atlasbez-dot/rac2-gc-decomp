/* Complete reconstruction; not linked. Profile: -O2 -G8 -ffunction-sections.
 * 26 October 2026 (M10): 496/508 bytes. D_L00_001A8F00 is a plain sized scalar (retail:  in
 * the delay slot, lui/lw elsewhere); the hero tail goes through the Hero union view (retail's
 * la + offset forms); the idle scan is a counted for loop (retail's blez entry test with found = 0
 * in the slot). Left: retail reads the 0x44 count twice, from two callee-saved copies of the table
 * address ( test,  loop: likely two hoisted invariants), keeps only 2 in , and the
 * prologue order follows from that. The earlier do/while form was 504 bytes.
 */
#include "common.h"
typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union { u8 b[0x2600]; s16 h[0x1300]; s32 i[0x980]; u32 u[0x980]; f32 f[0x980]; u8 *ptr[0x980]; TI128 q[0x260]; } Hero;
#define H ((Hero *)D_00189E20)

extern u8 D_00189E20[];
extern u8 D_00152C00[];
extern u8 D_L00_001BCAC0[];
extern s32 D_L00_001A8F00;
extern s32 func_L00_002D6418(void);

void func_L00_002D2E68(void)
{
    u8 *base;
    u8 *guard;
    u8 *table;
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
        if (mode == 2) {
            found = 0;
            for (count = 0; count < *(s16 *)(table + 0x44); count++) {
                if (*(s16 *)(((u8 **)(table + 0x18C))[count] + 0xAA) == 0)
                    found = 1;
            }
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
    obj = H->ptr[0x131C / 4];
    if (obj) *(u16 *)(obj + 0x34) |= 1;
    if (H->b[0x22B4] == 1) {
        obj = H->ptr[0x1864 / 4];
        if (obj) *(u16 *)(obj + 0x34) |= 1;
    }
    if (H->i[0x1248 / 4] == 10) {
        obj = H->ptr[0x1220 / 4];
        if (obj && D_L00_001A8F00 == 0 && obj[0x20])
            *(u16 *)(obj + 0x34) &= ~0x41;
    }
}
