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

extern void *ref_L15_00436298_00();
extern void ref_L15_00436298_01(s32, s32, void *);
extern void ref_L15_00436298_02(void *, s32, s32, f32, s32, f32, f32, f32, s32, s32, s32);
extern s32 ref_L15_00436298_03(s32, s32);

void func_L15_00436298(s8 *arg0) {
    s8 *temp_s0;
    s8 *temp_v0;
    s32 temp_v1;

    temp_s0 = (*(s8 **)((s8 *)(arg0) + (0x68)));
    temp_v0 = ref_L15_00436298_00();
    if ((temp_v0 != NULL) && ((*(s32 *)((s8 *)(temp_v0) + (0x120))) != 0) && ((*(s32 *)((s8 *)(temp_s0) + (0x450))) == 0)) {
        ref_L15_00436298_01(2, 0, arg0);
        ref_L15_00436298_02(arg0, 0x600000CF, 1, 1.0f, 0, 2.0f, 1.5f, 1.5f, 0x1E, (*(s32 *)((s8 *)(temp_s0) + (0x454))) * 2 + 4, 0);
        ref_L15_00436298_02(arg0, 0x600000CF, 1, 1.0f, 0, 2.0f, 1.5f, 1.5f, 0x1E, (*(s32 *)((s8 *)(temp_s0) + (0x454))) * 2 + 5, 0);
        (*(s32 *)((s8 *)(temp_s0) + (0x450))) = ref_L15_00436298_03(0x14, 0x3C);
        temp_v1 = (*(s32 *)((s8 *)(temp_s0) + (0x454))) + 1;
        (*(s32 *)((s8 *)(temp_s0) + (0x454))) = temp_v1;
        if (temp_v1 >= 3) {
            (*(s32 *)((s8 *)(temp_s0) + (0x454))) = 0;
        }
    }
}
