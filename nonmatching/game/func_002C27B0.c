/* 324-byte near miss (boot 0x002C27B0, 28 places): the C below is the retail's
 * exact size and 68 of its 81 instructions match at every place, but the unit
 * needs a compiler profile this file does not have and the last block is
 * scheduled differently.
 *
 * Profile: the retail's two 16-byte copies keep both addresses in registers
 * (`addiu $v1,$s0,0x10` / `lq $v0,0($v1)` / `sq $v0,0($sp)`), which is what
 * -frac2-qcopy produces; with the default profile the source address folds
 * into the displacement (`lq $v0,0x10($s0)`).  The function therefore needs a
 * unit of its own:
 *
 *     src/game/002BF6F0-qcopy.c	-O2 -G0 -ffunction-sections -frac2-qcopy
 *
 * (src/game/002BF6F0.c cannot take the flag: its other functions, matched on
 * master, use the folded copy.)
 *
 * What matches: the frame (0x50), the three saved registers, the whole head
 * (the null test, the short/word comparison and the two byte tests, with the
 * single shared kill block the `goto` form produces), the two float constants,
 * the call chain, the register roles ($s0 = self, $s1 = the sub-object vector,
 * $s2 = the motion pointer) and the tail (the three helpers inside the
 * `1.5f <` test, the two stores and the epilogue).
 *
 * What is left (13 instructions, all in one block):
 *   - the count at state + 4 is loaded into $a1 just before the blez in the
 *     retail (`lw $a1,0x4($s1)`), while here it is loaded early into $s2 and
 *     copied to $a1 at the call (`daddu $a1,$s2,$zero`);
 *   - the retail keeps the mul.s right after its two operands
 *     (`lwc1 $f22` then `mul.s $f21,$f1,$f0`), while here the mul.s is
 *     delayed into the delay slot of the blez;
 *   - the retail copies the vector address into $s1 in the delay slot of the
 *     blez (`daddu $s1,$v1,$zero`), while here that copy sits before the
 *     lq/sq pair.
 * All three follow from the same thing: the retail's count load is the last
 * instruction before the branch, so $s1 (the state pointer) is only free
 * after it, and the vector address can take $s1.  Here the count load is
 * scheduled early, $s1 is free earlier, and the allocator gives the vector
 * address $s2 instead.
 *
 * What was tried (each measured with tools/check.py --diff and the profile
 * above): the goto form of the head (needed: the `x == 0xFE || x == 0xFD`
 * spelling is folded into a range test by this cc1), the copy through a
 * pointer to the local (needed: the -frac2-qcopy pattern does not fire for a
 * frame slot, only for a memory operand reached through a register), the
 * count read before the call to func_002A7878 (13 differing instructions,
 * the best measured), read after it, through a pointer variable, into a
 * variable used by both the test and the call, and read directly (all of
 * them worse), the six orders of the three statements before the test (all
 * the same), and the float read from self + 0x3C instead of state + 0xC.
 */
extern void func_002B9180(void *);
extern float func_002A7878(float, float);
extern float func_00282E48(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_0029FCC0(int, int, void *);
extern void func_00282CC0(char *, char *, char *);

typedef int V4 __attribute__((mode(TI)));

void func_002C27B0(char *self)
{
    V4 local;
    V4 *lp = &local;
    char *state = self + 0x30;
    char *sub = *(char **)(self + 0x30);
    float f0;
    float f21;
    float f22;
    int count;

    if (sub == 0)
        goto kill;
    if (*(short *)(sub + 0xAA) == *(int *)(state + 8)) {
        if (*(unsigned char *)(sub + 0x20) == 0xFE)
            goto kill;
        if (*(unsigned char *)(sub + 0x20) != 0xFD)
            goto cont;
    }
kill:
    func_002B9180(self);
    return;
cont:
    count = *(int *)(state + 4);
    f0 = func_002A7878(0.5f, 1.0f);
    f22 = *(float *)(self + 0x2C);
    f21 = *(float *)(state + 0xC) * f0;
    *lp = *(V4 *)(self + 0x10);
    if (count > 0) {
        func_0029FCC0(*(int *)(self + 0x30), count, self + 0x10);
    } else {
        *(V4 *)(self + 0x10) = *(V4 *)(*(int *)(self + 0x30) + 0x10);
    }
    if (1.5f < func_00282E48(self + 0x10, self + 0x20)) {
        func_00282CF0(&local, &local, self + 0x10);
        func_00282F20(&local, &local, 1.5f);
        func_00282CC0(self + 0x20, self + 0x10, &local);
    }
    *(float *)(self + 0x1C) = f21;
    *(float *)(self + 0x2C) = f22;
}
