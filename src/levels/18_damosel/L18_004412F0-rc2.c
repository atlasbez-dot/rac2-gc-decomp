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

extern void ref_L18_004412F0_00(void *);
extern void ref_L18_004412F0_01(void *, s32, s32);
extern s32 ref_L18_004412F0_02(void *, s32, s32);
extern void ref_L18_004412F0_03(void *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void ref_L18_004412F0_04(void *, s32, s32, s32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 ref_L18_004412F0_05 __attribute__((sda));
extern s32 ref_L18_004412F0_06 __attribute__((sda));
extern s32 ref_L18_004412F0_07 __attribute__((sda));

void func_L18_004412F0(void *arg0) {
    u8 state = *(u8 *)((u8 *)arg0 + 0x20);
    s32 *temp_s1 = *(s32 **)((u8 *)arg0 + 0x68);

    switch (state) {
    case 0:
        ref_L18_004412F0_01(arg0, 1, -1);
        return;
    case 1:
        if (ref_L18_004412F0_02(arg0, 0x4010000, 0) != 0 && *temp_s1 == 0) {
            ref_L18_004412F0_01(arg0, 2, -1);
        }
        *(u8 *)((u8 *)arg0 + 0xA8) = 0xFF;
        return;
    case 2:
        ref_L18_004412F0_03(arg0, &ref_L18_004412F0_07, &ref_L18_004412F0_06, &ref_L18_004412F0_05,
                      0xFFFF, 0, -1, 0, 0xFFFF, 0xFF, 0);
        ref_L18_004412F0_04((u8 *)arg0 + 0x10, 0, 5, 5,
                      *(f32 *)((u8 *)arg0 + 0x2C) * 10.0f, 20.0f,
                      5, 5, 5, 0, 1, 0, 1, 0);
        ref_L18_004412F0_00(arg0);
        return;
    }
}
