/* -O2 -G0; US and US2: 16_snivelak: 624 bytes, expected 644; 0/1 each.
   PAL: absent from catalogue. 624 versus 644 bytes; collision flag conversion and saved-register allocation differ. Natural arrays, scalar hit flag and six-particle loop tried. Reopen with a matching lifetime/boolean spelling. */
#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_0029F338(void *);
extern s32 func_00282948(void *);
extern void func_00282CC0(void *, void *, void *);
extern u8 D_L16_001B9B00[];
extern void func_00283958(void *, void *);
extern void func_00283738(void *, void *, void *);
extern s32 func_002A9640(void *, s32, s32);
extern s32 func_00277258(void *, s32, void *, float);
extern void func_0032DA58(void *, void *, void *, float);
extern void func_002A8C28(void *, void *, s32, s32, s32, s32, float, float, float);
extern void func_002AB6D8(void *, void *);
extern void func_002A7A00(void *, float, float);
extern float func_002A7878(float, float);
extern void func_00273730(void *, s32, s32, s32, void *, void *, void *, s32, float, float);

void func_L16_004133B0(u8 *arg)
{
    float rotation[12];
    float toward[4];
    float velocity[4];
    u8 *state;
    u8 *pos;
    u8 *basis;
    u8 *angles;
    s32 hit;
    s32 old;
    s32 i;
    s32 kind;
    float speed;
    float life;
    state = *(u8 **)(arg + 0x68);
    if (arg[0x20] == 0) {
        func_00282CC0(arg + 0x10, arg + 0x10, state);
        if (func_00282948(state + 0x30) && !arg[0x31]) func_0029F338(arg);
    } else if (arg[0x20] == 2) {
        pos = arg + 0x10;
        func_00282CC0(pos, pos, state);
        basis = arg + 0xC0;
        *(float *)(state + 8) -= *(float *)(state + 0x34);
        func_00283958(state + 0x20, rotation);
        func_00283738(basis, rotation, basis);
        hit = func_002A9640(arg, 0x10000, 0) != 0;
        old = (*(u16 *)(arg + 0x96))++;
        if (old > 90 && func_00277258(pos, 0, arg, 1.0f)) hit = 1;
        if (hit) {
            func_00282CF0(toward, D_L16_001B9B00, pos);
            angles = arg + 0xF0;
            func_00282F20(toward, toward, 1.0f);
            func_0032DA58(arg, pos, toward, 0.0f);
            func_002A8C28(arg, pos, 0x10001, 0, 1, 0, 4.0f, 20.0f, 2.0f);
            func_002AB6D8(basis, angles);
            for (i = 0; i < 6; i++) {
                func_002A7A00(velocity, 0.0f, 0.33333334f);
                func_00282CC0(velocity, velocity, state);
                kind = *(s16 *)(arg + 0xAA);
                speed = func_002A7878(180.0f, 720.0f);
                life = func_002A7878(5.0f, 15.0f);
                func_00273730(arg, 2, kind, i, pos, angles, velocity, 255, speed, life);
            }
            func_0029F338(arg);
        }
    }
}
