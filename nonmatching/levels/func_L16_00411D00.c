/* -O2 -G8; US and US2: 16_snivelak: instruction at +0x12c differs; 0/1 each.
   PAL: absent from catalogue. Vector arrays and mixed absolute/GP declarations reconstruct all calls. Equal 460-byte body differs at +0x12c in call-argument and field-store scheduling, then a byte-conversion scratch register. Reopen with a matching scheduling witness. */
#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
extern void func_0032C700(void *, s32, s32, s32, s32, s32, s32, s32, float, float,
                          s32, s32, s32, s32);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_002A7878(float, float);
extern void func_002A7A00(void *, float, float);
extern void func_00283098(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern float func_L00_0031CDD0(void *, void *, s32, float, float);
extern void func_L16_0041F1F0(void *, void *, void *, s32, float, float);
extern s32 D_L16_001B17A0 __attribute__((sda));
extern float D_L16_001B17B0 __attribute__((sda));
extern float D_L16_001B17B8 __attribute__((sda));
extern float D_L16_001B17BC[] __attribute__((sda));

void func_L16_00411D00(u8 *arg)
{
    float random[4];
    float origin[4];
    float target[4];
    float direction[4];
    u8 *state;
    float scale;
    float speed;
    float zero = 0.0f;
    float one = 1.0f;
    float tick = 0.016666668f;
    state = *(u8 **)(arg + 0x68);
    func_002A7A00(random, zero, one);
    func_00283098(origin, &D_L16_001B17A0, arg + 0xC0);
    func_00282CC0(origin, origin, arg + 0x10);
    func_00282CC0(origin, origin, random);
    func_00282D30(target, random, 3.0f);
    target[2] = zero;
    func_00282CC0(target, target, *(u8 **)(state + 0x24C) + 0x10);
    scale = D_L16_001B17B0 * tick;
    speed = func_002A7878(D_L16_001B17B8, D_L16_001B17BC[0]) * 0.00027777778f;
    func_00282CF0(direction, target, origin);
    direction[2] = zero;
    func_00282F20(direction, direction, scale);
    direction[2] = func_L00_0031CDD0(origin, target, 0, D_L16_001B17B0 * tick, -speed);
    func_0032C700(origin, 0, 25, 20, 20, 20, 45, 1, one, 20.0f, 1, 0, 0, 0);
    func_L16_0041F1F0(*(void **)(state + 0x1F0), origin, direction, 0, speed, (float)state[0x36]);
}
