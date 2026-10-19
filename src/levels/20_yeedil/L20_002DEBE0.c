#include "include_asm.h"

extern void func_L00_002F3478(void);

extern void func_002B49E0(int a, int b, int c, int d, int e);

extern int D_001FFE40[];

extern int D_001A8FDC;

extern int D_00294F98;

INCLUDE_ASM("asm/levels", func_L20_002DEBE0);

INCLUDE_ASM("asm/levels", func_L20_00310E38);

INCLUDE_ASM("asm/levels", func_L20_00330A68);

INCLUDE_ASM("asm/levels", func_L20_0036AE68);

INCLUDE_ASM("asm/levels", func_L20_0036E720);

typedef struct YeedilEffectState {
    char pad00[0x30];
    int mode;
    int frame;
    char pad38[0x154];
    char *first;
    int unused190;
    char *second;
} YeedilEffectState;
extern YeedilEffectState D_L20_001BDCC0;
extern int D_L20_001A8F00[] __attribute__((sda));
extern void func_0032C700(void *, int, int, int, int, int, int, int,
                         int, int, int, int, float, float);
extern void func_0029FCC0(void *, int, void *);
extern float func_002A7878(float, float);
extern float func_002A7940(void);
extern void func_002AF000(void *, float, float, float);
extern int func_002A77E0(int);
extern void func_002BE278(void *, void *, int, float);

void func_L20_0039AA98(unsigned char *object)
{
    float position[4], velocity[4];
    float speed, heading, tilt;
    YeedilEffectState *state;

    switch (object[0x20]) {
    case 0:
        object[0x30] = 0xFF;
        object[0x20] = 1;
        break;
    case 1:
        if (D_L20_001A8F00[0] != 2)
            break;
        state = &D_L20_001BDCC0;
        if (state->mode != 7)
            break;
        if (state->frame == 157)
            func_0032C700(state->second + 0x10, 1, 40, 20, 30, 40, 50, 1,
                          1, 1, 0, 0, 1.5f, 20.0f);
        if ((unsigned int)(state->frame - 171) < 149) {
            func_0029FCC0(state->first, 0, position);
            position[2] += 0.03f;
            speed = func_002A7878(0.028333336114883423f, 0.05000000447034836f);
            heading = func_002A7940();
            tilt = func_002A7878(0.523598849773407f, 2.6179940700531006f);
            func_002AF000(velocity, speed, heading, tilt);
            if (func_002A77E0(2))
                func_002BE278(position, velocity, 0, func_002A7878(1470.0f, 7350.0f));
        }
        break;
    }
}

INCLUDE_ASM("asm/levels", func_L20_0039BB18);

INCLUDE_ASM("asm/levels", func_L20_0039BDF0);

INCLUDE_ASM("asm/levels", func_L20_0039BEC8);
