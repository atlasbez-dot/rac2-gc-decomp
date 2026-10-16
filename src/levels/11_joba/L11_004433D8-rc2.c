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

extern s32 ref_L11_004433D8_literal_0;
extern s8 ref_L11_004433D8_00[];
extern s32 ref_L11_004433D8_01 __attribute__((sda));
extern s32 ref_L11_004433D8_02 __attribute__((sda));

extern f32 ref_L11_004433D8_03(s8 *, s32 *);
extern void ref_L11_004433D8_04(s8 *, s32, s32);
extern void ref_L11_004433D8_05(s32, s32);
extern void ref_L11_004433D8_06(s32 *);
extern void ref_L11_004433D8_07(s32 *);

void func_L11_004433D8(s8 *arg0) {
    u8 temp_v1;

    *(s32*)(&ref_L11_004433D8_literal_0) = 1;
    if (ref_L11_004433D8_03(ref_L11_004433D8_00, &ref_L11_004433D8_01) < 0.01f) {
        temp_v1 = *(u8 *)(arg0 + 0x20);
        if (temp_v1 == 4) {
            ref_L11_004433D8_04(arg0, 7, -1);
        } else if (temp_v1 == 5) {
            ref_L11_004433D8_04(arg0, 6, -1);
        }
        ref_L11_004433D8_05(1, 0);
        ref_L11_004433D8_06(&ref_L11_004433D8_01);
        ref_L11_004433D8_07(&ref_L11_004433D8_02);
    }
}
