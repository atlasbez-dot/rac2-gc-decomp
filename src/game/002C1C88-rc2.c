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

extern f32 func_00282C48(f32);
extern s32 func_00282CC0();
extern s32 func_00283CF0(f32);
extern s32 func_002B9180();

void func_002C1C88(s32 arg0) {
    s32 temp_s1;
    f32 temp_f0;
    f32 temp_f1;
    f32 *temp_v0;
    s32 temp_v0_2;

    temp_s1 = arg0 + 0x20;
    func_00282CC0(arg0 + 0x10, arg0 + 0x10, temp_s1);
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (*(f32 *)((s8 *)(arg0) + (0xC))) + 5880.0f;
    temp_f0 = (*(f32 *)((s8 *)(temp_s1) + (0x14))) * 0.98f;
    temp_f1 = (*(f32 *)((s8 *)(temp_s1) + (0x10))) + temp_f0;
    (*(f32 *)((s8 *)(temp_s1) + (0x14))) = temp_f0;
    (*(f32 *)((s8 *)(temp_s1) + (0x10))) = temp_f1;
    (*(s8 *)((s8 *)(arg0) + (8))) = func_00283CF0(temp_f1);
    temp_v0 = (*(f32 **)((s8 *)(temp_s1) + (0x18)));
    if ((temp_v0 != 0) && (func_00282C48((*(f32 *)((s8 *)(arg0) + (0x18))) - *temp_v0) < 0.2f)) {
        (*(f32 *)((s8 *)(arg0) + (0x18))) = *(*(f32 **)((s8 *)(temp_s1) + (0x18))) + 0.02f;
    }
    temp_v0_2 = (*(u16 *)((s8 *)(arg0) + (0xA))) - 1;
    (*(u16 *)((s8 *)(arg0) + (0xA))) = temp_v0_2;
    if ((temp_v0_2 << 16) == 0) {
        (*(u16 *)((s8 *)(arg0) + (0xA))) = 1;
        (*(s32 *)((s8 *)(arg0) + (4))) = (*(s32 *)((s8 *)(arg0) + (4))) + 0xFF000000;
    }
    if (((*(s32 *)((s8 *)(arg0) + (4))) & 0xFF000000) == 0) {
        func_002B9180(arg0);
    }
}
