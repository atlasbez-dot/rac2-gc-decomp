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

extern s32 ref_L05_003D0420_00(s32);
extern s32 ref_L05_003D0420_01(s32, s32, void *, s32);
extern void *ref_L05_003D0420_02(void);
extern void ref_L05_003D0420_03(void *, u32, s32, s32, f32, f32, f32, f32, s32, s32, s32);
extern s32 D_001A79F0 __attribute__((sda));

void func_L05_003D0420(void *arg0) {
    void *temp_s1;
    void *temp_v0;

    temp_s1 = *(void **)((s8 *)arg0 + 0x68);
    temp_v0 = ref_L05_003D0420_02();
    if (temp_v0 != 0 &&
        *(s32 *)((s8 *)temp_v0 + 0x120) != 0 &&
        *(s32 *)((s8 *)temp_s1 + 0x1B8) == 0) {
        if (*(u8 *)((s8 *)arg0 + 0x20) == 1) {
            if (D_001A79F0 == 0xF) {
                ref_L05_003D0420_03(arg0, 0x60008000, 1, 0,
                              0.6f, 2.0f, 1.0f, 1.0f,
                              0, -1, 0);
            } else {
                ref_L05_003D0420_03(arg0, 0x60008000, 1, 0,
                              1.0f, 2.0f, 1.0f, 1.0f,
                              0, -1, 0);
            }
        }
        if (ref_L05_003D0420_00(3) == 0) {
            ref_L05_003D0420_01(0, 0, arg0, 0x957);
        }
        *(s32 *)((s8 *)temp_s1 + 0x1B8) = 0x14;
    }
}
