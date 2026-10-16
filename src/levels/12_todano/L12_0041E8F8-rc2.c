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

extern void ref_L12_0041E8F8_00(void *, void *, void *);
extern void ref_L12_0041E8F8_01(void *, void *, f32);
extern void ref_L12_0041E8F8_02(void *, void *, void *, s32, f32);
extern void ref_L12_0041E8F8_03(void *, s32, void *, f32, f32, f32, f32, s32);
extern void ref_L12_0041E8F8_04(s32, s32, void *);
extern s8 D_00189EA0[];
extern s8 D_0019B4A8[];
extern s32 D_001A79F0 __attribute__((sda));

void func_L12_0041E8F8(s8 *arg0) {
    s32 loc[4];
    s8 *p;
    u8 b;
    s32 x;
    s32 t;

    ref_L12_0041E8F8_00(loc, arg0 + 0x10, D_00189EA0);
    ref_L12_0041E8F8_02(arg0, loc, loc, 0, 0.0f);
    ref_L12_0041E8F8_01(loc, loc, 0.1000000089406967163085937500f);
    ref_L12_0041E8F8_03(arg0, 0x1F, loc, 6.0f, 12.0f, 6.0f, 12.0f, 0xFF);
    if (*(u16 *)(arg0 + 0xB2) & 1) {
        x = ((s16)*(u16 *)(arg0 + 0xB2)) >> 1;
        t = x + (D_001A79F0 << 10);
        p = (s8 *)(t + (s32)D_0019B4A8);
        b = *(u8 *)p;
        if (((b >> 4) & 7) != 7) {
            *p = b + 0x10;
        }
    } else {
        x = ((s16)*(u16 *)(arg0 + 0xB2)) >> 1;
        t = x + (D_001A79F0 << 10);
        p = (s8 *)(t + (s32)D_0019B4A8);
        b = *(u8 *)p;
        if ((b & 7) != 7) {
            *p = b + 1;
        }
    }
    ref_L12_0041E8F8_04(1, 0, arg0);
}
