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

extern s64 func_0027C878(s32);
extern s8 D_00239B10[];

void func_00281DE8(s8 *arg0, s32 arg1, s32 arg2, s64 arg3) {
    s32 k;
    s8 *p;
    s64 t;

    (*(s64 *)((s8 *)(arg0) + (0x78))) = func_0027C878(arg1);
    (*(s64 *)((s8 *)(arg0) + (0x80))) = ((s64) 0xFF90 << 0x20) | 0x260;
    k = arg2 * 0x14;
    p = D_00239B10 + k;
    (*(s64 *)((s8 *)(arg0) + (0x70))) = 0;
    t = (s64) (*(s32 *)((s8 *)(p) + (0)));
    t |= (s64) (*(s32 *)((s8 *)(p) + (4))) << 2;
    t |= (s64) (*(s32 *)((s8 *)(p) + (8))) << 4;
    t |= (s64) (*(s32 *)((s8 *)(p) + (0xC))) << 6;
    t |= arg3 << 0x20;
    (*(s64 *)((s8 *)(arg0) + (0x88))) = t;
}
