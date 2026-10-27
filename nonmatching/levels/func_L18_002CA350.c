/* func_L18_002CA350: near miss, 432 B vs 436. A fresh pointer variable assigned from D_00189E20 in every mode block reproduces retail's shared lui in $s0 (and the first pointer in $s2). Left: retail has one dead "lw $v0,0x340($s2)" right after the 0x22BD test (a branch that was folded away, which also ends the extended basic block so the mode==2 block recomputes the hero address instead of reusing $s2) and uses $v0 for the D_L18_001A7B0B flag byte. Build as part of L18_002C2D48.c (default flags). */
#include "common.h"

typedef unsigned char u8;
typedef short s16;
extern char D_00189E20[];

extern void func_00282A88(void *, int);
extern u8 D_L18_001A7B0B;

/* Re-initialises the 16-byte block at 0x1490 and then, from the saved mode in it, raises the matching flags. */
void func_L18_002CA350(void)
{
    char *p = D_00189E20;
    s16 mode = *(s16 *)(p + 0x1490);
    u8 keep = *(u8 *)(p + 0x149D);
    char *h;
    func_00282A88(p + 0x1490, 16);
    *(u8 *)(p + 0x149D) = keep;
    *(s16 *)(p + 0x1490) = mode;
    *(u8 *)(p + 0x22B9) = 0;
    *(s16 *)(p + 0x348) = 0;
    if (*(u8 *)(p + 0x22BD) == 0 && mode != -1) {
        if (mode == 2) {
            h = D_00189E20;
            if (*(s16 *)(h + 0x1DE) == 0 && (*(s16 *)(h + 0x34C) == 0 || *(float *)(h + 0x31C) < 2.5f)) {
                *(u8 *)(h + 0x1497) = 1;
                if (*(u8 *)(h + 0x22B4) == 0 && D_L18_001A7B0B != 0)
                    *(s16 *)(h + 0x348) = 1;
            }
        }
        if (mode == 0xE) {
            h = D_00189E20;
            *(u8 *)(h + 0x1494) = 1;
            *(float *)(h + 0x24C4) = 0.2f;
            *(float *)(h + 0x330) = *(float *)(h + 0x318) + 0.2f;
        }
        if (mode == 0) {
            float d;
            h = D_00189E20;
            d = *(float *)(h + 0x330) - *(float *)(h + 0x318);
            *(float *)(h + 0x24C4) = d;
            if (d < 0.85f && d > 0.25f)
                *(u8 *)(h + 0x22B9) = 1;
            h = D_00189E20;
            *(u8 *)(h + 0x1494) = 1;
        }
        if (mode == 7) {
            h = D_00189E20;
            *(u8 *)(h + 0x1492) = 1;
        }
        if (mode == 8) {
            h = D_00189E20;
            *(u8 *)(h + 0x149A) = 1;
        }
        if (mode == 0xC) {
            h = D_00189E20;
            *(u8 *)(h + 0x149A) = 1;
        }
    }
}
