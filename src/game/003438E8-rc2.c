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

extern void func_00336320(void *a0);
extern void func_00336A78(void *a0);
extern void func_00342BE8(void *a0);
extern s32 func_00342BC0(void *a0);
extern s32 func_00288FB8(s32 a0);
extern void func_00336A38(void *a0, s32 a1);
extern u8 D_00139568[];
extern struct T D_00239BA0[];

struct T {
    s8 p00[8];
    s32 w08;
    s8 p0C[0xD4];
};

struct S2 {
    s8 p000[0x4C];
    s8 p04C[0x4C];
    s8 p098[0x118];
    s8 p1B0[0x48];
    s8 p1F8[0x48];
    s8 p240[0x50];
    s32 w290;
    s8 p294[4];
    s8 p298[0x48];
};

void func_003438E8(struct S2 *a0) {
    s32 r;
    s32 v;

    if (a0->w290 != 0) {
        func_00336320(a0);
        func_00336320(a0->p04C);
        func_00336320(a0->p098);
        func_00336A78(a0->p1B0);
        func_00342BE8(a0->p298);
        r = func_00342BC0(a0->p298);
        v = func_00288FB8(D_00239BA0[D_00139568[r]].w08);
        func_00336A38(a0->p1F8, v);
        func_00336A78(a0->p1F8);
        func_00336A78(a0->p240);
    }
}
