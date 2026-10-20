
/* SPDX-License-Identifier: MIT
 * MIT License
 * 
 * Copyright (c) 2026 Forja contributors
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

extern f32 ref_L00_0031B9F8_00(s32 arg0);
extern s32 ref_L00_0031B9F8_01(f32 arg0);

f32 func_L00_0031B9F8(void *arg0, void *arg1, s32 *arg2, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f20;
    s32 temp_v0;

    temp_v0 = ref_L00_0031B9F8_01(*(f32 *)((u8 *)arg1 + 8) / fparg0);
    temp_f20 = ref_L00_0031B9F8_00(temp_v0);
    temp_f0 = (*(f32 *)((u8 *)arg0 + 8) + (*(f32 *)((u8 *)arg1 + 8) * temp_f20)) -
               (ref_L00_0031B9F8_00((temp_v0 * temp_v0 + temp_v0) >> 1) * fparg0);
    if (arg2 != 0) {
        *arg2 = temp_v0;
    }
    return temp_f0;
}
