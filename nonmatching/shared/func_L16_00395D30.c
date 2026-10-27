#include "include_asm.h"
#include "common.h"


extern u8 D_L16_001B9B00[];
extern float D_L16_001B3490[];
extern float D_L16_001B34A0[];
extern float D_L16_001B34B0[];
extern float D_L16_001B34C0[];
extern u8 *D_L16_001B2B1C;
extern float D_001AF440[] __attribute__((sda));

extern void func_00335438(void *, void *, int, int, int);
extern void func_002833F0(void *, void *);
extern void func_00283698(void *, void *);
extern void func_002A91F0(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00283098(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282DD8(void *, void *);
extern void func_002AB6D8(void *, void *);

void func_L16_00395D30(u8 *obj)
{
    u8 *p = *(u8 **)(obj + 0x68);
    int idx = *(int *)(p + 4);

    if (idx != -1) {
        u8 *rec = D_L16_001B2B1C + (idx << 8);
        float m0[12] __attribute__((aligned(16)));
        float m1[16] __attribute__((aligned(16)));
        float v70[4] __attribute__((aligned(16)));
        float v80[4] __attribute__((aligned(16)));
        float v90[4] __attribute__((aligned(16)));
        float vA0[4] __attribute__((aligned(16)));
        float vB0[4] __attribute__((aligned(16)));

        func_00335438(D_L16_001B9B00, D_L16_001B9B00 + 0x10, 1, 0, 0);
        *(int *)(p + 0x4C) = 0;
        *(int *)(p + 0x50) = 0;
        func_002833F0(m0, p + 0x20);
        func_00283698(m1, m0);
        func_002A91F0(D_L16_001B3490, D_L16_001B9B00 + 0x10);
        func_00282CF0(D_L16_001B34B0, D_L16_001B9B00, p + 0x10);
        func_00283098(D_L16_001B34B0, D_L16_001B34B0, m1);
        func_00282F20(vA0, rec + 0xE0, 3.0f);
        func_00282CC0(vA0, vA0, rec + 0x10);
        func_00282CF0(v70, vA0, obj + 0x10);
        func_00282F20(v70, v70, 1.0f);
        qcopy(v90, m0 + 8);
        func_00282DD8(v80, v70);
        func_00283098(D_L16_001B34C0, D_001AF440, v70);
        func_00283098(D_L16_001B34C0, D_L16_001B34C0, m1);
        func_002AB6D8(v70, vB0);
        func_002A91F0(D_L16_001B34A0, vB0);
    }
}
