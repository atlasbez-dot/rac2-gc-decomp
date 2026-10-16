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

extern s32 ref_L20_00443508_00(s8 *, s32);
extern s32 ref_L20_00443508_01(s8 *);
extern s32 ref_L20_00443508_02(s8 *);
extern s32 ref_L20_00443508_03(s8 *);

s32 func_L20_00443508(s8 *arg0, s8 *arg1) {
    s16 temp_v1;

    if (ref_L20_00443508_00(arg1 + 0x10, (*(s32 *)((s8 *)((*(s8 **)((s8 *)(arg0) + (0x68)))) + (0x220)))) != 0) {
        temp_v1 = (*(s16 *)((s8 *)(arg1) + (0xAA)));
        if (temp_v1 >= 0x1FF) {
            if (temp_v1 >= 0x201) {
                if (temp_v1 == 0x12D3) {
                    if (ref_L20_00443508_02(arg1) == 0) {
                        if (ref_L20_00443508_03(arg1) == 0) {
                            return 1;
                        }
                    }
                }
            } else {
                return ref_L20_00443508_01(arg1) == 0;
            }
        }
    }
    return 0;
}
