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

extern void ref_L01_003B5310_00(void *);
extern s32 ref_L01_003B5310_01(s32, s32);
extern void ref_L01_003B5310_02(void *, void *, s32, s32, f32);

void func_L01_003B5310(void *arg0) {
    void *temp_s0;
    u16 temp_v1;

    temp_s0 = (*(void **)((s8 *)(arg0) + (0x68)));
    if ((*(s32 *)((s8 *)(temp_s0) + (0x350))) != 0) {
        (*(s32 *)((s8 *)(temp_s0) + (0x350))) = 0;
        if ((*(s32 *)((s8 *)(temp_s0) + (0x330))) < 0xC8) {
            (*(s32 *)((s8 *)(temp_s0) + (0x330))) = ref_L01_003B5310_01(0x12C, 0x168);
        }
    }
    if ((*(s32 *)((s8 *)(temp_s0) + (0x244))) != 1) {
        ref_L01_003B5310_00((s8 *)temp_s0 + 0x330);
    }
    temp_v1 = (*(u16 *)((s8 *)(arg0) + (0x96)));
    if (temp_v1 <= 0xFFFD) {
        (*(u16 *)((s8 *)(arg0) + (0x96))) = temp_v1 + 1;
    }
    ref_L01_003B5310_00((s8 *)temp_s0 + 0x32C);
    ref_L01_003B5310_00((s8 *)temp_s0 + 0x334);
    ref_L01_003B5310_02(arg0, (s8 *)temp_s0 + 0x250, 6, 1, 4.0f);
}
