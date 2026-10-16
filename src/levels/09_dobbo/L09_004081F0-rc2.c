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

extern s32 ref_L09_004081F0_00;
extern void ref_L09_004081F0_01(s32, s32, s32, s32, s32);

void func_L09_004081F0(s32 arg0, s32 arg1, s8 *arg2, s32 arg3) {
    s32 temp_a1;

    temp_a1 = ref_L09_004081F0_00 + (arg1 << 8);
    if (temp_a1 != 0) {
        if (arg3 != 0) {
            ref_L09_004081F0_01(arg0, temp_a1, (*(s8 *)((s8 *)(arg2) + (0xBC))), (*(s8 *)((s8 *)(arg2) + (0xBD))), (*(s8 *)((s8 *)(arg2) + (0xBF))));
            return;
        }
        ref_L09_004081F0_01(arg0, temp_a1, -(*(s8 *)((s8 *)(arg2) + (0xBC))), -(*(s8 *)((s8 *)(arg2) + (0xBD))), -(*(s8 *)((s8 *)(arg2) + (0xBF))));
    }
}
