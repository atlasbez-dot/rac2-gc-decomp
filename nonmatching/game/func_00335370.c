/* Retained near miss: 88/88 bytes, 0/28 placements with
 * -O2 -G0 -ffunction-sections -frac2-qcopy.
 * The branch and grouped copy match. Post-reload scheduling fills the
 * field-load-to-address latency gap with the independent ra restore;
 * before sched2, the copy and restores already have retail order.
 * -mastra-keep-frame-order leaves the code identical because these restores
 * are not frame-related. -fno-schedule-insns2 fixes the tail but changes the
 * prologue. Five earlier source variants also failed.
 * Reopen with evidence for a legitimate epilogue/scheduling policy or a
 * meaningful source dependency; do not fabricate a clobber or barrier.
 */

typedef int TI128 __attribute__((mode(TI)));
typedef int s32;

#include "include_asm.h"

typedef struct {
    unsigned char pad_35370[0x70];
    void *f70_35370;
    unsigned char pad2_35370[0x12];
    short f86_35370;
} Obj_35370;

extern Obj_35370 *ref_L00_00335370_00;
extern char *func_00270280(s32 a0);

void func_00335370(void *a0)
{
    Obj_35370 *obj;
    Obj_35370 *selected;
    void *dst;
    char *p;

    obj = ref_L00_00335370_00;
    if (obj->f86_35370 != 5) {
        selected = (Obj_35370 *)func_00270280(5);
    } else {
        selected = obj;
    }
    dst = selected->f70_35370;
    p = (char *)dst + 0x80;
    *(TI128 *)p = *(TI128 *)a0;
}
