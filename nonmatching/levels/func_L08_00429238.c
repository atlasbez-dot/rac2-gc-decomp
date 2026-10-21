/* func_L08_00429238 (276 bytes, 1 place) - best attempt, NOT MATCHED.
 *
 * The retail body: a three-slot walk over the owner table 0x1B3A30 looking for the
 * handle (it answers 1 if the handle is already in a slot), and otherwise a second
 * walk over the same table for a free slot, whose ten parallel arrays (0x1B39A0,
 * 0x1B39B0, 0x1B39C0, 0x1B39D0, 0x1B39E0, 0x1B39F0, 0x1B3A00, 0x1B3A10, 0x1B3A20
 * and the table itself) are then filled.
 *
 * `python3 tools/check.py func_L08_00429238 --diff`: 284 bytes against the retail's
 * 276.  The two walks, the `bnel` delay-slot counter bumps, the ten stores and the
 * `slti`/`bnez` loop test are the retail's.  What is left:
 *
 *  - this cc1 copies the three arguments into $t6/$s0/$t9 in the prologue (the
 *    retail keeps them in $a0/$a1/$a2), which is three instructions too many;
 *  - the ten addresses are materialised in a different order: retail materialises
 *    0x1B39A0, 0x1B3A20, 0x1B3A10, 0x1B3A00, 0x1B39F0, 0x1B39E0, 0x1B39D0,
 *    0x1B39C0, 0x1B39B0, 0x1B3A30 into $t7, $t8, $t4, $t1, $a3, $t6, $t5, $t2,
 *    $t0, $v1, and this cc1 in another one.  The order is the allocator's (the
 *    ten addresses need ten callee-saved registers), and it does not follow the
 *    order the source names the arrays in - both orders of the stores measured here
 *    give the same materialisation.
 *
 * Measured, no effect: naming the ten arrays through pointers instead of indexing
 * them, and writing the ten stores in the retail's order.
 */

typedef int s32;

extern s32 D_L08_001B39A0[];
extern s32 D_L08_001B39B0[];
extern s32 D_L08_001B39C0[];
extern s32 D_L08_001B39D0[];
extern s32 D_L08_001B39E0[];
extern s32 D_L08_001B39F0[];
extern s32 D_L08_001B3A00[];
extern s32 D_L08_001B3A10[];
extern s32 D_L08_001B3A20[];
extern s32 D_L08_001B3A30[];

s32 func_L08_00429238(s32 a0, s32 a1, s32 a2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_L08_001B3A30[i] == a0) {
            return 1;
        }
    }
    for (i = 0; i < 3; i++) {
        if (D_L08_001B3A30[i] == 0) {
            D_L08_001B3A30[i] = a0;
            D_L08_001B39F0[i] = -1;
            D_L08_001B3A00[i] = a1;
            D_L08_001B3A10[i] = a2;
            D_L08_001B39A0[i] = 1;
            D_L08_001B39B0[i] = 0;
            D_L08_001B39C0[i] = 0;
            D_L08_001B39D0[i] = 0;
            D_L08_001B39E0[i] = -1;
            D_L08_001B3A20[i] = 0;
            return 1;
        }
    }
    return 0;
}
