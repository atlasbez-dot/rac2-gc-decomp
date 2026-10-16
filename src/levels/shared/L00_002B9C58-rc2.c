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

extern s8 D_00189E20[];

void func_L00_002B9C58(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_a3;
    s8 *base;
    s8 *var_v1;

    var_a3 = 0;
    base = D_00189E20;
    var_v1 = base + 0x23EC;
    do {
        var_a3 += 1;
        if ((*(s16 *)((s8 *)(var_v1) + (0))) == 0) {
            (*(s16 *)((s8 *)(var_v1) + (0))) = 1;
            (*(s16 *)((s8 *)(var_v1) + (6))) = arg2;
            (*(s16 *)((s8 *)(var_v1) + (4))) = arg1;
            (*(s16 *)((s8 *)(var_v1) + (2))) = arg0;
            return;
        }
        var_v1 += 8;
    } while (var_a3 < 8);
}
