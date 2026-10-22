#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L05_00419C60);

INCLUDE_ASM("asm/pal/levels", func_PAL_L05_0041A270);

#include "common.h"
extern void func_306630(char *dst, char *src, char *src2);
extern float func_332B50(float a, float b);
extern float func_332C18(void);
extern void func_33B330(char *dst, float a, float b, float c);
extern char *func_379CA0(char *object);
extern void func_37AEC0(char *object, int flag);
extern int D_L05_00221D10[];
extern char *D_L05_001B2614 __attribute__((sda));

void func_PAL_L05_0041A480(char *obj)
{
    char *sub = *(char **)(obj + 0x68);
    char *table;
    float a, b, c;

    *(unsigned char *)(obj + 0x20) = 1;
    *(unsigned short *)(obj + 0x34) = *(unsigned short *)(obj + 0x34) | 0x100;
    *(int *)(func_379CA0(obj) + 0x148) = 0x14;
    func_37AEC0(obj, 1);
    table = D_L05_001B2614 + D_L05_00221D10[0] * 128;
    *(int *)(sub + 0x26C) = -1;
    *(int *)(sub + 0x270) = -1;
    *(float *)(sub + 0x180) = 20.0f;
    *(int *)(sub + 0x268) = 0;
    *(float *)(obj + 0x2C) = 0.02f;
    a = func_332B50(0.0f, *(float *)table);
    b = func_332C18();
    c = func_332C18();
    func_33B330(obj + 0x10, a, b, c);
    func_306630(obj + 0x10, table + 0x30, obj + 0x10);
}

extern void func_379FA0(char *object, int a1, int a2, int a3, float f0, float f1, float f2,
                        float f3, int a8, int a9, int a10);

/* Runs the object's pending effect when three guards clear, then marks the run. */
void func_PAL_L05_0041A580(char *object)
{
    char *s1 = *(char **)(object + 0x68);
    char *r;

    r = func_379CA0(object);
    if (r == 0)
        return;
    if (*(int *)(r + 0x120) == 0)
        return;
    if (*(int *)(s1 + 0x268) != 0)
        return;
    if (*(unsigned char *)(object + 0x20) == 1)
        func_379FA0(object, 0x60800000, 1, 0, 0.75f, 5.0f, 1.0f, 1.0f, 0, -1, 0);
    *(int *)(s1 + 0x268) = 0x11;
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L05_0041A628);

INCLUDE_ASM("asm/pal/levels", func_PAL_L05_0041A808);
