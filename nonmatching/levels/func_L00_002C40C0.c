/* 544/544 bytes, first difference +0x8 in all three releases. The list walk, score filters, visibility probe and copies are reconstructed. A cached mode pointer and direct containing-object fields recover the target size, but address lifetimes and saved-register allocation differ from the entry block. Disabling GCSE measured 540 bytes and did not recover the frame. Reopen with a solved analogous mode-pointer lifetime; no assembly classification is justified.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * us: instruction at +0x8 differs; 0/25 placements
 * pal: instruction at +0x8 differs; 0/25 placements
 * us2: instruction at +0x8 differs; 0/25 placements
 */
#include "include_asm.h"
typedef int Vector __attribute__((mode(TI)));
typedef struct {
    unsigned char pad0[0x80]; float position[4];
    unsigned char pad1[8]; float heading;
    unsigned char pad2[0x64C - 0x9C]; float alternate_heading;
    unsigned char pad3[0xAA4 - 0x650]; void *selected_aa4; int ready_aa8;
    unsigned char pad4[12]; int value_ab8;
    unsigned char pad5[4]; int value_ac0; float score_ac4;
    unsigned char pad6[8]; void *selected_ad0;
    unsigned char pad7[4]; float score_ad8;
    unsigned char pad8[2]; short ready_ade;
    unsigned char pad9[0xB10 - 0xAE0]; void *selected_b10; int ready_b14;
    unsigned char pad10[0x2294 - 0xB18]; int mode, field_2298, state;
} HeroSelectionState;
extern HeroSelectionState D_00189E20;

extern unsigned char *D_L00_001B1EA8 __attribute__((sda));
extern int func_002B38B8(void *);
extern float func_L00_002AE388(void *, int *, float, float, float, float);
extern float func_00282E80(void *, void *);
extern int func_002761F8(void *, void *, int, void *, int);

int func_L00_002C40C0(void)
{
    unsigned char *node, *best;
    float score, closest;
    float first[4], second[4];
    int blocked[4];
    if (D_00189E20.state == 0x21) return D_00189E20.ready_b14;
    {
    best = 0;
    closest = 100000000.0f;
    D_00189E20.ready_b14 = 0;
    node = D_L00_001B1EA8;
    if (node) {
    HeroSelectionState *modes = &D_00189E20;
    do {
        float horizontal, vertical, heading;
        if (*(short *)(node + 0xAA) != 0x99D) continue;
        if (*(unsigned short *)(node + 0x34) & 1) continue;
        if (func_002B38B8(node)) continue;
        horizontal = 0.5235988497734069824f;
        vertical = -1.0f;
        if (modes->mode == 1 || modes->mode == 0x1D)
            horizontal = vertical = 0.087266474962234497f;
        heading = D_00189E20.heading;
        if (D_00189E20.state == 0xF)
            heading = D_00189E20.alternate_heading;
        score = func_L00_002AE388(node, blocked, heading, 30.0f, horizontal, vertical);
        if (blocked[0] != 0) continue;
        if (func_00282E80(D_00189E20.position, node + 0x10) < 4.0f) continue;
        if ((unsigned char)node[0x31] == 0) score += 10.0f;
        if (score < closest) { closest = score; best = node; }
    } while ((node = *(unsigned char **)(node + 0x28)) != 0);
    }
    if (best) {
        D_00189E20.selected_b10 = best;
        *(Vector *)first = *(Vector *)(D_00189E20.position);
        first[2] += 0.5f;
        *(Vector *)second = *(Vector *)(best + 0x10);
        if (!func_002761F8(first, second, 2, 0, 0))
            D_00189E20.ready_b14 = 1;
    }
    }
    return D_00189E20.ready_b14;
}
