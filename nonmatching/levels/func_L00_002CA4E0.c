/* 1020/948 bytes in both USA releases; canonical name absent from PAL. Actual C covers all four candidate filters, the pair of vector probes, weighted draw and final remapping. Typed 0x70 records and append/sampling cursors preserve the meaningful object boundaries but differ in allocation and selection-loop control flow. The first byte-view draft was 1004 bytes. Reopen with an analogous weighted-choice loop and record-base addressing control; no flags grid was pursued.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * us: 1020 bytes, expected 948; 0/27 placements
 * us2: 1020 bytes, expected 948; 0/27 placements
 */
#include "include_asm.h"
typedef int Vector __attribute__((mode(TI)));
typedef struct {
    unsigned char pad0[0xE0]; float origin[4];
    unsigned char pad1[0x1B8 - 0xF0]; int count;
    unsigned char pad2[0x208 - 0x1BC]; short gate;
    unsigned char pad3[0xC28 - 0x20A]; int flags;
    unsigned char pad4[0x2290 - 0xC2C]; void *object;
    unsigned char pad5[0x22A4 - 0x2294]; int mode;
    unsigned char pad6[0x22BB - 0x22A8]; unsigned char byte_22bb;
    unsigned char pad7[0x24CC - 0x22BC]; int state;
} HeroChoiceState;
extern HeroChoiceState D_00189E20;
extern int D_001A79F0 __attribute__((sda));
extern int D_001A7398 __attribute__((sda));
extern unsigned char D_00139568[];
extern unsigned char D_L00_00262570[];
typedef struct {
    unsigned char pad0[0x50]; int selector;
    unsigned char pad1[4]; float weight;
    unsigned char pad2[4]; int inactive;
    unsigned char pad3[12];
} ChoiceRecord;
extern ChoiceRecord D_L00_0025BC00[4];
extern int D_L00_0025BDB0;
extern int func_L00_002ADEA0(int);
extern int func_002761F8(void *, void *, int, void *, int);
extern float func_002A7878(float, float);

int func_L00_002CA4E0(int *selected)
{
    float *origin_position;
    int choices[20], count = 0, index, current;
    int *write, *cursor;
    ChoiceRecord *entry;
    float raised[4], origin[4];
    float sum, draw;
    if (D_00189E20.gate != 0) return 0;
    if (D_00189E20.state == 1) {
        *selected = 3;
        if (D_L00_0025BDB0 != 0) return 0;
        if ((D_00189E20.flags & 2) == 0) return 0;
        return func_002A7878(0.0f, 1.0f) < 0.33f;
    }
    origin_position = D_00189E20.origin;
    write = choices;
    entry = D_L00_0025BC00;
    for (index = 0; index < 4; index++, entry++) {
        if (entry->inactive != 0 || entry->weight == 0.0f) continue;
        current = func_L00_002ADEA0(0);
        if (entry->selector != -1 && entry->selector != current) continue;
        if (index == 2) {
            if (D_001A79F0 != 7 && D_001A79F0 != 0x13) continue;
            if (D_00189E20.byte_22bb == 2) continue;
            *(Vector *)origin = *(Vector *)(origin_position);
            *(Vector *)raised = *(Vector *)origin;
            raised[2] += 8.0f;
            if (func_002761F8(origin, raised, 2, D_00189E20.object, 0)) continue;
        }
        if (index == 3 && (D_00189E20.mode != 1 || D_00189E20.count > 50 || D_00189E20.state > 1)) continue;
        *write++ = index;
        count++;
    }
    if (!count) return 0;
    sum = 0.0f;
    cursor = choices;
    index = count;
    while (index > 0) {
        sum += 1.0f / (float)(int)(D_L00_0025BC00[*cursor++].weight * 60.0f);
        index--;
    }
    draw = func_002A7878(0.0f, 1.0f);
    if (!(draw < sum)) return 0;
    cursor = choices;
    for (index = 0; index < count; index++, cursor++) {
        *selected = *cursor;
        sum -= 1.0f / (float)(int)(D_L00_0025BC00[*cursor].weight * 60.0f);
        if (sum < draw) break;
    }
    if (D_001A7398 == 30 && D_L00_00262570[D_00139568[30] * 0xE0 + 4] == 0) {
        if (*selected == 1) *selected = 0x91;
        else if (*selected == 2) *selected = 0x92;
    }
    return 1;
}
