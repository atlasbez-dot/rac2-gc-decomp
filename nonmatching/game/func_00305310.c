/* func_00305310 - 248 bytes, 1 place (the boot), retail at 0x00305310:
   addiu $sp,$sp,-0xB0 ; sd $s1,0x78($sp) ; sd $s2,0x80($sp) ; sd $s3,0x88($sp) ;
   daddu $s2,$a0,$zero ; sd $s4,0x90($sp) ; sd $s0,0x70($sp) ; daddu $s4,$a1,$zero ;
   sd $ra,0x98($sp) ; swc1 $f20,0xA0($sp) ; lw $v0,0x68($s2) ; jal func_2FEC50 ;
   lw $a0,0x48($v0) ; daddu $s3,$v0,$zero ; addiu $s1,$sp,0x30 ; lq $v0,0x0($s4) ;
   sq $v0,0x0($s1) ; lq $v0,0x0($s1) ; sq $v0,0x0($sp) ; por $v0,$zero,$zero ;
   lui $at,0x3F80 ; mtc1 $at,$f20 ; addiu $s0,$sp,0x10 ; sq $v0,0x40($sp) ;
   daddu $a1,$sp,$zero ; addiu $a2,$sp,0x40 ; swc1 $f20,0x48($sp) ; jal func_282DD8 ;
   daddu $a0,$s0,$zero ; mov.s $f12,$f20 ; daddu $a0,$s0,$zero ; jal func_282F20 ;
   daddu $a1,$s0,$zero ; addiu $a0,$sp,0x20 ; daddu $a2,$sp,$zero ; jal func_282DD8 ;
   daddu $a1,$s0,$zero ; daddu $a1,$sp,$zero ; jal func_2AB600 ; addiu $a0,$s3,0x10 ;
   addiu $s0,$sp,0x50 ; daddu $a0,$s2,$zero ; daddu $a2,$s0,$zero ; jal func_29FCC0 ;
   daddu $a1,$zero,$zero ; daddu $a1,$s4,$zero ; addiu $a2,$s2,0xC0 ; jal func_283098 ;
   daddu $a0,$s1,$zero ; daddu $a1,$s1,$zero ; daddu $a2,$s0,$zero ; jal func_282CC0 ;
   addiu $a0,sp,0x60 ; ld $s0,0x70($sp) ; ld $s1,0x78($sp) ; ld $s2,0x80($sp) ;
   ld $s3,0x88($sp) ; ld $s4,0x90($sp) ; ld $ra,0x98($sp) ; lwc1 $f20,0xA0($sp) ;
   jr $ra ; addiu $sp,$sp,0xB0.

   func_00307AD0 (0x00307AD0, 248 bytes) is the same body word for word, at
   another address; the same source and the same differences apply to it.

   Measured near miss: 240 of 248 bytes with the default profile
   ("-O2 -G0 -ffunction-sections").  The frame (0xB0), the seven 16-byte stack
   slots (0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60), the copy of the 16 bytes
   of the "out" buffer, the {0, 0, 1.0f, 0} vector with its `por` and its
   `swc1`, the seven calls with their arguments, the constant 1.0f in $f20 and
   the epilogue all match.

   What is left:

   1. The copy is two steps in the retail and one in the candidate.  The retail
      stores the buffer into the slot at 0x30 and then reads that slot back to
      store it into the slot at 0x00 (`lq $v0,0x0($s1) ; sq $v0,0x0($sp)`);
      this compiler forwards the second copy and stores the loaded value into
      both slots.  Every spelling tried (a pointer to the slot, a temporary
      with the value, the slots as TI128 objects, as float[4] arrays, as a
      union and as a struct) is forwarded, so the retail's compiler simply
      kept a copy that this one removes.

   2. The registers of the frame differ, and with them the order of the
      prologue.  The retail uses s0 for the address of the first buffer, s1 for
      the address of the slot at 0x30, s2 for the owner, s3 for the child's
      pointer and s4 for "out", and saves them in the order s1, s2, s3, s4, s0,
      ra with the two `daddu` moves in between.  The candidate gives s1 to the
      owner, s2 to the child, s3 to "out" and s4 to the address of the slot at
      0x50, and saves s0, s1, s3, s4, ra, s2.  The retail also loads the
      child's pointer into $v0 and moves it to $s3 after the call, where the
      candidate loads it straight into the callee-saved register.

   3. The order of the first call's arguments: the retail sets a1 and a2
      before the constant, the candidate sets a2 and a1 in the other order.

   What was tried: the seven slots as TI128 objects and as float[4] arrays
   (the arrays are what put the {0, 0, 1.0f, 0} vector in the slot at 0x40 and
   give the `por`); the zero as a TI128 variable initialised to 0 and stored
   (`TI128 zero = 0; *(TI128 *)loc40 = zero;`, which is what the matched
   func_L00_003ACC88 in src/levels/shared/L00_003A8E28-g8.c does) instead of
   a plain assignment (which gives `sq $zero`); the copy through a pointer
   variable, through a temporary, and with the two slots of different types;
   the order of the statements; the flags "-frac2-qcopy",
   "-frac2-zero-ti-barrier" and "-fno-schedule-insns2".
   The measured values: the constant 1.0f (0x3F800000); the vector
   {0, 0, 1.0f, 0} is the third float of the slot at 0x40; the owner is the
   first argument, "out" the second. */

#include "common.h"

/* The 128-bit integer mode is what reaches retail's lq/sq copies. */
typedef int TI128 __attribute__((mode(TI)));

extern void func_002FEC50(void *);
extern void func_002AB600(void *, void *);
extern void func_00283098(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_0029FCC0(void *, int, void *);

/* Builds the owner's new position out of the old one. */
void func_00305310(void *owner, void *out)
{
    float loc00[4];
    float loc10[4];
    float loc20[4];
    float loc30[4];
    float loc40[4];
    float loc50[4];
    float loc60[4];
    float *p30;
    TI128 zero = 0;
    void *child;

    child = *(void **)((char *)owner + 0x68);
    func_002FEC50(*(void **)((char *)child + 0x48));

    *(TI128 *)loc30 = *(TI128 *)out;
    p30 = loc30;
    *(TI128 *)loc00 = *(TI128 *)p30;

    *(TI128 *)loc40 = zero;
    loc40[2] = 1.0f;

    func_00282DD8((void *)loc10, (void *)loc00, (void *)loc40);
    func_00282F20((void *)loc10, (void *)loc10, 1.0f);
    func_00282DD8((void *)loc20, (void *)loc10, (void *)loc00);
    func_002AB600((char *)child + 0x10, (void *)loc00);
    func_0029FCC0(owner, 0, (void *)loc50);
    func_00283098((void *)loc30, out, (char *)owner + 0xC0);
    func_00282CC0((void *)loc60, (void *)loc30, (void *)loc50);
}
