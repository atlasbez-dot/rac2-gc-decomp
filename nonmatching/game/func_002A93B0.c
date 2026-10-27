/* func_002A93B0: Opus closer M1 near miss, 26 October 2026.
   Profile: -O2 -G0 -ffunction-sections, own unit (qcopy from common.h).
   404/404 bytes, 9 differing. Real prototypes (func_00282D30/D60 take the float last), the flag word as an sda incomplete array, stores written out per arm. Left: y lands in $f3 instead of $f1 in the first arm, and the second arm stores 0x74 before 0x70. */
#include "common.h"
extern int D_001A8CA0[] __attribute__((sda));
extern float D_001BAFA0[] ;
extern float D_001BAFA8 ;
extern void func_00282D60(void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DB0(void *, void *);
extern int func_002761F8(void *, void *, int, void *, void *);
void func_002A93B0(char *o)
{
    float a[4] __attribute__((aligned(16)));
    float b[4] __attribute__((aligned(16)));
    float c[4] __attribute__((aligned(16)));
    float x;
    float y;

    if (D_001A8CA0[0] == 0) {
        if (*(float *)(o + 0xE8) < 0.9f) {
            *(float *)(o + 0x70) = 0.0f;
            *(float *)(o + 0x74) = 0.0f;
            return;
        }
        qcopy(a, o + 0x10);
        a[2] = a[2] - 16.0f;
        if (a[2] < 0.5f)
            a[2] = 0.5f;
        qcopy(b, o + 0x10);
        b[2] = b[2] + 0.5f;
        if (func_002761F8(b, a, 0x22, 0, 0) != 0) {
            y = *(float *)(o + 0xC) * 0.000244140625f;
            x = D_001BAFA8 - *(float *)(o + 0x18);
            *(float *)(o + 0x70) = x;
            *(float *)(o + 0x74) = y;
        } else {
            *(float *)(o + 0x70) = 0.0f;
            *(float *)(o + 0x74) = 0.0f;
        }
    } else {
        func_00282D60(a, o, 0.0009765625f);
        func_00282D30(b, o + 0xE0, -8.0f);
        func_00282CC0(b, a, b);
        if (func_002761F8(a, b, 0x22, 0, 0) != 0) {
            func_00282CF0(c, D_001BAFA0, o + 0x10);
            x = func_00282DB0(c, (float *)(o + 0xE0));
            *(unsigned char *)(o + 0xBD) = 0xFF;
            y = 0.2f;
            *(float *)(o + 0x70) = x;
            *(float *)(o + 0x74) = y;
        } else {
            *(float *)(o + 0x70) = 0.0f;
            *(float *)(o + 0x74) = 0.0f;
        }
    }
}
