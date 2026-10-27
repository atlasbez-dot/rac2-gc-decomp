/* Near miss (mid-16): all loads, stores and the qcopy match; the float temporaries are allocated f20/f21 swapped and the 1.0f/ratio divide sits after the call in retail. Every gp float load needs __attribute__((sda)) at -G8.
   Needs the unit flags: -O2 -G8 -ffunction-sections -frac2-qcopy (unit src/levels/shared/L05_00427090-qcopy.c) */
typedef int Quadword __attribute__((mode(TI)));

extern void *func_00328508(int);
extern int func_00307778(int, float);
extern void func_003068F8(void *, void *, float);
extern void func_00306748(void *, void *, void *);
extern float D_L05_001B1514 __attribute__((sda));
extern float D_L05_001B1518 __attribute__((sda));
extern int D_L05_001B151C __attribute__((sda));
extern float D_L05_001B1524 __attribute__((sda));
extern float D_L05_001B1528 __attribute__((sda));

void *func_L05_00427090(Quadword *a0, void *a1, int a2, unsigned char *a3, int a4, int a5)
{
    unsigned char *object = func_00328508(0x1182);
    unsigned char *state;
    float step, ratio, t1, t2;

    if (object != 0) {
        state = *(unsigned char **)(object + 0x68);
        object[0x30] = 0xFF;
        *(short *)(object + 0x32) = 0x1FF;
        object[0x20] = 1;
        object[0x31] = 1;
        *(int *)(state + 0x24) = a4;
        if (a4)
            t1 = D_L05_001B1518;
        else
            t1 = D_L05_001B1514;
        step = t1 * 0.016666668f;
        if (a4)
            t2 = D_L05_001B1528;
        else
            t2 = D_L05_001B1524;
        ratio = t2 / step;
        *(int *)(state + 0x18) = func_00307778(0x1FF, ratio);
        *(int *)(state + 0x28) = D_L05_001B151C;
        *(int *)(state + 0x10) = a2;
        *(int *)(state + 0x2C) = a5;
        *(unsigned char **)(state + 0x20) = a3;
        *(float *)(state + 0x1C) = 1.0f / ratio;
        *(int *)(state + 0x14) = 0;
        *(unsigned short *)(object + 0x34) |= 0x100;
        *(Quadword *)(object + 0x10) = *a0;
        func_003068F8(state, a1, step);
        func_003068F8(object + 0xC0, state, 1.0f);
        func_00306748(object + 0xD0, object + 0xC0, a3 + 0xE0);
        func_003068F8(object + 0xD0, object + 0xD0, 1.0f);
        func_00306748(object + 0xE0, object + 0xD0, object + 0xC0);
    }
    return object;
}
