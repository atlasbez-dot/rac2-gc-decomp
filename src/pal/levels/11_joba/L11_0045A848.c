#include "include_asm.h"

#include "common.h"
extern void func_002A7750(void *a0, int a1, int a2);
extern void func_002A0488(void *a0, int a1, int a2, int a3);
extern float func_002A7878(float a, float b);
extern void func_002A7470(void *a0, int a1, int a2, int a3);
extern void func_00282C88(void *);
extern void func_L11_003973F8(char *, int, float, float);

/* Aims the object's stage, re-arms its effect and stores the new heading. */
void func_PAL_L11_0045A848(char *p, int a1, int a2)
{
    char *q = *(char **)(p + 0x68);
    char *definition;
    unsigned short flags;
    int cache;
    float f;

    f = (float)*(short *)(q + 0x24);
    *(short *)(q + 0x1FC) = a2;
    *(short *)(q + 0x1EC) = 0;
    *(unsigned char *)(q + 0x2E) = 1;
    *(float *)(q + 0x20) = f;
    if (*(unsigned char *)(p + 0x43) != 0)
        func_002A7470(p, 0, 0, 8);
    flags = *(unsigned short *)(p + 0x34);
    *(unsigned char *)(p + 0x7F) = 0;
    *(unsigned short *)(p + 0x34) = (flags | 0x1000) & 0xFFB9;
    definition = *(char **)(p + 0x24);
    cache = *(int *)(definition + 0x10);
    *(int *)(p + 0x98) = cache;
    if (*(short *)(q + 0x1FC) != 0) {
        func_002A7750(p, 7, 3);
        *(unsigned short *)(p + 0x34) |= 0x100;
        func_L11_003973F8(p, 0, 2.0f, 2.0f);
    } else {
        func_002A7750(p, 3, 1);
        *(unsigned char *)(p + 0x31) = 1;
        *(unsigned short *)(p + 0x34) &= 0xFEFE;
    }
    func_00282C88(q + 0x1B0);
    f = func_002A7878(20.0f, 30.0f) * 0.017453294f;
    *(short *)(q + 0x1EE) = a1;
    *(float *)(q + 0x1CC) = f;
    if (*(short *)(q + 0x50) != 0) {
        *(short *)(q + 0x50) = 0;
        func_002A0488(p, *(int *)(q + 0x1F0), *(int *)(q + 0x1F4), *(int *)(q + 0x1F8));
        *(short *)(q + 0x52) = 1;
    }
}

extern void func_002A05A8(void *a0);
extern void func_L11_00441978(char *p, int id);
extern void func_002E59F8(int index);
extern void func_002E5DA0(int index, int value, char *object, int kind);
extern void func_0032C700(char *, int, int, int, int, int, int, int, float, float, int,
                         int, int, int);
extern char D_00188660[];

/* Releases the object's slot in the shared table and drops it to the idle flag block. */
void func_PAL_L11_0045A9A8(char *p)
{
    char *q = *(char **)(p + 0x68);
    int i = *(int *)(q + 0x1DC);
    char *entry;

    if (i != -1) {
        entry = D_00188660 + i * 0x70;
        if (*(char **)(entry + 0x88) == p && *(unsigned char *)(entry + 0x74) != 0)
            func_002E59F8(i);
    }
    *(int *)(q + 0x1DC) = -1;
    if (*(short *)(q + 0x1EC) == 1) {
        *(short *)(q + 0x1EC) = 0;
        func_L11_00441978(*(char **)(p + 0xB8), *(short *)(p + 0xAA));
    }
    if (*(unsigned char *)(p + 0x31) != 0) {
        func_0032C700(p + 0x10, 0, 10, 30, 0, 10, 45, 1, 0.3f, 0.0f, 0, 0, 0, 0);
        func_002E5DA0(0, 0, p, 0xDF7);
    }
    func_002A7470(p, 0, 0, 3);
    func_002A05A8(p);
    func_002A7750(p, 1, 0);
    *(unsigned short *)(p + 0x34) = (*(unsigned short *)(p + 0x34) & 0xEFFF) | 0x47;
    *(int *)(p + 0x98) = 0;
    *(unsigned char *)(p + 0x31) = 0;
    *(short *)(q + 0x1EC) = 0;
    *(int *)(q + 0x1C4) = 0;
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L11_0045AAE4);

INCLUDE_ASM("asm/pal/levels", func_PAL_L11_0045B9E8);
