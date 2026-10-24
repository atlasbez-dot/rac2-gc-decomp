/* Readable C reconstruction, measured2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/1, us2: 0/1, pal: not carried.
 * 432 versus444 bytes; extra saved-register/address lifetimes, state dispatch and interpolation scheduling differ.
 * Tried: Explicit vector address lifetimes, delayed rotation pointer setup and recomputed final rotation reference.
 * Reopen: A verified source lifetime or local-vector layout remedy.
 * Historical notes below are preserved; their copy-wall claims are superseded
 * by the current qualified copy profiles. No handwritten-assembly inference.
 */

/* Not matched (worker 06, level-20 wave of 2026-10-20): the 128-bit
   copies are the wall.  The retail keeps the address of every 128-bit
   access in a register - `lq $v0,0x0($s2)` with `addiu $s2,$s1,0x10`
   (the object's +0x10), `lq $v0,0x0($s3)` with `addiu $s3,$s1,0xF0`
   (the object's +0xF0), `lq $v0,0x0($v1)` with `addiu $v1,$sp,0x10`
   (a local buffer) - while this compiler folds the offset into the
   instruction (`lq $v0,0x10($s1)`).

   The mechanism is measured in the note of func_L20_0039C448: the CSE
   substitutes the pointer's value (`plus(reg,const)`) into the address
   of the `lq`/`sq` and the reload pass then keeps the offset in the
   instruction; a pointer that is a parameter or a value loaded from
   memory keeps the register form, a computed `reg + const` never does.
   Every source spelling measured folds: a TI128 pointer variable, a
   struct member, an array index, a volatile load, a volatile pointer
   (a stack store and a reload, eight bytes over), a `static
   __inline__` copy helper, a truncation and a 64-bit address.

   This body belongs in the `-G8` unit?  No: it reaches no global
   through `$gp`. */

/* ---- level-20 wave 5, worker 05 (2026-10-21) ----
 *
 * The wall and every escape measured are now written down in the note on
 * func_L20_0039E770 in this directory: the CSE's find_best_addr() folds the
 * offset of a `plus` of a register into the lq/sq, and the address only
 * stays in a register when the pointer's value is not a plus of a register
 * (a symbol, a load, a call result, or a pointer carried by a loop).
 *
 * The retail's four copies of this body are:
 *
 *   addiu $s2, $s1, 0x10 ; lq $v0,0x0($s2)     ; the source: arg0 + 0x10
 *   sq $v0, 0x0($sp)                          ; the destination: a stack slot
 *   addiu $v1, $sp, 0x10 ; lq $v0,0x0($s3)     ; the destination: sp + 0x10
 *   sq $v0, 0x0($v1)
 *   addiu $v1, $s0, 0x60 ; lq $v0,0x0($s2)     ; the destination: state + 0x60
 *   sq $v0, 0x0($v1)
 *   addiu $v1, $s0, 0x60 ; lq $v0,0x0($v1)     ; the source: state + 0x60
 *   sq $v0, 0x0($s2)
 *
 * The first store (into the stack slot at +0) is the one this compiler can
 * reproduce; the other three materialise an address with a runtime base or a
 * stack offset, and it folds the offset into the instruction.
 *
 * This wave also measured that the retail's shape for a stack local is NOT
 * reachable by passing the local's address to a call: the compiler hoists
 * the address into the argument register (`addu $4,$sp,16`) and the 128-bit
 * store still folds (`sq $2,16($sp)`), also when the same pointer is passed
 * to two calls (then it is kept in $s0 and the store is still
 * `sq $2,560($sp)`).
 *
 * This body belongs in the -G8 unit?  No: it reaches no global through $gp. */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
extern int func_002B3868(unsigned char *);
extern void func_002A7750(unsigned char *, unsigned char, int);
extern int func_00282948(int *);
extern void func_00282CF0(void *, const void *, const void *);
extern void func_002AD6F0(void *, const void *, const void *, const void *);

void func_L20_0039EBB8(unsigned char *object) {
    Vector oldPosition, oldRotation, delta;
    unsigned char *state = *(unsigned char **)(object + 0x68);
    Vector *position = (Vector *)(object + 0x10);
    float phase;
    oldPosition.q = position->q;
    oldRotation.q = *(Quadword *)(object + 0xF0);
    switch (object[0x20]) {
    case 0:
        if (func_002B3868(object)) *(Quadword *)(state + 0x60) = position->q;
        func_002A7750(object, 1, -1);
        break;
    case 1:
        if (func_002B3868(object)) *(int *)(state + 0x7C) = *(int *)(state + 0x78);
        if (func_00282948((int *)(state + 0x7C))) func_002A7750(object, 1, -1);
        position->q = *(Quadword *)(state + 0x60);
        phase = (float)*(int *)(state + 0x7C) / (float)*(int *)(state + 0x78) + *(float *)(state + 0x80);
        while (1.0f < phase) phase -= 1.0f;
        *(float *)(object + 0x14) += *(float *)(state + 0x74) +
            (*(float *)(state + 0x70) - *(float *)(state + 0x74)) * phase;
        break;
    }
    func_00282CF0(&delta, position, &oldPosition);
    func_002AD6F0(state + 0x20, &delta, &oldRotation, object + 0xF0);
}
