/* 160-byte near miss: the 152-byte C body is retail's exact size and every
 * instruction is right but two, but the catalogue row starts eight bytes
 * early: retail's row opens with the linker's fill, `addiu $sp,$sp,0x30` and a
 * `nop`, and the real body begins at +8 with the standard `addiu $sp,$sp,-0x20`
 * frame. A LEVEL_ENTRY_OFFSETS{(level, address): 8} entry for each of the nine
 * places (and the same shift in config/boot/functions.tsv) is what makes the
 * row place the body.
 *
 * What is left in the body: retail materialises the 0xFE000000 addend in `$a0`
 * and keeps the loaded word in `$v0` (`lui $a0,0xFE00` ; `lw $v0,0x4($s1)` ;
 * `addu $v0,$v0,$a0`), this cc1 gives the addend `$v0` and the word `$a0`.
 * The statement order, the `n = ... ; *p = n;` spelling and the block-scoped
 * local all give the same allocation.
 */
extern int func_00282978(short *);
extern void func_002B9180(void *);
extern void func_00282D30_12(char *, char *, float);
extern void func_00282CC0_17(char *, char *, char *);

void func_002C1DB0(char *self)
{
    char *motion = self + 0x20;

    func_00282D30_12(motion, motion, 0.975f);
    func_00282CC0_17(self + 0x10, self + 0x10, motion);
    *(int *)(self + 4) += (int)0xFE000000;
    *(float *)(self + 0xC) += 14700.0f;
    self[8] = self[8] + motion[0x10];
    if (*(int *)(self + 4) < 0)
        func_002B9180(self);
}
