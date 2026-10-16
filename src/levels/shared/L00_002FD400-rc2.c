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

extern void ref_L00_002FD400_00(s32, s32, s32);
extern s8 ref_L00_002FD400_01[];

void func_L00_002FD400(void) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_s1;
    void *var_s0;

    var_s0 = ref_L00_002FD400_01;
    var_s1 = 0;
    do {
        if (*(s32 *)((s8 *)var_s0 + 0x10) != 0) {
            temp_v0 = *(s32 *)((s8 *)var_s0 + 0xC);
            if (temp_v0 != 0) {
                temp_a0 = temp_v0 + (*(s16 *)((s8 *)var_s0 + 8) * 2);
                ref_L00_002FD400_00(temp_a0,
                             temp_a0 + (*(s16 *)((s8 *)var_s0 + 0xA) * 2),
                             var_s1);
                *(s16 *)((s8 *)var_s0 + 8) = 0;
                *(s16 *)((s8 *)var_s0 + 0xA) = 0;
            }
        }
        var_s1 += 1;
        var_s0 = (s8 *)var_s0 + 0x30;
    } while (var_s1 < 8);
}
