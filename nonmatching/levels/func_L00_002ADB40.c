/* func_L00_002ADB40: near miss (about 8 instructions off). Built as its own unit with -O2 -G0 -ffunction-sections -frac2-qcopy; the hero pointer is re-read from D_00189E20 after the call and the first probe base is D_00189EA0 - 0x80, as in retail, and the single-struct frame (q10, q20, a, b, c, d) gives retail's stack layout. Left: retail loads the D_L00_001A7B0C flag byte with "lui $v0; lbu $v0,off($v0)" (one register) while still sharing the hero high half in $s1; -mno-split-addresses gives the first but not the second. */
#include "common.h"

extern char D_00189E20[];
extern char D_00189EA0[];
extern u8 D_L00_001A7B0C[];
extern s32 func_L00_002AD868(void *, void *, void *, void *, void *, void *, void *, s32, s32);

/* Aims the hero's probe: when the hero is in the right state and the ray from its position hits something close enough, records the hit point. */
void func_L00_002ADB40(void)
{
    struct { float q10[4]; float q20[4]; s32 a; s32 b; float c; s32 d; } fr __attribute__((aligned(16)));
    char *h;
    char *b;
    char *h2;
    s32 m;
    float gap;

    if (D_L00_001A7B0C[0] != 0) {
        h = D_00189E20;
        *(s32 *)(h + 0x63C) = 0;
        if (*(short *)(h + 0x1F4) == 0) {
            m = *(s32 *)(h + 0x229C);
            if (m == 2 || m == 0 || m == 1 || m == 6)
                goto call;
            m = *(s32 *)(h + 0x2294);
            if (m == 1)
                goto call;
            if ((unsigned)(m - 0x28) < 2 && (*(s32 *)(h + 0x640) != 0 || *(s32 *)(h + 0x694) != 0))
                goto call;
            if (*(s32 *)(h + 0x229C) == 4 && (*(u8 *)(h + 0x49E) != 0 || *(short *)(h + 0x1F6) != 0))
                goto call;
            return;
call:
            qcopy(fr.q20, D_00189EA0);
            if (func_L00_002AD868(fr.q20, &fr.a, fr.q10, &fr.b, &fr.c, &fr.d, 0, 0, 0) != 0) {
                b = D_00189EA0 - 0x80;
                if (*(s32 *)(b + 0x2294) == 0x28 && *(s32 *)(b + 0x694) != 0 && fr.a == *(s32 *)(b + 0x630))
                    return;
                h2 = D_00189E20;
                gap = *(float *)(h2 + 0x88) - fr.q10[2];
                if (gap > -0.5f && (gap < 0.57f || *(short *)(h2 + 0x1F6) != 0)) {
                    qcopy(h2 + 0x5D0, fr.q10);
                    *(s32 *)(h2 + 0x63C) = 1;
                    *(s32 *)(h2 + 0x630) = fr.a;
                    *(s32 *)(h2 + 0x634) = fr.b;
                    *(float *)(h2 + 0x638) = fr.c;
                    *(s32 *)(h2 + 0x654) = fr.d;
                }
            }
        }
    }
}
