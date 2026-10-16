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

extern f32 ref_L01_003208D0_00(f32);
extern f32 ref_L01_003208D0_01(f32, f32);
extern s32 ref_L01_003208D0_02(s32, s32, f32);
extern f32 ref_L01_003208D0_03(f32, f32);
extern s32 ref_L01_003208D0_04(void *, s32);

void func_L01_003208D0(void *arg0, f32 *arg1, s32 arg2) {
    f32 temp_f0;
    s32 var_s0;

    u32 temp_v1 ;

    u32 var_v0 ;

    if (((*(u8 *)((s8 *)(arg0) + (0x23))) != 0) || (arg2 != 0)) {
        temp_f0 = ref_L01_003208D0_01(*arg1, 0.1454441249370575f);
        *arg1 = temp_f0;
        var_s0 = ref_L01_003208D0_02(0x8000C020, 0x80008000, (ref_L01_003208D0_00(temp_f0) + 0.5f) * 0.5f);
        if (ref_L01_003208D0_03(0.0f, 1.0f) < 0.05f) {
            var_s0 = ref_L01_003208D0_02(var_s0, 0x8080FFFF, 0.3f);
        }
        ref_L01_003208D0_04(arg0, var_s0);
        temp_v1 = (*(u8 *)((s8 *)(arg0) + (0x23)));
        if (arg2 != 0) {
            if (temp_v1 >= 0x3DU) {
                goto state_limit;
            }
            var_v0 = temp_v1 + 3;
            (*(u8 *)((s8 *)(arg0) + (0x23))) = var_v0;
            goto state_done;
        state_limit:
            var_v0 = 0x40;
            (*(u8 *)((s8 *)(arg0) + (0x23))) = var_v0;
            goto state_done;
        } else {
            if (temp_v1 >= 4U) {
                var_v0 = temp_v1 - 3;
                (*(u8 *)((s8 *)(arg0) + (0x23))) = var_v0;
            } else {
                (*(u8 *)((s8 *)(arg0) + (0x23))) = 0U;
                return;
            }
        }
    state_done: ;
    }
}
