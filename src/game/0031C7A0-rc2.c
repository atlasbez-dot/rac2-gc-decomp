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

extern void func_0031C970(s8 *);
extern void func_0031CB78(s8 *, s8 *, s32, s32, s32, f32);
extern void func_0031CDF8(s8 *, s32, s32, s32, f32);

void func_0031C7A0(s8 *arg0) {
    s8 *s1;
    u8 t;

    s1 = *(s8 **)(arg0 + 0x68);
    t = arg0[0x20];
    if ((u32)(t - 4) < 2 || *(u8 *)(arg0 + 0x95) == 2 || t == 10) {
        func_0031C970(arg0);
    }
    func_0031CB78(arg0, s1 + 0x370, 0x41DE, 0x10000000, 0x20000000, 0.125f);
    func_0031CB78(arg0, s1 + 0x380, 0x800000, 0x10000000, 0x30000000, 0.125f);
    func_0031CB78(arg0, s1 + 0x390, 0x800000, 0x10000000, 0x30000000, 0.125f);
    func_0031CDF8(arg0, *(s32 *)(s1 + 0x270) + 0x10, 0x204080, 0x204080, 0.075f);
    func_0031CDF8(arg0, *(s32 *)(s1 + 0x274) + 0x10, 0x204080, 0x204080, 0.075f);
    func_0031CDF8(arg0, *(s32 *)(s1 + 0x278) + 0x10, 0x204080, 0x204080, 0.075f);
}
