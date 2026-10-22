/* func_00307298 - 148 bytes, 1 place (the boot), retail at 0x00307298:
   addiu $sp,$sp,-0x30 ; sd $s0,0x10($sp) ; sd $s2,0x20($sp) ; sd $ra,0x28($sp) ;
   daddu $s2,$a0,$zero ; sd $s1,0x18($sp) ; addiu $s0,$s2,0x10 ;
   lw $s1,0x68($s2) ; lq $v0,0x0($s0) ; sq $v0,0x0($sp) ; daddu $a2,$s1,$zero ;
   daddu $a0,$s0,$zero ; jal func_282CC0 ; daddu $a1,$s0,$zero ;
   lwc1 $f0,-0x3A0($gp) ; daddu $a1,$s1,$zero ; lui $at,0x37E9 ;
   ori $at,$at,0x453 ; mtc1 $at,$f12 ; daddu $a0,$s0,$zero ; jal func_2FE880 ;
   mul.s $f12,$f0,$f12 ; daddu $a1,$s0,$zero ; daddu $a0,$sp,$zero ;
   addiu $a2,$zero,0x10 ; daddu $a3,$s2,$zero ; jal func_2761F8 ;
   daddu $t0,$zero,$zero ; beqz $v0,+8 ; addiu $v0,$zero,0x8 ; sb $v0,0x20($s2) ;
   ld $s0,0x10($sp) ; ld $s1,0x18($sp) ; ld $s2,0x20($sp) ; ld $ra,0x28($sp) ;
   jr $ra ; addiu $sp,$sp,0x30.

   Measured near miss: 124 of 148 bytes with the profile
   "-O2 -G8 -ffunction-sections -frac2-qcopy" in a unit of its own
   (src/game/00300618-g8.c).  The frame, the saves in the retail's order, the
   copy, the second and third calls with their arguments, the constant
   0x37E90453 (2.7777778e-05f, the time step), the branch, the store and the
   epilogue all match.

   What is left is the argument setup of the first call, six instructions in
   the wrong places: the retail has `lq ; sq ; daddu $a2,$s1,$zero ;
   daddu $a0,$s0,$zero ; jal ; daddu $a1,$s0,$zero` (the third argument first,
   the second in the delay slot) and this cc1 has `daddu $a0,$s0,$zero ;
   lq ; sq ; daddu $a1,$s0,$zero ; jal ; daddu $a2,$s1,$zero` (the first
   argument hoisted in front of the copy, the third in the delay slot).

   The scheduler picks the wrong one of the three argument moves to hoist:
   with "-fno-schedule-insns2" the order is the retail's up to the two moves
   that are swapped, so the difference is in the reload and in the scheduler's
   ready list, not in the source.  What was tried: the copy before and after
   the first call, the copy as a local initialiser and as a direct assignment,
   the object pointer in a local, the order of the declarations, the
   scheduler flags (-fno-schedule-insns, -fno-schedule-insns2,
   -fsched-spec, -fsched-spec-load, -fsched-interblock,
   -mastra-keep-frame-order, -frac2-zero-ti-barrier); none of them moves the
   first call's argument setup to the retail's place.

   The profile: the `$gp` float needs "-G8" and the small-data attribute, and
   the grouped 16-byte copy (the retail's `lq $v0,0x0($s0) ; sq $v0,0x0($sp)`)
   needs "-frac2-qcopy": without it this cc1 folds the copy's source address
   into the lq (`lq $2,16($s2)`) and puts the store in the delay slot.  The
   constant is at $gp-0x3A0 = 0x001AEC50, the same address in every program. */

#include "common.h"

/* The 128-bit integer mode is what reaches retail's lq/sq copies. */
typedef int TI128 __attribute__((mode(TI)));

extern float D_001AEC50 __attribute__((sda));
extern void func_282CC0(void *a, void *b, void *c);
extern void func_2FE880(void *a, void *b, float c);
extern int func_2761F8(void *a, void *b, int c, int d, int e);

/* Copies the owner's position, asks the vector unit whether it is inside the
   field, and marks the object when it is. */
void func_00307298(void *obj)
{
    void *s2 = obj;
    void *s0 = (char *)s2 + 0x10;
    void *s1 = *(void **)((char *)s2 + 0x68);
    TI128 local;

    *(TI128 *)&local = *(TI128 *)s0;
    func_282CC0(s0, s0, s1);
    func_2FE880(s0, s1, D_001AEC50 * 2.7777778e-05f);
    if (func_2761F8(&local, s0, 0x10, s2, 0) != 0)
        *(unsigned char *)((char *)s2 + 0x20) = 8;
}
