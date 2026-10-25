/* Retained manual C reconstruction, 25 October 2026; not matching.
 * Profile: -O2 -G0 -ffunction-sections.
 * 568/572 bytes. A measured input-record prefix, signed button words and separate snapshot
 * lifetime reproduce the input fallback and ring updates more closely. The entry load
 * destination/prologue, resident rematerialization and input-axis allocation still differ. The
 * frame-order profile did not improve the result. Reopen with independent evidence for those
 * lifetimes.
 * Checks: us: func_L18_002D0C00: 0 of 3 places match; us2: func_L18_002D0C00: 0 of 3 places
 * match; pal: func_L18_002D0C00 is in neither catalogue of pal.
 * No linked build or runtime validation. This header was added after candidate checks; the
 * copied standalone file was not recompiled after retention.
 */

#include "common.h"
extern s32 D_L18_001AFBB0;
extern u8 D_00189E20[];
/* Partial input record: only the observed axes and button words are modeled. */
typedef struct {
    u8 reserved000[0x108];
    float horizontal, vertical;
    u8 reserved110[0x90];
    s32 held;
    u8 reserved1A4[12];
    s32 pressed;
} InputRecordPrefix;
extern InputRecordPrefix D_00138180;
extern void func_L00_002B2BD0(void);
extern s32 func_00282978(void *);
extern s32 func_L00_002D3400(void);
extern float func_L00_002B3900(void);
extern float func_00282E20(void *);
extern void func_L18_002D7650(void);
extern void func_00283410(void *, void *);
extern void func_00283388(void *);
extern void func_00283698(void *, void *);
extern void func_L18_002D0850(void);
extern void func_L00_002C2DE8(void);
extern void func_L18_002DEFF8(void);
void func_L18_002D0C00(void)
{
    u8 *base;
    u8 *snapshot;
    s32 index;
    if (D_L18_001AFBB0) {
        func_L00_002B2BD0();
        return;
    }
    snapshot = D_00189E20 + 0x2030;
    qcopy(snapshot, snapshot - 0x1FB0);
    if (D_00138180.held & 3) {
        if (*(s16 *)(snapshot - 0xBDC) < 1) *(s16 *)(snapshot - 0xBDC) = 1;
    } else func_00282978(snapshot - 0xBDC);
    base = D_00189E20;
    if (*(s32 *)(base + 0x2294) == 16) *(s16 *)(base + 0x1454) = 0;
    base[0x22C3] = func_L00_002D3400();
    *(float *)(base + 0x1FB4) = D_00138180.vertical;
    *(float *)(base + 0x1FB0) = D_00138180.horizontal;
    *(s32 *)(base + 0x270) = 0;
    *(float *)(base + 0x24BC) = func_L00_002B3900();
    if (func_00282E20(base + 0x1FB0) < 0.25f) {
        *(float *)(base + 0x1FB0) = (float)((s32)((D_00138180.pressed >> 13) & 1) - (s32)((D_00138180.pressed >> 15) & 1));
        *(float *)(base + 0x1FB4) = (float)((s32)((D_00138180.pressed >> 14) & 1) - (s32)((D_00138180.pressed >> 12) & 1));
    }
    *(float *)(base + 0x24B8) = func_L00_002B3900();
    func_L18_002D7650();
    index = *(s32 *)(base + 0x23BC);
    *(float *)(base + 0x233C + index * 4) = *(float *)(base + 0x98);
    *(s32 *)(base + 0x23BC) = (index + 1) % 32;
    if (++*(s32 *)(base + 0x23C0) > 32) *(s32 *)(base + 0x23C0) = 32;
    index = *(s32 *)(base + 0x23C4);
    qcopy((base + 0x1D90 + index * 16), (base + 0x80));
    *(s32 *)(base + 0x23C4) = (index + 1) % 32;
    if (++*(s32 *)(base + 0x23C8) > 32) *(s32 *)(base + 0x23C8) = 32;
    func_00283410(base, base + 0x90);
    func_00283388(base + 0x40);
    func_00283698(base + 0x40, base);
    func_L18_002D0850();
    func_L00_002C2DE8();
    func_L18_002DEFF8();
}
