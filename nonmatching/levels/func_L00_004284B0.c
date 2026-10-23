/* func_L00_004284B0 (176 bytes, 27 places) - the TI128 destination wall is CROSSED with
 * -frac2-qcopy, but the register allocation is still off.
 *
 * Measured with scratch/wslcmp.py, flags "-O2 -G0 -ffunction-sections -frac2-qcopy":
 * "00_aranos_tutorial: instruction at +0x8 differs" - the size is exact (176 bytes / 44
 * instructions) and every instruction of the body is the right one; only the REGISTERS
 * differ.
 *
 * What -frac2-qcopy buys: the three quadword copies now materialise their addresses and
 * copy at offset 0, exactly like retail:
 *     addiu $a1, $a0, 0xB0 ; lq $v0,0($v1) ; sq $v0,0($a1)
 * Without it this cc1 folds the displacements into the lq/sq (measured 128 bytes). The
 * switch is in the master cc1 (build/compiler/tools), -frac2-qcopy-barrier is NOT (the
 * option is rejected), so the compiler-side barrier of COMPILER-NOTES cannot be used.
 *
 * The residue is the register allocation, in two places:
 *  - retail holds the owner in $s2 (daddu $s2,$a0,$zero), the sub-object in $s1
 *    (lw $s1,0x70($s2)) and the +0x14 pointer in $s0; this cc1 holds the owner in $s1,
 *    the sub-object in $s2 and the +0x14 pointer in $s0. The prologue's save order
 *    follows (retail: sd $s2 / sd $s0 / sd $s1 / sd $ra).
 *  - retail copies the first block into $a1 and the second into $a0; this cc1 uses $a0
 *    and $a1 the other way round.
 * Six spellings were measured (the sub-object read once or twice, the owner copied by
 * hand or left to the compiler, the declaration order of the three pointers, the two
 * constant blocks indexed or not): all give the same two swaps. The constant of the
 * last store is 0x40947AE1 = 4.64f.
 *
 * The C below is the closest measured form (exact size, right instructions, wrong
 * registers). */
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));

extern void func_L00_002D7940(char *p);
extern void func_L00_002D7958(char *dst, char *src, f32 x);
extern void func_L00_00427C78(char *p);

extern char D_00189EA0[];

void func_L00_004284B0(char *a0)
{
    char *s1 = *(char **)(a0 + 0x70);
    char *blk = s1 + 0xB0;
    char *s0;
    char *s2 = a0;

    *(TI128 *)blk = ((TI128 *)D_00189EA0)[0];
    *(f32 *)(blk + 8) = *(f32 *)(blk + 8) + 2.0f;
    *(TI128 *)(s1 + 0xC0) = ((TI128 *)D_00189EA0)[1];
    s1 = *(char **)(a0 + 0x70);
    *(TI128 *)(s1 + 0x80) = *(TI128 *)blk;
    s0 = s1 + 0x14;
    func_L00_002D7940(s0);
    func_L00_002D7958(s2 + 0x50, s0, 0.0f);
    *(f32 *)(s1 + 0x1C) = 4.64f;
    func_L00_00427C78(s2);
}
