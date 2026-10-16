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

extern void ref_L23_0041BF18_00(void *arg0, int arg1, void *arg2);
extern void ref_L23_0041BF18_01(void *arg0, int arg1, float arg2);
extern float ref_L23_0041BF18_02(float arg0, float arg1);

extern void *ref_L23_0041BF18_03 __attribute__((sda));
extern float ref_L23_0041BF18_04 __attribute__((sda));
extern float ref_L23_0041BF18_05 __attribute__((sda));

void func_L23_0041BF18(void *arg0, float arg1, float arg2) {
    void *temp_s0 = *(void **)((unsigned char *)ref_L23_0041BF18_03 + 0x68);

    if (*(unsigned char *)((unsigned char *)temp_s0 + 0x4F1) == 0) {
        ref_L23_0041BF18_00(arg0, 0x28, (unsigned char *)temp_s0 + 0x4F0);
    }

    ref_L23_0041BF18_01((unsigned char *)temp_s0 + 0x500, 0, *(float *)((unsigned char *)temp_s0 + 0x580));
    *(float *)((unsigned char *)temp_s0 + 0x580) =
        ref_L23_0041BF18_02(*(float *)((unsigned char *)temp_s0 + 0x580), arg1 * ref_L23_0041BF18_04 * 0.00029088825f);

    if (*(unsigned char *)((unsigned char *)temp_s0 + 0x531) == 0) {
        ref_L23_0041BF18_00(arg0, 0x29, (unsigned char *)temp_s0 + 0x530);
    }

    ref_L23_0041BF18_01((unsigned char *)temp_s0 + 0x540, 0, *(float *)((unsigned char *)temp_s0 + 0x584));
    *(float *)((unsigned char *)temp_s0 + 0x584) =
        ref_L23_0041BF18_02(*(float *)((unsigned char *)temp_s0 + 0x584), arg2 * ref_L23_0041BF18_05 * 0.00029088825f);
}
