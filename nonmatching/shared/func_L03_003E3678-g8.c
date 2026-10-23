/* func_L03_003E3678 (near miss, level 03 endako, 212 bytes at 8 places).
 *
 * Checked in a dedicated G8 unit (src/levels/shared/L03_003E3678-g8.c) built with
 *   -O2 -G8 -ffunction-sections -mno-split-addresses -frac2-qcopy
 * (the file needs its own flags: -mno-split-addresses keeps the lui/addiu pairs
 * of the two resident words together, and -frac2-qcopy is what lowers the
 * quadword copy to the grouped lq/sq pair with register addresses that retail
 * has).
 *
 * With that profile the candidate is retail's exact 212 bytes and every
 * instruction but one group is in place, in retail's order:
 *   - retail's first call takes rec+0x4C and rec+0x48, and the two addiu are in
 *     that order;
 *   - the second call's lui/addiu pairs stay together and the third argument's
 *     lwc1 is in the call's delay slot;
 *   - the copy at the end materialises the destination address (0x1B36B0)
 *     before the flag store at rec+0x56 and the source address (0x1B36C0)
 *     after it, and the lq/sq use $v0 for the quad.
 *
 * What is left is the prologue's first slot: retail puts the load of the
 * 1/60 factor's source word (0x1B0B80, the bare lwc1 $f1,0x1B90($gp) of a -G8
 * unit) between the frame adjustment and the register saves, and materialises
 * the 1/3600 constant (lui $at,0x3991 / ori / mtc1 $at,$f0) after the saves;
 * this cc1 materialises the constant before the saves and loads all three
 * $gp words after them. The two are the same 11 instructions in a different
 * order, and the rest of the function is retail's word for word.
 *
 * Tried and measured (all with the profile above):
 *   - the declaration order of c, f13, f14, f15 in any permutation: the
 *     object is the same every time, the constant always comes first;
 *   - the constants as locals (k = 0.00027777778f), the globals as locals, the
 *     multiply operands swapped (0.00027777778f * D_...), the values inlined
 *     in the call, and volatile reads of the globals: no change;
 *   - -fno-schedule-insns and -frac2-qcopy-barrier: no change.
 *
 * The next experiment would be a source shape in which the 1/3600 literal is
 * introduced after the 0x1B0B80 read in the RTL, since that literal's set is
 * what this cc1 hoists into the prologue slot.
 */

typedef unsigned char u8;

typedef float f32;

typedef int TI128 __attribute__((mode(TI)));

extern f32 D_L03_001B0B78 __attribute__((sda));

extern f32 D_L03_001B0B7C __attribute__((sda));

extern f32 D_L03_001B0B80 __attribute__((sda));

extern u8 D_L03_001B36B0[];

extern u8 D_L03_001B36C0[];

extern u8 D_L03_001B36B0_1[];

extern u8 D_L03_001B36C0_1[];

extern void func_002AA548(void *, void *, f32, f32, f32, f32);

extern void func_00283810(void *, void *, void *, f32);

extern void func_00283958(void *, void *);

/* Ages the entity's own rotation: hands the record's two angles and the shared
   factors to the vector helpers, then copies the shared direction into the
   resident direction when the record's angle has passed a full turn. */
void func_L03_003E3678(u8 *a0) {
    u8 *rec = *(u8 **)(a0 + 0x68);
    TI128 buf;
    f32 c = D_L03_001B0B80;
    f32 f13 = D_L03_001B0B78 * 0.00027777778f;
    f32 f14 = D_L03_001B0B7C * 0.00027777778f;
    f32 f15 = c * 0.016666668f;

    func_002AA548(rec + 0x4C, rec + 0x48, 1.0f, f13, f14, f15);
    func_00283810(&buf, D_L03_001B36B0, D_L03_001B36C0, *(f32 *)(rec + 0x4C));
    func_00283958(&buf, a0 + 0xC0);
    if (1.0f <= *(f32 *)(rec + 0x4C)) {
        TI128 *dst = (TI128 *)D_L03_001B36B0_1;
        TI128 *src = (TI128 *)D_L03_001B36C0_1;

        *(unsigned short *)(rec + 0x56) = 1;
        *dst = *src;
    }
}
