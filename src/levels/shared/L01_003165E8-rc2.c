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

extern s32 ref_L01_003165E8_00(s32, s8 *, s32);
extern s32 ref_L01_003165E8_01(s32, s32);
extern s32 ref_L01_003165E8_02(s32, s32);
extern s32 ref_L01_003165E8_03(s32, s32);
extern s8 *ref_L01_003165E8_04[];

s32 func_L01_003165E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s8 *temp;

    if (arg1 >= 0) {
        temp = ref_L01_003165E8_04[arg1];
        if (ref_L01_003165E8_00(arg0, temp + 0x10, *(s32 *)temp) != 0) {
            return 1;
        }
    }
    if (ref_L01_003165E8_01(arg0, arg2) != 0) {
        return 2;
    }
    if (ref_L01_003165E8_02(arg0, arg3) != 0) {
        return 3;
    }
    if (ref_L01_003165E8_03(arg0, arg4) == 0) {
        return 0;
    }
    return 4;
}
