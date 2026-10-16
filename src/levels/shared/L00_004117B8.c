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

extern s8 ref_L00_004117B8_00[];
extern void ref_L00_004117B8_01(s8 *, void *, s32);
extern void ref_L00_004117B8_02(void *, void *, f32);
extern void ref_L00_004117B8_03(s32);

void func_L00_004117B8(s32 arg0) {
    s8 *e = ref_L00_004117B8_00;
    s32 i = 0x1D;
    f32 tmp[3];
    f32 k21 = 0.0008300250046886503696441650390625f;
    f32 k20 = 0.000976499984972178936004638671875f;
    s8 *p;

    do {
        if (*(s8 **)(e + 0x18) != 0) {
            ref_L00_004117B8_01(*(s8 **)(e + 0x18) + 0x10, tmp, 1);
            p = *(s8 **)(e + 0x18);
            ref_L00_004117B8_02(tmp, tmp, *(f32 *)(p + 0xC) * k21);
            p = *(s8 **)(e + 0x18);
            tmp[0] = tmp[0] + *(f32 *)p * k20;
            tmp[1] = tmp[1] + *(f32 *)(p + 4) * k20;
            tmp[2] = tmp[2] + *(f32 *)(p + 8) * k20;
        }
        i -= 1;
        e += 0x30;
    } while (i >= 0);
    ref_L00_004117B8_03(arg0);
}
