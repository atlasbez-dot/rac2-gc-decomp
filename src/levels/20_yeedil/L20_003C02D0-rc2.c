
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

extern u16 *ref_L20_003C02D0_00[];
extern s32 ref_L20_003C02D0_01;
extern f32 ref_L20_003C02D0_02[];

void func_L20_003C02D0(s8 *arg0) {
    s32 *s;
    u16 *p;
    f32 *q;
    s8 *t;
    s32 base;
    s16 v;

    s = (*(s32 **)((char *)(arg0) + (0x68)));
    p = ref_L20_003C02D0_00[*s];
    if (p != 0) {
        base = ref_L20_003C02D0_01;
        q = ref_L20_003C02D0_02;
        do {
            t = (s8 *)(base + ((*p & 0x7FFF) << 8));
            *q = (*(f32 *)((char *)(t) + (0x18)));
            q++;
            (*(u16 *)((char *)(t) + (0x34))) = (u16)((*(u16 *)((char *)(t) + (0x34))) | 0x41);
            (*(f32 *)((char *)(t) + (0x18))) = (*(f32 *)((char *)(t) + (0x18))) - 20.0f;
            v = (s16) *p;
            p++;
        } while (v >= 0);
    }
}
