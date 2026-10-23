/* func_L00_004282F0 (216 bytes, 27 places) - the TI128 destination wall is CROSSED with
 * -frac2-qcopy and the flags -G8, but the prologue and the schedule still differ.
 *
 * Measured with scratch/wslcmp.py, flags "-O2 -G8 -ffunction-sections -frac2-qcopy":
 * "00_aranos_tutorial: instruction at +0xc differs" - the size is EXACT (216 bytes / 54
 * instructions) and every instruction of the body is the right one; only the registers
 * and the order of a few instructions differ.
 *
 * What -frac2-qcopy buys: the quadword copy now materialises BOTH pointers and copies
 * at offset 0, like retail:
 *     addiu $a0, $s0, 0xB0 ; addiu $v1, $s0, 0x80 ; lq $v0,0($v1) ; sq $v0,0($a0)
 * Without it this cc1 folds both displacements into the lq/sq (measured 208 bytes); the
 * switch is in the master cc1, -frac2-qcopy-barrier is NOT (rejected).
 *
 * Two fixes measured on the way (both kept below):
 *  - the three $gp arguments need SIZE on the objects: an incomplete `extern u8 D[]`
 *    goes out `lui $a1,0x0 ; addiu $a1,$a1,0x0` and costs a word each, a sized 8-byte
 *    object with `sda` reaches the bare GPREL16 addiu. That is why this row needs -G8.
 *  - 0x001B8F10 is the literal case: the retail holds `lui $v0,0x1C` and uses the low
 *    half as the displacement of the store.
 *
 * The residue, in the order it appears:
 *  - the prologue's save order: retail `sd $s0 / sd $s2 / sd $s1 / sd $ra`, this cc1
 *    `sd $s0 / sd $s1 / sd $s2 / sd $ra` (the registers themselves are the same);
 *  - the materialisation of the constant address: retail `lui $v0,0x1C` and
 *    `sh $zero,-0x70F0($v0)` in the delay slot of the call, this cc1 `lui $at,0x1C`,
 *    the store before the call and $at instead of $v0;
 *  - `mtc1 $zero,$f20` (the 0.0f of the blend weight): retail sets it after the copy
 *    (+0x58), this cc1 sets it right after the first call (+0x14);
 *  - the copy itself sits after the first call's argument setup here, before it there.
 *
 * Merging the argument and the sub-object into ONE C variable (so that the retail's
 * reuse of $s0 is reproduced) was measured too: it permutes the callee-saved registers
 * (param $s2, sub $s1 here against param $s1, sub $s2) and does not fix the schedule. */
typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

typedef int TI128 __attribute__((mode(TI)));

extern void *func_002D7A88(int a0);
extern void func_002D7DA0(void *a0);
extern void func_00428000(void *a0, void *a1);
extern void func_002D7958(void *a0, void *a1, f32 f12);
extern void func_002D7940(void *a0);
extern void func_00427C78(void *a0);

extern u8 D_L00_001B15E0[8] __attribute__((sda));
extern u8 D_L00_001B15F8[8] __attribute__((sda));
extern u8 D_L00_001B1610[8] __attribute__((sda));

void *func_L00_004282F0(u8 *a0) {
    u8 *s0 = a0;
    u8 *s2;
    u8 *p;
    f32 f20 = 0.0f;

    s2 = func_002D7A88(6);
    *(s16 *)0x001B8F10 = 0;
    func_002D7DA0(s2);
    func_00428000(s2, s0);
    p = *(u8 **)(s2 + 0x70);
    *(TI128 *)(p + 0xB0) = *(TI128 *)(p + 0x80);
    func_002D7958(p + 0x14, D_L00_001B15E0, f20);
    func_002D7958(s2 + 0x50, p + 0x14, f20);
    func_00427C78(s2);
    *(int *)(p + 0x9C) = 1;
    func_002D7958(p + 0x28, D_L00_001B15F8, f20);
    func_002D7958(p + 0x3C, D_L00_001B1610, f20);
    func_002D7940(p + 0x50);
    return s2;
}
