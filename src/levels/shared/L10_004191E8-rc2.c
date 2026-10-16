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
#ifndef NULL
#define NULL 0
#endif

extern void *ref_L10_004191E8_00();
extern s32 ref_L10_004191E8_01(s32);
extern void ref_L10_004191E8_02(s32, s32, s8 *);
extern void ref_L10_004191E8_03(s8 *, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32);

void func_L10_004191E8(s8 *arg0) {
    s8 *s1;
    s8 *v;
    u8 t;

    s1 = *(s8 **)(arg0 + 0x68);
    v = (s8 *)ref_L10_004191E8_00();
    if (v != NULL && *(s32 *)(v + 0x120) != 0 && *(s32 *)(s1 + 0x268) == 0) {
        t = *(u8 *)(arg0 + 0x20);
        if (t == 2) {
            ref_L10_004191E8_03(arg0, 0x60000080, 0, 1, 0.9f, 13.0f, 4.5f, 1.0f, 0, -1, 0);
        } else if (t == 1) {
            if (ref_L10_004191E8_01(2) != 0) {
                ref_L10_004191E8_03(arg0, 0x60800000, 1, 0, 0.6f, 5.0f, 1.0f, 1.0f, 0, -1, 0);
            } else {
                ref_L10_004191E8_03(arg0, 0x60800080, 1, 0, 0.6f, 5.0f, 1.0f, 1.0f, 0, -1, 0);
            }
        }
        if (ref_L10_004191E8_01(3) == 0) {
            ref_L10_004191E8_02(0, 0, arg0);
        }
        *(s32 *)(s1 + 0x268) = 0x19;
    }
}
