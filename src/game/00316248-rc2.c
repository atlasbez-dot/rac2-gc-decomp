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

extern f32 D_001AF57C __attribute__((sda));
extern s32 D_001B2520 __attribute__((nosda));
extern s32 g_001B2520 __attribute__((nosda));
extern s32 data_001B2520 __attribute__((nosda));

extern f32 func_00283B98(f32, f32);
extern f32 func_00283180(f32);
extern s32 func_00283D38(s32, s32, f32);
extern void func_003169D0(s32);
extern void func_00281EB8(s32, s32, s32, s32, f32, f32, f32);

void func_00316248(s32 arg0) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f23;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;

    temp_f0 = func_00283B98(D_001AF57C, 0.125f);
    D_001AF57C = temp_f0;
    temp_f20 = (func_00283180(temp_f0) + 1.0f) * 0.5f;
    temp_f23 = (temp_f20 * 0.0625f) + 0.0625f;
    temp_f22 = (temp_f20 * 0.19999999f) + 0.15f;
    temp_f21 = (temp_f20 * 0.125f) + 0.125f;
    temp_s0 = func_00283D38(0x2F007F00, 0x3F007F00, temp_f20);
    temp_s1 = func_00283D38(0x2F7F7F7F, 0x5F7F7F7F, temp_f20);
    temp_s2 = func_00283D38(0x10003F00, 0x10003F00, temp_f20);
    func_003169D0(arg0);
    func_00281EB8((s32)&D_001B2520, 0x31, temp_s0, 1, temp_f21, 0.125f, 0.0f);
    func_00281EB8((s32)&g_001B2520, 0x31, temp_s1, 1, temp_f23, 0.124f, 0.0f);
    func_00281EB8((s32)&data_001B2520, 0xB, temp_s2, 1, temp_f22, 0.123f, 0.0f);
}
