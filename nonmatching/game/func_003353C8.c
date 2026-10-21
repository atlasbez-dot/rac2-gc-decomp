/* func_003353C8 - 88 bytes, 28 places (the boot and every level), retail at
   0x003353C8: addiu $sp,$sp,-0x20 ; lui $v0,0x1B ; sd $s0,0x8($sp) ; ...

   Measured near miss: with `-frac2-qcopy` and the ternary source below the
   compiled body is byte-exact except for the position of one instruction: the
   epilogue's `ld $ra,0x8($sp)` comes before the copy instead of after it.

   The retail (28 places, all identical):
     addiu $sp,$sp,-0x10 ; lui $v0,0x1B ; sd $s0,0($sp) ; addiu $v1,$zero,0x5 ;
     daddu $s0,$a0,$zero ; sd $ra,0x8($sp) ; lw $a0,0x5390($v0) ;
     lh $v0,0x86($a0) ; beq $v0,$v1,+0x14 ; daddu $v0,$a0,$zero ;
     jal func_270280 ; addiu $a0,$zero,0x5 ; b +0x8 ; lw $v1,0x70($v0) ;
     lw $v1,0x70($v0) ; addiu $v1,$v1,0x90 ; lq $v0,0($s0) ; sq $v0,0($v1) ;
     ld $s0,0($sp) ; ld $ra,0x8($sp) ; jr $ra ; addiu $sp,$sp,0x10.

   What this attempt reached (0x003353C8 in src/game/003353C8-rc2.c, compiled
   with `-O2 -G0 -ffunction-sections -frac2-qcopy`): every instruction is the
   retail's, in the retail's order, with the retail's duplicated
   `lw $v1,0x70($v0)` (the branch delay slot and the join block), the retail's
   `daddu $v0,$a0,$zero` in the beq delay slot and the retail's
   `addiu $v1,$v1,0x90 ; lq $v0,0($s0) ; sq $v0,0($v1)` - except that
   `ld $ra,0x8($sp)` is hoisted above the copy (the first difference is at
   +0x3c), so the body is 88 bytes with one instruction in the wrong place.

   Why: the retail's 128-bit copy was the game's own inline-asm macro, so both
   schedulers treat it as a barrier and nothing crosses it; the frame restore
   that follows the copy therefore stays after it.  The `-frac2-qcopy`
   emulation reproduces the copy's bytes but not the barrier: `sched2` moves
   the independent `ld $ra` up to cover the copy's latency.  This is the same
   wall as the neighbouring func_00335370 (nonmatching/README.md), with the
   difference that this attempt reaches the retail's whole instruction
   sequence.

   What was tried (all give the same hoist): the ternary source (the only one
   that reproduces retail's branch shape), the if/else source, the copy
   through a `char *` and through a `TI128 *`, a volatile destination and a
   volatile source (the TImode path drops the volatile flag: the three
   variants compile identically), the destination offset as an `int` add, and
   the flags `-fno-schedule-insns`, `-fno-schedule-insns2`, `-fno-gcse`,
   `-fno-strength-reduce`, `-fno-sched-interblock`, `-fno-expensive-optimizations`,
   `-fno-delayed-branch`, `-mno-split-addresses`, `-mastra-keep-frame-order`
   and their pairs with `-frac2-qcopy`.  `-fno-schedule-insns2` gives the
   retail's tail exactly (copy, `ld $s0`, `ld $ra`) but changes the prologue:
   retail interleaves the `lui` of the global's address and the constant 5 with
   the two saves, which that flag leaves in the natural order.

   What is still open: a source shape (or a scheduling model) that keeps the
   epilogue restore after a non-zero 128-bit copy.  The copy's barrier is the
   original's, and the compiler models it only for a cleared quadword
   (`-frac2-zero-ti-barrier`), not for a copied one. */

#include "include_asm.h"

/* The 128-bit integer mode is what reaches retail's lq/sq copies. */
typedef int TI128 __attribute__((mode(TI)));

/* The object the copy's destination comes from: a pointer at +0x70 and a state
   short at +0x86.  The layout is measured; the original type is unknown. */
typedef struct {
    unsigned char pad_353C8[0x70];
    int f70_353C8;
    unsigned char pad2_353C8[0x12];
    short f86_353C8;
} Obj_3353C8;

extern Obj_3353C8 *D_001B5390;

extern Obj_3353C8 *func_270280(int id);

/* Copies the caller's position into the current object's position slot. */
void func_003353C8(TI128 *position)
{
    Obj_3353C8 *obj = D_001B5390;
    Obj_3353C8 *target = (obj->f86_353C8 == 5) ? obj : func_270280(5);
    TI128 *dst = (TI128 *)(target->f70_353C8 + 0x90);

    *dst = *position;
}
