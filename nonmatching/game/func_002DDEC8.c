/* func_002DDEC8 (520 bytes, boot 0x2DDEC8, 28 places)
 *
 * Draft, not compiled: the body is decoded, the table walk is not reproduced yet.
 *
 * The body: it takes no argument.  It reads a 64-bit word at +0x1C0 of the
 * block at 0x140000 - 0x7E80 and tests its low nibble against 6; if it is not 6
 * it clears a word through `$gp` (-0x3350) and leaves.  Otherwise it reads the
 * word at +0x1C4, tests the mask 0xF0A0, and leaves when it is zero.  It then
 * reads the word through `$gp` (-0x3350) and leaves when it is below 0x14, and
 * it walks a set of bits in the word: 0x1000, 0x4000, 0x8000, 0x2000 and 0x80
 * each give a value 0, 1, 2, 3 and 5 (with a `movn` for the last), the value
 * is scaled by 2 and used as an index into the table at 0x1B2028, and twenty
 * halfwords are written into it with a `movn`/`beql` chain.  Three calls
 * finish the body.
 *
 * The unit has to be built with -G8: the body reads a word through `$gp`
 * (-0x3350) and the table at 0x1B2028 is small data.
 *
 * What has to be reproduced: the order of the bit tests (each in the delay slot
 * of the next branch), the `movn` that picks 4 against 5, the index arithmetic
 * and the twenty halfword stores.
 *
 * What would unblock it: the bit-test chain's shape (the retail keeps the
 * assignment in the delay slot of the branch, which the level 20 wave found to
 * be a wall for if/else but reachable with two separate `if` statements), and
 * the table's index arithmetic.
 */
typedef unsigned short u16;

extern u16 ref_L00_001B2028_00[];

void func_002DDEC8(void)
{
    u16 *table = ref_L00_001B2028_00;
    int index = 0;
    int i;

    for (i = 0; i < 20; i++)
        table[i] = 0;
    table[index] = 0;
}
