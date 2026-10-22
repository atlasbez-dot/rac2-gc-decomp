/* Near miss (228 bytes, level 16): 2 words per block differ, in the order of the
   argument setup of the call to func_L16_00414038.

   The body matches retail word for word up to +0x50: the frame, the three saved
   registers ($s0 the random count, $s1 the handle, $s2 the handle + 0x10), the
   $f20/$f21 saves, the two calls to func_002A7820 and func_002A7940, the two
   "speed * 120" products and the 1.0f.  What differs is where the reload phase
   puts the two argument copies: retail sets $f12 (the speed) before $a2 (the
   count), this cc1 sets $a2 first, so the two words trade places in both blocks.

   The register allocation is right only with the speed in a block-local variable
   (one quantity per block): naming it in the function scope makes the count and
   the speed one quantity each, and the prologue then saves $s1 before $s0.
   Tried: the speed inline (the prologue's save order changes), the speed named
   and the count named (same), the count inline and the speed named (the closest
   form, kept here), the 1.0f as a variable and as a literal (no change), the
   speed computed before or after the count's call (no change).

   Kept as a starting point.  Removed from src/ on 2026-10-21. */

extern void func_L16_00414038(void *, s32, s32, s32, float, float, float, s32, void *);
extern s32 func_002A7820(s32, s32);
extern float func_002A7940(void);

extern s32 D_L16_001B1908 __attribute__((sda));
extern s32 D_L16_001B190C __attribute__((sda));
extern s32 D_L16_001B1940 __attribute__((sda));
extern s32 D_L16_001B1944 __attribute__((sda));
extern float D_L16_001B1948 __attribute__((sda));
extern float D_L16_001B194C __attribute__((sda));

void func_L16_00413EC8(u8 *arg)
{
    u8 *p;
    u8 *q;

    p = arg;
    q = p + 0x10;
    {
        float speed = D_L16_001B1948 * *(float *)(p + 0x2C);
        func_L16_00414038(q, D_L16_001B1908, func_002A7820(0x5F, 0x6F), D_L16_001B1940,
                          speed, func_002A7940(), 1.0f, 2, p);
    }
    {
        float speed = D_L16_001B1948 * *(float *)(p + 0x2C) * D_L16_001B194C;
        func_L16_00414038(q, D_L16_001B190C, func_002A7820(0x6F, 0x7F), D_L16_001B1944,
                          speed, func_002A7940(), 1.0f, 2, p);
    }
}
