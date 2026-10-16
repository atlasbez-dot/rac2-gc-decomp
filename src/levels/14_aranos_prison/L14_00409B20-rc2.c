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

extern s32 g_001B259C __attribute__((sda));
f32 ref_L14_00409B20_00(f32);
f32 ref_L14_00409B20_01(f32, f32);
s32 ref_L14_00409B20_02(s32, s32, f32);
void ref_L14_00409B20_03(void *, s32, s32);
s32 ref_L14_00409B20_04(void *);
s32 ref_L14_00409B20_05(void *);
void ref_L14_00409B20_06(s32, s32);
void ref_L14_00409B20_07(s32, s32, void *);

void func_L14_00409B20(void *arg0) {
    f32 temp_f0;
    s32 temp_a0;
    s32 var_s1;
    s32 var_s2;
    u8 temp_v1;
    void *temp_s3;

    var_s2 = (s32)0x808C8C8C;
    var_s1 = (s32)0x80282828;
    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    temp_s3 = *(void **)((u8 *)arg0 + 0x68);
    switch (temp_v1) {
    case 0:
        if (ref_L14_00409B20_04(arg0) != 0) {
            temp_a0 = *(s32 *)temp_s3;
            if (temp_a0 != -1) {
                ref_L14_00409B20_06(g_001B259C + (temp_a0 << 8), 1);
            }
            ref_L14_00409B20_03(arg0, 1, -1);
        }
        break;
    case 1:
        if (ref_L14_00409B20_05(arg0) != 0) {
            ref_L14_00409B20_07(0, 0, arg0);
        }
        var_s2 = (s32)0x80468CDC;
        var_s1 = (s32)0x801E78AA;
        break;
    }

    temp_f0 = ref_L14_00409B20_01(*(f32 *)((u8 *)temp_s3 + 4), 0.107628651f);
    *(f32 *)((u8 *)temp_s3 + 4) = temp_f0;
    temp_f0 = ref_L14_00409B20_00(temp_f0);
    *(s32 *)((u8 *)arg0 + 0x78) = ref_L14_00409B20_02(
        *(s32 *)((u8 *)arg0 + 0x78),
        ref_L14_00409B20_02(var_s2, var_s1, temp_f0 * 0.5f + 0.5f),
        0.15f);
}
