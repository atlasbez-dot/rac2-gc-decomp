/* Near miss, remeasured 2026-10-23: 288 bytes, 0/27 in US, PAL and US2.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * First difference +0x40 is p2.x in f4 instead of f3. The qualified copy profile
 * reproduces both copies without the old draft's artificial volatile stores.
 * The remaining permutation spans t2/t3 and the control-point coordinates.
 * Commuting products places t2/p0.x in retail's f5/f6, but leaves a cyclic
 * f2/f3/f4 allocation and reverses multiplication operands; explicit x locals
 * change load order. -G8 is identical to -G0. Retain the closer baseline below.
 * Next useful work: inspect allocator priorities for the coefficient expression.
 */
typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    float x, y, z, w;
} V4;

/* cubic curve through four control vectors: at a phase of zero the first is copied and
   at one the second, in between the three first components follow the cubic built from
   the four vectors and the fourth component is cleared */
void func_L00_003E9540(V4 *out, V4 *p0, V4 *p1, V4 *p2, float *p3, float t)
{
    float t2;
    float t3;
    float c;
    float a;

    if (t == 0.0f) {
        *(TI128 *)out = *(TI128 *)p0;
        return;
    }
    if (t == 1.0f) {
        *(TI128 *)out = *(TI128 *)p1;
        return;
    }
    t2 = t * t;
    t3 = t2 * t;
    a = p2->x - p0->x;
    c = (p3[0] - p1->x) - a;
    out->x = c * t3 + (a - c) * t2 + (p1->x - p2->x) * t + p0->x;
    c = (p3[1] - p1->y) - (p2->y - p0->y);
    out->y = c * t3 + ((p2->y - p0->y) - c) * t2 + (p1->y - p2->y) * t + p0->y;
    c = (p3[2] - p1->z) - (p2->z - p0->z);
    out->z = c * t3 + ((p2->z - p0->z) - c) * t2 + (p1->z - p2->z) * t + p0->z;
    out->w = 0.0f;
}
