
/* SPDX-License-Identifier: MIT
 * MIT License
 * 
 * Copyright (c) 2026 RC2 decomp contributions
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "common.h"

extern float ref_L00_002D3290_00(float v);
extern float ref_L00_002D3290_01(float v);
extern void ref_L00_002D3290_02(float *m, s8 *src);
extern void ref_L00_002D3290_03(float *dst, float *src, float *m);
extern void ref_L00_002D3290_04(void *q);
extern float ref_L00_002D3290_05(float a, float b);
extern s8 D_00189E20[];

typedef int TI __attribute__((mode(TI)));

struct Fr {
    f32 m[16];
    f32 v[4];
    f32 q1[4];
    f32 q2[4];
    TI t;
};

void func_L00_002D3290(void)
{
    struct Fr fr;
    s8 *b;
    f32 z;

    z = 0.0f;
    fr.v[0] = ref_L00_002D3290_00(z);
    fr.v[1] = ref_L00_002D3290_01(z);
    fr.v[2] = z;
    ref_L00_002D3290_02(fr.m, D_00189E20 + 0x90);
    ref_L00_002D3290_03(fr.v, fr.v, fr.m);
    b = D_00189E20;
    if (*(f32 *)(b + 0x2A0) != 0.0f || *(f32 *)(b + 0x2A4) != 0.0f) {
        fr.t = *(TI *)(b + 0x2A0);
        ref_L00_002D3290_04(fr.q1);
        ref_L00_002D3290_04(fr.q2);
        fr.q1[2] = -ref_L00_002D3290_05(*(f32 *)(b + 0x2A0), *(f32 *)(b + 0x2A4));
        ref_L00_002D3290_02(fr.m, fr.q1);
        ref_L00_002D3290_03(fr.v, fr.v, fr.m);
        ref_L00_002D3290_03((f32 *)&fr.t, (f32 *)&fr.t, fr.m);
        fr.q2[1] = -ref_L00_002D3290_05(((f32 *)&fr.t)[2], ((f32 *)&fr.t)[0]);
        ref_L00_002D3290_02(fr.m, fr.q2);
        ref_L00_002D3290_03(fr.v, fr.v, fr.m);
        fr.q1[2] = -fr.q1[2];
        ref_L00_002D3290_02(fr.m, fr.q1);
        ref_L00_002D3290_03(fr.v, fr.v, fr.m);
    }
    ref_L00_002D3290_05(fr.v[0], fr.v[1]);
}
