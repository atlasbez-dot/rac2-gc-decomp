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

typedef int rc2_qword __attribute__((mode(TI)));
extern void ref_L02_0040B980_00(void *, s32, s32, s32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void ref_L02_0040B980_01(s32, s32, void *, s32);
extern void ref_L02_0040B980_02(void *, f32, f32);
extern void ref_L02_0040B980_03(void *, void *, void *);
extern void ref_L02_0040B980_04(void *, s32, void *, f32, f32, f32, f32, s32);
extern void ref_L02_0040B980_05(void *, s32, s32, s32);
extern void ref_L02_0040B980_06(void *);
extern void ref_L02_0040B980_07(void *, s32, s32);

void func_L02_0040B980(void *arg0) {
    volatile rc2_qword sp20;
    void *object  = arg0;
    void *temp_s1  = *(void **)((u8 *)arg0 + 0x68);


    *(u16 *)((u8 *)temp_s1 + 0x2E2) = 0;
    *(s32 *)((u8 *)temp_s1 + 0x2D4) = 0;
    if (*(u8 *)((u8 *)object + 0x31) != 0) {
        ref_L02_0040B980_00((u8 *)object + 0x10, 0, 5, 5, 0.5f, 0.0f, 0x19, 0x14, 0xA, 1, 1, 0, 0, 0);
        ref_L02_0040B980_01(0, 0, object, 0xC3E);
        ref_L02_0040B980_02((void *)&sp20, 0.083333336f, 0.116666675f);
        ref_L02_0040B980_03((void *)&sp20, (void *)&sp20, (u8 *)temp_s1 + 0xD0);
        ref_L02_0040B980_04(object, 0xFF, (void *)&sp20, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF);
    }
    ref_L02_0040B980_05(object, 0, 0, 3);
    ref_L02_0040B980_06(object);
    ref_L02_0040B980_07(object, 1, 0);
    *(u8 *)((u8 *)object + 0x31) = 0;
    *(s32 *)((u8 *)object + 0x98) = 0;
    *(u16 *)((u8 *)object + 0x34) = (*(u16 *)((u8 *)object + 0x34) & 0xEFFF) | 0x47;
}
