/* 80-byte near miss: the 72-byte C body is retail's exact bytes at every one of
 * the 18 places, but the catalogue row starts eight bytes early: retail's row
 * opens with the linker's fill, `addiu $sp,$sp,0x60` and a `nop`, and the real
 * body begins at +8 with the standard `addiu $sp,$sp,-0x10` frame. A
 * LEVEL_ENTRY_OFFSETS{(level, address): 8} entry for each of the 18 places (and
 * the same shift in config/boot/functions.tsv) is what makes the row place the
 * body; no C can cover the leading two words.
 */
extern int func_00282978(short *);
extern void func_002B9180(void *);

void func_002C0C70(char *self)
{
    if (*(short *)(self + 10) != -1) {
        if (func_00282978((short *)(self + 10)) != 0)
            func_002B9180(self);
    }
}
