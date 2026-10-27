/* Nonmatching: 292/292 bytes.
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses.
 * Final placement checks: US: 0/1; US2: 0/1; PAL: 0/1.
 * 292/292 bytes and frame 0x30. Capturing the definition pointer before the flags write and reading its health field afterwards reproduces the complete prefix through +0x94. Three fresh global loads and grouped copies are present, but their address registers differ from +0x98 onward.
 * Reopen with source-level table/vector address lifetime evidence from the allocator dumps; -mno-split-addresses already removes the saved high-address register without inventing volatility.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750(unsigned char *, int, int);

extern void func_00282D60(TI128 *, char *, float);

extern int func_00283DB8(TI128 *, float);

extern float func_00283248(float, float);

extern char *D_L07_001B23CC __attribute__((nosda));

void func_L07_003EECE0(char *arg)
{
    TI128 tmp;
    char *s0 = arg;
    char *s1;
    char *base;
    char *definition;
    unsigned short v;
    int r;
    char *entry;
    float f0, f1;

    s1 = *(char **)(arg + 0x68);
    v = *(unsigned short *)(arg + 0x34);
    definition = *(char **)(arg + 0x24);
    *(unsigned short *)(arg + 0x34) = (v & 0xFFBE) | 0x1000;
    *(int *)(arg + 0x98) = *(int *)(definition + 0x10);
    func_002A7750((unsigned char *)arg, 3, -1);
    *(unsigned char *)(arg + 0x30) = 0xFF;
    *(unsigned short *)(arg + 0x32) = 0xFF;

    if (*(int *)(s1 + 0x98) != 0) {
        func_00282D60(&tmp, s0, 0.0009765625f);
        r = func_00283DB8(&tmp, 128.0f);
        if (r != -1) {
            base = D_L07_001B23CC;
            qcopy(arg + 0x10, base + *(int *)(s1 + 0x98) * 128 + 0x30);
        }
    }

    base = D_L07_001B23CC;
    f1 = *(float *)(arg + 0x10);
    f0 = *(float *)(arg + 0x14);
    r = *(int *)(s1 + 0x94);
    entry = r * 128 + base;
    *(float *)(s1 + 0xE8) = func_00283248(*(float *)(entry + 0x30) - f1, *(float *)(entry + 0x34) - f0);

    qcopy(s1 + 0xF0, arg + 0x10);

    r = *(int *)(s1 + 0x94);
    entry = r * 128 + D_L07_001B23CC;
    qcopy(s1 + 0xD0, entry + 0x30);
}
