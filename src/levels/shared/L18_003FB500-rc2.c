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

typedef int TI __attribute__((mode(TI)));

extern void ref_L18_003FB500_00(void *, u8, s8);
extern void ref_L18_003FB500_01(void *, void *, void *, s32,
                          f32, f32, f32, f32, f32, f32, f32,
                          s32, s32, s32, s32,
                          s32, s32, s32, s32);
extern void ref_L18_003FB500_02(s32, s32, void *, s32);
extern s8 ref_L18_003FB500_03[];

s32 func_L18_003FB500(void *arg0, s32 arg1) {
    void *stack = (void *)((u8 *)__builtin_alloca(0) - 0x20);
    s32 *temp_ptr;

    if (*(u8 *)((u8 *)arg0 + 0x20) != 2) {
        ref_L18_003FB500_00(arg0, 2, -1);
        temp_ptr = *(s32 **)((u8 *)arg0 + 0x68);
        *(s32 *)((u8 *)temp_ptr + 0x28) = arg1;
        if (arg1 != 0) {
            ref_L18_003FB500_01(arg0, ref_L18_003FB500_03, (u8 *)arg0 + 0x10, 5,
                          0.0f, 0.0f, 5.0f, 4.9f, 32.0f, 2.0f, 0.0f,
                          3, 8, -1, 1,
                          1, -1, 0, 0x810001);
            ref_L18_003FB500_02(1, 0, arg0, 0x1152);
        }
        return 0;
    }
    return 1;
}
