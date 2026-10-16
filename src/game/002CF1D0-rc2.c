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

extern s8 D_00138180[];
extern s8 D_001F2840[];
extern s32 D_001A8CFC __attribute__((sda));
extern void func_0029C560(s32 a);
extern void func_002D5E98(void *p);
extern void func_002E5E58(s32 a, s32 b, s32 c);
extern void *func_003415B8(s32 a);

s32 func_002CF1D0(void)
{
    s8 loc[8];
    s8 *base;
    s8 *q;
    s32 temp_a0;
    s32 temp_v1;
    s32 var_s1;
    s32 var_v1;
    void *r;
    s32 tv;

    base = D_00138180;
    temp_a0 = *(s32 *)(base + 0x1C4);
    var_s1 = 0;
    if (temp_a0 & 0x10) {
        q = D_001F2840;
        temp_v1 = *(s32 *)(*(s8 **)(q + 0x14) + 0xE0);
        if (temp_v1 != 0) {
            *(s32 *)(q + 0x18) = temp_v1;
            goto block_6;
        }
        var_v1 = -1;
        if (*(s32 *)(q + 0x134) != 0) {
            goto block_6;
        }
        goto block_7;
block_6:
        var_v1 = 0;
block_7:
        return var_v1;
    }
    if (temp_a0 & 0x900) {
        var_s1 = 1;
    } else {
        func_0029C560(temp_a0);
        var_v1 = *(s32 *)(base + 0x1C4);
        var_v1 = var_v1 & 0x40;
        if (var_v1 && (D_001A8CFC != 0)) {
            r = func_003415B8(D_001A8CFC + 0x3BE08);
            *(u16 *)(loc + 2) = *(u16 *)((s8 *)r + 8);
            tv = *(s32 *)((s8 *)r + 0xC);
            *(s32 *)(loc + 4) = tv;
            if (tv == 0) {
                func_002E5E58(5, 0, 0);
            }
            func_002D5E98(loc);
        }
    }
    return var_s1;
}
