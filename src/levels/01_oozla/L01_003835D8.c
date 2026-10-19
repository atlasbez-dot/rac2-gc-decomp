#include "include_asm.h"
#include "common.h"

typedef struct {
    u8 pad[0x1FB0];
    f32 f1FB0;
    f32 f1FB4;
} D00189E20_View;

extern D00189E20_View D_00189E20;

extern void func_00282948();

INCLUDE_ASM("asm/levels", func_L01_003835D8);

INCLUDE_ASM("asm/levels", func_L01_003839F0);

INCLUDE_ASM("asm/levels", func_L01_00388FD0);

INCLUDE_ASM("asm/levels", func_L01_003A5BB8);

INCLUDE_ASM("asm/levels", func_L01_003A6028);

INCLUDE_ASM("asm/levels", func_L01_003A6280);

INCLUDE_ASM("asm/levels", func_L01_003A6350);

void func_L01_003A6448(float *arg0, float *arg1) {
    *arg0 = -D_00189E20.f1FB0;
    *arg1 = -D_00189E20.f1FB4;
    if (*arg0 > 1.0f)
        *arg0 = 1.0f;
    else if (*arg0 < -1.0f)
        *arg0 = -1.0f;
    if (*arg1 > 1.0f)
        *arg1 = 1.0f;
    else if (*arg1 < -1.0f)
        *arg1 = -1.0f;
}

INCLUDE_ASM("asm/levels", func_L01_003A64F0);

INCLUDE_ASM("asm/levels", func_L01_003A6638);

INCLUDE_ASM("asm/levels", func_L01_003B1F08);

INCLUDE_ASM("asm/levels", func_L01_003B4200);

INCLUDE_ASM("asm/levels", func_L01_003B4480);

INCLUDE_ASM("asm/levels", func_L01_003B45D8);

void func_L01_003B46C8(char **arg0, int *arg1) {
    int i;

    if (*arg1 <= 0)
        return;
    i = 0;
    do {
        *(int *)(arg0[i] + 0x9C) = 0;
        i++;
    } while (i < *arg1);
}

INCLUDE_ASM("asm/levels", func_L01_003B4700);



void func_L01_003B4BD8(u8 *arg0) {
    char *s0 = *(char **)(arg0 + 0x68);

    if (arg0[0x21] != 0xFF) {
        if (*(int *)(s0 + 0x340) != 0) {
            func_00282948(*(int **)(s0 + 0x33C));
        }
    }
    *(int *)(s0 + 0x340) = 0;
}

int func_L01_003B4C20(u8 *arg0) {
    char *a1 = *(char **)(arg0 + 0x68);
    int r = 1;

    if (arg0[0x21] != 0xFF) {
        if (*(int *)(a1 + 0x340) == 0) {
            int *p = *(int **)(a1 + 0x33C);
            *p = *p + 1;
        }
    }
    *(int *)(a1 + 0x340) = r;
    return r;
}

INCLUDE_ASM("asm/levels", func_L01_003B4C58);

extern float func_002A89A8(void *, int, float);
extern float func_002A7940(void);
extern float func_002A7878(float, float);
extern int func_002A7820(int, int);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_00282CC0(void *, void *, void *);
extern void func_L01_0032EF38(void *, int, int, float, float, int);

void func_L01_003B50C8(char *object, int count, float height)
{
    float position[4];
    float angle, radius, first, second;
    char *state;
    int life, left;

    if (height == -1.0f) {
        state = *(char **)(object + 0x68);
        if (*(int *)(state + 0x1E8) != -1 || *(int *)(state + 0x198) != 0)
            return;
        height = *(float *)(state + 0x1A0) + 0.015f;
    }
    if (height == 0.0f)
        height = func_002A89A8(object + 0x10, 0, 0.5f) + 0.025f;
    for (left = 0; left < count; left++) {
        angle = func_002A7940();
        radius = func_002A7878(0.0f, 0.8f);
        first = func_002A7878(0.0f, 1.5f);
        second = func_002A7878(1.5f, 5.7f);
        life = func_002A7820(100, 180);
        position[0] = func_00283180(angle) * radius;
        position[1] = func_00283198(angle) * radius;
        position[2] = 0.0f;
        func_00282CC0(position, position, object + 0x10);
        position[2] = height;
        func_L01_0032EF38(position, 0x38002028, 0x2020, first, second, life);
    }
}


INCLUDE_ASM("asm/levels", func_L01_003B53C8);

INCLUDE_ASM("asm/levels", func_L01_003B57A8);

INCLUDE_ASM("asm/levels", func_L01_003B5878);

INCLUDE_ASM("asm/levels", func_L01_003B9F30);

/* func_L01_003BAFB0 lives in the -g8 sibling file (it reads a float through $gp). */

INCLUDE_ASM("asm/levels", func_L01_003BAFB8);
