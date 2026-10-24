/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 1072 / 1076 bytes; size equality is not a match.
 * us: 0/1 placements; 1072/1076 bytes.
 * us2: 0/1 placements; 1072/1076 bytes.
 * pal: 0/1 placements; 1072/1076 bytes.
 * Residual: Retail has unused player+0x340 load and mixed GP/absolute reads. Address lifetimes/joins remain; no volatile or alias invented.
 * Reopening condition: New concrete supported compiler/API/identity hypothesis only; see retained source comment. No repeated flag or permutation sweep.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete retained C, 1072/1076 bytes at -O2 -G0 -ffunction-sections.
   Four meaningful trials: persistent base 1012, no-GCSE tie 1012, direct global
   accesses 1072, G8/combined final animation selection 1064. All carrying releases
   remain nonmatching. Retail includes an unused load at player+0x340 and retains
   different address lifetimes, plus both GP and absolute reads of D_001A79F0.
   No invented volatile access or data alias is used to reproduce those effects.
   Reopen with evidence for the original player field contract or supported
   optimization behavior; ordinary clear helper takes two GPRs, animation helper
   takes two GPRs and returns a deliberate integer boolean. */
#include "common.h"

extern u8 D_00189E20[];
extern u8 D_001A7B0B;
extern s32 D_001A79F0;
extern void func_00282A88(void *, s32);
extern float func_00282C48(float);
extern s32 func_L08_002D2ED8(s32, s32);

/* Preserve the selected action while refreshing its transient trigger flags. */
void func_L08_002BE8E8(void)
{
    u8 *player = D_00189E20;
    s16 action = *(s16 *)(player + 0x1490);
    u8 saved = player[0x149D];

    func_00282A88(player + 0x1490, 16);
    *(s16 *)(player + 0x1490) = action;
    player[0x149D] = saved;
    player[0x22B9] = 0;
    *(u16 *)(player + 0x348) = 0;
    if (player[0x22BD] || action == -1)
        return;
    if (action == 2 && *(s16 *)(D_00189E20 + 0x1DE) == 0 &&
        (*(s16 *)(D_00189E20 + 0x34C) == 0 || *(float *)(D_00189E20 + 0x31C) < 2.5f)) {
        D_00189E20[0x1497] = 1;
        if (!D_00189E20[0x22B4] && D_001A7B0B)
            *(u16 *)(D_00189E20 + 0x348) = 1;
    }
    if (action == 14) {
        D_00189E20[0x1494] = 1;
        *(float *)(D_00189E20 + 0x330) = *(float *)(D_00189E20 + 0x318) + 0.2f;
        *(float *)(D_00189E20 + 0x24C4) = 0.2f;
    }
    if (action == 0) {
        float remaining = *(float *)(D_00189E20 + 0x330) - *(float *)(D_00189E20 + 0x318);
        *(float *)(D_00189E20 + 0x24C4) = remaining;
        if (remaining < 0.85f && remaining > 0.25f)
            D_00189E20[0x22B9] = 1;
        D_00189E20[0x1494] = 1;
    }
    if (action == 3)
        D_00189E20[0x1496] = 1;
    if (action == 11)
        D_00189E20[0x149B] = 1;
    if (action == 7)
        D_00189E20[0x1492] = 1;
    if (action == 13)
        D_00189E20[0x149C] = 1;
    if (action == 8)
        D_00189E20[0x149A] = 1;
    if (action == 12)
        D_00189E20[0x149A] = 1;

    if (D_00189E20[0x149C] && *(s32 *)(D_00189E20 + 0x2294) != 0x7C &&
        func_00282C48(*(float *)(D_00189E20 + 0x330) - (*(float *)(D_00189E20 + 0x88) + 0.25f)) < 1.0f &&
        *(float *)(D_00189E20 + 0x330) - *(float *)(D_00189E20 + 0x88) > 0.0f &&
        (*(float *)(D_00189E20 + 0x118) < 0.0f || *(s32 *)(D_00189E20 + 0x2294) == 0x7B)) {
        func_L08_002D2ED8(0x7C, 1);
    } else if (D_00189E20[0x1496] && *(s32 *)(D_00189E20 + 0x2294) != 0x65 &&
        *(s32 *)(D_00189E20 + 0x2294) != 0x78 &&
        func_00282C48(*(float *)(D_00189E20 + 0x334) - (*(float *)(D_00189E20 + 0x88) + 0.25f)) < 1.0f &&
        *(float *)(D_00189E20 + 0x334) - *(float *)(D_00189E20 + 0x88) > 0.0f &&
        (*(s32 *)(D_00189E20 + 0x2294) != 0x66 || D_00189E20[0x49E]) &&
        (*(float *)(D_00189E20 + 0x118) < 0.0f || *(s32 *)(D_00189E20 + 0x2294) == 0x7B)) {
        if (*(s32 *)(D_00189E20 + 0x24CC))
            func_L08_002D2ED8(0x65, 1);
        else
            func_L08_002D2ED8(0x78, 1);
    } else if (D_00189E20[0x149B] && *(s32 *)(D_00189E20 + 0x2294) != 0x78 &&
        *(s32 *)(D_00189E20 + 0x2294) != 0x74 &&
        func_00282C48(*(float *)(D_00189E20 + 0x334) - (*(float *)(D_00189E20 + 0x88) + 0.25f)) < 1.0f &&
        *(float *)(D_00189E20 + 0x334) - *(float *)(D_00189E20 + 0x88) > 0.0f &&
        (*(float *)(D_00189E20 + 0x118) < 0.0f || *(s32 *)(D_00189E20 + 0x2294) == 0x7B)) {
        if (D_001A79F0 != 13)
            func_L08_002D2ED8(0x78, 1);
        else
            func_L08_002D2ED8(0x74, 1);
    }
}
