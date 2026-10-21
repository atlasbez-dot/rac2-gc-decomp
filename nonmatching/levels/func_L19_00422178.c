/* Matched byte for byte, but not landable: this body needs `qcopy`/`qzero` from
   include/common.h, which are inline assembly, and AGENTS.md's "Plain C" rule (no inline
   assembly in a function) forbids that as a matching route - docs/COMPILER-NOTES.md says it
   in as many words. Kept here as a starting point: the shape is right, and only the 128-bit
   copies would need a plain-C spelling that neither `mode(TI)` nor an aggregate gives yet.
   Removed from src/ on 2026-10-13. */

void func_L19_00422178(char *a0, float *a1)
{
    float t = func_3183D8(0.0f, (*(float *)(a0 + 0x2C) / *(float *)(*(int *)(a0 + 0x24) + 0x24)) * 6.0f);
    float r = func_3183D8(-3.14159274f, 3.14159274f);

    qcopy(a1, a0 + 0x10);
    a1[0] = a1[0] + t * func_2EBF18(r);
    a1[1] = a1[1] + t * func_2EBF30(r);
}

/* --- wave 24, worker 02: the 128-bit copy wall, measured again. ---
 *
 * The retail body copies sixteen bytes with
 *     addiu $s0, $s0, 0x10 ; lq $v0, 0x0($s0) ; sq $v0, 0x0($s1)
 * i.e. the source address a0+0x10 is materialised in a register and the
 * 128-bit load uses a zero displacement.  This cc1 folds the constant offset
 * into the instruction and emits `lq $v0, 0x10($s0)`.
 *
 * Every plain-C spelling of the copy was measured and all of them fold: a
 * pointer variable, `src++` on a TI128 *, char * arithmetic, a struct member,
 * a second assignment of the pointer, the increment before or after the
 * call, and TI128 with and without aligned(16).  Only a loop-carried pointer
 * (the increment at the end of a loop body) keeps the register form, and
 * this body has no loop.  The qcopy/qzero route in the candidate above does
 * produce the retail bytes, but it is inline assembly, which AGENTS.md
 * forbids.
 *
 * Two further differences are independent of the copy and would still need
 * work: the retail keeps the second call's result in two registers ($f20 and
 * $f21) and passes $f21 to func_00283180/func_00283198, where this cc1
 * keeps one ($f20) and copies it to $f12; and this cc1 emits a nop between
 * the divisor's `lwc1` and the `div.s` (the R5900 load/divide hazard) while
 * the retail has none there.
 *
 * tools/check.py func_L19_00422178 --diff:
 *   19_grelbin: 180 bytes, expected 192
 *   func_L19_00422178: 0 of 1 places match
 */
