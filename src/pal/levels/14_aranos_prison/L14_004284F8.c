#include "include_asm.h"

extern void func_423000();
extern void func_423240();
extern void func_423358();
extern void func_423B30();
extern void func_423BD8();

void func_PAL_L14_004284F8(char *a0)
{
    if (*(unsigned char *)(a0 + 0x20) == 0) {
        func_423000(a0);
    } else {
        func_423240(a0);
        func_423358(a0);
        func_423B30(a0);
        func_423BD8(a0);
    }
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L14_00428558);

INCLUDE_ASM("asm/pal/levels", func_PAL_L14_004288B0);

extern void func_002B5278(char *object, float factor);
extern void func_002B5258(char *object);
extern void func_002B50E0(char *object, char *bone, float factor);
extern void func_002B4FF0(char *object, char *bone, float factor);
extern void *jtbl_002AA360[];

/* Dispatches on the owner's animation step and plays the matching bone animation. */
void func_PAL_L14_004290A8(char *object)
{
    static void * volatile tab[] = { &&cA, &&cC };
    char *state;
    unsigned int sel;

    sel = *(unsigned char *)(object + 0x42) - 1;
    state = *(char **)(object + 0x68);
    if (sel < 19) {
        goto *jtbl_002AA360[sel];
    }
    goto end;
cA:
    if (*(short *)(state + 0x776) != 0) {
        func_002B5278(object, *(float *)(state + 0x744));
    } else {
        func_002B5258(object);
    }
    goto out;
cC:
    if (*(short *)(state + 0x77A) != 0) {
        func_002B50E0(object, state + 0x700, *(float *)(state + 0x768));
    } else {
        func_002B4FF0(object, state + 0x700, *(float *)(state + 0x740));
    }
out:
end:
    return;
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L14_00429150);
