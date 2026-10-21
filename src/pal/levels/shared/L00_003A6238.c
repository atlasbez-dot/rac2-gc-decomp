#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_003A6238);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_003A64C8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_003A7140);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_003A7518);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_003A77D8);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_003A7A68);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_003A7ED8);

extern char D_L00_001A8F20[] __attribute__((sda));
extern void func_0029FCC0_1(int a, int b, void *c);
extern int func_L00_003AB9C0(int a, void *b, int c, char *d, float e, float f, float g, float h);

/* Runs one helper over the object and a stack buffer, then builds a second call from the object's field 104 sub-object - its field 24 as a float, the constants 2.0f/5.0f/0.6f and a bound data address - and stores the object into field 184 of the returned pointer when it is non-null. */
void func_PAL_L00_003A8978(int a0)
{
    int buf[4];
    int s0;
    int v;

    s0 = *(int *)(a0 + 104);
    func_0029FCC0_1(a0, 0, buf);
    v = func_L00_003AB9C0(a0, buf, *(int *)(s0 + 16), D_L00_001A8F20, *(float *)(s0 + 24), 2.0f, 5.0f, 0.6f);
    if (v != 0) {
        *(int *)(v + 184) = a0;
    }
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_003A89F0);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_003A9468);

INCLUDE_ASM("asm/pal/levels", func_PAL_L00_003A9668);
