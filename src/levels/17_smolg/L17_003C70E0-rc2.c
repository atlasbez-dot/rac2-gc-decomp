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

extern f32 ref_L17_003C70E0_00(f32);
extern void ref_L17_003C70E0_01(s8 *, s8 *, s8 *);
extern void ref_L17_003C70E0_02(s8 *, s8 *);
extern void ref_L17_003C70E0_03(s8 *, s8 *, s8 *);
extern f32 ref_L17_003C70E0_04 __attribute__((sda));
extern s8 D_00189EA0[];

s32 func_L17_003C70E0(s8 *arg0) {
    f32 buf[16];
    s8 *s0;
    s8 *s2;

    s2 = D_00189EA0;
    ref_L17_003C70E0_01((s8 *)buf, s2, arg0 + 0x10);
    s0 = (s8 *)buf + 0x10;
    ref_L17_003C70E0_02(s0, arg0 + 0xC0);
    ref_L17_003C70E0_03((s8 *)buf, (s8 *)buf, s0);
    if (!(ref_L17_003C70E0_00(buf[0]) <= ref_L17_003C70E0_04)) {
        return 0;
    }
    if (!(ref_L17_003C70E0_00(buf[1]) <= ref_L17_003C70E0_04)) {
        return 0;
    }
    if (ref_L17_003C70E0_00(*(f32 *)(s2 + 8) - *(f32 *)(arg0 + 0x18)) < 2.0f) {
        return 1;
    }
    return 0;
}
