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

extern void func_0031A098(void *);
extern s64 func_0027C878(s32);
extern f32 func_00283248(f32, f32);
extern f32 func_00282E80(void *, void *);
extern f32 func_002A7940();
extern void func_00283410(void *, f32 *);
extern void func_00282CF0(f32 *, void *, void *);
extern void func_00282F20(f32 *, f32 *, f32);
extern void func_00282D30(void *, void *, f32);
extern void func_00280B90(void *, void *, s32);
extern s8 D_001B5200[];

struct Fr {
    f32 m[16];
    s32 iv[4];
    s8 p50[0x28];
    s64 a78;
    s64 p80;
    s64 a88;
    f32 s5[16];
    f32 d0;
    f32 d4;
    f32 d8;
    s32 dc;
    f32 e0;
    f32 e4;
    f32 e8;
};

void func_0031A340(s32 u0, s8 *arg1, s32 arg2, s32 arg3, s32 arg4, f32 fparg0) {
    struct Fr fr;
    s8 *base;
    s8 *s4;
    f32 half;
    s32 t1;
    s32 t2;

    func_0031A098(&fr);
    half = 0.5f;
    fr.a78 = func_0027C878(11);
    base = D_001B5200;
    t1 = arg2 + arg3;
    fr.iv[3] = t1;
    fr.iv[2] = t1;
    fr.iv[1] = t1;
    fr.iv[0] = t1;
    s4 = base + 0x140;
    fr.a88 = 0x8000000048LL;
    fr.dc = 0;
    fr.d8 = func_00283248((*(f32 *)((s8 *)(base) + (0x140))) - (*(f32 *)((s8 *)(arg1) + (0))), (*(f32 *)((s8 *)(base) + (0x144))) - (*(f32 *)((s8 *)(arg1) + (4))));
    fr.d4 = -func_00283248(func_00282E80(arg1, s4), (*(f32 *)((s8 *)(base) + (0x148))) - (*(f32 *)((s8 *)(arg1) + (8))));
    fr.d0 = func_002A7940();
    func_00283410(fr.s5, &fr.d0);
    func_00282CF0(&fr.e0, s4, arg1);
    func_00282F20(&fr.e0, &fr.e0, half);
    fr.s5[12] = (*(f32 *)((s8 *)(arg1) + (0))) + fr.e0;
    fr.s5[13] = (*(f32 *)((s8 *)(arg1) + (4))) + fr.e4;
    fr.s5[14] = (*(f32 *)((s8 *)(arg1) + (8))) + fr.e8;
    fr.s5[15] = 1.0f;
    func_00282D30(&fr, &fr, fparg0);
    func_00282D30(&fr.m[4], &fr.m[4], fparg0);
    func_00282D30(&fr.m[8], &fr.m[8], fparg0);
    func_00282D30(&fr.m[12], &fr.m[12], fparg0);
    func_00280B90(&fr, fr.s5, 0);
    t2 = arg2 + arg4;
    fr.iv[3] = t2;
    fr.iv[2] = t2;
    fr.iv[1] = t2;
    fr.iv[0] = t2;
    func_00282D30(&fr, &fr, half);
    func_00282D30(&fr.m[4], &fr.m[4], half);
    func_00282D30(&fr.m[8], &fr.m[8], half);
    func_00282D30(&fr.m[12], &fr.m[12], half);
    func_00280B90(&fr, fr.s5, 0);
}
