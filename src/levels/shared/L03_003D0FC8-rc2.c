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

extern s32 ref_L03_003D0FC8_00(s32);
extern f32 ref_L03_003D0FC8_01(f32, f32);
extern void ref_L03_003D0FC8_02(void *, f32, f32);
extern void ref_L03_003D0FC8_03(void *, void *, s32);
extern void ref_L03_003D0FC8_04(void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);

void func_L03_003D0FC8(void *arg0, s32 arg1, s32 arg2) {
    f32 temp_f20;
    f32 temp_f21;
    s32 temp_s1;
    u8 scratch[0x10];

    (void)arg0;
    temp_f20 = ref_L03_003D0FC8_01(0.25f, 1.0f);
    temp_s1 = ref_L03_003D0FC8_00(2);
    temp_f21 = ref_L03_003D0FC8_01(3.0f, 7.0f) * 0.00027777778f;
    ref_L03_003D0FC8_02(scratch, 0.0f, 0.1f);
    ref_L03_003D0FC8_03(scratch, scratch, arg1);
    ref_L03_003D0FC8_04(scratch, 0x28, 0x7F800000u, 0,
                  temp_s1, arg2, temp_f20 * 0.2f, temp_f20, temp_f21, 0);
    ref_L03_003D0FC8_04(scratch, 0x3C, 0x7F7F7F7Fu, 1,
                  -temp_s1, arg2, temp_f20 * 0.14f,
                  temp_f20 * 0.7f, temp_f21, 0);
}
