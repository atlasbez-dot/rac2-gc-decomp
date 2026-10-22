/* func_L14_004221D8 (428 bytes, 1 place: 14:004221D8) -- NEAR MISS, not integrated.
   state: the size is retail's (428 bytes) and 35 of 107 words are byte-identical, but the
   remaining 72 differ only in the schedule and the register allocation: the same
   instructions, in another order or another register.  The frame (0x30), the four saved
   registers ($s0 = state+0x10, $s1 = state, $s2 = the object, $ra), the float block, the
   VU0 call, both 16-byte copies and the whole tail are retail's.

   Profile (the file must be built with it; the C is not in src/):
     src/levels/14_aranos_prison/L14_003F4F98-qcopy.c
       -O2 -G8 -ffunction-sections -frac2-qcopy
   -G8 is not optional: the five globals (0x1B1618, 0x1B1680..0x1B168C) are read and written
   through $gp in retail (sw $v1,0x2628($gp) etc.); at -G0 cc1 emits no `.extern` for them at
   all and they come out absolute (lui $at,%hi / lw $v0,%lo($at)).
   -frac2-qcopy is what reaches retail's copy shape: without it this cc1 folds the TI
   offsets into the lq/sq operands (`lq $v0,0x10($s1)`); with it the addresses are
   materialised in registers and the copies have zero offset (`addiu $s0,$s1,0x10 ;
   lq $v0,0($s1) ; sq $v0,0($s0)`), which is the wall several other rows record
   (func_L00_00333F90, func_L00_00423290, func_L02_003C4848, func_L02_003CED70).
   -mno-split-addresses was measured: no effect on this body.

   The 16-byte copy to the caller's stack (lq $v0,0($s0) ; sq $v0,0($sp), then the call to
   func_L11_0046BC08 with only $a0 set) is the one construct with no plain spelling: this
   cc1 passes a 16-byte aggregate in a register pair (lq $5,16($5)) or by reference
   (addu $5,$5,16), and a plain local is dead after the assignment.  Measured here: a
   volatile TI128 local gives the retail pair but lands in its own frame slot (0x40 frame);
   one union holding both the 12-byte {int,float,int} argument and the TI128 gives retail's
   0x30 frame and the zero-offset copy, with the copy written through a volatile lvalue
   (*(volatile TI128 *)&buf = *(TI128 *)s0).  The union's field stores stay non-volatile, so
   retail's `swc1 $f0,0x4($sp)` still sinks into the VU0 call's delay slot.

   What is left, in retail's order (the candidate's is in brackets):
   - the prologue: retail materialises the 6.0f constant (lui $at,0x40C0 ; mtc1 $at,$f0)
     after the two copies and leaves the frame's delay slot a nop; this cc1 hoists the
     constant into the frame's delay slot [lui $at,0x40C0 at +0x4].  Retail also saves
     $s2 before $s0 and copies the object (daddu $s2,$a0,$zero) in the middle of the saves.
   - the shared call: retail keeps D_L14_001B1618 = 20 in the jal's delay slot and the
     `daddu $a0,$s2,$zero` before it; this cc1 does the opposite.
   - the copy loop: same shape (the test at the top with the table load in the branch's
     delay slot, the reload of s1->0x38 inside the body, the i++ and the two += 16 in the
     latch), but the pre-loop part is in another order (retail computes the table pointer
     before the test, this cc1 in the delay slot), retail computes the destination as
     (s1->0x38 * 640 + 0x2594F0) + i*16 while this cc1 groups it as
     (s1->0x38 * 640 + i*16) + 0x2594F0, retail computes i*16 once and this cc1 twice, and
     retail keeps the destination's induction variable (addiu $a1,$a1,0x10 in the back
     edge's delay slot) that this cc1 drops.
   - the tail: retail loads the five globals first (lw $v0,0x2628($gp) ; lw $a0,0x2690($gp) ;
     lw $a1,0x2694($gp) ; lwc1 $f0,0x2698($gp) ; lwc1 $f1,0x269C($gp)) and then stores the
     six words; this cc1 interleaves each load with its store.  Reading the five globals
     into named locals first was measured: the compiler then keeps them in $s0..$s4 and
   -f20/$f21 and the frame grows to 0x50.

   The function is not a catalogue fragment: it has its own entry, a jr $ra and one place.

   Checked with tools/check.py func_L14_004221D8 --diff (level 14): the candidate is 428
   bytes, the same size as retail, and the first difference is the word at +0x4. */

#include "include_asm.h"

/* The 128-bit unit the copies move. */
typedef int TI128 __attribute__((mode(TI)));

extern void func_00282CC0_6(void *out, void *in1, void *in2);

extern void func_L11_0046BC08(void *self);

extern void func_L14_00422498(void *self);

extern void func_L00_002E6EF8(void *self, void *other);

extern void func_L14_004228C0(char *object);

extern int func_00291308(void *a, int b, float c, float d);

extern int D_L14_001B1618 __attribute__((sda));
extern int D_L14_001B1680 __attribute__((sda));
extern int D_L14_001B1684 __attribute__((sda));
extern float D_L14_001B1688 __attribute__((sda));
extern float D_L14_001B168C __attribute__((sda));

extern int D_001FE1C0[];
extern char D_002594F0[];

typedef struct {
    int x;
    float y;
    int z;
} L14Vec;

/* The vector the state block holds, and the one the level's pulse adds to it. */
typedef union {
    TI128 q;
    L14Vec v;
} L14Buf;

/* Copies the owner's vector into its state block, eases the state's pulse, adds the pulse to
   the vector, then refreshes the group's live class-0x112B entities and resets the owner. */
void func_L14_004221D8(char *self)
{
    char *s2 = self;
    char *s1;
    char *s0;
    L14Buf buf;
    float f1;
    float f0;
    int count;
    int i;
    int *table;

    s1 = *(char **)(s2 + 0x68);
    s0 = s1 + 0x10;
    *(TI128 *)s1 = *(TI128 *)(s2 + 0x10);
    *(TI128 *)s0 = *(TI128 *)s1;

    f1 = *(float *)(s1 + 0x20);
    f0 = (6.0f - f1) * 0.07f + 12.0f;
    f1 = f1 + f0;
    *(float *)(s1 + 0x20) = f1;

    buf.v.x = 0;
    buf.v.y = *(float *)(s1 + 0x20);
    buf.v.z = 0;
    func_00282CC0_6(s0, s1, &buf.v);

    *(volatile TI128 *)&buf = *(TI128 *)s0;
    D_L14_001B1618 = 20;
    func_L11_0046BC08(s2);

    if (*(int *)(s1 + 0x3C) != 0) {
        func_L14_00422498(s2);
        count = D_L14_001B1618;
        i = count - 4;
        table = &D_001FE1C0[*(int *)(s1 + 0x34)];
        while (i < count) {
            *(TI128 *)((char *)(*(int *)(s1 + 0x38) * 640 + (int)D_002594F0) + i * 16) =
                *(TI128 *)(*(int *)table + i * 16 + 0x10);
            i++;
        }
        func_L00_002E6EF8((void *)func_L14_004228C0, s2);
    }

    if (*(unsigned char *)(s2 + 0x20) == 0) {
        *(int *)(s1 + 0x3C) = 0;
        *(int *)(s1 + 0x24) = func_00291308(s1, 0, 0.0f, 0.0f);
        *(unsigned char *)(s2 + 0x20) = 1;
        *(int *)(s1 + 0x30) = -1;
        *(int *)(s1 + 0x2C) = D_L14_001B1618;
        *(int *)(s1 + 0x48) = D_L14_001B1680;
        *(int *)(s1 + 0x4C) = D_L14_001B1684;
        *(float *)(s1 + 0x40) = D_L14_001B1688;
        *(float *)(s1 + 0x44) = D_L14_001B168C;
    }
}
