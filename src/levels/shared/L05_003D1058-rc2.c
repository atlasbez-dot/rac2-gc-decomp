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
#ifndef NULL
#define NULL 0
#endif

extern void ref_L05_003D1058_00(s32, s32 *, s32);
extern void ref_L05_003D1058_01(s32 *, s32 *, f32);
extern void ref_L05_003D1058_02(s32 *, void *, s32 *);
extern void *ref_L05_003D1058_03(void *);
extern void ref_L05_003D1058_04(s32, s32, s32 *, s32, f32, f32, f32, s32 *);

void func_L05_003D1058(s32 arg0, s32 arg1, void *arg2, s32 arg3, f32 fparg0, f32 fparg1, f32 fparg2) {
    s32 sp[12];
    u8 temp_v1;
    void *temp_v0;

    if (arg2 != NULL) {
        temp_v1 = *(u8 *)((s8 *)arg2 + 0x20);
        if (temp_v1 != 0xFE) {
            if (temp_v1 != 0xFD) {
            ref_L05_003D1058_00(arg0, sp, 1);
            temp_v0 = ref_L05_003D1058_03(arg2);
            ref_L05_003D1058_01(&sp[4], sp, *(f32 *)((s8 *)temp_v0 + 0x10));
            ref_L05_003D1058_02(&sp[8], (s8 *)arg2 + 0x10, &sp[4]);
            ref_L05_003D1058_04(arg0, arg1, &sp[8], arg3, fparg0, fparg1, fparg2, sp);
            }
        }
    }
}
