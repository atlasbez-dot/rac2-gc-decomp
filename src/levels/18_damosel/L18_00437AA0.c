#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
extern char *func_0029EFD0(int);
extern void func_003001E0(char *,char *,char *);
extern float func_00283248(float,float);
extern void func_002A0F48(char *);
extern unsigned short D_L18_001B18FC __attribute__((sda));
extern float D_L18_001B191C __attribute__((sda));

char *func_L18_00437AA0(int owner, char *position, char *velocity, int value, float scale, float extra)
{
    char *object = func_0029EFD0(0xf9e);
    char *state;
    float angle;
    float k;
    unsigned short timer;
    if (object != 0) {
        state = *(char **)(object + 0x68);
        *(unsigned char *)(object + 0x30) = 0xff;
        *(short *)(object + 0x32) = 0xff;
        object[0x31] = 1;
        object[0x20] = 0;
        *(int *)(state + 0x24) = owner;
        *(TI128 *)(object + 0x10) = *(TI128 *)position;
        *(TI128 *)(state + 0x10) = *(TI128 *)velocity;
        timer = D_L18_001B18FC;
        *(float *)(state + 0x1c) = scale;
        *(int *)(state + 0x20) = value;
        *(short *)(state + 0x28) = timer;
        *(short *)(state + 0x2a) = 0;
        *(int *)(object + 0xf0) = 0;
        *(int *)(object + 0xf4) = 0;
        angle = func_00283248(*(float *)velocity, *(float *)(velocity+4));
        *(float *)(object + 0xf8) = angle;
        *(float *)(state + 0x30) = extra;
        k = D_L18_001B191C;
        *(float *)(object + 0x2c) = *(float *)(object + 0x2c) * k;
        func_002A0F48(object);
    }
    return object;
}
