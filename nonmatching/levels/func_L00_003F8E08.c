/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections (suffix profile).
 * Reported final C / retail: 564 / 568 bytes; size equality is not a match.
 * us: 0/27 placements; 564/568 bytes.
 * us2: 0/27 placements; 564/568 bytes.
 * pal: 0/27 placements; 564/568 bytes.
 * Residual: Initializer remains564/568 bytes. The counter allocator, split address construction and store motion differ. The deliberately supplied zero to the allocator wrapper is preserved; its observed unused formal has separately passed all carrying releases.
 * Reopening condition: Use a unique dedicated reset source filename, preserving the existing G8 sibling and its FE280 definition. New allocator/address-materialization evidence is needed; the approved zero input to3F8DC8 is now retained.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained complete manual reconstruction; not an exact match.
 * Source profile: -O2 -G8 -ffunction-sections (suffix profile).
 * Initializer remains564/568 bytes. The counter allocator, split address construction and store motion differ. The deliberately supplied zero to the allocator wrapper is preserved; its observed unused formal has separately passed all carrying releases.
 */
#include "common.h"

typedef struct EffectSpawnSlot {
    char prefix[0x14];
    char *owner;
    char tail[8];
} EffectSpawnSlot;
typedef struct {
    float weight;
    int count;
    char remainder[8];
} EffectTuning;
extern EffectSpawnSlot D_L00_002533B0[];
extern EffectTuning D_L00_00253770[];
extern unsigned char *D_L00_001B0A20 __attribute__((sda));
extern char D_L00_001B0A28[] __attribute__((sda));
extern char D_L00_001B0A38[] __attribute__((sda));
extern char D_L00_001B0A40[] __attribute__((sda));
extern char *D_L00_001B2BC8;
extern char *D_L00_001B2BCC;
extern char *D_L00_001B2BD0;
extern short D_L00_001B2BD4;
extern int D_L00_001B2BD8;
extern float D_L00_001B2BDC;
extern unsigned char *func_L00_003F8DC8(int unused);

/* Reset the effect slots and install the two banks of per-kind tuning. */

void func_L00_003F8E08(void) {
    int i;
    char **slot = &D_L00_002533B0[29].owner;
    EffectTuning *entry;
    for (i = 29; i >= 0; i--) {
        *slot = 0;
        slot -= 8;
    }
    D_L00_001B0A20 = 0;
    func_L00_003F8DC8(0);
    i = 30;
    D_L00_001B2BD4 = 3;
    D_L00_001B2BC8 = D_L00_001B0A28;
    D_L00_001B2BD8 = i;
    D_L00_001B2BDC = 0.96f;
    D_L00_001B2BCC = D_L00_001B0A38;
    D_L00_001B2BD0 = D_L00_001B0A40;
    entry = D_L00_00253770;
    for (i = 118; i >= 0; i--) {
        entry->weight = 0.0f;
        entry->count = 0;
        entry[119].weight = 0.0f;
        entry[119].count = 0;
        entry++;
    }
    entry = D_L00_00253770;
    entry[0x44].weight = 1.0f; entry[0x44].count = 3;
    entry[0x2A].weight = 1.0f; entry[0x2A].count = 5;
    entry[0x47].weight = 1.0f; entry[0x47].count = 5;
    entry[0x16].weight = 1.0f; entry[0x16].count = 3;
    entry[0x41].weight = 1.0f; entry[0x41].count = 3;
    entry[0x1A].weight = 1.0f; entry[0x1A].count = 3;
    entry[0x1D].weight = 2.0f; entry[0x1D].count = 4;
    entry[0x3F].weight = 2.0f; entry[0x3F].count = 4;
    entry[0x25].weight = 2.0f; entry[0x25].count = 4;
    entry[0x4C].weight = 2.0f; entry[0x4C].count = 4;
    entry[0x1B].weight = 2.0f; entry[0x1B].count = 4;
    entry[0x45].weight = 2.0f; entry[0x45].count = 4;
    entry[0x1C].weight = 2.0f; entry[0x1C].count = 4;
    entry[0x3E].weight = 2.0f; entry[0x3E].count = 4;
    entry[0x20].weight = 2.0f; entry[0x20].count = 4;
    entry[0x4E].weight = 2.0f; entry[0x4E].count = 4;
    entry[0x19].weight = 2.0f; entry[0x19].count = 4;
    entry[0xBE].weight = 9.0f; entry[0xBE].count = 8;
    entry[0xC3].count = 6;
    entry[0xBC].weight = 2.0f; entry[0xBC].count = 5;
    entry[0xC5].weight = 5.0f;
    entry[0x46].weight = 2.0f; entry[0x46].count = 4;
    entry[0xA1].weight = 9.0f; entry[0xA1].count = 8;
    entry[0x8D].weight = 3.0f; entry[0x8D].count = 4;
    entry[0xB8].weight = 3.0f; entry[0xB8].count = 4;
    entry[0x91].weight = 3.0f; entry[0x91].count = 4;
    entry[0xBB].weight = 3.0f; entry[0xBB].count = 4;
    entry[0x94].weight = 3.0f; entry[0x94].count = 6;
    entry[0xB6].weight = 3.0f; entry[0xB6].count = 6;
    entry[0x9C].weight = 3.0f; entry[0x9C].count = 6;
    entry[0xC3].weight = 3.0f;
    entry[0x92].weight = 2.0f; entry[0x92].count = 5;
    entry[0x93].weight = 5.0f; entry[0x93].count = 4;
    entry[0xB5].weight = 5.0f; entry[0xB5].count = 4;
    entry[0x97].weight = 5.0f; entry[0x97].count = 4;
    entry[0xC5].count = 4;
    entry[0xBD].count = 4; entry[0xBD].weight = 3.0f;
    entry[0x90].weight = 3.0f; entry[0x90].count = 4;
}
