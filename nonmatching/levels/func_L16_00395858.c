/* Bounded manual reconstruction, 2026-10-23; not linked.
 * Profile: -O2 -G0 -ffunction-sections.
 * us: func_L16_00395858: 0 of 2 places match (src/levels/shared/L16_00395858-state.c); us2: func_L16_00395858: 0 of 2 places match (src/levels/shared/L16_00395858-state.c); pal: func_L16_00395858 is in neither catalogue of pal
 * 328/348 bytes; resident-object address materialization and the state-condition merge differ. Tried a direct state chain preserving each visible read. Reopen with the original resident object layout and condition grouping.
 * Historical screening note below predates this C reconstruction.
 */
/* func_L16_00395858 - 348 bytes, 2 place(s), level 16_snivelak, retail at
   0x00395858. Screened with tools/w10_screen.py: 2 call(s)
   [func_L00_002D2168@0039594C, func_L00_002D2168@003959A0]; data addresses
   materialised [0x190000, 0x3d4c0000, 0x3d4c0000]; float constants
   [0x40e00000, 0x41200000, 0x41200000, 0x41200000, 0x41200000]; $gp-
   relative small data: no   saves: -; callee-saved registers saved [-];
   words plain C cannot emit [-]. Head: lui $v1, 0x19 ; addiu $sp, $sp,
   -0x10 ; sd $ra, 0x0($sp) ; daddu $a3, $v1, $zero ; addiu $v1, $v1,
   -0x61E0 ; lw $v0, 0xC28($v1). Not matched in this wave: the body is
   straight-line code whose register allocation and the materialisation of
   its constant addresses have to be reproduced word for word. What would
   unblock it: the exact source expression tree, so this cc1 picks the same
   registers in the same order. */

#include "common.h"
extern char D_00189E20[];
extern void func_L00_002D2168(int,int,float);
void func_L16_00395858(char *object)
{
    char *state=*(char **)(object+0x68);
    if ((*(int *)(D_00189E20+0xc28)&2) && *(unsigned char *)(*(char **)(D_00189E20+0x2290)+0x43)==0x44)
        func_L00_002D2168(0x3f,0,7.0f);
    else if (*(unsigned char *)(*(char **)(D_00189E20+0x2290)+0x43)==0x3f && *(float *)(state+0x30)!=0.0f)
        func_L00_002D2168(0x40,0,10.0f);
    else if (*(unsigned char *)(*(char **)(D_00189E20+0x2290)+0x43)==0x40) {
        if (*(float *)(state+0x30)>0.05000000447f) func_L00_002D2168(0x41,0,10.0f);
        else if (*(float *)(state+0x30)==0.0f) func_L00_002D2168(0x3f,0,10.0f);
    } else if (*(unsigned char *)(*(char **)(D_00189E20+0x2290)+0x43)==0x41 && *(float *)(state+0x30)<0.05000000447f)
        func_L00_002D2168(0x40,0,10.0f);
}
