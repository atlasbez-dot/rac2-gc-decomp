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

extern f32 ref_L03_0042B930_00 __attribute__((sda));
extern void ref_L03_0042B930_01(void *, void *, void *);
extern f32 ref_L03_0042B930_02(f32, f32);
extern void ref_L03_0042B930_03(void *);

void func_L03_0042B930(void *arg0) {
    s8 *arg = (s8 *)arg0;
    s8 *temp_s0 = *(s8 **)(arg + 0x68);
    s8 *parent = *(s8 **)(arg + 0x24);
    u32 temp_v0;

    *(f32 *)(arg + 0x2C) = *(f32 *)(parent + 0x24) * ref_L03_0042B930_00;
    *(f32 *)(temp_s0 + 0x08) = *(f32 *)(temp_s0 + 0x08) - 0.004166667f;
    ref_L03_0042B930_01(arg + 0x10, arg + 0x10, temp_s0);
    ref_L03_0042B930_01(arg + 0xF0, arg + 0xF0, temp_s0 + 0x10);
    *(f32 *)(arg + 0xF0) = ref_L03_0042B930_02(*(f32 *)(arg + 0xF0), *(f32 *)(temp_s0 + 0x10));
    *(f32 *)(arg + 0xF4) = ref_L03_0042B930_02(*(f32 *)(arg + 0xF4), *(f32 *)(temp_s0 + 0x14));
    *(f32 *)(arg + 0xF8) = ref_L03_0042B930_02(*(f32 *)(arg + 0xF8), *(f32 *)(temp_s0 + 0x18));
    temp_v0 = *(u8 *)(arg + 0xBC) - 1;
    *(u8 *)(arg + 0xBC) = (u8)temp_v0;
    if ((temp_v0 & 0xFF) == 0) {
        ref_L03_0042B930_03(arg0);
    }
}
