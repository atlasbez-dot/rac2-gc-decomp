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

extern f32 ref_L04_00412E38_00(f32);
extern f32 ref_L04_00412E38_01(f32);
extern f32 ref_L04_00412E38_02(f32, f32);

void func_L04_00412E38(void *arg0, void *arg1, f32 fparg0, f32 fparg1) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;

    temp_f0 = ref_L04_00412E38_02((*(f32 *)((s8 *)(arg1) + (0x38C))), fparg0);
    (*(f32 *)((s8 *)(arg1) + (0x38C))) = temp_f0;
    temp_f20 = ref_L04_00412E38_00(temp_f0) * fparg1;
    temp_f1 = (*(f32 *)((s8 *)(arg0) + (0xF4))) + (ref_L04_00412E38_01((*(f32 *)((s8 *)(arg1) + (0x38C)))) * fparg1);
    (*(f32 *)((s8 *)(arg0) + (0xF0))) = (*(f32 *)((s8 *)(arg0) + (0xF0))) + temp_f20;
    (*(f32 *)((s8 *)(arg0) + (0xF4))) = temp_f1;
}
