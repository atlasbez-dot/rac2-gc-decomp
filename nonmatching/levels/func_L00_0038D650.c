#include "include_asm.h"
typedef unsigned int Quad __attribute__((mode(TI)));
typedef union { Quad bits; float f[4]; } Vector;
extern int func_00282948(int *);
extern float func_00283CE0(int);
extern int func_00283CF0(float);


void func_L00_0038D650(char *object)
{
    Vector colour;
    char *data = *(char **)(object + 0x68);
    float fraction;
    unsigned int r, g, b;
    colour.bits = 0;
    colour.f[0] = 128.0f;
    colour.f[1] = 128.0f;
    colour.f[2] = 128.0f;
    colour.f[3] = 255.0f;
    func_00282948((int *)(data + 0x10));
    fraction = func_00283CE0(*(int *)(data + 0x10));
    fraction /= func_00283CE0(30);
    r = func_00283CF0((colour.f[0] - 255.0f) * fraction + 255.0f);
    g = func_00283CF0((colour.f[1] - 64.0f) * fraction + 64.0f);
    b = func_00283CF0((colour.f[2] - 64.0f) * fraction + 64.0f);
    b = (b << 16) | ((g << 8) | 0xFF000000);
    b |= r;
    *(unsigned int *)(object + 0x78) = b;
}
