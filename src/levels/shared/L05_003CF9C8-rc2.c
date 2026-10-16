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

extern f32 ref_L05_003CF9C8_00 __attribute__((sda));
extern f32 ref_L05_003CF9C8_01(f32, f32);
extern f32 ref_L05_003CF9C8_02(void);
extern s32 ref_L05_003CF9C8_03(s16);

void func_L05_003CF9C8(void *arg0) {
    f32 temp_f0;
    void *temp_s1;
    s32 var_v0;

    temp_s1 = *(void **)((s8 *)arg0 + 0x68);
    *(u8 *)((s8 *)arg0 + 0x30) = 0xFF;
    *(s16 *)((s8 *)arg0 + 0x32) = 0x1FF;
    var_v0 = ref_L05_003CF9C8_03(*(s16 *)((s8 *)arg0 + 0xAA));
    *(f32 *)((s8 *)arg0 + 0x2C) = *(f32 *)((s8 *)arg0 + 0x2C) * *(f32 *)((s8 *)&ref_L05_003CF9C8_00 + (var_v0 * 4));
    *(f32 *)((s8 *)arg0 + 0xF0) = ref_L05_003CF9C8_02();
    *(f32 *)((s8 *)arg0 + 0xF4) = ref_L05_003CF9C8_02();
    *(f32 *)((s8 *)arg0 + 0xF8) = ref_L05_003CF9C8_02();
    *(f32 *)((s8 *)temp_s1 + 0x0) = ref_L05_003CF9C8_01(0.0f, 0.5f) * 0.017453294f;
    *(f32 *)((s8 *)temp_s1 + 0x4) = ref_L05_003CF9C8_01(0.0f, 1.0f) * 0.017453294f;
    temp_f0 = ref_L05_003CF9C8_01(0.0f, 2.0f) * 0.017453294f;
    *(f32 *)((s8 *)temp_s1 + 0xC) = 1.0f;
    *(f32 *)((s8 *)temp_s1 + 0x8) = temp_f0;
}
