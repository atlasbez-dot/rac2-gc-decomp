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

extern s32 func_002E3998();
extern s32 func_002E3BD8();
extern s8 D_001B20C0[];

void func_002E3940(s32 arg0) {
    s32 temp_a0;
    s32 temp_v1;
    s32 tmp0;

    temp_v1 = *(s32 *)D_001B20C0;
    if (arg0 < *(s16 *)((s8 *)temp_v1 + 6)) {
        tmp0 = temp_v1 + arg0 * 4;
        temp_a0 = *(s32 *)((s8 *)tmp0 + 0x20);
        if (*(s32 *)((s8 *)temp_a0 + 4) != 0) {
            func_002E3BD8(temp_a0);
            return;
        }
        func_002E3998(temp_a0);
    }
}
