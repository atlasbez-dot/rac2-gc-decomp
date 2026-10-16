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

extern void func_002704D0(void);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282F20(void *, void *, f32);
extern void func_00283410(void *, void *);
extern void func_00283678(void *, void *);
extern s8 D_001B5200[];
extern s8 D_00189EB0[];

void func_003355A8(s32 arg0) {
    f32 sp0[4];
    f32 sp10[4];
    f32 sp20[8];
    f32 sp40[8];
    s8 *s2;
    s8 *s3;
    s8 *b;

    b = D_001B5200;
    s2 = *(s8 **)(b + 0x190);
    func_002704D0();
    if (arg0 == 0) {
        s3 = s2 + 0x30;
        func_00283410(sp20, D_00189EB0);
        func_00283678(s2, sp20);
        func_00282F20(sp10, sp20, -1.0f);
        func_00282F20(sp0, sp40, 1.2f);
        func_00282CC0(s3, D_00189EB0 - 0x10, sp0);
        func_00282CC0(s3, s3, sp10);
        (*(s16 *)((s8 *)(*(s8 **)(b + 0x190)) + (0x8A))) = 1;
    } else if (arg0 == 2) {
        (*(s8 *)((s8 *)(b) + (0x293))) = 0;
        (*(s16 *)((s8 *)(s2) + (0x7E))) = arg0;
        (*(f32 *)((s8 *)(b) + (0x2B4))) = 0.018f;
        (*(f32 *)((s8 *)(b) + (0x2A8))) = 0.018f;
    } else if (arg0 == 1) {
        (*(s16 *)((s8 *)(s2) + (0x7E))) = 3;
    } else if (arg0 == 4) {
        (*(s8 *)((s8 *)(b) + (0x293))) = 0;
        (*(s16 *)((s8 *)(s2) + (0x7E))) = 5;
        (*(f32 *)((s8 *)(b) + (0x2B4))) = 0.018f;
        (*(f32 *)((s8 *)(b) + (0x2A8))) = 0.018f;
    }
}
