#include "include_asm.h"
#include "common.h"

typedef struct {
    u8 pad00[0x50];
    float scale;
    u8 pad54[0xE0 - 0x54];
} TableEntry_L00_003FE920;

extern u8 D_0013957F[];
extern TableEntry_L00_003FE920 D_L00_00262570[];
extern u8 D_00189E20[];
extern u8 D_L00_001B9010[];
extern int D_001B0C0C __attribute__((sda));
extern float D_001B0C10 __attribute__((sda));

extern void func_00282F20(void *, void *, float);
extern void func_L00_0037FA90(void *, void *, float, float, float);
extern void func_L00_0032A1A8(void *, void *, void *, float);
extern float func_00283CE0(int);
extern float func_00283B98(float, float);
extern void func_002AB668(void *, void *, float);
extern void func_002ACDE8(void *, void *, void *);

void func_L00_003FE920(u8 *obj, u8 *out, int mode, u8 *flag)
{
    float f20;
    float f2;
    float q[4] __attribute__((aligned(16)));
    float r[4] __attribute__((aligned(16)));
    u8 *src;
    u8 *h = D_00189E20;

    f20 = D_L00_00262570[D_0013957F[0]].scale * 0.016666668f;
    if (*(s16 *)(h + 0x24EC) == 1) {
        func_00282F20(out, obj + 0xD0, -f20);
        src = obj + 0xC0;
    } else {
        func_00282F20(out, h + 0x760, f20);
        src = h + 0x750;
    }
    qcopy(q, src);
    if (*(int *)(h + 0x1500) != 0) {
        func_L00_0037FA90(out, flag, f20, 32.0f, 0.6981318f);
    }
    qcopy(q, D_L00_001B9010);
    if (*(int *)(D_00189E20 + 0xBF8) != 0) {
        func_L00_0032A1A8(*(void **)(D_00189E20 + 0xBF8), flag, out, f20);
    }
    f20 = func_00283CE0(mode);
    f20 = f20 / func_00283CE0(D_001B0C0C - 1);
    f2 = D_001B0C10 * 0.017453294f;
    if (mode != 2) {
        float a = func_00283B98(-f2, (f2 + f2) * f20);
        func_002AB668(r, q, a);
        func_002ACDE8(out, out, r);
    }
}
