/* func_L00_00333F90 (276 bytes, 27 places) - best attempt, NOT MATCHED.
 *
 * Re-measured on 22 October 2026 with the compiler rebuilt from the current sources and
 * the quadword-copy profile (-frac2-qcopy -frac2-qcopy-barrier): difference (a) is GONE,
 * the two copies now keep their addresses in registers exactly as retail does, as for
 * func_L00_00338D28 and func_L00_0033BA68. What is left is the multiply and, with it,
 * twelve bytes:
 *   - retail computes `func_002A77E0(6) * 6` with the R5900 three-operand multiply in
 *     place (`mult $v0,$v0,$a0`, the destination is the multiplicand, the constant 6 is
 *     materialised twice in $a0), then adds 0x40 and ORs 0x78404000 in $v0; this cc1 puts
 *     the product in a temporary register and moves it, and never reaches the same size.
 *     Tried: the product in its own statement, the operands swapped, the expression
 *     written inline in the store - all give the same 264 bytes.
 *   - retail keeps the second argument in $s1 and reuses that register for `obj + 0x20`
 *   - the byte the record's second flag byte takes is read from a per-level address:
 *     0x001FE98C in level 00 and another one in every other level, so the C needs a
 *     per-level symbol (ref_L00_00333F90_00) rather than D_L00_001FE98C.
 *
 * tools/check.py func_L00_00333F90 --diff:
 *   "00_aranos_tutorial: 272 bytes, expected 276" and the same for the other 26 places.
 *
 * The body, the two bound-helper calls, the flag bytes and the three float stores are
 * right; three measured differences remain:
 *   (a) the two 16-byte copies: retail materialises the destination first
 *       (`addiu $a2,$s2,0x10 ; sq $v0,0($a2)` and `addiu $s0,$s2,0x30 ; sq $v0,0($s0)`),
 *       this cc1 folds the constant offset into the `sq` (`sq $v0,0x10($s2)`).  Every
 *       spelling measured (a plain pointer variable, an inline `obj + 0x10`, a struct
 *       member) folds the offset, so retail's zero-offset form is not reachable with a
 *       `mode(TI)` copy;
 *   (b) retail keeps the second argument in $s1 and reuses that register for `obj + 0x20`
 *       after the copy; this cc1 keeps it in $s4 and the frame grows by 8 bytes;
 *   (c) retail's product is `mult $v0,$v0,$a0` (the destination is the multiplicand),
 *       this cc1 emits `mult $t0,$v0,$v1` and adds 0x40 into $v0 afterwards.
 *
 * What was measured to get here:
 *   - the object is allocated by func_002B9030(0x13) and the packed word is
 *     `(func_002A77E0(6) * 6 + 0x40) | 0x78404000`; the R5900 three-operand `mult` is what
 *     retail uses (`0x00441018` is `mult $v0,$v0,$a0`, not a `mult`+`mflo` pair);
 *   - the byte at +9 is the low byte of the packed word plus 0x20.
 *
 * To retake: a spelling of the 16-byte copy that keeps the destination address in a
 * register (the brief reports that a plain pointer with no offset does that, but it did
 * not here), and a product whose destination register is the multiplicand.
 */

#ifndef RAC2_T_TI128_33F90
#define RAC2_T_TI128_33F90
typedef int TI128_33F90 __attribute__((mode(TI)));
#endif

extern void *func_002B9030(int);

extern int func_002A77E0(int);

extern void func_00282CF0_1(char *dst, char *first, char *second);

extern unsigned char *D_L00_001FE98C;

/* Allocates the 0x13 object, fills its flags and its two 16-byte copies, and runs the
   two bound helpers over the record at +0x20. */
void *func_L00_00333F90(void *a0, void *a1)
{
    char *obj;
    char *s3 = a0;
    char *s1 = a1;
    int v;

    obj = (char *)func_002B9030(0x13);
    if (obj == 0)
        return obj;
    v = func_002A77E0(6) * 6;
    v = (v + 0x40) | 0x78404000;
    *(int *)(obj + 0xC) = v;
    *(int *)(obj + 0x4) = v;
    *(unsigned char *)(obj + 9) = (v + 0x20) & 0xFF;
    *(unsigned char *)(obj + 3) = 0x48;
    *(unsigned char *)(obj + 1) = 3;
    *(unsigned char *)(obj + 2) = *D_L00_001FE98C;
    *(TI128_33F90 *)(obj + 0x10) = *(TI128_33F90 *)s3;
    *(TI128_33F90 *)(obj + 0x30) = *(TI128_33F90 *)s1;
    func_00282CF0_1(obj + 0x20, s3, obj + 0x30);
    func_00282CF0_1(obj + 0x20, obj + 0x20, obj + 0x30);
    *(float *)(obj + 0x3C) = 6.0f;
    *(float *)(obj + 0x1C) = 0.09f;
    *(float *)(obj + 0x2C) = 0.5f;
    return obj;
}
