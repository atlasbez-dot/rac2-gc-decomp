
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

extern s32 ref_L00_00421B50_00(s32);
extern void ref_L00_00421B50_01(void *, void *, void *, f32, f32, f32);
extern void ref_L00_00421B50_02(void *, s32, void *, u8);
extern f32 ref_L00_00421B50_03 __attribute__((sda));
extern f32 ref_L00_00421B50_04 __attribute__((sda));
extern f32 ref_L00_00421B50_05 __attribute__((sda));
extern f32 ref_L00_00421B50_06 __attribute__((sda));

void func_L00_00421B50(void *arg0, s32 arg1) {
    s8 *temp_a0;
    s8 *temp_s0;
    s32 out[4];
    f32 temp_f20;
    f32 var_f12;
    f32 var_f13;
    u8 temp_v1;

    temp_a0 = (*(s8 **)((char *)(arg0) + (0x70)));
    temp_s0 = temp_a0 + 0x60;
    if (ref_L00_00421B50_00((s32)(temp_a0 + 0x126)) != 0) {
        (*(u8 *)((char *)(temp_s0) + (0xC5))) = (*(u8 *)((char *)(temp_s0) + (0xC4)));
    }
    temp_f20 = (f32) (*(s16 *)((char *)(temp_s0) + (0xC6))) * (*(f32 *)((char *)(temp_s0) + (0xC8)));
    ref_L00_00421B50_02(arg0, arg1, out, (*(u8 *)((char *)(temp_s0) + (0xC4))));
    temp_v1 = (*(u8 *)((char *)(temp_s0) + (0xC4)));
    if (temp_v1 == 3 || temp_v1 == 5 || temp_v1 == 6 || temp_v1 == 7 || temp_v1 == 1) {
        var_f12 = ref_L00_00421B50_05 + ((ref_L00_00421B50_03 - ref_L00_00421B50_05) * temp_f20);
        var_f13 = ref_L00_00421B50_06 + ((ref_L00_00421B50_04 - ref_L00_00421B50_06) * temp_f20);
    } else {
        var_f12 = ref_L00_00421B50_03;
        var_f13 = ref_L00_00421B50_04;
    }
    ref_L00_00421B50_01(arg0, temp_s0 + 0x90, out, var_f12, var_f13, 0.0f);
}
