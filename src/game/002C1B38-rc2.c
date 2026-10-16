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

extern s32 func_00282CC0(void *, void *, void *);
extern s32 func_002B9180(void *);
extern f32 D_001AA380 __attribute__((sda));

void func_002C1B38(void *arg0) {
    void *temp_a0;
    void *temp_s1;
    f32 *temp_a2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    s32 temp_v0;

    temp_a0 = (s8 *)arg0 + 0x10;
    temp_s1 = (s8 *)arg0 + 0x20;
    func_00282CC0(temp_a0, temp_a0, temp_s1);
    temp_f0 = (*(f32 *)((s8 *)(arg0) + (0x10)));
    if (temp_f0 < 2.0f) {
        goto block_8;
    }
    if (temp_f0 > 1021.0f) {
        goto block_8;
    }
    temp_f0_2 = (*(f32 *)((s8 *)(arg0) + (0x14)));
    if (temp_f0_2 < 2.0f) {
        goto block_8;
    }
    if (temp_f0_2 > 1021.0f) {
        goto block_8;
    }
    temp_f0_3 = (*(f32 *)((s8 *)(arg0) + (0x18)));
    if (temp_f0_3 < 2.0f) {
        goto block_8;
    }
    if (temp_f0_3 > 1021.0f) {
        goto block_7;
    }
    goto block_9;
block_7:
block_8:
    func_002B9180(arg0);
    return;
block_9:
    temp_f1 = (*(f32 *)((s8 *)(temp_s1) + (0x10)));
    (*(u8 *)((s8 *)(arg0) + (8))) = (u8)((*(u8 *)((s8 *)(arg0) + (8))) + 1);
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32)((*(f32 *)((s8 *)(arg0) + (0xC))) + temp_f1);
    temp_a2 = (*(f32 **)((s8 *)(temp_s1) + (0x14)));
    if (temp_a2 == NULL) {
        goto block_11;
    }
    (*(f32 *)((s8 *)(arg0) + (0x18))) = (f32)(*temp_a2 + D_001AA380);
block_11:
    temp_v0 = (*(u16 *)((s8 *)(arg0) + (0xA))) - 1;
    (*(u16 *)((s8 *)(arg0) + (0xA))) = temp_v0;
    if ((temp_v0 << 0x10) != 0) {
        goto block_13;
    }
    (*(u16 *)((s8 *)(arg0) + (0xA))) = 4;
    (*(s32 *)((s8 *)(arg0) + (4))) = (*(s32 *)((s8 *)(arg0) + (4))) + 0xFF000000;
block_13:
    if ((*(s32 *)((s8 *)(arg0) + (4))) & 0xFF000000) {
        goto block_15;
    }
    func_002B9180(arg0);
block_15:
    return;
}
