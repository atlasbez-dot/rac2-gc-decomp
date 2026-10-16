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

extern s8 D_00189E20[];

void func_L00_002D3248(f32 fparg0, f32 fparg1, s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 *base;

    base = D_00189E20;
    *(s32 *)(base + 0x1438) = (s32)arg0;
    *(s16 *)(base + 0x143C) = (s16)(arg1 & 0xFF);
    *(u16 *)(base + 0x143E) = (u16)((*(u16 *)(base + 0x143E) & ~(arg3 & 0xFF)) | (arg2 & 0xFF));
    *(f32 *)(base + 0x1430) = fparg0;
    *(f32 *)(base + 0x1434) = fparg1;
}
