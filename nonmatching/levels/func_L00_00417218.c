/* func_L00_00417218: Opus closer M1 near miss, 26 October 2026.
   Profile: -O2 -G0 -ffunction-sections.
   Callees renamed to their real functions (func_00283248, func_002A78D8, func_00283CF0 returns int, func_00283B98, func_00283180, func_00283198); retail constant is -1.5707965f. With the current compiler this is 392/404 bytes: cc1 hoists 4.0f, retail hoists 0.0f into $f25 and rematerialises 4.0f in the loop. */
#include "common.h"
extern float func_00283248(float, float);
extern float func_002A78D8(float, float);
extern int func_00283CF0(float);
extern float func_00283B98(float, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern unsigned char *func_L00_0033FFB8(void *, void *, int);
extern char D_L00_001A8F20[] __attribute__((sda));
extern struct { char pad[0x140]; float x, y; } D_L00_001B8C80;

void func_L00_00417218(char *object) {
    float v[8];
    float angle;
    int i;

    for (i = 24; i >= 0; i--) {
        angle = func_00283248(D_L00_001B8C80.x - *(float *)(object + 0x10),
                              D_L00_001B8C80.y - *(float *)(object + 0x14));
        func_00283CF0(func_002A78D8(1.0f, 2.0f));
        v[0] = *(float *)(object + 0x10) + func_002A78D8(-0.25f, 0.25f);
        v[1] = *(float *)(object + 0x14) + func_002A78D8(-0.25f, 0.25f);
        v[2] = *(float *)(object + 0x18) + func_002A78D8(-0.25f, 0.25f);
        angle = func_00283B98(angle, func_002A78D8(0.0f, -1.5707964f));
        v[4] = func_00283180(angle) * 0.016666668f * 4.0f;
        v[5] = func_00283198(angle) * 0.016666668f * 4.0f;
        v[6] = 0.075f;
        func_L00_0033FFB8(v, D_L00_001A8F20, 300);
    }
}
