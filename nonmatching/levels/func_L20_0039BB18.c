/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * 716/724 bytes. us: 0/1 places; us2: 0/1 places; pal: absent.
 * Remaining: Unsupported volatile contact loads are removed. The timer is an int32 pointer,
 * the incremented halfword value is interpreted in an unsigned 32-bit local,
 * the callback has its real one-pointer contract, and qcopy preserves the
 * complete velocity snapshot. The 0x70 frame agrees; contact-load CSE, object/
 * RNG-result saved-register priorities and float scheduling still differ.
 * Reopen with: Independent contact/counter lifetime evidence; never restore fake volatile
 * loads or the historical integer-value timer declaration.
 */

#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

typedef union {
    TI128 q;
    float f[4];
} L20_0039BB18_V4;

extern float D_L20_001AEC68 __attribute__((sda));

extern int func_00282948(int *);
extern float func_00282E80(void *, void *);
extern float func_002AA2E8(float *, float, float);
extern void func_0029F338(void *);
extern float func_002A7878(float, float);
extern int func_002A7820(int, int);
extern float func_002A7940(void);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_00282CC0(void *, void *, void *);
extern int func_002A77E0(int);
extern void func_002C3150(void *, void *, u32, int, int, int, float);
extern void func_L00_002E6CF0(void (*)(void *), void *);
extern void func_L20_0039BEC8(void *);

void func_L20_0039BB18(void *arg0)
{
    L20_0039BB18_V4 pos;
    L20_0039BB18_V4 vel;
    u32 s0;
    float t;
    float g;
    float angle;
    float rnd01;
    float rnd;
    float zero_arg;
    u32 old;
    unsigned long long c64;
    int m;
    int r;
    float r2;
    float rr;
    float rr2;

    s0 = *(u32 *)((u32)arg0 + 0x68);
    if (func_00282948((int *)(s0 + 4)) != 0)
        goto pathA;
    old = *(u16 *)((u32)arg0 + 0x96);
    c64 = old;
    *(u16 *)((u32)arg0 + 0x96) = old + 1;
    if (c64 < 11)
        goto check;
    if (*(u16 *)(*(u32 *)((u32)arg0 + 0xB8) + 0x34) & 1)
        goto pathA;
check:
    if (func_00282E80((void *)((u32)arg0 + 0x10),
                      (void *)(*(u32 *)((u32)arg0 + 0xB8) + 0x10)) > 0.1f) {
pathA:
        zero_arg = 0.0f;
        func_002AA2E8((float *)s0, zero_arg, 0.016666667f);
        if (*(float *)s0 == 0.0f) {
            func_0029F338(arg0);
            goto end;
        }
    } else {
        func_002AA2E8((float *)s0, 1.0f, 0.016666667f);
    }

common:
    g = D_L20_001AEC68;
    {
        float v = *(float *)(s0 + 0xC) + g * 0.016666667f;
        float w;
        *(float *)(s0 + 0xC) = v;
        if (v > 1.0f) {
            w = v - 1.0f;
        } else if (v < -1.0f) {
            w = v + 1.0f;
        } else {
            goto skip;
        }
        *(float *)(s0 + 0xC) = w;
    }
skip:
    rnd = func_002A7878(0.1f, 0.3f);
    m = func_002A7820(30, 60);
    vel.q = 0;
    r2 = func_002A7878(0.5f, 2.0f);
    vel.f[2] = -r2 * 0.016666667f;
    qcopy(&pos, &vel);
    rnd01 = func_002A7878(0.0f, 1.0f);
    angle = func_002A7940();
    vel.f[0] = func_00283180(angle) * rnd01;
    vel.f[1] = func_00283198(angle) * rnd01;
    vel.f[2] = 0.0f;
    rr = func_002A7878(1.0f, 10.0f);
    vel.f[2] = rr;
    rr2 = func_002A7878(1.0f, 10.0f);
    if (!(vel.f[2] > rr2)) {
        ;
    } else {
        vel.f[2] = rr2;
    }
    func_00282CC0(&vel, &vel, arg0 + 0x10);
    m &= 0xFF;
    r = func_002A77E0(255);
    func_002C3150(&vel, &pos, 0x60107080, m, r & 0xFF, 0, rnd);
    func_L00_002E6CF0(func_L20_0039BEC8, arg0);
end:
    return;
}
