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

typedef int TI __attribute__((mode(TI)));
typedef union {
    TI q;
    s32 w[4];
} VU;

extern f32 D_001AA3C4 __attribute__((sda));
extern f32 D_001AA3C8 __attribute__((sda));
extern f32 func_002A7878(f32, f32);
extern void func_00283CE0(s16);
extern void func_00282CC0(void *, void *, void *);
extern s32 func_002A77E0(s32);
extern void func_002C19D8(s32, s32, s32, f32, f32);
extern void func_002BFB38(void *, void *, s32, s32);
extern s32 func_00282978(void *);
extern void func_002B9180(void *);

void func_002C6360(s8 *arg0) {
    VU sp;
    s8 *temp_s1;
    s8 *temp_s2;
    f32 temp_f2;
    f32 temp_f3;

    temp_s1 = arg0 + 0x20;
    temp_s2 = arg0 + 0x10;
    temp_f2 = (*(f32 *)((s8 *)(temp_s1) + (8))) - (D_001AA3C4 + func_002A7878(-D_001AA3C8, D_001AA3C8));
    temp_f3 = (*(f32 *)((s8 *)(temp_s1) + (0x10))) + 0.0075f;
    (*(f32 *)((s8 *)(temp_s1) + (0x10))) = temp_f3;
    (*(f32 *)((s8 *)(temp_s1) + (8))) = temp_f2;
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32) ((*(f32 *)((s8 *)(temp_s1) + (0x14))) * temp_f3 * 210000.0f);
    sp.q = *(TI *)temp_s1;
    sp.w[3] = 0;
    func_00283CE0((*(s16 *)((s8 *)(arg0) + (0xA))));
    (*(s32 *)((s8 *)(arg0) + (4))) = 0x55503020;
    (*(u8 *)((s8 *)(arg0) + (8))) = (u8) ((*(u8 *)((s8 *)(arg0) + (8))) + (*(u8 *)((s8 *)(temp_s1) + (0x1A))));
    func_00282CC0(temp_s2, temp_s2, &sp);
    if (((*(f32 *)((s8 *)(arg0) + (0x18))) <= (*(f32 *)((s8 *)(temp_s1) + (0x1C)))) && (func_002A77E0(6) == 1)) {
        func_002C19D8((s32)temp_s2, 0, -1, 0.4f, 31500.001953125f);
    }
    if ((func_002A77E0(6) == 1) && ((*(s16 *)((s8 *)(temp_s1) + (0x18))) >= 0x32)) {
        func_002BFB38(arg0 + 0x10, &sp, 1, 0x14);
    }
    (*(s16 *)((s8 *)(temp_s1) + (0x18))) = (s16) ((u16) (*(s16 *)((s8 *)(temp_s1) + (0x18))) + 1);
    if (func_00282978(arg0 + 0xA) != 0) {
        func_002B9180(arg0);
    }
}
