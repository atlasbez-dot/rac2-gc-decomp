/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * 588/596 bytes; 0/1 USA v1.01 and USA v2.00 places.
 * The canonical function is absent from the PAL catalogue.
 * Remaining: Float temporaries spanning the two particle loops are allocated differently; the
 * retail move into the second-loop scale and loop setup are not reproduced.
 * Reopen with: Independent float lifetime/loop evidence. Disabling the second loop
 * optimization worsened this to 584 bytes and a smaller frame.
 */

#include "common.h"
typedef int OozlaQuad __attribute__((mode(TI)));
extern float D_L01_001B2F48 __attribute__((sda));
extern float func_002A89A8(void *, int, float);
extern void *func_00312D58(void *, float);
extern float func_002A7878(float, float);
extern float func_002A7940(void);
extern float func_00283180(float);
extern float func_00283198(float);
extern int func_002A77E0(int);
extern int func_002A7820(int, int);
extern void func_002C19D8(void *, void *, int, float, float);
extern void func_002BFB38(void *, void *, int, int);
void func_L01_003A6028(char *object)
{
    float center[4], velocity[4], position[4];
    float angle, radius;
    int i, j, type, lifetime;
    int scale = 2;
    float multiplier;
    qcopy(center, (object + 0x10));
    multiplier = scale;
    center[2] = D_L01_001B2F48 = func_002A89A8(object + 0x10, 0, 0.5f);
    func_00312D58(center, 4.5f);
    for (i = 4; i >= 0; --i) {
        velocity[0] = *(float *)(object + 0x10) + scale * func_002A7878(-0.3f, 0.3f);
        velocity[1] = *(float *)(object + 0x14) + scale * func_002A7878(-0.3f, 0.3f);
        velocity[2] = D_L01_001B2F48;
        func_002C19D8(velocity, &D_L01_001B2F48, -1, scale * func_002A7878(0.3f, 0.6f), 5250.0f);
    }
    {
    float secondScale = multiplier;
    for (j = 39; j >= 0; --j) {
        angle = func_002A7940();
        radius = secondScale * func_002A7878(0.0f, 0.0500000045f);
        velocity[0] = func_00283180(angle) * radius;
        velocity[1] = func_00283198(angle) * radius;
        velocity[2] = secondScale * func_002A7878(0.033333335f, 0.083333336f);
        position[0] = *(float *)(object + 0x10) + velocity[0] * 8.0f;
        position[1] = *(float *)(object + 0x14) + velocity[0] * 8.0f;
        position[2] = D_L01_001B2F48 - func_002A7878(0.0f, 0.2f);
        type = func_002A77E0(2);
        lifetime = func_002A7820(90, 120);
        func_002BFB38(position, velocity, type, scale * lifetime);
    }
    }
}
