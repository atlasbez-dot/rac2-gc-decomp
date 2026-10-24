/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -g -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -fno-gcse.
 * Reported final C / retail: 1476 / 1476 bytes; size equality is not a match.
 * us: 0/1 placements.
 * us2: 0/1 placements.
 * pal: absent from catalogue (not a match).
 * Residual: Frame 0x70 versus 0x60; pointer high halves, mixed GP/absolute entity table access, loop/constant allocation.
 * Reopening condition: New concrete supported compiler/API/identity hypothesis only; see retained source comment. No repeated flag or permutation sweep.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete retained controller, 1476/1476 bytes at -O2 -G8 -g
   -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -fno-gcse.
   Four trials: 1476 (frame0x70), 1468 mno-split/g, 1492 scoped loops/g,
   1476 no-GCSE. Retail frame0x60; independent address lifetimes and mixed
   GP/absolute reads of the same entity-table pointer remain. US/US2 0/1,
   PAL absent. Reopen only with a supported address-lifetime hypothesis.
   The two scratch vectors are also reused as four integer completion flags. */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 quad; float f[4]; s32 i[4]; } ControllerScratch;
extern u8 *D_L02_001B359C __attribute__((nosda));
extern u8 *D_L02_001B368C __attribute__((nosda));
extern u8 D_L02_001BA500[];
extern u8 D_0019B2E8[];
extern s32 D_001A79F0 __attribute__((sda));
extern u8 D_00189E20[];
extern TI128 D_L02_001C0960;
extern float D_L02_001A8F20[4];
extern void func_L02_0031F858(s32, s32);
extern float func_002A7940(void);
extern float func_00282E80(void *, void *);
extern void func_002A7750(u8 *, u8, s32);
extern s32 func_L02_004127F8(u8 *);
extern float func_002AA2E8(float *, float, float);
extern void func_0029F338(void *);
extern void func_002A0430(u32);
extern void func_002DF3F8(void *, void *);
extern s32 func_002761F8(void *, void *, s32, void *, s32);
extern float func_002A7878(float, float);
extern s32 func_002A7820(s32, s32);
extern s32 func_002A77E0(s32);
extern void *func_002C3150(void *, void *, u32, s32, s32, s32, float);
extern void func_00282D60(float *, u8 *, float);
extern s32 func_00283DB8(float *, float);
extern float func_00283B98(float, float);
extern void func_L00_002E6CF0(void *, void *);
extern void func_L02_00411D18(u8 *);

/* Track the four linked actors and fade the controller's visible effect. */
void func_L02_00411750(u8 *object)
{
    ControllerScratch scratch[2];
    u8 *state = *(u8 **)(object + 0x68);
    s32 *ids;
    float *phase;

    switch (object[0x20]) {
    case 0:
        {
        s32 i;
        if (D_0019B2E8[object[0xB0] + (D_001A79F0 << 4)] & 0x80) {
            func_L02_0031F858(*(s32 *)(state + 0x10), 1);
            func_0029F338(object);
            return;
        }
        *(float *)(state + 0x1C) = 1.0f;
        *(float *)(state + 0x2C) = func_002A7940();
        *(s32 *)(state + 0x20) = 0;
        *(float *)(state + 0x24) = 0.5f;
        {
            float visible = 1.0f;
            if (func_00282E80(D_L02_001BA500, object + 0x10) > 66.0f)
                visible = 0.0f;
            *(float *)(state + 0x1C) = visible;
        }
        i = 3;
        phase = (float *)(state + 0x3C);
        do { *phase-- = 1.0f; } while (--i >= 0);
        object[0x30] = 0x65;
        func_002A7750(object, 1, -1);
        object[0x31] = 0;
        *(u16 *)(object + 0x34) |= 1;
        break;
        }
    case 1:
        {
            s32 ready = 1;
            s32 i;
            ids = (s32 *)state;
            for (i = 0; i < 4; i++) {
                if (!func_L02_004127F8(D_L02_001B359C + (*ids << 8))) {
                    ready = 0;
                    break;
                }
                ids++;
            }
            if (ready)
                func_002A7750(object, 2, -1);
        }
        break;
    case 2:
        func_002AA2E8((float *)(state + 0x1C), 0.0f, 0.016666668f);
        if (*(float *)(state + 0x1C) <= 0.0f) {
            s32 i;
            ids = (s32 *)state;
            i = 3;
            do { func_0029F338(D_L02_001B359C + (*ids++ << 8)); } while (--i >= 0);
            func_L02_0031F858(*(s32 *)(state + 0x10), 1);
            func_002A0430(object[0xB0]);
            {
                u8 *record = D_L02_001B368C + (*(s32 *)(state + 0x14) << 7);
                func_002DF3F8(record + 0x30, record + 0x70);
            }
            func_0029F338(object);
            return;
        }
        break;
    }
    if (*(float *)(state + 0x1C) != 0.0f) {
        if (*(u8 **)(D_00189E20 + 0x270) == object || *(u8 **)(D_00189E20 + 0x26C) == object) {
            scratch[0].quad = *(TI128 *)(D_00189E20 + 0xE0);
            scratch[0].f[0] = *(float *)(object + 0x10);
            if (func_002761F8(D_00189E20 + 0xE0, scratch[0].f, 2, *(void **)(D_00189E20 + 0x2290), 0)) {
                s32 lifetime;
                s32 shade;
                scratch[1].quad = D_L02_001C0960;
                scratch[1].f[2] += func_002A7878(-0.5f, 0.5f);
                lifetime = (u8)func_002A7820(30, 60);
                shade = (u8)func_002A77E0(255);
                func_002C3150(scratch[1].f, D_L02_001A8F20, 0x60106070, lifetime, shade, 0, 1.0f);
            }
        }
        func_00282D60(scratch[0].f, object, 0.0009765625f);
        if (func_00283DB8(scratch[0].f, 80.0f) != -1) {
            *(float *)(state + 0x2C) = func_00283B98(*(float *)(state + 0x2C), 0.040724356f);
            *(float *)(state + 0x28) += 0.020833334f;
            if (*(float *)(state + 0x28) > 1.0f)
                *(float *)(state + 0x28) -= 1.0f;
            {
            s32 i;
            phase = (float *)(state + 0x20);
            i = 1;
            do {
                *phase += 0.011100001f;
                if (*phase > 1.0f)
                    *phase -= 1.0f;
                phase++;
            } while (--i >= 0);
            }
            func_L00_002E6CF0(func_L02_00411D18, object);
        }
        if (func_00282E80(object + 0x10, D_L02_001BA500) > 68.0f)
            func_002AA2E8((float *)(state + 0x1C), 0.0f, 0.008333334f);
        else
            func_002AA2E8((float *)(state + 0x1C), 1.0f, 0.008333334f);
    } else if (*(float *)(state + 0x1C) < 1.0f && func_00282E80(object + 0x10, D_L02_001BA500) < 64.0f)
        func_002AA2E8((float *)(state + 0x1C), 1.0f, 0.008333334f);

    ids = (s32 *)state;
    {
        s32 i = 3;
        s32 *out = scratch[0].i;
        do { *out++ = !func_L02_004127F8(D_L02_001B359C + (*ids++ << 8)); } while (--i >= 0);
    }
    if (*(float *)(state + 0x34) != 0.0f && scratch[0].i[0] == 0 && scratch[0].i[1] == 0)
        *(float *)(state + 0x34) = 0.0f;
    if (*(float *)(state + 0x38) != 0.0f && scratch[0].i[2] == 0 && scratch[0].i[3] == 0)
        *(float *)(state + 0x38) = 0.0f;
    if (*(float *)(state + 0x30) != 0.0f && scratch[0].i[0] == 0)
        *(float *)(state + 0x30) = 0.0f;
    if (*(float *)(state + 0x3C) != 0.0f && scratch[0].i[3] == 0)
        *(float *)(state + 0x3C) = 0.0f;
}
