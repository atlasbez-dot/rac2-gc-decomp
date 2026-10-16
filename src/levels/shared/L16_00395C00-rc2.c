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
extern void ref_L16_00395C00_00(s8 *, s8 *, s8 *, s32);
extern f32 ref_L16_00395C00_01(f32, f32);
extern f32 ref_L16_00395C00_02(f32);
extern f32 ref_L16_00395C00_03(f32);
extern f32 ref_L16_00395C00_04(f32);
extern void ref_L16_00395C00_05(f32 *, s8 *, f32);
extern void ref_L16_00395C00_06(f32 *, s8 *);
extern void ref_L16_00395C00_07(s8 *, s8 *, s8 *);

void func_L16_00395C00(s8 *arg0) {
    f32 buf[4];
    f32 v[4];
    s8 sp20[16];
    s8 pad[0x20];
    s8 *s2;

    s2 = (*(s8 **)((s8 *)(arg0) + (0x68)));
    ref_L16_00395C00_00(arg0, (s8 *)buf, D_00189E20, 0);
    (*(f32 *)((s8 *)(s2) + (0x38))) = -ref_L16_00395C00_01(buf[0], buf[1]);
    if ((*(f32 *)((s8 *)(s2) + (0x38))) > 0.2094395458698272705078125f) {
        (*(f32 *)((s8 *)(s2) + (0x38))) = 0.2094395458698272705078125f;
    } else if ((*(f32 *)((s8 *)(s2) + (0x38))) < -0.2094395458698272705078125f) {
        (*(f32 *)((s8 *)(s2) + (0x38))) = -0.2094395458698272705078125f;
    }
    if (!(ref_L16_00395C00_02((*(f32 *)((s8 *)(s2) + (0x38)))) <= 0.00174532947130501270294189453125f)) {
        ref_L16_00395C00_05(v, arg0 + 0xE0, ref_L16_00395C00_03((*(f32 *)((s8 *)(s2) + (0x38))) * 0.5f));
        v[3] = ref_L16_00395C00_04((*(f32 *)((s8 *)(s2) + (0x38))) * 0.5f);
        ref_L16_00395C00_06(v, sp20);
        ref_L16_00395C00_07(arg0 + 0xC0, sp20, arg0 + 0xC0);
    }
}
