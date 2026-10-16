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

extern void ref_L04_0042BF58_00(void *, void *, f32, f32, f32, f32);
extern void ref_L04_0042BF58_01(s32, s32, void *);

void func_L04_0042BF58(void *arg0) {
    f32 temp_f1;
    void *temp_s1;

    temp_s1 = *(void **)((s8 *)arg0 + 0x68);
    if (*(u8 *)((s8 *)arg0 + 0x20) == 0) {
        *(u8 *)((s8 *)arg0 + 0x20) = 1;
    }
    if (*(u8 *)((s8 *)arg0 + 0x20) == 2) {
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x18);
        if (temp_f1 >= 30.0f) {
            *(f32 *)((s8 *)arg0 + 0x18) = temp_f1 - 0.283333361148834228515625f;
        }
        if (*(f32 *)((s8 *)arg0 + 0x18) < 30.0f) {
            *(u8 *)((s8 *)arg0 + 0x20) = 4;
        }
    }
    if (*(u8 *)((s8 *)arg0 + 0x20) == 3) {
        ref_L04_0042BF58_00((s8 *)arg0 + 0x18, temp_s1, 55.0f,
                      0.008333333767950534820556640625f,
                      0.013888888992369174957275390625f,
                      0.4500000178813934326171875f);
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x18);
        if (temp_f1 >= 55.0f) {
            ref_L04_0042BF58_01(0, 0, arg0);
            *(s32 *)((s8 *)temp_s1 + 4) = 0;
            *(u8 *)((s8 *)arg0 + 0x20) = 1;
        }
    }
}
