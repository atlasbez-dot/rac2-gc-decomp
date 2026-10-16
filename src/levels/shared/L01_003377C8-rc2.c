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

extern f32 ref_L01_003377C8_00(void *, void *);
extern void ref_L01_003377C8_01(s8 *);
extern s8 ref_L01_003377C8_02[];

f32 func_L01_003377C8(s8 *arg0) {
    s32 n ;
    f32 var_f20;
    f32 temp_f0;
    s32 temp_s0;
    s32 temp_s1;
    s32 var_s0;

    var_f20 = 0.0f;
    if (arg0 == 0) {
        ref_L01_003377C8_01(ref_L01_003377C8_02);
        return -1.0f;
    }
    n = *(s32 *)arg0;
    var_s0 = 0;
    if (n > 0) {
        do {
            temp_s1 = var_s0 + 1;
            temp_s0 = var_s0 * 0x10;
            temp_f0 = ref_L01_003377C8_00(arg0 + (temp_s0 + 0x10), arg0 + (((temp_s1 % n) * 0x10) + 0x10));
            *(f32 *)(arg0 + temp_s0 + 0x1C) = temp_f0;
            var_s0 = temp_s1;
            var_f20 += temp_f0;
            n = *(s32 *)arg0;
        } while (var_s0 < n);
    }
    return var_f20;
}
