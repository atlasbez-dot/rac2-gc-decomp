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

extern void ref_L11_0044C220_00(void *, s32, void *, void *, f32, s32, s32, s32, s32);
extern s32 ref_L11_0044C220_01 __attribute__((sda));
extern s32 ref_L11_0044C220_02 __attribute__((sda));
extern s32 ref_L11_0044C220_03;

void func_L11_0044C220(void *arg0) {
    void *temp_v0;
    f32 f5;
    s32 i6;
    s32 i7;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x68)));
    f5 = (*(f32 *)((s8 *)(temp_v0) + (0x4B8)));
    i6 = (*(s32 *)((s8 *)(temp_v0) + (0x4B4)));
    i7 = (*(s32 *)((s8 *)(temp_v0) + (0x4B0)));
    ref_L11_0044C220_00(&ref_L11_0044C220_01, 4, (s8 *)temp_v0 + 0x270, (s8 *)temp_v0 + 0x370, f5, i6, i7, ref_L11_0044C220_02, ref_L11_0044C220_03);
}
