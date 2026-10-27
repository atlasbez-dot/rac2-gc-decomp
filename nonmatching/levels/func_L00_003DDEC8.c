/* func_L00_003DDEC8: near miss. Same calls and constants; retail loads 454.0f straight into $f12 at each call and holds 380.0f in $f24, while this build also hoists 454.0f and 372.0f into saved float registers; retail also saves an unused $s0 (the 0x8710 offset sits in $s1). Own unit: -O2 -G8 -ffunction-sections -mno-split-addresses. */
#include "common.h"

extern s32 D_001B043C __attribute__((sda));
extern s32 D_001A904C;
extern f32 D_001B2704;
extern s32 D_001B2B40;
extern char D_001B0450[];

extern void func_00300A00(s32, s32, f32, f32, f32, f32, f32);
extern s32 func_00336D50(s32, s32);
extern void func_002ED578(s32, s32 *, s32 *, s32 *);
extern void func_00115DA8(void *, char *, s32, s32, s32);
extern s32 func_00283CF0(f32);
extern void func_0027F5B8(s32, s32, u64, void *, s32);

/* Draws the two coloured bars of the overlay at the screen scale and, below them, the text block. */
s32 func_L00_003DDEC8(void)
{
    s32 a, b, c;
    char buffer[0x40];

    if (D_001B043C != 0) {
        func_00300A00(func_00336D50(D_001A904C + 0x8710, 0xC1), 0x60442D00, (f32)454, (f32)(s32)(D_001B2704 * 380.0f + 0.5f), -0.5f, 1.0f, 0.0f);
        func_00300A00(func_00336D50(D_001A904C + 0x8710, 0xC2), 0x55F0C070, (f32)454, (f32)(s32)(D_001B2704 * 380.0f + 0.5f), -0.5f, 1.0f, 0.0f);
        func_002ED578(D_001B2B40, &a, &b, &c);
        func_00115DA8(buffer, D_001B0450, a, b, c);
        func_0027F5B8(func_00283CF0(405.0f), (s32)(D_001B2704 * 372.0f + 0.5f), 0x80808080, buffer, 0x80);
    }
    return 1;
}
