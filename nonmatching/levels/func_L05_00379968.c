/* 2026-10-23 reconstruction. Measured with -O2 -G0 -ffunction-sections -fno-gcse -mno-split-addresses.
   us: 0/4 placements; 05_feltzin_system: 456 bytes, expected 504; us2: 0/4 placements;
   05_feltzin_system: 456 bytes, expected 504; pal: 0/4 placements; 05_feltzin_system: 456 bytes,
   expected 504. Four meaningful profiles: default436, no-split404, no-GCSE460, combined456 versus
   retail504 bytes. Retained combined profile has the correct initial absolute-load form; repeated
   global loads and state-base scheduling still differ. Reopen with a matching initialization-table
   witness. Historical screening is preserved below. */

/* func_L05_00379968 - 504 bytes, 4 place(s), level 05_feltzin_system,
   retail at 0x00379968. Screened with tools/w10_screen.py: 0 call(s) [-];
   data addresses materialised [0x1a0000, 0x2a0000, 0x1a0000, 0x1a0000,
   0x1a0000, 0x1a0000, 0x1a0000, 0x1a0000]; float constants [0x1a0000]; $gp-
   relative small data: no   saves: -; callee-saved registers saved [-];
   words plain C cannot emit [-]. Head: lui $v0, 0x1A ; lw $v0, 0x7AF0($v0)
   ; andi $v0, $v0, 0x40 ; beqz $v0, . + 4 + (0x8 << 2) ; lui $v0, 0x2A ;
   addiu $a0, $zero, 0x1. Not matched in this wave: the body is straight-
   line code whose register allocation and the materialisation of its
   constant addresses have to be reproduced word for word. What would
   unblock it: the exact source expression tree, so this cc1 picks the same
   registers in the same order. */

extern int D_001A7AF0;
extern int D_L05_002A1800[];

void func_L05_00379968(void)
{
    int *state = D_L05_002A1800;
    if (D_001A7AF0 & 0x40) {
        state[0x140/4] = 1;
        state[0x158/4] = 1;
        state[0] = 0;
    } else {
        state[0] = 1;
        state[0x140/4] = 0;
    }
    state[0x18/4] = 1;
    if (D_001A7AF0 & 0x100) {
        state[0x90/4] = 1;
        state[0x1D0/4] = 1;
    } else {
        if (D_001A7AF0 & 0x80) state[0x90/4] = 1;
        else state[0x90/4] = 0;
        state[0x1D0/4] = 0;
    }
    state[0x78/4] = 0;
    state[0x1B8/4] = 0;
    if (D_001A7AF0 & 0x200) {
        state[0x28/4] = 0;
        state[0x168/4] = 1;
        state[0x180/4] = 1;
    } else {
        state[0x168/4] = 0;
        state[0x28/4] = 1;
    }
    state[0x40/4] = 1;
    if (D_001A7AF0 & 0x800) {
        state[0x68/4] = 1;
        state[0x1A8/4] = 1;
    } else {
        if (D_001A7AF0 & 0x400) state[0x68/4] = 1;
        else state[0x68/4] = 0;
        state[0x1A8/4] = 0;
    }
    state[0x50/4] = 0;
    state[0x190/4] = 0;
    if (D_001A7AF0 & 0x1000) state[0xB8/4] = 1;
    else state[0xB8/4] = 0;
    state[0xA0/4] = 0;
    if (D_001A7AF0 & 0x2000) state[0xE0/4] = 1;
    else state[0xE0/4] = 0;
    state[0xC8/4] = 0;
    if (D_001A7AF0 & 0x8000) {
        state[0x1E0/4] = 0;
        state[0x1F8/4] = 1;
        state[0x230/4] = 1;
        state[0xF0/4] = 0;
        state[0x248/4] = 1;
    } else if (D_001A7AF0 & 0x4000) {
        state[0x230/4] = 0;
        state[0x1F8/4] = 1;
        state[0x1E0/4] = 1;
        state[0xF0/4] = 0;
    } else {
        state[0x1F8/4] = 0;
        state[0xF0/4] = 1;
        state[0x230/4] = 0;
        state[0x1E0/4] = 0;
        state[0x248/4] = 0;
    }
    state[0x108/4] = 1;
    if (D_001A7AF0 & 0x10) {
        state[0x208/4] = 1;
        state[0x118/4] = 0;
        state[0x220/4] = 1;
    } else {
        state[0x118/4] = 1;
        state[0x208/4] = 0;
    }
    state[0x130/4] = 1;
}
