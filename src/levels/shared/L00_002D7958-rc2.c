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

extern f32 ref_L00_002D7958_00(f32 a, f32 b);

void func_L00_002D7958(void *arg0, void *arg1, f32 fparg0) {
    (*(f32 *)((s8 *)(arg0) + (0))) = ref_L00_002D7958_00((*(f32 *)((s8 *)(arg1) + (0))), fparg0);
    (*(f32 *)((s8 *)(arg0) + (4))) = (*(f32 *)((s8 *)(arg1) + (4)));
    (*(f32 *)((s8 *)(arg0) + (8))) = (*(f32 *)((s8 *)(arg1) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (*(f32 *)((s8 *)(arg1) + (0xC)));
    (*(f32 *)((s8 *)(arg0) + (0x10))) = (*(f32 *)((s8 *)(arg1) + (0x10)));
}
