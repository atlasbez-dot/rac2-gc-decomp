#include "include_asm.h"
typedef unsigned int Quad __attribute__((mode(TI)));
typedef union { Quad bits; float f[4]; } Vector;

extern char *func_0029EFD0(int);
extern float func_002A7878(float, float);
extern void func_002A0F48(void *);
extern int func_002FED90(void *, void *, float, float, float);


char *func_L00_0038D530(Quad *position, Quad *direction)
{
    unsigned char *object = (unsigned char *)func_0029EFD0(0x79);
    if (object) {
        char *data;
        Quad *destination;
        object[0x30] = 0xFF;
        *(short *)(object + 0x32) = 0x1FF;
        destination = (Quad *)(object + 0x10);
        object[0x31] = 1;
        data = *(char **)(object + 0x68);
        object[0x20] = 0;
        *destination = *position;
        *(Quad *)data = *direction;
        *(int *)(data + 0x14) = 0;
        *(int *)(data + 0x10) = 30;
        *(int *)(data + 0x18) = 300;
        *(float *)(object + 0xF0) = func_002A7878(-3.1415927410125732f, 3.1415927410125732f);
        *(float *)(object + 0xF4) = func_002A7878(-3.1415927410125732f, 3.1415927410125732f);
        *(float *)(object + 0xF8) = func_002A7878(-3.1415927410125732f, 3.1415927410125732f);
        *(int *)(object + 0xFC) = 0;
        func_002A0F48(object);
        *(int *)(data + 0x1C) = func_002FED90(object, 0, 1.0f, 1.0f, 1.0f);
    }
    return object;
}
