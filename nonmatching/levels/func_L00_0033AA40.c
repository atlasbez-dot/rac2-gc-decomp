/* func_L00_0033AA40 (384 bytes, 27 places) - NEAR MISS (M22, 2026-10-26).
 * Profile: the default "-O2 -G0 -ffunction-sections" (qcopy() helper), as
 * src/levels/shared/L00_0033AA40.c.  384/384, 8 words off: only two register
 * pairs are swapped - size/value get $s5/$s6 the wrong way round and a/b get
 * $f21/$f22 the wrong way round (retail: value $s5, size $s6, a $f22, b $f21).
 * The D_L00_001FEA40 pointer moves between levels, so it is a ref_ name.
 * Storing b before a fixes the float pair but reverses the two stores; storing
 * value after size fixes the int pair but swaps $s6/$s7.  On the permuter.
 */
#include "include_asm.h"
#include "common.h"

typedef int Quad __attribute__((mode(TI)));

/* A spawned particle: header, position, then the payload its update reads. */
typedef struct {
    unsigned char b0, b1, b2, b3;
    int color;
    unsigned char seed, alpha;
    unsigned short size;
    float life;
    union { Quad q; float f[4]; } position;
    float payload[8];
} L00_0033AA40_Particle;

extern L00_0033AA40_Particle *func_002B9030(int);
extern int func_00283CF0(float);
extern float func_00282E80(void *, void *);
extern float func_002A7878(float, float);
extern unsigned char *ref_L00_0033AA40_00[];
extern char D_00189EA0[];

L00_0033AA40_Particle *func_L00_0033AA40(float life, float a, float b, Quad *position, Quad *velocity,
                                         unsigned int size, int color, int value, int flag)
{
    L00_0033AA40_Particle *p = func_002B9030(0x40);

    if (p) {
        float *out = p->payload;

        qcopy(&p->position, position);
        if (func_00282E80(D_00189EA0, position) < 80.0f)
            p->alpha = func_00283CF0(1.0f) + 48;
        else
            p->alpha = func_00283CF0(1.0f) + 32;
        p->b3 = flag ? 0x48 : 0x44;
        p->b1 = 0;
        p->b2 = ref_L00_0033AA40_00[0][1];
        p->color = color;
        p->life = life * 210000.0f;
        {
            float random = func_002A7878(0.0f, 255.0f);

            p->size = size;
            p->seed = (int)random;
        }
        qcopy(out, velocity);
        out[4] = a;
        out[5] = b;
        *(int *)(out + 6) = value;
    }
    return p;
}
