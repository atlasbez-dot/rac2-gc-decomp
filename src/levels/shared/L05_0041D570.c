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

extern s32 ref_L05_0041D570_00 __attribute__((sda));
extern s32 D_001A79F0;
extern f32 ref_L05_0041D570_01(s32, void *);
extern void ref_L05_0041D570_02(void *, s32, s32, f32, f32, f32);
extern void ref_L05_0041D570_03(s32, s32, void *, s32);
extern void ref_L05_0041D570_04(s32, s32);
extern void ref_L05_0041D570_05(s32, s32, s32);
extern void ref_L05_0041D570_06(void *);
extern f32 ref_L05_0041D570_07(f32, f32);
extern void ref_L05_0041D570_08(void *);

void func_L05_0041D570(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    s32 temp_s2;
    void *temp_s1;
    void **temp_v0;

    temp_s2 = *(s32 *)((s8 *)arg0 + 0x68);
    if (ref_L05_0041D570_00 != 0) {
        temp_s1 = (s8 *)arg0 + 0x10;
        temp_f20 = ref_L05_0041D570_01(ref_L05_0041D570_00 + 0x10, temp_s1);
        if (D_001A79F0 == 0x14) {
            ref_L05_0041D570_02(temp_s1, ref_L05_0041D570_00 + 0x10, temp_s2 + 0x40, 0.008888889104127884f, 0.0033333334140479565f, 1.0666667222976685f);
        } else if (temp_f20 < 60.0f) {
            temp_v0 = *(void ***)((s8 *)arg0 + 0x24);
            temp_f0 = *(f32 *)((s8 *)temp_v0 + 0x24) * 0.02222222276031971f * temp_f20;
            *(f32 *)((s8 *)arg0 + 0x2C) = temp_f0;
            temp_f1 = *(f32 *)((s8 *)temp_v0 + 0x24) * 0.30000001192092896f;
            if (temp_f0 < temp_f1) {
                *(f32 *)((s8 *)arg0 + 0x2C) = temp_f1;
            }
            ref_L05_0041D570_02(temp_s1, ref_L05_0041D570_00 + 0x10, temp_s2 + 0x40, 0.0055555556900799274f, 0.0016666667070239782f, 0.5f);
        }
        if (temp_f20 < 0.5f) {
            ref_L05_0041D570_03(0xC, 0, arg0, 0xFBF);
            ref_L05_0041D570_04(1, 0xA);
            ref_L05_0041D570_05(0x1286, 0xA, -1);
            ref_L05_0041D570_06(arg0);
            return;
        }
    }
    *(f32 *)((s8 *)arg0 + 0xF8) = ref_L05_0041D570_07(*(f32 *)((s8 *)arg0 + 0xF8), 0.04f);
    ref_L05_0041D570_08(arg0);
}
