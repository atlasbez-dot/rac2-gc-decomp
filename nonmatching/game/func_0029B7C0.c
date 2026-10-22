/* Near miss: func_0029B7C0 (76 bytes in every program).
 *
 * The function stores its two arguments into one of two 8-byte slots of the
 * record at D_001A8CFC[0] + 0x38000 and returns 1; it returns 0 when the
 * record is absent or when the slot index is not below 2.
 *
 * The best C found is below.  It compiles to 68 bytes; retail is 76.  The
 * structure is right (the two guards, the 0x38000 constant, the index scaled
 * by 8, the two stores) but the register allocation differs:
 *
 *   retail                          this C
 *   daddu $t0, $a0, $zero           daddu $t0, $a0, $zero   (in the branch's
 *   beqz  $a3, ret0                    delay slot instead)   delay slot)
 *   daddu $t1, $a1, $zero           (missing: a1 is copied to t1)
 *   sltiu $v0, $a2, 0x2              sltiu $v0, $a2, 0x2
 *   beqz  $v0, ret0                 beqz  $v0, ret0
 *   lui   $v1, 0x3                  lui   $a0, 0x3
 *   sll   $a1, $a2, 3               sll   $v1, $a2, 3
 *   ori   $v1, $v1, 0x8000          ori   $a0, $a0, 0x8000
 *   addiu $v0, $zero, 0x1           addiu $v0, $zero, 0x1
 *   addu  $v1, $a3, $v1             addu  $v1, $v1, $a0
 *   addu  $a0, $v1, $a1             addu  $v1, $a3, $v1
 *   daddu $v1, $a0, $zero           (missing: the copy of the pointer)
 *   sw    $t0, 0x7390($a0)          sw    $a1, 0x7394($v1)
 *   jr    $ra                       jr    $ra
 *   sw    $t1, 0x7394($v1)          sw    $t0, 0x7390($v1)
 *
 * What was tried (all compile, none matches):
 *  - the pointer built as (char *)base + 0x38000 + a2 * 8, as
 *    (char *)base + 0x38000 + (a2 * 8), with the index in a local, with an
 *    int * base and a scaled index (p + a2 * 2), with the two stores through
 *    two names of the same pointer, with the stores in the opposite order,
 *    with volatile stores and with the arguments copied into two locals;
 *  - the guards written as "&&" and as nested "if"s.
 * The sibling func_0029B810 (same file, not mine) shows the shape retail
 * wants - the sum in a register of its own, the index in an argument
 * register, and a copy of the pointer for the second store - but there the
 * only argument is free, so the allocator picks differently.
 *
 * Open: what makes this cc1 give the pointer sum its own register (so that
 * the argument registers a0 and a1 are both freed and the index can use a1).
 */
extern char *D_001A8CFC[] __attribute__((sda));

int func_0029B7C0(int a0, int a1, int a2)
{
    char *p;

    if (D_001A8CFC[0] != 0 && (unsigned int)a2 < 2) {
        p = (char *)D_001A8CFC[0] + 0x38000 + a2 * 8;
        *(int *)(p + 0x7390) = a0;
        *(int *)(p + 0x7394) = a1;
        return 1;
    }
    return 0;
}
