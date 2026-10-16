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

void ref_L14_00423240_00(void *);
void ref_L14_00423240_01(void *, s32, s32);
void *ref_L14_00423240_02(void *, s32, s32);
void ref_L14_00423240_03(void *, void *, s32, f32, f32);
void ref_L14_00423240_04(void *, void *, s32);
extern f32 g_001B16B0 __attribute__((sda));

void func_L14_00423240(void *arg0) {
    void *temp_s1;
    void *temp_v0;
    void *temp_v0_2;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    temp_v0 = ref_L14_00423240_02(arg0, 0x10000, 1);
    if (temp_v0 != 0) {
        temp_v0_2 = *(void **)((u8 *)temp_v0 + 0x20);
        if (temp_v0_2 != 0 && *(s16 *)((u8 *)temp_v0_2 + 0xAA) == 0xB69) {
            if (*(u8 *)((u8 *)arg0 + 0x31) == 0) {
                *(s32 *)((u8 *)temp_v0 + 0x2C) = 0;
            } else {
                *(f32 *)((u8 *)temp_v0 + 0x2C) = 1.0f;
            }
        }
    }
    ref_L14_00423240_04(arg0, (u8 *)temp_s1 + 0x60, 0);
    if (*(f32 *)((u8 *)temp_s1 + 0x20) <= 0.0f) {
        ref_L14_00423240_03(arg0, (u8 *)arg0 + 0x10, -1, 1.0f, 13.0f);
        ref_L14_00423240_01(arg0, 0, 3);
        ref_L14_00423240_00(arg0);
        return;
    }
    if (*(f32 *)((u8 *)arg0 + 0x18) < g_001B16B0) {
        ref_L14_00423240_01(arg0, 0, 3);
        ref_L14_00423240_00(arg0);
    }
}
