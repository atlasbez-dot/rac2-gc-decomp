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

extern s32 func_0029C4F0(s32 v);
extern void func_002D5E98(s8 *p, s32 v);
extern s8 *func_003415B8(s32 v);
extern s32 D_001A8CFC;
extern s8 D_00138180[];
extern s8 D_001F2840[];

s32 func_002CD950(void) {
    s8 *s0 = D_00138180;
    s32 a0 = *(s32 *)(s0 + 0x1C4);
    s32 s1 = 0;
    s8 loc[8];
    s8 *r;
    u16 h;
    s32 w;

    if (a0 & 0x10) {
        s8 *p = D_001F2840;
        s32 t = *(s32 *)(*(s32 *)(p + 0x14) + 0xE0);
        s32 r;
        if (t != 0) {
            *(s32 *)(p + 0x18) = t;
        } else {
            s32 x = *(s32 *)(p + 0x134);
            r = -1;
            if (x == 0) {
                goto out;
            }
        }
        r = 0;
    out:
        return r;
    }
    if (a0 & 0x900) {
        s1 = 1;
    } else {
        func_0029C4F0(a0);
        if ((*(s32 *)(s0 + 0x1C4) & 0x40) && D_001A8CFC != 0) {
            r = func_003415B8(D_001A8CFC + 0x3BE08);
            h = *(u16 *)(r + 8);
            *(u16 *)(loc + 2) = h;
            w = *(s32 *)(r + 0xC);
            *(s32 *)(loc + 4) = w;
            func_002D5E98(loc, w);
        }
    }
    return s1;
}
