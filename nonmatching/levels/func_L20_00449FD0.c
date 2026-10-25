/* Retained manual C near miss; no linked or exact-C credit.
 * Profile: -O2 -G8 -ffunction-sections. US: 308/308 bytes, 0/1, exit 1.
 * Full vectors, nullable object return and both independent floating inputs are preserved.
 * Residual: the two saved floating parameters swap f20/f21, with earlier state-base loading.
 * Three meaningful field/lifetime variants emitted identical complete diagnostics.
 * Reopen with independently supported source lifetimes or qualified allocator behavior. */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float D_L20_001B23F8 __attribute__((sda));

extern void *func_0029EFD0(int);
extern void func_002B37E8(u8 *, u8 *);
extern float func_002A7940(void);
extern void func_002833F0(void *, void *);
extern float func_002A7878(float a, float b);

char *func_L20_00449FD0(char *arg0, char *arg1, char *arg2, int arg3,
                        float f12, float f13) {
    char *obj;
    char *state;
    float radiusScale, baseRadius;

    obj = func_0029EFD0(0x12EE);
    if (obj != 0) {
        func_002B37E8((u8 *)obj, (u8 *)arg0);
        qcopy((obj + 0x10), arg1);
        *(float *)(obj + 0xF0) = func_002A7940();
        *(float *)(obj + 0xF4) = func_002A7940();
        func_002833F0(obj + 0xC0, obj + 0xF0);
        *(u8 *)(obj + 0x20) = 1;
        *(u16 *)(obj + 0x34) |= 0x100;
        radiusScale = D_L20_001B23F8;
        baseRadius = *(float *)(*(char **)(obj + 0x24) + 0x24);
        state = *(char **)(obj + 0x68);
        *(float *)(obj + 0x2C) = baseRadius * radiusScale;
        qcopy(state, arg2);
        *(int *)(state + 0x18) = (int)arg3;
        *(float *)(state + 0x1C) = f13;
        *(float *)(state + 0x14) = f12 * 0.016666668f;
        *(int *)(state + 0x20) = 0x3C;
        *(float *)(state + 0x10) =
            func_002A7878(10.0f, 20.0f) * 0.00027777778f;
    }
    return obj;
}
