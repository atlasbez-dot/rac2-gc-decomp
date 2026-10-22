/* func_002BD8B0 (256 bytes, 28 places) - near miss.
 *
 * The body is recovered: the frame, the seven callee-saved registers
 * ($s0 = the particle, $s1 = the fourth argument, $s2 = the first,
 * $s3 = the third, $s4 = the sixth, $s5 = the fifth, $s6 = the second),
 * both 16-byte copies, every store, the two calls and the epilogue are the
 * retail's, in the retail's order.
 *
 * Two differences are left:
 *
 * 1. The 4.0f of the `func_00283CF0(4.0f)` call.  The retail keeps it at
 *    the use point, between the copy and the call; this cc1 hoists it to the
 *    top of the basic block, before the copy:
 *
 *      ours:   daddu ; lui $at,0x4080 ; mtc1 $at,$f12 ; addiu ; lq ; sq ; jal
 *      retail: daddu ; addiu ; lq ; sq ; lui $at,0x4080 ; mtc1 $at,$f12 ; jal
 *
 *    The hoisting is not the scheduler's: with -fno-schedule-insns the order
 *    is the same.  Measured on small cases, the reload puts a float constant
 *    at the start of the block, and the position depends on the statements
 *    around it; the same wall blocks func_002BB838.
 *
 * 2. The first branch.  The retail branches to the body
 *    (`bnez $s1` + a `b` to the epilogue for the zero case); this cc1
 *    canonicalises the test and branches over the body instead
 *    (`beqz $s1` to the epilogue).  Measured source shapes: an early
 *    `if (a4 == 0) return 0;`, an `if (a4 != 0) { ... }` around the whole
 *    body and a nested `if (p != 0) { ... }` - all three give the `beqz`.
 *
 * The 16-byte copies need the retail's materialised addresses, so the
 * candidate wants -frac2-qcopy.
 *
 * The flags used: -O2 -G0 -ffunction-sections -frac2-qcopy.
 * Last check line: "boot: instruction at +0x40 differs" (0 of 28 places).
 */
extern void *func_002B9030(int kind);
extern int func_00283CF0(float f);
extern int func_001163B0(void);
extern unsigned char *D_001F2594;

typedef int TI128_002BD8B0 __attribute__((mode(TI)));

void *func_002BD8B0(void *a0, void *a1, int a2, int a3, int a4, int a5, float f)
{
    void *p;
    char *q;
    int v;

    if (a4 == 0)
        return 0;
    p = func_002B9030(0x15);
    if (p == 0)
        return 0;
    *(TI128_002BD8B0 *)((char *)p + 0x10) = *(TI128_002BD8B0 *)a0;
    *(int *)((char *)p + 4) = a2;
    v = func_00283CF0(4.0f);
    *(unsigned char *)((char *)p + 1) = 0;
    *(float *)((char *)p + 0xC) = f;
    *(unsigned char *)((char *)p + 3) = 0x48;
    *(unsigned char *)((char *)p + 9) = (unsigned char)(v - 0x60);
    *(unsigned char *)((char *)p + 8) = (unsigned char)func_001163B0();
    q = (char *)p + 0x20;
    *(short *)((char *)p + 0xA) = a4;
    *(unsigned char *)((char *)p + 2) = *D_001F2594;
    *(short *)(q + 0x18) = a4;
    *(float *)(q + 0x1C) = f;
    *(int *)(q + 0x10) = a2;
    *(int *)(q + 0x14) = a3;
    *(short *)(q + 0x1A) = a5;
    *(TI128_002BD8B0 *)q = *(TI128_002BD8B0 *)a1;
    return p;
}
