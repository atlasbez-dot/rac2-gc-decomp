/* Near miss, remeasured 2026-10-23: 372 versus 396 bytes, 0/27 in US,
 * PAL and US2. Profile: -O2 -G8 -ffunction-sections -fno-strict-aliasing.
 * The retained old draft had incorrect behavior: the negative angle was formed
 * only on the lower clamp path and the final cap was 0.055 instead of retail's
 * 0x3D8F5C29 (0.07). Corrected both, made clamp branches exclusive, and fixed
 * canonical data names. This is useful C, not the former 364-byte approximation.
 * Differences remain in record-address lifetime, pointer reload, FP allocation
 * and two missing pre-div nops; -fno-gcse did not improve the result.
 * Next useful work: establish the original memory/alias model and division floor.
 */
#include "include_asm.h"
#include "common.h"

/* The record the level writes: four floats near its end. */
typedef struct Rac2Native_002B8CB8_Record {
    unsigned char prefix_00[0xCC8];
    float f_CC8;
    unsigned char prefix_CCC[0xCF8 - 0xCC8 - 4];
    float f_CF8;
    unsigned char prefix_CFC[0xD04 - 0xCF8 - 4];
    float f_D04;
    float f_D08;
} Rac2Native_002B8CB8_Record;

extern char D_00189E20[];

extern unsigned char D_001A7A43 NOT_SDA;

/* A float in the boot's small data: the sda attribute and this unit's -G8 make the
   reference to it $gp-relative, the way retail has it. */
extern float D_001A7BF8 __attribute__((sda));

extern Rac2Native_002B8CB8_Record D_L00_0025BE10;

extern float D_L00_0025CB1C NOT_SDA;

extern float func_00282C48(float f);

/* Scales the level's record by the state block's mode: the block's own angle is clamped
   to a range, turned into a small signed share and written back, and the record's two
   lengths follow it. */
void func_L00_002B8CB8(void)
{
    Rac2Native_002B8CB8_Record *rec = &D_L00_0025BE10;
    float *live;
    char *st = D_00189E20;
    float x;
    float y;
    float share;
    float len;
    float scale;

    if (*(void **)(st + 0x1314) == 0)
        return;
    if (D_001A7A43 != 0)
        D_L00_0025CB1C = D_001A7BF8;
    live = *(void **)(st + 0x1314);
    scale = 1024.0f / *(float *)((char *)live + 0x2C);
    if (*(int *)(st + 0x2294) != 2)
        return;

    x = *(float *)(st + 0x1A8);
    y = 0.02f;
    rec->f_D04 = y;
    rec->f_D08 = 0.35f;
    if (1.4f < x)
        x = 1.4f;
    else if (x < -1.4f) {
        x = -1.4f;
    }
    y = -x * 1.2f;
    if (75.0f * 3.14159274f / 180.0f < y)
        y = 75.0f * 3.14159274f / 180.0f;
    else if (y < -(75.0f * 3.14159274f / 180.0f))
        y = -(75.0f * 3.14159274f / 180.0f);
    rec->f_CC8 = y;

    share = 0.1f;
    len = func_00282C48(x) * share;
    share = len + share;
    if (0.07f < share)
        share = 0.07f;
    rec->f_CF8 = share * scale;
}
