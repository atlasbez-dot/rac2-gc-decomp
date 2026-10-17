/* 0 of 1 place match - last line: 02_maktar_nebula: 132 bytes, expected 184
   Advances a short counter at state+0x31A while the float at state+0x20 stays below
   (float)(s16)state+0x24 * (3.0f - (float)(s16)i) * 0.33333334f, then latches the state word
   at state+0x318 to 1; returns immediately when that word is already non-zero.
   Modelled as the natural `do { i++; state[0x31A] = i; } while (cond);`, this cc1 emits a
   ROTATED loop of 132 bytes - the increment and its store sit at the loop head and a single
   `bc1t` closes it. Retail is 184 bytes because it PEELS the first iteration: it computes
   `i = count + 1`, tests with `bc1f -> DONE`, keeps `sh $a0,0x31A($a1)` in that branch's delay
   slot, and only then runs the loop body (whose own store, `sh $v1,0x31A($a1)`, is after the
   back-edge `bc1t`). The two operand constants match exactly (0x40400000, 0x3EAAAAAB).
   The register roles are also swapped: retail keeps (float)state[0x24] in $f2 and the float
   at state[0x20] in $f1 (loaded last, `lwc1 $f1,0x20($a1)`), this form uses $f1/$f2 the other
   way round - so a spelling that computes the scaled term before reading state+0x20, and that
   produces the peeled store, is what to try next. */

#include "include_asm.h"

void func_L02_003D4990(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    float f;
    float hf;
    int i;

    if (*(short *)(state + 0x318) != 0)
        return;
    f = *(float *)(state + 0x20);
    hf = (float)*(short *)(state + 0x24);
    i = *(unsigned short *)(state + 0x31A);
    do {
        i++;
        *(unsigned short *)(state + 0x31A) = i;
    } while (f < hf * (3.0f - (float)(short)i) * 0.33333334f);
    *(short *)(state + 0x318) = 1;
}
