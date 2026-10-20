
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

extern s32 ref_L02_00331440_00(s32, s32, f32);
extern void *ref_L02_00331440_01();

s32 func_L02_00331440(s32 arg0, s32 arg1, s32 arg2,
                   f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f20;
    f32 temp_f22;
    s32 temp_s3;
    s32 temp_v0;
    void *temp_v0_2;

    temp_v0_2 = ref_L02_00331440_01(arg0);
    if (temp_v0_2 != 0) {
        goto process_object;
    }
    return 8;
process_object:
    temp_s3 = *(s32 *)((u8 *)temp_v0_2 + 0x38);
    *(s32 *)((u8 *)temp_v0_2 + 0x38) = arg2;
    temp_f22 = *(f32 *)((u8 *)temp_v0_2 + 0x28);
    if (fparg1 > 0.0f) {
        *(f32 *)((u8 *)temp_v0_2 + 0x28) = fparg1;
    }
    temp_f20 = *(f32 *)((u8 *)temp_v0_2 + 0x20);
    if (fparg2 > 0.0f) {
        *(f32 *)((u8 *)temp_v0_2 + 0x20) = fparg2;
    }
    temp_v0 = ref_L02_00331440_00(arg0, arg1, fparg0);
    *(volatile f32 *)((u8 *)temp_v0_2 + 0x20) = temp_f20;
    *(volatile s32 *)((u8 *)temp_v0_2 + 0x38) = temp_s3;
    *(volatile f32 *)((u8 *)temp_v0_2 + 0x28) = temp_f22;
    return temp_v0;
}
