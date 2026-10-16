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

extern s32 *func_00335E20(s8 *);
extern void func_003363C0(s8 *, f32);
extern f32 D_001ADBCC __attribute__((sda));
extern f32 D_001ADBD0 __attribute__((sda));

void func_00338810(s8 *arg0)
{
    s8 *p;
    s8 *a1;
    s32 n;
    s32 s1;
    s8 *s3;
    s8 *s4;
    s8 *v1;
    s32 *q1;
    s32 *q2;
    f32 t;
    f32 z;
    s32 k;

    p = (*(s8 **)((s8 *)(arg0) + (8)));
    n = (*(s32 *)((s8 *)(arg0) + (0x1B8)));
    s1 = ((u8 *)p)[3];
    if (n > 0) {
        s1 = s1 + 8;
        n = n - 1;
        s1 = (s1 < 0x61) ? s1 : 0x60;
        (*(s32 *)((s8 *)(arg0) + (0x1B8))) = n;
    } else {
        s1 = s1 - 8;
        s1 = (-1 < s1) ? s1 : 0;
    }
    if (s1 == 0) {
        *(*(s32 **)((s8 *)(arg0) + (4))) = 0;
    } else {
        s1 = s1 << 24;
        a1 = (*(s8 **)((s8 *)(arg0) + (8)));
        *(s32 *)a1 = (*(s32 *)a1 & 0xFFFFFF) | s1;
        s4 = arg0 + 0x10;
        s3 = arg0 + 0x5C;
        t = 0.0f;
        v1 = (*(s8 **)((s8 *)(arg0) + (0xC)));
        *(s32 *)v1 = (*(s32 *)v1 & 0xFFFFFF) | s1;
        q1 = func_00335E20(s4);
        *q1 = (*q1 & 0xFFFFFF) | s1;
        q2 = func_00335E20(s3);
        *q2 = (*q2 & 0xFFFFFF) | s1;
        if ((*(s32 *)((s8 *)(arg0) + (0x1C4))) == 1) {
            k = ((*(s32 *)((s8 *)(arg0) + (0x1D4))) >> 1) + 8;
            (*(s32 *)((s8 *)(arg0) + (0x1BC))) = 8;
            (*(s32 *)((s8 *)(arg0) + (0x1C0))) = 6;
            (*(s32 *)((s8 *)(arg0) + (0x1AC))) = (((*(s32 *)((s8 *)(arg0) + (0x1B0))) << 4) >> 1) + 6;
            z = t;
            (*(s32 *)((s8 *)(arg0) + (0x1A8))) = k;
            func_003363C0(s3, ((((f32) k - 40.0f) * 0.00495049497f) * 0.567499995f) + 0.00499999989f);
            if (z < D_001ADBCC) {
                func_003363C0(s3, D_001ADBCC);
            }
            t = ((f32) (*(s32 *)((s8 *)(arg0) + (0x1AC))) - 14.0f) * 0.00657894742f;
            func_003363C0(s4, (t * 0.850000024f) + 0.0299999993f);
            if (z <= D_001ADBD0) {
                func_003363C0(s4, D_001ADBD0);
            }
            (*(f32 *)((s8 *)(arg0) + (0x1D0))) = (t * 306.0f) + 23.5f;
        }
    }
}
