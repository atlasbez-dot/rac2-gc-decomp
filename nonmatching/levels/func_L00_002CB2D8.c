/* Game -O2 -G8, with nosda on the absolute resident words: see per-release measurements below, 0/27 in us/us2; absent PAL catalogue. The merge input D_001A7398 now uses GP addressing. Absolute high-half reuse, branch/load scheduling and flag expression allocation still differ; no compiler impossibility is established.
 * Profile: -O2 -G8 -ffunction-sections
 * us: 196 bytes, expected 204
 * us2: 196 bytes, expected 204
 */
#include "common.h"

extern char D_00189E20_36[];
extern char D_0018C750[];
extern int D_001A7A04 __attribute__((nosda));
extern int D_001A7390 __attribute__((nosda));
extern int D_001A79F0 __attribute__((nosda));
extern int D_001A7390_1 __attribute__((sda));
extern int D_001A7398 __attribute__((sda));
extern int func_L00_002D3FB0(int);

void func_L00_002CB2D8(void)
{
    char *s0 = D_00189E20_36;
    char *a3;
    int ac, r, t, g;
    u16 c;

    if (*(int *)(s0 + 0x2538) == 0)
        return;
    g = D_001A7398;
    ac = *(int *)(s0 + 0x1248);
    r = D_001A7A04;
    if (ac == 10)
        r = g;
    *(int *)(s0 + 0x2538) = 0;
    if (r == 0)
        return;
    if (ac == D_001A7A04)
        return;
    a3 = D_0018C750;
    c = *(u16 *)(a3 + 0x174);
    if (c > 0xFFFE)
        t = D_001A7390_1;
    else {
        *(u16 *)(a3 + 0x174) = c + 1;
        t = D_001A7390;
    }
    if (*(u32 *)(a3 + 0x178) < (u32)t)
        *(int *)(a3 + 0x178) = t;
    t = *(int *)(a3 + 0x17C) | (1 << D_001A79F0);
    *(int *)(a3 + 0x17C) = t | 0x80000000;
    *(int *)(s0 + 0x22C8) = func_L00_002D3FB0(r);
    *(short *)(s0 + 0x24FA) = 0;
    *(short *)(s0 + 0x24F8) = 0;
}
