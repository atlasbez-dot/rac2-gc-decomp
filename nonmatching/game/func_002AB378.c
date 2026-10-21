#include "include_asm.h"

/* Near miss for func_002AB378 (boot 0x002AB378, level 00 0x0031E930, 27 levels).
 *
 * The retail body turns a 3x4 float matrix into a quaternion: when the trace of
 * the matrix is positive it takes the short way round, otherwise it picks the
 * largest diagonal element and works from there.  The candidate recovers the
 * whole body - the 12-byte copy of the index table, the two halves, the calls,
 * the frame, the stack layout - and 160 of the retail's 161 instructions match
 * with "-O2 -G0 -ffunction-sections -g" (the default flags of the unit plus
 * "-g", which gives the division its two nops).
 *
 * What this candidate gets wrong:
 *   - the branch to the second half (bc1fl) has the wrong instruction in its
 *     delay slot: the retail fills it with a copy of the load of in[9] that the
 *     first half needs (lwc1 $f5, 0x24($s0)), this cc1 fills it with the load
 *     of in[8] that the second half needs (lwc1 $f4, 0x20($s0)) and then does
 *     not load in[8] again.  The candidate is therefore one instruction short.
 *     The order of the statements in the second half (where the copy of in[8]
 *     sits among the other loads of the matrix) changes which load lands in
 *     the delay slot, but no order tried gives the retail's in[9].
 *   - the registers of the second half follow from that: the retail keeps
 *     in[1] in $f4 and in[8] in $f3, this cc1 the other way round, and the
 *     store of the matrix' seventh word (the scale of the first half, which the
 *     second half reads uninitialised) lands one slot earlier.
 *   - the last difference is the order of the index arithmetic: the retail
 *     computes sll $v1, $s1, 2 before the three mults, this cc1 after the
 *     first one.
 *
 * The matrix is filled from the input's words 0, 1, 2, 4, 5, 6, 8 and 10 - the
 * input is a 3x4 array of floats and the matrix its first three columns.  The
 * index table at 0x1A9EA0 holds the three indices the second half walks
 * (it reads them as int v[3] out of a 12-byte copy).
 */
/* the three indices the second half of func_002AB378 walks */
typedef struct { int v[3]; } Perm;

extern Perm D_001A9EA0;
extern float func_00282C10(float x);

void func_002AB378(void *out, void *in)
{
    float *o = (float *)out;
    float *v = (float *)in;
    Perm perm;
    float m[3][3];
    float scale;
    float t;
    int i, j, k;

    perm = D_001A9EA0;

    if (v[0] + v[5] + v[10] > 0.0f) {
        t = func_00282C10(v[0] + v[5] + v[10] + 1.0f);
        scale = t;
        o[3] = scale * 0.5f;
        scale = 0.5f / scale;
        o[0] = (v[9] - v[6]) * scale;
        o[1] = (v[2] - v[8]) * scale;
        o[2] = (v[4] - v[1]) * scale;
    } else {
        m[0][0] = v[0];
        m[0][1] = v[1];
        m[0][2] = v[2];
        m[1][0] = v[4];
        m[1][1] = v[5];
        m[1][2] = v[6];
        m[2][0] = v[8];
        m[2][1] = scale;
        m[2][2] = v[10];
        i = 0;
        if (v[0] < v[5])
            i = 1;
        if (!(m[i][i] < v[10]))
            i = 2;
        j = perm.v[i];
        k = perm.v[j];
        t = func_00282C10(m[i][i] - (m[j][j] + m[k][k]) + 1.0f);
        scale = t;
        o[i] = scale * 0.5f;
        if (scale != 0.0f)
            scale = 0.5f / scale;
        o[3] = (m[k][j] - m[j][k]) * scale;
        o[j] = (m[j][i] + m[i][j]) * scale;
        o[k] = (m[k][i] + m[i][k]) * scale;
    }
}
