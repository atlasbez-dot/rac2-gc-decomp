#include "include_asm.h"

INCLUDE_ASM("asm/us2/game", func_US2_0033C958);

extern void Ffb202470_FUN_0033AB50(char *p);

char *func_US2_0033CD80(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

extern void Fe524d931_FUN_0033AE28(char *p);
extern void Fe524d931_FUN_0033B018(char *p, float x, float y);
extern void Fe524d931_FUN_002E5E58(int a, int b, int c);
extern void Fe524d931_FUN_00284E40(void);
extern short Fe524d931_D_001A6480[];

int func_US2_0033CEE0(char *object, int mask)
{
    char *sub = object + 8;
    short oldx;
    short oldy;
    int *v;

    Fe524d931_FUN_0033AE28(sub);
    v = *(int **)(object + 732);
    Fe524d931_FUN_0033B018(sub, *(float *)v, *(float *)(v + 1));
    if ((mask & 0x40) != 0 && *(int *)(object + 728) == 0)
        Fe524d931_FUN_002E5E58(4, 0, 0);
    if ((mask & 0xf000) != 0) {
        short *p = Fe524d931_D_001A6480;
        oldx = p[180];
        oldy = p[181];
        if ((mask & 0x1000) != 0) {
            ((unsigned short *)p)[181] = ((unsigned short *)p)[181] - 1;
            if ((short)((unsigned short *)p)[181] < -32)
                p[181] = -32;
        }
        if ((mask & 0x4000) != 0) {
            unsigned short *q = (unsigned short *)Fe524d931_D_001A6480;
            q[181] = q[181] + 1;
            if ((short)q[181] > 32)
                ((short *)q)[181] = 32;
        }
        if ((mask & 0x8000) != 0) {
            unsigned short *q = (unsigned short *)Fe524d931_D_001A6480;
            q[180] = q[180] - 1;
            if ((short)q[180] < -40)
                ((short *)q)[180] = -40;
        }
        if ((mask & 0x2000) != 0) {
            unsigned short *q = (unsigned short *)Fe524d931_D_001A6480;
            q[180] = q[180] + 1;
            if ((short)q[180] > 40)
                ((short *)q)[180] = 40;
        }
        {
            short *q = Fe524d931_D_001A6480;
            if (oldx != q[180] || oldy != q[181])
                Fe524d931_FUN_002E5E58(4, 0, 0);
        }
        Fe524d931_FUN_00284E40();
    }
    return (mask >> 6) & 1;
}

INCLUDE_ASM("asm/us2/game", func_US2_0033D070);

char *func_US2_0033D1C0(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/us2/game", func_US2_0033D3C0);

char *func_US2_0033D478(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/us2/game", func_US2_0033D5D8);

INCLUDE_ASM("asm/us2/game", func_US2_0033D780);

char *func_US2_0033DA00(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

extern void Fc558ca70_FUN_0033AE28(char *p);
extern void Fc558ca70_FUN_0033B018(char *p, float a, float b);
extern void Fc558ca70_FUN_002E5E58(int a, int b, int c);
extern volatile unsigned char Fc558ca70_D_001A7B95 __attribute__((sda));
extern volatile unsigned char Fc558ca70_D_001A7B94 __attribute__((sda));

int func_US2_0033DB60(char *a0, int a1)
{
    char *p = a0 + 8;
    float *q;
    int v;

    Fc558ca70_FUN_0033AE28(p);
    q = *(float **)(a0 + 732);
    Fc558ca70_FUN_0033B018(p, q[0], q[1]);
    if (a1 & 0x1000) {
        Fc558ca70_FUN_002E5E58(3, 0, 0);
        v = *(int *)(a0 + 728);
        *(int *)(a0 + 728) = (v + 1) % 2;
    } else if (a1 & 0x4000) {
        Fc558ca70_FUN_002E5E58(3, 0, 0);
        v = *(int *)(a0 + 728);
        *(int *)(a0 + 728) = (v + 1) % 2;
    } else if (a1 & 0x40) {
        Fc558ca70_FUN_002E5E58(4, 0, 0);
        switch (*(int *)(a0 + 728)) {
        case 0:
            Fc558ca70_D_001A7B95 = Fc558ca70_D_001A7B95 == 0;
            break;
        case 1:
            Fc558ca70_D_001A7B94 = Fc558ca70_D_001A7B94 == 0;
            break;
        }
    }
    return (a1 >> 6) & 1;
}

INCLUDE_ASM("asm/us2/game", func_US2_0033DC68);

extern void func_0033AB50(int);

char *func_US2_0033DDC8(char *object)
{
    extern void func_003363D0(void *);
    func_0033AB50((int)(object + 8));
    func_003363D0(object + 0x2DC);
    func_003363D0(object + 0x324);
    return object;
}

INCLUDE_ASM("asm/us2/game", func_US2_0033E070);

INCLUDE_ASM("asm/us2/game", func_US2_0033E308);

char *func_US2_0033E488(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/us2/game", func_US2_0033E5E8);

INCLUDE_ASM("asm/us2/game", func_US2_0033E680);

char *func_US2_0033E750(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/us2/game", func_US2_0033E788);

INCLUDE_ASM("asm/us2/game", func_US2_0033E8B0);

INCLUDE_ASM("asm/us2/game", func_US2_0033E9B8);

INCLUDE_ASM("asm/us2/game", func_US2_0033EB20);

INCLUDE_ASM("asm/us2/game", func_US2_0033EB58);

INCLUDE_ASM("asm/us2/game", func_US2_0033EC80);

INCLUDE_ASM("asm/us2/game", func_US2_0033ED18);

INCLUDE_ASM("asm/us2/game", func_US2_0033EDD0);

INCLUDE_ASM("asm/us2/game", func_US2_0033EE08);

INCLUDE_ASM("asm/us2/game", func_US2_0033EF30);

INCLUDE_ASM("asm/us2/game", func_US2_0033EFC8);

INCLUDE_ASM("asm/us2/game", func_US2_0033F000);

INCLUDE_ASM("asm/us2/game", func_US2_0033F128);

INCLUDE_ASM("asm/us2/game", func_US2_0033F1C0);

INCLUDE_ASM("asm/us2/game", func_US2_0033F200);

INCLUDE_ASM("asm/us2/game", func_US2_0033F360);

INCLUDE_ASM("asm/us2/game", func_US2_0033F398);

INCLUDE_ASM("asm/us2/game", func_US2_0033F3B8);

INCLUDE_ASM("asm/us2/game", func_US2_0033F3F0);

INCLUDE_ASM("asm/us2/game", func_US2_0033F478);

INCLUDE_ASM("asm/us2/game", func_US2_0033F4D0);

INCLUDE_ASM("asm/us2/game", func_US2_0033F510);

INCLUDE_ASM("asm/us2/game", func_US2_0033F610);

void func_0033AF48(int);

void func_US2_0033F670(int param_1) {
  func_0033AF48(param_1 + 8);
}

extern void func_0033AB50_1(void *);
extern void func_L00_0042BFF8(void *);
extern void func_L00_0042C290(void *);
extern void func_L00_0042BAD0(void *);

/* Calls twelve sub-object handlers in sequence, each with the object base plus a fixed byte offset (8, 684, 744, 816, 888, 960, 1040, 1112, 1184, 1256, 1328, 1400), then returns the object pointer. */
char *func_US2_0033F690(char *object)
{
    func_0033AB50_1(object + 8);
    func_L00_0042BFF8(object + 732);
    func_L00_0042C290(object + 792);
    func_L00_0042C290(object + 880);
    func_L00_0042C290(object + 968);
    func_L00_0042BAD0(object + 1056);
    func_L00_0042C290(object + 1136);
    func_L00_0042C290(object + 1224);
    func_L00_0042C290(object + 1312);
    func_L00_0042C290(object + 1400);
    func_L00_0042C290(object + 1488);
    func_L00_0042C290(object + 1576);
    return object;
}

INCLUDE_ASM("asm/us2/game", func_US2_0033F720);

INCLUDE_ASM("asm/us2/game", func_US2_0033FAB0);

INCLUDE_ASM("asm/us2/game", func_US2_0033FCE8);

INCLUDE_ASM("asm/us2/game", func_US2_0033FDD8);

INCLUDE_ASM("asm/us2/game", func_US2_0033FEF8);

INCLUDE_ASM("asm/us2/game", func_US2_0033FF68);

INCLUDE_ASM("asm/us2/game", func_US2_003400E0);
