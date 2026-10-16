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

extern u8 ref_L02_003C4E18_00[];
void ref_L02_003C4E18_01(void *, s32, f32 *);
f32 ref_L02_003C4E18_02(f32, f32);
s32 func_001234F0(f32);
void ref_L02_003C4E18_03(void *, s32, s32, s32, s32);
void ref_L02_003C4E18_04(void *, s32, f32);

void func_L02_003C4E18(void *arg0) {
    void *temp_s0 ;
    void *temp_s1 ;
    s32 temp_s2 ;
    s32 temp_s3 ;
    f32 temp_f20 ;
    f32 stack_values[4];

    temp_s0 = arg0;
    ref_L02_003C4E18_01(arg0, 1, stack_values);
    temp_f20 = ref_L02_003C4E18_02(*(f32 *)((u8 *)arg0 + 0xF8), 3.14159f);
    temp_s1 = ref_L02_003C4E18_00;
    temp_s3 = func_001234F0(stack_values[0]);
    temp_s2 = func_001234F0(stack_values[1]);
    temp_s0 = func_001234F0(stack_values[2]);
    ref_L02_003C4E18_03(temp_s1, temp_s3, temp_s2, temp_s0, func_001234F0(temp_f20));
    ref_L02_003C4E18_04(stack_values, 0, temp_f20);
}
