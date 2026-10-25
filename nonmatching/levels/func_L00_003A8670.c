/* Retained nonmatching C; measured 25 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * Final check.py coverage: us 0/27, us2 0/27, pal catalogue absent.
 * 356/356 bytes, improved from364. The measured112-byte record and explicit configuration branches reproduce the prefix through +0xFC. First difference +0x100: column-base/index association and three following address/schedule words. Extending column-pointer lifetime worsened allocation and was discarded.
 * Reopen: Establish the original real strided-column address lifetime and its C expression without false padding, register pins or fake dependencies; preserve the full80-entry and two nine-element sequences.
 * Shared EE transfer helpers are approved; their use is not matching evidence.
 * Earlier complete drafts and all trial sources/logs are preserved privately.
 */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
typedef struct { char pad[0x2294]; int level; } Context;
extern char D_00189E20[];
extern float D_L00_001AF718 __attribute__((sda));
extern float D_L00_001AF71C __attribute__((sda));
extern float D_L00_001AF724 __attribute__((sda));
extern float D_L00_001AF728 __attribute__((sda));
extern float D_L00_001AF72C __attribute__((sda));
extern float D_L00_001AF730 __attribute__((sda));
extern int D_L00_001AF734 __attribute__((sda));
extern int D_L00_001AF738 __attribute__((sda));
extern float D_L00_001AF73C __attribute__((sda));
extern float D_L00_001AF740 __attribute__((sda));
extern float D_L00_001AF744 __attribute__((sda));
extern char *func_L00_0032A088(int, int);
extern float func_002A7940(void);
extern float func_002A78D8(float, float);
extern float func_002A7878(float, float);
extern int func_002A7820(int, int);
extern float func_00283CE0(int);

/* The pool's measured stride is 112 bytes, including both nine-float arrays. */
typedef struct {
    TI128 position;
    short duration, active;
    float angle, spin, scale, reciprocal, drift;
    float phase[9], speed[9];
} BeamParticle;

void func_L00_003A8670(TI128 *position, int index)
{
    char *base = func_L00_0032A088(1483, index);
    BeamParticle *entry;
    int i, j;
    Context *context = (Context *)D_00189E20;
    for (i = 0, entry = (BeamParticle *)base; i < 80; ++i, ++entry) {
        if (entry->active == 0) {
            float high;
            float *p;
            entry->active = 1;
            qcopy(&entry->position, position);
            entry->angle = func_002A7940();
            entry->spin = func_002A78D8(D_L00_001AF718, D_L00_001AF71C) * 0.017453294f;
            entry->scale = func_002A7878(D_L00_001AF728, D_L00_001AF724);
            entry->duration = func_002A7820(D_L00_001AF734, D_L00_001AF738);
            entry->reciprocal = 1.0f / func_00283CE0(entry->duration);
            if (context->level == 29)
                high = D_L00_001AF744;
            else
                high = D_L00_001AF740;
            entry->drift = func_002A7878(D_L00_001AF73C, high) * 0.016666668f;
            p = (float *)(i * sizeof(BeamParticle) + (base + 76));
            for (j = 8; j >= 0; --j, ++p) {
                p[-9] = 0.0f;
                *p = func_002A7878(D_L00_001AF72C, D_L00_001AF730);
            }
            return;
        }
    }
}
