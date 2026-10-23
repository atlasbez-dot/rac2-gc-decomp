/* Retained C reconstruction: 228/228 bytes.
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   0/27 in us, pal and us2; first bound difference +0x5C. Complete C replaces an empty body. An explicit selected pointer and grouped local record reproduce the frame/save order and tail; the packed eight-byte copy uses a1/v0 instead of a2/v1 and schedules f13 later.
   Reopen only with new source/type/lifetime evidence; bounded scheduling/profile variants did not close it. */

#include "include_asm.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct __attribute__((packed)) { int values[2]; } Pair;
extern Pair D_L00_001B1458;
extern int D_L00_001B1464 __attribute__((sda));
extern void func_00282F20(void *, void *, float);
extern float func_002A7878(float, float);
extern void *func_L00_003411A0(void *, void *, int, float);
void func_L00_0041AD40(char *self, void *position, Quad *src)
{
    struct { Quad local; Pair choices; } temp;
    char *state = *(char **)(self + 0x68);
    float size;
    int *selected;
    temp.local = *src;
    func_00282F20(&temp.local, &temp.local, 0.05f);
    temp.choices = D_L00_001B1458;
    selected = temp.choices.values;
    size = func_002A7878(0.05f, 0.1f);
    selected += D_L00_001B1464 % 2;
    func_L00_003411A0(position, &temp.local, *selected,
                       size * *(float *)(state + 0x50) * 0.1f);
    D_L00_001B1464 += 1;
}
