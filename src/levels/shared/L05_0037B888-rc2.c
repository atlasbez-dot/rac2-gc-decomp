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

extern void *ref_L05_0037B888_00();
extern s32 ref_L05_0037B888_01();
extern s32 ref_L05_0037B888_02 __attribute__((sda));
extern s8 *ref_L05_0037B888_03[];
extern s8 ref_L05_0037B888_04[];

s32 func_L05_0037B888(void *arg0) {
    s8 *temp_a2;
    s8 *temp_a3;
    s8 *temp_t;
    s16 temp_a1;
    s32 var_s1;
    s32 lim;

    temp_a3 = ref_L05_0037B888_00(arg0);
    var_s1 = 1;
    temp_a2 = ref_L05_0037B888_04;
    if (*(s32 *)(temp_a2 + 0x2C) == var_s1) {
        return 0;
    }
    if (temp_a3 == 0) {
        return 0;
    }
    temp_a1 = *(s16 *)((s8 *)arg0 + 0xAA);
    temp_t = ref_L05_0037B888_03[ref_L05_0037B888_02];
    if (temp_a1 != *(s16 *)(temp_t + 0xAA)) {
        return 0;
    }
    if (*(s32 *)(temp_a3 + 0x118) == var_s1) {
        return 0;
    }
    lim = *(s32 *)(temp_a2 + 0x20);
    if (!(*(s32 *)(temp_a2 + 0xC) < lim)) {
        return 0;
    }
    if (ref_L05_0037B888_01(arg0, temp_a1, temp_a2, temp_a3) == 3) {
        return 0;
    }
    if ((ref_L05_0037B888_01(arg0) ^ 0xD) == 0) {
        var_s1 = 0;
    }
    return var_s1;
}
