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

extern s8 D_00188660[];
extern s8 ref_L10_00418400_00[];
extern s32 ref_L10_00418400_01(s32, s32, s8 *, s32);
extern s32 ref_L10_00418400_02();
extern void ref_L10_00418400_03(s8 *, s8 *, s32, s32);
extern void ref_L10_00418400_04(s8 *, s32, s32, s32);
extern void ref_L10_00418400_05(s8 *);
extern void ref_L10_00418400_06(s8 *);

void func_L10_00418400(s8 *arg0) {
    s8 *s1;
    s8 *t;
    u8 k;

    k = *(u8 *)(arg0 + 0x20);
    s1 = *(s8 **)(arg0 + 0x68);
    switch (k) {
    case 0:
        *(u8 *)(arg0 + 0x30) = 0xFF;
        if (ref_L10_00418400_02() == 0) {
            return;
        }
        ref_L10_00418400_05(arg0);
        if (*(s32 *)(s1 + 0x264) != 0) {
            ref_L10_00418400_03(arg0, ref_L10_00418400_00, 0, 0);
        }
        break;
    case 1:
        ref_L10_00418400_04(arg0, 0, 1, 1);
        ref_L10_00418400_06(arg0);
        break;
    }
    t = D_00188660 + *(s32 *)(s1 + 0x268) * 0x70;
    if (*(void **)(t + 0x88) == arg0) {
        if (*(u8 *)(t + 0x74) != 0) {
            return;
        }
    }
    *(s32 *)(s1 + 0x268) = ref_L10_00418400_01(0, 6, arg0, 0xF8D);
}
