/* 0 of 27 places match - last line: 00_aranos_tutorial: instruction at +0x28 differs
 *
 * Every instruction of the body matches except one: the retail adds the block's
 * base to the scaled index with the base as the first source operand
 * (`addu $v0, $a0, $v0`), this cc1 always puts the index there
 * (`addu $v0, $v0, $a0`). The RTL order is canonicalised, so the source order
 * does not change it: tried the hoisted pointer, the inline expression, an int
 * base, a char * base, an unsigned index with a multiply, a 16-byte record
 * array and the pre-scaled index - all give the same instruction.
 *
 * What was measured and works:
 *  - the body needs a -G8 unit: the retail reaches the first registry word with
 *    `lw $a0, -0x1850($gp)`, which only comes out of a -G8 file with an `sda`
 *    declaration; the second word is reached absolutely (`lui $a1, 0x1B;
 *    lw $a1, -0x285C($a1)`), so it is declared without the attribute;
 *  - the block is the level's own data at 0x0022F7C0 (D_L00_0022F7C0, the same
 *    block func_L00_00374708 reads);
 *  - the helper is the boot function func_002B0D70 (the retail's jal target
 *    0x003269A8 in level 00); it takes no argument, the block pointer simply
 *    happens to still be in $a0;
 *  - the limit has to be read before the call (it then lives in $s0 across it);
 *  - the dispatch is `if (r >= limit)` with the 0x1129 arm in the then branch
 *    and the 0x1128 arm in the else branch - the retail's `bnez` jumps to the
 *    0x1128 arm;
 *  - the third argument of func_0027FB40 is a long, so the 0x80F0F0F0 colour
 *    comes out as `ori; dsll; ori`.
 *
 * Wave 8 re-measured the one remaining difference with ten more spellings
 * (int/char/short/void/unsigned base, `index*16` against `index<<4`, the
 * constant first, the address in a local, a 16-byte record array): the order
 * of the two operands follows the *kind* of the base, not the source.  A
 * runtime base (a parameter, or the block pointer read through a pointer
 * variable) gives `addu $2,$4,$2` / `addu $2,$3,$2` - base first, exactly
 * retail's shape - while a constant base (the symbol's address) goes through
 * the address pattern and gives `addu $2,$2,$4`, the index first.  Both the
 * game cc1 and the SDK's ee cc1 do the same.  So the retail's compiler kept
 * the materialised constant in a register for the add, and this cc1 folds the
 * address into the address pattern instead; the source cannot ask for the
 * difference, it depends on the base being a value in a register.
 *
 * The file lives in src/levels/shared/L00_00358D98-g8.c; the candidate needs
 * that -G8 unit, so it cannot stay in the plain unit.
 */
extern int D_L00_0022F7C0[];

extern int D_L00_001AD7A0 __attribute__((sda));

extern int D_L00_001AD7A4;

extern int func_002B0D70(void);

extern unsigned char *func_00288FB8(int);

extern int func_0027FB40(int, int, long, unsigned char *, int);

void func_L00_00378DE0(void)
{
    int base = (int)D_L00_0022F7C0;
    int index;
    int limit;
    int r;

    if (*(int *)(base + 0x84) == 0)
        return;
    index = *(int *)(base + 0x80);
    limit = *(int *)(base + (index << 4) + 0x148);
    r = func_002B0D70();
    if (r >= limit)
        func_0027FB40(D_L00_001AD7A0, D_L00_001AD7A4, 0x80F0F0F0, func_00288FB8(0x1129), -1);
    else
        func_0027FB40(D_L00_001AD7A0, D_L00_001AD7A4, 0x80F0F0F0, func_00288FB8(0x1128), -1);
}
