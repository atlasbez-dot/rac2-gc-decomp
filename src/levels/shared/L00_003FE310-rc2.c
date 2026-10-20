
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

extern void ref_L00_003FE310_00(int a);
extern float ref_L00_003FE310_01(float a, float b);
extern unsigned int ref_L00_003FE310_02(int a, int b);
extern void ref_L00_003FE310_03(s8 *p, float a, float b);
extern s8 *ref_L00_003FE310_04(float fa, float fb, float fc, float fd, s8 *p, int z,
                         s8 *local, unsigned int v, int one);
extern void ref_L00_003FE310_05(s8 *a, s8 *b, float k);
extern void ref_L00_003FE310_06(s8 *a, s8 *b, int c, int d);
extern s8 ref_L00_003FE310_07[];

void func_L00_003FE310(s8 *unused, s8 *arg, s8 *arg2)
{
    s8 local[16];
    float f;
    int i;
    unsigned int v;
    unsigned int w;
    unsigned int x;
    s8 *r;

    i = 19;
    do {
        ref_L00_003FE310_00(2);
        ref_L00_003FE310_00(2);
        f = ref_L00_003FE310_01(70000.0f, 150000.0f);
        v = ref_L00_003FE310_02(10, 127);
        w = (v << 8) | 0x7f000000U;
        x = (v << 16) | w;
        v = x | v;
        ref_L00_003FE310_03(local, 1.6666668670950457453728e-05f,
                      6.6666672937572002410889e-03f);
        r = ref_L00_003FE310_04(0.3f, 1.0f, 1.01f, f, arg, 0, local, v, 1);
        if (r != 0) {
            s8 *q = r + 32;

            *(short *)(r + 10) = 120;
            *(int *)(q + 4) = 2;
            *(s8 *)(q + 10) = 127;
            *(s8 *)(q + 11) = *(unsigned char *)(r + 10);
        }
        i = i - 1;
    } while (i >= 0);
    ref_L00_003FE310_05(ref_L00_003FE310_07, arg2, 1.5f);
    ref_L00_003FE310_06(ref_L00_003FE310_07, arg, 0, 0);
}
