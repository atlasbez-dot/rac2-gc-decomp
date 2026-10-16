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

extern s32 func_0029D830();
extern s32 func_0029DB28();
extern s8 D_0025A6E0[];
extern s32 D_0025A620;
extern s8 D_001C51D0[];

s32 func_002D75E8(s8 *arg0) {
    s32 *temp_t0;
    s8 *temp_a0;
    s8 *temp_a0_2;

    func_0029D830();
    (*(s32 *)((s8 *)(arg0) + (0xA0))) = func_0029DB28(0x70000000, 0, 0x70000100, 1);
    temp_a0 = arg0 + 0x30;
    temp_t0 = (s32 *)(temp_a0 + *(s32 *)D_001C51D0 * 4);
    if (*temp_t0 != -1) {
        temp_a0_2 = D_0025A6E0;
        (*(s32 *)((s8 *)(temp_a0_2) + (0x3C))) = -0x240;
        (*(s32 *)((s8 *)(temp_a0_2) + (0x34))) = *(s32 *)(0x70000000 + *temp_t0 * 4);
        D_0025A620 = *(s32 *)(0x70000100 + *temp_t0 * 4);
    }
    (*(s32 *)((s8 *)(arg0) + (0xA4))) = 0;
    return 0;
}
