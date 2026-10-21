/* func_002B5E48 (boot function, 176 bytes; 20 levels, 21 places in all): near miss. Built alone (src/game/002B5E48.c) with
 * `-O2 -G0 -ffunction-sections -frac2-qcopy` it is retail's 176 bytes and 3 of its 44 words differ, at every place
 * (before the profile: 17 words, from the folded `lq $v0,0x10($a0)`). The register-address copy (`addiu $s2,$a2,0x10`
 * first, then `lq $v0,0($s2)` / `sq $v0,0($sp)`), the prologue and the allocation ($a2 = obj, $s1 = moby,
 * $s0 = moby + 0x60, $s2 = obj + 0x10) are exact. The three words are the order of the copy and one load:
 *     retail: addiu $s2,$a2,0x10 / lq $v0,0($s2) / sq $v0,0($sp) / lwc1 $f12,0($s1) / daddu $a1,$sp / jal
 *     here:   addiu $s2,$a2,0x10 / lwc1 $f12,0($s1) / lq $v0,0($s2) / sq $v0,0($sp) / daddu $a1,$sp / jal
 * Cause (measured with -dS -dR -fsched-verbose-5): retail's copy is a scheduling barrier, the grouped copy is not.
 * Before reload the dump shows no dependence between `lwc1 0($s1)` (an address based on a parameter) and the copy's
 * store to the frame, the load has latency 2 and priority 4 against 3 for the copy (cost 1, unit none), so the load
 * goes first, and the second scheduler keeps that order (after reload it does treat the two as possibly aliasing). Check: the same C
 * with `__asm__ __volatile__("" ::: "memory");` after the copy (scratch only, never for src/) is `boot: OK`, 0 of
 * 44 words different.
 * Tried without effect: all 24 orders of func_002C9218's parameters (the three integer ones must stay in order for
 * the registers; the float anywhere gives the same 3 words); integer-typed obj/moby; -fno-schedule-insns (11 words).
 * What would unblock it: the grouped copy given a volatile asm's scheduling dependences, as `-frac2-zero-ti-barrier`
 * does for `sq $zero` (func_002EE988 and func_002B50E0 are blocked by the same thing).
 */
typedef int TI128_002B5E48 __attribute__((mode(TI)));
typedef union { TI128_002B5E48 q; float f[4]; } Vec4Q_002B5E48;

extern int func_002C9218(int a0, void *a1, void *a2, float f);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(char *, char *, float);

int func_002B5E48(char *obj, char *moby)
{
    Vec4Q_002B5E48 v;
    char *s2;
    int id;

    id = *(int *)(moby + 0x3C);
    if (id == -1) return 0;
    if (*(unsigned int *)(moby + 0x9C) & 1) return 0;
    s2 = obj + 0x10;
    v.q = *(TI128_002B5E48 *)s2;
    if (func_002C9218(id, &v, s2, *(float *)moby) != 0) {
        func_00282CF0(moby + 0x60, &v, s2);
        func_00282F20(moby + 0x60, moby + 0x60, *(float *)moby);
        *(unsigned int *)(moby + 0x94) |= 0x10;
        return 1;
    }
    return 0;
}
