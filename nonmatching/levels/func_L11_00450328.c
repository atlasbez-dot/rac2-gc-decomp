/* func_L11_00450328 (480 B): this C matches 1/1, but only by declaring the word at
   0x1A8F20 under two names (D_001A8F20 and D_001A8F20_1) so the two calls do not share
   one address register. Both names use the same addressing form, so that is a steering
   alias, which docs/MATCHING-BLOCKERS.md rules out. Kept as a near miss; reopen with a
   spelling that rematerialises the address without the second name.
   Flags tried: -O2 -G0 -ffunction-sections -mno-split-addresses -frac2-qcopy -frac2-qcopy-barrier */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern char *func_0029EFD0(int id);
extern float func_002A7878(float a, float b);
extern float func_002A7940(void);
extern void func_002C2210(void *, unsigned int, int, unsigned int, int, char *, float, float, float, int);
extern int D_001A8F20;
extern int D_001A8F20_1;

char *func_L11_00450328(char *a0, TI128 *a1, TI128 *a2, float f12)
{
    char *obj = func_0029EFD0(0xDD9);

    if (obj != 0) {
        char *st;
        float f20;

        *(unsigned char *)(obj + 0x30) = 0xFF;
        *(short *)(obj + 0x32) = 0xFF;
        obj[0x31] = 1;
        obj[0x20] = 0;
        *(long long *)(obj + 0x38) = *(long long *)(a0 + 0x38);
        *(TI128 *)(obj + 0x10) = *a2;
        st = *(char **)(obj + 0x68);
        *(TI128 *)st = *a1;
        *(float *)(st + 0x14) = f12;
        *(char **)(st + 0x10) = a0;
        *(float *)(st + 0x18) = func_002A7940();
        *(float *)(st + 0x1C) = func_002A7878(0.20943954586982727f, 0.6283186078071594f);
        *(float *)(st + 0x20) = 0.15f;
        *(unsigned char *)(obj + 0x23) = 0x80;
        *(unsigned short *)(obj + 0x34) |= 0x100;
        *(float *)(obj + 0x2C) = func_002A7878(0.005f, 0.00625f);
        *(int *)(st + 0x24) = 0;
        *(unsigned short *)(obj + 0x34) |= 0x200;
        f20 = func_002A7878(2.0f, 4.0f);
        *(unsigned short *)(obj + 0x34) |= 0x41;
        func_002C2210(obj + 0x10, 4, 0x801060E0, 0, 10, (char *)&D_001A8F20, f20 * 0.3f, f20, 0.0f, 0);
        func_002C2210(obj + 0x10, 4, -1, 1, -10, (char *)&D_001A8F20_1, f20 * 0.04f, f20 * 0.4f, 0.0f, 0);
    }
    return obj;
}
