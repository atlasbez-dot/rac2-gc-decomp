/* Nonmatching C: Test the visibility path between two full vectors and inspect the collision owner.
 * Tested profile: -O2 -G8 -ffunction-sections.
 * Measured US size: 520 bytes; retail: 532 bytes.
 * Placement checks: US and US2: 0/1 each; PAL: 0/1.
 * Remaining: Register roles, stack vector addresses and collision-field reload scheduling differ.
 * Reopen with evidence for the pointer lifetimes across the raycast calls; preserve all six complete 16-byte vectors and pointer-valued collision fields.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float D_L23_001AFA70 __attribute__((sda));
extern float D_L23_001AFAB0 __attribute__((sda));

extern float func_00282E48(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_002761F8(void *, void *, int, int, int);
extern void func_L23_00418650(void *, float);

extern u8 D_L23_001C0A80[];
extern int D_00189E20[];

int func_L23_003C0A60(char *obj, TI128 *p1, TI128 *p2) {
    char *state = *(char **)(obj + 0x68);
    TI128 loc[6];
    TI128 *pos;
    TI128 *q;
    TI128 *dst;
    float d;
    int done;
    char *hit;

    if (D_L23_001AFA70 < func_00282E48(p1, p2))
        return 0;
    qcopy(&loc[0], p2);
    func_L23_00418650(&loc[0], *(float *)(state + 0x54) + *(float *)(state + 0x50));
    func_00282CF0(&loc[1], &loc[0], p1);
    func_00282F20(&loc[1], &loc[1], D_L23_001AFAB0);
    pos = &loc[4];
    qcopy(pos, p1);
    dst = &loc[2];
    qcopy(dst, p1);
    func_L23_00418650(dst, *(float *)(state + 0x54) + *(float *)(state + 0x50));
    done = 0;
    do {
        d = func_00282E48(pos, &loc[0]);
        if (d < D_L23_001AFAB0) {
            if (d < 0.0f)
                return 1;
            func_00282F20(&loc[5], &loc[1], d);
            done = 1;
            func_00282CC0(&loc[3], pos, &loc[5]);
            q = &loc[3];
            func_L23_00418650(&loc[3], *(float *)(state + 0x54) + *(float *)(state + 0x50));
        } else {
            func_00282CC0(&loc[3], pos, &loc[1]);
            q = &loc[3];
            func_L23_00418650(&loc[3], *(float *)(state + 0x54) + *(float *)(state + 0x50));
        }
        if (func_002761F8(&loc[2], q, 0x10, 0, 0)) {
            hit = *(char **)(D_L23_001C0A80+0x18);
            if (hit != obj && hit != *(char **)((u8 *)D_00189E20+0x2290))
                return 0;
        }
        dst = &loc[2];
        qcopy(dst, q);
        func_00282CC0(pos, pos, &loc[1]);
    } while (!done);
    return 1;
}
