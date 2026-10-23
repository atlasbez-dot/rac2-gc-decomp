/* func_L03_003E4588 (near miss, level 03 endako, 244 bytes at 8 places).
 *
 * Checked in the -G8 sibling (src/levels/shared/L03_003C5B28-g8.c): the
 * candidate is 228 bytes against retail's 244.  The branch structure, the
 * $gp words and floats, the three arms and the two calls are in place; what
 * is missing is retail's spill of the selected word pair:
 *
 *   - retail keeps the selected pair on the stack (sw $v0,0($sp) in the arm,
 *     sw $v1,4($sp) in the common tail) and reloads them for the lookup call
 *     (lw $a0,0($sp) / lw $a1,4($sp)); this cc1 keeps the pair in $s0/$s1 and
 *     moves them with daddu, which also costs two more saved registers;
 *   - retail holds the 1/2880 factor in $f0 across the first call (mov.s
 *     $f12,$f0 before the second), this cc1 rematerialises it after the call
 *     (lui $at,0x3998 / ori / mtc1) and keeps a copy in $f20.
 *
 * An array or a volatile pair was tried for the spill: the array keeps the
 * pair in memory but stops the two identical arms from being merged, and the
 * volatile pair keeps the second store in the arm instead of the common tail
 * (the project rejects an artificial volatile qualifier anyway).
 *
 * Re-measured on 22 October 2026 with the project's rebuilt compiler (the
 * one that carries -frac2-qcopy, -mno-split-addresses and the other opt-in
 * switches): the candidate is still 228 bytes, with the same two residuals.
 */

typedef unsigned char u8;

typedef unsigned int u32;

typedef float f32;

extern u32 D_L03_001B0C48 __attribute__((sda));

extern u32 D_L03_001B0C4C;

extern u32 D_L03_001B0C50;

extern u32 D_L03_001B0C54;

extern u32 D_L03_001B0C58;

extern u32 D_L03_001B0C5C;

extern f32 D_L03_001B0C60 __attribute__((sda));

extern f32 D_L03_001B0C64;

extern f32 func_00283B98(f32, f32);

/* The shared lookup the record's state selects: its target sits at another
   address in every program, so it is named by its own place. */
extern int ref_L01_0031BC68_00(int, int, f32);

/* Eases the record's own rate by the shared factor and hands the state the
   shared lookup asks for. */
void func_L03_003E4588(u8 *a0) {
    u8 *rec = *(u8 **)(a0 + 0x68);
    u32 v0;
    u32 v1;
    f32 f13;

    if (a0[0x20] == 5) {
        v0 = D_L03_001B0C48;
        v1 = D_L03_001B0C4C;
        f13 = D_L03_001B0C60 * 0.00029088825f;
    } else if (*(short *)(rec + 0x6A) == 0) {
        v0 = D_L03_001B0C48;
        v1 = D_L03_001B0C4C;
        f13 = D_L03_001B0C60 * 0.00029088825f;
    } else if (*(short *)(rec + 0x68) != 0) {
        v0 = D_L03_001B0C50;
        v1 = D_L03_001B0C54;
        f13 = D_L03_001B0C64 * 0.00029088825f;
    } else {
        v0 = D_L03_001B0C58;
        v1 = D_L03_001B0C5C;
        f13 = D_L03_001B0C64 * 0.00029088825f;
    }
    func_00283B98(*(f32 *)(rec + 0x78), f13);
    *(f32 *)(rec + 0x78) = 0.00029088825f;
    *(u32 *)(a0 + 0x78) = ref_L01_0031BC68_00(v0, v1, 0.00029088825f);
}
