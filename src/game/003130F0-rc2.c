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

extern s8 D_001B5340[];
extern s8 D_0018A0E0[];
extern f32 D_001AF1A4 __attribute__((sda));
extern f32 D_001AF1A8 __attribute__((sda));
extern u8 D_001AF1AC;
extern s32 D_001AF1B0;
extern s32 D_001AF1B4;
extern s32 D_001AF1B8;
extern f32 D_001AF1BC __attribute__((sda));
extern f32 D_001AF1C0 __attribute__((sda));
extern void func_00282CF0(s8 *, s8 *, s32);
extern void func_00282D30(s8 *, s8 *, f32);
extern s32 func_002A77E0(s32);
extern f32 func_002A7878(f32, f32);
extern f32 func_002A7940(void);
extern void func_002ACEC0(s8 *, s8 *, s8 *, f32);
extern void func_002C3150(s32, s8 *, s32, u8, f32, u8, s32);

void func_003130F0(s32 arg0) {
    s8 sp0[16];
    s8 sp10[16];
    s8 sp20[16];
    s32 temp_s2;
    s32 var_s2;
    s32 temp_s1;
    u8 temp_s0;
    s32 temp_v0;
    u8 temp_s0_2;
    s32 temp_v0_2;

    temp_s2 = (*(s32 *)((s8 *)(arg0) + (0x68)));
    func_00282CF0(sp0, D_001B5340, arg0 + 0x10);
    func_00282D30(sp10, D_0018A0E0, func_002A7878(D_001AF1A4 * 0.016666668f, D_001AF1A8 * 0.016666668f));
    func_002ACEC0(sp20, sp10, sp0, func_002A7940());
    if ((*(u8 *)((s8 *)(temp_s2) + (0x57))) != 0) {
        var_s2 = D_001AF1B8;
    } else {
        var_s2 = D_001AF1B0;
    }
    temp_s0 = D_001AF1AC;
    temp_v0 = func_002A77E0(0xFF);
    temp_s1 = arg0 + 0x10;
    func_002C3150(temp_s1, sp20, var_s2, temp_s0, D_001AF1BC, (u8) temp_v0, 1);
    temp_s0_2 = D_001AF1AC;
    temp_v0_2 = func_002A77E0(0xFF);
    func_002C3150(temp_s1, sp20, D_001AF1B4, temp_s0_2, D_001AF1C0, (u8) temp_v0_2, 1);
}
