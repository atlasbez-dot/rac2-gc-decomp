/*
 * Complete manual reconstruction retained as nonmatching; no coverage credit.
 * Fresh qualified-compiler checks, 2026-10-25.
 * Profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por
 * Coverage: US: 0/1; US2: 0/1; PAL: absent from catalogue.
 * Compiled text: 628 bytes; retail: 628 bytes.
 * Remaining difference: 628/628 bytes and frame 0x50 agree, but entry register ownership differs
 * from +8 and scalar/controller scheduling remains different. The final rotation/angle copies
 * intentionally remain ordinary TI transfers: retail interleaves their loads/stores and puts the
 * final SQ in a JAL delay slot; opaque qcopy increased the body to 632 bytes.
 * Reopen when: Independent controller/object field and allocation evidence; do not force shared
 * copies where the measured call-delay schedule requires ordinary transfers.
 */

#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
extern f32 D_L04_001B1870 __attribute__((sda));
extern u8 D_L04_001BFAC0[];
extern TI128 D_L04_001BFB00;
extern f32 func_00283248(f32, f32);
extern f32 func_00283B98(f32, f32);
extern float func_002A7CA0(void *, float *, f32, f32, f32, f32);
extern int func_00283CF0(f32);
extern void func_L04_0033D0C0(void *, void *);
extern void func_002C9218(int, void *, void *, f32);
extern void func_002AD0E0(void *, void *, void *, void *, void *, void *);
extern f32 func_002A89A8(void *, int, f32);
extern int func_002AD0B0(void *);
extern void func_L04_00344568(void *, void *, f32);

void func_L04_0044D428(u8 *object) {
    union { TI128 q; f32 f[4]; } angles;
    TI128 rotation;
    u8 *data = *(u8 **)(object + 0x68);
    f32 heading, floor;
    if (object[0x20] == 4) {
        heading = func_00283248(*(f32 *)(data + 0x240) - *(f32 *)(object + 0x10),
                               *(f32 *)(data + 0x244) - *(f32 *)(object + 0x14));
        heading = func_00283B98(heading, *(f32 *)(data + 0x314));
        func_002A7CA0(object, (float *)(data + 0x310), heading, 0.05f, 0.3f, 0.10471977293491364f);
        *(int *)(data + 0x140) = func_00283CF0(D_L04_001B1870 * 1024.0f);
        *(f32 *)(data + 0x144) = D_L04_001B1870;
        func_L04_0033D0C0(object, data + 0x140);
        if (*(int *)(data + 0x2F0) != -1)
            func_002C9218(*(int *)(data + 0x2F0), object + 0x10, object + 0x10, D_L04_001B1870);
    } else if (object[0x20] == 5) {
        heading = func_00283248(*(f32 *)(data + 0x240) - *(f32 *)(object + 0x10),
                               *(f32 *)(data + 0x244) - *(f32 *)(object + 0x14));
        heading = func_00283B98(heading, *(f32 *)(data + 0x314));
        func_002A7CA0(object, (float *)(data + 0x310), heading, 0.05f, 0.3f, 0.10471977293491364f);
    }
    if (*(void **)(data + 0x320)) {
        angles.q = 0;
        func_002AD0E0(object, *(void **)(data + 0x320), object + 0x10, object + 0xF0, object + 0x10, &angles);
        *(f32 *)(object + 0xF8) = angles.f[2];
    }
    if (object[0x95] != 3) {
        *(f32 *)(data + 0x324) += 0.0027222223579883575f;
        *(f32 *)(object + 0x18) -= *(f32 *)(data + 0x324) - 2.0f;
        floor = func_002A89A8(object + 0x10, 0, 0.5f);
        *(f32 *)(object + 0x18) -= 2.0f;
        if (*(f32 *)(object + 0x18) < floor) {
            u8 *controller = D_L04_001BFAC0;
            if (*(void **)(controller + 0x18)) {
                if (func_002AD0B0(*(void **)(controller + 0x18))) {
                    *(void **)(data + 0x320) = *(void **)(controller + 0x18);
                } else if (*(void **)(data + 0x320)) {
                    *(void **)(data + 0x320) = 0;
                }
            } else if (*(void **)(data + 0x320)) {
                *(void **)(data + 0x320) = 0;
            }
            *(f32 *)(object + 0x18) = floor;
            *(f32 *)(data + 0x324) = 0;
        }
    }
    if (*(void **)(data + 0x320)) {
        rotation = *(TI128 *)(object + 0xF0);
        angles.q = D_L04_001BFB00;
        func_L04_00344568(&angles, &rotation, *(f32 *)(object + 0xF8));
    }
}
