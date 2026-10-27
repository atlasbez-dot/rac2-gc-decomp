/* Nonmatching C: Choose a visible group target, return its position and copy its orientation to the second output.
 * Tested profile: -O2 -G0 -ffunction-sections.
 * Measured US size: 648 bytes; retail: 644 bytes.
 * Placement checks: US, US2 and PAL: 0/2 each.
 * Remaining: The first output spill still follows the register saves; final output-pointer reloads and the floating result store also differ.
 * Reopen with a measured lifetime or scheduling explanation for the early argument spill and the output pointer across the final copy; preserve the three real inputs and forwarded result of func_L03_00419BD8.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern unsigned char *D_L03_001B2A1C __attribute__((sda));

extern int D_L03_001B2A38 __attribute__((sda));

extern unsigned short *D_L03_001FB5A0[];

extern int func_L03_00419BD8(unsigned int, void *, void *);

extern float func_00282E80(void *, void *);

extern float func_00282E48(void *, void *);

extern int func_00277258(void *, int, void *, float);

extern float func_002A89A8(void *, int, float);


typedef struct {
    unsigned char pad0[0x200];
    int ids[8];
    unsigned int ref220;
    unsigned char pad1[0x354 - 0x224];
    unsigned char *target;
} L03SeekState;


float *func_L03_003C5668(unsigned char *a0, float *a1, float *a2) {
    L03SeekState *o = *(L03SeekState **)(a0 + 0x68);
    unsigned short **tbl = D_L03_001FB5A0;
    unsigned char *cand;
    unsigned char *best = 0;
    unsigned char *e;
    unsigned short *q;
    float bestd;
    float d;
    float vec[4] __attribute__((aligned(16)));
    int r;
    int i;

    bestd = func_00282E48(a0 + 0x10, o->target + 0x10);
    cand = o->target;
    if (func_L03_00419BD8(o->ref220, a0 + 0x10, cand + 0x10))
        best = o->target;
    for (i = 0; i < 8; i++) {
        for (q = tbl[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L03_001B2A38 && q != 0 &&
             ((short)q[-1] >= 0 || q == tbl[o->ids[i]]);
             q++) {
            e = D_L03_001B2A1C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (*(short *)(e + 0xAA) == 0x972) {
                d = func_00282E80(a0 + 0x10, e + 0x10);
                if (d < bestd) {
                    qcopy(vec, e + 0x10);
                    vec[2] += 1.0f;
                    if (func_00277258(vec, 0, a0, 0.5f) == 0) {
                        cand = e;
                        r = func_L03_00419BD8(o->ref220, a0 + 0x10, e + 0x10);
                        bestd = d;
                        if (r)
                            best = cand;
                    }
                }
            }
        }
    }
    if (best)
        cand = best;
    qcopy(a2, cand + 0xF0);
    {
        float *out = a1;
        qcopy(out, cand + 0x10);
        out[2] = func_002A89A8(out, 0, 0.5f);
    }
    return a1;
}
