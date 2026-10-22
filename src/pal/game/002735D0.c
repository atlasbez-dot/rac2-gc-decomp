#include "include_asm.h"

INCLUDE_ASM("asm/pal/game", func_PAL_002735D0);

INCLUDE_ASM("asm/pal/game", func_PAL_00273818);

INCLUDE_ASM("asm/pal/game", func_PAL_00273A10);

extern void Fdb046c5d_FUN_002742E8(void *);
extern void Fdb046c5d_FUN_00274128(void *);
extern int Fdb046c5d_FUN_00274500(void *);
extern void Fdb046c5d_FUN_00282F20(float, void *, void *);
extern void Fdb046c5d_FUN_00282DD8(void *, void *, void *);
extern void Fdb046c5d_FUN_00274A88(void *, void *, void *);
extern void Fdb046c5d_FUN_002AFFD8(void *, void *, int);
extern int Fdb046c5d_FUN_00274BA8(void *, void *, void *, float, float);
extern int Fdb046c5d_FUN_002E5CF8(int, int, void *);
extern void Fdb046c5d_FUN_00274768(void *, int, void *);
extern void Fdb046c5d_FUN_002E5F00(int, void *);
extern char Fdb046c5d_D_001BAFC0[];

int func_PAL_00273BB0(char *obj)
{
    float buf[4];
    float out[4];
    char *p;
    char *s1;
    unsigned char k;
    int r;
    int s4;
    int s5;

    p = *(char **)(obj + 104);
    k = *(unsigned char *)(p + 92);
    if (k >= 3)
        return 1;
    if (k != 0)
        Fdb046c5d_FUN_002742E8(obj);
    else
        Fdb046c5d_FUN_00274128(obj);

    s5 = Fdb046c5d_FUN_00274500(obj);
    if (s5 == -1)
        return 0;

    s1 = Fdb046c5d_D_001BAFC0;
    s4 = -1;
    Fdb046c5d_FUN_00282F20(1.0f, s1, s1);
    Fdb046c5d_FUN_00282DD8(buf, s1, p);
    Fdb046c5d_FUN_00274A88(obj, p + 16, buf);
    Fdb046c5d_FUN_002AFFD8(obj + 16, out, 1);
    r = Fdb046c5d_FUN_00274BA8(p, s1, out, *(float *)(p + 56), *(float *)(p + 60));
    if (r == 0) {
        if (*(unsigned char *)(p + 94) != 255 && *(unsigned char *)(p + 92) == 0)
            s4 = Fdb046c5d_FUN_002E5CF8(*(unsigned char *)(p + 94), 0, obj);
        Fdb046c5d_FUN_00274768(obj, s5, out);
    } else {
        if (*(unsigned char *)(p + 94) != 255)
            s4 = Fdb046c5d_FUN_002E5CF8(*(unsigned char *)(p + 94), 0, obj);
    }
    if (s4 != -1)
        Fdb046c5d_FUN_002E5F00(s4, p + 32);
    return 0;
}

INCLUDE_ASM("asm/pal/game", func_PAL_00273D38);
