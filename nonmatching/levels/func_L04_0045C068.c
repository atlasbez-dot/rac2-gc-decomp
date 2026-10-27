/* near miss: func_L04_0045C068 compiles to the right instruction mix (needs a -frac2-qcopy unit) but cc1 loads and allocates the float constants in another order (46 differing lines, all float-register allocation and hoisting). */
#include "common.h"

/* A -frac2-qcopy unit: the 16-byte position copy is an lq/sq pair. */

typedef int Q16_B0e5d8f83 __attribute__((mode(TI)));

extern int func_33E6B0(unsigned char *obj, int a1, int a2);
extern void func_382DF8(int a0, int a1, unsigned char *obj);
extern void func_33BD68(float *vec, float f12, float f13);
extern float func_30ECD8(float value);
extern void func_348A48(unsigned char *obj, float *pos, int a2, int a3, float *vel, int color, int t2, float f12, float f13, float f14, float f15);
extern void func_3317E8(unsigned char *obj);

/* Throws two puffs of the effect at the object's position, lifted by 0.75, then flags the object and updates it twice. */
void func_L04_0045C068(unsigned char *obj)
{
    float vel[4];
    float pos[4];

    if (func_33E6B0(obj, 0x10000, 0) != 0) {
        func_382DF8(0, 0, obj);
        *(Q16_B0e5d8f83 *)pos = *(Q16_B0e5d8f83 *)(obj + 0x10);
        pos[2] += 0.75f;
        func_33BD68(vel, 0.06666667f, 0.100000009f);
        vel[2] = func_30ECD8(vel[2]) * 1.5f;
        func_348A48(obj, pos, 15, 1, vel, 0x50404040, 0, 0.5f, 3.0f, 0.75f, 1.25f);
        func_33BD68(vel, 0.06666667f, 0.100000009f);
        vel[2] = func_30ECD8(vel[2]) * 1.5f;
        func_348A48(obj, pos, 15, 1, vel, 0x50404040, 0, 0.5f, 3.0f, 0.75f, 1.25f);
        obj[0xA8] = 0xFF;
        func_3317E8(obj);
        func_3317E8(obj);
    }
}
