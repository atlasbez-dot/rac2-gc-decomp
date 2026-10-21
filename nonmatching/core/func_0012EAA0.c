/* from src/core/0012EAA0.c: 136 bytes; the candidate is 96 (SDK profile) or 104 (game) */
/*
 * Places a 64-bit value into one of the ten physical regions the table at
 * 0x137F78 describes ({u64 base; u64 mask} entries, ending in 0xCDCDCDCD fill):
 * the mask says which bits the region number occupies, so its trailing zeros are
 * the shift - 0xFF00000000 -> 32, 0xFFFF000000 -> 24, 0xFFFFFFFFFFFF -> 0 - and
 * the result is `base | (value << shift)`. The switch over the mask is the
 * natural source for the three values the table holds.
 *
 * What retail does that this cc1 does not:
 *  - the case selection is a value tree: `beq $v1,$a0` (mask == 0xFFFF000000),
 *    then `sltu $v0,$a0,$v1` + `bnel` to the shift-0 default, then
 *    `beq $v1,$v0` (mask == 0xFF00000000). Both profiles here compile the same
 *    two-case switch to two equality tests in a row: the SDK profile to
 *    `beq`/`bne` (96 bytes), the game profile to `beql`/`bne` (104 bytes).
 *    Reordering the cases in the source does not change which one is tested
 *    first - both cc1s sort the two case values - and neither emits the range
 *    test.
 *  - retail's frame is 16 bytes (`addiu $sp,$sp,-0x10` ... `addiu $sp,$sp,
 *    0x10`) with nothing stored in it; neither profile allocates a frame for
 *    this body. Whatever holds that frame is not visible in the C (there is no
 *    call), so the source shape that draws it is unknown.
 *
 * The table read, the two `ori`/`dsll` constant pairs, the variable `dsllv` and
 * the `ld`/`or` tail are the same in all three.
 *
 * Wave 24 (worker 06) measured the same body and adds:
 * - the retail's value tree comes from an if/else-if chain with a RANGE test in
 *   the middle, not from a switch: with
 *       if (cur == 0xFFFF000000ULL) sh = 24;
 *       else if (cur <= 0xFFFF000000ULL) sh = 32;
 *       else if (cur == 0xFF00000000ULL) sh = 32;
 *       else sh = 0;
 *   the compiler emits retail's `beq $v1,$a0` / `sltu $v0,$a0,$v1` / `beq $v1,$v0`
 *   in retail's order, with the third test dead (it is only reached when the
 *   mask is above 0xFFFF000000, so it can never be 0xFF00000000).  The switch
 *   above sorts its cases and never emits the range test.
 * - the shift amount has to be an int: a 64-bit shift variable makes the
 *   compiler sign-extend it (dsll32/dsra32) before the dsllv; retail has the
 *   plain `dsllv $a0,$a3,$a1`.
 * - the retail's split address of the table (lui $t0,0x13 once, the
 *   `addiu $v0,$t0,0x7F78` at every use) needs the symbol used TWICE, not
 *   through one pointer variable: `((u64 *)D_00137F78)[arg0 * 2 + 1]` and
 *   `((u64 *)D_00137F78)[arg0 * 2]` give the split form, a single pointer
 *   variable gives the materialised one.
 * - the shift amount takes the argument's register in the retail (the argument
 *   is copied to $a3 first, the shift lives in $a1); this cc1 keeps the
 *   argument in $a1 and the shift in $a0, and it if-converts the third test to
 *   a conditional move (movn) where the retail keeps the branch.
 * - with all of the above the body is 120 of the retail's 136 bytes; what is
 *   still missing is the 16-byte frame with nothing in it (an unused TImode
 *   local does not leave a frame in this cc1) and the two words that put the
 *   shift in $a1.
 */
typedef struct {
    unsigned long long base;
    unsigned long long mask;
} PhysRegion;

extern PhysRegion D_00137F78[];

unsigned long long func_0012EAA0(unsigned int arg0, unsigned long long arg1) {
    unsigned long long result = 0;

    if (arg0 < 10) {
        int shift;

        switch (D_00137F78[arg0].mask) {
        case 0xFFFF000000ULL:
            shift = 24;
            break;
        case 0xFF00000000ULL:
            shift = 32;
            break;
        default:
            shift = 0;
            break;
        }
        result = D_00137F78[arg0].base | (arg1 << shift);
    }
    return result;
}
