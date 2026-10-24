/* 2026-10-23 bounded reconstruction, not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0 of 27 places match (src/levels/shared/L00_003EFF58-qcopy.c); us2: 0 of 27 places match (src/levels/shared/L00_003EFF58-qcopy.c); pal: 0 of 27 places match (src/levels/shared/L00_003EFF58-qcopy.c).
 * 324/328 bytes; prologue load scheduling, one-slot scan edge and vector pointer liveness differ. Tried natural single-slot loops and source-order/ABI corrections. Reopen with evidence for the original record iteration or scheduling policy.
 * Historical note below is retained; its no-C-attempt statement predates this draft.
 */
/* from src/levels/shared/L00_003EE100.c: not written this wave. Retail 328 bytes, 27 place(s), first word at L00:003eff58.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x003eff58  addiu       $sp, $sp, -0x50
 *   0x003eff5c  lui         $v0, 0x1B
 *   0x003eff60  lw          $v0, 0x2BB4($v0)
 *   0x003eff64  sd          $s0, 0x10($sp)
 *   0x003eff68  daddu       $t0, $a1, $zero
 *   0x003eff6c  sd          $s1, 0x18($sp)
 * Kept as data for the maintainers. */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
extern char *D_L00_001B2BB4;
extern void func_00282F20(char *,char *,float);
extern void func_00282CC0(char *,char *,char *);
extern void func_00282DD8(char *,char *,char *);
extern float func_002A7940(void);
extern void func_L00_003F0198(char *,int,float,float,int);
extern float func_00283B98(float,float);
void func_L00_003EFF58(char *owner, int value, char *direction, char *position, float scale)
{
    TI128 local;
    char *record = D_L00_001B2BB4;
    char *velocity = record + 0x20;
    char *normal = record + 0x10;
    int slot, step;
    float angle;
    for (slot = 0; slot <= 0; slot++, record += 0x50, velocity += 0x50, normal += 0x50) {
        if (*(int *)(record + 0x30) != 0) continue;
        *(int *)(record + 0x34) = value;
        *(float *)(record + 0x3c) = scale;
        *(char **)(record + 0x30) = owner;
        *(int *)(record + 0x38) = 0;
        *(TI128 *)record = *(TI128 *)position;
        *(TI128 *)velocity = *(TI128 *)direction;
        *(float *)(record + 0x28) = *(float *)(owner + 0x18);
        func_00282F20((char *)&local,position,2.0f);
        func_00282CC0((char *)&local,(char *)&local,velocity);
        func_00282DD8(normal,velocity,(char *)&local);
        angle = func_002A7940();
        for (step = 99; step >= 0; step--) {
            func_L00_003F0198(record,2,angle,0.0f,0);
            func_L00_003F0198(record,0,angle,0.0f,0);
            angle = func_00283B98(angle,0.06346652f);
        }
        *(int *)(record + 0x40) = 0;
        *(int *)(record + 0x44) = 0;
        break;
    }
}
