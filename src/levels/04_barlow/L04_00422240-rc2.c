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

typedef struct {
    s32 w0;
    s32 w1;
    s32 w2;
} External3;

extern void ref_L04_00422240_00(s8 *, s8 *, s32, s32, f32, f32, f32, s32, s32);
extern s32 ref_L04_00422240_01(s8 *, f32, s32, s8 *);
extern void ref_L04_00422240_02(s32, s8 *, u32);
extern void ref_L04_00422240_03(s32 *);
extern External3 ref_L04_00422240_04;
extern External3 D_0018C0B0;
extern s32 ref_L04_00422240_05 __attribute__((sda));
extern s8 ref_L04_00422240_06;

void func_L04_00422240(s8 *arg0) {
    s8 *temp_s1 = arg0 + 0x10;
    f32 one  = 1.0f;

    ref_L04_00422240_00(arg0, temp_s1, 0x10001, 5, one, one, one, 1, 0);
    if (ref_L04_00422240_01(temp_s1, one, 1, arg0) != 0) {
        s32 temp_a0 = ref_L04_00422240_04.w0;
        if (temp_a0 != 0 && temp_a0 == D_0018C0B0.w0) {
            if (ref_L04_00422240_05 <= 0) {
                ref_L04_00422240_05 = 0x3C;
            }
        }
    }
    if (ref_L04_00422240_05 > 0) {
        ref_L04_00422240_02(D_0018C0B0.w0, &ref_L04_00422240_06, 0xFFFF);
        ref_L04_00422240_03(&ref_L04_00422240_05);
    }
}
