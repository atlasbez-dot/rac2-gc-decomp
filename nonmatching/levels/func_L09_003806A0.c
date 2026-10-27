/* Nonmatching: 1228/1296 bytes.
 * Profile: -O2 -G8 -ffunction-sections.
 * Placement checks: US: 0/2; US2: 0/2; PAL: 0/2.
 * 1228/1296 bytes, frame0x80. The two UV layers now use a truthful pair view with an8-byte stride and incomplete outer extent. The complete scans, ordered FP reductions, vector history transfers and typed callback registrations remain. Loop/base materialization, global addressing and register allocation still differ.
 * Reopen with independently qualified UV/history ownership and measured loop/base lifetimes across both placements. The direct helper substitution had previously tied; this follow-up qualifies the interleaved pair view without inventing global extents.
 */
#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef struct { float u, v; } ScrollLayer;
#define I32(p, o) (*(int *)((p) + (o)))
#define F32(p, o) (*(float *)((p) + (o)))
#define S16(p, o) (*(short *)((p) + (o)))

extern u8 D_00189E20[], D_00189EA0[];
extern float D_001A7928;
extern int D_L09_001C9F80;
extern Quad D_L09_001B3100 __attribute__((sda));
extern u8 D_L09_001B9A00[];
extern u8 *D_L09_001B294C;
extern ScrollLayer D_L09_001B3110[];
extern float D_L09_001AEC38[] __attribute__((sda));
extern float D_L09_001AEC48[] __attribute__((sda));
extern float D_L09_001AEC4C[];
extern float D_L09_001B3120, D_L09_001B3124 __attribute__((sda));
extern int D_L09_001B2388;

extern int func_002ACBC8(void *, int);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern int func_00283CF0(float);
extern float func_00283CE0(int), func_00283198(float);
extern void func_L09_0037FCE8(void *);
extern void func_L00_002E6DB8(void (*)(void *), void *);
extern void func_L00_002E6CF0(void (*)(void *), void *);

void func_L09_003806A0(u8 *object)
{
    u8 *state = *(u8 **)(object + 0x68);
    float delta[4] __attribute__((aligned(16)));
    float scaled[4] __attribute__((aligned(16)));
    int i, index;

    if (D_L09_001C9F80 != I32(state, 0x30))
        return;
    if (object[0x20] == 0) {
        object[0x30] = 255;
        object[0x20] = 1;
        {
            ScrollLayer *layer = D_L09_001B3110;
            for (i = 1; i >= 0; i--, layer++) {
                layer->u = 0.0f;
                layer->v = 0.0f;
            }
        }
        qcopy(&D_L09_001B3100, D_L09_001B9A00);
        D_L09_001B3124 = F32(state, 0x14);
        return;
    }
    for (i = 0; i < 4; i++) {
        index = I32(state, 0x40 + i * 4);
        if (index == -1)
            continue;
        if (func_002ACBC8(D_00189EA0, index)) {
            S16(D_00189E20, 0x1FE) = 0;
            return;
        }
    }
    D_L09_001B3124 = F32(state, 0x14);
    for (i = 0; i < 4; i++) {
        index = I32(state, 0x50 + i * 4);
        if (index == -1)
            continue;
        if (func_002ACBC8(D_00189EA0, index)) {
            D_L09_001B3124 = F32(D_L09_001B294C + index * 128, 0x38) + 0.15f;
            break;
        }
    }
    S16(D_00189E20, 0x1FE) = 2;
    func_00282CF0(delta, D_L09_001B9A00, &D_L09_001B3100);
    qcopy(&D_L09_001B3100, D_L09_001B9A00);
    if (!(F32(state, 0x20) < F32(D_L09_001B9A00, 8)))
        return;

    for (i = 0; i < 2; i++) {
        func_00282D30(scaled, delta,
                     (D_L09_001AEC38[i] + D_L09_001AEC38[i]) /
                     (F32(state, 0x18) * 5.0f));
        /* Preserve the ordered comparisons, including the exact-1 and NaN paths. */
        if (1.0f < scaled[0] || scaled[0] < 1.0f)
            scaled[0] -= func_00283CE0(func_00283CF0(scaled[0]));
        if (1.0f < scaled[1] || scaled[1] < 1.0f)
            scaled[1] -= func_00283CE0(func_00283CF0(scaled[1]));
        D_L09_001B3110[i].u += scaled[0];
        D_L09_001B3110[i].v += scaled[1];
        if (1.0f < D_L09_001B3110[i].u)
            D_L09_001B3110[i].u -= 1.0f;
        if (D_L09_001B3110[i].u < -1.0f)
            D_L09_001B3110[i].u += 1.0f;
        if (1.0f < D_L09_001B3110[i].v)
            D_L09_001B3110[i].v -= 1.0f;
        if (D_L09_001B3110[i].v < -1.0f)
            D_L09_001B3110[i].v += 1.0f;
    }
    D_L09_001B3120 = D_L09_001B3124 +
        func_00283198(func_00283CE0(D_L09_001B2388 % 360) *
                     0.017444444820284843f - 3.140000104904175f) * F32(state, 0x34);
    for (i = 0; i < 2; i++) {
        D_L09_001B3110[i].u += D_L09_001AEC48[i * 2] * D_001A7928;
        if (1.0f < D_L09_001B3110[i].u)
            D_L09_001B3110[i].u -= 1.0f;
        if (D_L09_001B3110[i].u < -1.0f)
            D_L09_001B3110[i].u += 1.0f;
        D_L09_001B3110[i].v += D_L09_001AEC4C[i * 2] * D_001A7928;
        if (1.0f < D_L09_001B3110[i].v)
            D_L09_001B3110[i].v -= 1.0f;
        if (D_L09_001B3110[i].v < -1.0f)
            D_L09_001B3110[i].v += 1.0f;
    }
    if (I32(state, 0x38))
        func_L00_002E6DB8(func_L09_0037FCE8, object);
    else
        func_L00_002E6CF0(func_L09_0037FCE8, object);
}
