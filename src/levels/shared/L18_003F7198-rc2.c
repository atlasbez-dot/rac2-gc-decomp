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

extern s8 ref_L18_003F7198_00[];
extern f32 ref_L18_003F7198_01(s8 *, s8 *);
extern void ref_L18_003F7198_02(s8 *);
extern void ref_L18_003F7198_03(s8 *, s32);
extern void ref_L18_003F7198_04(s8 *, s8 *, s32, s32, f32);

void func_L18_003F7198(s8 *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    u16 temp_v1;
    s8 *temp_s1;

    temp_v1 = *(u16 *)(arg0 + 0x96);
    temp_s1 = *(s8 **)(arg0 + 0x68);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)(arg0 + 0x96) = temp_v1 + 1;
    }
    *(s16 *)(temp_s1 + 0x290) = 0;
    if (*(u8 *)(arg0 + 0x31) != 0 &&
        ref_L18_003F7198_01(arg0 + 0x10, ref_L18_003F7198_00) < 24.0f) {
        ref_L18_003F7198_02(arg0);
        *(s8 *)(arg0 + 0x6F) = 0x16;
    }
    temp_f0 = *(f32 *)(arg0 + 0x10);
    if (temp_f0 < 5.0f) goto block_15;
    if (temp_f0 > 1018.0f) goto block_15;
    temp_f0_2 = *(f32 *)(arg0 + 0x14);
    if (temp_f0_2 < 5.0f || temp_f0_2 > 1018.0f ||
        (temp_f0_3 = *(f32 *)(arg0 + 0x18), temp_f0_3 < 5.0f) ||
        temp_f0_3 > 1018.0f) {
block_15:
        ref_L18_003F7198_03(arg0, 0);
    }
    ref_L18_003F7198_04(arg0, temp_s1 + 0x2B0, 2, 1, 1.8f);
}
