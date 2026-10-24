/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses.
 * Reported final C / retail: 228 / 228 bytes; size equality is not a match.
 * us: 0/1 placements.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: Nine source trials; the final int-index body is228 bytes with a0x40 frame. The loop body matches under -mno-split-addresses, but the initial list base remains in s2 across its count guard instead of being promoted from v1 afterward. Reopen with a naturally different list-base lifetime, not another equivalent loop.
 * Reopening condition: Express the initial list/count lifetime without extending the persistent base through the guard.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: Earlier address-commoning experiments identified list-base lifetime as a blocker. The current manual draft preserves that remaining source-lifetime question. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/* Not matched, 2026-10-23.
 * Nine source trials; the final int-index body is228 bytes with a0x40 frame. The loop body matches under -mno-split-addresses, but the initial list base remains in s2 across its count guard instead of being promoted from v1 afterward. Reopen with a naturally different list-base lifetime, not another equivalent loop.
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses
 * Final us check: func_L19_0042A8B8: 0 of 1 places match (src/levels/19_grelbin/L19_0042A8B8.c); exit 1.
 * This source has not passed a linked build or a runtime test.
 */
#include "common.h"

extern s32 D_L19_001A8F00;
extern u8 D_001A7A40;
extern u8 D_L19_001B22E1;
extern u8 D_L19_001B22E0[];
extern f32 D_L19_001B2300;
extern f32 D_L19_001B2304;
extern f32 D_L19_001B2308;
extern u8 D_L19_001BD740[];
extern void func_0029F978(u8 *, u32, u8 *);

void func_L19_0042A8B8(void)
{
    u8 *block;
    u8 **entry;
    int i;
    if (D_L19_001A8F00 != 2) return;
    if (!D_001A7A40) return;
    block = D_L19_001BD740;
    if (*(s16 *)(block+0x44) <= 0) return;
    entry = (u8 **)(block+0x18c);
    i=0;
    do {
        u8 *object = *entry;
        if (*(s16 *)(object + 0xaa) == 0xe3e && !D_L19_001B22E1) {
        func_0029F978(object, 0, D_L19_001B22E0);
        D_L19_001B2300 = 1.9f;
        D_L19_001B2304 = 1.9f;
        D_L19_001B2308 = 1.9f;
        }
        i++;
        entry++;
    } while (i < *(s16 *)(block+0x44));
}
