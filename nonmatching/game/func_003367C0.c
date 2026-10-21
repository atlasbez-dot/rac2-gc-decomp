/* func_003367C0 - near miss.
 *
 * The C below reproduces the retail's 96 instructions instruction for instruction
 * (checked with tools/check.py --diff), but the catalogue's extent for the function
 * is 104 bytes: the eight bytes in front of the real body are the previous
 * function's epilogue area, not part of this function.
 *
 * At 0x0042C0E8 (level 00) the extent begins with
 *     addiu $sp, $sp, 0x20
 *     nop
 * and the real body (addiu $sp,$sp,-0x20 ... addiu $sp,$sp,0x20) starts at
 * 0x0042C0F0.  The previous function, func_003367B8, ends at 0x0042C0E7 with
 * `jr $ra` / `lw $v0,0x34($a0)`; the nop at 0x0042C0EC is the padding that
 * aligns the next function to 16 bytes.  The eight bytes in between belong to no
 * catalogued function, and the same shape is what the nonmatching rows
 * func_L00_00341798 and func_L00_002E6440 describe.
 *
 * So the extent is a catalogue defect (tools/levels.py): it is eight bytes too
 * long at the front.  With the extent fixed to 96 bytes this C is the match.
 */

extern char D_L00_001ADD78[];

extern void func_00336ED0(int a, int b);
extern void func_003360F8(char *object, int flags);

void func_003367C0(char *object, int flags)
{
    *(void **)(object + 0x30) = D_L00_001ADD78;
    if (*(int *)(object + 0x2C) != 0) {
        if (*(int *)(object + 0x38) == 0)
            func_00336ED0(*(int *)(object + 0x2C), *(int *)(object + 0x34));
    }
    func_003360F8(object, flags);
}
