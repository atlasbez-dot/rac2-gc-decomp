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

extern void ref_L17_003C7018_00(void *, void *, void *, f32, f32, f32);
extern void ref_L17_003C7018_01(void *, void *, void *, f32, f32, f32);
extern f32 ref_L17_003C7018_02 __attribute__((sda));
extern f32 ref_L17_003C7018_03 __attribute__((sda));
extern f32 ref_L17_003C7018_04 __attribute__((sda));
extern f32 ref_L17_003C7018_05 __attribute__((sda));
extern f32 ref_L17_003C7018_06 __attribute__((sda));

void func_L17_003C7018(void *arg0) {
    s8 *temp_s0;

    temp_s0 = (*(s8 **)((s8 *)(arg0) + (0x68)));
    if ((*(u8 *)((s8 *)(arg0) + (0x20))) == 3) {
        ref_L17_003C7018_00(arg0, temp_s0 + 0x11C, temp_s0 + 0x118, ref_L17_003C7018_02, ref_L17_003C7018_03 * 0.00029088825f, (*(f32 *)((s8 *)(temp_s0) + (0x12C))));
    } else {
        ref_L17_003C7018_00(arg0, temp_s0 + 0x11C, temp_s0 + 0x118, ref_L17_003C7018_02, ref_L17_003C7018_03 * 0.00029088825f, -1.0f);
    }
    ref_L17_003C7018_01(arg0, temp_s0 + 0x120, temp_s0 + 0x124, ref_L17_003C7018_04, ref_L17_003C7018_05 * 0.00029088825f, ref_L17_003C7018_06 * 0.00029088825f);
}
