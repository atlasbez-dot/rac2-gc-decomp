/* Near miss: the retail body is 200 bytes, this C compiles to 188.

   The 128-bit copy is the wall: retail reads the source through a register
   (addiu $v1, $a1, 0x10 ; lq $v0, 0x0($v1)) and this cc1 folds the constant
   offset into the load (lq $v0, 0x10($a0)); the source address is base+const.
   The two branch-likely forms (bnel $a0, $zero and bc1tl) are also not reached
   by this spelling: retail's bnel carries the load of the f13 field in its
   delay slot and bc1tl carries the store of the clamped value.

   Checked with: python3 tools/check.py func_L01_003BD5E8 --diff
   Last line: func_L01_003BD5E8: 0 of 1 places match (src/levels/01_oozla/L01_003BB9D0.c) */

typedef int TI128 __attribute__((mode(TI)));

extern float func_L01_003BD560(void *, void *, float, float, float, float);

extern char D_00189EA0[];

void func_L01_003BD5E8(char *a0)
{
    char *s0 = *(char **)(a0 + 0x68);
    TI128 v = *(TI128 *)(a0 + 0x10);
    float f13;
    float f12;
    float f0 = 10.0f;
    float r;

    if (*(unsigned char *)(a0 + 0x20) != 0) {
        f13 = *(float *)(a0 + 0x18);
        f12 = 2.0f;
    } else {
        f13 = *(float *)(s0 + 0x1D8);
        f12 = 20.0f;
    }
    f12 = f13 + f12;
    f13 = f13 - f0;
    r = func_L01_003BD560(&v, a0, f12, f13, *(float *)(s0 + 0x27C), *(float *)(s0 + 0x288));
    *(float *)(s0 + 0x224) = r;
    if (*(float *)(s0 + 0x224) < *(float *)(s0 + 0x27C)) {
        *(float *)(s0 + 0x224) = *(float *)(s0 + 0x27C);
    }
    *(float *)(s0 + 0x228) = (*(float *)(D_00189EA0 + 8) + 0.1f > *(float *)(s0 + 0x224) + 0.4f)
        ? (*(float *)(D_00189EA0 + 8) + 0.1f) : (*(float *)(s0 + 0x224) + 0.4f);
}
