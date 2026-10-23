/* Retained plain-C near miss; measured 23 October 2026, USA v1.01.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 316/316 bytes, 0/27 placements. First instruction mismatch +0x14: argument
 * saved-register allocation; initial store motion and final chained float-zero/store
 * scheduling also differ. Corrects the previous draft: copy the input position, short
 * 255, two 16-byte locals, and the missing second vector copy. Reopen with actual
 * record declarations/lifetimes.
 */
#include "include_asm.h"
typedef int TI128 __attribute__((mode(TI)));
extern char D_L00_001B8DC0[];
extern char *func_0029EFD0(int);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_002AFFD8(void *, void *, int);
extern void func_00282DD8(void *, void *, void *);

int func_L00_00416F68(TI128 *position, char *arg1, int arg2)
{
    char local[32];
    char *object = func_0029EFD0(0x139E);
    char *state;
    char *first;
    char *second;
    char *third;
    int result = 255;
    if (object != 0) {
    state = *(char **)(object + 0x68);
    first = object + 0x10;
    *(unsigned char *)(object + 0x30) = 255;
    *(short *)(object + 0x32) = 255;
    *(unsigned char *)(object + 0x20) = 0;
    *(TI128 *)first = *position;
    *(float *)(object + 0x1C) = 1.0f;
    second = object + 0xC0;
    func_00282CF0(local, D_L00_001B8DC0, first);
    func_00282F20(local, local, 1.0f);
    func_002AFFD8(first, local + 16, 1);
    *(TI128 *)second = *(TI128 *)local;
    third = object + 0xD0;
    func_00282DD8(third, second, local + 16);
    func_00282F20(third, third, 1.0f);
    func_00282DD8(object + 0xE0, third, second);
    *(float *)(object + 0xCC) = *(float *)(object + 0xEC) = *(float *)(object + 0xDC) = 0.0f;
    *(int *)(state + 8) = arg2;
    *(int *)(state + 0) = 60;
    *(char **)(state + 4) = arg1;
    result = (int)object;
    }
    return result;
}
