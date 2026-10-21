#include "include_asm.h"

/* Near miss (wave 13, worker g3): 104 bytes of retail, the body is reproduced except for
   the two callee-saved registers.

   The retail body:

     addiu $sp,$sp,-0x30 / lw $v1,-0x14C4($gp) / sd $s0 / sd $s1 / daddu $s0,$a0 /
     sd $ra / beqz $v1 / daddu $s1,$a1 / lui $v0,0x19 / daddu $a1,$v1 /
     lw $a0,-0x3F50($v0) / jal func_002AD330 / daddu $a3,$sp / daddu $a0,$s0 /
     daddu $a1,$s1 / jal func_00282CC0 / daddu $a2,$sp / b / ld $s0 / lq $v0,0($s1) /
     sq $v0,0($s0) / ld $s0 / ld $s1 / ld $ra / jr $ra / addiu $sp,$sp,0x30

   This C is the same body with $s0 and $s1 swapped: the copy takes its source from
   $s0 and its destination from $s1, where the retail takes the source from $s1 and
   the destination from $s0.  Everything else (the frame, the 16-byte local at $sp+0
   that both calls take, the lq/sq pair, the branch to the epilogue with the `ld $s0`
   in its delay slot) is reproduced word for word.

   The register allocation follows the first use of the 128-bit copy's source: with
   `*(TI128 *)a0 = *(TI128 *)a1` the source is a1, and a1 takes $s0 (measured: the
   source of the lq always gets the first callee-saved register).  The retail has the
   destination in $s0, so its copy reads the other way round in the allocation, but the
   bytes say otherwise: the lq reads $s1 and the sq writes $s0, and $s0 holds $a0.

   Measured: `tools/check.py func_003001E0 --diff` gives "instruction at +0x10 differs"
   in the boot and in every level (the first difference is the `daddu $s0,$a1` against
   `daddu $s0,$a0`); the size is right (104).

   The cell at $gp-0x14C4 sits at a different address in the boot and in the levels, so
   it is named without an address; the function needs a -G8 unit for the gp-relative
   access. */

typedef int TI128 __attribute__((mode(TI)));

extern int ref_L00_003001E0_00 __attribute__((sda));

extern unsigned char D_0018C0B0[];

extern void func_002AD330(void *, void *, void *, void *);

extern void func_00282CC0(void *, void *, void *);

void func_003001E0(void *a0, void *a1, void *a2)
{
    TI128 buf;
    int *state = ref_L00_003001E0_00;

    if (state != 0) {
        func_002AD330(*(int *)D_0018C0B0, state, a2, &buf);
        func_00282CC0(a0, a1, &buf);
    } else {
        *(TI128 *)a0 = *(TI128 *)a1;
    }
}
