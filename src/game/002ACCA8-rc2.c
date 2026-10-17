
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

extern s32 func_00282CF0(void *, s32, s32);
extern s32 func_00283098(void *, void *, s32);
extern f32 func_00282DF0(void *);

s32 func_002ACCA8(s32 arg0, s32 arg1) {
    s32 sp[4];
    s32 sp10[4];
    s32 temp_s0;

    if (arg1 < 0) {
        return 0;
    }
    temp_s0 = *(s32 *)0x1B1C54 + (arg1 << 7);
    func_00282CF0(sp, arg0, temp_s0 + 0x30);
    sp[3] = 0;
    func_00283098(sp10, sp, temp_s0 + 0x40);
    if (func_00282DF0(sp10) < 1.0f) {
        return 1;
    }
    return 0;
}
