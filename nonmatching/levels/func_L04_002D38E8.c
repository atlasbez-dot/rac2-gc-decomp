/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: default -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 576 / 624 bytes; size equality is not a match.
 * us: 0/1 placements; 576/624 bytes.
 * us2: not run / not reported.
 * pal: not run / not reported.
 * Residual: 576 vs624 bytes; 0/1 US placement, differing base lifetimes, unused retail read and register allocation.
 * Reopening condition: Qualify actual global declarations and compiler base-lifetime mechanism.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Manual reconstruction. Default -O2 -G0 profile: 576 bytes versus retail 624,
   0/1 US placement (trial1.log, private). Retail reloads the resident base in
   each state block and retains an unused word read at +0x340. Do not invent
   volatile semantics to reproduce that read. Reopen after the original global
   declaration and compiler base-address lifetime mechanism are qualified. */
#include "include_asm.h"

extern unsigned char D_00189E20[];
extern unsigned char D_001A7B0B;
extern void func_00282A88(void *, int);
extern float func_00282C48(float);
extern void func_L04_002E7C08(int, int);

void func_L04_002D38E8(void)
{
    unsigned char *hero = D_00189E20;
    short state = *(short *)(hero + 0x1490);
    unsigned char saved = hero[0x149d];
    func_00282A88(hero + 0x1490, 16);
    hero[0x149d] = saved;
    *(short *)(hero + 0x1490) = state;
    hero[0x22b9] = 0;
    *(short *)(hero + 0x348) = 0;
    if (hero[0x22bd] || state == -1)
        return;
    if (state == 2 && *(short *)(hero + 0x1de) == 0 &&
        (*(short *)(hero + 0x34c) == 0 || *(float *)(hero + 0x31c) < 2.5f)) {
        hero[0x1497] = 1;
        if (hero[0x22b4] == 0 && D_001A7B0B)
            *(short *)(hero + 0x348) = 1;
    }
    if (state == 14) {
        hero[0x1494] = 1;
        *(float *)(hero + 0x330) = *(float *)(hero + 0x318) + 0.2f;
        *(float *)(hero + 0x24c4) = 0.2f;
    }
    if (state == 0) {
        float remaining = *(float *)(hero + 0x330) - *(float *)(hero + 0x318);
        *(float *)(hero + 0x24c4) = remaining;
        if (remaining < 0.85f && remaining > 0.25f)
            hero[0x22b9] = 1;
        hero[0x1494] = 1;
    }
    if (state == 7) hero[0x1492] = 1;
    if (state == 13) hero[0x149c] = 1;
    if (state == 8) hero[0x149a] = 1;
    if (state == 12) hero[0x149a] = 1;
    if (hero[0x149c] && *(int *)(hero + 0x2294) != 124 &&
        func_00282C48(*(float *)(hero + 0x330) - (*(float *)(hero + 0x88) + 0.25f)) < 1.0f &&
        *(float *)(hero + 0x330) - *(float *)(hero + 0x88) > 0.0f &&
        (*(float *)(hero + 0x118) < 0.0f || *(int *)(hero + 0x2294) == 123))
        func_L04_002E7C08(124, 1);
}
