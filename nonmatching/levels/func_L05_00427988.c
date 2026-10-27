/* func_L05_00427988: M3 2026-10-26: the scale constant is 1/60 (0x3C888889), not 1/120; needs -G8 -frac2-qcopy. 404/404 bytes; allocation differs (pos in $s7, the +0xC0/+0xD0 pointers computed early) and the pre-division nop pair is missing.
 */

typedef int TI128 __attribute__((mode(TI)));

extern char * func_0029EFD0(int);
extern int func_00283CF0(float);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern float D_L05_001B154C __attribute__((sda));
extern float D_L05_001B1550 __attribute__((sda));
extern int D_L05_001B1554 __attribute__((sda));
extern float D_L05_001B155C __attribute__((sda));
extern float D_L05_001B1560 __attribute__((sda));

char *func_L05_00427988(char *pos, char *vec, int a2, char *a3, int flag)
{
    char *obj = func_0029EFD0(0x1191);

    if (obj != 0) {
        char *st = *(char **)(obj + 0x68);
        float f20;
        float f21;
        float f22;

        *(unsigned char *)(obj + 0x30) = 0xFF;
        *(unsigned short *)(obj + 0x32) = 0x1FF;
        *(unsigned char *)(obj + 0x20) = 1;
        *(unsigned char *)(obj + 0x31) = 1;
        *(int *)(st + 0x24) = flag;
        f22 = (flag ? D_L05_001B1550 : D_L05_001B154C) * (1.0f / 60.0f);
        f21 = (flag ? D_L05_001B1560 : D_L05_001B155C) / f22;
        f20 = 1.0f;
        *(int *)(st + 0x18) = func_00283CF0(f21);
        *(int *)(st + 0x28) = D_L05_001B1554;
        *(int *)(st + 0x10) = a2;
        *(char **)(st + 0x20) = a3;
        *(int *)(st + 0x14) = 0;
        *(float *)(st + 0x1C) = f20 / f21;
        *(unsigned short *)(obj + 0x34) = *(unsigned short *)(obj + 0x34) | 0x100;
        *(TI128 *)(obj + 0x10) = *(TI128 *)pos;
        func_00282F20(st, vec, f22);
        func_00282F20(obj + 0xC0, st, f20);
        func_00282DD8(obj + 0xD0, obj + 0xC0, a3 + 0xE0);
        func_00282F20(obj + 0xD0, obj + 0xD0, f20);
        func_00282DD8(obj + 0xE0, obj + 0xD0, obj + 0xC0);
    }
    return obj;
}
