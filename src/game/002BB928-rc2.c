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

extern s32 func_00282978(s32);
extern s32 func_00282CC0(s32, s32, s32);
extern f32 func_00283CE0(s32);
extern u32 func_00283D38(s32, s32, f32);
extern s32 func_002B9180(s32);
extern s8 D_001F2560[];

void func_002BB928(s32 arg0) {
    s32 temp_s1;
    s32 temp_a0;
    s32 temp_a2;
    u32 temp_v0;
    s32 temp_a0_2;

    temp_s1 = arg0 + 0x20;
    temp_a0 = arg0 + 0x10;
    func_00282CC0(temp_a0, temp_a0, temp_s1);
    if (func_00282978(arg0 + 0xA) != 0) {
        func_002B9180(arg0);
        return;
    }
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (*(f32 *)((s8 *)(arg0) + (0xC))) + (*(f32 *)((s8 *)(temp_s1) + (0x1C)));
    temp_v0 = func_00283D38((*(s32 *)((s8 *)(temp_s1) + (0x14))), (*(s32 *)((s8 *)(temp_s1) + (0x10))), (f32) (*(s16 *)((s8 *)(arg0) + (0xA))) / func_00283CE0((*(s32 *)((s8 *)(temp_s1) + (0x18)))));
    temp_a2 = (*(s16 *)((s8 *)(arg0) + (0xA)));
    (*(u32 *)((s8 *)(arg0) + (4))) = temp_v0;
    if (temp_a2 < 6) {
        (*(u32 *)((s8 *)(arg0) + (4))) = (temp_v0 & 0xFFFFFF) | (((s32) (temp_a2 * (s32) (temp_v0 >> 24)) / 6) << 24);
    }
    temp_a0_2 = (*(s32 *)((s8 *)(temp_s1) + (0x18)));
    (*(u8 *)((s8 *)(arg0) + (2))) = ((u8 *) *(s32 *) D_001F2560)[((temp_a0_2 - (*(s16 *)((s8 *)(arg0) + (0xA)))) * 10) / temp_a0_2];
}
