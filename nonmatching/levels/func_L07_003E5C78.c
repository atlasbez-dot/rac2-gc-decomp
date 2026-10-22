/* func_L07_003E5C78 (260 bytes, level 07_siberius) -- NEAR MISS, not integrated.
   state: 260 bytes, the retail's size; 58 of 65 words are identical. The two
   copies of 16 bytes, the frame, the five callee-saved registers, the branch
   and the three calls are the retail's; what is left is the slot of one load.

   The file must build with the grouped-quadword copy, i.e.
     src/levels/07_siberius/L07_003E5C78-rc2.c  -O2 -G0 -ffunction-sections -frac2-qcopy
   because the retail's two 16-byte copies are the grouped `lq $v0,0($sN) ;
   sq $v0,0($aN)` pair with the address in a register; without -frac2-qcopy
   this cc1 folds the destination offset into the `sq` and the words differ
   from the first copy on.  With the flag the copy is exact.

   check.py (07_siberius), with the source below:
     003E5CC0  addiu $a2, $zero, 0x4     |  lw $s0, 0x68($s1)
     003E5CD0  lw $s0, 0x68($s1)         |  sh $v0, 0x34($s1)
   Retail loads the state pointer (arg+0x68) before the call to func_002A7750
   and keeps the flags store in the call's delay slot; this cc1 sinks the load
   to its first use (after the call) and leaves the flags store after the
   call.  The load's slot is what is left.

   What is measured and right:
   - the state pointer and the loop pointer are one variable: the retail has
     $s0 = *(arg+0x68) for the two copies and then $s0 = arg+0xC0 for the
     loop, in the same register, and the loop counter reuses $s2 (the third
     argument's dead register);
   - the second flag update (|= 0x100) and the loop's pointer assignment sit
     AFTER the `if (a3 != 0)` block: the retail's branch to +0xB lands on the
     flag read, not on the loop;
   - the callee-saved order is the retail's: $s0 = state, $s1 = arg,
     $s2 = the fourth argument, $s3 = the third, $s4 = the second.  It comes
     out of the source only with -fno-schedule-insns or with the source
     below; the plain spelling puts the second argument first ($s0) and the
     state pointer second;
   - the flags read-modify-write must not live across the call: written as
     one statement the value stays in $v0 and the store goes into the call's
     delay slot; written as a separate variable it needs a saved register and
     the body grows by 4 bytes.

   Tried and not enough: the state load before, between and after the flag
   statements and the call (it always sinks to its first use); the two copies
   in both orders; the copy destinations as pointer variables; the flag
   update split into a read and a store; -fno-schedule-insns, -fno-schedule-insns2,
   -fno-gcse, -fno-strength-reduce, -mastra-keep-frame-order (the last one
   changes the prologue's save order but not the load's slot). */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750(int, int, int);

extern void func_00282CF0(void *, void *, void *);

extern void func_002AFDD8(char *, char *, char *, char *);

extern void func_00282F20(void *, void *, float);

void func_L07_003E5C78(char *arg, char *a1, char *a2, char *a3)
{
    char *s0;
    unsigned short v;
    int i;

    if (*(unsigned char *)(arg + 0x20) != 8)
        return;

    *(unsigned short *)(arg + 0x34) = (*(unsigned short *)(arg + 0x34) & 0xFFBE) | 0x1000;
    *(int *)(arg + 0x98) = 0;
    func_002A7750(arg, 9, 4);

    s0 = *(char **)(arg + 0x68);
    *(TI128 *)(arg + 0x10) = *(TI128 *)a1;
    *(TI128 *)(s0 + 0x230) = *(TI128 *)a2;
    *(int *)(s0 + 0x260) = (int)a3;
    *(unsigned char *)(arg + 0x7F) = 0;

    if (a3 != 0) {
        func_00282CF0(s0 + 0x220, a2, a3 + 0x10);
        func_002AFDD8(a3, s0 + 0x220, s0 + 0x220, 0);
    }
    v = *(unsigned short *)(arg + 0x34);
    s0 = arg + 0xC0;
    i = 2;
    *(unsigned short *)(arg + 0x34) = v | 0x100;
    do {
        func_00282F20(s0, s0, 0.1f);
        s0 += 0x10;
        i--;
    } while (i >= 0);
}
