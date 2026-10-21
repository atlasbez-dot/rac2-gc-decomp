/* func_002B50E0 (boot function, 372 bytes; 20 levels, 21 places in all): near miss. Built alone (src/game/002B50E0.c) with
 * `-O2 -G0 -ffunction-sections -frac2-qcopy` it is retail's 372 bytes (368 without the profile) and 11 of its 93
 * words differ, at every place. The prologue, the register assignment (self in $s2, target in $s3, data in $s1),
 * the stack slots, the `$gp` / absolute mix of D_001B1688 (the `sda` declaration gives retail's) and the register-address copy
 * (`addiu $v1,$s2,0x10` / `lq $v0,0($v1)` / `sq $v0,0($sp)`) are right. Two things are left:
 *  (1) 8 words after the copy. Retail loads data->0xBC first and the global after it
 *      (lw $v1,0xBC($s1) / lui $v0,%hi / lw $v0,%lo($v0) / subu $v0,$v0,$v1 / slti), and puts the copy before both;
 *      here the global's `lui`/`lw` chain (the longest path to the branch) is issued before the copy, the copy's address
 *      is then in $a0 and the `lw $v1,0xBC` / `subu` registers swap. Same cause as func_002B5E48: retail's copy is a scheduling
 *      barrier, the grouped copy is an ordinary insn with cost 1 and unit none.
 *  (2) 3 words in the arguments of the func_002B5828 call. Retail: daddu $a2,$s3 / daddu $a3,$sp / daddu $a0,$s2 /
 *      jal (slot: daddu $a1,$s1); here: $a2, $a0, $a1, then jal with `daddu $a3,$sp` in the slot (the call of
 *      func_002B5678 just before, and func_002B52A0, come out as retail's). Not moved by `(void *)work` for the argument,
 *      a pointer variable for it (388 bytes), or a TI/float union for the array.
 * Check: with `__asm__ __volatile__("" ::: "memory");` after `work[0] = *src;` (scratch only, never for src/) (1) is
 * gone and only the 3 words of (2) are left. -fno-schedule-insns makes it worse (30 words).
 * What would unblock it: the grouped copy given a volatile asm's scheduling dependences (see func_002B5E48), and then a source form
 * for (2).
 */
extern int D_001B1688 __attribute__((sda));
extern char *func_002B5D28(void *);
extern void func_002B5CD8(void *, void *);
extern void func_002B5BC0(void *, void *, float);
extern int func_00282C88(void *);
extern void func_002B52A0(void *, void *, void *, void *, void *, float);
extern void func_002B5678(void *, void *, void *, void *);
extern void func_002B5828(void *, void *, void *, void *);
extern void func_002B5EF8(void *, void *, float);
extern void func_002B62A0(void);

typedef int PoseVector128 __attribute__((mode(TI)));

int func_002B50E0(void *self, void *target, float amount)
{
    char *data = func_002B5D28(self);
    PoseVector128 work[3];

    if (data == 0)
        return 8;
    if (D_001B1688 != *(int *)(data + 0xBC)) {
        *(int *)(data + 0x98) = *(int *)(data + 0x94);
        *(int *)(data + 0x94) = 0;
        if (!(*(int *)(data + 0x38) & 0x100))
            func_002B5CD8(self, data);
        {
            PoseVector128 *src = (PoseVector128 *)((char *)self + 0x10);
            work[0] = *src;
        }
        if (D_001B1688 - *(int *)(data + 0xBC) >= 2 || *(int *)(data + 0xBC) == 0) {
            func_002B5BC0(self, data, 0.0f);
            *(unsigned char *)(data + 0xEA) = 0xFF;
            *(int *)(data + 0x9C) &= ~2;
            *(float *)(data + 0xB4) = 0.0f;
            *(int *)(data + 0x80) = 0;
            func_00282C88(data + 0xA0);
        }
        *(int *)(data + 0xBC) = D_001B1688;
        func_002B52A0(self, data, target, &work[1], &work[2], amount);
        func_002B5678(self, data, &work[0], &work[2]);
        func_002B5828(self, data, target, &work[0]);
        func_002B5EF8(self, data, amount);
        func_002B62A0();
    }
    return *(int *)(data + 0x94);
}
