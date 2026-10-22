/* Near miss for func_002C6DD8 (boot 0x002C6DD8, 276 bytes, 28 places).
 *
 * tools/check.py func_002C6DD8: 0 of 28 places match - every place reports
 * "instruction at +0x50 differs" (the same first difference at every place).
 * The size is right (276 bytes) and the prologue, the epilogue, the two quad
 * copies, the calls and the field offsets all match; what is left is the
 * order of four independent instructions in the middle of the body.
 *
 *   retail  002B6E28  sw  $v0, 0xC($s0)     the 0x7FFFFFFF store
 *           002B6E2C  mov.s $f12, $f20      the argument copy
 *           002B6E30  jal func_283CF0
 *           002B6E34  sw  $v0, 0x4($s0)     the second 0x7FFFFFFF store, in the delay slot
 *   this    002B6E28  mov.s $f12, $f20
 *           002B6E2C  sw  $v0, 0xC($s0)
 *           002B6E30  jal func_283CF0
 *           002B6E34  sw  $v0, 0x4($s0)
 *
 * and after that the three call-clobbered registers are chosen differently:
 * the retail uses $a1 for the constant 3 and $a0 for the address of
 * D_001F26A8, this one uses $a0 for the constant and $a2 for the address;
 * with that, the load of D_001F26A8 also ends up four instructions later
 * than the retail's (behind the 0.9f materialisation instead of in front of
 * it).
 *
 * The register choice follows the order in which the values appear in the
 * source: the retail gives the older pseudo the lower register, so its source
 * reads D_001F26A8 before the two byte constants, while this one reads it
 * last.  Putting the D_001F26A8 read first was measured (work/../report.md)
 * and moved the load to the front of the block, which is further away.
 *
 * What else was measured: the function's shape (allocate 0x5A bytes, fill the
 * fields, copy the two quads with the 16-byte vector type, two helper calls
 * with the scratch vector), that the second float argument is not used at all
 * (the value at 0x2C is the constant 2.0f that the first helper is called
 * with), that the third argument is a 64-bit value whose low halfword is
 * stored at 0xA, and that the word at 0x4 holds the same 0x7FFFFFFF as the
 * word at 0xC (the retail stores it in the call's delay slot, before the
 * helper's result exists).
 */

extern void *func_002B9030(int);
extern void func_00282F20(float, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern int func_00283CF0_6(float);
extern int *D_001F26A8;

typedef int V4_Fc3cb9262 __attribute__((mode(TI)));

/* Creates the object of 0x5A bytes: the two quads of the arguments are copied
   into it, the fields are filled and the two helpers are called with the
   scratch vector and the first argument. */
char *func_002C6DD8(void *a0, void *a1, long long a2, float f1)
{
    V4_Fc3cb9262 vec;
    char *s0;
    int v;

    s0 = (char *)func_002B9030(0x5A);
    if (s0 != 0) {
        *(int *)(s0 + 4) = 0x7FFFFFFF;
        *(int *)(s0 + 0xC) = 0x7FFFFFFF;
        v = func_00283CF0_6(2.0f);
        *(char *)(s0 + 9) = (char)(v + 0x20);
        *(char *)(s0 + 3) = 0x48;
        *(char *)(s0 + 1) = 3;
        *(char *)(s0 + 2) = *(char *)D_001F26A8;
        *(V4_Fc3cb9262 *)(s0 + 0x30) = *(V4_Fc3cb9262 *)a1;
        *(float *)(s0 + 0x3C) = f1;
        *(V4_Fc3cb9262 *)(s0 + 0x10) = *(V4_Fc3cb9262 *)a0;
        func_00282F20(0.9f, &vec, a0);
        func_00282CF0(s0 + 0x20, a0, &vec);
        *(short *)(s0 + 0xA) = a2;
        *(float *)(s0 + 0x1C) = 0.1f;
        *(char *)(s0 + 8) = (char)(*(unsigned char *)(s0 + 0xA) - 0xF);
        *(float *)(s0 + 0x2C) = 2.0f;
    }
    return s0;
}
