/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 0/1; PAL 0/1.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Nonmatching: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L02_003D25C8: 0 of 1 places match (src/levels/02_maktar_nebula/L02_003D25C8.c); us2: func_L02_003D25C8: 0 of 1 places match (src/levels/02_maktar_nebula/L02_003D25C8.c); pal: func_L02_003D25C8: 0 of 1 places match (src/levels/02_maktar_nebula/L02_003D25C8.c). Six bounded manual/profile trials. Best228/228, frame0x30, firstdiff+0x78: state load,8.0constant and destination-address scheduling. Entire other body matches; no max/min/MMI blocker. Reopen with original radius-expression/copy ordering. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern float func_00283248(float, float), func_002A7878(float, float), func_00283180(float), func_00283198(float);
/* Chooses a point behind the actor with a randomized heading and radius. */
void func_L02_003D25C8(char *self, float *point) {
    char *state;
    float heading, radius;
    heading = func_00283248(*(float *)(self + 0x10) - point[0], *(float *)(self + 0x14) - point[1]);
    heading += func_002A7878(-0.78539824f, 0.78539824f);
    radius = func_002A7878(-2.0f, 2.0f) + 8.0f;
    state = *(char **)(self + 0x68);
    *(Quad *)(state + 0x2D0) = *(Quad *)point;
    *(float *)(state + 0x2D0) += radius * func_00283180(heading);
    *(float *)(state + 0x2D4) += radius * func_00283198(heading);
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L02_003D25C8 (228 bytes, 1 place) - MMI/COP1 words, ASM_FUNC candidate.
 *
 * Classified by pattern, not decoded this wave: the row carries two `.word # INVALID`
 * entries and a max.s/min.s class word (the 4600xxxx COP1 funct 0x28/0x29 family the sixth
 * wave measured as unemittable from C text), with five calls.  The same combination already
 * blocks func_L08_00422850 and func_L08_00422900, so this row is behind the same
 * compiler-side wall; re-read it only if max.s/min.s becomes available.
 */
