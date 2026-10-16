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

extern void ref_L07_00410B48_00(s8 *);
extern void ref_L07_00410B48_01(s8 *, s32, s32);
extern s32 ref_L07_00410B48_02(s8 *, s32, s32);
extern void ref_L07_00410B48_03(s8 *, s32 *, s32 *, s32 *, s32, s32, s32, s32, s32, s32, s32);
extern void ref_L07_00410B48_04(s32, s32, s8 *);
extern s32 ref_L07_00410B48_05 __attribute__((sda));
extern s32 ref_L07_00410B48_06 __attribute__((sda));
extern s32 ref_L07_00410B48_07 __attribute__((sda));

void func_L07_00410B48(s8 *arg0) {
    s8 *s0;
    s32 *s1;
    s32 v1;

    s0 = arg0;
    v1 = *(u8 *)(s0 + 0x20);
    s1 = *(s32 **)(s0 + 0x68);
    if (v1 == 1) {
        goto case1;
    }
    if (v1 < 2) {
        if (v1 == 0) {
            goto case0;
        }
        return;
    }
    if (v1 == 2) {
        goto case2;
    }
    return;
case0:
    ref_L07_00410B48_01(s0, 1, -1);
    return;
case1:
    if (ref_L07_00410B48_02(s0, 0x4010000, 0) != 0) {
        if (*s1 == 0) {
            ref_L07_00410B48_01(s0, 2, -1);
        }
    }
    *(u8 *)(s0 + 0xA8) = 0xFF;
    return;
case2:
    ref_L07_00410B48_04(0, 0, s0);
    ref_L07_00410B48_03(s0, (s32 *)&ref_L07_00410B48_07, (s32 *)&ref_L07_00410B48_06, (s32 *)&ref_L07_00410B48_05, 0xFFFF, 0, -1, 0, 0xFFFF, 0xFF, 0);
    ref_L07_00410B48_00(s0);
    return;
}
