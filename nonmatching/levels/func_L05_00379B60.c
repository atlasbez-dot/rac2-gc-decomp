/* 2026-10-23 reconstruction. Measured with -O2 -G8 -ffunction-sections. us: 0/4 placements;
   05_feltzin_system: instruction at +0x4 differs; us2: 0/4 placements; 05_feltzin_system: instruction
   at +0x4 differs; pal: 0/4 placements; 05_feltzin_system: instruction at +0x4 differs. Four
   meaningful trials. Separate selection and callback-state lifetimes recover retail size; remaining
   initial absolute load scheduling, register allocation and selected-index branch layout differ.
   Reopen with an exact witness for the selection loop. Historical screening is preserved below. */

/* func_L05_00379B60 - 260 bytes, 4 place(s), level 05_feltzin_system,
   retail at 0x00379b60. Screened with tools/w10_screen.py: 4 call(s)
   [func_L05_00379968@00379B8C, func_002A7820@00379BBC,
   func_L05_0037B3A0@00379BF4, func_L00_002E6EF8@00379C3C]; data addresses
   materialised [0x1b0000, 0x220000, 0x220000, 0x380000]; float constants
   [-]; $gp-relative small data: yes   saves: -; callee-saved registers
   saved [-]; words plain C cannot emit [-]. Head: lui $v0, 0x1B ; lw $v0,
   0x2048($v0) ; addiu $sp, $sp, -0x30 ; sd $s0, 0x0($sp) ; sd $s1, 0x8($sp)
   ; slti $v0, $v0, 0xA. Not matched in this wave: the body is straight-line
   code whose register allocation and the materialisation of its constant
   addresses have to be reproduced word for word. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */

#include "common.h"
extern int D_L05_001B2048 NOT_SDA;
extern int D_L05_00221D10[];
extern void *D_L05_00225DD0[];
extern int D_L05_001AC4D8 __attribute__((sda));
extern int D_L05_001AC4DC __attribute__((sda));
extern void func_L05_00379968(void);
extern int func_002A7820(int,int);
extern int func_L05_0037B3A0(void *);
extern void func_L05_0037A218(void *);
extern void func_L00_002E6EF8(void (*)(void *),void *);
void func_L05_00379B60(void)
{
    int found;
    int *state,*selection;
    if (D_L05_001B2048 < 10) func_L05_00379968();
    selection = D_L05_00221D10;
    if (selection[0x84/4] == 0) {
        if (D_L05_001AC4D8 < 2) D_L05_001AC4DC = 0;
        else {
            D_L05_001AC4DC = func_002A7820(0,D_L05_001AC4D8-1);
            found = 0;
            while (!found) {
                if (selection[0x10/4] == 0) found = 1;
                if (func_L05_0037B3A0(D_L05_00225DD0[D_L05_001AC4DC])) found = 1;
                if (!found) {
                    D_L05_001AC4DC++;
                    if (D_L05_001AC4DC >= D_L05_001AC4D8) D_L05_001AC4DC = 0;
                }
            }
        }
    }
    state = D_L05_00221D10;
    *(unsigned short *)((char *)state+0x40) = 0;
    *(unsigned short *)((char *)state+0x42) = 0;
    if (state[0x78/4]) func_L00_002E6EF8(func_L05_0037A218,(void *)state[0x78/4]);
}
