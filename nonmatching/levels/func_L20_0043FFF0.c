/* func_L20_0043FFF0 (348 bytes, level 20 only) -- NEAR MISS, not integrated.
   state: 372 bytes against retail's 348; the control flow, the block order and the whole
   loop match, and the fault is the register allocation: the retail spends six callee-saved
   registers and this compiler spends nine, so the constants (0xFF and 6) are kept in
   registers instead of being rematerialised in the loop, and the two global addresses are
   materialised as full addresses instead of being split (the %hi in a register, the %lo
   added at every use).
   check.py (20_yeedil), with the source below:
     0043FFF4  lui   $a1, 0x0          |  sd    $s0, 0x0($sp)
     0043FFF8  sd    $s2, 0x10($sp)   |  sd    $s2, 0x10($sp)
     0043FFFC  sd    $s5, 0x28($sp)   |  lui   $s0, 0x19
     00440004  daddu $s5, $a1, $zero  |  daddu $s2, $a0, $zero
     00440014  addiu $a1, $a1, 0x0    |  addiu $a1, $s0, -0x6160
   The retail keeps the %hi of D_00189EA0 in $s0 and copies it to $s5 for the use inside
   the loop; this compiler materialises the whole address in $a1 and copies that.  The
   retail's %hi of D_L20_001FBB20 lands in $s0 (the register the first %hi is copied out
   of) and its %lo is added at the use; this compiler materialises the table's address in
   full.

   What is measured and right:
   - the unit must be built with -G8: the function reads D_L20_001B2020 (the limit of the
     two counters, 5) and D_L20_001B2FB8 (the bound of the bank) through $gp.  In a -G0
     unit the `sda` attribute does NOT give the gp-relative form (measured: the relocation
     comes out HI16/LO16), so the function needs its own -G8 file.
   - the loop's block order is the retail's: the body first (the `a2` computation, the
     counters and the float compare), then the head (the index re-read, the two bound
     tests and the two "found" tests).  The source spells the head first and jumps into
     the body; the compiler keeps that order, which is what the retail has.
   - the two "found" tests are the branch-likely pair `bgezl`/`beql` with the `lhu` of the
     short in the delay slots, and the float compare is `c.lt.s $f0, $f20` + `bc1tl`,
     which needs the source `if (f20 > f) s4++;` (the operands swapped).
   Tried and not enough: the global addresses through a variable, through a second name
   and re-assigned after a nested block (the "split address" of the matched witness
   src/levels/shared/L00_002C2DE8.c); the pointer's declaration order; the loop written
   as a `while` with the head at the top.  What is left is the register allocation: the
   retail's %hi registers (one for D_00189EA0, one for D_L20_001FBB20) have to survive
   the call, and the source has to make the compiler keep the %hi rather than the whole
   address. */

#include "include_asm.h"

/* This unit is built with -G8: func_L20_0043FFF0 reads two globals through $gp
   (the bound of the bank and the limit of the counters). */

extern float func_00282E80(char *, char *);

/* The limit of the two counters. */
extern int D_L20_001B2020 __attribute__((sda));

/* The bound of the object bank. */
extern int D_L20_001B2FB8 __attribute__((sda));

/* The table of the objects' links. */
extern char *D_L20_001FBB20[];

/* The point the distances are measured from. */
extern char D_00189EA0[];

/* The first object of the bank. */
extern char *D_L20_001B2F9C;

int func_L20_0043FFF0(char *arg0) {
    char *base = D_00189EA0;
    char *s2 = arg0;
    char *s1;
    int s3 = 0;
    int s4 = 0;
    float f20;
    unsigned int idx;

    f20 = func_00282E80(arg0 + 0x10, base);
    idx = (unsigned char)arg0[0x21];
    s1 = (char *)D_L20_001FBB20[idx];
    goto head;

    for (;;) {
    body:
        {
            char *a2 = (char *)D_L20_001B2F9C
                     + ((*(unsigned short *)s1 & 0x7FFF) << 8);
            char *state;

            if (a2 == 0) {
                goto end1;
            }
            if (a2 == arg0) {
                s1 += 2;
                goto head;
            }
            if (*(unsigned char *)(a2 + 0x20) == 6) {
                s1 += 2;
                goto head;
            }
            state = *(char **)(a2 + 0x68);
            if (*(int *)(state + 0x280) != 0) {
                s3++;
            }
            if (s3 < D_L20_001B2020) {
                float f;

                base = D_00189EA0;
                f = func_00282E80(a2 + 0x10, base);
                if (f20 > f) {
                    s4++;
                }
                if (s4 < D_L20_001B2020) {
                    s1 += 2;
                    goto head;
                }
            }
            goto end0;
        }
    head:
        idx = (unsigned char)arg0[0x21];
        if (idx == 0xFF) {
            goto end1;
        }
        if (D_L20_001B2FB8 < (int)idx) {
            goto end1;
        }
        if (s1 == 0) {
            goto end1;
        }
        if (*(short *)(s1 - 2) >= 0) {
            goto body;
        }
        if (s1 == (char *)D_L20_001FBB20[idx]) {
            goto body;
        }
        goto end1;
    }
end1:
    return 1;
end0:
    return 0;
}
