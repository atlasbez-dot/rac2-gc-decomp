#include "common.h"

/* Near miss: 336 bytes against the retail's 348, with the unit's flags
   -O2 -G8 -ffunction-sections -frac2-qcopy. The pi constant is one ulp above the float pi
   (the retail's bits are 0x40490FDC). */

/* A 16-byte copy: this compiler lowers one to the R5900's lq/sq pair. */
typedef int TI16 __attribute__((mode(TI)));

extern float D_L17_001B0240 __attribute__((sda));

extern void func_00282CF0(float *, float *, float *);

extern void func_00282CC0(float *, float *, float *);

extern void func_00282D30(float *, float *, float *);

extern float func_00283180(float);

extern float func_00283CE0(s32);

extern s32 func_00283CF0(float);

/* Scales the sub-object's angle by pi, takes the frame it names and measures the object's
   own height against the frame's, writing the difference into the sub-object. */
void func_L17_003C3AF0(char *a0, char *a1, char *a2)
{
    f32 v[4];
    f32 f0;
    f32 f1;
    f32 f12;
    f32 f20;
    f32 f21;
    s32 s0;
    s32 v0;
    char *s1 = a1;
    char *s2 = a0;
    char *s3;
    char *s4 = a2;

    s3 = *(char **)(s2 + 0x68);
    f12 = *(f32 *)(s3 + 0xA8);
    f12 = f12 * 3.1415929f / (D_L17_001B0240 * 60.0f);
    f0 = func_00283180(f12);
    f21 = 1.0f - f0;
    f21 = f21 * 0.5f;
    f0 = func_00283CE0(*(s32 *)s1 - 1);
    f12 = f0 * f21;
    v0 = func_00283CF0(f12);
    s0 = v0;
    f20 = func_00283CE0(*(s32 *)s1 - 1);
    f0 = func_00283CE0(s0);
    f20 = f20 * f21;
    f20 = f20 - f0;
    if (s0 == *(s32 *)s1 - 1) {
        *(TI16 *)(s2 + 0x10) = *(TI16 *)(s1 + s0 * 16 + 0x10);
    } else {
        func_00282CF0(v, (f32 *)(s1 + s0 * 16 + 0x20), (f32 *)(s1 + s0 * 16 + 0x10));
        func_00282D30(v, v, f20);
        func_00282CC0((f32 *)(s2 + 0x10), v, (f32 *)(s1 + s0 * 16 + 0x10));
    }
    *(f32 *)(s3 + 0xC0) = *(f32 *)(s2 + 0x18) - *(f32 *)(s4 + 8);
}
