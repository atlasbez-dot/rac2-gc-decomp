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

extern s8 D_001A63A8[];

void func_L03_003F71E0(void *arg0, s32 arg1) {
    s8 *s;
    s32 ix ;
    s8 *a3 ;
    s8 *q ;
    s8 *p ;
    s32 sh ;
    s32 one ;
    s32 c258 ;
    s32 v;

    s = D_001A63A8;
    ix = arg1;
    a3 = (*(s8 **)((s8 *)(arg0) + (0x68)));
    if ((*(s32 *)((s8 *)(s) + (0x68))) == 0 && (*(s32 *)((s8 *)(s) + (0x24))) == -1 && ix != (*(s32 *)((s8 *)(a3) + (0x40C)))) {
        sh = ix << 2;
        q = a3 + ix;
        p = a3 + sh;
        v = (*(s32 *)((s8 *)(p) + (0x3D0)));
        one = 1;
        c258 = 0x258;
        (*(s32 *)((s8 *)(s) + (0x28))) = 0;
        (*(s32 *)((s8 *)(s) + (0x24))) = (v & 0x3FFF) + 0x7D0;
        (*(s8 *)((s8 *)(q) + (0x410))) = one;
        (*(s32 *)((s8 *)(a3) + (0x408))) = c258;
        (*(s32 *)((s8 *)(a3) + (0x40C))) = ix;
    }
}
