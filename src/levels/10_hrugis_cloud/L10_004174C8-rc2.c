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

extern s32 ref_L10_004174C8_00;
extern u16 *ref_L10_004174C8_01[];
extern void ref_L10_004174C8_02(s8 *, s8 *);
extern void ref_L10_004174C8_03(s8 *);

void func_L10_004174C8(u8 *arg0) {
    s8 *s0;
    s8 *a;
    s8 *b;
    u16 *s1;
    u16 *t;
    s16 c;

    t = ref_L10_004174C8_01[arg0[0x21]];
    if (t != NULL) {
        s1 = t;
        do {
            s0 = *(s8 **)((s8 *)(ref_L10_004174C8_00 + ((*s1 & 0x7FFF) << 8)) + 0x68);
            a = *(s8 **)(s0 + 0x2C4);
            if (a != NULL) {
                ref_L10_004174C8_02(a, s0 + 0x370);
                ref_L10_004174C8_02(*(s8 **)(s0 + 0x2C4), s0 + 0x3B0);
                b = *(s8 **)(*(s8 **)(*(s8 **)(s0 + 0x2C4) + 0x68) + 0x18);
                if (b != NULL) {
                    ref_L10_004174C8_03(b);
                }
                ref_L10_004174C8_03(*(s8 **)(s0 + 0x2C4));
                *(s8 **)(s0 + 0x2C4) = NULL;
            }
            a = *(s8 **)(s0 + 0x2C0);
            if (a != NULL) {
                ref_L10_004174C8_02(a, s0 + 0x2F0);
                ref_L10_004174C8_02(*(s8 **)(s0 + 0x2C0), s0 + 0x330);
                b = *(s8 **)(*(s8 **)(*(s8 **)(s0 + 0x2C0) + 0x68) + 0x18);
                if (b != NULL) {
                    ref_L10_004174C8_03(b);
                }
                ref_L10_004174C8_03(*(s8 **)(s0 + 0x2C0));
                *(s8 **)(s0 + 0x2C0) = NULL;
            }
            c = (s16) *s1;
            s1++;
        } while (c >= 0);
    }
}
