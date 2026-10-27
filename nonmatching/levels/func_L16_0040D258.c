/* Complete retained C reconstruction; not linked or counted.
 * Qualified compiler profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por.
 * Measured 2026-10-25: 660/656 bytes, frame 0x60. US and US2 contain the
 * function; PAL has no matching catalogue identity.
 * The complete clear, velocity and position vectors are retained. The ordinary
 * TI copy intentionally spans a bone-query call: retail loads before JAL and
 * stores in its delay slot, so the opaque qcopy helper cannot model this event.
 * Moving the real bone increment after the lifetime draw, directly passing the
 * first size draw, and giving both phases separate counters all produced the
 * identical full object. These tied directions are closed pending new evidence.
 * All eight particle GPR inputs and the pointer/null factory result contract
 * remain intact. An unused AAA00 declaration now has its true float return;
 * this does not change the function's object. No coverage or native credit.
 * Reopen with an independently justified loop/call-setup lifetime rather than
 * another equivalent spelling, a register pin or an artificial memory access.
 */
#include "common.h"
typedef int BossQuadword __attribute__((mode(TI)));
extern unsigned int D_L16_001B2648;
extern u8 *D_L16_001FE7C0[];
extern u8 *D_L16_001B2C0C;
extern float D_L16_001B9B00[4];
extern float D_L16_001B1750 __attribute__((sda));
extern float D_L16_001B18CC __attribute__((sda));
extern float D_L16_001B18D0 __attribute__((sda));
extern float D_L16_001B18D4 __attribute__((sda));
extern float func_002A7878(float, float);
extern int func_002A7820(int, int), func_002A77E0(int);
extern void func_0029FCC0(char *, int, char *);
extern void *func_002BAE50(void *, void *, int, int, int, int, int, int);
extern void func_00282F20(void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_002AAC80(float *, float, float, float, float);
extern float func_00283248(float, float);
extern float func_002AAA00(float *, float *, int, float, float, float, float);
extern int func_002A8D70(float, float, float, void *, int, int, int, int, int);
extern void func_L16_00410FA8(u8 *);
extern u8 *func_0029EFD0(int);
extern void func_002B37E8(u8 *, u8 *);
extern void func_002A7750(u8 *, int, int);
extern void func_00282C90(void *);
extern int func_00283DB8(void *, float);
extern void func_002830C0(void *, void *, void *);
extern float func_00283B98(float, float), func_00283180(float), func_00283198(float);
extern int func_00283CF0(float);
extern void func_0029F338(void *), func_002A0F48(void *);
extern void func_L16_004133B0(u8 *);

void func_L16_0040D258(u8 *moby)
{
    float position[4] __attribute__((aligned(16)));
    float velocity[4] __attribute__((aligned(16)));
    float clear[4] __attribute__((aligned(16)));
    int bone, lifetime, size;
    for (bone = 5; bone < 8; bone++) {
        *(BossQuadword *)clear = 0;
        clear[2] = -(func_002A7878(4.5f, 5.5f) * 0.016666668f);
        *(BossQuadword *)velocity = *(BossQuadword *)clear;
        func_0029FCC0((char *)moby, bone, (char *)position);
        if (D_L16_001B2648 & 1) {
            size = func_002A7820(18, 22);
            func_002BAE50(position, velocity, 0xcf0000ff, 0xcf, size, 180, -10, 1);
        } else {
            size = func_002A7820(20, 24);
            func_002BAE50(position, velocity, 0x6000ffff, 0x80, size, 350, -10, 1);
        }
        lifetime = func_002A7820(20, 90);
        size = func_002A7820(10, 15);
        func_002BAE50(position, velocity, 0xefff7f4f, 0xff0000, size, lifetime, -lifetime, 1);
    }
    for (bone = 3; bone < 5; bone++) {
        func_00282F20(velocity, moby + 0xc0, -(func_002A7878(4.5f, 5.5f) * 0.016666668f));
        func_0029FCC0((char *)moby, bone, (char *)position);
        if (D_L16_001B2648 & 1) {
            size = func_002A7820(18, 22);
            func_002BAE50(position, velocity, 0xcf0000ff, 0xcf, size, 50, -10, 1);
        } else {
            size = func_002A7820(20, 24);
            func_002BAE50(position, velocity, 0x6000ffff, 0x80, size, 100, -10, 1);
        }
        lifetime = func_002A7820(10, 25);
        size = func_002A7820(10, 15);
        func_002BAE50(position, velocity, 0xefff7f4f, 0xff0000, size, lifetime, -lifetime, 1);
    }
}
