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

extern u8 D_001395DB;
extern s8 D_00189EA0[];
extern s32 ref_L12_004254A8_00(s8 *, s32);
extern void ref_L12_004254A8_01(s8 *, s32, s32);

void func_L12_004254A8(s8 *arg0) {
    s32 a1;

    if (*(u8 *)(arg0 + 0x20) == 0) {
        a1 = *(s32 *)(*(s8 **)(arg0 + 0x68));
        if ((a1 != -1) && (ref_L12_004254A8_00(D_00189EA0, a1) != 0)) {
            D_001395DB = 1;
            ref_L12_004254A8_01(arg0, 1, -1);
        }
    }
}
