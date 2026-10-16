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

extern s32 *ref_L09_003EA058_00[];
extern s16 ref_L09_003EA058_01(s8 *, s32, s8 *, s16, s32, f32);
extern f32 ref_L09_003EA058_02(s8 *, s32);
extern void ref_L09_003EA058_03(s8 *, s8 *, f32);

void func_L09_003EA058(s8 *arg0, s32 arg1) {
    s8 buf[0x10];
    s8 *s0 ;
    s16 v;
    s32 t0;
    s16 r;
    s32 k;
    s32 **pt;
    f32 g;

    s0 = (*(s8 **)((s8 *)(arg0) + (0x68)));
    v = (*(s16 *)((s8 *)(s0) + (0x118)));
    t0 = (v < (*(s16 *)((s8 *)(s0) + (0x11A)))) ? 1 : -1;
    r = ref_L09_003EA058_01(arg0, arg1, buf, v, t0, (*(f32 *)((s8 *)(s0) + (0x78))) * 10.0f);
    (*(s16 *)((s8 *)(s0) + (0x118))) = r;
    pt = &ref_L09_003EA058_00[arg1];
    k = (*(s16 *)((s8 *)(s0) + (0x11A))) * 0x10 + 0x10;
    g = ref_L09_003EA058_02(arg0 + 0x10, (s32)*pt + k);
    ref_L09_003EA058_03(arg0, buf, g);
}
