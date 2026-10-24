/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -g -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 2492 / 2528 bytes; size equality is not a match.
 * us: 0/1 placements; 2492/2528 bytes.
 * us2: 0/1 placements; 2492/2528 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Exact frame 0xE0. CFG joins, address caching, mixed GP/absolute accesses and camera argument setup remain.
 * Reopening condition: New concrete supported compiler/API/identity hypothesis only; see retained source comment. No repeated flag or permutation sweep.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete retained lift controller. 2492/2528 bytes, exact 0xE0 frame,
   with -O2 -G16 -Wa,-G16 -ffunction-sections -g -frac2-qcopy
   -frac2-qcopy-barrier. Three meaningful trials: default 2480; no-GCSE 2428
   with wrong 0xC0 frame; source case order 0,4,1,2,3 gives 2492.
   Control-flow joins, mixed absolute/GP accesses, pointer lifetimes and
   outgoing camera-call setup remain. The 16-byte template has its actual
   extent under G16. All five cases, camera arguments and variadic double
   promotion are preserved. Reopen with a concrete CFG/address-lifetime model. */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 quad; float f[4]; } LiftVector;
extern u8 D_00189E20[];
extern u8 D_0019B2E8[];
extern u8 D_00188660[];
extern u8 D_001A7B1E __attribute__((nosda));
extern s32 D_001A79F0 __attribute__((nosda));
extern u8 *D_L02_001B368C __attribute__((nosda));
extern s32 D_L02_001B30C8 __attribute__((nosda));
extern float D_L02_001B2FE0 __attribute__((nosda));
extern float D_L02_001B1C50 __attribute__((sda));
extern float D_L02_001B1C54 __attribute__((sda));
extern LiftVector D_L02_001B1C60 __attribute__((sda));
extern float D_L02_001B1C6C __attribute__((nosda));
extern char D_L02_001B1C70[];
extern u8 D_L02_001BA500[];
extern void func_00282A28(void);
extern void func_002A7750(u8 *, u8, s32);
extern void func_002A7470(void *, s32, s32, s32);
extern void func_00282D60(void *, void *, float);
extern s32 func_00283DB8(void *, float);
extern void func_0029F338(void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern float func_00282E20(void *);
extern void func_002AFDD8(char *, char *, char *, char *);
extern double func_001234F0(float);
extern void func_0026FEB8(const char *, ...);
extern void func_L00_002C42E0(s32, s32);
extern float func_00282E80(void *, void *);
extern void func_003355A8(s32);
extern s32 func_002B3868(u8 *);
extern void func_00335438(void *, void *, s32, s32, s32);
extern void func_L00_002D40A0(void *, s32, float);
extern s32 func_002E5CF8(s32, s32, char *);
extern float func_002AA2E8(float *, float, float);
extern void func_00282F20(void *, void *, float);
extern s32 func_002A8C28(void *, void *, u32, float, float, float, s32, s32, s32);
extern float func_00283248(float, float);
extern void func_002AA800(float *, s32, float, float);
extern void func_00335370(void *);
extern void func_003353C8(void *);
extern void func_002E59F8(s32);
extern void func_002A7398(s8 *, s32, s32);
extern void func_002833F0(void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_L00_002B9D60(void *, void *, s32, s32);
extern void func_L00_0042A500(s32);
extern void func_L02_00413730(u8 *);
extern void func_002AD6F0(void *, void *, void *, void *);

/* Move between the two lift poses, coordinating the camera and boarding state. */
void func_L02_00412D50(u8 *object)
{
    LiftVector old_position;
    LiftVector old_rotation;
    LiftVector delta;
    LiftVector point;
    LiftVector aim;
    LiftVector launch;
    LiftVector rotation;
    u8 *state = *(u8 **)(object + 0x68);
    u8 *record;
    s32 side;
    s32 slot;
    float distance;
    float target;
    s32 i;

    old_position.quad = *(TI128 *)(object + 0x10);
    old_rotation.quad = *(TI128 *)(object + 0xF0);
    switch (object[0x20]) {
    case 0:
        object[0x30] = 0xFF;
        *(s32 *)(state + 0x84) = -1;
        if (*(s32 *)(state + 0x7C) == -1 || *(s32 *)(state + 0x80) == -1) {
            func_0029F338(object);
            return;
        }
        if (*(s32 *)(state + 0x60) == -1 || *(s32 *)(state + 0x64) == -1)
            func_00282A28();
        if (*(s32 *)(state + 0x68) == -1 || *(s32 *)(state + 0x6C) == -1)
            func_00282A28();
        if (*(s32 *)(state + 0x78) == -1)
            func_002A7750(object, 1, -1);
        else {
            if (D_001A7B1E) {
                func_0029F338(object);
                return;
            }
            *(s32 *)(object + 0x98) = 0;
            *(u16 *)(object + 0x34) = (*(u16 *)(object + 0x34) & 0xEFFF) | 0x41;
            func_002A7750(object, 4, -1);
        }
        if (object[0x43] != 2)
            func_002A7470(object, 2, 0, 1);
        record = D_L02_001B368C + (*(s32 *)(state + 0x7C) << 7);
        *(TI128 *)(state + 0x90) = *(TI128 *)(record + 0x30);
        *(TI128 *)(state + 0xA0) = *(TI128 *)(record + 0x70);
        break;
    case 4:
        if (D_0019B2E8[*(s32 *)(state + 0x78) + (D_001A79F0 << 4)] & 0x80) {
            func_00282D60(&delta, object, 0.0009765625f);
            if (func_00283DB8(&delta, 64.0f) == -1) {
                *(u16 *)(object + 0x34) = (*(u16 *)(object + 0x34) & 0xFFBE) | 0x1000;
                *(u32 *)(object + 0x98) = *(u32 *)(*(u8 **)(object + 0x24) + 0x10);
                func_002A7750(object, 1, -1);
            }
        }
        break;
    case 1:
        if (*(s32 *)(state + 0x78) != -1 && D_001A7B1E) {
            func_0029F338(object);
            return;
        }
        if (*(u8 **)(D_00189E20 + 0x33C) == object && *(s32 *)(D_00189E20 + 0x340)) {
            func_00282CF0(&delta, D_00189E20 + 0x80, object + 0x10);
            point.quad = 0;
            point.f[2] = -0.69f;
            point.f[0] = -1.2f;
            func_00283098(&point, &point, object + 0xC0);
            func_00282CC0(&point, &point, object + 0x10);
            func_00282CF0(&aim, &point, D_00189E20 + 0x80);
            distance = func_00282E20(&aim);
            func_002AFDD8((char *)object, (char *)&delta, (char *)&delta, 0);
            if (delta.f[2] < -0.6f) {
                func_0026FEB8(D_L02_001B1C70, func_001234F0(distance));
                func_L00_002C42E0(0x6F, 1);
                func_002A7750(object, 2, -1);
            }
        } else if ((D_L02_001B30C8 & 0x3F) == 0) {
            float current;
            side = (*(s32 *)(state + 0xBC) + 1) & 1;
            record = D_L02_001B368C + (*(s32 *)(state + 0x7C + side * 4) << 7);
            distance = func_00282E80(D_00189E20 + 0x80, record + 0x30);
            record = D_L02_001B368C + (*(s32 *)(state + 0x7C + *(s32 *)(state + 0xBC) * 4) << 7);
            current = func_00282E80(D_00189E20 + 0x80, record + 0x30);
            if (distance < current) {
                *(s32 *)(state + 0xBC) = side;
                record = D_L02_001B368C + (*(s32 *)(state + 0x7C + side * 4) << 7);
                *(TI128 *)(state + 0x90) = *(TI128 *)(record + 0x30);
                *(TI128 *)(state + 0xA0) = *(TI128 *)(record + 0x70);
                *(TI128 *)(object + 0x10) = *(TI128 *)(state + 0x90);
                *(TI128 *)(object + 0xF0) = *(TI128 *)(state + 0xA0);
            }
        }
        break;
    case 2:
        if (*(s32 *)(D_00189E20 + 0x340) == 0) {
            func_003355A8(0);
            break;
        }
        if (func_002B3868(object)) {
            func_00335438(D_L02_001BA500, D_L02_001BA500 + 0x10, 1, 0, 0);
            delta.quad = 0;
            delta.f[0] = -1.2f;
            delta.f[2] = -0.69f;
            func_00283098(&delta, &delta, object + 0xC0);
            func_00282CC0(&delta, &delta, object + 0x10);
            func_L00_002D40A0(&delta, 0, *(float *)(object + 0xF8));
            D_00189E20[0x22B6] = 1;
            func_002E5CF8(1, 0, (char *)object);
            if (object[0x43])
                func_002A7470(object, 0, 0, 45);
        }
        func_002AA2E8((float *)(state + 0xCC), D_L02_001B1C50 * 0.016666668f, D_L02_001B1C54 * 0.00027777778f);
        func_00282F20(&delta, object + 0xC0, *(float *)(state + 0xCC));
        delta.f[2] = 0.0f;
        func_00282CC0(state + 0x90, state + 0x90, &delta);
        i = 0;
        do {
            point.quad = D_L02_001B1C60.quad;
            if (i)
                point.f[1] = -point.f[1];
            func_00283098(&point, &point, object + 0xC0);
            func_00282CC0(&point, &point, object + 0x10);
            func_002A8C28(object, &point, 0x10000, D_L02_001B1C6C, 1.0f, 1.0f, 0, 1, 0);
        } while (++i < 2);
        point.quad = *(TI128 *)D_L02_001BA500;
        point.f[2] += 0.016666668f;
        aim.quad = *(TI128 *)(D_L02_001BA500 + 0x10);
        distance = func_00282E80(&point, D_00189E20 + 0x80);
        target = func_00283248(distance, *(float *)(D_00189E20 + 0x88) - point.f[2]);
        func_002AA800(aim.f + 1, 0, -target, 0.013089969f);
        target = func_00283248(*(float *)(D_00189E20 + 0x80) - point.f[0], *(float *)(D_00189E20 + 0x84) - point.f[1]);
        func_002AA800(aim.f + 2, 0, target, 0.026179938f);
        func_00335370(&point);
        func_003353C8(&aim);
        {
            u16 previous = *(u16 *)(object + 0x96);
            u16 ticks = previous + 1;
            *(u16 *)(object + 0x96) = ticks;
            if (previous >= 121)
                func_002AA2E8(&D_L02_001B2FE0, 1.0f, 0.033333335f);
            else {
                if (ticks == 45)
                    func_L00_002C42E0(0x6F, 1);
                slot = *(s32 *)(state + 0x84);
                record = D_00188660 + slot * 0x70;
                if (*(u8 **)(record + 0x88) != object || !record[0x74])
                    *(s32 *)(state + 0x84) = func_002E5CF8(0, 4, (char *)object);
            }
        }
        if (D_L02_001B2FE0 >= 1.0f) {
            func_L00_002C42E0(0, 1);
            slot = *(s32 *)(state + 0x84);
            if (slot != -1) {
                record = D_00188660 + slot * 0x70;
                if (*(u8 **)(record + 0x88) == object && record[0x74])
                    func_002E59F8(slot);
            }
            *(s32 *)(state + 0x84) = -1;
            func_002A7398((s8 *)object, 2, 0);
            func_002A7750(object, 3, -1);
            side = (*(s32 *)(state + 0xBC) + 1) & 1;
            *(s32 *)(state + 0xBC) = side;
            record = D_L02_001B368C + (*(s32 *)(state + 0x7C + side * 4) << 7);
            *(TI128 *)(state + 0x90) = *(TI128 *)(record + 0x30);
            *(TI128 *)(state + 0xA0) = *(TI128 *)(record + 0x70);
            func_002833F0(object + 0xC0, state + 0xA0);
            record = D_L02_001B368C + (*(s32 *)(state + 0x60 + *(s32 *)(state + 0xBC) * 4) << 7);
            func_00282D30(&launch, record, -0.9f);
            func_00282CC0(&launch, &launch, record + 0x30);
            rotation.quad = *(TI128 *)(record + 0x70);
            func_L00_002B9D60(&launch, &rotation, 0, 1);
            func_L00_002D40A0(record + 0x30, 1, *(float *)(record + 0x78));
            func_003355A8(0);
            func_L00_0042A500(*(s32 *)(state + 0x68 + *(s32 *)(state + 0xBC) * 4));
            func_L02_00413730(object);
        }
        break;
    case 3:
        func_002AA2E8(&D_L02_001B2FE0, 0.0f, 0.033333335f);
        if (D_L02_001B2FE0 <= 0.0f) {
            *(float *)(state + 0xCC) = 0.0f;
            func_002A7750(object, 1, -1);
        }
        break;
    }
    if (object[0x31])
        func_L02_00413730(object);
    func_00282CF0(&delta, object + 0x10, &old_position);
    func_002AD6F0(state + 0x20, &delta, &old_rotation, object + 0xF0);
}
