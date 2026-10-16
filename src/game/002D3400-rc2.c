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

extern void func_0029C5D0(s32 a);
extern s8 D_00138180[];
extern s8 D_001F2840[];

s32 func_002D3400(void) {
    s8 *b;
    s8 *p;
    s32 f;
    s32 x;
    s32 s0;
    s32 r;

    b = D_00138180;
    s0 = 0;
    f = *(s32 *)(b + 0x1C4);
    if (f & 0x10) {
        p = D_001F2840;
        x = *(s32 *)(*(s32 *)(p + 0x14) + 0xE0);
        if (x != 0) {
            *(s32 *)(p + 0x18) = x;
        } else {
            if (*(s32 *)(p + 0x134) == 0) {
                r = -1;
                goto ret;
            }
        }
        r = 0;
    ret:
        return r;
    }
    if (f & 0x900) {
        s0 = 1;
    } else {
        func_0029C5D0(*(s32 *)(b + 0x1C0));
    }
    return s0;
}
