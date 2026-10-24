/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 736 / 1504 bytes; size equality is not a match.
 * us: 0/1 placements; 736/1504 bytes.
 * us2: 0/1 placements; 736/1504 bytes.
 * pal: 0/1 placements; 736/1504 bytes.
 * Residual: Three tagged visibility walks are expressed as one group loop; original walks were expanded. Reopen by restoring individual walk lifetimes.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Manual reconstruction, 2026-10-23: NOT MATCHED. US 736/1504 bytes,
 * 0/1 placements; profile: -O2 -ffunction-sections default O2/G0.
 * Three tagged visibility walks are expressed as one group loop; original walks were expanded. Reopen by restoring individual walk lifetimes.
 * Historical screening notes below are preserved; the current measured
 * residual replaces any earlier claim that lq/sq/por cannot be emitted. */
#include "common.h"
extern unsigned short *D_L16_001FB660[];
extern u8 *D_L16_001B2B1C;
extern int D_L16_001B2B38;
extern u8 D_0013963B;

/* Applies the three tagged group lists, then the boss and its visible children. */
void func_L16_00411F80(u8 *moby, int hidden)
{
    u8 *state = *(u8 **)(moby + 0x68);
    unsigned short *entry;
    unsigned int index;
    unsigned short flags;
    u8 *part;
    int group, field;
    for (group = 0; group < 3; group++) {
        field = group == 0 ? 0x184 : 0x178 + group * 4;
        index = *(unsigned int *)(state + field);
        entry = D_L16_001FB660[index];
        for (;;) {
            index = *(unsigned int *)(state + field);
            if ((index & 255) == 255 || (int)index > D_L16_001B2B38 || !entry) break;
            if ((short)entry[-1] < 0 && entry != D_L16_001FB660[index]) break;
            part = (u8 *)((unsigned int)D_L16_001B2B1C + ((*entry++ & 0x7fff) << 8));
            if (!part) break;
            if (hidden) {
                flags = *(unsigned short *)(part + 0x34);
                *(unsigned short *)(part + 0x34) = (flags & 0xffbe) | 0x1000;
                if (group == 0) {
                    int bound = *(int *)(*(u8 **)(part + 0x24) + 0x10);
                    *(unsigned short *)(part + 0x34) = (flags & 0xffbc) | 0x1000;
                    *(int *)(part + 0x98) = bound;
                } else *(int *)(part + 0x98) = *(int *)(*(u8 **)(part + 0x24) + 0x10);
            } else {
                *(int *)(part + 0x98) = 0;
                *(unsigned short *)(part + 0x34) = (*(unsigned short *)(part + 0x34) & 0xefff) | (group ? 0x41 : 0x43);
            }
        }
    }
    if (hidden) {
        *(unsigned short *)(moby + 0x34) = (*(unsigned short *)(moby + 0x34) & 0xffbe) | 0x1000;
        *(int *)(moby + 0x98) = *(int *)(*(u8 **)(moby + 0x24) + 0x10);
        part = *(u8 **)(state + 0x1f0);
        if (part) {
            *(unsigned short *)(part + 0x34) &= 0xffbe;
            *(unsigned short *)(*(u8 **)(state + 0x1f0) + 0x34) |= 0x1000;
            *(int *)(*(u8 **)(state + 0x1f0) + 0x98) = *(int *)(*(u8 **)(*(u8 **)(state + 0x1f0) + 0x24) + 0x10);
        }
        part = *(u8 **)(state + 0x238);
        if (part) {
            *(unsigned short *)(part + 0x34) &= 0xffbe;
            *(unsigned short *)(*(u8 **)(state + 0x238) + 0x34) |= 0x1000;
            *(int *)(*(u8 **)(state + 0x238) + 0x98) = *(int *)(*(u8 **)(*(u8 **)(state + 0x238) + 0x24) + 0x10);
        }
        part = *(u8 **)(state + 0x23c);
        if (part) {
            *(unsigned short *)(part + 0x34) &= 0xffbe;
            *(unsigned short *)(*(u8 **)(state + 0x23c) + 0x34) |= 0x1000;
            *(int *)(*(u8 **)(state + 0x23c) + 0x98) = *(int *)(*(u8 **)(*(u8 **)(state + 0x23c) + 0x24) + 0x10);
        }
    } else if (!D_0013963B) {
        *(int *)(moby + 0x98) = 0;
        *(unsigned short *)(moby + 0x34) = (*(unsigned short *)(moby + 0x34) & 0xefff) | 0x41;
        part = *(u8 **)(state + 0x1f0);
        if (part) {
            *(unsigned short *)(part + 0x34) |= 0x41;
            *(unsigned short *)(*(u8 **)(state + 0x1f0) + 0x34) &= 0xefff;
            *(int *)(*(u8 **)(state + 0x1f0) + 0x98) = 0;
        }
        part = *(u8 **)(state + 0x238);
        if (part) {
            *(unsigned short *)(part + 0x34) |= 0x41;
            *(unsigned short *)(*(u8 **)(state + 0x238) + 0x34) &= 0xefff;
            *(int *)(*(u8 **)(state + 0x238) + 0x98) = 0;
        }
        part = *(u8 **)(state + 0x23c);
        if (part) {
            *(unsigned short *)(part + 0x34) |= 0x41;
            *(unsigned short *)(*(u8 **)(state + 0x23c) + 0x34) &= 0xefff;
            *(int *)(*(u8 **)(state + 0x23c) + 0x98) = 0;
        }
        *(float *)(moby + 0x48) = 0.0f;
        if (*(u8 **)(state + 0x1f0)) *(float *)(*(u8 **)(state + 0x1f0) + 0x48) = 0.0f;
    }
}
