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

extern s32 ref_L00_0032C5E8_00(s32, s32, s32, s32, s32, s32);

void func_L00_0032C5E8(s32 arg0, void *arg1) {
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg1) + (0x88)));
    if ((temp_a1 != 0) && (ref_L00_0032C5E8_00(arg0, temp_a1, arg0 + 0x10, arg0 + 0xF0, arg0 + 0x10, arg0 + 0xF0) != 0)) {
        (*(s32 *)((s8 *)(arg1) + (0x94))) = (s32) ((*(s32 *)((s8 *)(arg1) + (0x94))) | 0x40);
    }
}
