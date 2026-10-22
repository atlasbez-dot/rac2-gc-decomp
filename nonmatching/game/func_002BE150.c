/* func_002BE150 (292 bytes, 28 places) - near miss.
 *
 * The body is recovered and everything but three instructions and one
 * instruction slot matches the retail:
 *
 *   - the frame, the two callee-saved registers ($s2 = the object,
 *     $s1 = the object + 0x20), the three branches, the 16-byte copy
 *     (`addiu $v1,$a1,0x10 ; lq $v0,0($v1) ; sq $v0,0($a0)`), the float
 *     chain, the two float branches (bc1f / bc1tl), the division by 256
 *     (`mul.s` with 1/256) and the epilogue are the retail's;
 *
 *   - what is left is the unsigned 32 -> 64 bit widening of the word at
 *     +4 of the object.  The retail loads it with `lw` and widens it with
 *     `lui $v0,0xFF ; ori $v0,$v0,0xFFFF ; and $s0,$s0,$v0` (the `dli`
 *     expansion of the 32 bit constant 0xFFFFFFFFu in a 64 bit context).
 *     Measured: this cc1 folds that widening into the load (`lwu`) whenever
 *     the value is unsigned, drops it when the value is only used in 32 bits,
 *     and otherwise emits a sign extension (`dsll32`/`dsra32`) instead.  No
 *     source shape keeps the `lw` plus the mask;
 *
 *   - and the 0.0f constant (`mtc1 $zero,$f3`) sits one slot earlier than in
 *     the retail.
 *
 * The 16-byte copy needs the retail's materialised destination, so the
 * candidate wants -frac2-qcopy.
 *
 * The flags used: -O2 -G0 -ffunction-sections -frac2-qcopy.
 * Last check line: "boot: 280 bytes, expected 292" (0 of 28 places).
 */
extern void func_002B9180_4(void *);
extern float func_00283CE0(int n);
extern int func_00283CF0(float f);

typedef int TI128_002BE150 __attribute__((mode(TI)));

void func_002BE150(char *a0)
{
    char *s0;
    char *s1;
    unsigned char *p;
    float f0;
    float f1;
    float f2;
    float f3;
    unsigned int c;
    int r;

    s0 = a0;
    if (s0 == 0)
        return;
    s1 = s0 + 0x20;
    p = *(unsigned char **)(s0 + 0x20);
    if (p == 0 || (p[1] & 0x80)) {
        func_002B9180_4(s0);
        return;
    }
    *(TI128_002BE150 *)(s0 + 0x10) = *(TI128_002BE150 *)(p + 0x10);
    *(unsigned char *)(s0 + 8) = p[8];
    f0 = *(float *)(p + 0xC) * *(float *)(s1 + 4) + *(float *)(s1 + 8);
    *(float *)(s0 + 0xC) = f0;
    f3 = 0.0f;
    f1 = *(float *)(s1 + 0xC) + *(float *)(s1 + 0x14);
    *(float *)(s1 + 0xC) = f1;
    if (f1 < f3) {
        *(float *)(s1 + 0xC) = f3;
        return;
    }
    if (1.0f < f1) {
        *(float *)(s1 + 0xC) = 1.0f;
    }
    c = *(int *)(s0 + 4);
    r = func_00283CF0(((func_00283CE0((*(unsigned char **)(s0 + 0x20))[7]) / 256.0f)
                       * *(float *)(s1 + 0x10) + *(float *)(s1 + 0xC)) * 256.0f);
    c = c | ((unsigned int)r << 24);
    *(unsigned int *)(s0 + 4) = c;
}
