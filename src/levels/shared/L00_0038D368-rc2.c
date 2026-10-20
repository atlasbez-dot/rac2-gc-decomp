
/* SPDX-License-Identifier: MIT
 * MIT License
 *
 * Copyright (c) 2026 Forja contributors
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

extern s32 ref_L00_0038D368_00(void *);
extern f32 ref_L00_0038D368_01(f32, f32);
extern f32 ref_L00_0038D368_02(s32);
extern void ref_L00_0038D368_03(void *);

void func_L00_0038D368(void *arg0) {
    f32 temp_f20;
    f32 k;
    s16 temp_a1;
    s32 temp_a0;
    void *temp_s1;

    k = 0.0523598865f;
    temp_s1 = (*(void **)((char *)(arg0) + (0x68)));
    temp_f20 = ref_L00_0038D368_02((*(s32 *)((char *)(temp_s1) + (0x14))) - (*(s16 *)((char *)(temp_s1) + (0x1C))));
    (*(f32 *)((char *)(arg0) + (0x2C))) = (f32) ((temp_f20 * (*(f32 *)((char *)(temp_s1) + (0x18)))) / ref_L00_0038D368_02((*(s32 *)((char *)(temp_s1) + (0x14)))));
    (*(f32 *)((char *)(arg0) + (0xF0))) = ref_L00_0038D368_01((*(f32 *)((char *)(arg0) + (0xF0))), k);
    (*(f32 *)((char *)(arg0) + (0xF4))) = ref_L00_0038D368_01((*(f32 *)((char *)(arg0) + (0xF4))), k);
    (*(f32 *)((char *)(arg0) + (0xF8))) = ref_L00_0038D368_01((*(f32 *)((char *)(arg0) + (0xF8))), k);
    if (ref_L00_0038D368_00(temp_s1 + 0x1C) != 0) {
        ref_L00_0038D368_03(arg0);
        return;
    }
    temp_a1 = (*(s16 *)((char *)(temp_s1) + (0x1C)));
    temp_a0 = (s32) (*(s32 *)((char *)(temp_s1) + (0x14))) / 2;
    if (temp_a1 < temp_a0) {
        (*(s8 *)((char *)(arg0) + (0x23))) = (s8) ((s32) (temp_a1 * (*(s16 *)((char *)(temp_s1) + (0x1E)))) / temp_a0);
    }
}
