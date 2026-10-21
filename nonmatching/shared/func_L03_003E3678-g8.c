/* func_L03_003E3678 (near miss, level 03 endako, 212 bytes at 8 places).
 *
 * Checked in the original -G8 unit (src/levels/shared/L03_003C5B28-g8.c): the
 * candidate is 212 bytes, the exact size, and the frame, the calls, the $gp
 * loads and the lq/sq copy are all in place.  What is left is the order of a
 * handful of instructions:
 *
 *   - retail materialises the 1/3600 constant (lui $at,0x3991 / ori / mtc1)
 *     after the frame saves, this cc1 puts it before them, and retail loads
 *     the 1/60 factor's source word (0x1B0B80) first, this cc1 loads it after
 *     the saves;
 *   - retail computes the first call's two arguments in source order
 *     (rec+0x4C then rec+0x48), this cc1 computes rec+0x48 first;
 *   - retail materialises the copy's destination address (0x1B36B0) before the
 *     store of the flag at rec+0x56 and its source address (0x1B36C0) after
 *     it, keeping each lui/addiu pair together; this cc1 loads the source
 *     first and splits the pairs around the flag store;
 *   - retail's lq/sq use $v0 for the quad, this cc1 uses $a0.
 *
 * The 0x1B36B0/0x1B36C0 words are named twice here (D_L03_001B36B0_1 and
 * D_L03_001B36C0_1): the copy reads and writes them after the calls, so they
 * have to be materialised again there instead of kept in a saved register.
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
