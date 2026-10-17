/* 0 of 1 places match - candidate is 92 bytes, retail 96. File:
   src/levels/02_maktar_nebula/L02_002ED7B0-g8.c (-O2 -G8 -ffunction-sections).
   Everything matches except the two scheduling decisions around the guard:
     +0xB0 mine beqz $v0,->end + lui in the delay slot | retail beql $v0,$zero,->end
                                                          + the epilogue restore in it
     +0xC0 mine lui $v0,%hi(D_001B00A4) ; lw $a1,%lo($v0) | retail lui $a1,%hi(D_001B00A4)
                                                            ; lw $a1,%lo($a1)
   i.e. retail takes the branch-likely form (delay slot filled from the target, which
   duplicates the epilogue restore - one extra instruction), and materialises the
   absolute address into the ARGUMENT register that receives the value. This cc1 fills
   the delay slot from the fall-through and uses a scratch base register. Same residue
   as the register-pair/rematerialisation walls. $gp member reached correctly with
   `extern int X __attribute__((sda));` and the absolute member with
   `extern unsigned int X __attribute__((nosda));` (no `&`, the retail loads the VALUE). */

#include "include_asm.h"

typedef unsigned int u32;
typedef short s16;

extern int D_L02_gp10B0 __attribute__((sda));
extern unsigned int D_001B00A4 __attribute__((nosda));

extern int func_002F1BE0(void *);
extern s16 func_0031E7B0(int, unsigned int);
extern void func_00366B30(int, int, void *);

void func_L02_003CB090(char *a0) {
    char *s0 = *(char **)(a0 + 0x68);

    if (func_002F1BE0(s0 + 0x3B4) != 0) {
        *(s16 *)(s0 + 0x3B4) = func_0031E7B0(D_L02_gp10B0, D_001B00A4);
        func_00366B30(1, 0, a0);
    }
}
