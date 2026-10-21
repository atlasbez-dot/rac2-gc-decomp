#include "include_asm.h"

/* func_002BA8A0: the particle record's constructor.
 *
 * MEASURED (tools/check.py, level 00 and the boot):
 *   - 212 bytes in the retail; this body compiles to 216 bytes with the default flags
 *     and to 208 bytes when the file is compiled with "-frac2-qcopy".
 *   - The 16-byte copy of the source's first 16 bytes into the record at +0x10 needs
 *     the retail's shape "addiu $a0,$s0,0x10 ; lq $v0,0($s1) ; sq $v0,0($a0)": a
 *     materialised address and a zero displacement.  This cc1 always folds a constant
 *     displacement into the MMI pair ("sq $v0,0x10($s0)"); thirteen spellings were
 *     measured (char*, TI128*, void*, a variable offset, an unaligned source, a
 *     volatile store, a 64-bit pointer, a pointer used twice) and every one of them
 *     folds.  The compiler's own "-frac2-qcopy" (tools/compiler/transformers/
 *     qcopy_pattern.py) lowers an aligned TImode assignment to the grouped
 *     "lq/sq with register addresses" form, and with it this body emits exactly
 *     "addiu $a0,$s0,0x10 ; lq $v0,0($s1) ; sq $v0,0($a0)".
 *   - What is left is the scheduler's order: the retail keeps the float's group
 *     together (lwc1, lui/ori/mtc1, nop, add.s, swc1), then the copy, then the
 *     colour; this body lets the scheduler hoist the colour's "lui $v0,0x90" and
 *     split the float's group.  The instruction set is the same, the order is not,
 *     and the retail's "nop" after "mtc1 $at,$f1" (the mtc1 interlock) is the one
 *     instruction this body does not have.
 *
 * The record's global byte is at 0x1FE944 in level 00 and at 0x1F2544 in the boot,
 * so it needs a "ref_" name; the level's own copy of the function is in every
 * program.
 */

extern char *func_002B9030(int size);

extern int func_002EF250(float f);

/* The byte at the level's own global, whose address differs from program to program. */
extern unsigned char *ref_L00_0020E944_00;

typedef int TI128 __attribute__((mode(TI)));

/* Allocates a one-byte record, nudges the source's field 8 up by 0.2, copies the source's
 * first 16 bytes into the record and fills the record's header. */
void func_002BA8A0(void *a0, int a1)
{
    char *obj = (char *)func_002B9030(1);
    unsigned char byte;
    int r;

    if (obj == 0)
        return;
    *(TI128 *)(obj + 0x10) = *(TI128 *)a0;
    *(float *)((char *)a0 + 8) = *(float *)((char *)a0 + 8) + 0.2f;
    *(int *)(obj + 4) = (a1 << 24) | 0x00907070;
    r = func_002EF250(2.0f);
    *(char *)(obj + 9) = (char)(r + 0x40);
    *(char *)(obj + 3) = 0x44;
    *(char *)(obj + 1) = 0;
    byte = *ref_L00_0020E944_00;
    *(int *)(obj + 0x20) = a1;
    *(char *)(obj + 2) = byte;
    *(float *)(obj + 0xC) = 63000.00390625f;
    *(char *)(obj + 8) = 0xA0;
    *(short *)(obj + 0xA) = 0x1B;
}
