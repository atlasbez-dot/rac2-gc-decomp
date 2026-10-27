/* Complete manual reconstruction; not linked.
 * Profile: -O2 -G8 -ffunction-sections, in its own unit (not the existing L00_003F8E08-g8.c).
 * 568/568 bytes; us 0/27, ~92 differing lines.
 * 26 October 2026 (M10): the slot reset as D_L00_002533B0[i].owner with i from 29 down and then
 * i = 30 (the counter lives across the allocator call, so $s0 as retail; the giv base is
 * la + 0x3B4 as retail); the three gp blocks sized ([8]) give retail's $gp address forms.
 * Left: the tuning-table block. Ours emits the last store of each equal-constant group first
 * and uses $a3 as the table base (retail $a0/$v0, constants f0/f1 swapped). Store climbing on
 * the first two groups only reached 92.
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
extern char D_L00_001B0A28[8] __attribute__((sda));
extern char D_L00_001B0A38[8] __attribute__((sda));
extern char D_L00_001B0A40[8] __attribute__((sda));
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
    EffectTuning *entry;
    for (i = 29; i >= 0; i--)
        D_L00_002533B0[i].owner = 0;
    i = 30;
    D_L00_001B0A20 = 0;
    func_L00_003F8DC8(0);
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
