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

extern s32 ref_L09_003FEA48_00(s8 *, s8 *, s32);
extern s32 ref_L09_003FEA48_01(s32);
extern void ref_L09_003FEA48_02(s8 *);
extern void ref_L09_003FEA48_03(s8 *, s32, s32, s32, f32, f32);
extern s32 D_001A79F0 __attribute__((sda));
extern s32 ref_L09_003FEA48_04 __attribute__((sda));
extern s32 ref_L09_003FEA48_05 __attribute__((sda));

void func_L09_003FEA48(s8 *arg0) {
    s8 *temp_s0 ;
    s16 temp_a0;

    temp_s0 = (*(s8 **)((s8 *)(arg0) + (0x68)));
    if (ref_L09_003FEA48_00(arg0, temp_s0 + 0x160, 0) != 0) {
        if (D_001A79F0 == 9) {
            temp_a0 = (*(s16 *)((s8 *)(temp_s0) + (0x1D0)));
            if (temp_a0 != -1) {
                if (ref_L09_003FEA48_01(ref_L09_003FEA48_05 + (temp_a0 << 8)) == 0) {
                    ref_L09_003FEA48_04 = 0;
                }
                (*(s16 *)((s8 *)(temp_s0) + (0x1D0))) = -1;
            }
        }
        ref_L09_003FEA48_02(arg0);
    }
    ref_L09_003FEA48_03(arg0, (*(s32 *)((s8 *)(temp_s0) + (0x448))), 0, 0, 0.0f, 0.0f);
}
