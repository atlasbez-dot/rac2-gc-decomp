/* Default profile with sda on the first resident guard: 160/160 bytes, first mismatch +0x28, 0/27 each. The GP word at -0x60F0 is D_L00_001A8F00, not D_00189E20; all resident names below LEVEL_BASE are corrected. A shared rejection label recovers the retail block order. Allocation, absolute/GP addressing and sharing the high address half remain different.
 * Profile: -O2 -G0 -ffunction-sections
 * us: instruction at +0x28 differs
 * pal: instruction at +0x28 differs
 * us2: instruction at +0x28 differs
 */
#include "include_asm.h"
typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern s32 D_001A7908 __attribute__((sda));
extern s32 D_L00_001B8E10;
extern s16 D_00190086;
extern s32 D_L00_001A8F00 __attribute__((sda));
extern u8 D_00189E20[];

s32 func_L00_002D6418(void)
{
    s32 v;
    if (D_001A7908 == 0) goto deny;
    v = D_L00_001A8F00;
    if (v == 2 || v == 6) goto deny;
    if (D_L00_001B8E10 != 0) {
        if (D_00190086 == 5) {
 deny:
            return 0;
        }
    }
    {
        u8 *blk = D_00189E20;
        if (blk[0x22B4] != 0) goto deny;
        if (*(s32 *)(blk + 0x229C) == 0x14) goto deny;
        if (*(s32 *)(blk + 0x24CC) == 0) goto deny;
        v = *(s32 *)(blk + 0x2294);
        if (v == 0x6F || v == 0x31 || v == 0x1C || v == 0x8C) goto deny;
        return 1;
    }
}
