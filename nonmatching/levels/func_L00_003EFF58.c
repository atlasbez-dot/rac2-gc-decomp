/*
 * Retained manual near miss; not linked or counted.
 * Final measured profile: -O2 -G0 -ffunction-sections.
 * Final C / retail: 328 / 328 bytes.
 * us:0/27 placements, exit1; us2:0/27 placements, exit1.
 * pal:0/27 placements, exit1.
 * 5 bounded source/profile trials; three natural source forms tie.
 * Equal328-byte size and0x50 frame; first difference+0x4, global-load/prologue scheduling and record/normal base allocation differ. The0x50-stride partial record view is measured, with no table-length claim.
 * Reopen only with: An original record-walk or allocator/scheduling witness that resolves the entry and base-register differences.
 * Measured in the dedicated src unit before its marker/profile were restored; this body is retained unchanged modulo this comment.
 * Historical draft and trial variants remain private. Behavior and strict linked equality remain unverified.
 */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
/* Table stride0x50 and these field offsets are measured; no table length is claimed. */
typedef struct { TI128 position,normal,velocity; char *owner; int value,phase; float scale; int first,last; } EffectRecord;
extern EffectRecord *D_L00_001B2BB4;
extern void func_00282F20(char *,char *,float);
extern void func_00282CC0(char *,char *,char *);
extern void func_00282DD8(char *,char *,char *);
extern float func_002A7940(void);
extern void func_L00_003F0198(char *,int,float,float,int);
extern float func_00283B98(float,float);
void func_L00_003EFF58(char *owner, int value, char *direction, char *position, float scale)
{
    TI128 local;
    EffectRecord *base = D_L00_001B2BB4;
    EffectRecord *record;
    char *velocity;
    char *normal;
    int slot, step;
    float angle;
    slot = -1;
    while (++slot <= 0) {
        record = base + slot;
        velocity = (char *)&record->velocity;
        normal = (char *)&record->normal;
        if (record->owner != 0) continue;
        record->value = value;
        record->scale = scale;
        record->owner = owner;
        record->phase = 0;
        qcopy(&record->position,position);
        qcopy(velocity,direction);
        ((float *)&record->velocity)[2] = *(float *)(owner + 0x18);
        func_00282F20((char *)&local,position,2.0f);
        func_00282CC0((char *)&local,(char *)&local,velocity);
        func_00282DD8(normal,velocity,(char *)&local);
        angle = func_002A7940();
        for (step = 99; step >= 0; step--) {
            func_L00_003F0198((char *)record,2,angle,0.0f,0);
            func_L00_003F0198((char *)record,0,angle,0.0f,0);
            angle = func_00283B98(angle,0.06346652f);
        }
        record->first = 0;
        record->last = 0;
        break;
    }
}
