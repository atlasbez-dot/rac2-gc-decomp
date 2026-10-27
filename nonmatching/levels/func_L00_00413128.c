/* 26 October 2026 (M24): -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier, 364/364 bytes, 52 lines off: hero fields through the Hero view (retail keeps the base in $s0); left the 0xFE/0xFD test, which fold() turns into a range check here but retail tests separately, and the first argument order. */
/* Retained plain-C near miss; measured 23 October 2026, USA v1.01.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 360/364 bytes, 0/27 placements. The complete child position/scale and indexed
 * release paths replace the old incomplete 208-byte body. Address formation,
 * child-byte join and index argument register differ; no linked credit. Reopen with
 * typed resident context and table layouts.
 */
#include "include_asm.h"
typedef int TI128 __attribute__((mode(TI)));
extern char D_00189E20[];
typedef union { unsigned char b[0x2600]; int i[0x980]; float f[0x980]; char *ptr[0x980]; } Hero;
#define H ((Hero *)D_00189E20)
extern char D_00188660[];
extern int func_00282978(void *);
extern void func_0029F338(char *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern float *func_002AB1F0(char *);
extern void func_L00_00414018(char *);
extern void func_L00_00413358(char *);
extern void func_002E59F8(int);

void func_L00_00413128(char *object)
{
    char *state = *(char **)(object + 0x68);
    char local[32];
    char *child;
    int code, index;
    float *value;
    if (func_00282978(state + 0x1E) != 0) {
        func_0029F338(object);
        return;
    }
    func_00282D30(local, H->ptr[2212] + 0xE0, 0.75f);
    func_00282CC0(object + 0x10, &H->f[32], local);
    if (*(char **)(state + 0x20) != 0 && (*(unsigned char *)(*(char **)(state + 0x20) + 0x20) == 254 || *(unsigned char *)(*(char **)(state + 0x20) + 0x20) == 253))
        *(char **)(state + 0x20) = 0;
    child = *(char **)(state + 0x20);
    if (child != 0) {
        *(TI128 *)(state + 0x30) = *(TI128 *)(child + 0x10);
        value = func_002AB1F0(child);
        if (value != 0) {
            func_00282D30(local + 16, *(char **)(state + 0x20) + 0xE0, value[4]);
            func_00282CC0(state + 0x30, state + 0x30, local + 16);
        }
    }
    if (*(unsigned char *)(object + 0x20) == 1) {
        func_L00_00414018(object);
        func_L00_00413358(object);
    } else {
        index = *(int *)(state + 0x18);
        if (index >= 0) {
            if (index != -1 && *(char **)(D_00188660 + index * 112 + 0x88) == object &&
                *(unsigned char *)(D_00188660 + index * 112 + 0x74) != 0)
                func_002E59F8(index);
            *(int *)(state + 0x18) = -1;
        }
    }
}
