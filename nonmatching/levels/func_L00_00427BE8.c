/* func_L00_00427BE8 (144 bytes, 27 places) - the TI128 destination wall is CROSSED with
 * -frac2-qcopy, but two retail instructions are still missing.
 *
 * Measured with scratch/wslcmp.py, flags "-O2 -G0 -ffunction-sections -frac2-qcopy":
 * "00_aranos_tutorial: 136 bytes, expected 144" - two words short.
 *
 * What -frac2-qcopy buys: the two quadword copies now materialise their destinations
 * and copy at offset 0, like retail:
 *     addiu $a0, $s0, 0xB0 ; lq $v0,0($a2) ; sq $v0,0($a0)
 *     addiu $v1, $s0, 0x80 ; lq $v0,0($a2) ; sq $v0,0($v1)
 * Without the switch this cc1 folds both displacements into the lq/sq (measured 128
 * bytes). The switch is in the master cc1; -frac2-qcopy-barrier is NOT (rejected).
 *
 * The two missing words are the ones the compiler's jump2 pass deletes:
 *  - retail re-copies the blend weight with `mov.s $f12,$f0` before the first call; this
 *    cc1 keeps the weight in $f0 and passes the parameter $f12 straight through, so the
 *    move is redundant and jump2 removes it. The compiler notes say the switch
 *    -frac2-qcopy-barrier is what keeps such a move (the copy becomes a barrier), and
 *    that option is not built here.
 *  - retail materialises the source pointer twice (daddu $a1,$s2,$zero before each of
 *    the two calls) because the first call clobbers $a1; this cc1 passes the incoming
 *    parameter $a1 straight to the first call and only reloads it for the second. A
 *    local copy of the source pointer (void *src = a1) was measured and does not change
 *    it: gcc still uses $a1 for the first call.
 *
 * The order of the two copies also differs: retail copies to +0xB0 and then to +0x80 with
 * one materialisation each, this cc1 materialises both destinations before the copies.
 */
typedef float f32;
typedef int TQ __attribute__((mode(TI)));

extern void func_L00_002D7958(float *dst, void *src, float x);
extern void func_L00_002D7940(char *p);
extern void func_L00_002EE0C0(char *p);
extern void func_L00_00427B40(char *p);

void func_L00_00427BE8(char *a0, void *a1, TQ *a2, f32 f12)
{
    char *s0 = *(char **)(a0 + 0x70);
    f32 weight = f12;

    *(TQ *)(s0 + 0xB0) = *a2;
    *(TQ *)(s0 + 0x80) = *a2;
    *(f32 *)(s0 + 0xC8) = weight;
    func_L00_002D7958((float *)(s0 + 0x14), a1, weight);
    func_L00_002D7958((float *)(a0 + 0x50), a1, 0.0f);
    func_L00_002D7940(s0);
    func_L00_002EE0C0(s0 + 0x90);
    func_L00_00427B40(a0);
}
