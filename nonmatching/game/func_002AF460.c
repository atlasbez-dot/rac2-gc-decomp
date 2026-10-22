/* func_002AF460 (284 bytes, 28 places: the boot and the 27 levels) - near miss.
 *
 * The body is understood and matches retail instruction for instruction from the
 * loop on: the three early exits (the null position, the zero coordinate and the
 * flag func_002AF2E8 sets), the call to func_002AF2E8 with the copy of the caller's
 * two floats on the stack, the "keep the smallest distance" test, the walk of the
 * moby list with the pointer increment sunk into the delay slots of the three
 * likely branches, and the epilogue.
 *
 * What is left is the prologue.  Retail computes the address of the list head
 * (&global) and the save of $s1 after the loop's entry test:
 *
 *   lui $v1,0x1F / lw $s0,-0x16A0($v1) / beqz $s0,end / ... / addiu $s1,$v1,-0x16A0
 *
 * while this cc1 puts the address computation in the prologue, which also moves
 * the save of $s1 to the front of the prologue:
 *
 *   lui $v1,0x1F / sd $s0,0x20($sp) / sd $s1,0x28($sp) / sd $s2,0x30($sp) /
 *   addiu $s1,$v1,%lo(sym) / sd $s3,0x38($sp) / ...
 *
 * The two forms are the same instruction set in a different order, so this is the
 * prologue-interleaving wall (docs/COMPILER-NOTES.md) plus the address cost tie in
 * cse ("find_best_addr gives a register and a register plus a small constant the
 * same cost, and the tie goes to the sum").
 *
 * Measured (tools/check.py, the file's own flags):
 *   - the body from 0x2AF4D8 on matches at every place;
 *   - the whole function is 284 bytes (retail's size) with
 *       unsigned int *p = &global;  unsigned int node = global;
 *     and 292 bytes with the pointer assigned after the entry test (the compiler
 *     then materialises the address in a register and copies it, one instruction
 *     more than retail).
 *
 * Tried: the pointer as a function-scope variable with an initializer (the only
 * form that keeps retail's one-instruction address computation, but it lands in the
 * prologue), the pointer assigned after an explicit "if (node == 0) goto end"
 * (292 bytes, one instruction more), the pointer declared inside a block (292
 * bytes), a for-loop with the pointer as the loop variable (284 bytes, the same
 * prologue difference), the global declared as an array (284 bytes, the same
 * prologue difference), and the flags -O1, -O3, -fno-schedule-insns,
 * -fno-schedule-insns2, -fno-gcse, -fno-strength-reduce, -mno-split-addresses
 * (the last gives 292 bytes).
 *
 * What would unblock it: a source shape in which the address of the list head is
 * computed after the loop's entry test without the extra copy, or a cc1 that
 * schedules the prologue the way retail's does.
 */
extern unsigned int D_L00_0020ACE0;

int func_002AF460(V4_F876460d6 *pos, float p1, float p2, float p3, float p4)
{
    V4_F876460d6 copy = *pos;
    char *cbuf = (char *)&copy;
    float best = 1.0e8f;
    float d;
    int bestnode = 0;
    int flag;
    unsigned int node = D_L00_0020ACE0;
    unsigned int *p = &D_L00_0020ACE0;
    void *v;

    while (node) {
        v = (void *)func_002AB1F0((void *)node);
        if (v == 0)
            goto next;
        if (*(float *)v == 0.0f)
            goto next;
        d = func_002AF2E8(cbuf, (char *)node, &flag, p1, p2, p3, p4);
        if (flag)
            goto next;
        if (d < best) {
            best = d;
            bestnode = (int)node;
        }
    next:
        p++;
        node = *p;
    }
    return bestnode;
}
