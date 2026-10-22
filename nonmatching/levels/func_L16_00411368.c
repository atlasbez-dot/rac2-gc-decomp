/* Near miss (276 bytes, level 16): the FPU registers and the constant placement
   differ; every other word matches retail.

   Retail keeps the accumulated rate in $f20 (the only saved FPU register it
   uses) and materialises the 120.0f twice: once into $f12 for the call to
   func_00283CF0 and once into $f0 for the division.  This cc1 merges the two
   literals into one value that lives across the call, so the reload phase puts
   it in a saved register ($f20) and the accumulator lands in $f21 instead.

   The rest of the body matches: the four-way type test that picks 10.0f or
   25.0f, the modulo with the retail divide-by-zero guard (beql + break), the
   2*pi and pi constants, and the call to func_002AA548 with the three measured
   rates.  Tried: the 120.0f as a literal, as a variable, as a variable used
   twice, and as a variable in its own block; the copy propagation folds every
   form back into the single constant, so the two copies of the literal cannot
   be kept apart.

   Kept as a starting point.  Removed from src/ on 2026-10-21. */

extern s32 func_00283CF0(float);
extern float func_00283198(float);
extern void func_002AA548(void *, void *, float, float, float, float);
extern s32 D_L16_001B2648;

void func_L16_00411368(u8 *arg)
{
    u8 *s0;
    u8 *s1;
    float f20;
    float f12;
    s32 v0;

    s0 = arg;
    s1 = *(u8 **)(arg + 0x68);
    f20 = 10.0f;
    if (s0[0x20] == 0xD || s0[0x20] == 0xF || s0[0x20] == 0xE || s0[0x20] == 0x11)
        f20 = 25.0f;
    f12 = 120.0f;
    v0 = func_00283CF0(f12);
    f20 = f20 + func_00283198((float)(D_L16_001B2648 % v0) / f12 * 6.2831855f - 3.1415927f);
    func_002AA548(s0 + 0x18, s1 + 0x268, *(float *)(s1 + 0x264) + f20,
                  0.0083333338f, 0.0027777778f, 0.16666667f);
    func_L16_00412F48(s0);
}
