/* Complete retained source attempt for func_0030E8A8; not matched.
 * Current qualified G0 profile: 1028 bytes versus 1052, 0/28 placements.
 * The 0x120 frame is correct; pointer lifetimes/register allocation, folded
 * stack-vector copies and the two reset paths still differ from retail.
 * Separate vector locals and a separately evaluated dot product did not
 * improve the initial array spelling. Tested -fno-schedule-insns (1008 bytes),
 * -fno-gcse (1020), and -fno-expensive-optimizations (1020): none matched.
 * The resident symbol is now named by its fixed address, and the collision
 * result uses an opaque per-placement reference. Unrelated empty function
 * stubs from the earlier whole-file draft have been removed from this record.
 * Reopen with a supported vector-address/lifetime or control-flow improvement;
 * no inline assembly, volatile barrier or register pin was added. Runtime
 * behavior and linked-image equivalence of this candidate remain unverified.
 */
#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } MotionVector;

extern char D_00189E20[];
extern char ref_0030E8A8_00[];

extern void func_002FE8D8(char *, char *);
extern void func_00282CF0(char *, char *, char *);
extern void func_00282CC0(char *, char *, char *);
extern void func_00282D30(char *, char *, float);
extern float func_00282DB0(char *, char *);
extern float func_00282DF0(char *);
extern void func_00282F20(char *, char *, float);
extern int func_002761F8(char *, char *, int, int, int);
extern float func_002AA3A8(float *, float *, float, float, float, float);
extern void func_002A8240(char *, char *, int, float, float, float);

void func_0030E8A8(char *a0)
{
    char *obj = a0;
    char *e = *(char **)(obj + 0x68);
    char *d = D_00189E20;
    short flag = *(short *)(d + 0x202);
    MotionVector v0, v1, v2, v3, v4, v5, v6, v7, v8, v9;
    float projection;
    float f;
    int mode;
    float l3;
    float l2;
    float step;
    float acc;
    float x;
    int r;

    if (*(int *)(e + 0x44) == 0 && flag == 0)
        return;

    func_002FE8D8(obj + 0x10, (char *)v0.f);
    acc = 0.0f;
    func_00282CF0((char *)v1.f, obj + 0x10, d + 0x80);
    projection = func_00282DB0((char *)v1.f, (char *)v0.f);
    func_00282D30((char *)v3.f, (char *)v0.f, projection);
    func_00282CF0((char *)v2.f, (char *)v1.f, (char *)v3.f);
    l3 = func_00282DF0((char *)v3.f);
    l2 = func_00282DF0((char *)v2.f);
    func_00282D30((char *)v4.f, (char *)v0.f, -2.5f);
    func_00282CC0((char *)v4.f, obj + 0x10, (char *)v4.f);
    func_00282D30((char *)v5.f, (char *)v0.f, 0.5f);
    func_00282CC0((char *)v5.f, obj + 0x10, (char *)v5.f);
    r = func_002761F8((char *)v5.f, (char *)v4.f, 2, 0, 0);
    if (r != 0) {
        *(TI128 *)((char *)v6.f) = *(TI128 *)ref_0030E8A8_00;
        mode = 0;
    } else {
        mode = 1;
    }
    if (mode == 0) {
        func_00282CF0((char *)v8.f, (char *)v6.f, obj + 0x10);
        projection = func_00282DB0((char *)v8.f, (char *)v0.f);
        func_00282D30((char *)v7.f, (char *)v0.f, projection);
        acc = func_00282DF0((char *)v7.f);
    }
    if (*(int *)(e + 0x44) == 0) {
        if (!(l2 < 1.0f))
            return;
        if (!(l3 < 1.3f))
            return;
        *(int *)(e + 0x44) = 1;
    }
    *(TI128 *)((char *)v8.f) = *(TI128 *)((char *)v2.f);
    if (l2 - 1.4f > 0.0f)
        f = 0.0f;
    else
        f = l2 - 1.4f;
    if (flag == 0)
        f = 0.0f;
    step = 0.02f;
    func_002AA3A8(&f, (float *)(e + 0x48), 0.0f, step, 0.3f, 0.066666666f);
    if (f == 0.0f && *(float *)(e + 0x48) == 0.0f && acc < step)
        *(int *)(e + 0x44) = 0;
    if (l2 < *(float *)(e + 0x48))
        *(float *)(e + 0x48) = l2;
    if (*(float *)(e + 0x48) < l2)
        func_00282F20((char *)v8.f, (char *)v8.f, *(float *)(e + 0x48));
    func_002A8240(obj, (char *)v8.f, 0, 0.5f, 0.4f, 0.0f);
    if (mode == 0) {
        if (func_00282DB0((char *)v7.f, (char *)v0.f) > 0.0f) {
            *(TI128 *)(obj + 0x10) = *(TI128 *)((char *)v6.f);
            *(float *)(e + 0x4C) = 0.0f;
        } else {
            x = *(float *)(e + 0x4C) - 0.0066666668f;
            *(float *)(e + 0x4C) = x;
            func_00282D30((char *)v8.f, (char *)v0.f, x);
            func_00282CC0(obj + 0x10, (char *)v8.f, obj + 0x10);
            func_00282CF0((char *)v9.f, (char *)v6.f, obj + 0x10);
            if (func_00282DB0((char *)v9.f, (char *)v0.f) > 0.0f) {
                *(TI128 *)(obj + 0x10) = *(TI128 *)((char *)v6.f);
                *(float *)(e + 0x4C) = 0.0f;
            }
        }
    } else {
        x = *(float *)(e + 0x4C) - 0.0066666668f;
        *(float *)(e + 0x4C) = x;
        func_00282D30((char *)v8.f, (char *)v0.f, x);
        func_00282CC0(obj + 0x10, (char *)v8.f, obj + 0x10);
    }
}
